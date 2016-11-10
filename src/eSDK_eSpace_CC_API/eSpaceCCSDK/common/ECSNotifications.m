//
//  ECSNotifications.m
//  VTMSDK
//
//  Created by gaoshuming on 15/10/20.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import "ECSNotifications.h"

/* define of common keys */
NSString* const ECSCommonKeyResultCode							= @"ECSCommonKeyResultCode";
NSString* const ECSCommonKeyResult								= @"ECSCommonKeyResult";
NSString* const ECSCommonKeyFlag								= @"ECSCommonKeyFlag";
NSString* const ECSCommonKeyDescription							= @"ECSCommonKeyDescription";
NSString* const ECSCommonKeyType								= @"ECSCommonKeyType";
NSString* const ECSCommonKeyAccount								= @"ECSCommonKeyAccount";
NSString* const ECSCommonKeyAccounts							= @"ECSCommonKeyAccounts";
NSString* const ECSCommonKeyGroupid								= @"ECSCommonKeyGroupid";
NSString* const ECSCommonKeyFixGroupInfo						= @"ECSCommonKeyFixGroupInfo";
NSString* const ECSCommonKeyGroupType                           = @"ECSCommonKeyGroupType";
NSString* const ECSCommonKeyIsAdmin                             = @"ECSCommonKeyIsAdmin";
NSString* const ECSCommonKeyAttendee							= @"ECSCommonKeyAttendee";
NSString* const ECSCommonKeyData								= @"ECSCommonKeyData";
NSString* const ECSCommonKeyNickname							= @"ECSCommonKeyNickname";
NSString* const ECSCommonKeyHeadid								= @"ECSCommonKeyHeadid";
NSString* const ECSCommonKeyNativeName							= @"ECSCommonKeyNativeName";
NSString* const ECSCommonKeyRequestId							= @"ECSCommonKeyRequestId";
NSString* const ECSCommonKeyMsgId								= @"ECSCommonKeyMsgId";
NSString* const ECSCommonKeyMsgs								= @"ECSCommonKeyMsgs";
NSString* const ECSCommonKeyMsg									= @"ECSCommonKeyMsg";
NSString* const ECSCommonKeyDeptDesc							= @"ECSCommonKeyDeptDesc";
NSString* const ECSCommonKeyDeptDescEng							= @"ECSCommonKeyDeptDescEng";
NSString* const ECSCommonKeySex									= @"ECSCommonKeySex";
NSString* const ECSCommonKeyTag									= @"ECSCommonKeyTag";
NSString* const ECSCommonKeyContent								= @"ECSCommonKeyContent";
NSString* const ECSCommonKeyReasonType							= @"ECSCommonKeyReasonType";
NSString* const ECSCommonKeyQueryType                           = @"ECSCommonKeyQueryType";
NSString* const ECSCommonKeyURL									= @"ECSCommonKeyURL";
NSString* const ECSCommonKeyDiscussionGroupInfo                 = @"ECSCommonKeyDiscussionGroupInfo";
NSString* const ECSCommonKeyTopicId                             = @"ECSCommonKeyTopicId";
NSString* const ECSCommonKeyTopicOwnerId                        = @"ECSCommonKeyTopicOwnerId";
NSString* const ECSCommonKeyCircleTopic                         = @"ECSCommonKeyCircleTopic";
NSString* const ECSCommonKeyComment                             = @"ECSCommonKeyComment";
NSString* const ECSCommonKeyCommentId                           = @"ECSCommonKeyCommentId";
NSString* const ECSCommonKeyCommentDBId                         = @"ECSCommonKeyCommentDBId";
NSString* const ECSCommonKeyCommentType                         = @"ECSCommonKeyCommentType";
NSString* const ECSCommonKeyTopicList                           = @"ECSCommonKeyTopicList";

NSString* const ECSCommonKeyTime                                = @"ECSCommonKeyTime";
NSString* const ECSCommonKeyNum                                 = @"ECSCommonKeyNum";

