//
//  ECSDefines.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/20.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#ifdef __cplusplus
#define ECS_EXTERN		extern "C"
#else
#define ECS_EXTERN		extern
#endif

#define	ECS_IFFREE(p)	do { if(p) { [p release]; p=nil; } } while(0)

//应用程序根目录地址
#define APP_DOC_PATH		[NSHomeDirectory() stringByAppendingPathComponent:@"Documents"]

typedef enum {
    ANSWER_VIDEO = 0,	// 被叫接听升级的邀请
    REJECT_VIDEO,		// 被叫拒绝升级的邀请
    CANCEL_VIDEO,		// 主叫在没有收到被叫响应前取消邀请
    UNKNOW_ACTION
}VIDEO_ACTION;

typedef enum {
    OPEN_VIDEO = 1,
    CLOSE_VIDEO = 2,
    START_VIDEO = 4,
    OPENORSTART = 5,
    STOP_VIDEO = 8
}VIDEO_CONTROL;

typedef enum
{
    ServiceREQResultSuccess			= 0,	//
    ServiceREQResultFailure			= -1,	//
    ServiceREQResultInvalidParam	= -2,	//
    ServiceREQResultSendFailed		= -3	//
}ServiceREQResult;

typedef enum
{
    kECSSuccess				= 0,
    kECSFailure				= 1,
    kECSTimeout				= 2,
    kECSResultCodeUnkown	= 100,
}ECSResultCode;

#define APNS_PRODUCT    @"APNS_PRODUCT"
#define APNS_DEV        @"APNS_DEV"
#define APNS_ENTERPRISE @"APNS_ENTERPRISE"

//APNS SERVER类型
typedef enum{
    APNS_SERVER_TYPE_INVALID    = 0,
    APNS_SERVER_TYPE_PRODUCTION = 1,
    APNS_SERVER_TYPE_DEVELOPE   = 2
} APNS_SERVER_TYPE;

#define HMETraceSwith 0
//hme录制模式
typedef enum{
    HMETraceMode_Disable    = 0,    //trace关闭
    HMETraceMode_RealTime   = 1,    //实时,每10ms写一次
    HMETraceMode_Prestore   = 2     //预录，只trace最后30s
} HMETraceMode;

//APNS证书类型
typedef enum{
    APNS_CER_TYPE_INVALID       = 0,
    APNS_CER_TYPE_APPSTORE      = 1,
    APNS_CER_TYPE_ENTERPRISE    = 2,
    APNS_CER_TYPE_ENTERPRISE_HD = 3,
    APNS_CER_TYPE_APPSTORE_HD   = 4
} APNS_CER_TYPE;

//越狱检测策略
typedef enum{
    JAILBREAK_DETECT_NONE   = 0,    //不检测
    JAILBREAK_DETECT_TIP    = 1,    //检测并提示
    JAILBREAK_DETECT_FORBID = 2     //检测并禁止登录
} JAILBREAK_DETECT;

//屏幕尺寸
typedef enum{
    SCREEN_SIZE_3_5     = 1,    //3.5寸
    SCREEN_SIZE_4       = 2,    //4寸
    SCREEN_SIZE_720P    = 3     //720P
} SCREEN_SIZE;

