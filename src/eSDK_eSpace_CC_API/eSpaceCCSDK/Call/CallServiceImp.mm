//
//  CallServiceImp.m
//  VTMSDK
//
//  Created by gaoshuming on 15/10/13.
//  Copyright © 2015年 wangchan. All rights reserved.
//


#import "CallServiceImp.h"
#import "call_interface.h"
#import "Log.h"
#import "tup_def.h"
#import "TupCallNotifications.h"
//#import "LogOne_interface.h"
#import "ECSUtils.h"
#import "AccountInfo.h"
#import "call_def.h"
#import "SecurityMacros.h"
#import "ECSNotifications.h"
#import <arpa/inet.h>
#import "VTMCommonUtil.h"
#import "VTMNotificationsDefine.h"
#import "Reachability.h"

#include "securec.h"

static BOOL g_CallLogOn = NO;

#define DUMP_TUP_API_EXECUTED_RESULT(apiName, apiResult) do { if (TUP_SUCCESS == (apiResult)) \
{ logDbg(@"Execute (%s) success.", #apiName ); }\
else\
{ logErr(@"Execute (%s) failed, result = %d",#apiName, (apiResult)); }\
} while(0)

//应用程序根目录地址
#define APP_DOC_PATH		[NSHomeDirectory() stringByAppendingPathComponent:@"Documents"]
#define DUMP_TUP_API_EXECUTED(apiName) do {  logDbg(@"Execute %s", #apiName); } while(0)

//语音TUP上报通知所带参数组成的字典中对应的key
#define NOTIFY_DIC_OBJECT_KEY @"NOTIFY_DIC_OBJECT_KEY"  //通知携带的object对应的KEY
#define NOTIFY_DIC_ID_KEY @"NOTIFY_DIC_ID_KEY"          //通知携带的通知ID对应的KEY

NSString* const VOIP_DEREGISTER_RETCODE = @"VOIP_DEREGISTER_RETCODE";
NSString* const TERMINAL_VOIP_REGISTER_EVENT = @"TERMINAL_VOIP_REGISTER_EVENT";

NSString *const STARTCALL_RESULT = @"STARTCALL_RESULT";//发起呼叫响应
NSString *const CALL_RINGBACK = @"CALL_RINGBACK";//收到回铃音事件
NSString *const RECEIVE_CALL_MESSAGE = @"RECEIVE_CALL_MESSAGE";  //呼叫成功后发送消息
NSString *const CALL_ENDED = @"CALL_ENDED"; //呼叫结束
NSString *const SIP_INFO_RECEIVE_NOTIFY = @"SIP_INFO_RECEIVE_NOTIFY"; //接收到sipinfo消息的通知
NSString *const SIP_INFO_CONTENT = @"SIP_INFO_CONTENT";//发送的SIP消息
NSString *const CALL_RELEASE = @"CALL_RELEASE";//释放呼叫

@interface CallServiceImp ()<TupCallNotificationsHandler>



@end

static CallServiceImp *callServiceImp;
@implementation CallServiceImp


+(CallServiceImp *)sharedInstance
{
    @synchronized(self) {
        if (callServiceImp == nil) {
            callServiceImp = [[CallServiceImp alloc]init];
        }
    }
    return callServiceImp;
}

+(CallServiceImp *)destroyInstance
{
    @synchronized(self) {
        if (callServiceImp != nil) {
            callServiceImp = nil;
        }
    }
    return callServiceImp;
}

-(id)init
{
    if (self = [super init])
    {
        NSLog(@"加载CallServiceImp...");
        [self setTupCallLoggerSwitch:YES];
        [self initFastSDKServices];
        [self loadFastSDK];
        
        isRegToMainServer_ = YES;
    }
    return self;
}

#pragma mark 日志配置

/**
 *  Tup呼叫部分的日志路径
 *
 *  @return Tup呼叫部分的日志路径
 */

- (NSString *)fastSDKLogDirPath {
    return [APP_DOC_PATH stringByAppendingPathComponent:@"/tuplog/call"];
}


/**
 *  打开/关闭Tup呼叫部分的日志
 *
 *  @param isLoggerOn 是否打开Tup呼叫部分的日志
*/

- (void)setTupCallLoggerSwitch:(BOOL)isLoggerOn
{
    if (isLoggerOn)
    {
        tup_call_log_start(0, 10*100, 2, (TUP_CHAR*)[[self fastSDKLogDirPath] UTF8String]);
        DUMP_TUP_API_EXECUTED(tup_call_log_start);
        g_CallLogOn = YES;
    }
    else
    {
        tup_call_log_stop();
        DUMP_TUP_API_EXECUTED(tup_call_log_stop);
        g_CallLogOn = NO;
    }
}

- (BOOL)initFastSDKServices {
    TUP_RESULT ret = tup_call_init();
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_init, ret);
    NSLog(@"ret:%d",ret);
    return (TUP_SUCCESS == ret);
}

-(BOOL)loadFastSDK
{
    TUP_RESULT ret_register_process = tup_call_register_process_notifiy(onTupCallNotifications);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_register_process_notifiy,ret_register_process );
    [TupCallNotifications setHandler:self];
    NSLog(@"ret_register_process:%d",ret_register_process);
    return (TUP_SUCCESS == ret_register_process);
}


//打开日志开关
+ (void)setLoggerSwitch:(BOOL)isLoggerOn
{
    [[CallServiceImp sharedInstance] setTupCallLoggerSwitch:isLoggerOn];
    logDbg(@"打开日志开关");
}


/**
 *  发起呼叫(外部接口)
 *
 *  @param callType     呼叫类型
 *  @param calleeNumber 呼叫号码
 *
 *  @return 发起呼叫内部接口返回值
 */
+ (BOOL)startCall:(EN_CALL_TYPE)callType calleeNumber:(NSString *)calleeNumber
{
    RETURN_NO_IF_PARAM_TEXT_EMPTY(calleeNumber);
    NSString * originalDomain = [ECSUtils domainFromNumber:calleeNumber];
    calleeNumber = [ECSUtils removeDomainField:calleeNumber];
    
    NSString * transformedNumber = [[CallServiceImp sharedInstance] transferNumberWithDigitMap:calleeNumber];
    calleeNumber = [ECSUtils addDomainField:transformedNumber domain:originalDomain];
    NSLog(@"发起呼叫calleeNumber:%@",calleeNumber);
    RETURN_NO_IF_PARAM_TEXT_EMPTY(calleeNumber);
    return [[CallServiceImp sharedInstance] createNewCallToCallee:calleeNumber withCallType:callType];
}

/**
 *  voip呼叫,通过数图规则转换号码,转换失败,则返回转换前的号码
 *
 *  @param NSString 需要转换的号码
 *
 *  @return 转换成功，返回转换之后的号码；转换失败，返回原始号码
 */

- (NSString *)transferNumberWithDigitMap:(NSString *)callNumber {
    NSString *digitMapValue = nil;//[[[[CESpaceLoginModel shareInstance] userInfo] infoFromMaa] digitMap];
    if (0 == [digitMapValue length]) {
        return callNumber;
    }
    
    if (0 == [callNumber length]) {
        logErr(@"Call number is empty.");
        return callNumber;
    }
    
    TUP_INT32 handle = -1;
    TUP_RESULT ret_create = tup_call_digitmap_create_handle(1, [digitMapValue UTF8String], &handle);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_digitmap_create_handle, ret_create);
    if (TUP_SUCCESS != ret_create || handle < 0)
    {
        return callNumber;
    }
    DMRESULT dmresult;
    HW_MEMSET(&dmresult, sizeof(dmresult), 0, sizeof(dmresult));
    NSString *replaceNumber = callNumber;
    TUP_RESULT ret_match = tup_call_digitmap_match(handle, [callNumber UTF8String], &dmresult);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_digitmap_match, ret_match);
    if (TUP_SUCCESS == ret_match)
    {
        replaceNumber = [NSString stringWithUTF8String:dmresult.pszNUM];
    }
    
    TUP_RESULT ret_destroy = tup_call_digitmap_destroy_handle(handle);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_digitmap_destroy_handle, ret_destroy);
    return replaceNumber;
}

