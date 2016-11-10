//
//  CallServiceManger.m
//  VTMSDK
//
//  Created by gaoshuming on 15/10/20.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import "CallServiceManger.h"
#import "Log.h"
#import "ECSUtils.h"
#import "SubNotifyResult.h"
#import "ECSCallService.h"
#import "ECSNotifications.h"
#import "CallServiceImp.h"
#import "ECSNotificationCenter.h"
#import <UIKit/UIKit.h>

@interface FSMExecuteResult : NSObject
{
    BOOL isExecSucces_;
    BOOL isMsgHandled_;
}

@property (nonatomic, assign, readonly) BOOL isExecSucces;
@property (nonatomic, assign, readonly) BOOL isMsgHandled;

+ (FSMExecuteResult *)fsmExecResultWithIsMsgHandled:(BOOL)isMsgHandled andIsResultSuccess:(BOOL)isResultSuccess;

@end

@implementation FSMExecuteResult

@synthesize isExecSucces = isExecSucces_;
@synthesize isMsgHandled = isMsgHandled_;

- (id)initWithIsMsgHandled:(BOOL)isMsgHandled andIsResultSuccess:(BOOL)isResultSuccess {
    if (self = [super init]) {
        isMsgHandled_ = isMsgHandled;
        isExecSucces_ = isResultSuccess;
    }
    return self;
}

+ (FSMExecuteResult *)fsmExecResultWithIsMsgHandled:(BOOL)isMsgHandled andIsResultSuccess:(BOOL)isResultSuccess {
    return [[FSMExecuteResult alloc] initWithIsMsgHandled:isMsgHandled andIsResultSuccess:isResultSuccess];
}

@end

@interface FSMMsg : NSObject
{
    EN_CALL_MSG_TYPE msgType_;
    void * param_;
}

@property (nonatomic, assign, readonly) EN_CALL_MSG_TYPE msgType;
@property (nonatomic, assign, readonly) void * param;

+ (FSMMsg *)fsmMsgWithType:(EN_CALL_MSG_TYPE)msgType andParam:(void *)param;

@end

@implementation FSMMsg

@synthesize msgType = msgType_;
@synthesize param = param_;

- (id)initWithType:(EN_CALL_MSG_TYPE)msgType andParam:(void *)param {
    if (self = [super init]) {
        msgType_ = msgType;
        param_ = param;
    }
    return self;
}

+ (FSMMsg *)fsmMsgWithType:(EN_CALL_MSG_TYPE)msgType andParam:(void *)param {
    return [[FSMMsg alloc] initWithType:msgType andParam:param];
}

@end

@interface FSMHandler : NSObject
{
    SEL selector_;
}

@property (nonatomic, assign, readonly) SEL selector;

+ (FSMHandler *)fsmHandlerWithSelector:(SEL)selector;

- (FSMExecuteResult *)performStateHandlerWithTarget:(CallServiceManger *)target withMsg:(FSMMsg *)msg;

@end

@implementation FSMHandler

@synthesize selector = selector_;

- (id)initWithSelector:(SEL)selector {
    if (self = [super init]) {
        selector_ = selector;
    }
    return self;
}

+ (FSMHandler *)fsmHandlerWithSelector:(SEL)selector {
    return [[FSMHandler alloc] initWithSelector:selector];
}

- (FSMExecuteResult *)performStateHandlerWithTarget:(CallServiceManger *)target withMsg:(FSMMsg *)msg {
    if ([target respondsToSelector:selector_]) {
        return [target performSelector:selector_ withObject:msg];
    }
    return [FSMExecuteResult fsmExecResultWithIsMsgHandled:NO andIsResultSuccess:NO];
}

@end

@interface CallServiceManger ()

@property (nonatomic, copy) NSString * scheduleConfId;
@property (nonatomic, copy) NSString *  accessCode;
@property (nonatomic, copy) NSString *  passCode;

@end

#define   NTF_SIP_TRANSFER_SUCCESS                      @"NTF_SIP_TRANSFER_SUCCESS"
#define   NTF_SIP_TRANSFER_FAILED                       @"NTF_SIP_TRANSFER_FAILED"
#define WRN_UNKNWON_MSG_IN_STATE_HANDLERS(msgType) do { logWarn(@"Unknwon msg[%s] for state[%s]",[[self dumpEventInfo:msgType] UTF8String],[[self dumpStateInfo:currentCallState_] UTF8String]); } while(0)

@implementation CallServiceManger

static CallServiceManger *g_callServiceMangerInstance = Nil;

-(id)init
{
    if (self = [super init]) {
        [self initCallStatesTimedoutLen];
        lastCallState_ = EN_CALL_IDLE;
        currentCallState_ = EN_CALL_IDLE;
        
        [self addDebugInfo];
        [self initStateHandlers];
    }
    return self;
}

+ (CallServiceManger *)getCallserviceInstance {
    if (Nil == g_callServiceMangerInstance) {
        g_callServiceMangerInstance = [[CallServiceManger alloc] init];
    }
    return g_callServiceMangerInstance;
}