/* enum for supported functions */
typedef enum
{
    /* 0..EN_LOGINACK_FUNCID_MAX_LEN 严格对应Login响应中funcid的位数 */
    EN_FUNC_SMS						= 0,	/* 是否支持短信能力 checkversion & login*/
    EN_FUNC_CTC						= 1,    /* 是否支持手机端即时会议能力  chreckversion & login*/
    EN_FUNC_CTD						= 2,    /* 是否支持CTD checkversion & login*/
    EN_FUNC_IM						= 3,    /* 是否支持IM即时消息 login*/
    EN_FUNC_VOIP					= 4,	/* 判断服务器是否支持Voip checkversion & login*/
    EN_FUNC_VEDIO					= 9,	/* 是否支持视频 login*/
    EN_FUNC_MULTIMEDIA				= 11,	/* 是否支持多媒体会议 login */
    EN_FUNC_FILE_TRANSPOTR			= 12,	/* 是否支持文件传输 login*/
    EN_FUNC_MEDIAX					= 14,   /* 是否支持显示和加入预约会议 login*/
    EN_FUNC_NEWS					= 15,   /* 是否支持公告 login*/
    EN_FUNC_COUNTRYCODE				= 16,	/* 是否支持国家码 login*/
    EN_FUNC_SEARCHMOBILE			= 17,	/* 是否支持批量匹配号码 login*/
    EN_FUNC_CREATE_SCHEDULE_MEETING	= 18,	/* 是否支持创建预约会议 login*/
    EN_FUNC_TRANSFER				= 19,	/* 是否支持refer转接 控制2方通话中转到第三方和会议中转到第三方 login*/
    EN_FUNC_FORWARD  			    = 20,	/* 是否支持呼叫前转 login*/
    EN_FUNC_VEDIOCALL				= 21,	/* 是否支持H264点对点视频通话 login*/
    EN_FUNC_TRANSFER_HWUC			= 22,	/* 是否支持HWUC会议中转移 login*/
    EN_FUNC_DEPTMSG					= 23,	/* 是否支持部门通知 login*/
    EN_FUNC_FIXGROUP				= 24,	/* 是否支持固定群组 login */
    
    EN_FUN_CALL_HOLD				= 25,	/* 呼叫保持，如果不开启，则灰化按键。对应datamodel中的memFuncFlag 中的取值,memFeatureFlag无此值。
                                             支持动态变更通知。login */
    EN_FUNC_PASSWORD_CALL_LIMIT		= 26,	/* 密码限呼功能，功能位开的时候，显示一个提示，不能呼出。类型见callLimitType.
                                             对应datamodel中的FuncFlag和featureFlag取”|”之后的值。支持动态变更通知。login */
    EN_FUNC_CALL_WAIT				= 27,	/* 呼叫等待, ，缺省为0 如果开启，应该在收到第二路呼叫时，回182并放提示音。否则，直接拒绝。
                                             对应datamodel中的FuncFlag和featureFlag取”|”之后的值。支持动态变更通知。login */
    EN_FUNC_CALL_FORWARDING_UNCONDITIONAL = 28, /* login */
    EN_FUNC_CALL_FORWORDING_ONBUSY	= 29,	/* login */
    EN_FUNC_CALL_FORWORDING_NOREPLY	= 30,	/* login */
    EN_FUNC_CALL_FORWORDING_OFFLIEN = 31,	/* login */
    EN_FUNC_VOICE_MAIL				= 32,	/* 语音留言功能，缺省为0。login */
    EN_FUNC_PRESENCE				= 33,	/* 是否具备presence权限，1为具备，0不具备。缺省为1具备。如果老的MAA没返回这个功能位，客户端理解为具备PRESENCE权限。login */
    
    EN_FUNC_PROMPT_FOR_USE_CTD_CTC	= 34,	/* CTD是否需要增加告警提示 */
    EN_FUNC_PROMPT_FOR_USE_CTC		= 35,	/* CTC是否需要增加告警提示 */
    
    EN_FUNC_LBS						= 36,	/* LBS功能，缺省为0。1代表支持。0代表不支持。*/
    EN_FUNC_SNR						= 37,	/* SNR功能。1代表支持，0代表不支持。缺省0 */
    EN_FUNC_VOIP_FOR_NO_WIFI		= 38,	/* 非WIFI环境下也支持VOIP呼叫控制位。
                                             1代表“非WIFI下也支持VOIP”。0代表“非WIFI下不支持VOIP”。华为UC和老的UC2.0不返回时客户端默认为出厂值0。沙特石油版本要返回1。*/
    EN_FUNC_CALLLOG					= 39,	/* 支持云存储。login */
    EN_FUNC_CREATE_GROUP			= 40,	/* 支持在加人时创建新分组。1支持，0不支持。 login */
    EN_FUNC_UNINTERRUPT				= 41,	/* 免打扰功能位，1支持，0不支持。 login */
    EN_FUNC_UM						= 42,	/* 指示终端可使用UM特性，在body体中发送图文混排内容 */
    EN_FUNC_MSGLOG					= 43,	/* 1由服务器指示客户端支持IMLOG的获取。0不支持。 */
    EN_FUNC_DYNAMIC_LABEL_CONFIG	= 44,	/* 动态标签特性 功能位，作用是：终端可以根据MAA下发的标签进行动态修改界面的显示。 */
    EN_FUNC_AUTO_ANSWER             = 45,   /* 为1时，所有来电自动接听，以满足临时的展厅需求。默认为0。不按自动接听处理。（不可控制）*/
    EN_FUNC_AUTO_CONF_ANSWER        = 46,   /*用于指定客户端是否在收到pushmail一键入会请求时，根据来电匹配列表情况自动接听，1表示自动接听，0表示手动接听。
                                             仅华为UC下使用，且仅针对华为Media Pad使用。对于UC2.0，该功能位默认填0。
                                             */
    EN_FUNC_VISUAL_VOICE_MAIL       = 47,   /*是否启用可视化语音留言功能，0不启用，1启用，对应AA登录接口funcId功能位第112位。*/
    EN_FUNC_QOS_REPORT              = 48,   /*QoS上报开关，MAA从AA的sEntControlFlag字段对应bit位获取而来：具体对应sEntControlFlag[9]
                                             （注，sEntControlFlag比特功能位从0开始计算，因此此处是sEntControlFlag[9]）。0 关，1开。
                                             注意：第[49] QoS上报开关来源是企业顶级配置，是登录时生效一次的。在0x041a中该功能位不生效，MAA在0x041a中对应[49]位默认填0，终端应忽略。
                                             */
    EN_FUNC_VOIP_REACHABLE          = 49,   /*VOIP号码可达性查询(功能命令码:0x02 11)功能位，如果打开，则终端可使用0x0211，如果关闭，终端不能使用0x0211。1打开，0关闭。
                                             仅华为UC使用，UC2.0不使用。
                                             */
    EN_FUNC_DISCUSSION_GROUP        = 50,   /*是否支持讨论组,仅华为UC使用，UC2.0不使用*/
    EN_FUNC_ANTI_COPY               = 51,   /*MDM防拷贝功能，开启后支持清除剪切板*/
    EN_FUNC_TLS_SRTP_FORCE_DISABLED = 52,   /*TLS/SRTP加密是否强制关闭，YES：强制关闭忽略插件参数配置，NO：非强制关闭读取插件参数配置*/
    EN_FUNC_SERVER_MASK_GROUP_MSG   = 53,   /*群组消息屏蔽是否上报服务器功能位*/
    EN_FUNC_AGC                     = 54,   /*AGC降噪功能位*/
    EN_FUNC_PUSHSWICH               = 55,   /*push消息开关设置功能位*/
    EN_FUNC_CALLREPORT              = 56,   /*voip语音质量上报功能位*/
    EN_FUNC_HISTORY_VERSION_RECORD  = 57,   /* 支持服务器查询版本历史更新 */
    EN_FUNC_FRIEND_CIRCLE           = 58,   /* 支持朋友圈 */
    EN_FUNC_PUBLIC_ACCOUNT          = 59,   /* 支持公众号 */
    EN_FUNC_ROAMING_MESSAGE         = 60,   /* 支持IM聊天记录漫游*/
    EN_FUNC_TRANSFER_INCOMING_CALL  = 61,   /* 支持通话前呼叫偏转*/
    EN_FUNC_EVENTREPORT             = 62,   /* 终端时间上报*/
    EN_FUNC_UMTRANSPORT_ENCRYPT     = 63,   /* 终端与UM交互协议 0 http 1 https*/
    EN_LOGINACK_FUNCID_MAX_LEN,				/* 登录响应中funcid最大有效位数 */
    
    EN_FUNC_DATACONF				= 99,	/* 是否支持数据会议 checkversion & login（区分手机和pad）*/
    
    EN_FUNC_ADDDOMAIN				= 100,	/* voip鉴权时username是否添加域名 checkversion*/
    EN_FUNC_TRANSPHONE				= 101,  /* 是否支持来电转接能力 checkversion*/
    EN_FUNC_CALLFORWARD				= 102,	/* 是否支持给予状态路由查询与设置 checkversion*/
    EN_FUNC_MANAGECONF				= 103,	/* 是否支持会议控制 checkversion*/
    EN_FUNC_ENCRYPT					= 104,	/* 是否支持aes加密 checkversion*/
    EN_FUNC_SENSITIVE_WORDS			= 105,  /* 是否支持敏感词 checkversion*/
    EN_FUNC_ALLOWPHONECALL			= 106,  /* 是否允许本地phone呼叫实现CTD checkversion*/
    EN_FUNC_3GLOGIN					= 107,	/* 0-表示不允许3G登录，1－表示允许3G登录，为了解决C01版本的兼容性问题，C02及以上版本必须是1。当UC2.0解决同时3GLogin标志位为0时，采用不允许3G登录的流程。checkversion */
    EN_FUNC_SUBSCRIBE_NON_FRIEND    = 108,  /*是否支持非好友状态订阅 checkversion*/
    EN_FUNC_ROOTFOBID               = 109,  /*是否允许root设备登录 checkversion C10版本申明废弃*/
    EN_FUNC_BATTERYSAVING_MODE      = 110,  /*是否允许设置省电模式 checkversion*/
    
    EN_FUNC_TEMPGRP					= 200,	/* 是否支持临时群 */
    EN_FUNC_HEAD_IMAGE				= 201,	/* 是否支持联系人头像 */
    EN_FUNC_CONTACT_SIMPLIFY		= 202,	/* 是否支持通讯录精简模式 */
    EN_FUNC_IM_VIA_DATACONF_SERVER	= 203,  /* 是否支持通过数据会议服务器的IM */
    EN_FUNC_TRANSFER_IN_CALL        = 204,  /* 是否支持点对点通话中的转移*/
    EN_FUNC_TRANSFER_IN_CONF        = 205,  /* 是否支持会议中的转移*/
    EN_FUNC_VOIP_TO_AUDIO_CONF		= 206,	/* 是否支持普通通话转多人语音会议 */
    EN_FUNC_BUTT
}SUPPORT_FUNC_TYPE;