#pragma mark - VOIP接口
/**
 *  发起匿名呼叫(内部私有接口)
 *
 *  @param calleeNumber 发起呼叫的号码
 *  @param callType     呼叫的类型：视频/音频
 *
 *  @return 是否成功发起呼叫（tup同步接口调用结果）
 */
- (BOOL)createNewCallToCallee:(NSString *)calleeNumber withCallType:(EN_CALL_TYPE)callType
{
    TUP_UINT32 callId;
    RETURN_NO_IF_PARAM_TEXT_EMPTY(calleeNumber);
    TUP_RESULT ret = TUP_FAIL;
    TUP_UINT32 port = 0;
    ret = tup_call_get_cfg(CALL_D_CFG_SIP_PORT, &port, sizeof(TUP_INT32));
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_get_cfg, ret);
    NSString *strAnonymousNum = [NSString stringWithFormat:@"%@@%@:%d",[AccountInfo sharedInstance].anonymousCardName,self.localIPAddress,port];
    logDbg(@"tup_call_set_cfg AnonymousNum = %s" , [strAnonymousNum UTF8String]);
    
    ret = tup_call_set_cfg(CALL_D_CFG_SIP_ANONYMOUSNUM, (TUP_VOID *)[strAnonymousNum UTF8String]);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_anonymous_call, ret);
    RETURN_NO_IF_PARAM_TEXT_EMPTY(calleeNumber);
    ret = tup_call_anonymous_call(&callId, [[self calleeURIWithNumber:calleeNumber] UTF8String]);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_anonymous_call, ret);
    self.callId = [NSString stringWithFormat:@"%d", callId];
    logDbg(@"callid = %s" , [self.callId UTF8String]);
    return YES;
}