+ (void)destoryCallServiceInstance {
    if (nil != g_callServiceMangerInstance) {
        g_callServiceMangerInstance = nil;
    }
}

-(void)addDebugInfo
{
    ECSUTILES_ADD_ENUM_DESCRIPTION(EN_CALL_IDLE, EnumDescType_CallServiceState);
    ECSUTILES_ADD_ENUM_DESCRIPTION(EN_CALL_RECV, EnumDescType_CallServiceState);
    ECSUTILES_ADD_ENUM_DESCRIPTION(EN_CALL_START, EnumDescType_CallServiceState);
    ECSUTILES_ADD_ENUM_DESCRIPTION(EN_CALL_PROCEEDING, EnumDescType_CallServiceState);
    ECSUTILES_ADD_ENUM_DESCRIPTION(EN_CALL_RUNNING, EnumDescType_CallServiceState);
    ECSUTILES_ADD_ENUM_DESCRIPTION(EN_CALL_TRANSFERING, EnumDescType_CallServiceState);
    
    ECSUTILES_ADD_ENUM_DESCRIPTION(MSG_CMD_START_CALL, EnumDescType_CallServiceEvt);
}

#pragma mark -
#pragma mark init/dealloc

- (void)initCallStatesTimedoutLen {
    callStateTimedoutLenDict_ = [[NSDictionary alloc] initWithObjectsAndKeys:
                                 [NSNumber numberWithInt:90], [NSString stringWithFormat:@"%d", EN_CALL_RECV],
                                 [NSNumber numberWithInt:90], [NSString stringWithFormat:@"%d", EN_CALL_START],
                                 [NSNumber numberWithInt:90], [NSString stringWithFormat:@"%d", EN_CALL_PROCEEDING],
                                 [NSNumber numberWithInt:90], [NSString stringWithFormat:@"%d", EN_CALL_TRANSFERING],
                                 [NSNumber numberWithInt:15], [NSString stringWithFormat:@"%d", EN_WAITING_CONF_INVITE],
                                 nil];
}

#pragma mark -
#pragma mark 对外接口

- (BOOL)isCallFSMStateIdle {
    
    
    return currentCallState_ == EN_CALL_IDLE;
}


- (BOOL)handleMsg:(FSMMsg *)msg
{
   // currentCallState_ = EN_CALL_IDLE;
    logDbg(@"Process msg[%s] at state[%s].",[[self dumpEventInfo:msg.msgType] UTF8String],[[self dumpStateInfo:currentCallState_] UTF8String]);
    FSMHandler * handler = [self stateHandlerWithState:currentCallState_];
    FSMExecuteResult * handleResult = [handler performStateHandlerWithTarget:self withMsg:msg];
    return handleResult.isMsgHandled ? handleResult.isExecSucces : [self handleMissingMsg:msg];
}

- (NSString *)dumpEventInfo:(EN_CALL_MSG_TYPE)eventType {
    return [ECSUtils enumDescription:eventType forType:EnumDescType_CallServiceEvt];
}

- (BOOL)CallService_ProcCallStateMsg:(EN_CALL_MSG_TYPE)enCallMsgType args:(void *)arg {
    NSLog(@"enCallMsgType and arg:%u,%@",enCallMsgType,arg);
    return [self handleMsg:[FSMMsg fsmMsgWithType:enCallMsgType andParam:arg]];
}

- (NSString *)dumpStateInfo:(EN_CALL_STATE)state
{
    return [ECSUtils enumDescription:state forType:EnumDescType_CallServiceState];
}


- (FSMHandler *)stateHandlerWithState:(EN_CALL_STATE)state {
    if (nil == callStateHandlers_) {
        return [FSMHandler fsmHandlerWithSelector:NULL];
    }
    FSMHandler *handler = [callStateHandlers_ objectForKey:[NSString stringWithFormat:@"%d", state]];
    return handler != nil ? handler : [FSMHandler fsmHandlerWithSelector:NULL];
}


#pragma mark -
#pragma mark 状态机入口

- (BOOL)handleMissingMsg:(FSMMsg *)msg
{
    logDbg(@"Process missing msg[%s] at state[%s]." ,[[self dumpEventInfo:msg.msgType] UTF8String] ,[[self dumpStateInfo:currentCallState_] UTF8String]);
    switch (msg.msgType)
    {
        case MSG_NTF_CALL_TRANSFER_NOTIFY:
        {
            SubNotifyResult * subNotifyResult = (SubNotifyResult *)msg.param;
            if (subNotifyResult == nil || ![subNotifyResult isKindOfClass:[SubNotifyResult class]]) {
                return YES;
            }
            
            if ([subNotifyResult isResultTrying]) {
                return YES;
            }
            
            if ([subNotifyResult isResultSuccess]) {
                [[NSNotificationCenter defaultCenter] postNotificationName:NTF_SIP_TRANSFER_SUCCESS object:nil];
            }
            else {
                NSDictionary * retDict = [NSDictionary dictionaryWithObject:[NSNumber numberWithInt:[subNotifyResult.statusCode intValue]] forKey:ECSCommonKeyResultCode];
                [[NSNotificationCenter defaultCenter] postNotificationName:NTF_SIP_TRANSFER_FAILED object:nil userInfo:retDict];
            }
            return YES;
        }
            
        default:
            logWarn(@"Missing msg[%s] at state[%s]" ,[[self dumpEventInfo:msg.msgType] UTF8String] ,[[self dumpStateInfo:currentCallState_] UTF8String]);
            
            break;
    }
    return NO;
}