//UC2.0_DEV xieshuotao
/*emnu for attendee conf state*/
typedef enum {
    ATTENDEE_CONF_STATE_INVITING		= 1,			//正在邀请
    ATTENDEE_CONF_STATE_INVITE_SUCCESS	= 2,			//邀请成功
    ATTENDEE_CONF_STATE_INVITE_FAILED	= 3,			//邀请失败
    ATTENDEE_CONF_STATE_HANG_UP			= 4,			//挂断
    ATTENDEE_CONF_STATE_JOIN_SUCCESS	= 5,			//加入成功
    ATTENDEE_CONF_STATE_QUIT			= 6,			//退出
    ATTENDEE_CONF_STATE_HOLD			= 7				//保持
}EN_ATTENDEE_CONF_STATE;

typedef enum {
    ATTENDEE_AUDIO_RIGHT_ENABLE			= 0,			//有语音发言权
    ATTENDEE_AUDIO_RIGHT_DISABLE		= 1,			//没有语音发言权
    ATTENDEE_AUDIO_RIGHT_APPLYING		= 2				//正在申请发言权
}ATTENDEE_AUDIO_RIGHT;

//UC2.0_DEV
typedef enum
{
    EN_TRANS_CALL_TO_CALL,
    EN_TRANS_CALL_TO_CONF,
    EN_TRANS_CONF_TO_CALL,
    EN_TRANS_CALL_TO_SNR,  //ATS业务：一键转接
    EN_TRANSFER_BUTT,
}EN_TRANSFER_TYPE;

