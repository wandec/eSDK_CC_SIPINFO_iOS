//
//  ECSNotifications.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/20.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECSDefines.h"

/* defines join data conf error code */
typedef enum {
    RESULT_SUCCESS								   = 0,  //加入成功
    RESULT_USER_REJECTED						   = 101,  //服务器拒绝客户端的连接
    RESULT_NETWORK_ERROR						   = 102,	 //网络错误，客户度连接不上服务器
    RESULT_VERSION_NOT_MATCH					   = 103,	 //客户端与服务器版本不匹配
    RESULT_PROTOCOL_NOT_RIGHT					   = 104,	 //客户端与服务器协议版本不匹配
    RESULT_TOO_MANY_CONNECTIONS					   = 105,	 //服务器端的连接数超过了授权
    RESULT_EXPIRED								   = 106,	 //时间戳不对，或者服务器的授权过期
    RESULT_DOMAIN_TERMINATED					   = 107,	 //会议已经结束
    RESULT_SERVER_CONN_FAILED					   = 108,	 //服务器与父服务器连接失败
    RESULT_SYS_SHUTINGDOWN						   = 109,	 //系统正在停止
    IMCC_RESULT_DOMAIN_MERGING					   = 110, //服务器之间正在重连
    
    IMCC_RESULT_AUTH_FAILED						   = 126, //会议请求验证失败
    //	1.Web site id 未配置正确，导致消息发送不到wts。
    //	2.客户端丛web上拿到的加密key和wts丛web上拿到的加密key不一致
    // 3.WTS没有工作
    // 4.WTS无法连接WEB
    
    IMCC_RESULT_UNKNOWN							   = 127, //其他原因
    // 1.会议数已满
    // 2.创建的会议已经存在
    
    RESULT_AUTH_REDIRECT						   = 128, //鉴权重定向
    RESULT_QUERY_PARENT_OR_TOP_AGENT_EXPIRED	   = 129, //查询parent或top ms超时
    RESULT_DOMAIN_LOCKED						   = 130, //会议锁定
    RESULT_AUTH_TIMEOUT							   = 131, //鉴权超时
    RESULT_AUTH_KEY_NOT_AVAILABLE	               = 132, //加密key错误
    RESULT_TOO_MANY_CONFERENCE	                   = 133, //会议数过多
    RESULT_TOO_MANY_CONFERENCE_USER                = 134, //会议人数过多
    RESULT_NOT_DATA_USER_LICENSE                   = 135  //没有license
}JoinDataConfErrorCode;


#pragma mark -
#pragma mark common keys
/* define of common keys */
ECS_EXTERN NSString* const ECSCommonKeyResultCode;					// 键值类型：NSNumber of ECSResultCode，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyResult;						// 键值类型：NSString，取值范围：{@"success",@"error",@"timeout"}，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyFlag;						// 键值类型：NSNumber of int，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyDescription;					// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyType;						// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyAccount;						// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyAccounts;					// 键值类型：NSArray of NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyGroupid;						// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyFixGroupInfo;				// 键值类型：FixGroup，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyGroupType;					// 键值类型：NSNumber，取值范围：0,1，默认值：NA，描述：0:固
// 定群，1讨论组
ECS_EXTERN NSString* const ECSCommonKeyIsAdmin;                     // 键值类型：NSNumber,0:非管理员；1:管理员
ECS_EXTERN NSString* const ECSCommonKeyAttendee;					// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyData;						// 键值类型：NSData，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyNickname;					// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyHeadid;						// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyNativeName;					// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyRequestId;					// 键值类型：NSNumber of int，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyMsgId;						// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyMsgs;						// 键值类型：NSArray of [ECSMsgBase subclass type]，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyMsg;							// 键值类型：ECSMsgBase subclass type，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyDeptDesc;					// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyDeptDescEng;					// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeySex;							// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyTag;							// 键值类型：id(NSObject)，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyContent;						// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyReasonType;					// 键值类型：NSNumber of int，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyQueryType;                   // 键值类型：NSString，取值范围{@"accept",@"refuse",@"Wait",@"groupAddSuccess"},默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyURL;							// 键值类型：NSString，取值范围：NA,默认值：NA，描述：NA

