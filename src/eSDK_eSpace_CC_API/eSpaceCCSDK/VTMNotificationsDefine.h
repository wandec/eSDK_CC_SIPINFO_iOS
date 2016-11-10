//
//  VTMNotificationsDefine.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/15.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#ifdef __cplusplus
#define ECS_EXTERN		extern "C"
#else
#define ECS_EXTERN		extern
#endif



#ifndef VTMNotificationsDefine_h
#define VTMNotificationsDefine_h

//通话状态通知

ECS_EXTERN NSString *const STARTCALL_RESULT; //发起呼叫响应
ECS_EXTERN NSString *const RECEIVE_CALL_MESSAGE;  //呼叫成功发送消息
ECS_EXTERN NSString *const CALL_RINGBACK; //SIP通话开始通知
ECS_EXTERN NSString *const CALL_ENDED;  //SIP通话结束通知
ECS_EXTERN NSString *const SIP_INFO_RECEIVE_NOTIFY; //接收SIP消息的通知
ECS_EXTERN NSString *const SIP_INFO_CONTENT; //SIP消息内容
ECS_EXTERN NSString *const CALL_RELEASE; //SIP消息内容
ECS_EXTERN NSString *const CHECK_ISINWIFI;//检测是否是WIFI


ECS_EXTERN NSString* const VTM_ANONYMOUS_CANCEL_ALL_REQUEST_NOTIFY;
ECS_EXTERN NSString * const VTMKeyOperateOK;
ECS_EXTERN NSString * const VTMCallSendReultNotify;//语音模块是否将呼叫发出的通知
ECS_EXTERN NSString * const VTMCallQueueInfoReultNotify;//获取排队信息通知
ECS_EXTERN NSString * const VTM_RETURN_CODE;//VTM通知中得返回值key字段(@"retCode")
ECS_EXTERN NSString * const VTM_RETURNCODE_SUCCESS;//VTM请求返回值正常
ECS_EXTERN NSString * const VTM_RETCODE_NETWORK_ERROR;//网络错误返回码
ECS_EXTERN NSString * const VTM_RETCODE_HTTP_ERROR;//HTTP错误返回码
ECS_EXTERN NSString * const VTM_RETURN_MSG;//上报的通知中的消息键值,表示服务器返回的消息
ECS_EXTERN NSString * const VTM_RELATIVE_PATH;//上报的通知中,http相对路径

ECS_EXTERN NSString * const VTM_ANONYMOUSCALL_REQUEST_NOTIFY;//发起匿名呼叫请求之后的响应通知
ECS_EXTERN NSString * const VTM_ANONYMOUSCALL_NOTIFYSESSIONSTATE_NOTIFY;//匿名呼叫状态响应通知
ECS_EXTERN NSString * const VTM_ANONYMOUSCALL_GETSESSIONSTATE_NOTIFY;//获取通话状态的通知

ECS_EXTERN NSString * const VTM_GETSTATE_ENV_NAME; //状态获取事件的名字
ECS_EXTERN NSString * const VTM_ANONYMOUS_QUEUINGEVENT;//匿名呼叫进入排队事件
ECS_EXTERN NSString * const VTM_ANONYMOUS_MEETINGINFOEVENT;//匿名呼叫获取到了会议信息事件
ECS_EXTERN NSString * const VTM_ANONYMOUS_OCCUPYAGENTEVENT;//匿名呼叫获取到了呼叫信息事件
/*****************匿名呼叫部分**********************/
ECS_EXTERN NSString * const VTM_ANONYMOUSCALL_REQUEST_NOTIFY;//发起匿名呼叫请求之后的响应通知
ECS_EXTERN NSString * const VTM_ANONYMOUSCALL_NOTIFYSESSIONSTATE_NOTIFY;//匿名呼叫状态响应通知
ECS_EXTERN NSString * const VTM_ANONYMOUSCALL_GETSESSIONSTATE_NOTIFY;//获取通话状态的通知

ECS_EXTERN NSString * const VTM_GETSTATE_ENV_NAME; //状态获取事件的名字
ECS_EXTERN NSString * const VTM_RETURN_CODE;//VTM通知中得返回值key字段(@"retCode")
ECS_EXTERN NSString * const VTM_RETURNCODE_SUCCESS;//VTM请求返回值正常
ECS_EXTERN NSString * const VTM_RETCODE_NETWORK_ERROR;//网络错误返回码
ECS_EXTERN NSString * const VTM_RETCODE_HTTP_ERROR;//HTTP错误返回码
ECS_EXTERN NSString * const VTM_RETURN_MSG;//上报的通知中的消息键值,表示服务器返回的消息
ECS_EXTERN NSString * const VTM_RELATIVE_PATH;//上报的通知中,http相对路径

ECS_EXTERN NSString * const VTM_ANONYMOUS_RELEASEEVENT;//匿名呼叫被释放事件
ECS_EXTERN NSString * const VTM_ANONYMOUS_QUEUINGEVENT;//匿名呼叫进入排队事件
ECS_EXTERN NSString * const VTM_ANONYMOUS_MEETINGINFOEVENT;//匿名呼叫获取到了会议信息事件
ECS_EXTERN NSString * const VTM_ANONYMOUS_OCCUPYAGENTEVENT;//匿名呼叫获取到了呼叫信息事件

//Network state changed
ECS_EXTERN NSString * const VTM_SIP_NETSTATE_CHANGED;//网络信号状态变化
ECS_EXTERN NSString * const VTM_KEY_NETSTATE_CHANGED;//网络状态变化通知userDic:信号级别1-5,5满格

ECS_EXTERN NSString * const VTMCallQueueInfoReultNotify;//获取排队信息通知

#endif