typedef enum
{
    EN_CONF_NO_RIGHT,
    EN_CONF_TALKING,
    
    EN_CONF_TALK_RIGHT_BUTT,
}EN_CONF_TALK_RIGHT;

// 服务器类型，checkversion ack中返回
typedef enum tsgServerType
{
    SERVERTYPE_UC_UNKNOWN,
    SERVERTYPE_UC_V1,   // UC1.0
    SERVERTYPE_UC_HW,   // HUAWEI UC
    SERVERTYPE_UC_V2,   // UC2.0
    SERVERTYPE_UC_IPT,  // IPT
    
    SERVERTYPE_UC_BUTT
}SERVERTYPE;

#define UC_UNKNOWN
#define UCV1		(@"UC1.0")
#define UCHW		(@"HUAWEIUC")
#define UCV2		(@"UC2.0")
#define UCIPT       (@"IPT")

/* 聊天消息发送模式 */
typedef enum
{
    kSendMsgViaMaa = 0,				// 通过MAA服务器发送
    kSendMsgViaConfComponent = 1	// 通过多媒体会议组件发送(UC1.0开多媒体会议时使用)
}ChatMsgSendMode;

/* 临时群创建模式 */
typedef enum
{
    kCreateTempGroup = 0,				// 直接创建临时群
    kSingleChatChangedToTempGroup = 1,	// 从单聊转成临时群
    kSingleChatChangedToTempGroupWhenCallProcessing = 2,
}TempGroupCreatedMode;