ECS_EXTERN NSString* const ECSCommonKeyDiscussionGroupInfo;         // 键值类型：DiscussionGroup，取值范围：NA,默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyTopicId;                    // 键值类型：NSString，取值范围：NA,默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyTopicOwnerId;               // 键值类型：NSString，取值范围：NA,默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyCircleTopic;               // 键值类型：CircleTopic，取值范围：NA,默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyComment;                   // 键值类型：CircleComment，取值范围：NA,默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyCommentId;                 // 键值类型：NSString，取值范围：NA,默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyCommentDBId;               // 键值类型：NSNumber of int，取值范围：NA,默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyCommentType;               // 键值类型：CircleCommentType，取值范围：NA,默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyTopicList;                 // 键值类型：NSArray of CircleTopic，取值范围：NA,默认值：NA，描述：NA

ECS_EXTERN NSString* const ECSCommonKeyTime;                      // 键值类型：NSString，取值范围：NA,默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonKeyNum;                       // 键值类型：NSNumber of int，取值范围：NA,默认值：NA，描述：NA

ECS_EXTERN NSString* const ECSCommonPAId;                           // 键值类型：NSString，取值范围：NA,默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonPAKeyMessageList;               // 键值类型：NSArray of PublicAccountMsg，取值范围：NA,默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonPAKeyPageNo;                    // 键值类型：NSNumber of int，取值范围：NA,默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonPAKeyPageSize;                  // 键值类型：NSNumber of int，取值范围：NA,默认值：NA，描述：NA
ECS_EXTERN NSString* const ECSCommonPAKeyTotalNo;                   // 键值类型：NSNumber of int，取值范围：NA,默认值：NA，描述：NA


/* head image service */
ECS_EXTERN NSString* const ECSGetHeadImageResultNotify;				// userInfo : ECSCommonKeyResult
//			+ ECSCommonKeyAccount
//			+ ECSCommonKeyData
//			+ ECSCommonKeyHeadid
ECS_EXTERN NSString* const ECSGetHeadHDImageResultNotify;           //同上
ECS_EXTERN NSString* const ECSSetSelfHeadImageResultNotify;			// userInfo : ECSCommonKeyResult
//			+ ECSCommonKeyAccount
//			+ ECSCommonKeyData
//			+ ECSCommonKeyHeadid
ECS_EXTERN NSString* const ECSHeadImageDeletedNotify;				// userInfo : ECSCommonKeyAccount
ECS_EXTERN NSString* const ECSTlsDownLoadFailNotify;

#pragma mark -
#pragma mark call service notifications
/* call service */

ECS_EXTERN NSString* const ECSTempGrpCreateAudioConfSuccessNotify;		// userInfo : nil
ECS_EXTERN NSString* const ECSTempGrpCreateAudioConfFailedNotify;		// userInfo : nil
ECS_EXTERN NSString* const ECSTempGrpMemberJoinAudioConfSuccessNotify;	// userInfo : @"attendee" (NSString*) -- attendee bindno
ECS_EXTERN NSString* const ECSTempGrpMemberJoinAudioConfFailedNotify;	// userInfo : @"attendee" (NSString*) -- attendee bindno
ECS_EXTERN NSString* const ECSTempGrpAudioConfClosedNotify;				// userInfo : nil
ECS_EXTERN NSString* const ECSTempGrpAudioConfMemberLeaveNotify;		// userInfo : @"attendee" (NSString*) -- attendee bindno