-(NSString *)calleeURIWithNumber:(NSString *)number
{
    if ([number length] == 0) {
        return @"";
    }
    if ([number rangeOfString:@"@"].length == 0) {
        number = [ECSUtils addDomainField:number domain:self.selfUserDomain];
    }
    if ([self.outgoingAccountCode length] > 0) {
        number = [ECSUtils addPrefix:number prefix:self.outgoingAccountCode];
    }
    return [ECSUtils removeDomainField:number];
}

#pragma mark - TupCallNotificationsHandler代理
/**
 *  tup 呼叫部分回调通知接收方法（解析数据）
 *
 *  @param notification 相应tup回调上报的通知结构体
 */
- (void)onRecvNotification:(TupCallNotifications *)notification
{
    logDbg(@"call notification:%s, callId:%d",[[notification description] UTF8String],notification.param1);
    NSMutableDictionary *notifyDic = [[NSMutableDictionary alloc]init];
    [notifyDic setObject:[NSNumber numberWithInt:notification.msgId] forKey:NOTIFY_DIC_ID_KEY];
    switch (notification.msgId) {
        case CALL_E_EVT_SIPACCOUNT_INFO://上报注册与注销结果
        {
            CALL_S_SIP_ACCOUNT_INFO *regResult = (CALL_S_SIP_ACCOUNT_INFO *)notification.data;
            NSNumber *regStateNum = [NSNumber numberWithInt:regResult->enRegState];
            [notifyDic setObject:regStateNum forKey:NOTIFY_DIC_OBJECT_KEY];
            NSLog(@"上报注册与注销结果");
        }
            break;
        case CALL_E_EVT_CALL_STARTCALL_RESULT:
        {
            [[NSNotificationCenter defaultCenter] postNotificationName:STARTCALL_RESULT object:nil];
            NSLog(@"发起呼叫响应");
        }
            break;
         case CALL_E_EVT_CALL_INCOMMING://收到来电请求
        {
            NSLog(@"收到来电请求");
        }
            break;
        case CALL_E_EVT_CALL_RINGBACK://回铃音事件
        {
           [[NSNotificationCenter defaultCenter] postNotificationName:CALL_RINGBACK object:nil];
            NSLog(@"回铃音事件");
        }
            break;
        case CALL_E_EVT_CALL_CONNECTED://通话已建立
        {
            [[NSNotificationCenter defaultCenter] postNotificationName:RECEIVE_CALL_MESSAGE object:nil];
            NSLog(@"通话已建立");
        }
            break;
        case CALL_E_EVT_DIALOG_INFO: //消息回调
        {
            NSLog(@"消息回调");
            CALL_S_DIALOG_INFO *messageInfo = (CALL_S_DIALOG_INFO *)notification.data;
            NSLog(@"messageInfo:%s,%s,%s",messageInfo->media_type,messageInfo->sub_media_type,messageInfo->body);
            [self handleMessage:messageInfo];
        }
            break;
        case CALL_E_EVT_CALL_ENDED://会话结束
        {
            [[NSNotificationCenter defaultCenter] postNotificationName:CALL_ENDED object:nil];
            NSLog(@"会话结束");
        }
            break;
        case CALL_E_EVT_CALL_DESTROY://会话释放
        {
            self.callId = nil;
            [[NSNotificationCenter defaultCenter] postNotificationName:CALL_RELEASE object:nil];
            NSLog(@"会话释放");
        }
            break;
        default:
            break;
    }
}