typedef enum {
    EN_STATE_LOGIN_IDLE			= 0,
    EN_STATE_LOGIN_PROCESS		= 1,
    EN_STATE_LOGIN_NORMAL		= 2
}LOGIN_STATE;

//语音状态类型
typedef enum
{
    AUDIO_STATE_CALLING = 0,		//多人语音成员入会状态
    AUDIO_STATE_TALKING,			//多人语音成员会议中状态
    AUDIO_STATE_CALLOVER,			//多人语音成员离会状态
    AUDIO_STATE_INIT,				//unuse
    AUDIO_STATE_FORBID,				//多人语音成员静音状态
    AUDIO_STATE_DELETE,				//unuse
    
    AUDIO_STATE_BUTT				//unuse
}EN_AUDIO_STATE;

typedef  enum
{
    enForbidden,      /* 账号被禁用 */
    enExpired,        /* 账号到期 */
    enLoginedByOther  /* 别处登录 */
}KICKOFF_TYPE;

/* 添加好友结果 */
typedef  enum
{
    enAgreed,    /* 对方同意 */
    enWaiting,   /* 等待 */
    enRejected   /* 被对方拒绝 */
}ADD_FRIEND_RSP;



//UC2.0_DEV
#define   UCV2_REFER_ACCEPT         @"202"
#define   UCV2_NOTIFY_200           @"200"
#define   UCV2_CONF_ATTENDEE_SPLIT  @"|1|,"
#define   UCV2_SIP_HEADER                       @"sip:"
#define   UCV2_REPORT_TERMINAL_TIMER_LEN 3 //延迟上报终端类型定时器时长


typedef enum
{
    EN_MEDIA_TYPE_AUDIO = 1,
    EN_MEDIA_TYPE_MULTIMEDIA = 2,
    EN_MEDIA_TYPE_BUTT
}MEDIA_TYPE;

typedef enum
{
    EN_OPT_ADD = 0,
    EN_OPT_MODIFY = 1,
    EN_OPT_REMOVE = 3,
    EN_OPT_BUTT,
}DATA_OPT_TYPE;

/* 预定会议默认提醒时间，单位second */
#define SCHEDULE_CONF_DEFAULT_REMIND_TIMELEN		(600)


// transfer subscriptionState
#define SUBSCRIPTION_STATE_ACTIVE			@"active"
#define SUBSCRIPTION_STATE_PENDING			@"pending"
#define SUBSCRIPTION_STATE_TERMINATED		@"terminated"

typedef enum voip_call_tpye
{
    VOIP_CALL_AUDIO = 0 ,
    VOIP_CALL_VIDEO
}EN_CALL_TYPE;

typedef enum {
    CallMediaTypeAudioOnly = 0,
    CallMediaTypeVideoOnly = 1,
    CallMediaTypeAudioAndVideo = 2
}CallMediaType;

typedef enum answer_call_type
{
    ANSWER_CALL_AUDIO = 1,
    ANSWER_CALL_VIDEO
}ANSWER_CALL_TYPE;

/* 视频方向的枚举定义 */
typedef enum VideoOrientation_ {
    kVideoOrientationLandscape = 0, // 横向视频
    kVideoOrientationPortrait = 1, // 纵向视频
}VideoOrientation;