- (void)initStateHandlers {
    callStateHandlers_ = [[NSDictionary alloc] initWithObjectsAndKeys:
                          [FSMHandler fsmHandlerWithSelector:@selector(handleMsgAtCallIdle:)], [NSString stringWithFormat:@"%d", EN_CALL_IDLE],
                          [FSMHandler fsmHandlerWithSelector:@selector(handleMsgAtCallRecv:)], [NSString stringWithFormat:@"%d", EN_CALL_RECV],
                          [FSMHandler fsmHandlerWithSelector:@selector(handleMsgAtCallStart:)], [NSString stringWithFormat:@"%d", EN_CALL_START],
                          [FSMHandler fsmHandlerWithSelector:@selector(handleMsgAtCallProcessing:)], [NSString stringWithFormat:@"%d", EN_CALL_PROCEEDING],
                          [FSMHandler fsmHandlerWithSelector:@selector(handleMsgAtCallRunning:)], [NSString stringWithFormat:@"%d", EN_CALL_RUNNING],
                          [FSMHandler fsmHandlerWithSelector:@selector(handleMsgAtCallTransfering:)], [NSString stringWithFormat:@"%d", EN_CALL_TRANSFERING],
                         // [FSMHandler fsmHandlerWithSelector:@selector(handleMsgAtCallWaitingConfInvite:)], [NSString stringWithFormat:@"%d", EN_WAITING_CONF_INVITE],
                          nil];
}

- (FSMExecuteResult *)handleMsgAtCallTransfering:(FSMMsg *)msg {
    EN_CALL_MSG_TYPE enCallMsgType = msg.msgType;
    void * arg = msg.param;
    BOOL ret = YES;
    
    switch (enCallMsgType) {
        case MSG_NTF_CALL_TRANSFER_ACK:
          //  [self CallService_CallTransferingProcTransferAck:(__bridge NSString *)arg];
            break;
            
        case MSG_NTF_CALL_TRANSFER_NOTIFY:
            //ret = [self CallService_CallTransferingProcTransferNotify:(__bridge SubNotifyResult*)arg];
            break;
            
        case MSG_NTF_SIP_BYE:
            [self changeToIdleAndNotifyCallClosedWithReason:(__bridge NSString *)arg];
            break;
            
        case MSG_NTF_SIP_PEER_HELD:
            [ECSNotificationCenter postNotificationName:NTF_SIP_PEER_HELD object:nil];
            break;
            
        case MSG_NTF_SIP_PEER_RETRIEVED:
            [ECSNotificationCenter postNotificationName:NTF_SIP_PEER_RETRIEVED object:nil];
            break;
            
        case MSG_CMD_CLOSE_CALL:
        case MSG_CMD_ABNORMAL_TERMINATE:
        {
            [self closeCallAndChangeToIdle];
        }
            
            break;
            
        case MSG_NTF_CALL_SESSION_MODIFY_ALERTING:
          //  [CallServiceProxy answerCallWithSendMode:AudioSendMode_SendRecv isAudioOnly:NO];
            break;
            
        default:
            WRN_UNKNWON_MSG_IN_STATE_HANDLERS(enCallMsgType);
            return [FSMExecuteResult fsmExecResultWithIsMsgHandled:NO andIsResultSuccess:NO];
    }
    
    return [FSMExecuteResult fsmExecResultWithIsMsgHandled:YES andIsResultSuccess:ret];
}