#pragma mark -
#pragma mark -发送消息接口
-(BOOL)sendSIPDiaglogInfo:(SIPDiaglogInfo *)sipInfo
{
    NSLog(@"-----%s send",__FUNCTION__);
    BOOL result = NO;
    if (self.callId == nil) {
        logErr(@"error:callid is nil!!");
        return NO;
    }
    CALL_S_DIALOG_INFO diaglogInfo;
    
    strncpy(diaglogInfo.media_type, [sipInfo.mediaType UTF8String], CALL_D_MAX_CONTENT_TYPE_LEN);
    diaglogInfo.media_type[CALL_D_MAX_CONTENT_TYPE_LEN - 1] = NULL;
    
    strncpy(diaglogInfo.sub_media_type, [sipInfo.subMediaType UTF8String], CALL_D_MAX_CONTENT_TYPE_LEN);
    diaglogInfo.sub_media_type[CALL_D_MAX_CONTENT_TYPE_LEN-1] = NULL;
    
    strncpy(diaglogInfo.body, [sipInfo.body UTF8String], CALL_D_MAX_INFO_BODY_LEN);
    diaglogInfo.body[CALL_D_MAX_INFO_BODY_LEN-1] = NULL;
    
    TUP_RESULT iRet = tup_call_send_diaglog_info([self.callId intValue], &diaglogInfo);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_send_diaglog_info, iRet);
    if (iRet == 0)
    {
        [CallServiceImp sharedInstance].callId = [NSString stringWithFormat:@"%@", self.callId];
        result = YES;
    }
    NSLog(@"%s end",__FUNCTION__);
    return result;
}

//收到消息后的处理逻辑
-(void)handleMessage:(CALL_S_DIALOG_INFO *)message
{
    NSString *contentStr = [NSString stringWithFormat:@"[%s/%s]:%s",message->media_type,message->sub_media_type,message->body];
    NSLog(@"contentStr:%@",contentStr);
    NSMutableDictionary *userInfoDic = [NSMutableDictionary dictionary];
    [userInfoDic setObject:contentStr forKey:SIP_INFO_CONTENT];
    [[NSNotificationCenter defaultCenter] postNotificationName:SIP_INFO_RECEIVE_NOTIFY object:nil userInfo:userInfoDic];
}

#pragma mark -
#pragma mark 可视化留言接口