#define  ADD_CONTACT_BUTTON							@"ADD_CONTACT_BUTTON"
#define  VOICE_CONF_BUTTON							@"VOICE_CONF_BUTTON"
#define  DATA_CONF_BUTTON							@"DATA_CONF_BUTTON"

// 语音会议与会成员号码分隔符
#define AUDIO_CONF_ATTENDEE_NUMBER_SPLIT		@"#"

/* 同步通讯录操作枚举值 */
typedef enum
{
    EN_NOT_DOWNLOAD_CONTACTS = 0,			//不同步通讯录
    EN_PARTITIAL_DOWNLOAD_CONTACTS = 1,		//部分同步通讯录
    EN_FULL_DOWNLOAD_CONTACTS = 2			//完全同步通讯录
}EN_DOWNLOAD_CONTACTS_TYPE;

//会议解析类型
typedef enum
{
    CONF_LIST_PARSE     = 1,	//会议列表解析
    CONF_INFO_PARSE     = 2,	//单个会议信息解析
    
    CONF_SEND_INVITE    = 100, //会议中发送email邀请
    CONF_QUERY_MEMBERS  = 200,  // 查询会议成员消息
    CONF_REDIRECT_PARAMS_PARSE = 300, //重定向参数信息解析
    
    CONF_TYPE_NULL
}PARSE_TYPE;			//解析类型

/*音频路由枚举定义*/
typedef enum
{
    AUDIO_ROUTE_TYPE_HEADPHONES = 0, //听筒（蓝牙、有线、听筒自动切换；优先级：蓝牙>有线>听筒）
    AUDIO_ROUTE_TYPE_REPRODUCER = 1 //扬声器
}AUDIO_ROUTE_TYPE;

/* 删除通话记录操作类型枚举定义 */
typedef enum
{
    ECSCallLogOptType_deleteOne = 0,		// 按条删除
    ECSCallLogOptType_deleteAll = 1,		// 删除所有记录
    ECSCallLogOptType_deleteByUser = 2		// 按用户删除
}ECSCallLogOptType;

/*视频格式*/
typedef enum
{
    VIDEO_SQCIF     = 1,
    VIDEO_QCIF      = 2,
    VIDEO_CIF       = 3,
    VIDEO_4CIF      = 4,
    VIDEO_16CIF     = 5,
    VIDEO_QQVGA     = 6,
    VIDEO_QVGA      = 7,
    VIDEO_VGA       = 8,
    VIDEO_720P      = 9
}VIDEO_SOLUTION;

//ios版本
typedef enum{
    IOS_MAINVERSION_4 = 4,
    IOS_MAINVERSION_5 = 5,
    IOS_MAINVERSION_6 = 6,
    IOS_MAINVERSION_7 = 7,
    IOS_MAINVERSION_8 = 8,
    IOS_MAINVERSION_UNKNOW = 999
} IOS_MAINVERSION;

//后台离线时间
typedef enum{
    BKGOFFLINE_TIME_NEVER       = 0,
    BKGOFFLINE_TIME_TENMINS     = 10,
    BKGOFFLINE_TIME_THIRTYMINS  = 30,
    BKGOFFLINE_TIME_SIXTYMINS   = 60,
    BKGOFFLINE_TIME_FOREVER     = -1
} BKGOFFLINE_TIME;

//省电模式
typedef enum {
    BATTERY_MODE_STANDARD   = 0,    //标准模式，不开启省电状态
    BATTERY_MODE_NORMAL     = 1,    //普通省电模式，屏蔽状态
    BATTERY_MODE_EXTREM     = 2     //极限省电模式，屏蔽voip注册，ios暂未使用
} BATTERY_MODE;

//密码保护模式
typedef enum {
    PSW_PROTECT_NONE        = 0,   //无保护
    PSW_PROTECT_SALT        = 1    //盐值保护
} PSW_PROTECT_TYPE;

#pragma mark -
#pragma mark UM
//UM消息类型
typedef enum UMTYPE_
{
    UMTYPE_UNKONW	= -1, //未知
    UMTYPE_IMAGE	= 0, //图片
    UMTYPE_VIDEO	= 1, //视频
    UMTYPE_AUDIO	= 2, //音频
    UMTYPE_FAX		= 3,//传真
    UMTYPE_FILE		= 4 //文件
}UMTYPE;