- (FSMExecuteResult *)handleMsgAtCallRunning:(FSMMsg *)msg {
    EN_CALL_MSG_TYPE enCallMsgType = msg.msgType;
    void * arg = msg.param;
    BOOL  ret = YES;
    
    switch (enCallMsgType) {
        case MSG_NTF_SIP_BYE:
            [self changeToIdleAndNotifyCallClosedWithReason:(__bridge NSString *)arg];
            break;
            
        case MSG_CMD_TRANSFER_CALL:
            ret = [self CallService_CallRunningProcTransferCmd:(__bridge NSDictionary *)arg];
            break;
            
        case MSG_CMD_SEND_DTMF:
            ret = [ self CallService_SendDtmf:(__bridge NSString *)arg];
            break;
            
        case MSG_CMD_CALL_CONTROL_VOICE_MAIL_PALY:
            ret = [self CallService_CallRunningProcControlVoiceMailPlay:(__bridge NSString *)arg];
            break;
            
        case MSG_CMD_HOLD_CALL:
            ret = [CallServiceImp holdCall];
            break;
            
        case MSG_CMD_RESUME_CALL:
            //ret = [CallServiceProxy resumeCall];
            break;
            
        case MSG_NTF_SIP_HOLD_RESULT:
            [ECSNotificationCenter postNotificationName:ECSCallHoldOrResumeResultNotify object:nil
                                         withUserObject:[NSNumber numberWithInt:([(__bridge NSNumber *)arg boolValue] ? kECSSuccess : kECSFailure)]
                                                 forKey:ECSCommonKeyResultCode
                                        withUserObject2:[NSNumber numberWithBool:YES]
                                                forKey2:ECSIsSelfHoldCallKey];
            break;
        case MSG_NTF_SIP_RESUME_RESULT:
            [ECSNotificationCenter postNotificationName:ECSCallHoldOrResumeResultNotify object:nil
                                         withUserObject:[NSNumber numberWithInt:([(__bridge NSNumber *)arg boolValue] ? kECSSuccess : kECSFailure)]
                                                 forKey:ECSCommonKeyResultCode
                                        withUserObject2:[NSNumber numberWithBool:NO]
                                                forKey2:ECSIsSelfHoldCallKey];
            break;
            
        case MSG_NTF_SIP_PEER_HELD:
            [ECSNotificationCenter postNotificationName:NTF_SIP_PEER_HELD object:nil];
            break;
            
        case MSG_NTF_SIP_PEER_RETRIEVED:
            [ECSNotificationCenter postNotificationName:NTF_SIP_PEER_RETRIEVED object:nil];
            break;
            
        case MSG_CMD_MODIFY_CALL_SESSION_SENDMODE_SENDRECV:
           // [CallServiceProxy modifyCallSendMode:AudioSendMode_SendRecv];
            break;
            
        case MSG_NTF_SIP_PEER_ANSWER_CALL:
            ret =[self CallService_CallRunningProcPeerACK];
            
            break;
        case MSG_CMD_START_VIDEO_CALL:
           // ret = [CallServiceProxy modifyCallSessionWithAddVideo];
            break;
        case MSG_CMD_CALL_REMOVE_VIDEO:
           // ret =[CallServiceProxy modifyCallSessionWithRemoveVideo];
            break;
        case MSG_CMD_ACCEPT_CALL_SESSION_MODIFY:
           // ret =[CallServiceProxy acceptCallSessionModify];
            break;
        case MSG_CMD_REFUSE_CALL_SESSION_MODIFY:
          //  ret =[CallServiceProxy refuseCallSessionModify];
            break;
        case MSG_CMD_CANCEL_CALL_SESSION_MODIFY:
          //  ret =[CallServiceProxy cancelCallSessionModify];
            break;
        case MSG_NTF_CALL_SESSION_MODIFIED_RESULT:
            ret = YES;
            [[NSNotificationCenter defaultCenter] postNotificationName:ECSCallSessionModifyResultNotify object:nil userInfo:(__bridge NSDictionary *)arg];
            break;
        case MSG_NTF_CALL_SESSION_MODIFY_ALERTING:
            ret = YES;
            [[NSNotificationCenter defaultCenter] postNotificationName:ECSAddVideoCallAlerting object:nil userInfo:(__bridge NSDictionary *)arg];
            break;
        case MSG_NTF_CALL_SESSION_MODIFIED_CANCELED:
            ret = YES;
            [[NSNotificationCenter defaultCenter] postNotificationName:ECSAddVideoCallCanceled object:nil userInfo:(__bridge NSDictionary *)arg];
            break;
            
        case MSG_NTF_SIP_UPDATED_TO_CONF:
          //  [self CallService_CallRunningProcUCV2GroupUri:(UCV2GroupURI*)arg];
            break;
            
        case MSG_CMD_RESUME_CALL_CONTROL_SESSION:
        {
           // ret = [CallServiceProxy modifyCallSessionWithControlMode:YES];
            break;
        }
            
        case MSG_CMD_SUSPEND_CALL_CONTROL_SESSION:
        {
          //  ret = [CallServiceProxy modifyCallSessionWithControlMode:NO];
            break;
        }
            
        case MSG_CMD_CLOSE_CALL:
        case MSG_CMD_ABNORMAL_TERMINATE:
            [self closeCallAndChangeToIdle];
            break;
            
        default:
            WRN_UNKNWON_MSG_IN_STATE_HANDLERS(enCallMsgType);
            return [FSMExecuteResult fsmExecResultWithIsMsgHandled:NO andIsResultSuccess:NO];
    }
    
    return [FSMExecuteResult fsmExecResultWithIsMsgHandled:YES andIsResultSuccess:ret];
}

-(BOOL)CallService_CallRunningProcPeerACK
{
    [ECSNotificationCenter postNotificationName:NTF_SIP_PEER_ANSWER_ACK object:nil];
    //if (isMediaXConf && !hasSDP) {
    //之前是HWUC MediaX会议来电不带SDP，重协商，现在是HWUC 所有不带SDP的来电均重协商
    //    if (SERVERTYPE_UC_HW == [[eSpaceIOSSDK userService] serverType] && !hasSDP) {
    //		[self performSelector:@selector(modifyCallSessionSendRecv) withObject:nil afterDelay:1]; // mediaX会议外呼无SDP重协商媒体，需要延时一段时间协商
    //	}
    return YES;
}