ECS_EXTERN NSString* const ECSCallSessionModifyResultNotify;			// userInfo : ECSCommonKeyResultCode -- value : enum of ECSResultCode
//          + ECSIsSelfHoldCallKey (optional)
ECS_EXTERN NSString* const ECSAddVideoCallAlerting;						// userInfo : nil
ECS_EXTERN NSString* const ECSAddVideoCallCanceled;						// userInfo : nil
ECS_EXTERN NSString* const ECSSessionModifyAckNotify;                   // userInfo :CALL_LOCAL_ADDR (NSString*),CALL_REMOTE_ADDR(NSString*)
// 语音转移，收到refer的成功响应（202 accept）之后，上报的通知
ECS_EXTERN NSString* const ECSTransferAcceptNotify;						// userInfo : nil

ECS_EXTERN NSString* const ECSIsSelfHoldCallKey;						// 键值类型：NSNumber of bool，取值范围：YES呼叫保持，NO呼叫恢复

ECS_EXTERN NSString* const ECSCallHoldOrResumeResultNotify;			// userInfo : ECSCommonKeyResultCode -- value : enum of ECSResultCode
//          + ECSIsSelfHoldCallKey
ECS_EXTERN NSString* const ECSKeyBidirectionalFriendList;
ECS_EXTERN NSString* const ECSKeyNewCircleStateUserDict;

/*************************************CallLogs***********************/

ECS_EXTERN NSString * const ECSCallLogDeleleteIdsKey;		// 键值类型：NSArray of ECSCallLog，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString * const ECSCallLogDeleteUserkey;		// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString * const ECSNewCallLogskey;				// 键值类型：NSArray of ECSCallLog，取值范围：NA，默认值：NA，描述：NA

ECS_EXTERN NSString * const ECSDelCallLogsResultNotify;		// 删除通话记录结果通知
// userInfo : ECSCommonKeyResultCode
//			+ ECSCommonKeyDescription
ECS_EXTERN NSString * const ECSUpdateCallLogsResultNotify;	// 更新通话记录结果通知
// userInfo : ECSCommonKeyResultCode
//			+ ECSCommonKeyDescription
//			+ ECSNewCallLogskey

/*************************************CallLogs**********************/

/*************************************CTD**********************/
ECS_EXTERN NSString * const ECSCTDCallIdKey;				// 键值类型：NSNumber of int ctd推送消息对应callid
ECS_EXTERN NSString * const ECSCTDFailedReasonKey;			// 键值类型：NSNumber of int ctd请求失败原因
ECS_EXTERN NSString * const ECSCTDResultNotify;				// ctd请求结果通知
// userInfo : ECSCommonKeyResultCode
//			+ ECSCTDCallIdKey
//			+ ECSCTDFailedReasonKey
//          + ECSCommonKeyRequestId
/*************************************CTD**********************/

/************************************************** LBS Location *****************************************************************/

ECS_EXTERN NSString * const ECSTopLevelLocationID;
ECS_EXTERN NSString * const ECSInternetLocationID;

ECS_EXTERN NSString * const ECSLocationInfoKey;				// 键值类型：LocationInfo，取值范围：NA，默认值：NA，描述：NA

ECS_EXTERN NSString * const ECSSetLocationResultNotify;		// 更新通话记录结果通知
// userInfo : ECSCommonKeyResultCode
//			+ ECSCommonKeyDescription

ECS_EXTERN NSString * const ECSQueryLocationResultNotify;	// 更新通话记录结果通知
// userInfo : ECSCommonKeyResultCode
//			+ ECSCommonKeyDescription
//			+ ECSLocationInfoKey

/************************************************** LBS Location ******************************************************************/
/************************************************** News Notify ******************************************************************/
ECS_EXTERN NSString * const ECSReceiveNewsTitleKey;     //键值类型：NSString*，取值范围：NA，默认值：NA，描述：NA
ECS_EXTERN NSString * const ECSReceiveNewsIdKey;        //键值类型：NSString*，取值范围：NA，默认值：NA，描述：NA

ECS_EXTERN NSString * const ECSReceiveNewsNotify;       //收到新公告通知
// userInfo : ECSReceiveNewsTitleKey,ECSReceiveNewsIdKey

/************************************************** News Notify  ******************************************************************/