//文件格式枚举
typedef enum  FILE_TYPE_{
    FILE_TYPE_JPEG = 1,
    FILE_TYPE_PNG = 2,
    FILE_TYPE_MP4 = 3,
    FILE_TYPE_WAV = 4,
    FILE_TYPE_AMR = 5,
    FILE_TYPE_UNKNOW = 100
}FILE_TYPE;

#pragma mark -
#pragma mark ATS业务
/*主被叫控类型枚举*/
typedef enum
{
    ECSCallControllType_NoControl	  = 0,  //无控制
    ECSCallControllType_CallerControl = 1,  //主叫控
    ECSCallControllType_CalledControl = 2,  //被叫控
    ECSCallControllType_UserSuspend	  = 3,  //用户暂停
    ECSCallControllType_UserResume	  = 4	//用户恢复
}ECSCallControllType;

typedef enum
{
    ECSCallVideoOperationType_NoControl = 0, //对视频无操作
    ECSCallVideoOperationType_Update = 1, //升级视频
    ECSCallVideoOperationType_Remove = 2, //移除视频
}ECSCallVideoOperationType;

/*incoming call info key*/
#define CALL_FROMNUMBER		@"CALL_FROMNUMBER"	//value:来电from头域uri解析的号码，NSString*
#define CALL_FROMNAME		@"CALL_FROMNAME"	//value:来电from头域uri解析的姓名，NSString*
#define CALL_PAINUMBER		@"CALL_PAINUMBER"	//value:来电pai头域uri号码，NSString*
#define CALL_PAITELNUMBER	@"CALL_PAITELNUMBER" //value:来电pai头域tel-uri号码，NSString* (tel:1395464;phone-context=+9663)
#define CALL_PAITELCONTEXT	@"CALL_PAITELCONTEXT" //value:来电pai头域tel-uri中phone-context=后的内容，NSString* (tel:1395464;phone-context=+9663)
#define CALL_LOCAL_ADDR     @"CALL_LOCAL_ADDR"  //value:本地IP
#define CALL_REMOTE_ADDR    @"CALL_REMOTE_ADDR" //value:远端IP
#define CALL_TONUMBER       @"CALL_TONUMBER"  //value:来电to头域uri解析的号码，NSString*

#define CALL_PAINAME		@"CALL_PAINAME"		//value:来电pai头域uri解析的姓名，NSString*
#define CALL_SDPINFO		@"CALL_SDPINFO"		//value:来电sdp信息，NSNumber of bool
#define CALL_CONTROLTYPE	@"CALL_CONTROLTYPE"	//value:来电呼叫控制，NSNumber of ECSCallControllType
#define CALL_HISTORYINFO	@"CALL_HISTORYINFO" //value:来电转接历史uri，NSMutableArray with NSString

/*answer call info key*/
#define CALL_ANSWER_SENDMODE   @"CALL_ANSWER_SENDMODE" //value:应答的媒体方向，NSNumber of int
#define CALL_ANSWER_AUDIOONLY  @"CALL_ANSWER_AUDIOONLY" //value:应答的媒体类型，NSNumber of bool

#define SESSION_MODIFY_CALLID @"SESSION_MODIFY_CALLID"  //修改会话操作时的callID

// 2012.12.14 k00228462 语音留言
#define VOICE_MAIL_MAILBOXNUM_KEY @"VOICE_MAIL_MAILBOXNUM_KEY"	//value:用户的语音邮箱号码
#define VOICE_MAIL_SHORTCODE_KEY @"VOICE_MAIL_SHORTCODE_KEY"	//value:该条留言的UMS请求短号


//语音转会议
#define VOICE_CONFERENCE_ID_KEY				@"conferenceID"		//会议ID
#define VOICE_CONFERENCE_MEDIATYPE_KEY			@"conferenceType"	//会议type
#define VOICE_CALL_ID_SDK_KEY               @"callID"

//心跳正常通知
#define ECS_HEART_BEAT_RESPOND_SUCCESS @"ECS_HEART_BEAT_RESPOND_SUCCESS"