/**
 *  开始播放语音指定的留言(通过点对点呼叫指定号码实现)
 *
 *  @param shortCode 语音留言对应的号码
 *
 *  @return 是否成功播放(是否成功对指定的号码发起呼叫)
 */
+ (BOOL)playVoiceMsgWithMailShortCode:(NSString *)shortCode {
    RETURN_NO_IF_PARAM_TEXT_EMPTY(shortCode);
    TUP_UINT32 callid;
    TUP_RESULT ret = tup_call_start_call(&callid, CALL_E_CALL_TYPE_IPAUDIO, [shortCode UTF8String]);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_start_call__play_voice_message, ret);
    if (TUP_SUCCESS == ret)
    {
        [CallServiceImp sharedInstance].callId = [NSString stringWithFormat:@"%d", callid];
    }
    return (TUP_SUCCESS == ret);
}

/**
 *  接听当前收到的呼叫(外部接口)
 *
 *  @param audioSendMode 此参数当前不需要，预留（TUPC30之前版本在使用）
 *  @param isAudioOnly   是否为语音通话
 *
 *  @return 是否成功接听(调用TUP接口同步返回结果)
 */
+ (BOOL)answerCallWithSendMode:(CallServiceAudioSendMode)audioSendMode isAudioOnly:(BOOL)isAudioOnly
{
    NSString * callId = [CallServiceImp sharedInstance].callId;
    RETURN_NO_IF_PARAM_TEXT_EMPTY(callId);
    logDbg(@"tup call: tup_call_accept_call , %s" , (isAudioOnly ? "audiocall " : "videoCall"));
    TUP_RESULT ret = tup_call_accept_call([callId intValue], isAudioOnly ? TUP_FALSE : TUP_TRUE);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_accept_call, ret);
    return (TUP_SUCCESS == ret);
}

- (BOOL)isDTMFNumberValid:(NSInteger)num {
    /* 0x0a:*  0x0b:# 0x0c:A 0x0d:B 0x0e:C 0x0f:D*/
    if (  (num < 0 || num > 0x0f) )
    {
        return NO;
    }
    else {
        return YES;
    }
}

+ (BOOL)sendDTMF:(NSInteger)dialNum
{
    if (![[CallServiceImp sharedInstance] isDTMFNumberValid:dialNum])
    {
        return NO;
    }
    
    NSString *callId = [CallServiceImp sharedInstance].callId;
    RETURN_NO_IF_PARAM_TEXT_EMPTY(callId);
    
    TUP_RESULT dtmf_ret = tup_call_send_DTMF([callId intValue], (CALL_E_DTMF_TONE)dialNum);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_send_DTMF, dtmf_ret);
    
    return (TUP_SUCCESS == dtmf_ret);
}

/**
 *  对当前的呼叫进行呼叫保持(外部接口)
 *
 *  @return 调用tup呼叫保持接口同步返回结果
 */
+ (BOOL)holdCall
{
    NSString * callId = [CallServiceImp sharedInstance].callId;
    RETURN_NO_IF_PARAM_TEXT_EMPTY(callId);
    
    TUP_RESULT ret = tup_call_hold_call([callId intValue]);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_hold_call, ret);
    
    return (TUP_SUCCESS == ret);
}

+(void)closeCall
{
    RETURN_IF_PARAM_TEXT_EMPTY([CallServiceImp sharedInstance].callId);
    logDbg(@"closeCall %s",[[CallServiceImp sharedInstance].callId UTF8String]);
    
    //reject code 放在开头configset那边统一设置
    TUP_UINT32 callid = [[CallServiceImp sharedInstance].callId intValue];
    TUP_RESULT ret = tup_call_end_call(callid);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_end_call, ret);
    [[CallServiceImp sharedInstance] resetCallId];
    [[CallServiceImp sharedInstance] resetCallConnectStatus];
    
    if (TUP_SUCCESS == ret)
    {
        [[NSNotificationCenter defaultCenter] postNotificationName:ECSTempGrpAudioConfClosedNotify object:nil userInfo:nil];
    }
}