/*********************** Local Contact*********************/
ECS_EXTERN NSString * const ECSLocalContactMatchResultKey; //键值类型 NSDictionary( key:account value:matched number
/*********************** Local Contact end****************/


//add by xieshuotao 20120507
/* CWComponent notifications for data conf */
/***************notifications for multimedia conf from IOSSDK to UI*****************/
ECS_EXTERN NSString* const ECSDataConfSetHostNotify;                //userInfo: ECSDataConfKeysUserID
ECS_EXTERN NSString* const ECSDataConfSetPresenterNotify;           //userInfo: ECSDataConfKeysUserID
ECS_EXTERN NSString* const ECSDataConfActiveTalkerNotify;           //userInfo: ECSDataConfKeysUserID
ECS_EXTERN NSString* const ECSDataConfTerminatedNotify;             //userInfo: nil
ECS_EXTERN NSString* const ECSDataConfJoinConfResultNotify;         //userInfo: ECSDataConfKeysJoinResult
ECS_EXTERN NSString* const ECSDataConfNetBrokenNotify;              //userInfo: nil
ECS_EXTERN NSString* const ECSDataConfUserJoinInNotify;             //userInfo: ECSDataConfKeysUserID
//        + ECSDataConfKeysUserBindNo
//        + ECSDataConfKeysUserName
//        + ECSDataConfKeysIsSelf

ECS_EXTERN NSString* const ECSDataConfUserLeaveNotify;              //userInfo: ECSDataConfKeysUserID
ECS_EXTERN NSString* const ECSDataConfReceiveChatMsgNotify;         //userInfo: ECSDataConfKeysMsgSenderID
//        + ECSDataConfKeysMsgSenderName
//        + ECSDataConfKeysMsgReceiverID
//        + ECSDataConfKeysMsgReceiverName
//        + ECSDataConfKeysMsgContent,
//        + ECSDataConfKeysMsgTime

ECS_EXTERN NSString* const ECSDataConfSelfKickOffByHostNotify;      //userInfo: ECSDataConfKeysLeaveConfReason (NSNumber *)
ECS_EXTERN NSString* const ECSDataConfReceiveShareDataNotify;       //userInfo: ECSDataConfKeysShareImage
//        + ECSDataConfKeysShareDataType,
//        + ECSDataConfKeysUserID] ---- only when recieve video data has this key!

ECS_EXTERN NSString* const ECSDataConfStopSharingDataNotify;        //userInfo: nil
ECS_EXTERN NSString* const ECSDataConfChangeASSharingDataNotify;    //userInfo:nil
ECS_EXTERN NSString* const ECSDataConfStopsharingDocNotify;         //userInfo: nil
ECS_EXTERN NSString* const ECSDataConfVideoStatusNotify;            //userInfo: ECSDataConfKeysUserID
//        + ECSDataConfKeysVideoStatus
//        + ECSDataConfKeysDeviceName
ECS_EXTERN NSString* const ECSDataConfDelVideoCloseNotify;

ECS_EXTERN NSString* const ECSDataConfCameraInfoNotify;             //userInfo: ECSDataConfKeysUserID
//        + ECSDataConfKeysDeviceNameArray

ECS_EXTERN NSString* const ECSDataConfKeysUserVideoDeviceAddOrDel;
ECS_EXTERN NSString* const ECSDataConfStartScreenSharing;           //userInfo: nil

ECS_EXTERN NSString* const ECSDataConfMute;							//userInfo: ECSDataConfKeysIsConfMute
ECS_EXTERN NSString* const ECSDataConfKeysConferenceMode;
ECS_EXTERN NSString* const ECSDataConfShareModeChangeNotify;		//userInfo:ECSDataConfKeysLastMode (NSNumber of int)
//		 + ECSDataConfKeysCurrentMode (NSNumber of int)