typedef enum
{
    VoiceMailPlayRewind		= 1,
    VoiceMailPlayPause		= 2,
    VoiceMailPlayForward	= 3,
}VoiceMailPlayControlMode;

// 2012.12.14 k00228462 语音留言 end

/*transfer key*/
#define TRANSFER_TARGET_KEY @"TRANSFER_TARGET_KEY" //value:转接目标号码，NSString*
#define TRANSFER_TYPE_KEY   @"TRANSFER_TYPE_KEY"   //value:转接类型，NSNumber of EN_TRANSFER_TYPE

/* 媒体流方向枚举定义 */
typedef enum
{
    AudioSendMode_SendRecv = 0,		// 指定媒体流可以接收和发送
    AudioSendMode_SendOnly = 1,		// 指定媒体流只发送
    AudioSendMode_RecvOnly = 2,		// 指定媒体流只接收
    AudioSendMode_Inactive = 3,		// 指定媒体流不可以接收和发送
}CallServiceAudioSendMode;

/* 其他客户端登录的客户端类型 */
typedef enum
{
    OtherLoginTypeUnknown = -1, // 类型未知或客户端没有登录
    OtherLoginTypePC,			// 客户端已经登录且类型为PC
    OtherLoginTypeMobile,		// 客户端已经登录且类型为手机
    OtherLoginTypePad,			// 客户端已经登录且类型为Pad
    OtherLoginTypeIPPhone		// 客户端已经登录且类型为IP话机
}OtherLoginType;

/* 即时消息或固定群消息的状态枚举 */
typedef enum
{
    ChatMsgStatusRead = 0,	// 消息已读
    ChatMsgStatusUnread = 1 // 消息未读
}ChatMsgStatusType;


/* 录音的类型 */
typedef enum
{
    AudioRecordTypeLocalWhileNotCalling = 0,	// 非通话状态下，录制本地声音。
    AudioRecordTypeLocalWhileCalling = 1,		// 通话状态下，录制本地的声音。
    AudioRecordTypeRemoteWhileCalling = 2,		// 通话状态下，录制远端的声音。
    AudioRecordTypeBothWhileCalling = 3,		// 通话状态下，录制双向的声音。
}AudioRecordType;

#define SERVICE_NAME_FOR_LPOE @"LPOE" // 表示产权局定制版本

/* 核心网部署模式 */
typedef enum
{
    CoreNetDeployModel_Unknown = 0,
    CoreNetDeployModel_UAP = 1,
    CoreNetDeployModel_ATS = 2,
}CoreNetDeployModel;

/*设备型号枚举*/
typedef enum
{
    UIDeviceMode_Iphone3G = 1,
    UIDeviceMode_Iphone3GS = 2,
    UIDeviceMode_Iphone4 = 3,
    UIDeviceMode_Iphone4S = 4,
    UIDeviceMode_Iphone5 = 5,
    UIDeviceMode_Iphone5C = 6,
    UIDeviceMode_Iphone5S = 7,
    UIDeviceMode_Ipad2 = 8,
    UIDeviceMode_Ipad3 = 9,
    UIDeviceMode_IpadMini = 10,
    UIDeviceMode_Ipad4 = 11,
    UIDeviceMode_Ipad5 = 12,
    UIDeviceMode_IpadMini2 = 13,
    UIDeviceMode_Iphone6 = 14,
    UIDeviceMode_Iphone6_Plus = 15,
    UIDeviceMode_Ipad6 = 16,
    UIDeviceMode_IpadMini3 = 17,
    UIDeviceMode_Unknown = 100,
}UIDeviceMode;

//DND SIP Action
typedef enum {
    DND_ACTION_TYPE_NONE = 0,
    DND_ACTION_TYPE_SET = 1,
    DND_ACTION_TYPE_RESET = 2,
}DND_ACTION_TYPE;

/*
 0 - 拒接模式（ATS会自动将呼叫前转到语音邮箱）
 1 - 静音模式（ATS会放行呼叫到终端，终端自己静音）
 */
typedef enum  {
    DND_MODE_NEED_DND_ACTION = 0,
    DND_MODE_NO_NEED_DND_ACTION = 1,
}DND_MODE;