NSString* const ECSCommonPAId                                   = @"ECSCommonPAId";
NSString* const ECSCommonPAKeyMessageList                       = @"ECSCommonPAKeyMessageList";
NSString* const ECSCommonPAKeyPageNo                            = @"ECSCommonPAKeyPageNo";
NSString* const ECSCommonPAKeyPageSize                          = @"ECSCommonPAKeyPageSize";
NSString* const ECSCommonPAKeyTotalNo                           = @"ECSCommonPAKeyTotalNo";

/* head image service */
NSString* const ECSGetHeadImageResultNotify						= @"ECSGetHeadImageResultNotify";
NSString* const ECSGetHeadHDImageResultNotify                   = @"ECSGetHeadHDImageResultNotify";
NSString* const ECSSetSelfHeadImageResultNotify					= @"ECSSetSelfHeadImageResultNotify";
NSString* const ECSHeadImageDeletedNotify						= @"ECSHeadImageDeletedNotify";

NSString* const ECSTlsDownLoadFailNotify                        = @"ECSTlsDownLoadFailNotify";



/* circle service */
NSString* const ECSKeyBidirectionalFriendList                   = @"ECSKeyBidirectionalFriendList";
NSString* const ECSKeyNewCircleStateUserDict                    = @"ECSKeyNewCircleStateUserDict";

/* user service */

/* chat service */


/* call service */
NSString* const ECSTempGrpCreateAudioConfSuccessNotify          = @"ECSTempGrpCreateAudioConfSuccessNotify";
NSString* const ECSTempGrpCreateAudioConfFailedNotify           = @"ECSTempGrpCreateAudioConfFailedNotify";
NSString* const ECSTempGrpMemberJoinAudioConfSuccessNotify      = @"ECSTempGrpMemberJoinAudioConfSuccessNotify";
NSString* const ECSTempGrpMemberJoinAudioConfFailedNotify       = @"ECSTempGrpMemberJoinAudioConfFailedNotify";
NSString* const ECSTempGrpAudioConfClosedNotify                 = @"ECSTempGrpAudioConfClosedNotify";
NSString* const ECSTempGrpAudioConfMemberLeaveNotify            = @"ECSTempGrpAudioConfMemberLeaveNotify";

NSString* const ECSCallSessionModifyResultNotify				= @"ECSCallSessionModifyResultNotify";
NSString* const ECSAddVideoCallAlerting							= @"ECSAddVideoCallAlerting";
NSString* const ECSAddVideoCallCanceled							= @"ECSAddVideoCallCanceled";
NSString* const ECSSessionModifyAckNotify                       = @"ECSSessionModifyAckNotify";

NSString* const ECSTransferAcceptNotify							= @"ECSTransferAcceptNotify";

NSString* const ECSIsSelfHoldCallKey							= @"ECSIsSelfHoldCallKey";

NSString* const ECSCallHoldOrResumeResultNotify                 = @"ECSCallHoldOrResumeResultNotify";

/*************************************CallLogs***********************/

NSString * const ECSCallLogDeleleteIdsKey = @"ECSCallLogDeleleteIdsKey";
NSString * const ECSCallLogDeleteUserkey = @"ECSCallLogDeleteUserkey";
NSString * const ECSNewCallLogskey = @"ECSNewCallLogskey";
NSString * const ECSDelCallLogsResultNotify = @"ECSDelCallLogsResultNotify";
NSString * const ECSUpdateCallLogsResultNotify = @"ECSUpdateCallLogsResultNotify";

/*************************************CallLogs**********************/

/*************************************CTD**********************/
NSString * const ECSCTDCallIdKey = @"ECSCTDCallIdKey";				// 键值类型：NSString ctd推送消息对应callid
NSString * const ECSCTDFailedReasonKey = @"ECSCTDFailedReasonKey";			// 键值类型：NSString ctd请求失败原因
NSString * const ECSCTDResultNotify = @"ECSCTDResultNotify";				// ctd请求结果通知
/*************************************CTD**********************/
/************************************************** LBS Location *****************************************************************/

NSString * const ECSTopLevelLocationID = @"-1";
NSString * const ECSInternetLocationID = @"internet";
NSString * const ECSLocationInfoKey = @"ECSLocationInfoKey";
NSString * const ECSSetLocationResultNotify = @"ECSSetLocationResultNotify";
NSString * const ECSQueryLocationResultNotify = @"ECSQueryLocationResultNotify";