ECS_EXTERN NSString* const ECSDataConfVideModeChangeNotify;			//userInfo:ECSDataConfKeysCurrentVideoMode
ECS_EXTERN NSString* const ECSDataConfOverMaxAudioOpen;
ECS_EXTERN NSString* const ECSDataConfOverMaxCameraOpen;
ECS_EXTERN NSString* const ECSDataConfNotOpenCameraInBack;
ECS_EXTERN NSString* const ECSDataConfDisConnectNotify;
ECS_EXTERN NSString* const ECSDataConfReConnectNotify;

// 正在共享着的userId
ECS_EXTERN NSString* const ECSDataConfCurrentSharingAttendeeNotify; //userInfo: ECSDataConfKeysUserID

ECS_EXTERN NSString* const ECSDataConfPhoneUserJoinInNotify;
ECS_EXTERN NSString* const ECSDataConfPhoneUserLeaveNotify;
ECS_EXTERN NSString* const ECSDataConfPhoneUserCallNidNotify;
ECS_EXTERN NSString* const ECSDataConfPhoneUserNameNotify;
ECS_EXTERN NSString* const ECSDataConfUserInfoModifyNotify;
ECS_EXTERN NSString* const ECSDataConfKickOffModifyUserNotify;
ECS_EXTERN NSString* const ECSDataConfUSerAudioCapilityModifyUserNotify;

ECS_EXTERN NSString* const ECSDataConfAudioCodecResultNotify;		//userInfo:ECSDataConfKeyAudioCodecResult (NSNumber of BOOL)

// notification names of portal query result
ECS_EXTERN NSString* const ECSQueryConfListNotify;				//获取会议列表返回通知
ECS_EXTERN NSString* const ECSQueryConfInfoNotify;				//获取会议详情返回通知
ECS_EXTERN NSString* const ECSQueryConfMembesNotify;			//获取会议成员返回通知
ECS_EXTERN NSString* const ECSSendEmailResultNotify;			//发送会议邮件邀请返回的通知

/***************dictionary keys for multimedia conf from IOSSDK to UI*****************/
ECS_EXTERN NSString* const ECSDataConfKeysUserVideoDeviceInfo;
ECS_EXTERN NSString* const ECSDataConfKeysNetSignalValue;
ECS_EXTERN NSString* const ECSDataConfKeysUserID;
ECS_EXTERN NSString* const ECSDataConfKeysUserBindNo;
ECS_EXTERN NSString* const ECSDataConfKeysUserName;
ECS_EXTERN NSString* const ECSDataConfKeysIsSelf;
ECS_EXTERN NSString* const ECSDataConfKeysIsPresenter;
ECS_EXTERN NSString* const ECSDataConfKeysIsHost;
ECS_EXTERN NSString* const ECSDataConfKeysTransferBindindNum;
ECS_EXTERN NSString* const ECSDataConfKeysJoinResult;
ECS_EXTERN NSString* const ECSDataConfKeysShareDataType;
ECS_EXTERN NSString* const ECSDataConfKeysShareImage;
ECS_EXTERN NSString* const ECSDataConfKeysLastMode;
ECS_EXTERN NSString* const ECSDataConfKeysCurrentMode;
ECS_EXTERN NSString* const ECSDataConfKeysCurrentVideoMode;
ECS_EXTERN NSString* const ECSDataConfKeysJoinOrder;          //是否先于我入会
ECS_EXTERN NSString* const ECSDataConfKeysMaxMicOpenNumber;
ECS_EXTERN NSString* const ECSDataConfKeysUserAudioCapility;

// keys for chat message in data conf
ECS_EXTERN NSString* const ECSDataConfKeysMsgSenderID;
ECS_EXTERN NSString* const ECSDataConfKeysMsgReceiverID;
ECS_EXTERN NSString* const ECSDataConfKeysMsgSenderName;
ECS_EXTERN NSString* const ECSDataConfKeysMsgReceiverName;
ECS_EXTERN NSString* const ECSDataConfKeysMsgContent;
ECS_EXTERN NSString* const ECSDataConfKeysMsgLength;
ECS_EXTERN NSString* const ECSDataConfKeysMsgTime ;