/**
 *  重置呼叫callid
 */
- (void)resetCallId
{
    self.callId = nil;
    self.sessionId = nil;
}

/**
 *  重置呼叫接通状态iscallConnect_
 */
- (void)resetCallConnectStatus
{
    isCallConnect_ = NO;
}


- (void)updateSIPInfo:(BOOL)isToMainServer
{
    [self currentReachableViaNetwork];
    _selfUserDomain = [AccountInfo sharedInstance].entryServerIp;
   // _selfUserDomain = @"172.22.8.69";
    NSLog(@"_selfUserDomain:%@",_selfUserDomain);
    _countryCode = @"086";
    isNeedAddDomainForHuaweiUC_ = NO;
    
    isRegToMainServer_ = isToMainServer;
}

- (void)currentReachableViaNetwork
{
    NetworkStatus netStatus = [[Reachability reachabilityForInternetConnection] currentReachabilityStatus];
    logInfo(@"netStatus:%d",netStatus);
    
    if (netStatus == ReachableViaWiFi)
    {
        NSDictionary *ipDic = [VTMCommonUtil getIPAddresses];
        _localIPAddress = [ipDic objectForKey:@"en0/ipv4"];
        logInfo(@"localIPAddress wifi:%@",_localIPAddress);
    }
    else if (netStatus == ReachableViaWWAN)
    {
        NSDictionary *ipDic = [VTMCommonUtil getIPAddresses];
        _localIPAddress = [ipDic objectForKey:@"pdp_ip0/ipv4"];
        logInfo(@"localIPAddress 4G:%@",_localIPAddress);
    }
    else
    {
        netStatus = NotReachable;
    }
}

+ (BOOL)updateInfoAndRegisterToServer:(BOOL)isToMainServer
{
    [self updateInfoAndRegisterToServer:YES];
    [[CallServiceImp sharedInstance] registerToServer];
    return YES;
}


-(BOOL)registerToServer
{
    NSString *userDomain = _selfUserDomain;
    if (userDomain == nil) {
        logErr(@"param is nil");
        return NO;
    }
    [self configSipStack];
    TUP_RESULT ret_register = tup_call_register([[self IMPU]UTF8String], [[self IMPI] UTF8String], [[self voipPassword] UTF8String]);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_register, ret_register);
    BOOL ret = TUP_SUCCESS == ret_register;
    
    if (!ret) {
        logErr(@"tup_call_register is failed");
    }
    NSMutableDictionary* userDict = [NSMutableDictionary dictionaryWithCapacity:1];
    [userDict setObject:[NSNumber numberWithBool:ret] forKeyedSubscript:VOIP_DEREGISTER_RETCODE];
    NSLog(@"CallServiceImp----userDict:%@",userDict);
    [[NSNotificationCenter defaultCenter] postNotificationName:TERMINAL_VOIP_REGISTER_EVENT object:nil userInfo:userDict];
    return (TUP_SUCCESS == ret_register);
}


