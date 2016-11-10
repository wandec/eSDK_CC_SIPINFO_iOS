//
//  eSpaceCCSDK.m
//  eSpaceCCSDK
//
//  Created by gaoshuming on 15/11/3.
//  Copyright © 2015年 gaoshuming. All rights reserved.
//

#import "eSpaceCCSDK.h"
#import "Log.h"
#import "CallServiceImp.h"
#import "AnonymousCall.h"
#import "AccountInfo.h"
#import "ECSCallService.h"
#import "VTMCommonUtil.h"
#import "SIPDiaglogInfo.h"
#import "Reachability.h"
#import "eSDKIOSLog.h"
#import "Reachability.h"

#define ESDKLOG_PRODUCT @"eSDK-CC-API-iOS"

NSString *const CHECK_ISINWIFI = @"CHECK_ISINWIFI";//释放呼叫


static eSpaceCCSDK *g_eSpaceCCSDK = nil;

int getWIFIStatus()
{
    return [[eSpaceCCSDK sharedInstance] checkIfInWifiOrNot];
}

@implementation eSpaceCCSDK

+(eSpaceCCSDK *)sharedInstance
{
    @synchronized(self)
    {
        if (g_eSpaceCCSDK == nil) {
            g_eSpaceCCSDK = [[eSpaceCCSDK alloc]init];
            [[eSpaceCCSDK sharedInstance] loadESDKLog];
        }
    }
    return g_eSpaceCCSDK;
}

-(BOOL)loadeSpaceCCSDK
{
    logInit();
    [self setCallBack];
    [AccountInfo sharedInstance];
    [CallServiceImp sharedInstance];
    [ECSCallService sharedInstance];
    
    return YES;
}

-(BOOL)unloadeSpaceCCSDK
{
    [AccountInfo destroyInstance];
    [ECSCallService destroyInstance];
    [CallServiceImp destroyInstance];
    [AnonymousCall destroyInstance];
    
    return YES;
}

-(void)setLogSwitch:(BOOL)openOrClose
{
    setDBLogEnabledOpt(openOrClose);
}

- (short)setHostAddr:(NSString*)serverIP withPort:(NSUInteger)serverPort withCard:(NSString *)anonymousCard localPort:(NSString *)localPort
{
    NSLog(@"enter");
    NSLog(@"set server config with ip :%@ ,port:%lu",serverIP,(unsigned long)serverPort);
    
    NSString *nowDateStr = [self getCurrentTime];
    
    if ([serverIP length] == 0)
    {
        NSLog(@"nil or empty ip string");
        return RET_PARAM_ERROR;
    }
    
    BOOL isIPInvalid = [VTMCommonUtil isValidIP:serverIP];
    if (!isIPInvalid)
    {
        NSLog(@"ip is invalid");
        return RET_PARAM_ERROR;
    }
    BOOL isPortValid = [VTMCommonUtil isValidPort:serverPort];
    if ( !isPortValid)
    {
        NSLog(@"port is invalid");
        return RET_PARAM_ERROR;
    }
    
    if ([anonymousCard isEqualToString:@""])
    {
        anonymousCard = @"AnonymousCard";
    }
    
    BOOL isPortValid1 = [VTMCommonUtil isValidPort:[localPort integerValue]];
    if ( !isPortValid1)
    {
        NSLog(@"port is invalid");
        return RET_PARAM_ERROR;
    }
    
    NSString *portStr = [NSString stringWithFormat:@"%lu",(unsigned long)serverPort];
    
    [AccountInfo sharedInstance].entryServerIp = serverIP;
    [AccountInfo sharedInstance].entryServerPort = portStr;
    [AccountInfo sharedInstance].strSipServerPort = localPort;
    [AccountInfo sharedInstance].anonymousCardName = anonymousCard;
    
    NSString *nextDateStr = [self getCurrentTime];
    
    [[eSDKIOSLog getInstance] logInterfaceInfo:ESDKLOG_PRODUCT interfaceType:@"1" protocolType:@"SMPP" interfaceName:@"setHostAddr:withPort:" sourceAddr:@"" targetAddr:@"" transactionID:@"" reqTime:nowDateStr respTime:nextDateStr resultCode:[NSString stringWithFormat:@"%ld",(long)RET_OK] params:[NSString stringWithFormat:@"ip=%@,port=%lu",serverIP,(unsigned long)serverPort]];
    
    NSLog(@"end");
    return RET_OK;
}

#pragma mark anonymous call
-(short)anonymousCallWithAccessCode:(NSString *)accessCode
{
    NSString *nowDataStr = [self getCurrentTime];
    if (0 == [accessCode length])
    {
        NSLog(@"no accessCode set, can not make anonymous call");
        return RET_PARAM_ERROR;
    }
    
    //检查isa的服务器,端口有没有配置
    NSString *server = [AccountInfo sharedInstance].entryServerIp;
    if (0 == [server length])
    {
        NSLog(@"server is nil or emtpy");
        return RET_PARAM_ERROR;
    }
    
    NSString *token = [AccountInfo sharedInstance].identifyCode;
    if(0 == [token length])
    {
        NSLog(@"anonymous token is nil or emtpy");
        return RET_PARAM_ERROR;
    }
    
    [AnonymousCall sharedInstance];
    
    [AccountInfo sharedInstance].accessCode = accessCode;
    BOOL result = [[AnonymousCall sharedInstance] isInCall:accessCode];
    if (result)
    {
        NSString *nextDateStr = [self getCurrentTime];
        [[eSDKIOSLog getInstance] logInterfaceInfo:ESDKLOG_PRODUCT interfaceType:@"1" protocolType:@"SMPP" interfaceName:@"anonymousCallWithAccessCode " sourceAddr:@"" targetAddr:@"" transactionID:@"" reqTime:nowDataStr respTime:nextDateStr resultCode:[NSString stringWithFormat:@"%ld",(long)RET_OK] params:[NSString stringWithFormat:@"accessCode=%@",accessCode]];
        return RET_OK;
    }
    else
    {
        return RET_COMMON_EEROR;
    }
}