// keys for video status
ECS_EXTERN NSString* const ECSDataConfKeysVideoStatus;
ECS_EXTERN NSString* const ECSDataConfKeysDeviceName;
ECS_EXTERN NSString* const ECSDataConfKeysDeviceNameArray;
ECS_EXTERN NSString* const ECSDataConfKeysDeviceId;
//end by xieshuotao 20120507

ECS_EXTERN NSString* const ECSDataConfKeyHasMic;
ECS_EXTERN NSString* const ECSDataConfKeyMicStatus;
//区分自己是否可更改静音状态
ECS_EXTERN NSString* const ECSDataConfKeyMuteMicOwner;
ECS_EXTERN NSString* const ECSDataConfKeysIsConfMute;
ECS_EXTERN NSString* const ECSDataConfKeysIsConfLock;
ECS_EXTERN NSString* const ECSDataConfKeysChatRights;
ECS_EXTERN NSString* const ECSDataConfKeysComponentNumber;

// keys for schedule conf join result
ECS_EXTERN NSString* const ECSScheduleConfId;
ECS_EXTERN NSString* const ECSScheduleConfErrorDesc;

//
ECS_EXTERN NSString* const ECSDataConfKeyAudioCodecResult;
ECS_EXTERN NSString* const ECSDataConfKeyAndioCodecConnect;

// 离会原因
ECS_EXTERN NSString* const ECSDataConfKeysLeaveConfReason;
/* index				key				value					description					rang */

//keys for phone user status keys
ECS_EXTERN NSString* const ECSDataConfKeysPhoneuserID;
ECS_EXTERN NSString* const ECSDataConfKeysUserType;
ECS_EXTERN NSString* const ECSDataConfKeysUserStatus;
ECS_EXTERN NSString* const ECSDataConfKeysMuteStatus;
ECS_EXTERN NSString* const ECSDataConfKeysDevCapable;
ECS_EXTERN NSString* const ECSDataConfKeysPinNum;
ECS_EXTERN NSString* const ECSDataConfKeysBindingNid;
ECS_EXTERN NSString* const ECSDataConfKeysTerminalType;
//added by zhangjianfang 20121108
// http链接返回错误
ECS_EXTERN NSString* const ECSHTTPConnectError;
// 网络链接返回错误
ECS_EXTERN NSString* const ECSCurlConnectError;

// keys for eSpace Meeting query confList & query confDetail

ECS_EXTERN NSString* const ECSPARSETYPE;						//解析类型

ECS_EXTERN NSString* const ECSHTTPHandle;                       // 返回对应请求的句柄，NSNumber＊类型
// ui使用发送请求时候得到的handle与此字段比较来判断是否需要处理

ECS_EXTERN NSString* const ECSQueryPortalConfData;              // 返回查询会议列表或者会议详情的结构体：返回ParseInfo

ECS_EXTERN NSString* const ECSQueryHttpErrorCode;         // 返回查询会议列表的错误码，NSString＊类型，“0”表示成功

ECS_EXTERN NSString* const ECSVideoReuqestAccepted;				// 语音升级成视频时，对方接受

ECS_EXTERN NSString* const ECSMDataConfKeysMGWInfoType;			// mgw服务器的info类型，NSString类型，sdk负责透传。
// MGW_INFO_TYPE_NO_LICENSE || MGW_INFO_TYPE_NO_REJECT

#pragma mark -
#pragma mark 遗留通知

/*******************************************************************************************
 SIP相关的通知消息
 ********************************************************************************************/