/************************************************** LBS Location ******************************************************************/
/************************************************** News Notify ******************************************************************/
NSString * const ECSReceiveNewsTitleKey = @"ECSReceiveNewsTitleKey";     //键值类型：NSString*，取值范围：NA，默认值：NA，描述：NA
NSString * const ECSReceiveNewsIdKey = @"ECSReceiveNewsIdKey";          //键值类型：NSString*，取值范围：NA，默认值：NA，描述：NA

NSString * const ECSReceiveNewsNotify = @"ECSReceiveNewsNotify";       //收到新公告通知
// userInfo : ECSReceiveNewsTitleKey,ECSReceiveNewsIdKey

/************************************************** News Notify ******************************************************************/

/*********************** Local Contact*********************/
NSString * const ECSLocalContactMatchResultKey = @"ECSLocalContactMatchResultKey";
/*********************** Local Contact end****************/
//add by xieshuotao 20120507
/* CWComponent notifications for data conf */
/***************notifications for multimedia conf from IOSSDK to UI*****************/
NSString* const ECSDataConfSetHostNotify                        = @"ECSDataConfSetHostNotify";
NSString* const ECSDataConfSetPresenterNotify                   = @"ECSDataConfSetPresenterNotify";
NSString* const ECSDataConfActiveTalkerNotify                   = @"ECSDataConfActiveTalkerNotify";
NSString* const ECSDataConfTerminatedNotify                     = @"ECSDataConfTerminatedNotify";
NSString* const ECSDataConfJoinConfResultNotify                 = @"ECSDataConfJoinConfResultNotify";
NSString* const ECSDataConfNetBrokenNotify                      = @"ECSDataConfNetBrokenNotify";
NSString* const ECSDataConfUserJoinInNotify                     = @"ECSDataConfUserJoinInNotify";
NSString* const ECSDataConfUserLeaveNotify                      = @"ECSDataConfUserLeaveNotify";
NSString* const ECSDataConfReceiveChatMsgNotify                 = @"ECSDataConfReceiveChatMsgNotify";
NSString* const ECSDataConfSelfKickOffByHostNotify              = @"ECSDataConfSelfKickOffByHostNotify";
NSString* const ECSDataConfReceiveShareDataNotify               = @"ECSDataConfReceiveShareDataNotify";
NSString* const ECSDataConfStopSharingDataNotify                = @"ECSDataConfStopSharingDataNotify";
NSString* const ECSDataConfChangeASSharingDataNotify            = @"ECSDataConfChangeASSharingDataNotify";
NSString* const ECSDataConfStopsharingDocNotify                 = @"ECSDataConfStopsharingDocNotify";
NSString* const ECSDataConfVideoStatusNotify                    = @"ECSDataConfVideoStatusNotify";
NSString* const ECSDataConfDelVideoCloseNotify                  = @"ECSDataConfDelVideoCloseNotify";
NSString* const ECSDataConfKeysUserVideoDeviceInfo              = @"ECSDataConfKeysUserVideoDeviceInfo";
NSString* const ECSDataConfKeysUserVideoDeviceAddOrDel          = @"ECSDataConfKeysUserVideoDeviceAddOrDel";
NSString* const ECSDataConfKeysNetSignalValue                   = @"ECSDataConfKeysNetSignalValue";
NSString* const ECSDataConfCameraInfoNotify                     = @"ECSDataConfCameraInfoNotify";
NSString* const ECSDataConfStartScreenSharing                   = @"ECSDataConfStartScreenSharing";
NSString* const ECSDataConfMute									= @"ECSDataConfMute";
NSString* const ECSDataConfCurrentSharingAttendeeNotify			= @"ECSDataConfCurrentSharingAttendeeNotify";
NSString* const ECSDataConfShareModeChangeNotify				= @"ECSDataConfShareModeChangeNotify";
NSString* const ECSDataConfVideModeChangeNotify					= @"ECSDataConfVideModeChangeNotify";
NSString* const ECSDataConfOverMaxAudioOpen                     = @"ECSDataConfOverMaxAudioOpen";
NSString* const ECSDataConfOverMaxCameraOpen                    = @"ECSDataConfOverMaxCameraOpen";
NSString* const ECSDataConfNotOpenCameraInBack                  = @"ECSDataConfNotOpenCameraInBack";
NSString* const ECSDataConfDisConnectNotify                     = @"ECSDataConfDisConnectNotify";
NSString* const ECSDataConfReConnectNotify                      = @"ECSDataConfReConnectNotify";
// 电话用户的通知消息
NSString* const ECSDataConfPhoneUserJoinInNotify				= @"ECSDataConfPhoneUserJoinInNotify";
NSString* const ECSDataConfPhoneUserLeaveNotify					= @"ECSDataConfPhoneUserLeaveNotify";
NSString* const ECSDataConfPhoneUserCallNidNotify               = @"ECSDataConfPhoneUserCallNidNotify";
NSString* const ECSDataConfPhoneUserNameNotify                  = @"ECSDataConfPhoneUserNameNotify";
NSString* const ECSDataConfUserInfoModifyNotify                 = @"ECSDataConfUserInfoModifyNotify";
NSString* const ECSDataConfKickOffModifyUserNotify              = @"ECSDataConfKickOffModifyUserNotify";
NSString* const ECSDataConfUSerAudioCapilityModifyUserNotify    = @"ECSDataConfUSerAudioCapilityModifyUserNotify";
//added by zhangjianfang 20121108