#pragma mark - SIP服务器相关设置
-(void)configSipStack
{
    //服务器相关设置
    NSString *selfDomain = [ECSUtils notNilString:_selfUserDomain];
    logDbg(@"self domain is:%@",selfDomain);
    CALL_S_SERVER_CFG serverCfg1;
    HW_MEMSET(&serverCfg1, sizeof(CALL_S_SERVER_CFG), 0, sizeof(CALL_S_SERVER_CFG));
    HW_STRNCPY(serverCfg1.server_address, CALL_D_MAX_URL_LENGTH, [selfDomain UTF8String], CALL_D_MAX_URL_LENGTH);
    serverCfg1.server_port = [[self serverPort] intValue];
    
    NSLog(@"serverCfg1.server_port:%u",serverCfg1.server_port);
    TUP_RESULT ret_regprimary = tup_call_set_cfg(CALL_D_CFG_SERVER_REG_PRIMARY, &serverCfg1);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_set_cfg__CALL_D_CFG_SERVER_REG_PRIMARY, ret_regprimary);
    //"local-sip-port"设置
    TUP_UINT32 sipPort = [[AccountInfo sharedInstance].strSipServerPort intValue];
    logInfo(@"sipPort:%d",sipPort);
    TUP_RESULT ret_port = tup_call_set_cfg(CALL_D_CFG_SIP_PORT, &sipPort);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_set_cfg__CALL_D_CFG_SIP_PORT, ret_port);
    
    //消息配置回调
    
    CALL_S_CONTENT_TYPE contentType;
    NSString *mediaStr = @"text";
    NSString *subMediaStr = @"xml";
    
    strncpy(contentType.media_type, [mediaStr UTF8String], CALL_D_MAX_CONTENT_TYPE_LEN);
    contentType.media_type[CALL_D_MAX_CONTENT_TYPE_LEN - 1] = NULL;
    strncpy(contentType.sub_media_type, [subMediaStr UTF8String], CALL_D_MAX_CONTENT_TYPE_LEN);
    contentType.sub_media_type[CALL_D_MAX_CONTENT_TYPE_LEN - 1] = NULL;
    
    TUP_RESULT ret_sipInfo = tup_call_set_cfg(CALL_D_CFG_SIPGLOBAL_CONTENT_TYPE,&contentType);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_set_cfg__CALL_D_CFG_SIPGLOBAL_CONTENT_TYPE, ret_sipInfo);
    NSLog(@"ret_sipInfo:%d",ret_sipInfo);
    
    
    //"outbound-proxy-ip"、 "outbound-proxy-port"设置  //OK
    CALL_S_SERVER_CFG serverCfg2;
   // server IP and port
    NSString *serverAddr = [AccountInfo sharedInstance].entryServerIp;
    logDbg(@"outbound proxy ip is %@",serverAddr);
    NSString *serverPort = [AccountInfo sharedInstance].entryServerPort;
    logDbg(@"outbound proxy port is %@",serverPort);
    HW_MEMSET(&serverCfg2, sizeof(CALL_S_SERVER_CFG), 0, sizeof(CALL_S_SERVER_CFG));
    HW_STRNCPY(serverCfg2.server_address, CALL_D_MAX_URL_LENGTH, [serverAddr UTF8String], CALL_D_MAX_URL_LENGTH);
    serverCfg2.server_port = [serverPort intValue];
    
    TUP_RESULT ret_proxyprimary = tup_call_set_cfg(CALL_D_CFG_SERVER_PROXY_PRIMARY, &serverCfg2);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_set_cfg__CALL_D_CFG_SERVER_PROXY_PRIMARY, ret_proxyprimary);
    
    //"local-ip"设置
    NSString *localIP = [self getLocalIP];
    logDbg(@"localIP is:%@",localIP);
    CALL_S_IF_INFO IFInfo;
    HW_MEMSET(&IFInfo, sizeof(CALL_S_IF_INFO), 0, sizeof(CALL_S_IF_INFO));
    IFInfo.ulType = CALL_E_IP_V4;
    IFInfo.uAddress.ulIPv4 = inet_addr([localIP UTF8String]);
    TUP_RESULT ret_netaddress = tup_call_set_cfg(CALL_D_CFG_NET_NETADDRESS, &IFInfo);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_set_cfg__CALL_D_CFG_NET_NETADDRESS, ret_netaddress);
    
    //"mos"阈值设置
    //数据值 *1000（主要原因是使用整型比float型方便），取值范围0~5000（对应0.0~5.0），大于这个阀值则不上报mos值
    TUP_FLOAT mosThreshold = 3.0;//[CESpaceLoginModel shareInstance].userInfo.infoFromMaa.mosthreshold;
    
    if (mosThreshold > 5.0)
    {
        logDbg(@"mosThreshold beyond 5.0");
    }
    else
    {
        TUP_UINT32 mosThresholdReal = mosThreshold * 1000;
        TUP_RESULT ret_mos_threshold = tup_call_set_cfg(CALL_D_CFG_MEDIA_MOS_THRESHOLD, &mosThresholdReal);
        logDbg(@"mos threshold %d",mosThresholdReal);
        DUMP_TUP_API_EXECUTED_RESULT(CALL_D_CFG_MEDIA_MOS_THRESHOLD, ret_mos_threshold);
    }
    
    //"expires"设置  //OK
    TUP_UINT32 regExpires = 300;//[CESpaceLoginModel shareInstance].userInfo.infoFromMaa.regExpires;
    TUP_UINT32 regExpiresReal = ((regExpires >= 60 && regExpires <= 3600) ? regExpires : 300);
    TUP_RESULT ret_2 = tup_call_set_cfg(CALL_D_CFG_SIP_REGIST_TIMEOUT, &regExpiresReal);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_set_cfg__CALL_D_CFG_SIP_REGIST_TIMEOUT, ret_2);
    
    TUP_UINT32 sessionExpires = 1800;//[CESpaceLoginModel shareInstance].userInfo.infoFromMaa.sessionExpires;
    TUP_UINT32 sessionExpiresReal = ((sessionExpires >=90 && sessionExpires <= 3600 )? sessionExpires : 1800);
    TUP_RESULT ret_sessionExpires = tup_call_set_cfg(CALL_D_CFG_SIP_SESSIONTIME, &sessionExpiresReal);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_set_cfg__CALL_D_CFG_SIP_SESSIONTIME, ret_sessionExpires);
    
    TUP_UINT32 subTimeout = 300;//[CESpaceLoginModel shareInstance].userInfo.infoFromMaa.regExpires;
    TUP_UINT32 subTimeoutReal = ((regExpires >= 60 && regExpires <= 3600) ? subTimeout : 300);
    TUP_RESULT ret_4 = tup_call_set_cfg(CALL_D_CFG_SIP_SUBSCRIBE_TIMEOUT, &subTimeoutReal);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_set_cfg__CALL_D_CFG_SIP_SUBSCRIBE_TIMEOUT, ret_4);
    
    //todo,timeout时间为临时时间
    TUP_UINT32 reregisterTimeout = 20;
    TUP_RESULT ret_reregister = tup_call_set_cfg(CALL_D_CFG_SIP_REREGISTER_TIMEOUT, &reregisterTimeout);
    DUMP_TUP_API_EXECUTED_RESULT(tup_call_set_cfg__CALL_D_CFG_SIP_REREGISTER_TIMEOUT, ret_reregister);
    
    
}