//  addedd by k00228462 2012.11.30 LENT02 迭代2 语音留言
/* 语音留言通知, 参数: userInfo  */
#define   NTF_SIP_NEW_VOICE_MESSAGES                      @"NTF_SIP_NEW_VOICE_MESSAGES"//语音留言状态通知（包括已读未读、新留言）
#define	  NTF_SIP_NEW_VOICE_MESSAGES_SUB_ID				@"NTF_SIP_NEW_VOICE_MESSAGES_SUB_ID"
#define	  NTF_SIP_NEW_VOICE_MESSAGES_NEW_MESSAGE_NUMBER			  @"NTF_SIP_NEW_VOICE_MESSAGES_NEW_MESSAGE_NUMBER"
#define	  NTF_SIP_NEW_VOICE_MESSAGES_OLD_MESSAGE_NUMBER			  @"NTF_SIP_NEW_VOICE_MESSAGES_OLD_MESSAGE_NUMBER"

//  addedd by k00228462 2012.11.30 LENT02 迭代2 语音留言 end

/* 新电话来电, 参数: NSString* peerNumber */
#define   NTF_SIP_INCOMING_CALL                      @"NTF_SIP_INCOMING_CALL"

/* 对方挂断电话或者会议主持主动结束会议，或者对方取消未接通的呼叫, key @"isClosedAtRunning" NSNumber of bool */
#define   NTF_SIP_BYE                                @"NTF_SIP_BYE"

/* 对方无法接通 */
#define   NTF_SIP_PEER_UNAVAILABLE                   @"NTF_SIP_PEER_UNAVAILABLE"

/* 对方振铃 参数: NSString* peerNumber */
#define   NTF_SIP_PEER_ALERTING                      @"NTF_SIP_PEER_ALERTING"

//add on 2012.8.15,deal with 183 msg /* 收到被叫的临时响应,呼叫正在处理中/
#define   NTF_SIP_183_PROGRESS                       @"NTF_SIP_183_PROGRESS"
//end add on 2012.8.15

// UserInfo: Key : CALL_SDPINFO, Value : NSNumber of bool (YES mean has SDP)
#define   NTF_SIP_CALL_QUEUED_182                   @"NTF_SIP_CALL_QUEUED_182"

//add on 2012.12.5,deal with 181 msg,对方呼叫被转发
#define NTF_SIP_PEER_FORWARD                        @"NTF_SIP_PEER_FORWARD"
//end add on 2012.12.5

/* 对方接听 参数: NSString* peerNumber*/
#define   NTF_SIP_PEER_ANSWER_CALL                   @"NTF_SIP_PEER_ANSWER_CALL"

/* 被呼叫后返回200后对方返回ACK消息 */
#define   NTF_SIP_PEER_ANSWER_ACK					@"NTF_SIP_PEER_ANSWER_ACK"

/* 网络状态信号强度 */
#define   NTF_SIP_NET_STATE_CHANGED                        @"NTF_SIP_NET_STATE_CHANGED"


/* 通话相关状态上报 */
#define   NTF_SIP_NET_INFO_NOTIFY                     @"NTF_SIP_NET_INFO_NOTIFY"
#define   NTF_SIP_NET_INFO_LOST_KEY               @"NTF_SIP_NET_INFO_LOST_KEY"
#define   NTF_SIP_NET_INFO_DELAY_KEY              @"NTF_SIP_NET_INFO_DELAY_KEY"
#define   NTF_SIP_NET_INFO_JITTER_KEY             @"NTF_SIP_NET_INFO_JITTER_KEY"

/* 通话mos值上报 */
#define NTF_SIP_NET_MOS_NOTIFY                      @"NTF_SIP_NET_MOS_NOTIFY"
#define NTF_SIP_NET_MOS_KEY                         @"NTF_SIP_NET_INFO_MOS_KEY"

/* 视频网络状态信号强度 */
#define   NTF_SIP_VIDEO_NET_STATE_CHANGED                        @"NTF_SIP_VIDEO_NET_STATE_CHANGED"

/*视频操作结果 */
#define   NTF_SIP_VIDEO_OPERATION                        @"NTF_SIP_VIDEO_OPERATION"

/*视频大小改变 */
#define   NTF_SIP_VIDEO_FRAMESIZE_CHANGE                        @"NTF_SIP_VIDEO_FRAMESIZE_CHANGE"

