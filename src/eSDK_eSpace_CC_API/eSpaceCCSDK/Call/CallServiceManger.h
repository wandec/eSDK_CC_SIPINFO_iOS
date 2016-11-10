//
//  CallServiceManger.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/20.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <Foundation/Foundation.h>

/* 呼叫、会议及多媒体会议状态机状态定义 */
typedef   enum
{
    EN_CALL_IDLE                 = 0,              /* 空闲态 */
    EN_CALL_RECV                 = 1,              /* 收到对端呼叫 */
    EN_CALL_START                = 2,              /* 发出呼叫 */
    EN_CALL_PROCEEDING           = 3,              /* 收到对端回铃音 */
    EN_CALL_RUNNING              = 4,              /* 普通通话进行中 */
    EN_CALL_TRANSFERING			= 5,			   /* 普通通话或会议中语音转移中 */
    EN_WAITING_CONF_INVITE		= 6,				/* */
    EN_CALL_BUTT
}EN_CALL_STATE;

/* 呼叫及会议相关的消息 */
// 消息描述：发起语音呼叫，入参：NA，响应该消息的状态：NA
typedef enum {
    MSG_CMD_START_CALL										= 1,	// 消息描述：发起语音呼叫，入参：被叫号码(NSString)，响应该消息的状态：EN_CALL_IDLE
    MSG_CMD_START_VIDEO_CALL								= 2,	// 消息描述：发起视频呼叫或语音通话升级视频，入参：被叫号码(NSString)，响应该消息的状态：EN_CALL_IDLE／EN_CALL_RUNNING
    MSG_CMD_ANSWER_CALL										= 3,	// 消息描述：接听语音呼叫，入参：媒体流模式及语音视频模式(NSString)，响应该消息的状态：EN_CALL_RECV
    MSG_CMD_CLOSE_CALL										= 4,	// 消息描述：结束或取消语音呼叫，入参：NA，响应该消息的状态：NA
    MSG_CMD_SEND_DTMF                                       = 5,   // 消息描述：二次拨号，发送dtmf，入参：dtmf(NSString)，响应该消息的状态：NA
    MSG_CMD_HOLD_CALL                                       = 6,   /* 通话过程中，进行呼叫保持 */
    MSG_CMD_RESUME_CALL                                     = 7,   /* 恢复被保持的通话 */
    MSG_CMD_TRANSFER_CALL                                   = 8,
    MSG_CMD_JOIN_SCHEDULE_CONF								= 9,   /* 一件入会按钮消息 */
    MSG_CMD_MODIFY_CALL_SESSION_SENDMODE_SENDRECV			= 10,   /* 修改call会话的媒体流方向 */
    MSG_CMD_ACCEPT_CALL_SESSION_MODIFY						= 11,   /* 接听由语音升级的视频通话 */
    MSG_CMD_REFUSE_CALL_SESSION_MODIFY						= 12,   /* reject由语音升级的视频通话 */
    MSG_CMD_CANCEL_CALL_SESSION_MODIFY						= 13,   /* 对方接听前，取消视频请求 */
    MSG_CMD_CALL_REMOVE_VIDEO								= 14,   /* 视频过程中，去除video */
    MSG_CMD_CALL_PLAY_VOICE_MAIL							= 15,	/* 请求语音留言（到UMS） */
    MSG_CMD_CALL_CONTROL_VOICE_MAIL_PALY					= 16,	/* 语音留言播放时，暂停、快进、快退*/
    MSG_CMD_SUSPEND_CALL_CONTROL_SESSION					= 17,	/* 主被叫控，暂停 */
    MSG_CMD_RESUME_CALL_CONTROL_SESSION						= 18,	/* 主被叫控，恢复 */
    MSG_CMD_ABNORMAL_TERMINATE								= 19,	/* 状态机非正常结束，释放资源，每个状态都应该实现 */
    
    MSG_NTF_CALL_SESSION_MODIFIED_RESULT					= 51,   /* 上抛session modified结果给UI层 */
    MSG_NTF_CALL_SESSION_MODIFY_ALERTING					= 52,   /* 收到语音升级视频的请求抛给UI层 */
    MSG_NTF_CALL_SESSION_MODIFIED_CANCELED					= 53,   /* 取消语音升级视频的请求抛给UI层 */
    MSG_NTF_SIP_INCOMING_CALL								= 54,	/* 新电话来电 */
    MSG_NTF_SIP_INCOMING_CONFERENCE_CALL					= 55,	/*iphone收到会议来电*/
    MSG_NTF_SIP_BYE											= 56,	/* 对方挂断电话或者会议主持主动结束会议，或者对方取消未接通的呼叫 */
    MSG_NTF_SIP_PEER_UNAVAILABLE							= 57,	/* 对方无法接通 */
    MSG_NTF_SIP_PEER_ALERTING								= 58,	/* 对方振铃 */
    MSG_NTF_SIP_PEER_ANSWER_CALL							= 59,	/* 对方接听 */
    MSG_NTF_SIP_PEER_HELD           	                    = 60,	/* 对方呼叫保持 */
    MSG_NTF_SIP_PEER_RETRIEVED		     			        = 61,	/* 对方取消呼叫保持 */
    MSG_NTF_CALL_TRANSFER_ACK								= 62,   /* refer ack(202) */
    MSG_NTF_CALL_TRANSFER_NOTIFY							= 63,   /* notify for refer */
    MSG_NTF_SIP_UPDATED_TO_CONF								= 64,	/* info:5000*/
    MSG_NTF_JOIN_SCHEDULE_CONF_FAILED						= 65,   /* 一件入会失败*/
    MSG_NTF_SIP_PEER_FORWARD                                = 66,	//呼叫被转发,181
    //add on 2013.5.29,deal with 183,对方彩铃
    MSG_NTF_SIP_PEER_PROGRESS                               = 67,
    //end add on 2013.5.29
    
    MSG_NTF_SIP_HOLD_RESULT           	                    = 68,	/* 呼叫保持结果 */
    MSG_NTF_SIP_RESUME_RESULT		     			        = 69,	/* 恢复呼叫保持结果 */
    
    MSG_TYPE_INVALID										= 9999 
}EN_CALL_MSG_TYPE;

@interface CallServiceManger : NSObject
{
    EN_CALL_STATE lastCallState_;//上一个状态
    EN_CALL_STATE currentCallState_;// 当前状态
    NSTimer * callStatesTimedoutTimer_;// 状态机定时器
    
    NSDictionary * callStateTimedoutLenDict_; // 状态机各不稳定状态的超时时间
    NSDictionary * callStateHandlers_;
    //NSString			*scheduleConfId;		// 一键入会的会议id。
}


-(BOOL)CallService_ProcCallStateMsg:(EN_CALL_MSG_TYPE)enCallMsgType args:(void *)arg;
- (BOOL)isCallFSMStateIdle;

+ (CallServiceManger *)getCallserviceInstance;
+ (void)destoryCallServiceInstance;

- (void)onCallStatesTimedout;

@end