// notification names of portal query result
NSString* const ECSQueryConfListNotify							= @"ECSQueryConfListNotify";
NSString* const ECSQueryConfInfoNotify							= @"ECSQueryConfInfoNotify";
NSString* const ECSQueryConfMembesNotify						= @"ECSQueryConfMembesNotify";
NSString* const ECSSendEmailResultNotify						= @"ECSSendEmailResultNotify";

NSString* const ECSDataConfAudioCodecResultNotify				= @"ECSDataConfAudioCodecResultNotify";



/***************dictionary keys for multimedia conf from IOSSDK to UI*****************/
NSString* const ECSDataConfKeysUserID                           = @"ECSDataConfKeysUserID";
NSString* const ECSDataConfKeysUserBindNo                       = @"ECSDataCOnfKeysUserBindNo";
NSString* const ECSDataConfKeysUserName                         = @"ECSDataCOnfKeysUserName";
NSString* const ECSDataConfKeysIsSelf                           = @"ECSDataCOnfKeysIsSelf";
NSString* const ECSDataConfKeysIsPresenter                      = @"ECSDataConfKeysIsPresenter";
NSString* const ECSDataConfKeysIsHost                           = @"ECSDataConfKeysIsHost";
NSString* const ECSDataConfKeysTransferBindindNum               = @"ECSDataConfKeysTransferBindindNum";
NSString* const ECSDataConfKeysJoinResult                       = @"ECSDataCOnfKeysJoinResult";
NSString* const ECSDataConfKeysShareDataType                    = @"ECSDataCOnfKeysShareDataType";
NSString* const ECSDataConfKeysShareImage                       = @"ECSDataConfKeysShareImage";
NSString* const ECSDataConfKeysLastMode							= @"ECSDataConfKeysLastMode";
NSString* const ECSDataConfKeysCurrentMode						= @"ECSDataConfKeysCurrentMode";
NSString* const ECSDataConfKeysCurrentVideoMode					= @"ECSDataConfKeysCurrentVideoMode";
NSString* const ECSDataConfKeysJoinOrder                        = @"ECSDataConfKeysJoinOrder";
NSString* const ECSDataConfKeysMaxMicOpenNumber                 = @"ECSDataConfKeysMaxMicOpenNumber";
NSString* const ECSDataConfKeysUserAudioCapility                = @"ECSDataConfKeysUserAudioCapility";
// keys for chat message in data conf
NSString* const ECSDataConfKeysMsgSenderID                      = @"ECSDataConfKeysMsgSenderID";
NSString* const ECSDataConfKeysMsgReceiverID                    = @"ECSDataConfKeysMsgReceiverID";
NSString* const ECSDataConfKeysMsgSenderName                    = @"ECSDataConfKeysMsgSenderName";
NSString* const ECSDataConfKeysMsgReceiverName                  = @"ECSDataConfKeysMsgReceiverName";
NSString* const ECSDataConfKeysMsgContent                       = @"ECSDataConfKeysMsgContent";
NSString* const ECSDataConfKeysMsgLength                        = @"ECSDataConfKeysMsgLength";
NSString* const ECSDataConfKeysMsgTime                          = @"ECSDataConfKeysMsgTime";

