//
//  TupCallNotifications.m
//  VTMSDK
//
//  Created by gaoshuming on 15/10/13.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import "TupCallNotifications.h"
#import "ECSUtils.h"

@interface TupCallNotifications()
{
    CALL_E_CALL_EVENT msgId_;
    TUP_UINT32 param1_;
    TUP_UINT32 param2_;
    void* data_;
}
@end

@implementation TupCallNotifications

@synthesize msgId = msgId_;
@synthesize param1 = param1_;
@synthesize param2 = param2_;
@synthesize data = data_;

static id<TupCallNotificationsHandler> g_tupCallNotificationsHandler = nil;
+ (void)setHandler:(id<TupCallNotificationsHandler>)handler
{
    g_tupCallNotificationsHandler = handler;
}

+ (void)resetHandler
{
    g_tupCallNotificationsHandler = nil;
}

+ (NSString *)eventDescription:(CALL_E_CALL_EVENT)event
{
    static BOOL isEventDescInit = NO;
    
    if (!isEventDescInit)
    {
        isEventDescInit = YES;
        
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_SIPACCOUNT_INFO, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_STARTCALL_RESULT, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_INCOMMING, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_OUTGOING, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_RINGBACK, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_CONNECTED, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_DIALOG_INFO, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_ENDED, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_DESTROY, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_RTP_CREATED, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_ADD_VIDEO, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_SESSION_MODIFIED, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_DEL_VIDEO, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_MODIFY_VIDEO_RESULT, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_HOLD_SUCCESS, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_HOLD_FAILED, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_UNHOLD_SUCCESS, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_UNHOLD_FAILED, EnumDescType_TUP_Call_Notifications);
        
        
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_BLD_TRANSFER_SUCCESS, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_BLD_TRANSFER_FAILED, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_ATD_TRANSFER_SUCCESS, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_ATD_TRANSFER_FAILED, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_SET_IPT_SERVICE_SUCCESS, EnumDescType_TUP_Call_Notifications);
        
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_SET_IPT_SERVICE_FAILED, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_SIPACCOUNT_WMI, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_VVM_DOWNLOAD_SUCCESS_NOTIFY, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_VVM_DOWNLOAD_FAIL_NOTIFY, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_VVM_FORWARD_SUCCESS_NOTIFY, EnumDescType_TUP_Call_Notifications);
        
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_VVM_FORWARD_FAIL_NOTIFY, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_VVM_DELETE_SUCCESS_NOTIFY, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_VVM_DELETE_FAIL_NOTIFY, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_VVM_DELETEALL_SUCCESS_NOTIFY, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_VVM_DELETEALL_FAIL_NOTIFY, EnumDescType_TUP_Call_Notifications);
        
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_VoiceMail_SUB_SUCCESS, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_VoiceMail_SUB_FAILED, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_MODIFY_SUCCESS, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_MODIFY_FAILED, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_UPATE_REMOTEINFO, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_SRTP_STATE, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_STATISTIC_MOS, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_VIDEO_QUALITY, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_CALL_CALL_REINVITED, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_NEW_SERVICE_RIGHT, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_SERVERCONF_ENDED, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_REFRESH_VIEW, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_AUDIO_UNIT_INIT, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_IMS_FORWARD_RESULT, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_SIPACCOUNT_WMI, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_SESSION_CODEC, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_VIDEO_FRAMESIZE_CHANGE, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_VIDEO_OPERATION, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_VIDEO_STATISTIC_NETINFO, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_STATISTIC_NETINFO, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_NET_QUALITY_CHANGE, EnumDescType_TUP_Call_Notifications);
        ECSUTILES_ADD_ENUM_DESCRIPTION(CALL_E_EVT_AUDIO_END_FILE, EnumDescType_TUP_Call_Notifications);
    }
    
    NSString *desc = [ECSUtils enumDescription:event forType:EnumDescType_TUP_Call_Notifications];
    
    if (desc.length == 0)
    {
        desc = [NSString stringWithFormat:@"%d", event];
    }
    
    return desc;
}

-(id)initWithMsgId:(CALL_E_CALL_EVENT)msgId param1:(TUP_UINT32)param1 param2:(TUP_UINT32)param2 data:(void *)data
{
    if (self = [super init])
    {
        msgId_ = msgId;
        param1_ = param1;
        param2_ = param2;
        data_ = data;
    }
    return self;
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"msgid(%@)param1(%d)param2(%d)data(%p)", [TupCallNotifications eventDescription:msgId_], param1_, param2_, data_];
}

@end
TUP_VOID onTupCallNotifications(TUP_UINT32 msgid, TUP_UINT32 param1, TUP_UINT32 param2, void *data)
{
    if (nil == g_tupCallNotificationsHandler)
    {
        return;
    }
    
    TupCallNotifications *notification = [[TupCallNotifications alloc] initWithMsgId:(CALL_E_CALL_EVENT)msgid
                                                                              param1:param1
                                                                              param2:param2
                                                                                data:data];
    [g_tupCallNotificationsHandler onRecvNotification:notification];
}