/*系统中断事件*/
/* object : 0 中断结束 1 开始中断*/
#define   NTF_SYSTEM_INTERRUPTION                       @"NTF_SYSTEM_INTERRUPTION"

/* 关闭数据会议界面 */
#define   NTF_CW_DATA_CONFERENCE_TERMINATE				@"NTF_CW_DATA_CONFERENCE_TERMINATE"

/* 主持人关闭数据会议 */
#define   NTF_CW_DATA_CONFERENCE_TERMINATE_BY_HOST	    @"NTF_CW_DATA_CONFERENCE_TERMINATE_BY_HOST"

/* 设置当前在讲话的人的信息 */
#define   NTF_CW_DATA_CONFERENCE_SET_NET_BROKEN			@"NTF_CW_DATA_CONFERENCE_SET_NET_BROKEN"

/* 对方呼叫保持 */
#define   NTF_SIP_PEER_HELD								@"NTF_SIP_PEER_HELD"

/* 对方取消呼叫保持 */
#define   NTF_SIP_PEER_RETRIEVED						@"NTF_SIP_PEER_RETRIEVED "

//UC2.0_DEV
#define   NTF_SIP_TRANSFER_STARTS_TRYING                      @"NTF_SIP_TRANSFER_STARTS_TRYING"

#define   NTF_SIP_TRANSFER_FAILED                       @"NTF_SIP_TRANSFER_FAILED"

#define   NTF_SIP_TRANSFER_SUCCESS                      @"NTF_SIP_TRANSFER_SUCCESS"

/* UCV2: Notify UI that schedule conf invite has come and UI should draw conf view */
#define	  NTF_SIP_SCHEDULE_CONF_JOIN_SUCCESS			@"NTF_SIP_SCHEDULE_CONF_JOIN_SUCCESS"

#define	  NTF_SIP_MEDIAX_CONF_JOIN_SUCCESS				@"NTF_SIP_MEDIAX_CONF_JOIN_SUCCESS"

/* UCV2: Notify UI that schedule conf invite has come and UI should draw conf view */
#define	  NTF_SIP_SCHEDULE_CONF_JOIN_TIME_OUT			@"NTF_SIP_SCHEDULE_CONF_JOIN_TIME_OUT"

/* UCV2: Notify UI change from common conversation to voice conference */
#define   NTF_UPGRADE_TO_VOICE_CONFERENCE               @"NTF_UPGRADE_TO_VOICE_CONFERENCE"

//userInfo :    NTF_SIP_DND_ACTION_TYPE_KEY     NSNumber:DND_ACTION_TYPE
//              NTF_SIP_DND_ACTION_RESULT_KEY   NSNumber:BOOL
#define  NTF_SIP_DND_ACTION_NOTIFY                      @"NTF_SIP_DND_ACTION_NOTIFY"
#define  NTF_SIP_DND_ACTION_RESULT_KEY                  @"NTF_SIP_DND_ACTION_RESULT_KEY"
#define  NTF_SIP_DND_ACTION_TYPE_KEY                    @"NTF_SIP_DND_ACTION_TYPE_KEY"

/***********************************************************************
 * add by lushuang(00202855)
 * 通知UI当前状态机发生变化，从而改变自身状态
 ***********************************************************************/
// when call or conference finished, the state change to idle
#define NTF_STATE_TO_IDLE								@"NTF_STATE_TO_IDLE"
// when call or conference start, the state change to busy
#define NTF_STATE_TO_BUSY							@"NTF_STATE_TO_BUSY"

/* 公告列表查询结果 */
#define NTF_BULLETIN_LIST					@"NTF_BULLETIN_LIST"

/* 公告详情查询结果 */
#define NTF_BULLETIN_DETAIL				@"NTF_BULLETIN_DETAIL"
//end

//音频初始化成功通知 add by jinlu
#define NTF_RST_AUDIOROUTER			@"NTF_RST_AUDIOROUTER"

#define NTF_FILE_PLAY_ENDED			@"NTF_FILE_PLAY_ENDED"