-(BOOL)CallService_CallRunningProcTransferCmd:(NSDictionary*)transferInfo
{
    NSString * targetNum = [transferInfo objectForKey:TRANSFER_TARGET_KEY];
    NSNumber * transferType = [transferInfo objectForKey:TRANSFER_TYPE_KEY];
    if ([targetNum length] == 0) {
        return NO;
    }
    if (nil == transferType) {
        transferType = [NSNumber numberWithInt:EN_TRANS_CALL_TO_CALL];
    }
//    if(![CallServiceProxy sendReferToTarget:targetNum transferType:((EN_TRANSFER_TYPE)[transferType intValue])])
//    {
//        return  NO;
//    }
   // [self changeToNewCallState:EN_CALL_TRANSFERING];
    return YES;  
}

-(BOOL)CallService_CallRunningProcControlVoiceMailPlay:(NSString *)cmdCode {
    /*
    NSInteger iDialNum = [self convertDTMFCharacterToInt:cmdCode];
    if (-1 == iDialNum) {
        return NO;
    }
    return [CallServiceProxy controlVoiceMessagePlayingByCmdCode:(VoiceMailPlayControlMode)iDialNum];
     */
    NSLog(@"对语音留言进行操作(播放、快进、快退)-----该接口好像已经被废弃，统一使用二次拨号方式实现//待确认");
    return YES;
}

#pragma mark -
#pragma mark 状态机处理函数 (EN_CALL_PROCEEDING)
- (FSMExecuteResult *)handleMsgAtCallProcessing:(FSMMsg *)msg {
    EN_CALL_MSG_TYPE enCallMsgType = msg.msgType;
    void * arg = msg.param;
    BOOL  ret = YES;
    
    switch (enCallMsgType) {
        case MSG_NTF_SIP_PEER_ANSWER_CALL:
        {
           // [self changeToNewCallState:EN_CALL_RUNNING];
            [ECSNotificationCenter postNotificationName:NTF_SIP_PEER_ANSWER_CALL object:nil userInfo:(__bridge NSDictionary*)arg];
            break;
        }
            
        case MSG_NTF_SIP_BYE:
            [self changeToIdleAndNotifyCallClosedWithReason:(__bridge NSString *)arg];
            break;
            
        case MSG_NTF_SIP_PEER_ALERTING:
        {
            [ECSNotificationCenter postNotificationName:NTF_SIP_PEER_ALERTING object:nil userInfo:(__bridge NSDictionary*)arg];
            break;
        }
            //add on 2013.5.29,对方彩铃,183
        case MSG_NTF_SIP_PEER_PROGRESS:
        {
            [ECSNotificationCenter postNotificationName:NTF_SIP_183_PROGRESS object:nil userInfo:(__bridge NSDictionary*)arg];
            break;
        }
            //end add on 2013.5.29
            
        case MSG_NTF_SIP_PEER_FORWARD:
        {
            [ECSNotificationCenter postNotificationName:NTF_SIP_PEER_FORWARD object:nil userInfo:(__bridge NSDictionary *)arg];
            break;
        }
        case MSG_CMD_SEND_DTMF:
        {
            ret = [self CallService_SendDtmf:(__bridge NSString *)arg];
            break;
        }
            
        case MSG_CMD_CLOSE_CALL:
        case MSG_CMD_ABNORMAL_TERMINATE:
        {
            [self closeCallAndChangeToIdle];
            break;
        }
            
        default:
            WRN_UNKNWON_MSG_IN_STATE_HANDLERS(enCallMsgType);
            return [FSMExecuteResult fsmExecResultWithIsMsgHandled:NO andIsResultSuccess:NO];
    }
    
    return [FSMExecuteResult fsmExecResultWithIsMsgHandled:YES andIsResultSuccess:ret];
}

-(BOOL)CallService_SendDtmf:(NSString *)dialNum
{
    int iDialNum = [self convertDTMFCharacterToInt:dialNum];
    if (iDialNum == -1) {
        return NO;
    }
    return [CallServiceImp sendDTMF:iDialNum];
}

#pragma mark -
#pragma mark 状态无关的事件处理

/*!
 @method
 @abstract   dtmf字符转换到数字
 @discussion 转换失败返回－1
 */
- (NSInteger)convertDTMFCharacterToInt:(NSString *)_DTMFCharacter
{
    if ([_DTMFCharacter length] != 1) {
        return -1;
    }
    NSRange subRange = [@"*#abcd" rangeOfString:_DTMFCharacter];
    
    if (subRange.length == 0) { //为数字
        return [_DTMFCharacter intValue];
    }else {
        if ([_DTMFCharacter isEqualToString:@"*"]) {
            return 0x0a;
        }else if ([_DTMFCharacter isEqualToString:@"#"]){
            return 0x0b;
        }else if ([_DTMFCharacter caseInsensitiveCompare:@"a"]==NSOrderedSame) {
            return 0x0c;
        }else if ([_DTMFCharacter caseInsensitiveCompare:@"b"]==NSOrderedSame) {
            return 0x0d;
        }else if ([_DTMFCharacter caseInsensitiveCompare:@"c"]==NSOrderedSame) {
            return 0x0e;
        }else if ([_DTMFCharacter caseInsensitiveCompare:@"d"]==NSOrderedSame) {
            return 0x0f;
        }
    }
    return -1;
}