- (short)releaseCall
{
    NSString *nowDataStr = [self getCurrentTime];
    
    short returnCode = RET_OK;
    [[AnonymousCall sharedInstance] closeCall];
    [CallServiceImp closeCall];
    
    NSString *nextDateStr = [self getCurrentTime];
    [[eSDKIOSLog getInstance] logInterfaceInfo:ESDKLOG_PRODUCT interfaceType:@"1" protocolType:@"SMPP" interfaceName:@"releaseCall " sourceAddr:@"" targetAddr:@"" transactionID:@"" reqTime:nowDataStr respTime:nextDateStr resultCode:[NSString stringWithFormat:@"%d",returnCode] params:@""];
    return returnCode;
}

-(short)sendMessageWithMediaType:(NSString *)mediaType subType:(NSString *)subMediaType body:(NSString *)infoBody
{
    NSString *nowDateStr = [self getCurrentTime];
    [CallServiceImp sharedInstance];
    SIPDiaglogInfo *diaglogInfo = [[SIPDiaglogInfo alloc]init];
    diaglogInfo.mediaType = mediaType;
    diaglogInfo.subMediaType = subMediaType;
    diaglogInfo.body = infoBody;
    
    if ([infoBody length] > 0)
    {
       short ret = [[CallServiceImp sharedInstance] sendSIPDiaglogInfo:diaglogInfo];
        NSLog(@"diaglogInfo.mediaType and diaglogInfo.subMediaType %@,,%@,,%@",diaglogInfo.mediaType,diaglogInfo.subMediaType,diaglogInfo.body);
        if (ret)
        {
            NSString *nextDateStr = [self getCurrentTime];
            [[eSDKIOSLog getInstance] logInterfaceInfo:ESDKLOG_PRODUCT interfaceType:@"1" protocolType:@"SMPP" interfaceName:@"sendMessageWithMediaType:subType:body:" sourceAddr:@"" targetAddr:@"" transactionID:@"" reqTime:nowDateStr respTime:nextDateStr resultCode:[NSString stringWithFormat:@"%d",RET_OK] params:[NSString stringWithFormat:@"mediaType=%@,subMediaType=%@,infoBody=%@",mediaType,subMediaType,infoBody]];
            
            NSLog(@"sendSIPDiaglogInfo ret:%d",ret);
            return RET_OK;
        }
        else
        {
            NSLog(@"send message failed:%d",ret);
            return RET_COMMON_EEROR;
        }
    }
    else
    {
        NSLog(@"message is nil ");
        return RET_PARAM_ERROR;
    }
}

#pragma mark - 日志采集
-(void)loadESDKLog
{
    //设置输入日志接口
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDicrectory = [paths objectAtIndex:0];
    NSString *logPath = [documentsDicrectory stringByAppendingString:@"/log"];
    
    //设置配置文件目录
    
    NSString *filePath = [[NSBundle mainBundle]pathForResource:@"eSDKClientLogCfg" ofType:@"plist"];
    NSLog(@"filePath:%@",filePath);
    //日志模块初始化
    unsigned int level[LOG_CATEGORY]={0};
    
    [[eSDKIOSLog getInstance] logInit:ESDKLOG_PRODUCT iniFile:filePath logLevel:level logPath:logPath];
}

-(int)checkIfInWifiOrNot
{
    if ([self isCurrentReachableViaWiFi])
    {
        NSLog(@"wifi。。。。");
        return 1;
    }
    else
    {
        NSLog(@"not wifi。。。。");
        return 0;
    }
}

- (BOOL)isCurrentReachableViaWiFi
{
    NetworkStatus netStatus = [[Reachability reachabilityForInternetConnection] currentReachabilityStatus];
    return netStatus == ReachableViaWiFi;
}

-(void)setCallBack
{
    NSString *serverPath = @"esdk-log.huawei.com:9086";
    [[eSDKIOSLog getInstance] esdk_log_setSendLogStrategy:0 wifiFlag:1 serverPath:[serverPath UTF8String]];
    [[eSDKIOSLog getInstance] setCallBackMethod:getWIFIStatus];
    [[eSDKIOSLog getInstance] initMobileLog:[ESDKLOG_PRODUCT UTF8String]];
}

-(NSString *)getCurrentTime
{
    NSDate *nowDate = [NSDate date];
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    dateFormatter.dateFormat = @"yyyy-MM-dd HH:mm:ss SSS";
    NSString *nowDateStr = [dateFormatter stringFromDate:nowDate];
    return nowDateStr;
}


@end