#pragma mark - 私有方法

- (NSString *)serverAddress {
   // [AccountInfo sharedInstance].strSipServerIP = @"172.22.8.69";
    NSString *serverAddress = [AccountInfo sharedInstance].entryServerIp;
    return [ECSUtils notNilString:serverAddress];
}

- (NSString *)serverPort {
   // [AccountInfo sharedInstance].strSipServerPort = @"5060";
    NSString *serverPort = [AccountInfo sharedInstance].entryServerPort;
    return [ECSUtils notNilString:serverPort];
}

- (NSString *)getLocalIP {
    if ([_localIPAddress length] == 0) {
        return @"";
    }
    return _localIPAddress;
}

- (NSString *)IMPU {
    return _voipNumber;
}

-(NSString *)IMPI
{
    NSString * impu = [self IMPU];
    if ([impu length] == 0) {
        return @"";
    }
    NSString * impi = [ECSUtils removeDomainField:impu];
    
    if (isNeedAddDomainForHuaweiUC_) {
        impi = [ECSUtils addDomainField:impi domain:_selfUserDomain];
    }
    return [ECSUtils addPrefix:impi prefix:_countryCode];
}

- (NSString *)voipPassword {
    NSString *voipPassword = @"";
    return [ECSUtils notNilString:voipPassword];
}




@end