#pragma mark -
#pragma mark 状态机处理函数 (EN_CALL_START)

- (FSMExecuteResult *)handleMsgAtCallStart:(FSMMsg *)msg {
    EN_CALL_MSG_TYPE enCallMsgType = msg.msgType;
    void * arg = msg.param;
    BOOL  ret = YES;
    
    switch (enCallMsgType) {
        case MSG_NTF_SIP_PEER_ALERTING:
        {
           // [self changeToNewCallState:EN_CALL_PROCEEDING];
            [ECSNotificationCenter postNotificationName:NTF_SIP_PEER_ALERTING object:nil userInfo:(__bridge NSDictionary*)arg];
            break;
        }
            //add on 2013.5.29,对方彩铃,183
        case MSG_NTF_SIP_PEER_PROGRESS:
        {
           // [self changeToNewCallState:EN_CALL_PROCEEDING];
            [ECSNotificationCenter postNotificationName:NTF_SIP_183_PROGRESS
                                                 object:nil
                                               userInfo:(__bridge NSDictionary*)arg];
            break;
        }
            //end add on 2013.5.29
            
        case MSG_NTF_SIP_PEER_FORWARD:
        {
           // [self changeToNewCallState:EN_CALL_PROCEEDING];
            [ECSNotificationCenter postNotificationName:NTF_SIP_PEER_FORWARD object:nil userInfo:(__bridge NSDictionary *)arg];
            break;
        }
            
        case MSG_NTF_SIP_PEER_ANSWER_CALL:
        {
           // [self changeToNewCallState:EN_CALL_RUNNING];
            [ECSNotificationCenter postNotificationName:NTF_SIP_PEER_ANSWER_CALL object:nil userInfo:(__bridge NSDictionary*)arg];
            break;
        }
            
        case MSG_NTF_SIP_BYE:
            [self changeToIdleAndNotifyCallClosedWithReason:(__bridge NSString *)arg];
            break;
            
        case MSG_NTF_SIP_PEER_UNAVAILABLE:
        {
           // [self changeToNewCallState:EN_CALL_IDLE];
            [ECSNotificationCenter postNotificationName:NTF_SIP_PEER_UNAVAILABLE object:nil];
            break;
        }
            
        case MSG_CMD_CLOSE_CALL:
        case MSG_CMD_ABNORMAL_TERMINATE:
        {
            [self closeCallAndChangeToIdle];
            break;
        }
            
        default:
            WRN_UNKNWON_MSG_IN_STATE_HANDLERS(enCallMsgType);
            return [FSMExecuteResult fsmExecResultWithIsMsgHandled:NO andIsResultSuccess:NO];
    }
    
    return [FSMExecuteResult fsmExecResultWithIsMsgHandled:YES andIsResultSuccess:ret];
}

- (FSMExecuteResult *)handleMsgAtCallIdle:(FSMMsg *)msg {
    EN_CALL_MSG_TYPE enCallMsgType = msg.msgType;
    void * arg = msg.param;
    BOOL ret = YES;
    switch (enCallMsgType)
    {
        case MSG_CMD_START_CALL:
        {
            ret = [self CallService_CallIdleProcStartCall:(__bridge NSString *)arg callType:VOIP_CALL_AUDIO];
            break;
        }
        case MSG_CMD_START_VIDEO_CALL:
        {
            ret = [self CallService_CallIdleProcStartCall:(__bridge NSString *)arg callType:VOIP_CALL_VIDEO];
            break;
        }
        case MSG_CMD_JOIN_SCHEDULE_CONF:
        {
            ret = [self CallService_CallIdleProcJoinScheduleConf:(__bridge NSDictionary *)arg];
            break;
        }
        case MSG_NTF_SIP_INCOMING_CALL:
        {
            ret = [self CallService_CallIdleProcIncomingCall:(__bridge NSDictionary *)arg];
            break;
        }
        case MSG_NTF_SIP_INCOMING_CONFERENCE_CALL:
        {
            ret = [self CallService_CallIdleProcConferenceCall:(__bridge ConfInviteInfo *)arg];
            break;
        }
        case MSG_CMD_CALL_PLAY_VOICE_MAIL:
        {
            ret = [self CallService_CallIdleProcPlayVoiceMail:(__bridge NSDictionary *)arg];
            break;
        }
        case MSG_CMD_ABNORMAL_TERMINATE:
            // Do nothing here.
            break;
            
        default:
        {
            WRN_UNKNWON_MSG_IN_STATE_HANDLERS(enCallMsgType);
            return [FSMExecuteResult fsmExecResultWithIsMsgHandled:NO andIsResultSuccess:NO];
        }
    }
    
    return [FSMExecuteResult fsmExecResultWithIsMsgHandled:YES andIsResultSuccess:ret];
}