//keys for video status
NSString* const ECSDataConfKeysVideoStatus                      = @"ECSDataConfKeysVideoStatus";
NSString* const ECSDataConfKeysDeviceName                       = @"ECSDataConfKeysDeviceName";
NSString* const ECSDataConfKeysDeviceNameArray                  = @"ECSDataConfKeysDeviceNameArray";
NSString* const ECSDataConfKeysDeviceId							= @"ECSDataConfKeysDeviceId";
//end by xieshuotao 20120507

NSString* const ECSDataConfKeyHasMic							= @"ECSDataConfKeyHasMic";
NSString* const ECSDataConfKeyMicStatus							= @"ECSDataConfKeyMicStatus";
NSString* const ECSDataConfKeyMuteMicOwner                      = @"ECSDataConfKeyMuteMicOwner";

NSString* const ECSDataConfKeysIsConfMute						= @"ECSDataConfKeysIsConfMute";
NSString* const ECSDataConfKeysIsConfLock						= @"ECSDataConfKeysIsConfLock";
NSString* const ECSDataConfKeysChatRights						= @"ECSDataConfKeysChatRights";
NSString* const ECSDataConfKeysComponentNumber                  = @"ECSDataConfKeysComponentNumber";
NSString* const ECSDataConfKeysConferenceMode                   = @"ECSDataConfKeysConferenceMode";
// keys for schedule conf join result
NSString* const ECSScheduleConfId								= @"ECSScheduleConfId";
NSString* const ECSScheduleConfErrorDesc						= @"ECSScheduleConfErrorDesc";

//keys for phone user status keys
NSString* const ECSDataConfKeysPhoneuserID                      = @"ECSDataConfKeysPhoneuserID";
NSString* const ECSDataConfKeysUserType                         = @"ECSDataConfKeysUserType";
NSString* const ECSDataConfKeysUserStatus                       = @"ECSDataConfKeysUserStatus";
NSString* const ECSDataConfKeysMuteStatus                       = @"ECSDataConfKeysMuteStatus";
NSString* const ECSDataConfKeysDevCapable                       = @"ECSDataConfKeysDevCapable";
NSString* const ECSDataConfKeysPinNum                           = @"ECSDataConfKeysPinNum";
NSString* const ECSDataConfKeysBindingNid                       = @"ECSDataConfKeysBindingNid";
NSString* const ECSDataConfKeysTerminalType                     = @"ECSDataConfKeysTerminalType";
//added by zhangjianfang 20121108

NSString* const ECSDataConfKeyAudioCodecResult					= @"ECSDataConfKeyAudioCodecResult";
NSString* const ECSDataConfKeyAndioCodecConnect                    = @"ECSDataConfKeyAndioCodecConnect";
NSString* const ECSDataConfKeysLeaveConfReason					= @"ECSDataConfKeysLeaveConfReason";
// http链接返回错误
NSString* const ECSHTTPConnectError								= @"ECSHTTPConnectError";
// 网络链接返回错误
NSString* const ECSCurlConnectError								= @"ECSCurlConnectError";

// keys for eSpace Meeting query conf info or conf list from portal
// 返回对应请求的句柄，NSNumber＊类型
NSString* const ECSHTTPHandle                                   = @"ECSHTTPHandle";

//解析类型
NSString* const ECSPARSETYPE									= @"ECSPARSETYPE";

// 返回查询会议列表或者会议详情的结构体：返回ParseInfo
NSString* const ECSQueryPortalConfData                          = @"ECSQueryPortalConfData";

// 返回查询d错误码 NSNumber类型
NSString* const ECSQueryHttpErrorCode							= @"ECSQueryHttpErrorCode";

// 语音升级成视频时，对方接受
NSString* const ECSVideoReuqestAccepted							= @"ECSVideoRequestAccepted";
NSString* const ECSMDataConfKeysMGWInfoType						= @"ECSMDataConfKeysMGWInfoType";