- (FSMExecuteResult *)handleMsgAtCallRecv:(FSMMsg *)msg {
    EN_CALL_MSG_TYPE enCallMsgType = msg.msgType;
    void * arg = msg.param;
    
    BOOL ret = YES;
    
    switch (enCallMsgType) {
        case MSG_CMD_ANSWER_CALL:
            ret = [self CallService_CallRecvProcAnswerCall:(__bridge NSDictionary*)arg];
            break;
            
        case MSG_NTF_SIP_BYE:
            [self changeToIdleAndNotifyCallClosedWithReason:(__bridge NSString *)arg];
            break;
            
        case MSG_CMD_CLOSE_CALL:
        case MSG_CMD_ABNORMAL_TERMINATE:
        {
            [self closeCallAndChangeToIdle];
            
        }
            
            break;
            
        default:
            WRN_UNKNWON_MSG_IN_STATE_HANDLERS(enCallMsgType);
            return [FSMExecuteResult fsmExecResultWithIsMsgHandled:NO andIsResultSuccess:NO];
    }
    
    return [FSMExecuteResult fsmExecResultWithIsMsgHandled:YES andIsResultSuccess:ret];
}

#pragma mark -
#pragma mark 状态机处理函数 (EN_CALL_RECV)

-(BOOL)CallService_CallRecvProcAnswerCall:(NSDictionary*)answerInfo{
    CallServiceAudioSendMode mode = AudioSendMode_SendRecv;
    BOOL onlyAudio = [[answerInfo objectForKey:CALL_ANSWER_AUDIOONLY] boolValue];
    
    
    //	if ([[eSpaceIOSSDK SDKConfigForKey:ECSDeviceTypeKey] isEqualToString:DEVICE_TYPE_IPHONE]) {
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone){
        mode = (CallServiceAudioSendMode)[[answerInfo objectForKey:CALL_ANSWER_SENDMODE] intValue];
    }
    else {
        // 如果是mediaX会议外呼同时invite中没有sdp信息，则先回inactive，再重协商成sendrecv
        //mode = ((isMediaXConf && !hasSDP) ? AudioSendMode_Inactive : AudioSendMode_SendRecv);
        // 现在放宽为HWUC只要没有sdp，则先回inactive，再重协商成sendrecv
        //mode = ((SERVERTYPE_UC_HW == [[eSpaceIOSSDK userService] serverType] && !hasSDP) ? AudioSendMode_Inactive : AudioSendMode_SendRecv);\
        //当前最新方案，来电不带SDP ，重协商即可，不用回inactive
        mode = AudioSendMode_SendRecv;
    }
    
    if(![CallServiceImp answerCallWithSendMode:mode isAudioOnly:onlyAudio]) {
        return  NO;
    }
    //[self changeToNewCallState:EN_CALL_RUNNING];
    return YES;
}

- (void)changeToIdleAndNotifyCallClosedWithReason:(NSString *)callClosedReason {
   // [self changeToNewCallState:EN_CALL_IDLE];
    [ECSNotificationCenter postNotificationName:NTF_SIP_BYE object:callClosedReason];
    
}

- (BOOL)CallService_CallIdleProcJoinScheduleConf:(NSDictionary *)confInfo
{
    RETURN_NO_IF_PARAM_NIL(confInfo);
    self.scheduleConfId = [confInfo objectForKey:@"conferenceid"];
    self.accessCode = [confInfo objectForKey:@"accesscode"];
    self.passCode = [confInfo objectForKey:@"passcode"];
    RETURN_NO_IF_PARAM_TEXT_EMPTY(self.scheduleConfId);
   // [self changeToNewCallState:EN_WAITING_CONF_INVITE];
    return YES;
}

-(BOOL)CallService_CallIdleProcIncomingCall:(NSDictionary *)comingCallDic {
    RETURN_NO_IF_PARAM_NIL(comingCallDic);
    
    NSString * callerNumber = [comingCallDic objectForKey:CALL_FROMNUMBER];
    RETURN_NO_IF_PARAM_TEXT_EMPTY(callerNumber);
    
   // [self changeToNewCallState:EN_CALL_RECV];
    [ECSNotificationCenter postNotificationName:NTF_SIP_INCOMING_CALL object:nil userInfo:comingCallDic];
    return YES;
}

- (BOOL)CallService_CallIdleProcConferenceCall:(ConfInviteInfo *)conf {
    RETURN_NO_IF_PARAM_NIL(conf);
    
   // [self changeToNewCallState:EN_CALL_RECV];
    
    NSDictionary * args = [NSDictionary dictionaryWithObjectsAndKeys:
                           conf.callerNum,		CALL_FROMNUMBER,
                           conf.confId,			VOICE_CONFERENCE_ID_KEY,
                           conf.confType,		VOICE_CONFERENCE_MEDIATYPE_KEY,
                           nil];
    
    [ECSNotificationCenter postNotificationName:NTF_SIP_INCOMING_CALL object:nil userInfo:args];
    
    return YES;
}

-(BOOL)CallService_CallIdleProcPlayVoiceMail:(NSDictionary *)infoDic {
    RETURN_NO_IF_PARAM_NIL(infoDic);
    NSString *shortCode	 = [infoDic objectForKey:VOICE_MAIL_SHORTCODE_KEY];
    if (![CallServiceImp playVoiceMsgWithMailShortCode:shortCode]) {
        return NO;
    }
   // [self changeToNewCallState:EN_CALL_START];
    return YES;	
}

#pragma mark -
#pragma mark 状态机处理函数 (EN_CALL_IDLE)

-(BOOL)CallService_CallIdleProcStartCall:(NSString *)calleeNumber callType:(EN_CALL_TYPE)callType{
    if([CallServiceImp startCall:callType calleeNumber:calleeNumber]) {
       // [[CallServiceImp sharedInstance] callSendDiaglogInfo];
        return YES;
    }
    
    return NO;
}

- (void)changeToNewCallState:(EN_CALL_STATE)newState {
    lastCallState_ = currentCallState_;
    currentCallState_ = newState;
    logDbg(@"Change currentState[%s] to newState[%s].",[[self dumpStateInfo:lastCallState_] UTF8String] ,[[self dumpStateInfo:currentCallState_] UTF8String]);
    [self stopCallStatesTimer];
    [self startCallStatesTimer:currentCallState_];
    
    [self notifyCallStateChangedIfLogin];
    [self releaseSessionResourceIfCallStateIdle];
}

- (void)stopCallStatesTimer{
    if (nil != callStatesTimedoutTimer_ && [callStatesTimedoutTimer_ isValid]) {
        [callStatesTimedoutTimer_ invalidate];
        callStatesTimedoutTimer_ = nil;
    }
}

- (void)startCallStatesTimer:(EN_CALL_STATE)callState {
    [self stopCallStatesTimer];
    NSNumber * stateTimedoutLen = [self callStateTimedoutLenForState:callState];
    if (stateTimedoutLen != nil && [stateTimedoutLen intValue] > 0) {
        
        logDbg(@"Start timer for state[%s],time len = %d",[[self dumpStateInfo:callState] UTF8String], [stateTimedoutLen intValue]);
        callStatesTimedoutTimer_ = [NSTimer scheduledTimerWithTimeInterval:[stateTimedoutLen intValue]
                                                                     target:self
                                                                   selector:@selector(onCallStatesTimedout)
                                                                   userInfo:nil 
                                                                    repeats:NO];
    }
}

- (NSNumber *)callStateTimedoutLenForState:(EN_CALL_STATE)state {
    if (nil == callStateTimedoutLenDict_) {
        return nil;
    }
    
    return [callStateTimedoutLenDict_ objectForKey:[NSString stringWithFormat:@"%d", state]];
}

- (void)onCallStatesTimedout {
    [self stopCallStatesTimer];
    logInfo(@"Call state[%s] timedout.",[[self dumpStateInfo:currentCallState_] UTF8String]);
    
    switch (currentCallState_) {
        case EN_CALL_IDLE:
        case EN_CALL_RUNNING:
            break;
            
        case EN_CALL_RECV:
        case EN_CALL_START:
        case EN_CALL_PROCEEDING:
        {
            [self closeCallAndChangeToIdle];
            [ECSNotificationCenter postNotificationName:NTF_SIP_BYE object:nil];
            break;
        }
            
        case EN_CALL_TRANSFERING:
        {
            [ECSNotificationCenter postNotificationName:NTF_SIP_TRANSFER_FAILED object:nil userInfo:[NSDictionary dictionary]];
           // [self changeToNewCallState:EN_CALL_RUNNING];
            break;
        }
            
        case EN_WAITING_CONF_INVITE:
        {
           // [self changeToNewCallState:EN_CALL_IDLE];
            [ECSNotificationCenter postNotificationName:NTF_SIP_SCHEDULE_CONF_JOIN_TIME_OUT object:self.scheduleConfId userInfo:nil];
            break;
        }
            
        default:
            //			SDK_WRN_LOG("Unknwon state[" << currentCallState_ << "]");
            logWarn(@"Unknwon state[%d]",currentCallState_);
            break;
    }
}

- (void)closeCallAndChangeToIdle {
    [CallServiceImp closeCall];
   // [self changeToNewCallState:EN_CALL_IDLE];
}

- (void)notifyCallStateChangedIfLogin {
    //	if ([[eSpaceIOSSDK loginService] isLogin]) {
    if (EN_CALL_IDLE == lastCallState_) {
        if (EN_CALL_IDLE != currentCallState_) {
            [ECSNotificationCenter postNotificationName:NTF_STATE_TO_BUSY object:nil];
        }
    }
    else {
        if (EN_CALL_IDLE == currentCallState_) {
            [ECSNotificationCenter postNotificationName:NTF_STATE_TO_IDLE object:nil];
        }
    }
    //	}
}

-(void)releaseSessionResourceIfCallStateIdle {
    if (EN_CALL_IDLE == currentCallState_) {
        self.scheduleConfId = nil;
        //hasSDP = YES;
        self.accessCode = nil;
        self.passCode = nil;
      //  isMediaXConf = NO;
    }
}


@end








