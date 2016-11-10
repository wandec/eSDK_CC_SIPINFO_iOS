
/** 
* @file call_def.h
* 
* Copyright(C), 2012-2015, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
* 
* ������TUP ������ϵͳ����ҵ����ͷ�ļ��� \n
*/


/**
*
*  @{
*/


#ifndef __CALL_DEF_H__
#define __CALL_DEF_H__


#include "tup_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /*  __cpluscplus */
#endif /*  __cpluscplus */

#define TUP_CALL_VERSION   "TUP V100R001C50B022"


#define CALL_D_ACCESSCODE_MAX_LENGTH    (32)   /**< �������ַ�����󳤶�*/
#define CALL_D_IP_LENGTH                (16)   /**< IP��ַ�ַ�����󳤶� */
#define CALL_D_PROTOCOL_LENGTH          (30)   /**< Э�������ַ�����󳤶� */
#define CALL_D_HMEVERSION_LENGTH        (128)  /**< HME�汾�ַ�����󳤶�*/ 
#define CALL_D_MAX_AUDIO_CODEC_LEN      (64)   /**< ��Ƶ�����������󳤶�*/
#define CALL_D_MAX_CODEC_LIST_LEN       (127)  /**< ��Ƶ�������������󳤶ȣ��Զ��ŷָ�*/
#define CALL_D_MAX_DEVICE_NUM           (10)   /**< ����/����豸���֧����Ŀ*/

#define CALL_MAX_CODEC_NAME_LEN         (31)   /**< ����Ƶ��������Ƴ��� */
#define CALL_MAX_FRAMESIZE_LEN          (16)   /**< ��Ƶ�ֱ��ʳ��� */    
#define CALL_MAX_PROFILE_LEN            (8)    /**< ��Ƶ������ʽ����*/

#define CALL_D_MAX_LENGTH_NUM           (256)  /**< ͨ���ַ�����󳤶�*/
#define CALL_D_MAX_DISPLAY_NAME         (256)  /**< ��ʾ����󳤶�*/
#define CALL_D_MAX_USERNAME_LENGTH      (256)  /**< �û�����󳤶�*/
#define CALL_D_MAX_PASSWORD_LENGTH      (256)  /**< ������󳤶�*/
#define CALL_D_MAX_URL_LENGTH           (256)  /**< ͨ��URL��󳤶�*/
#define CALL_D_MAX_SERVER_LENGTH        (256)  /**< ��������󳤶�*/
#define CALL_D_MAX_TOKEN_LENGTH         (256)  /**< TOKEN��󳤶�*/
#define CALL_D_MAX_PASSCODE_LENGTH      (256)  /**< ��������󳤶�*/



#define CALL_D_MAX_HTTP_URL_LENGTH      (512)  /**< HTTP URL��󳤶�*/

#define CALL_D_MAXDEVICENUM             (8)    /**< ����Ƶ�豸������� */

#define CALL_D_MAX_PRESET_MSG_LENGTH    (100)  /**< Ԥ����Ϣ�ַ�����󳤶� */

#define CALL_D_MAX_MSGSUMMARY_NUM       (10)   /**< UM��Ϣ������ */

#define CALL_D_MAX_ACCOUNT_NUM          (24)   /**< �û��˺������ */
#define CALL_D_MAX_CALL_NUM             (24)   /**< �����������·�� */
#define CALL_D_MAX_LINE_NUM             (24)   /**< ���ú�����·���·�� */
#define CALL_D_MAX_LINE_KEY_NUM         (24)   /**< ������·������� */

#define CALL_D_MAX_ACB_NUM              (5)    /**< �غ������� */

#define CALL_D_MAX_FOWARD_NUM           (24)   /**< ǰת���ƿ鴦��������*/

#define CALL_D_MAX_INTERCOM_GROUPNUM    (CALL_D_MAX_ACCOUNT_NUM-1)     /**< intercom��·�����,��������˺�����һ· */

#define CALL_D_PASSCODE_LENGTH          (50)   /**< ���鴴������н�������󳤶� */
#define CALL_D_DATACONF_PARAM_LENGTH    (32)   /**< ���ݻ��������������ֵ */
#define CALL_D_DATACONF_CMADDR_LENGTH   (64)   /**< ���ݻ������cm_address����ֵ */
#define CALL_D_CONF_CODE_LENGTH         (33)   /**< �����������󳤶� */
#define CALL_D_CONF_LINK_NUM_LENGTH     (32)   /**< �����б��г�Ա����������󳤶� */
#define CALL_D_CONF_TYPE_MAX_LEN        (21)   /**< ����������󳤶� */

#define CALL_D_TLSVERSION_V1_0          0x00000001L  /**< TLS v1.0 */
#define CALL_D_TLSVERSION_V1_1          0x00000002L  /**< TLS v1.1 */
#define CALL_D_TLSVERSION_V1_2          0x00000004L  /**< TLS v1.2 */


/**dialog info*/
#define CALL_D_MAX_INFO_BODY_LEN (512)          /**< ���ͶԻ���INFO text��󳤶�*/
#define CALL_D_MAX_CONTENT_TYPE_LEN (64)        /**< ���ͶԻ���INFO ����*/



/** 
 * ����ģ��ID 
 */
typedef enum tagCALL_E_MOD_ID
{
    CALL_E_MOD_ID_TSP = 0,         /**< ���п�������Ϣ����ģ�� */
    CALL_E_MOD_ID_STACK,          /**< SIPЭ��ջ��Ϣ����ģ�� */

    CALL_E_MOD_ID_SIP = 4096,      /**< SIPC��Ϣ����ģ�� */
    CALL_E_MOD_ID_HLLM,            /**< HLLM����DNS��ѯ��Ϣ����ģ�� */
    CALL_E_MOD_ID_VCOM,            /**< VCOM��Ϣ����ģ�� */
    CALL_E_MOD_ID_TPTD,            /**< TPTD��Ϣ����ģ�� */

    CALL_E_MOD_ID_BUTT
} CALL_E_MOD_ID;


/** 
 * ID���� 
 */
typedef enum tagCALL_E_ID_TYPE
{
    CALL_E_IDTYPE_CALL_ID,  /**< ���� */
    CALL_E_IDTYPE_CONF_ID   /**< ���� */
}CALL_E_ID_TYPE;


/** 
 * ��־����
 */
enum CALL_E_LOG_LEVEL
{
    CALL_E_LOG_ERROR = 0,    
    CALL_E_LOG_WARNING,     
    CALL_E_LOG_INFO,         
    CALL_E_LOG_DEBUG         
};


/** 
 *ϵͳ�����붨��
 */
typedef enum tagCALL_E_ERR_ID
{
    CALL_E_ERR_BEGIN = 0x08002100UL,
    CALL_E_ERR_GENERAL_ERROR,                     /**<1  һ����� */
    CALL_E_ERR_PARAM_ERROR,                       /**<2  �������� */
    CALL_E_ERR_MEM_ERROR,                         /**<3  �����ڴ���� */
    CALL_E_ERR_SYSTEM_ERROR,                      /**<4  ϵͳ���� */
    CALL_E_ERR_MSG_ERROR,                         /**<5  ������Ϣ���� */
    CALL_E_ERR_CFG_ERROR,                         /**<6  ��ȡϵͳ���ô��� */
    CALL_E_ERR_NET_ERROR,                         /**<7  ����������� */
    CALL_E_ERR_ACCESS_ERROR,                      /**<8  �������ʧ�ܴ��� */
    CALL_E_ERR_TIMER_ERROR,                       /**<9  ������ʱ������ */
    CALL_E_ERR_STATE_ERROR,                       /**<10 ����״̬����ȷ */
    
    CALL_E_ERR_OPERATE_ERROR,                     /**<11 ���ڽ��������������� */
    CALL_E_ERR_REQSRV_ERROR,                      /**<12 �������ؽ��к��п�ʼ���� */
    CALL_E_ERR_REQRES_ERROR,                      /**<13 ������Ƶ��Դ���� */
    CALL_E_ERR_SERVICE_DOING,                     /**<14 ���ڽ�����������ҵ�� */
    CALL_E_ERR_CALLRECORD_ERROR,                  /**<15 ��¼ͨ����¼���� */
    CALL_E_ERR_MPROC_ERROR,                       /**<16 ý����̷��صĴ��� */
    CALL_E_ERR_MAX_CALL_ERROR,                    /**<17 ����������·�� */
    CALL_E_ERR_SIPID_NOTEXIT_ERROR,               /**<18 SIP�˻�ID������ */
    CALL_E_ERR_CALLID_NOEXIT_ERROR,               /**<19 ����ID������ */
    CALL_E_ERR_REGISTERING_ERROR,                 /**<20 ����ע����ʧ��*/
    
    CALL_E_ERR_REGIST_FALL_ERROR,                 /**<21 ����sip�ӿ�ע��ʧ�� */
    CALL_E_ERR_DEREGIST_FALL_ERROR,               /**<22 ����sip�ӿ�ע��ʧ�� */
    CALL_E_ERR_SET_SIP_INFO_ERROR,                /**<23 �����˻���Ϣ���� */
    CALL_E_ERR_SETACCOUNT_ERROR,                  /**<24 ����SIPģ��ʧ��*/
    CALL_E_ERR_NOTIFYSIPACCOUNT_ERROR,            /**<25 �ϱ�ʧ��  */
    CALL_E_ERR_SIPSEVER_ERROR,                    /**<26 ��������Ϣ����*/
    CALL_E_ERR_SIPACCOUNTINFO_ERROR,              /**<27 �˻���Ϣ����*/
    CALL_E_ERR_SIPC_ERROR,                        /**<28 SIPCִ�д���*/
    CALL_E_ERR_UNREGISTER_ERROR,                  /**<29 δע�����*/
    CALL_E_ERR_SUB_FALL_ERROR,                    /**<30 ����Sip�ӿڶ���ʧ�� */
    
    CALL_E_ERR_DESUBING_ERROR,                    /**<31 ע�������д��� */
    CALL_E_ERR_SUBING_ERROR,                      /**<32 �����д��� */
    CALL_E_ERR_LOCAL_MAX_CONFER_ERROR,            /**<33 ���ػ����Ѵ�����ֻ����һ���᳡*/
    CALL_E_ERR_LOCAL_CONFER_NOEXIT_ERROR,         /**<34 ���ػ���δ���� */
    CALL_E_ERR_LOCAL_CONFER_NOMATCH_ERROR,        /**<35 �������·����ϯ�˻���ƥ��*/
    CALL_E_ERR_CONF_STATE_ERROR,                  /**<36 ���ػ���״̬����*/
    CALL_E_ERR_JOINTSTATENOTIFY_ERROR,            /**<37 IP Phone������״̬�ϱ�ʧ��*/
    CALL_E_ERR_CONFID_NOTEXIST_ERROR,             /**<38 ����ID������ */
    CALL_E_ERR_CONF_VIDEO_HOLD_ERROR,             /**<39 ��Ƶ����ʧ�� */
    CALL_E_ERR_CONF_VIDEO_UNHOLD_ERROR,           /**<40 ��Ƶ�ָ�ʧ�� */
    
    CALL_E_ERR_MAX_SERVER_CONF_ERROR,             /**<41 ����������������� */
    CALL_E_ERR_AA_REQRANDOMNUM_ERROR,             /**<42 AA��ȡ�����ʧ�� */
    CALL_E_ERR_AA_LOGIN_ERROR,                    /**<43 AA��½ʧ�� */
    CALL_E_ERR_CONF_VIDEO_TYPE_NO_MATCH,          /**<44 �������Ͳ�ƥ��*/
    CALL_E_ERR_CONF_VIDEO_START_ERROR,            /**<45 ��Ƶ���鿪��ʧ��*/
    CALL_E_ERR_AA_NOMAINSERVER_ERROR,             /**<46 AA���������� */
    CALL_E_ERR_AA_PASSWORD_ERROR,                 /**<47 ������� */
    CALL_E_ERR_AA_USERNAME_ERROR,                 /**<48 �û������� */
    CALL_E_ERR_AA_USERLOGINED_ERROR,              /**<49 �û��ѵ�¼ */
    CALL_E_ERR_AA_ACCOUNTLOCKED_ERROR,            /**<50 �˻������� */
    
    CALL_E_ERR_AA_TERMINALTYPE_ERROR,             /**<51 �ն����Ͳ�ƥ�� */
    CALL_E_ERR_AA_PARSEXML_ERROR,                 /**<52 ����XML���� */
    CALL_E_ERR_AA_CONNECT_ERROR,                  /**<53 ���ӷ��������� */
    CALL_E_ERR_MEDIA_CFG_ERROR,                   /**<54 ��ȡý������ʧ�� */
    CALL_E_ERR_AA_GETSRINFO_ERROR,                /**<55 ��ȡҵ��Ȩ��ʧ�� */
    CALL_E_ERR_AA_LACKSR_ERROR,                   /**<56 ҵ��Ȩ�޲���ʧ�� */
    CALL_E_ERR_NETWORKENV_ERROR,                  /**<57 ���绷������ */
    CALL_E_ERR_SERVICE_CONFLICT_ERROR,            /**<58 ҵ���ͻ*/
    CALL_E_ERR_AA_TIMEOUT_ERROR,                  /**<59 ���ӳ�ʱ */
    CALL_E_ERR_AA_UNKOWN_ERROR,                   /**<60 δ֪����*/
    
    CALL_E_ERR_PICKUP_ADDTIP_ERROR,               /**<61 ���������Ϣʧ�� */
    CALL_E_ERR_PICKUP_REMOVETIP_ERROR,            /**<62 ɾ����������Ϣʧ�� */
    CALL_E_ERR_PICKUP_CREATERINGNUM_ERROR,        /**<63 �����������ʧ�� */
    CALL_E_ERR_VVM_PARAM_ERR,                     /**<64 VVM�������� */
    CALL_E_ERR_GET_IPT_INFO_ERR,                  /**<65 ��ȡ�Ǽ�ҵ����� */
    CALL_E_ERR_VVM_GETVOICEMAIL_ERR,              /**<66 ��ȡ�������� */
    CALL_E_ERR_ATTENDEE_ALREADY_EXIST,            /**<67 ������Ѿ����� */
    CALL_E_ERR_ATTENDEE_NOT_EXIST,                /**<68 ����߲����� */
    CALL_E_ERR_CREATE_CONF_WND_ERROR,             /**<69 ������������Ƶ���鴰��ʧ��*/
    CALL_E_ERR_CREATE_CONF_WND_EXIST,             /**<70 ��Ƶ���ڲ�����*/
    
    CALL_E_ERR_GET_CONF_LIST_INFO_ERROR,          /**<71 ��ȡ�����б�ʧ��*/
    CALL_E_ERR_NEED_CHAIRMAN_TO_OPERATE,          /**<72 ��Ҫ������Ȩ�޲��ܲ���*/
    CALL_E_ERR_NO_VIDEO_DEVICE_TO_OPERATE,        /**<73 û����Ƶ�豸���Բ���*/
	CALL_E_ERR_NOT_STOP_REFRESHREG,               /**<74 û�йر�ˢ��ע��*/
    CALL_E_ERR_NOTIFY_ONLINE_STATE_ERROR,         /**<75 ����״̬notify�ϱ�ʧ��*/
    CALL_E_ERR_NOTIFY_NETADDR_ERROR,              /**<76 �����ַ������notify�ϱ�ʧ��*/
    CALL_E_ERR_INFO_FORCEUNREG_ERROR,             /**<77 �����˺ű���info�ϱ�ʧ��*/
    CALL_E_ERR_TLSROOTCERT_ERROR,                 /**<78 TLS��֤�����*/
    
    CALL_E_ERR_BUTT,
    CALL_E_ERR_NUM = (CALL_E_ERR_BUTT & 0x00001FFF)
} CALL_E_ERR_ID;

/**
 *����ʧ�ܵ�ԭ����
 */
typedef enum tagCALL_E_REASON_CODE
{
    CALL_E_REASON_CODE_OK = 0,

    CALL_E_REASON_CODE_BADREQUEST = 400,                    /**< 400 bad request �������� */
    CALL_E_REASON_CODE_PAYMENTREQUIRED = 402,               /**< 402 payment required ����Ҫ�� */
    CALL_E_REASON_CODE_FORBIDDEN = 403,						/**< 403 forbidden ��ֹ */
    CALL_E_REASON_CODE_NOTFOUND = 404,						/**< 404 not found δ���� */
    CALL_E_REASON_CODE_METHODNOTALLOWED = 405,				/**< 405 method no allowed ���������� */
    CALL_E_REASON_CODE_RESNOTACCEPTABLE = 406,				/**< 406 not acceptable ���ɽ��� */
    CALL_E_REASON_CODE_REQUESTTIMEOUT = 408,				/**< 408 request timeout ����ʱ */
    CALL_E_REASON_CODE_GONE = 410,							/**< 410 gone �뿪 */
    CALL_E_REASON_CODE_REQUESTENTITYTOOLARGE = 413,			/**< 413 request entity too large ����ʵ��̫�� */
    CALL_E_REASON_CODE_REQUESTURITOOLONG = 414,				/**< 414 request-url too long ����URL̫�� */
    CALL_E_REASON_CODE_UPSUPPORTEDMEDIATYPE = 415,			/**< 415 unsupported media type ��֧�ֵ�ý������ */
    CALL_E_REASON_CODE_UPSUPPORTEDURISCHEME = 416,			/**< 416 unsupported url scheme ��֧�ֵ�URL�ƻ� */
    CALL_E_REASON_CODE_BADEXTENSION = 420,					/**< 420 bad extension ������չ */
    CALL_E_REASON_CODE_EXTENSIONREQUIRED = 421,				/**< 421 extension required ��Ҫ��չ  */
    CALL_E_REASON_CODE_TEMPORARILYUNAVAILABLE = 480,		/**< 480 temporarily unavailable ��ʱʧЧ */
    CALL_E_REASON_CODE_CALLTRANSACTIONDOESNOTEXIST = 481,	/**< 481 call/transaction does not exist ����/���񲻴��� */
    CALL_E_REASON_CODE_LOOPDETECTED = 482,					/**< 482 loop detected ���ֻ�· */
    CALL_E_REASON_CODE_TOOMANYHOPS = 483,					/**< 483 too many hops ����̫�� */
    CALL_E_REASON_CODE_ADDRESSINCOMPLETE = 484,				/**< 484 address incomplete ��ַ������ */
    CALL_E_REASON_CODE_AMBIGUOUS = 485,						/**< 485 ambiguous ������ */
    CALL_E_REASON_CODE_BUSYHERE = 486,						/**< 486 busy here ����æ */
    CALL_E_REASON_CODE_REQUESTTEMINATED = 487,				/**< 487 request terminated ������ֹ */
    CALL_E_REASON_CODE_NOTACCEPTABLEHERE = 488,				/**< 488 not acceptable here �������󲻿ɽ��� */
    CALL_E_REASON_CODE_REQUESTPENDING = 491,				/**< 491 request pending δ������ */
    CALL_E_REASON_CODE_UNDECIPHERABLE = 493,				/**< 493 undecipherable ���ɱ�ʶ */

    CALL_E_REASON_CODE_SERVERINTERNALERROR = 500,			/**< 500 server internal error �������ڲ����� */
    CALL_E_REASON_CODE_NOTIMPLEMENTED = 501,				/**< 501 not implemented ����ִ�� */
    CALL_E_REASON_CODE_BADGATEWAY = 502,					/**< 502 bad gateway ������ */
    CALL_E_REASON_CODE_SERVICEUNAVAILABLE = 503,			/**< 503 service unavailable ������Ч */
    CALL_E_REASON_CODE_SERVERTIMEOUT = 504,					/**< 504 server time-out ��������ʱ */
    CALL_E_REASON_CODE_VERSIONNOTSUPPORTED = 505,			/**< 505 version not supported �汾��֧�� */
    CALL_E_REASON_CODE_MESSAGETOOLARGE = 513,				/**< 513 message too large ��Ϣ̫�� */

    CALL_E_REASON_CODE_BUSYEVERYWHERE = 600,				/**< 600 busy everywhere ȫæ */
    CALL_E_REASON_CODE_DECLINE = 603,						/**< 603 decline ���� */
    CALL_E_REASON_CODE_DOESNOTEXISTEVERYWHERE = 604,		/**< 604 does not exist anywhere ������ */
    CALL_E_REASON_CODE_NOTACCEPTABLE = 606,					/**< 606 not acceptable ���ɽ��� */

    CALL_E_REASON_CODE_TLS_CERTIFICATE_INVALIDE = 801, 		/**< 801 ֤����� */
    CALL_E_REASON_CODE_TLS_RECV_CERTIFICATE_FAIL = 802,		/**< 802 ����֤��ʧ�� */
    CALL_E_REASON_CODE_END
} CALL_E_REASON_CODE;



/**
 * ������ҵ������
 */
typedef enum tagCALL_E_SERVICE_CALL_TYPE
{
    CALL_E_SERVICE_CALL_NORMAL,


    CALL_E_SERVICE_CALL_TYPE_REG_DND,                   /**< �Ǽ�DND */
    CALL_E_SERVICE_CALL_TYPE_UNREG_DND,                 /**< ȡ���Ǽ�DND */

    
    CALL_E_SERVICE_CALL_TYPE_CALL_WAIT_ACTIVE,          /**< ���еȴ����� */
    CALL_E_SERVICE_CALL_TYPE_CALL_WAIT_DEACTIVE,        /**< ���еȴ��ر� */

    CALL_E_SERVICE_CALL_TYPE_REG_SCAPRIVATE,            /**< �Ǽ�˽�˺��� */
    CALL_E_SERVICE_CALL_TYPE_UNREG_SCAPRIVATE,          /**< ȡ���Ǽ�˽�˺��� */


    CALL_E_SERVICE_CALL_TYPE_REG_ALERT_SILENCE,         /**< �Ǽǹ��������羲�� */
    CALL_E_SERVICE_CALL_TYPE_UNREG_ALERT_SILENCE,       /**< ȡ�����������羲�� */
    CALL_E_SERVICE_CALL_TYPE_REG_PRIVACY,               /**< �Ǽ�˽�˺���ҵ��*/
    CALL_E_SERVICE_CALL_TYPE_UNREG_PRIVACY,             /**< ȡ��˽�˺���ҵ��*/

    CALL_E_SERVICE_CALL_TYPE_SET_CALLPARK,              /**< ���ú���פ�� */
    CALL_E_SERVICE_CALL_TYPE_DIRECTCALLPARK,            /**< ֱ�Ӻ���פ�� */
    CALL_E_SERVICE_CALL_TYPE_GET_CALLPARK,              /**< ȡ�غ���פ�� */

    CALL_E_SERVICE_CALL_TYPE_FORWARD_UNCONDITION,       /**< ����������ǰת*/
    CALL_E_SERVICE_CALL_TYPE_FORWARD_ONBUSY,            /**< ������æǰת*/
    CALL_E_SERVICE_CALL_TYPE_FORWARD_NOREPLY,           /**< ������Ӧ��ǰת*/

    CALL_E_SERVICE_CALL_TYPE_CFUVoiceMail_Active,       /**< ������ת��������Ǽ�(����) */
    CALL_E_SERVICE_CALL_TYPE_CFUVoiceMail_Deactive,     /**< ������ת��������ע��*/
    CALL_E_SERVICE_CALL_TYPE_CFBVoiceMail_Active,       /**< ��æ ת��������Ǽ�(����) */
    CALL_E_SERVICE_CALL_TYPE_CFBVoiceMail_Deactive,     /**< ��æ ת��������ע��*/
    CALL_E_SERVICE_CALL_TYPE_CFNVoiceMail_Active,       /**< ��Ӧ�� ת��������Ǽ�(����) */
    CALL_E_SERVICE_CALL_TYPE_CFNVoiceMail_Deactive,     /**< ��Ӧ�� ת��������ע��*/
    CALL_E_SERVICE_CALL_TYPE_CFOVoiceMail_Active,       /**< ���� ת��������Ǽ�(����) */
    CALL_E_SERVICE_CALL_TYPE_CFOVoiceMail_Deactive,     /**< ���� ת��������ע��*/

    CALL_E_SERVICE_CALL_TYPE_FORWARD_UNCONDITION_Active,/**< ������������ǰת�Ǽ�(����) */
    CALL_E_SERVICE_CALL_TYPE_FORWARD_UNCONDITION_Deactive, /**< ������������ǰתע��*/
    CALL_E_SERVICE_CALL_TYPE_FORWARD_ONBUSY_Active,     /**< ��������æǰת�Ǽ�(����) */
    CALL_E_SERVICE_CALL_TYPE_FORWARD_ONBUSY_Deactive,   /**< ��������æǰתע��*/
    CALL_E_SERVICE_CALL_TYPE_FORWARD_NOREPLY_Active,    /**< ��������Ӧ��ǰת�Ǽ�(����) */
    CALL_E_SERVICE_CALL_TYPE_FORWARD_NOREPLY_Deactive,  /**< ��������Ӧ��ǰתע��*/
    CALL_E_SERVICE_CALL_TYPE_FORWARD_OFFLINE_Active,    /**< ����������ǰת�Ǽ�(����) */
    CALL_E_SERVICE_CALL_TYPE_FORWARD_OFFLINE_Deactive,  /**< ����������ǰתע��*/

    CALL_E_SERVICE_CALL_TYPE_SCAPRIVATE_ACTIVE,         /**< ������·˽�˺��еǼ�*/
    CALL_E_SERVICE_CALL_TYPE_SCAPRIVATE_DEACTIVE,       /**< ������·˽�˺���ע��*/

    CALL_E_SERVICE_CALL_TYPE_ACBCALL_ACTIVE,            /**< ���лغ��Ǽ�(����) */
    CALL_E_SERVICE_CALL_TYPE_ACBCALL_DEACTIVE,          /**< ���лغ�ע�� */

    CALL_E_SERVICE_CALL_TYPE_GOURPPICKUP,               /**< Ⱥ�����*/
    CALL_E_SERVICE_CALL_TYPE_DESPICKUP,                 /**< ָ������*/

    CALL_E_SERVICE_CALL_TYPE_DIVERT,                    /**< ƫת*/

    CALL_E_SERVICE_CALL_TYPE_REG_DICF,                  /**< �ܾ�ǰת����Ǽ� */
    CALL_E_SERVICE_CALL_TYPE_UNREG_DICF,                /**< �ܾ�ǰת����ע�� */

    CALL_E_SERVICE_CALL_TYPE_ABSENT_ON,                 /**< ����absence */
    CALL_E_SERVICE_CALL_TYPE_ABSENT_OFF,                /**< �ر�absence */

    CALL_E_SERVICE_CALL_TYPE_MCID,                      /**< ������и��� */

    CALL_E_SERVICE_CALL_TYPE_CALL_LIMIT_ACTIVE,         /**< ���������޺� */
    CALL_E_SERVICE_CALL_TYPE_CALL_LIMIT_DEACTIVE,       /**< �ر������޺� */

    CALL_E_SERVICE_CALL_TYPE_ATTENDCONF_BY_ONEKEY,      /**< һ�����**/
    CALL_E_SERVICE_CALL_TYPE_HUNTGROUP_SIGNIN,          /**< huntgroupǩ�� */
    CALL_E_SERVICE_CALL_TYPE_HUNTGROUP_SIGNOUT,         /**< huntgroupǩ�� */
    CALL_E_SERVICE_CALL_TYPE_GET_VIRTUALVM,             /**< ��ȡ������������ */

    CALL_E_SERVICE_CALL_TYPE_BUIT

} CALL_E_SERVICE_CALL_TYPE;



/**
 * DTMF��ֵ
 */
typedef enum tagCALL_E_DTMF_TONE
{
    CALL_E_DTMF0,       /**< dtmf����0 */
    CALL_E_DTMF1,       /**< dtmf����1 */
    CALL_E_DTMF2,       /**< dtmf����2 */
    CALL_E_DTMF3,       /**< dtmf����3 */
    CALL_E_DTMF4,       /**< dtmf����4 */
    CALL_E_DTMF5,       /**< dtmf����5 */
    CALL_E_DTMF6,       /**< dtmf����6 */
    CALL_E_DTMF7,       /**< dtmf����7 */
    CALL_E_DTMF8,       /**< dtmf����8 */
    CALL_E_DTMF9,       /**< dtmf����9 */
    CALL_E_DTMFSTAR,    /**< dtmf����'*' */
    CALL_E_DTMFJIN,     /**< dtmf����'#' */
    CALL_E_DTMFA,       /**< dtmf����A */
    CALL_E_DTMFB,       /**< dtmf����B */
    CALL_E_DTMFC,       /**< dtmf����C */
    CALL_E_DTMFD,       /**< dtmf����D */
    CALL_E_DTMFFLASH,   /**< dtmf����FLASH */
    CALL_E_BUTT
} CALL_E_DTMF_TONE;




/**
 *�ϱ���������¼�
 */
typedef enum tagCALL_E_CALL_EVENT
{
    CALL_E_EVT_BEGIN = 0,

    CALL_E_EVT_SIPACCOUNT_INFO,             /**< ֪ͨ�ϲ�Ӧ�ã�SIP�˻���Ϣ�ı�
                                                <br>param1���� 
                                                <br>param2����  
                                                <br>data��  CALL_S_SIP_ACCOUNT_INFO* */    
    CALL_E_EVT_CALL_STARTCALL_RESULT,       /**< ���������Ӧ���첽
                                                <br>param1��ulCallID 
                                                <br>param2��ulResult  �������н��
                                                <br>data���� */
    CALL_E_EVT_CALL_INCOMMING,              /**< �����¼�
                                                <br>param1��ulCallID 
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO* */   
    CALL_E_EVT_CALL_OUTGOING,               /**< �����¼�
                                                <br>param1��ulCallID 
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO* */   
    CALL_E_EVT_CALL_RINGBACK,               /**< �������¼� 
                                                <br>param1��ulCallID 
                                                <br>param2���� 
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_CONNECTED,              /**< ͨ���ѽ���
                                                <br>param1��ulCallID 
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_ENDED,                  /**< ���н���
                                                <br>param1��ulCallID 
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */  
    CALL_E_EVT_CALL_DESTROY,                /**< ɾ������ID
                                                <br>param1��ulCallID 
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */  
    CALL_E_EVT_CALL_RTP_CREATED,            /**< RTPͨ���ѽ��������Խ��ж��β���
                                                <br>param1��ulCallID 
                                                <br>param2����
                                                <br>data��  �� */   
    CALL_E_EVT_CALL_ADD_VIDEO,              /**< ͨ��������Ƶ
                                                <br>param1��ulCallID 
                                                <br>param2��ulOrientType ���������ƶ���ʹ�ã�
                                                <br>data��  ��  */  
    CALL_E_EVT_CALL_DEL_VIDEO,              /**< ͨ��ɾ����Ƶ
                                                <br>param1��ulCallID 
                                                <br>param2����
                                                <br>data��  �� */   
    CALL_E_EVT_CALL_MODIFY_VIDEO_RESULT,    /**< �޸���Ƶ���
                                                <br>param1��ulCallID 
                                                <br>param2��ulResult 0�ɹ� ����ʧ��
                                                <br>data��  CALL_S_MODIFY_VIDEO_RESULT*  */ 
    CALL_E_EVT_REFRESH_VIEW,                /**< ��Ƶviewˢ��֪ͨ
                                                <br>param1��ulCallID 
                                                <br>param2����
                                                <br>data��  CALL_S_REFRESH_VIEW*  */   
    CALL_E_EVT_DECODE_SUCCESS,              /**< ý�����ɹ�֪ͨ(��Ϣ��ΪCALL_S_DECODE_SUCCESS)
                                                <br>param1��ulCallID 
                                                <br>param2����
                                                <br>data��  CALL_S_DECODE_SUCCESS*  */  
    CALL_E_EVT_MOBILE_ROUTE_CHANGE,         /**< �ƶ�·�ɱ仯֪ͨ
                                                <br>param1��ulCallID 
                                                <br>param2��ulRoute
                                                <br>data��  ��  */   
    CALL_E_EVT_AUDIO_END_FILE,              /**< ��Ƶ�ļ�������֪ͨ
                                                <br>param1��ulHandle 
                                                <br>param2����
                                                <br>data��  ��  */   
    CALL_E_EVT_NET_QUALITY_CHANGE,          /**< ���������ı�֪ͨ
                                                <br>param1��ulCallID 
                                                <br>param2����
                                                <br>data��  CALL_S_NETQUALITY_CHANGE*  */
    CALL_E_EVT_STATISTIC_NETINFO,           /**< ��������ͳ����Ϣ
                                                <br>param1��ulCallID 
                                                <br>param2����
                                                <br>data��  CALL_S_STATISTIC_NETINFO*  */    
    CALL_E_EVT_STATISTIC_MOS,               /**< ��������Ƶ�����ϱ�ulQualityLevel 0-5 level=0ʱerrorֵ��Ч������� 
                                                <br>0 : û�д��� 1 : ���緢�˴��� 2 : �����ն˴��� 3 : �����շ�������     MOS���ϱ�
                                                <br>param1��ulCallID
                                                <br>param2��ulMos
                                                <br>data��  ��  */   
    CALL_E_EVT_STATISTIC_QOS,               /**< QOS������Ϣ�ϱ�
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  CALL_S_NOTIFYLOACLQOS_INFO* */   
    CALL_E_EVT_STATISTIC_LOCAL_QOS,         /**< ��ʱ5���ϱ�QOS������Ϣ�ϣ����ڽ�������״̬��ʾ
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_NOTIFYLOACLQOS_INFO* */    
    CALL_E_EVT_SPKDEV_VOLUME_CHANGE,        /**< �������豸�����仯(pc/mac)
                                                <br>param1��uiVolume
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_MICDEV_VOLUME_CHANGE,        /**< ��˷��豸�����仯(pc/mac)
                                                <br>param1��uiVolume
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_AUDIO_UNIT_INIT,             /**< ��Ƶ��Ԫ��ʼ�����֪ͨ(������֪ͨ�ϲ�����·��)
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  ��  */
    CALL_E_EVT_AUDIO_SET_INDEVICE_ERR,      /**< ��Ƶ���������豸ʧ��
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  ��  */
    CALL_E_EVT_AUDIO_SET_OUTDEVICE_ERR,     /**< ��Ƶ��������豸ʧ��
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  ��  */   
    CALL_E_EVT_VIDEO_OPERATION,             /**< ��Ƶ����
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_VIDEO_OPERATION*  */   
    CALL_E_EVT_VIDEO_STATISTIC_NETINFO,     /**< ��Ƶ��������ͳ����Ϣ
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_STATISTIC_NETINFO*  */    
    CALL_E_EVT_VIDEO_QUALITY,               /**< ��Ƶ����
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_NETQUALITY_CHANGE*  */
    CALL_E_EVT_VIDEO_FRAMESIZE_CHANGE,      /**< ��Ƶ��С���
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_VIDEO_FRAMESIZE_CHANGE*  */    
    CALL_E_EVT_DATA_FRAMESIZE_CHANGE,       /**< ������С���
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_VIDEO_FRAMESIZE_CHANGE*  */    
    CALL_E_EVT_DATA_READY,                  /**< ����׼����
                                                <br>param1��ulCallID
                                                <br>param2��bIsDataReady
                                                <br>data��  ��  */    
    CALL_E_EVT_DATA_SENDING,                /**< ������ʼ����
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_DATA_RECVING,                /**< ������ʼ����
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_DATA_START_ERR,              /**< ��������ʧ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_DATA_STOPPED,                /**< ����ֹͣ
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_SESSION_MODIFIED,            /**< �Ự�޸����֪ͨ
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_SESSION_MODIFIED*  */    
    CALL_E_EVT_SESSION_CODEC,               /**< �Ự����ʹ�õ�codec֪ͨ
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_SESSION_CODEC*  */    
    CALL_E_EVT_CALL_HOLD_SUCCESS,           /**< ���ֳɹ�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_HOLD_FAILED,            /**< ����ʧ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_UNHOLD_SUCCESS,         /**< �ָ��ɹ�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_UNHOLD_FAILED,          /**< �ָ�ʧ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_ENDCALL_FAILED,         /**< ����ͨ��ʧ��
                                                <br>param1��ulCallID
                                                <br>param2��ulResult ������
                                                <br>data��  ��  */    
    CALL_E_EVT_CALL_DIVERT_FAILED,          /**< ƫתʧ��
                                                <br>param1��ulCallID
                                                <br>param2��ulResult ������
                                                <br>data��  �� */    
	CALL_E_EVT_CALL_BLD_TRANSFER_RECV_SUC_RSP,	/**< äתREFER�յ��ɹ���Ӧ
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */	
    CALL_E_EVT_CALL_BLD_TRANSFER_SUCCESS,   /**< äת�ɹ�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_BLD_TRANSFER_FAILED,    /**< äתʧ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_ATD_TRANSFER_SUCCESS,   /**< ��ѯת�ɹ�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_ATD_TRANSFER_FAILED,    /**< ��ѯתʧ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_SET_IPT_SERVICE_SUCCESS,     /**< �Ǽ�ҵ��ɹ�,���ں��п���ʹ��
                                                <br>param1��CALL_E_SERVICE_CALL_TYPE enIPTServiceType
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_SET_IPT_SERVICE_FAILED,      /**< �Ǽ�ҵ��ʧ��,���ں��п���ʹ��
                                                <br>param1��CALL_E_SERVICE_CALL_TYPE enIPTServiceType
                                                <br>param2����
                                                <br>data��  �� */    
    CALL_E_EVT_SIPACCOUNT_WMI,              /**< ����֪ͨ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_MSG_WAIT_INFOS*  */    
    CALL_E_EVT_VVM_DOWNLOAD_SUCCESS_NOTIFY, /**< VVM���ؽ���ɹ�֪ͨ
                                                <br>param1��ulSipAccountID
                                                <br>param2��ulDataLen
                                                <br>data��  pcData  */    
    CALL_E_EVT_VVM_DOWNLOAD_FAIL_NOTIFY,    /**< VVM���ؽ��ʧ��֪ͨ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_VVM_FORWARD_SUCCESS_NOTIFY,  /**< VVMת�����Գɹ�֪ͨ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_VVM_FORWARD_FAIL_NOTIFY,     /**< VVMת������ʧ��֪ͨ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_VVM_DELETE_SUCCESS_NOTIFY,   /**< VVMɾ�����Գɹ�֪ͨ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_VVM_DELETE_FAIL_NOTIFY,      /**< VVMɾ������ʧ��֪ͨ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_VVM_DELETEALL_SUCCESS_NOTIFY,/**< VVMɾ���������Գɹ�֪ͨ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_VVM_DELETEALL_FAIL_NOTIFY,   /**< VVMɾ����������ʧ��֪ͨ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_CALL_VoiceMail_SUB_SUCCESS,  /**< �������䶩�ĳɹ�֪ͨ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_CALL_VoiceMail_SUB_FAILED,   /**< �������䶩��ʧ��֪ͨ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_TO_UI_JOINT_START,           /**< ���������¼�
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_CLOSE,           /**< �����ر��¼�
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_ACCEPTCALL,      /**< ���������¼�
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_STARTCALL,       /**< ���������¼�
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_HUNGUP,          /**< ���������¼�
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_HOLD,            /**< ������������
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_UNHOLD,          /**< �����ָ�����
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*   */    
    CALL_E_EVT_TO_UI_JOINT_DIVERT,          /**< ����ƫת����
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_BLDTRANSFER,     /**< ����äת����
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UP_JOINT_TO_CONF,         /**< ��������ת����
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_DTMF,            /**< ��������DTMF��Ϣ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_CONFCREATE,      /**< ������������
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_ONLINE,          /**< ������������
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_OFFLINE,         /**< ������������
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_ONHOOK,          /**< ���������ѹһ�
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_OFFHOOK,         /**< ����������ժ��
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_OUTGOING,        /**< ���������Ѻ���
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_ESTABLISHED,     /**< ������������ͨ����
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_RINGRING,        /**< ������������
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_SWITCH_TO_PHONE, /**< �����л�������
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_SWITCH_TO_PC,    /**< �����л���pc
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_CREATE_CONFERENCE,   /**< IPPHONE����֪ͨ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*   */    
    CALL_E_EVT_TO_UI_JOINT_REFER_RESULT,    /**< ����ת�ƽ��
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_STARTVIDEOCALL,  /**< ������Ƶ�����¼�
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_JOINT_CONF_RESULT,     /**< ����PC������֪ͨ�����ķ�����Ϣ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_JOINT_CMD_INFOS*  */    
    CALL_E_EVT_TO_UI_CTD_INFO,              /**< CTD info��Ϣ
                                                <br>param1��ulCallID
                                                <br>param2��ulServiceType
                                                <br>data��  CALL_S_CTD_INFO_BODY*  */    
    CALL_E_EVT_TO_UI_JOINT_REPLACECALL,	    /**< ����PC�滻������Ϣ
                                                <br>param1��ulCallID
                                                <br>param2��ulServiceType
                                                <br>data��  CALL_S_CTD_INFO_BODY*  */
    CALL_E_EVT_TO_UI_JOINT_JOINMSCONF,      /**< ���������ںϻ����ϱ�
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  CALL_S_JOINMSCONF_INFO*  */    
    CALL_E_EVT_TO_UI_JOINT_PEER_CAPS_REPORT,/**< ���������Ƿ������Ƶ�����ϱ�
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  CALL_S_JOINMSCONF_INFO*  */    
	CALL_E_EVT_SERVER_LINK_OK,              /**< ���������������������� ��
                                                <br>param1��ulCallID
                                                <br>param2��ucCheckingServerIndex
                                                <br>data��  ��  */    
    CALL_E_EVT_CALL_RECORD_SUCCESS,         /**< ��¼���������ɹ�
                                                <br>param1��ulID
                                                <br>param2��ulIDType
                                                <br>data��  �� */    
    CALL_E_EVT_CALL_RECORD_FAILED,          /**< ��¼��������ʧ��
                                                <br>param1��ulID
                                                <br>param2��ulIDType
                                                <br>data��  �� */    
    CALL_E_EVT_CALL_UNRECORD_SUCCESS,       /**< ��¼�����رճɹ�
                                                <br>param1��ulID
                                                <br>param2��ulIDType
                                                <br>data��  �� */    
    CALL_E_EVT_CALL_UNRECORD_FAILED,        /**< ��¼�����ر�ʧ��
                                                <br>param1��ulID
                                                <br>param2��ulIDType
                                                <br>data��  �� */    
    CALL_E_EVT_CALL_CALLINFO_SUB_FAILED,    /**< ������·״̬����ʧ��
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_CALL_CALLINFO_UNSUB_FAILED,  /**< ������·״̬ȥ����ʧ��
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_CALL_LINESEIZE_UNSUB_FAILED, /**< ����ժ��ȥ����ʧ��
                                                <br>param1��ulSipAccountID
                                                <br>param2��ulLineID
                                                <br>data��  �� */    
    CALL_E_EVT_CALL_LINESEIZE_UNSUB_SUCCESS,/**< ����ժ��ȥ���ĳɹ�
                                                <br>param1��ulSipAccountID
                                                <br>param2��ulLineID
                                                <br>data��  �� */    
    CALL_E_EVT_CALL_LINESEIZE_SUCCESS,      /**< ����ժ���ɹ�
                                                <br>param1��ulSipAccountID
                                                <br>param2��ulLineID
                                                <br>data��  �� */    
    CALL_E_EVT_CALL_LINESEIZE_FAILED,       /**< ����ժ��ʧ��
                                                <br>param1��ulSipAccountID
                                                <br>param2��ulLineID
                                                <br>data��  ��  */    
    CALL_E_EVT_CALL_CALLINFO_NOTIFY,        /**< ������·״̬֪ͨ
                                                <br>param1��ulStateCount
                                                <br>param2����
                                                <br>data��  CALL_S_SCA_CALLINFO*  */    
    CALL_E_EVT_CALL_MODIFY_SUCCESS,         /**< �޸�ͨ���ɹ�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_MODIFY_FAILED,          /**< �޸�ͨ��ʧ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_JOIN_CONF,              /**< ͨ�����뱾�ػ��飬֪ͨͨ��״̬
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_LCONF_JOIN_SUCCESS,          /**< ���ػ������ɹ�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CONFER_LOCAL_INFO*  */    
    CALL_E_EVT_LCONF_JOIN_FAILED,           /**< ���ػ������ʧ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CONFER_LOCAL_INFO*  */    
    CALL_E_EVT_LCONF_TALK_STATE_CHANGE,     /**< ����߷���״̬�ı�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CONFER_LOCAL_INFO*  */    
    CALL_E_EVT_LCONF_CONFEREE_DROPED,       /**< �޳������/������˳��᳡
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CONFER_LOCAL_INFO*  */    
    CALL_E_EVT_LCONF_CONFER_ENDED,          /**< ��������֪ͨ
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CONFER_LOCAL_INFO*  */    
    CALL_E_EVT_LCONF_HOLD_SUCESS,           /**< ���ֻ᳡�ɹ�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CONFER_LOCAL_INFO*  */    
    CALL_E_EVT_LCONF_HOLD_FAILED,           /**< ���ֻ᳡ʧ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CONFER_LOCAL_INFO*  */    
    CALL_E_EVT_LCONF_UNHOLD_SUCESS,         /**< �ָ��᳡�ɹ�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CONFER_LOCAL_INFO*  */    
    CALL_E_EVT_LCONF_UNHOLD_FAILED,         /**< �ָ��᳡ʧ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CONFER_LOCAL_INFO*  */    
    CALL_E_EVT_CALL_MOBILE_EXTEND_SUCCESS,  /**< �ֻ��ֻ��л��ɹ�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_MOBILE_EXTEND_FAILED,   /**< �ֻ��ֻ��л�ʧ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_ACBCALL_REQ,            /**< ACB����
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_ACB_REQ_INFO*  */    
    CALL_E_EVT_CALL_ACBCALL_TIMEOUT,        /**< ACB��ʱ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_IPT_DATA*  */    
    CALL_E_EVT_CALL_CALLPARK_GET_SUCCESS,   /**< פ��ȡ�سɹ�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_CALLPARK_GET_FAILED,    /**< פ��ȡ��ʧ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_CALLPARK_INVALID,       /**< פ����ʱ���߱�ȡ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CONTACT_STATUS_CHANGE,       /**< ��ϵ��״̬�ϱ�
                                                <br>param1��ulSipAccountID
                                                <br>param2��ulNum
                                                <br>data��  pcData  */
    CALL_E_EVT_CONTACTINCRE_STATUS_CHANGE,  /**< PGM��ϵ�������ϱ�
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  pcData  */    
    CALL_E_EVT_CONTACT_INFO,                /**< ��ϵ����Ϣ
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_CONTACT_INFO*  */    
    CALL_E_EVT_PHONE_SETTING_STATUS_CHANGE, /**< ��������״̬
                                                <br>param1��ulSipAccountID
                                                <br>param2��CALL_E_CONTACT_STATUS
                                                <br>data��  �� */    
    CALL_E_EVT_ONLINESTATE_NOTIFY_INFO,     /**< ����״̬����notify body�ϱ�
                                                <br>param1��ulSipAccountID
                                                <br>param2��ulSendNum
                                                <br>data��  pcBodyTmp  */    
    CALL_E_EVT_NETADDR_NOTIFY_INFO,         /**< �����ַ������notify body�ϱ�
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_IDO_NETADDRESS*  */    
    CALL_E_EVT_FORCEUNREG_INFO,             /**< �˺ű���info body�ϱ�
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_IDO_FORCEUNREG*  */    
    CALL_E_EVT_SUB_ONLINESTATE_RESULT_INFO, /**< ����״̬���Ľ���ϱ�
                                                <br>param1��ulSipAccountID
                                                <br>param2��ulResult
                                                <br>data��  ��  */    
    CALL_E_EVT_SUB_NETADDR_RESULT_INFO,     /**< �����ַ�����Ľ���ϱ�
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  �� */    
    CALL_E_EVT_CALL_AUTHORIZE_SUCCESS,      /**< ��Ȩ�ɹ�
                                                <br>param1��ulResult
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_CALL_AUTHORIZE_FAILED,       /**< ��Ȩʧ��
                                                <br>param1��ulResult
                                                <br>param2����
                                                <br>data��  �� */    
    CALL_E_EVT_NEW_SERVICE_RIGHT,           /**< ҵ��Ȩ�޸ı䣬֪ͨ����
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_SERVICERIGHT_CFG*  */    
    CALL_E_EVT_SERVERCONF_INCOMING,         /**< ���������¼�
                                                <br>param1��ulConfID
                                                <br>param2��ulCallID
                                                <br>data��  CALL_S_CONF_INFO*  */    
    CALL_E_EVT_SERVERCONF_CREATE_RESULT,    /**< ����������
                                                <br>param1��ulConfID
                                                <br>param2��ulResult
                                                <br>data��  pcBody */    
    CALL_E_EVT_SERVERCONF_CONNECT_RESULT,   /**< ���������
                                                <br>param1��ulConfID
                                                <br>param2��ulResult
                                                <br>data��  CALL_S_CONF_CONNECT_RESULT*  */    
    CALL_E_EVT_SERVERCONF_ADDATTENDEE_RESULT,   /**< �������߽��
                                                <br>param1��ulConfID
                                                <br>param2��ulResult
                                                <br>data��  pcAttendees*  */    
    CALL_E_EVT_SERVERCONF_REFRESHLIST,      /**< ˢ��������б�
                                                <br>param1��ulConfID
                                                <br>param2��ulAttendeeCount
                                                <br>data��  CALL_S_CONF_MEMBER*  */    
    CALL_E_EVT_SERVERCONF_SUBJECT,          /**< �ϱ���������
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  CALL_S_CONF_SUBJECT*  */    
    CALL_E_EVT_SERVERCONF_CHAIRMAN_NUM,     /**< �ϱ���ϯ����
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  pcChairNum */    
    CALL_E_EVT_SERVERCONF_DATACONF_PARAM,   /**< �ϱ����ݻ�����ز���
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  CALL_S_DATACONF_PARAM*  */    
    CALL_E_EVT_SERVERCONF_MODIFYATTENDEE_RESULT,   /**< �޸�����߷���Ȩ���
                                                <br>param1��ulConfID
                                                <br>param2��ulResult
                                                <br>data��  pcAttendeeNumber */    
    CALL_E_EVT_SERVERCONF_DROPATTENDEE_RESULT,   /**< �߳�����߽��
                                                <br>param1��ulConfID
                                                <br>param2��ulResult
                                                <br>data��  pcAttendeeNumber */    
    CALL_E_EVT_SERVERCONF_END_RESULT,       /**< ����������
                                                <br>param1��ulConfID
                                                <br>param2��ulResult
                                                <br>data��  ��  */    
    CALL_E_EVT_SERVERCONF_ATTENDEEKICKED,   /**< ����߱��߳�
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  pcAttendeeNum  */    
    CALL_E_EVT_SERVERCONF_ENDED,            /**< ���鱻����
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  �� */    
    CALL_E_EVT_SERVERCONF_ATTENDEEJOINED_SUCCESS,   /**< ����߼���ɹ�
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_SERVERCONF_ACCESSCODEJOINED_SUCCESS,   /**< ��������м��룬����߼���ɹ�
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  �� */    
    CALL_E_EVT_SERVERCONF_ATTENDEEJOINED_FAILED,   /**< ����߼���ʧ��
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_SERVERCONF_ATTENDEEQUIT,     /**< ������˳�
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_SERVERCONF_ADDRESSOR,        /**< ��ʾ������
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  pstSpeakMem  */    
    CALL_E_EVT_SERVERCONF_BETRANSFERTOCONF, /**< ��ת����
                                                <br>param1��ulConfID
                                                <br>param2��ulCallID
                                                <br>data��  CALL_S_CONF_BETRANSFERTOCONF*  */    
    CALL_E_EVT_BETRANSFERTOPRERECECONF,     /**< ��ת���ںϻ��� 
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO* */
    CALL_E_EVT_SERVERCONF_TRANSFERTOCONF_SUCCESS,   /**< ת����ɹ�
                                                <br>param1��ulConfID
                                                <br>param2��ulCallID
                                                <br>data��  CALL_S_CONF_TRANSFERTOCONF_RESULT*  */    
    CALL_E_EVT_SERVERCONF_TRANSFERTOCONF_FAILED,   /**< ת����ʧ��
                                                <br>param1��ulConfID
                                                <br>param2��ulCallID
                                                <br>data��  CALL_S_CONF_TRANSFERTOCONF_RESULT */    
    CALL_E_EVT_SERVERCONF_HOLD_SUCESS,      /**< ���ֻ᳡�ɹ�
                                                <br>param1��ulConfID
                                                <br>param2��ulResult
                                                <br>data��  ��  */    
    CALL_E_EVT_SERVERCONF_HOLD_FAILED,      /**< ���ֻ᳡ʧ��
                                                <br>param1��ulConfID
                                                <br>param2��ulResult
                                                <br>data��  ��   */    
    CALL_E_EVT_SERVERCONF_UNHOLD_SUCESS,    /**< �ָ��᳡�ɹ�
                                                <br>param1��ulConfID
                                                <br>param2��ulResult
                                                <br>data��  ��   */    
    CALL_E_EVT_SERVERCONF_UNHOLD_FAILED,    /**< �ָ��᳡ʧ��
                                                <br>param1��ulConfID
                                                <br>param2��ulResult
                                                <br>data��  ��   */    
    CALL_E_EVT_SERVERCONF_MUTE_STATUS_CHANGE,   /**< �᳡����״̬���
                                                <br>param1��ulConfID
                                                <br>param2��bMuted
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_SERVERCONF_LOCK_STATUS_CHANGE,   /**< �᳡����״̬���
                                                <br>param1��ulConfID
                                                <br>param2��bLocked
                                                <br>data��  ��  */
    CALL_E_EVT_PICKUP_NOTIFY,               /**< ͬ�����֪ͨ/ȡ��
                                                <br>param1��bIndicate
                                                <br>param2��ulSipAccoutID
                                                <br>data��  CALL_S_TIPINFO*  */    
    CALL_E_EVT_FORWARD_RESULT,              /**< ǰת���еĽ��
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  CALL_S_FORWARD_SERVICE*  */    
    CALL_E_EVT_IMS_FORWARD_RESULT,          /**< IMS��ǰת��Ŀ�ĺ�����
                                                <br>param1��ulSipAccountId
                                                <br>param2��ulCallID
                                                <br>data��  CALL_S_HISTORY_INFO*  */    
    CALL_E_EVT_CALL_LOGOUT_NOTIFY,          /**< ֪ͨ����logout
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_TURN_CALL_NOTIFY,            /**< ֪ͨ���棬�ֻ��ֻ����ֻ��������Ҷ�
                                                <br>param1��bIndicate
                                                <br>param2��ulSipAccoutID
                                                <br>data��  pszNumber  */    
    CALL_E_EVT_SUB_BLF_RESULT_NOTIFY,       /**< BLF���Ľ��
                                                <br>param1��ulSipAccountID
                                                <br>param2��ulResult
                                                <br>data��  pvSubData  */    
    CALL_E_EVT_SUB_RLS_RESULT_NOTIFY,       /**< RLS���Ľ��
                                                <br>param1��ulSipAccountID
                                                <br>param2��ulResult
                                                <br>data��  �� */    
    CALL_E_EVT_CALL_CALLOUT_TIMEOUT,        /**< ������ʱ
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_REPORTED_CALLINFO,      /**< ���������ϱ�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_CLEAN_SCALINE,          /**< ���������·״̬
                                                <br>param1��accountid
                                                <br>param2��appearance_lineIndex
                                                <br>data��  ��  */    
    CALL_E_EVT_UM_MSG_NOTIFY,               /**< UM �¼�����
                                                <br>param1��ulSipAccoutID
                                                <br>param2����
                                                <br>data��  CALL_S_UM_MSG*  */    
    CALL_E_EVT_CALL_INTERCOM_NUMBER,        /**< �ϱ�����AA���͵�intercom����
                                                <br>param1��ulSipAccoutID
                                                <br>param2����
                                                <br>data��  pszIntercomNumber*  */    
    CALL_E_EVT_CALL_CALLPARK_SUCCESS,       /**< ����פ���ɹ�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_CALL_183_BUSY,               /**< ͨ���յ�183busy
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_CALL_PICKUP_REMOTE_INFO,     /**< �������з���Ϣ
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_PICKUP_REMOTE_INFO*  */    
    CALL_E_EVT_CALL_ACB_LIST_NOTIFY,        /**< �غ��б�֪ͨ
                                                <br>param1��ulSipAccountID
                                                <br>param2��ulACBCount
                                                <br>data��  CALL_S_ACB_INFO*  */    
    CALL_E_EVT_CALL_PICKUP_INTERCOM_SUCCESS,/**< intercom����ɹ�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_PICKUP_INTERCOM_FAILED, /**< intercom����ʧ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_INTERCOM_BEPICKUP,      /**< intercom ��pick up �¼�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_UPATE_REMOTEINFO,       /**< ����Զ�˺�����Ϣ
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_SRTP_STATE,             /**< SRTP������ر�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_PINCODE_VALID,          /**< ͨ�����Ƿ����� PinCode
                                                <br>param1��ulCallID
                                                <br>param2��bPinCodeValid
                                                <br>data��  ��  */    
    CALL_E_EVT_CALL_PINCODE_OK,             /**< ������֤ͨ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_CALL_PINCODE_ERROR,          /**< ������֤ʧ�ܣ�����������
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_CALL_CALLACCEPTED_RMTCTRL,   /**< �Զ˻ظ� 200 OK �� P-Notification: Callee Ctrl
                                                <br>param1��ulCallID
                                                <br>param2��ulRmtCtrl
                                                <br>data��  ��  */
    CALL_E_EVT_CALL_CALL_REINVITED,         /**< Call���ܶԶ˵�Reinvite�� ���ϱ���
                                                <br>param1��ulCallID
                                                <br>param2��enHoldType
                                                <br>data��  CALL_S_CALL_INFO* */    
    CALL_E_EVT_SET_IPT_SERVICE_BATCH_SUCCESS,   /**< �����Ǽ�ҵ��ɹ�
                                                <br>param1��CALL_E_CALL_EVENT enIPTServiceType
                                                <br>param2��ulResultNum
                                                <br>data��  pulResultlist */    
    CALL_E_EVT_SET_IPT_SERVICE_BATCH_FAILED,/**< �����Ǽ�ҵ��ʧ��
                                                <br>param1��CALL_E_CALL_EVENT enIPTServiceType
                                                <br>param2��ulResultNum
                                                <br>data��  pulResultlist  */    
    CALL_E_EVT_SET_CALL_LIMIT_ON_LOCKED,    /**< �Ǽ������޺�ʧ��(������)
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_SET_CALL_LIMIT_OFF_LOCKED,   /**< ȡ�������޺�ʧ��(������)
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_SERVERCONF_MERGER_RESULT,    /**< �ϲ�������
                                                <br>param1��ulConfID
                                                <br>param2��ulResult
                                                <br>data��  pcBody  */    
    CALL_E_EVT_SERVERCONF_SPLIT_RESULT,     /**< ��ֻ�����
                                                <br>param1��ulConfID
                                                <br>param2��ulResult
                                                <br>data��  pcBody  */    
    CALL_E_EVT_ACCOUNT_STATUS_CHANGE,       /**< �˺�״̬���
                                                <br>param1��ulSipAccountID
                                                <br>param2��CALL_E_CONTACT_STATUS enStatus
                                                <br>data��  ��  */    
    CALL_E_EVT_MESSAGE_RELOGIN_REQUEST,     /**< �յ�relogin��message��֪ͨ��������AA��¼
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_CALL_ONEKEY_TO_WM_ON_CALL_SUCCESS,   /**< �ϱ�һ��תVM�ɹ�
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_ONEKEY_TO_WM_ON_CALL_FAIL,   /**< �ϱ�һ��תVMʧ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_CALL_CALLPARK_FAILED,        /**< פ��ʧ��
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_CALL_INFO*  */    
    CALL_E_EVT_SERVERCONF_CONNECT_ONEKEY_TO_CONF_RESULT,   /**< һ�����������
                                                <br>param1��ulCallID
                                                <br>param2��ulResult
                                                <br>data��  CALL_S_ONEKEY_TO_CONF_RESULT*  */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_CREATEWND_RESULT,   /**< ��Ƶ���鴴�����ڽ��
                                                <br>param1��ulConfID
                                                <br>param2��ulCreateResult
                                                <br>data��  CALL_S_VIDEOCONFWND_INFO*  */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_CREATEVIDEO_MEETING_FAILED,   /**< ������Ƶ����ʧ��
                                                <br>param1��ulConfID
                                                <br>param2��ulReason
                                                <br>data��  ��  */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_LEAVECONF_RESULT,   /**< ��Ƶ���������뿪������
                                                <br>param1��ulConfID
                                                <br>param2��ulLeaveResult
                                                <br>data��  ��  */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_ATTEND_JOINED_CONF,   /**< ��Ƶ�����Ա�������
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  pszAttendNum */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_END_CONF,   /**< ��Ƶ�������
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_BEKICKOUT_CONF,   /**< ��Ƶ�����б���ϯ�߳�
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_LEAVE_CONF,   /**< ��Ƶ��������������˳�
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  pszAttendNum  */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_VIDEO_STATUS_CHANGE,   /**< ��Ƶ����������߰����Լ�����Ƶ״̬�ı�֪ͨ
                                                <br>param1��ulConfID
                                                <br>param2��CALL_E_VIDEOCONF_DEVICE_STATUS eVideoConfVideoStatus
                                                <br>data��  pszAttendNum  */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_VIDEO_REQUEST_CHANGE,   /**< ��Ƶ��������Ƶ�����������������
                                                <br>param1��ulConfID
                                                <br>param2��bOpenVideo
                                                <br>data��  pszAttendNum  */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_VIDEO_DEVICE_STATUS,   /**< ��Ƶ����������߰����Լ�����Ƶ�豸״̬�ı�֪ͨ: �β�
                                                <br>param1��ulConfID
                                                <br>param2��CALL_E_VIDEOCONF_DEVICE_INPUT_STATUS eDeviceStatus
                                                <br>data��  pszAttendNum */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_JOINCHANNEL,   /**< ��Ƶ���뵽�ߵ���ʱ�ķ����������������뵽�ߵ���
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  CALL_S_VIDEOCONF_DOUBLESTREAM_STATUS*  */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_VIDEO_DISCONNECT,   /**< ��Ƶ����ʧȥ����
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_VIDEO_RECONNECT,   /**< ��Ƶ������������
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_USERDEVICE_STATUSCHANGE,   /**< ��Ƶ�������豸״̬�ı�(��ͣ����ȡ����ͣ)
                                                <br>param1��ulConfID
                                                <br>param2��CALL_E_VIDEOCONF_DEVICE_STATUS eLocalDeviceStatus
                                                <br>data��  pszAttendNum */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_WARNING_FLOWCONTROL,   /**< ���ظ澯(��ǰ��Ƶ�����£�����Ҫ���أ���ر���Ƶ����ʾ)
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  pszAttendNum  */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_NOTIFY_FLOWCONTROL,   /**< ������Ƶ�ֱ��ʸ���֪ͨ
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  pszAttendNum  */    
    CALL_E_EVT_SERVERCONF_VOICECONF_TO_VIDEOCONF_SUCCESS,   /**< ��Ƶ����ת��Ƶ����ɹ�
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  �� */    
    CALL_E_EVT_SERVERCONF_VOICECONF_TO_VIDEOCONF_FAILED,   /**< ��Ƶ����ת��Ƶ����ʧ��
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  �� */    
    CALL_E_EVT_SERVERCONF_VIDEO_ON_FIRST_KEYFRAME,   /**< �ؼ�֪֡ͨ
                                                <br>param1��ulConfID
                                                <br>param2����
                                                <br>data��  pszAttendNum  */    
    CALL_E_EVT_SERVERCONF_VIDEOCONF_NET_STATUS,   /**< ����״̬֪ͨ
                                                <br>param1��ulNetStatus
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_MEETING_MSG_NOTIFY,          /**< �����¼�����
                                                <br>param1��ulSipAccoutID
                                                <br>param2����
                                                <br>data��  CALL_S_UM_MEETING_MSG*  */    
    CALL_E_EVT_GET_MEETING_CONF_RESULT,     /**< ��ȡ�����б���
                                                <br>param1��ulResult
                                                <br>param2��ulSipAccount
                                                <br>data��  CALL_S_GETCONF_MEETING_LIST_INFO*  */    
    CALL_E_EVT_GET_MEETING_CONF_XML_RESULT, /**< ��ȡ����XML �ļ����
                                                <br>param1��ulResult
                                                <br>param2��ulSipAccount
                                                <br>data��  pFileNameList  */    
    CALL_E_EVT_SIP_AUTH_INFO_WRITTEN,       /**< �˻���Ȩ��Ϣд�������ļ��ɹ���֪ͨUI
                                                <br>param1��ulAccountID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_SWITCH_DND_SUCCESS,          /**< �л�DNDģʽ�ɹ�
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  �� */    
    CALL_E_EVT_SWITCH_DND_FAIL,             /**< �л�DNDģʽʧ��
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  �� */    
    CALL_E_EVT_CALL_RECORDINFO_NOTIFY,      /**< ֪ͨ��¼�������
                                                <br>param1��ulID
                                                <br>param2��ulIDType
                                                <br>data��  CALL_S_RECORD_INFO*  */    
    CALL_E_EVT_SPKDEV_MUTE_CHANGE,          /**< �������豸����״̬�仯 iMute ��ǰ����״̬ 0��ǰ״̬Ϊ�Ǿ���  ��0 ��ǰ״̬Ϊ����
                                                <br>param1��iMute
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_MICDEV_MUTE_CHANGE,          /**< ��˷��豸����״̬�仯 iMute ��ǰ����״̬ 0��ǰ״̬Ϊ�Ǿ���  ��0 ��ǰ״̬Ϊ����
                                                <br>param1��iMute
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_VMTC_VERSION_INFO,           /**< VMTC�汾��Ϣ uiVerInfo �汾�ȽϽ�� 0:�汾���� 1:VM�汾�� 2:TC�汾��
                                                <br>param1��uiVerInfo
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_VMTC_DISCONNECT,             /**< VMTC�Ͽ�����֪ͨ uiInfo �Ͽ�������Ϣ
                                                <br>param1��uiInfo
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_VMTC_CONNECTOK,              /**< VMTC���ӳɹ�֪ͨ uiInfo ���ӳɹ���Ϣ
                                                <br>param1��uiInfo
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_SYN_MISSCALL,                /**< ����ͨ����¼ͬ��
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  �� */    
    CALL_E_EVT_HUNTGROUP_STATUS_CHANGE,     /**< ֪ͨhuntgroup״̬�ı�
                                                <br>param1��ulSipAccountID
                                                <br>param2����
                                                <br>data��  CALL_S_CONTACT_STATUS*  */    
    CALL_E_EVT_PAGING_INCOMING,             /**< ֪ͨpaging����
                                                <br>param1��ulGroupID
                                                <br>param2����
                                                <br>data��  CALL_S_PAGING_GROUP*  */    
    CALL_E_EVT_PAGING_ENDED,                /**< ֪ͨpaging������
                                                <br>param1��ulGroupID
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_SIPPORT_CHANGE,              /**< sip�˿ڱ��֪ͨ
                                                <br>param1��ulSipPort
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_AUDIO_DEVICE_CHANGED,        /**< ��Ƶ����/����豸���֪ͨ
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  CALL_S_AUDIO_DEVICE_INFO*  */    
    CALL_E_EVT_AUDIO_INPUT_DEVICE_CHANGED,  /**< ��Ƶ�����豸���֪ͨ
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_AUDIO_OUTPUT_DEVICE_CHANGED, /**< ��Ƶ����豸���֪ͨ
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_VIDEO_DEVICE_CHANGED,        /**< ��Ƶ�����豸(Capture)���֪ͨ
                                                <br>param1��ulCallID
                                                <br>param2��bIsDeviceLost, ��ʾ��ǰ����ͷ�Ƿ�ʧ, true��ʾ��ʧ
                                                <br>data��  CALL_S_VIDEO_DEVICE_INFO*  */    
    CALL_E_EVT_MEDIA_ERROR_INFO,            /**< ý�������Ϣ֪ͨ
                                                <br>param1��ulCallID
                                                <br>param2����
                                                <br>data��  CALL_S_MEDIA_ERRORINFO*  */    
    CALL_E_EVT_PASSWORD_CHANGEED_RESULT,    /**< �����޸Ľ��
                                                <br>param1��ulResult
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_GET_LICENSE_TYPE_RESULT,     /**< ��ȡlicense������Ӧ
                                                <br>param1��ulResult TUP_SUCCESS �ɹ�  ����ֵ ʧ��
                                                <br>param2��ulLicenseType (LOGIN_E_LICENSE_TYPE)
                                                <br>data��  ��  */    
    CALL_E_EVT_APPLY_LICENSE_RESULT,        /**< ����license��Ӧ
                                                <br>param1��ulResult TUP_SUCCESS �ɹ�  ����ֵ ʧ��
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_REFRESH_LICENSE_FAILED,      /**< ����licenseʧ��
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_RELEASE_LICENSE_RESULT,      /**< �ͷ�license��Ӧ
                                                <br>param1��ulResult TUP_SUCCESS �ɹ�  ����ֵ ʧ��
                                                <br>param2����
                                                <br>data��  ��  */    
    CALL_E_EVT_IDO_OVER_BFCP,               /**< id���ʹ��bfcp��ʽ
                                                <br>param1��ulCallID
                                                <br>param2��bIdoOverBfcp
                                                <br>data��  ��  */    
    CALL_E_EVT_DEVICE_STATUS_CHANGE,        /**< ���� �豸״̬����ϱ�
                                                <br>param1��istatus
                                                <br>data��  ��  */    
    CALL_E_EVT_SIP_AUTH_TYPE,               /**< sip��֤��ʽ
                                                <br>param1��ulSipAccount
                                                <br>param2��eAuthType ��CALL_E_AUTH_TYPE��
                                                <br>data��  ��  */    
    CALL_E_EVT_UPORTAL_TOKEN_REFRESH,       /**< uportal tokenˢ��֪ͨ
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  CALL_S_UPORTAL_TOKEN_REFRESH_INFO */        
    CALL_E_EVT_COMPLETE_LOAD_SERVIE_RIGHT,  /**< �յ�relogin��message��֪ͨ��������AA��¼ 
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  CALL_S_UPORTAL_TOKEN_REFRESH_INFO */     
    CALL_E_EVT_REFER_NOTIFY,                /**< ת��֪ͨ
                                                <br>param1��ulCallId
                                                <br>param2����
                                                <br>data��  �� */
    CALL_E_EVT_EXIT_UI_MSGQUEUE,            /**< �˳���Ϣ����������Ϣ��������� 
                                                <br>param1����
                                                <br>param2����
                                                <br>data��  PID�� */    
    CALL_E_EVT_DIALOG_INFO,                 /**<���ܵ��Ի���INFO��Ϣ��
                                                @see CALL_D_CFG_SIP_CONTENT_TYPE*/


    CALL_E_EVT_BUTT
} CALL_E_CALL_EVENT;




/**
 * SIP�˻�ע��״̬
 */
typedef enum tagCALL_E_REG_STATE
{
    CALL_E_REG_STATE_UNREGISTER,     /**< SIP�˻�δע�� */
    CALL_E_REG_STATE_REGISTERING,    /**< SIP�˻�ע���� */
    CALL_E_REG_STATE_DEREGISTERING,  /**< SIP�˻�ע���� */
    CALL_E_REG_STATE_REGISTERED,     /**< SIP�˻���ע�� */
    CALL_E_REG_STATE_BUTT            /**< SIP�˻���Ч״̬ */
} CALL_E_REG_STATE;

/**
 * ��������
 */
typedef enum tagCALL_E_CALL_TYPE
{
    CALL_E_CALL_TYPE_IPAUDIO,        /**< IP�������� */
    CALL_E_CALL_TYPE_IPVIDEO,        /**< IP��Ƶ���� */
    CALL_E_CALL_TYPE_BUTT            /**< ��Ч���ͺ��� */
} CALL_E_CALL_TYPE;


/** 
 * ���л���״̬
 */
typedef enum tagCALL_E_CALL_STATE
{
    CALL_E_CALL_STATE_IDLE,         /**< ���п���̬ */
    CALL_E_CALL_STATE_IN,           /**< ���к���̬ */
    CALL_E_CALL_STATE_OUT,          /**< ���к���̬ */
    CALL_E_CALL_STATE_LIVE,         /**< ����ͨ��̬ */
    CALL_E_CALL_STATE_HOLD,         /**< ���б���̬ */
    CALL_E_CALL_STATE_END,          /**< ���н���̬ */
    
    CALL_E_CALL_STATE_BUTT          /**< ������Ч̬ */
} CALL_E_CALL_STATE;


/** 
 * �豸����
 */
typedef enum tagCALL_E_DEVICE_TYPE
{
    CALL_E_CALL_DEVICE_MIC,         /**< ��˷��豸 */
    CALL_E_CALL_DEVICE_SPEAK,       /**< �������豸 */
    CALL_E_CALL_DEVICE_VIDEO,       /**< ��Ƶ�豸 */
    CALL_E_CALL_DEVICE_BUTT         /**< ��Ч�豸 */
} CALL_E_DEVICE_TYPE;


/**
 * ��������
 */
typedef enum tagCALL_E_CALL_ALERTTYPE
{
    CALL_E_CALL_ALERTTYPE_COMMON = 0x1,     /**< ��ͨ���� */
    CALL_E_CALL_ALERTTYPE_INTERNAL,         /**< �������� */
    CALL_E_CALL_ALERTTYPE_EXTERNAL,         /**< �������� */
    CALL_E_CALL_ALERTTYPE_NETWORK,          /**< ������� */
    CALL_E_CALL_ALERTTYPE_SILENCE,          /**< ���羲�� */
    CALL_E_CALL_ALERTTYPE_WAKEUP,           /**< �������� */
    CALL_E_CALL_ALERTYPE_HUNTGROUP,         /**< HUNTGROUP�������� */

    CALL_E_CALL_ALERTTYPE_BUTT = 0x0
} CALL_E_CALL_ALERTTYPE;


/** 
 * �ϱ��������������������
 */
typedef enum tagCALL_E_MSG_WAIT_TYPE
{
    CALL_E_MSG_WAIT_TYPE_VOICE = 0,     /**< ������Ϣ */
    CALL_E_MSG_WAIT_TYPE_VIDEO,         /**< ��Ƶ��Ϣ */
    CALL_E_MSG_WAIT_TYPE_FAX,           /**< ������Ϣ */
    CALL_E_MSG_WAIT_TYPE_PAGER,         /**< ҳ����Ϣ */
    CALL_E_MSG_WAIT_TYPE_MULTIMEDIA,    /**< ý����Ϣ */
    CALL_E_MSG_WAIT_TYPE_TEXT,          /**< �ı���Ϣ */
    CALL_E_MSG_WAIT_TYPE_VITRUALVM,     /**< ��������������Ϣ */
    CALL_E_MSG_WAIT_TYPE_BUTT           /**< δ֪��Ϣ */
} CALL_E_MSG_WAIT_TYPE;


/**
 * �����ɫ
 */
typedef enum tagCALL_E_CONF_ROLE
{
    CALL_E_CONF_ROLE_ATTENDEE,          /**< ����� */
    CALL_E_CONF_ROLE_CHAIRMAN,          /**< ��ϯ�� */
    CALL_E_CONF_ROLE_CONFCHAIN,         /**< ����(�ϲ�����ҵ��) */
    CALL_E_CONF_ROLE_CHAIRMAN_DN,       /**< ��ϯ��DN */
    CALL_E_CONF_ROLE_BUTT
} CALL_E_CONF_ROLE;


/**
 * ���������
 */
typedef enum tagCALL_E_CONF_ATTENDEE_TYPE
{
    CALL_E_CONF_ATTENDEE_NORMAL,          /*��ͨ�����*/
    CALL_E_CONF_ATTENDEE_TE,          /**< TE����� */
    CALL_E_CONF_ATTENDEE_BUTT
} CALL_E_CONF_ATTENDEE_TYPE;



/**
 * ���������������״̬
 */
typedef enum tagCALL_E_CONF_STATE
{
    CALL_E_CONF_ATTENDEE_INVITING,      /**< ������  */
    CALL_E_CONF_ATTENDEE_INVITE_FAIL,   /**< ����ʧ��  */
    CALL_E_CONF_ATTENDEE_ADD_FAIL,      /**< ���ʧ��  */
    CALL_E_CONF_ATTENDEE_INCONF,        /**< ������  */
    CALL_E_CONF_ATTENDEE_OUT,           /**< �˳����� */
    CALL_E_CONF_ATTENDEE_STATE_BUTT
} CALL_E_CONF_ATTENDEE_STATE;


/**
 * �����������˳���������
 */
typedef enum tagCALL_E_CONF_END_TYPE
{
    CALL_E_CONF_END_TYPE_END,           /**< ��������,�ͷŻ᳡ */
    CALL_E_CONF_END_TYPE_LEAVE          /**< ���,���ͷŻ᳡ */
} CALL_E_CONF_END_TYPE;


/**
 * ҵ��Ȩ�����ͣ���Ӧ���ݽṹCALL_S_SERVICERIGHT_CFG
 * @see tagCALL_S_SERVICERIGHT_CFG
 */
typedef enum tagCALL_E_SERVICE_RIGHT_TYPE
{
    CALL_E_SERVICE_RIGHT_TYPE_NULL = -1,                        /**< �����ͣ���Ч���� */ 
        
    CALL_E_SERVICE_RIGHT_TYPE_ABBRDIAL = 0,                     /**< ��λ���� */
    CALL_E_SERVICE_RIGHT_TYPE_CTD,                              /**< ������� */
    CALL_E_SERVICE_RIGHT_TYPE_CALLDEFLECTION,                   /**< ����ƫתҵ�� */
    CALL_E_SERVICE_RIGHT_TYPE_ATTENDANT,                        /**< ����Ա  */
    CALL_E_SERVICE_RIGHT_TYPE_SECRETARYSERVICE,                 /**< ����ҵ�� */
    CALL_E_SERVICE_RIGHT_TYPE_SECRETARYSTATIONSERVICE,          /**< ����̨ */
    CALL_E_SERVICE_RIGHT_TYPE_GROUPPICKUP,                      /**< ͬ����� */
    CALL_E_SERVICE_RIGHT_TYPE_DESIGNATEPICKUP,                  /**< ָ������ */
    CALL_E_SERVICE_RIGHT_TYPE_ACB,                              /**< �Զ��ؽ�ҵ�� */
    CALL_E_SERVICE_RIGHT_TYPE_RECORDING,                        /**< ��¼���� */
    
    CALL_E_SERVICE_RIGHT_TYPE_CALLTRANSFER,                     /**< ����ת�� */
    CALL_E_SERVICE_RIGHT_TYPE_CALLPARK,                         /**< ����Ԥ�� */
    CALL_E_SERVICE_RIGHT_TYPE_CALLHOLD,                         /**< ���б��� */
    CALL_E_SERVICE_RIGHT_TYPE_DONOTDISTURB,                     /**< ����� */
    CALL_E_SERVICE_RIGHT_TYPE_THREEPARTYCONFERENCE,             /**< ����ͨ�� */
    CALL_E_SERVICE_RIGHT_TYPE_CALLFORWARDING_UNCONDITIONAL,     /**< ������ת�� */
    CALL_E_SERVICE_RIGHT_TYPE_CALLFORWARDING_ONBUSY,            /**< ��æת�� */
    CALL_E_SERVICE_RIGHT_TYPE_CALLFORWARDING_NOREPLY,           /**< ��Ӧ��ת�� */
    CALL_E_SERVICE_RIGHT_TYPE_CALLFORWARDING_OFFLINE,           /**< ����ת�� */
    CALL_E_SERVICE_RIGHT_TYPE_CALLFORWARDINGTOVOICEMAILBOX_UNCONDITIONAL, /**< ������ת�������� */
    
    CALL_E_SERVICE_RIGHT_TYPE_CALLFORWARDINGTOVOICEMAILBOX_ONBUSY, /**< ��æת�������� */
    CALL_E_SERVICE_RIGHT_TYPE_CALLFORWARDINGTOVOICEMAILBOX_NOREPLY,/**< ��Ӧ��ת�������� */
    CALL_E_SERVICE_RIGHT_TYPE_CALLFORWARDINGTOVOICEMAILBOX_OFFLINE,/**< ����ת�������� */
    CALL_E_SERVICE_RIGHT_TYPE_VOICECONFERENCE,                  /**< �������� */
    CALL_E_SERVICE_RIGHT_TYPE_CORPORATEDIRECTORY,               /**< ��ҵͨѶ¼ */
    CALL_E_SERVICE_RIGHT_TYPE_INDIVIDUALDIRECTORY,              /**< ����ͨѶ¼ */
    CALL_E_SERVICE_RIGHT_TYPE_TURNPHONE,                        /**< һ��ת�� */
    CALL_E_SERVICE_RIGHT_TYPE_VOICECALL,                        /**< ��Ƶͨ������ */
    CALL_E_SERVICE_RIGHT_TYPE_EXTENSIONMOBILITY,                /**< �ֻ�Я��,AA�����ͣ�WEB���޸� */
    CALL_E_SERVICE_RIGHT_TYPE_SUBREGSTATE,                      /**< �ֻ�Я��ʱ����ҵ��Ȩ��,AA�����ͣ�WEB���޸� */
    
    CALL_E_SERVICE_RIGHT_TYPE_BLF,                              /**< BLF, AA�����ͣ�WEB���޸� */
    CALL_E_SERVICE_RIGHT_TYPE_PRESENCE,                         /**< ״̬���� */
    CALL_E_SERVICE_RIGHT_TYPE_INTERCOM,                         /**< intercomҵ�� */
    CALL_E_SERVICE_RIGHT_TYPE_DICF,                             /**< �ܾ�ǰת���� */
    CALL_E_SERVICE_RIGHT_TYPE_ABSENT,                           /**< ȱϯҵ�� */
    CALL_E_SERVICE_RIGHT_TYPE_TURN_VM,                          /**< һ��ת��������*/
    CALL_E_SERVICE_RIGHT_TYPE_HOT_LINE,                         /**< ����ҵ�� */
    CALL_E_SERVICE_RIGHT_TYPE_MCID,                             /**< ������и� */
    CALL_E_SERVICE_RIGHT_TYPE_CALL_LIMIT,                       /**< �����޺� */
    CALL_E_SERVICE_RIGHT_TYPE_CALL_WAIT,                        /**< ���еȴ� */

    CALL_E_SERVICE_RIGHT_TYPE_VVM,                              /**< ���ӻ��������� */
    CALL_E_SERVICE_RIGHT_TYPE_BARGE,                            /**< ǿ��*/
    CALL_E_SERVICE_RIGHT_TYPE_LBS,                              /**< LBS*/
    CALL_E_SERVICE_RIGHT_TYPE_PRIVACY,                          /**< privacyҵ�� */
    CALL_E_SERVICE_RIGHT_TYPE_HOLD_PRIVATE,                     /**< ˽�˱���ҵ�� */
    CALL_E_SERVICE_RIGHT_TYPE_BRIDGE,                           /**< bridgeҵ�� */
    CALL_E_SERVICE_RIGHT_TYPE_RESUME,                           /**< resumeҵ�� */
    CALL_E_SERVICE_RIGHT_TYPE_VOICE_MAIL,                       /**< �������� */
    CALL_E_SERVICE_RIGHT_TYPE_HUNTGROUP,                        /**< huntgroupȨ�� */
    CALL_E_SERVICE_RIGHT_TYPE_VIRTUALVM,                        /**< ������������ */
    
    CALL_E_SERVICE_RIGHT_TYPE_UC2X_VOICECONFERENCE,             /**< UC2.X�������� */

    CALL_E_SERVICE_RIGHT_TYPE_BUTT
} CALL_E_SERVICE_RIGHT_TYPE;


/**
 * �����ź���ö��
 */
typedef enum  enumAUDIO_CompoundVoice
{
    COMPOUND_E_NONE   = 0,  /**< ���ź��� */
    COMPOUND_E_BUSY,        /**< æ�� */    
    COMPOUND_E_BACK,        /**< ������ */
    COMPOUND_E_DIAL,        /**< ������ */
    COMPOUND_E_WAIT,        /**< ������ */
    COMPOUND_E_TIP,         /**< ��ʾ�� */
    COMPOUND_E_WARN,        /**< ������ */
    COMPOUND_E_LEAVE,       /**< �᳡�뿪�� */
    COMPOUND_E_UFWD,        /**< ������ǰת���Ⲧ���� */

    COMPOUND_E_DTMF0,       /**< dtmf����0 */
    COMPOUND_E_DTMF1,       /**< dtmf����1 */
    COMPOUND_E_DTMF2,       /**< dtmf����2 */
    COMPOUND_E_DTMF3,       /**< dtmf����3 */
    COMPOUND_E_DTMF4,       /**< dtmf����4 */
    COMPOUND_E_DTMF5,       /**< dtmf����5 */
    COMPOUND_E_DTMF6,       /**< dtmf����6 */
    COMPOUND_E_DTMF7,       /**< dtmf����7 */
    COMPOUND_E_DTMF8,       /**< dtmf����8 */
    COMPOUND_E_DTMF9,       /**< dtmf����9 */ 
    COMPOUND_E_DTMFSTAR,    /**< dtmf����'*' */
    COMPOUND_E_DTMFJIN,     /**< dtmf����'#' */
    COMPOUND_E_DTMFA,       /**< dtmf����A */
    COMPOUND_E_DTMFB,       /**< dtmf����B */
    COMPOUND_E_DTMFC,       /**< dtmf����C */
    COMPOUND_E_DTMFD,       /**< dtmf����D */
    COMPOUND_E_DTMFFLASH,   /**< dtmf����FLASH */
    
    COMPOUND_E_BUTT
}AUDIO_E_COMPOUNT_VOICE;


/**
 * ��Ƶ��������
 */
typedef enum tagCALL_E_AUDIO_CAP
{
    CALL_E_AUDIO_CAP_AACLD = 0,  /**< AAC-LD  */
    CALL_E_AUDIO_CAP_G722,       /**< G722  */
    CALL_E_AUDIO_CAP_G7221,      /**< G722.1  */
    CALL_E_AUDIO_CAP_G7222,      /**< G722.2  */
    CALL_E_AUDIO_CAP_G711A,      /**< G711A  */
    CALL_E_AUDIO_CAP_G711U,      /**< G711U  */
    CALL_E_AUDIO_CAP_G729AB,     /**< G729AB  */
    CALL_E_AUDIO_CAP_G726,       /**< G726  */
    CALL_E_AUDIO_CAP_ILBC,       /**< ILBC  */
    CALL_E_AUDIO_CAP_OPUS,       /**< OPUS  */
    CALL_E_AUDIO_CAP_DTMF,       /**< DTMF  */
    
    CALL_E_AUDIO_CAP_BUTT
}CALL_E_AUDIO_CAP;


/** 
 * ��ƵЭ������
 */
typedef enum tagCALL_E_VIDEO_CAP
{
    CALL_E_VIDEO_CAP_H264 = 0,   /**< H264 */
    CALL_E_VIDEO_CAP_H263,       /**< H264 */
    
    CALL_E_VIDEO_CAP_BUTT
}CALL_E_VIDEO_CAP;


/** 
 * DTMF ����ģʽ
 */
typedef enum
{
    CALL_E_DTMF_MODE_TRANSPARENT = 0,   /**< ͸��ģʽ */
    CALL_E_DTMF_MODE_RFC2833,           /**< RFC2833ģʽ(�Զ�Э��) */
    CALL_E_DTMF_MODE_CONST2833,         /**< ǿ��2833ģʽ */
    CALL_E_DTMF_MODE_INFO,              /**< INFOģʽ */  
    
    CALL_E_DTMF_MODE_BUTT
}CALL_E_DTMF_MODE;


/** 
 * �����¼�����
 */
typedef enum tagCALL_E_NET_EVT_TYPE
{
    CALL_E_NET_EVENT_CONNECTED,         /**< ���ӳɹ� */
    CALL_E_NET_EVENT_CONNECTFAIL,       /**< ����ʧ�� */
    CALL_E_NET_EVENT_LINKUP,            /**< ���� UP */
    CALL_E_NET_EVENT_LINKDOWN,          /**< ���� DOWN */

    CALL_E_NET_EVENT_BUTT
}CALL_E_NET_EVT_TYPE;


/** 
 * ��Ʒ����
 */
typedef enum tagCALL_E_PRODUCT_TYPE
{
    CALL_E_PRODUCT_TYPE_PHONE = 0,      /**< IP Phone */
    CALL_E_PRODUCT_TYPE_PC,             /**< PC */
    CALL_E_PRODUCT_TYPE_MOBILE,         /**< Mobile */
    
    CALL_E_PRODUCT_TYPE_BUTT
}CALL_E_PRODUCT_TYPE;


/**
 * ��Ƶ��������豸����(���ն�ʹ��)
 */
typedef enum tagCALL_E_AO_DEV
{
    CALL_E_AO_DEV_SPEAKER = 0,          /**< ������ */
    CALL_E_AO_DEV_BLUETOOTH,            /**< ������� */
    CALL_E_AO_DEV_EARPIECE,             /**< �ֱ���� */
    CALL_E_AO_DEV_HEADSET,              /**< 3.5mm������� */
    CALL_E_AO_DEV_HDMI,                 /**< HDMI��� */
    CALL_E_AO_DEV_USB,                  /**< USB��� */
    CALL_E_AO_DEV_SPEAKERRING,          /**< ����������(��ȡ����ֵʱ���õ�) */
    CALL_E_AO_DEV_BLUETOOTHRING,        /**< �����������(��ȡ����ֵʱ���õ�) */
    CALL_E_AO_DEV_HDMIRING,             /**< �ֱ���� */
    CALL_E_AO_DEV_USBRING,              /**< USB�������(��ȡ����ֵʱ���õ�) */
    
    CALL_E_AO_DEV_BUTT                  /**< ��Чֵ */
} CALL_E_AO_DEV;


/**
 * ��Ƶ��������豸����
 */
typedef enum tagCALL_E_AUDDEV_ROUTE
{
    CALL_E_AUD_DEV_ROUTE_DEFAULT     = 0x0,  /**< ����ֵ�����ò���Ч */
    CALL_E_AUD_DEV_ROUTE_LOUDSPEAKER = 0x1,  /**< ������ ��֧��������� */
    CALL_E_AUD_DEV_ROUTE_BLUETOOTH   = 0x2,  /**< �������� ��֧�����������֧���������豸ʹ�ã����ֻ���IP���� */
    CALL_E_AUD_DEV_ROUTE_EARPIECE    = 0x3,  /**< ��Ͳ �ֱ��豸��֧�����������IP����ʹ�� */
    CALL_E_AUD_DEV_ROUTE_HEADSET     = 0x4,  /**< 3.5���׶��� ��֧�����������֧��3.5���׶������豸ʹ�ã����ֻ���IP���� */
    CALL_E_AUD_DEV_ROUTE_SUBDEFAULT  = 0x5,  /**< ����ֵ�����ò���Ч */
    CALL_E_AUD_DEV_ROUTE_HDMI        = 0x6,  /**< HDMI,֧�������IP�����������������豸ʹ�� */
    CALL_E_AUD_DEV_ROUTE_USB         = 0x7,  /**< USB���� ��֧�����������IP����ʹ�� */
    CALL_E_AUD_DEV_ROUTE_MAX         = 0X8   /**< ��Чֵ */
} CALL_E_AUDDEV_ROUTE;


/**
 * ����ģʽ
 */
typedef enum tagCALL_E_REG_FAILOVER_MODE{
    CALL_E_REG_FAILOVER_MODE_REGMASTER,     /**< �������Ⱥ�ע�ᣬA-S */
    CALL_E_REG_FAILOVER_MODE_REGALL,        /**< ������ͬʱע��, A-A */
    
    CALL_E_REG_FAILOVER_MODE_BUTT
}CALL_E_REG_FAILOVER_MODE;


/**
 * ������������
 */
typedef enum tagCALL_E_NET_ENVIRONMENT
{
    CALL_E_NET_UC1X = 0,        /**< UC1.0����*/
    CALL_E_NET_UC2X,            /**< UC2.0����*/
    CALL_E_NET_OTHERS,          /**< ���������������ϰ汾��Ϊ2 */
    CALL_E_NET_ASTERISK,        /**< Asterisk����*/
    CALL_E_NET_BROADSOFT,       /**< Broadsoft����*/
    CALL_E_NET_IPCC,            /**< IPCC����  */
    CALL_E_NET_IMSUC_MIX,       /**< IMS+UC */
    CALL_E_NET_TE,              /**< ���� */
    CALL_E_NETWORK_HUAWEIUC,    /**< ��ΪUC*/
    CALL_E_NET_IMS,             /**< IMS���� */
    
    CALL_E_NET_BUTT
} CALL_E_NET_ENVIRONMENT;


/**
 * IPЭ������
 */
typedef enum tagCALL_E_IP_PROTOCOL_TYPE
{
    CALL_E_IP_V4 = 0,          /**< IP V4 */
    CALL_E_IP_V6,              /**< IP V6 */
}CALL_E_IP_PROTOCOL_TYPE;


/**
 * ҵ��Ȩ��״̬
 */
typedef enum tagCALL_E_SEVICERIGHT_STATUS
{
    CALL_E_SEVICERIGHT_LACK = 0,  /**< ûȨ�� */
    CALL_E_SEVICERIGHT_HAVE       /**< ��Ȩ�� */
} CALL_E_SEVICERIGHT_STATUS;


/**
 * ��������������
 */
typedef enum tagCALL_E_SERVERCONF_TYPE
{
    CALL_E_SERVERCONF_AUDIO = 1,  /**< �᳡���ͣ����� */
    CALL_E_SERVERCONF_DATA  = 3   /**< �᳡���ͣ�����+���� */
} CALL_E_SERVERCONF_TYPE;


/**
 * ����������ģʽ
 */
typedef enum tagCALL_E_CONF_MODE
{
    CALL_E_CONF_MODE_NOMAL = 0,         /**< �������� */
    CALL_E_CONF_MODE_VIDEO,             /**< ��Ƶ����*/
    CALL_E_CONF_MODE_PRESECE_VOICE,     /**< ������������*/
    CALL_E_CONF_MODE_PRESECE_VIDEO,     /**< ������Ƶ����*/
    CALL_E_CONF_MODE_LINKAGE,           /**< �������� */
    
    CALL_E_CONF_MODE_BUTT
}CALL_E_CONF_MODE;


/**
 * ��ƵԤ��ý������
 */
typedef enum tagCALL_E_REFRESHVIEW_MIDEATYPE
{
    CALL_E_REFRESHVIEW_VIDEO_PREVIEW = 1,   /**< ������ƵԤ�� */
    CALL_E_REFRESHVIEW_VIDEO = 2,           /**< ��ͨ��Ƶ */
    CALL_E_REFRESHVIEW_DATA = 3             /**< ���� */
} CALL_E_REFRESHVIEW_MIDEATYPE;


/**
 * ����ɹ�����Ƶý������
 */
typedef enum tagCALL_E_DECODE_SUCCESS_MIDEATYPE
{
    CALL_E_DECODE_SUCCESS_VIDEO = 2,        /**< ��ͨ��Ƶ */
    CALL_E_DECODE_SUCCESS_DATA = 3          /**< ���� */
} CALL_E_DECODE_SUCCESS_MIDEATYPE;


/**
 * ý������
 */
typedef enum tagCALL_E_MEDIATYPE
{
    CALL_E_MEDIATYPE_AUDIO, /**< ��Ƶ */
    CALL_E_MEDIATYPE_VIDEO, /**< ��ͨ��Ƶ */
    CALL_E_MEDIATYPE_DATA   /**< ���� */
} CALL_E_MEDIATYPE;


/**
 * ��Ƶˢ���¼�
 */
typedef enum tagCALL_E_REFRESHVIEW_EVENT
{
    CALL_E_LOCALVIEW_ADD = 1,     /**< ����view��� */
    CALL_E_LOCALVIEW_REMOVE       /**< ����viewɾ�� */
} CALL_E_REFRESHVIEW_EVENT;


/**
 * ��������
 */
typedef enum tagCALL_E_URI_PARAMTYPE
{
    CALL_E_URI_PARAM_NORAML,                /**< ��ͨ���� */
    CALL_E_URI_PARAM_INTERCOM,              /**< �Խ������� */
    CALL_E_URI_PARAM_PAGING,                /**< Paging���� */
    CALL_E_URI_PARAM_APPEARANCE_PRIVATE,    /**< ˽�˺������� */
    CALL_E_URI_PARAM_BUTT
}CALL_E_URI_PARAMTYPE;


/**
 * ��Ƶ��������
 */
typedef enum tagCALL_E_VIDEOWND_TYPE
{
    CALL_E_VIDEOWND_CALLREMOTE = 0,         /**< ͨ��Զ�˴��� */
    CALL_E_VIDEOWND_CALLLOCAL,              /**< ͨ�����ش��� */
    CALL_E_VIDEOWND_PREVIEW,                /**< Ԥ������ */
    CALL_E_VIDEOWND_CALLDATA,               /**< �������� */
    CALL_E_VIDEOWND_BUTT
} CALL_E_VIDEOWND_TYPE;


/**
 * ��������
 */
typedef enum tagCALL_E_COORDINATE_TYPE
{
    CALL_E_COORDINATE_X = 0,               /**< X �� */
    CALL_E_COORDINATE_Y,                   /**< Y �� */
    CALL_E_COORDINATE_W,                   /**< �� */
    CALL_E_COORDINATE_H,                   /**< �� */
    CALL_E_COORDINATE_Z,                   /**< Z �� */  
    CALL_E_COORDINATE_BUTT
} CALL_E_COORDINATE_TYPE;


/**
 * ��Ƶ������ʾ���ͣ�eSpace 8950ʹ��
 */
typedef enum tagCALL_E_VIDEOWND_DISPLAY_TYPE
{
    CALL_E_VIDEOWND_DISPLAY_ZOOM = 0,       /**< 0:���ֱ�������,�Ӻڱ�,Ĭ��Ϊ��ֵ */
    CALL_E_VIDEOWND_DISPLAY_CUT,            /**< 1:���ֱ�������,����ü�   */
    CALL_E_VIDEOWND_DISPLAY_FULL,           /**< 2:ȫ������,���Ӻڱߣ������ü�   */
    CALL_E_VIDEOWND_DISPLAY_BUTT
} CALL_E_VIDEOWND_DISPLAY_TYPE;


/**
 * ý�巢��ģʽ
 */
typedef enum tagCALL_E_MEDIA_SENDMODE
{
    CALL_E_MEDIA_SENDMODE_INACTIVE = 0x00,  /**< ���ղ��� */
    CALL_E_MEDIA_SENDMODE_SENDONLY = 0x01,  /**< ֻ�� */
    CALL_E_MEDIA_SENDMODE_RECVONLY = 0x02,  /**< ֻ�� */
    CALL_E_MEDIA_SENDMODE_SENDRECV = 0x04,  /**< �շ� */

    CALL_E_MEDIA_SENDMODE_INVALID  = 0x08   /**< ��Ч */
}CALL_E_MEDIA_SENDMODE;


/**
 * ��Ƶ���
 */
typedef enum tagCALL_E_VIDEO_MOD_RESULT
{
    CALL_E_VIDEO_MOD_NORMAL = 0,            /**< ��Ƶ������/�ر� */
    CALL_E_VIDEO_MOD_LOW_BW,                /**< �ɵʹ�����ɵ���Ƶ�л�����Ƶ */ 
    CALL_E_VIDEO_MOD_BUTT
}CALL_E_VIDEO_MOD_RESULT;


/**
 * ������
 */
typedef enum tagCALL_E_BANDWIDTH_LEVER
{
    CALL_E_BANDWIDTH_NORMAL,                /**< �������� */
    CALL_E_BANDWIDTH_LOWER,                 /**< �ʹ��� */
    CALL_E_BANDWIDTH_LOWEST
}CALL_E_BANDWIDTH_LEVER;



/**
 * �ƶ���Ƶ·���豸����
 */
typedef enum  tagCALL_E_MOBILE_AUIDO_ROUTE
{
    CALL_MBOILE_AUDIO_ROUTE_DEFAULT = 0,        /**< ��������>���߶���>��Ͳ */
    CALL_MOBILE_AUDIO_ROUTE_LOUDSPEAKER = 1,    /**< ������ */
    CALL_MOBILE_AUDIO_ROUTE_BLUETOOTH = 2,      /**< ���� */
    CALL_MOBILE_AUDIO_ROUTE_EARPIECE = 3,       /**< ��Ͳ�����ڻ�ȡ������ʱ���������ش��� */
    CALL_MOBILE_AUDIO_ROUTE_HEADSET = 4         /**< ���������ڻ�ȡ������ʱ���������ش��� */
}CALL_E_MOBILE_AUIDO_ROUTE;




/**
 * ��Ƶ����
 */
typedef struct tagCALL_S_VIDEOCONTROL
{
    TUP_UINT32 ulCallID;      /**< ����ID */
    TUP_UINT32 ulOperation;   /**< ������ȡֵ:
                                 <br>open 0x01��close 0x02��start 0x04��stop 0x08
                                 ����ʹ���߼������"|"���ӣ�open|start��close|stop */
    TUP_UINT32 ulModule;      /**< ģʽ��ȡֵ:
                                 <br>��ʾԶ�˴��� 0x01
                                 <br>��ʾ���˴��� 0x02
                                 <br>����ͷ       0x04
                                 <br>������       0x08
                                 <br>������       0x10*/
    TUP_BOOL bIsSync;         /**< true��ʾͬ��ִ�У�false��ʾ�첽ִ�С�ios8.3ʹ���첽���������к�̨ʱ���øýӿڻᱻϵͳѸ�ٹ����±������� */
}CALL_S_VIDEOCONTROL;



/** 
 * �˺�ע����
 */
typedef struct tagCALL_S_SIP_ACCOUNT_INFO
{
    TUP_UINT32 ulSipAccountID;                      /**< SIP�˻�ID */
    CALL_E_REG_STATE enRegState;                    /**< SIP�˻�ע��״̬ */
    TUP_UINT32 ulReasonCode;                        /**< ע��ʧ�ܵ�ԭ���� */
    TUP_INT8 acUserNum[CALL_D_MAX_USERNAME_LENGTH]; /**< SIP�˻��û��� */
    TUP_INT8 acTelNum[CALL_D_MAX_LENGTH_NUM];       /**< SIP�˻����� */
	TUP_INT8 acServer[CALL_D_MAX_SERVER_LENGTH];    /**< SIP��������Ϣ*/
} CALL_S_SIP_ACCOUNT_INFO;


/** 
 * ���в���
 */
typedef struct tagCALL_S_CALL_PARAMS
{
    TUP_UINT32 ulLineId;                        /**< ��·ID */
    TUP_UINT32 ulCallType;                      /**< �������� */
    TUP_UINT32 ulAccountId;                     /**< �˺�ID */
    TUP_UINT32 ulReserved;                      /**< �����ֶ� */
    TUP_UINT32 ulCallId;                        /**< ����ID, ��������������� */
    TUP_INT8 acTelNum1[CALL_D_MAX_LENGTH_NUM];  /**< �绰����, CTD���� */
    TUP_INT8 acTelNum2[CALL_D_MAX_LENGTH_NUM];  /**< �绰����, CTD�ý� */
    TUP_VOID* pReserved;                        /**< �����ֶ� */
}CALL_S_CALL_PARAMS;


/** 
 * ͨ��״̬��Ϣ
 */
typedef struct tagCALL_S_CALL_STATE_INFO
{
    TUP_UINT32 ulSipAccountID;                          /**< ͨ��������·ID */
    TUP_UINT32 ulCallID;                                /**< ͨ��ID */
    CALL_E_CALL_TYPE enCallType;                        /**< �������� */
    CALL_E_CALL_STATE enCallState;                      /**< ͨ��״̬ */
    TUP_INT8 acTelNum[CALL_D_MAX_LENGTH_NUM];           /**< ������� �� ��Ϊ����ʱ�ĺ������� */
    TUP_INT8 acDisplayName[CALL_D_MAX_DISPLAY_NAME];    /**< �������� */
    TUP_INT8 acDomainIp[CALL_D_MAX_DISPLAY_NAME];       /**< �������� or ip */
    TUP_UINT32 ulReasonCode;                            /**< ʧ��ԭ���룬@see tagCALL_E_REASON_CODE */ 
    TUP_BOOL bIsIn;                                     /**< ��ʶ��·ͨ���Ƿ�Ϊ���� */
    TUP_BOOL bIsPassiveEnd;                             /**< ��ʶ��·�����Ƿ�Զ�˹Ҷ� */
    CALL_E_CALL_ALERTTYPE enAlertType;                  /**< ������������ */
    TUP_BOOL bIsAccept;                                 /**< �����Ƿ��Ѿ�������־ */
    TUP_BOOL bIsTimeout;                                /**< ���г�ʱ��־��������¼���糬ʱδ�Ӽ�¼ */
    TUP_BOOL bIsInLocalConf;                            /**< ��־�Ƿ���뱾�ػ��� */
    TUP_BOOL bIsInBridgeConf;                           /**< ��ʶ�Ƿ��ǽ���bridge����״̬ */
    TUP_BOOL bCompletedElsewhere;                       /**< ��ʶ�Ƿ��ǲ��ü���δ������ı��������� */
    TUP_BOOL bIsAutoAnswer;                             /**< �����Ƿ��Զ�������־  */
    TUP_UINT32 ulAutoAnswerTime;                        /**< �����Զ�����ʱ�� */
    TUP_UINT32 ulCause;                                 /**< sip����cause�� */
    TUP_CHAR szPresetMsg[CALL_D_MAX_PRESET_MSG_LENGTH]; /**< Ԥ����Ϣ */
    TUP_BOOL bIsPaging;                                 /**< �Ƿ�Paging */
    TUP_BOOL bHaveSDP;                                  /**< �Ƿ����SDP */
}CALL_S_CALL_STATE_INFO;


/** 
 * ������Ϣ
 */
typedef struct tagCALL_S_CALL_INFO
{
    CALL_S_CALL_STATE_INFO stCallStateInfo;         /**< ͨ��״̬��Ϣ */

    CALL_E_URI_PARAMTYPE enUriType;                 /**< URI ���� */
    
    TUP_BOOL bIsFwdCallForbidden;                   /**< ������ָʾ��ֹ����ǰ��,���ڶԽ�BROADSOFT������ */
    TUP_BOOL bIsFwdCall;                            /**< �Ƿ�ǰת���� */
    TUP_INT8 acFwdFromNum[CALL_D_MAX_LENGTH_NUM];   /**< ǰת�ߺ��� */
    TUP_INT8 acFwdFromName[CALL_D_MAX_DISPLAY_NAME];/**< ǰת������ */

    TUP_INT8 acTelNumTel[CALL_D_MAX_LENGTH_NUM];    /**< ������� */
    TUP_INT8 acDisplayNameTel[CALL_D_MAX_LENGTH_NUM];/**< �������� */

    TUP_BOOL bIsShareLine;                          /**< �Ƿ����� */
    TUP_UINT32 ulSCALineID;                         /**< ��������·ID */
    TUP_UINT32 ulBossLineID;                        /**< �����߾�����·ID */
    TUP_BOOL   bIsReplace;                          /**< �Ƿ��滻��· */
    TUP_UINT32 ulReplaceID;                         /**< ��ѯת�����滻��ԭ����ID */
    TUP_CHAR acBossNum[CALL_D_MAX_LENGTH_NUM];      /**< �����߾������ */
    TUP_UINT32 ulRmtCtrl;                           /**< �Ƿ�Զ˿� */
    TUP_UINT32 ulSwitchId;                          /**< PC����һ���л��ĺ���ID */

    TUP_BOOL bIsFocus;                              /**< �Ƿ��isfoucs��ʶ���ƶ����鳡��ʹ��*/  
    TUP_INT8 acServerConfType[CALL_D_MAX_LENGTH_NUM];/**< �������ͣ��ƶ����鳡��ʹ��*/  
    TUP_INT8 acServerConfID[CALL_D_MAX_LENGTH_NUM]; /**< ����ID, �ƶ����鳡��ʹ��*/
    TUP_UINT32 ulOrientType;                        /**< �ƶ���Ƶ���������*/
    TUP_INT8 acLocalAddr[CALL_D_IP_LENGTH];         /**< �ƶ��ϱ����ص�ַ*/
    TUP_INT8 acRemoteAddr[CALL_D_IP_LENGTH];        /**< �ƶ��ϱ�Զ�˵�ַ*/
    TUP_INT8 acUserAgent[CALL_D_MAX_LENGTH_NUM];    /**< �Զ˵�UserAgent */
    CALL_E_MEDIA_SENDMODE enAudioSendMode;          /**< ��Ƶý�巽�� */
    CALL_E_MEDIA_SENDMODE enVideoSendMode;          /**< ��Ƶý�巽�� */
    CALL_E_MEDIA_SENDMODE enDataSendMode;           /**< ����ý�巽�� */

} CALL_S_CALL_INFO;


/** 
 * ��Ϣ֪ͨ��Ϣ����
 */
typedef struct tagCALL_S_MSG_INFO
{
    CALL_E_MSG_WAIT_TYPE enMsgType;                 /**< ���Ե����� */
    TUP_UINT32 ulNewMsgNum;                         /**< ����Ϣ���� */
    TUP_UINT32 ulOldMsgNum;                         /**< ����Ϣ���� */
    TUP_UINT32 ulNewEmgMsgNum;                      /**< �½�����Ϣ���� */
    TUP_UINT32 ulOldEmgMsgNum;                      /**< �ɽ�����Ϣ���� */
    TUP_CHAR   aszSubscriber[CALL_D_MAX_LENGTH_NUM];/**< �����ĺ��� */
} CALL_S_MSG_INFO;


/** 
 * ��������֪ͨ
 */
typedef struct tagCALL_S_MSG_WAIT_INFOS
{
    TUP_UINT32 ulMsgCnt;                                    /**< ��Ϣ���� */
    CALL_S_MSG_INFO astMsgInfos[CALL_D_MAX_MSGSUMMARY_NUM]; /**< ��Ϣ��Ϣ���� */
} CALL_S_MSG_WAIT_INFOS;


/** 
 * ����ͨ��MOS��Ϣ
 */
typedef struct tagCALL_CHANNEL_EMODEL_RESULT_STRU
{
    TUP_UINT8  ucSendMOSValidFlag;  /**< ���ͷ���MOS����Ч��־,��ͨ��δ�յ�RTCP RR����ʱ������4�����ͷ����MOS�ֲ�������Ч */
    TUP_UINT8  ucRecvMOSValidFlag;  /**< ���շ���MOS����Ч��־,��ͨ��δ�յ��κα��Ļ�δ�ﵽ��������(RTCP�������ڣ�5s)ʱ������4�����շ����MOS�ֲ�������Ч */
    TUP_UINT16 uwResv;              /**< ����λ����֤4�ֽڶ��� */

    TUP_FLOAT fSendAverageMosQ;     /**< ���ͷ���MOS��ƽ��ֵ,�ø�������ʾ:ȡֵ��Χ(0, 5], 0xFFFFFFFF��ʾ�ò�����Ч */
    TUP_FLOAT fSendMaxMosQ;         /**< ���ͷ���MOS�����ֵ,�ø�������ʾ:ȡֵ��Χ(0, 5], 0xFFFFFFFF��ʾ�ò�����Ч */
    TUP_FLOAT fSendMinMosQ;         /**< ���ͷ���MOS����Сֵ,�ø�������ʾ:ȡֵ��Χ(0, 5], 0xFFFFFFFF��ʾ�ò�����Ч */
    TUP_FLOAT fSendCurMosQ;         /**< ���ͷ���MOS�ֵ�ǰֵ,�ø�������ʾ:ȡֵ��Χ(0, 5], 0xFFFFFFFF��ʾ�ò�����Ч */

    TUP_FLOAT fRecvAverageMosQ;     /**< ���շ���MOS��ƽ��ֵ,�ø�������ʾ:ȡֵ��Χ(0, 5], 0xFFFFFFFF��ʾ�ò�����Ч */
    TUP_FLOAT fRecvMaxMosQ;         /**< ���շ���MOS�����ֵ,�ø�������ʾ:ȡֵ��Χ(0, 5], 0xFFFFFFFF��ʾ�ò�����Ч */
    TUP_FLOAT fRecvMinMosQ;         /**< ���շ���MOS����Сֵ,�ø�������ʾ:ȡֵ��Χ(0, 5], 0xFFFFFFFF��ʾ�ò�����Ч */
    TUP_FLOAT fRecvCurMosQ;         /**< ���շ���MOS�ֵ�ǰֵ,�ø�������ʾ:ȡֵ��Χ(0, 5], 0xFFFFFFFF��ʾ�ò�����Ч */
} CALL_CHANNEL_EMODEL_RESULT_STRU;


/** 
 * ��Ƶͨ����Ϣ
 */
typedef struct tagCALL_S_AUDIO_STREAM_INFO
{
    TUP_BOOL bIsCalling;                                /**< �Ƿ���ͨ����*/
    TUP_INT8 bIsSRTP;                                   /**< �Ƿ�����SRTP MEDIASERVICE_TRANS_SRTP*/
    TUP_INT8 acEncodeProtocol[CALL_D_PROTOCOL_LENGTH];  /**< ����Э��*/
    TUP_INT8 acDecodeProtocol[CALL_D_PROTOCOL_LENGTH];  /**< ����Э��*/
    TUP_UINT32 ulChannelID;                             /**< ͨ��ID */
    TUP_UINT32 ulSendBitRate;                           /**< ���ͱ����� */
    TUP_UINT32 ulRecvBitRate;                           /**< ���ձ����� */
    TUP_UINT32 ulSendTotalLostPacket;                   /**< ���ͷ��ۼư��� */
    TUP_FLOAT fSendLossFraction;                        /**< ���ͷ�������(%) */
    TUP_FLOAT fSendNetLossFraction;                     /**< ���ͷ����綪����(%) */
    TUP_FLOAT fSendJitter;                              /**< ���ͷ�ƽ������(ms) */
    TUP_FLOAT fSendDelay;                               /**< ���ͷ�ƽ��ʱ��(ms) */
    TUP_UINT32 ulRecvTotalLostPacket;                   /**< ���շ��ۼư��� */
    TUP_FLOAT fRecvLossFraction;                        /**< ���շ�������(%) */
    TUP_FLOAT fRecvNetLossFraction;                     /**< ���շ�������(%) */
    TUP_FLOAT fRecvJitter;                              /**< ���շ�ƽ������(ms) */
    TUP_FLOAT fRecvDelay;                               /**< ���շ�ƽ��ʱ��(ms) */
    CALL_CHANNEL_EMODEL_RESULT_STRU stMosResult;        /**< ����mosֵ */
} CALL_S_AUDIO_STREAM_INFO, *CALL_S_AUDIO_STREAM_INFO_PTR;


/** 
 * ��Ƶͨ����Ϣ
 */
typedef struct tagCALL_S_VIDEO_STREAM_INFO
{
    TUP_INT8 acEncodeName[CALL_MAX_CODEC_NAME_LEN];     /**< ��������*/
    TUP_INT8 acDecodeName[CALL_MAX_CODEC_NAME_LEN];     /**< ��������*/
    TUP_INT8 acEncoderSize[CALL_MAX_FRAMESIZE_LEN];     /**< ͼ��ֱ���(����)*/
    TUP_INT8 acDecoderSize[CALL_MAX_FRAMESIZE_LEN];     /**< ͼ��ֱ���(����)*/
    TUP_INT8 bIsSRTP;                                   /**< �Ƿ�����SRTP,��ӦMEDIASERVICE_TRANS_SRTP*/
    TUP_UINT32 ulSendFrameRate;                         /**< ��Ƶ֡��(����)*/
    TUP_UINT32 ulRecvFrameRate;                         /**< ��Ƶ֡��(����)*/
    TUP_UINT32 ulVideoSendBitRate;                      /**< ��������*/
    TUP_UINT32 ulVideoRecvBitRate;                      /**< ��������*/
    TUP_INT8 acEncoderProfile[CALL_MAX_PROFILE_LEN];    /**< ��Ƶ�����ʽ*/
    TUP_INT8 acDecoderProfile[CALL_MAX_PROFILE_LEN];    /**< ��Ƶ�����ʽ*/
    TUP_FLOAT fVideoSendLossFraction;                   /**< ���ͷ�������(%) */
    TUP_FLOAT fVideoSendJitter;                         /**< ���ͷ�ƽ������(ms) */
    TUP_FLOAT fVideoSendDelay;                          /**< ���ͷ�ƽ��ʱ��(ms) */
    TUP_FLOAT fVideoRecvLossFraction;                   /**< ���շ�������(%) */
    TUP_FLOAT fVideoRecvJitter;                         /**< ���շ�ƽ������(ms) */
    TUP_FLOAT fVideoRecvDelay;                          /**< ���շ�ƽ��ʱ��(ms) */
    TUP_UINT32 ulWidth;                                 /**< ��Ƶ�ֱ���-��*/
    TUP_UINT32 ulHeight;                                /**< ��Ƶ�ֱ���-��*/
    
} CALL_S_VIDEO_STREAM_INFO, *CALL_S_VIDEO_STREAM_INFO_PTR;


/** 
 * �Ựý��ͨ��(��Ƶ+��Ƶ)��Ϣ
 */
typedef struct tagCALL_S_MEDIA_STREAM_INFO
{
    TUP_UINT32 uiCt;                                    /**< �Ự������ ct */
    TUP_CHAR szAudioCodec[CALL_D_MAX_CODEC_LIST_LEN+1]; /**< �ỰЭ�̳�����֧�ֵ���Ƶ������б� "G722,PCMA,PCMU,G729,iLBC,telephone-event,red"*/
    TUP_CHAR szVideoCodec[CALL_D_MAX_CODEC_LIST_LEN+1]; /**< �ỰЭ�̳�����֧�ֵ���Ƶ������б� Ԥ��*/
}CALL_S_MEDIA_STREAM_INFO, *CALL_S_MEDIA_STREAM_INFO_PTR;


/**
* �Ự��Ϣ
*/
typedef struct tagCALL_S_STREAM_INFO
{
    CALL_S_MEDIA_STREAM_INFO stMediaStreamInfo;         /**< �Ự����Ϣ*/
    CALL_S_AUDIO_STREAM_INFO stAudioStreamInfo;         /**< ��Ƶ����Ϣ*/
    CALL_S_VIDEO_STREAM_INFO stVideoStreamInfo;         /**< ��Ƶ����Ϣ*/
    CALL_S_VIDEO_STREAM_INFO stDataStreamInfo;          /**< ������Ϣ*/
    TUP_BOOL bIsIn;                                     /**< ��ʶ��·ͨ���Ƿ�Ϊ���� */
    TUP_BOOL bIsEndCall;                                /**< ��ʶ�Ƿ�Ϊ�����ϱ� */
    TUP_CHAR acLocalIP[CALL_D_IP_LENGTH];               /**< ����IP*/
    TUP_CHAR acRemoteNum[CALL_D_MAX_LENGTH_NUM];        /**< Զ�˺���*/
    TUP_CHAR acLocalNum[CALL_D_MAX_LENGTH_NUM];         /**< ���˺���*/
} CALL_S_STREAM_INFO, *CALL_S_STREAM_INFO_PTR;


/**
* �����ߺ�����Ϣ
*/
typedef struct tagCALL_S_SCA_CALL_INFO
{
    TUP_BOOL bIsShareLine;                              /**< �Ƿ����� */
    TUP_UINT32 ulSCALineID;                             /**< ��������·ID */
    TUP_UINT32 ulBossLineID;                            /**< �����߾�����·ID */
    TUP_CHAR acBossNum[CALL_D_MAX_LENGTH_NUM];          /**< �����߾������ */
} CALL_S_SCA_CALL_INFO;


/**
* ������Ϣ
*/
typedef struct tagCALL_S_CONF_INFO
{
    TUP_UINT32 ulConfID;                                /**< ������ƿ�ID  */               
    CALL_E_SERVERCONF_TYPE eConfType;                   /**< �������᳡���� */
    TUP_UINT32 ulCallID;                                /**< ���п��ƿ�ID */  
    TUP_UINT32 ulSipAccountID;                          /**< �û��˺�ID  */
    
    TUP_INT8 acUserNumber[CALL_D_MAX_LENGTH_NUM];       /**< Զ���û����� */
    TUP_INT8 aszRemoteDisplayName[CALL_D_MAX_LENGTH_NUM ]; /**< Զ���û���ʾ�ǳ� */
    
    TUP_INT8 aszRemoteUserIDTel[CALL_D_MAX_LENGTH_NUM]; /**< Զ���û����룬
                                                            <br>����ʹ�ã�ƥ��ɳ��ATS���������ں�����ʾ������PAI�еĵڶ���URI��Ĭ��ΪTEL��  */
	TUP_INT8 aszRemoteDisplayNameTel[CALL_D_MAX_LENGTH_NUM ]; /**< Զ���û���ʾ�ǳƣ�
	                                                        <br>����ʹ�ã�ƥ��ɳ��ATS���������ں�����ʾ������PAI�еĵڶ���URI��Ĭ��ΪTEL��  */
	
    TUP_INT8 acGroupUri[CALL_D_MAX_LENGTH_NUM];         /**< Ⱥ��URI */
    TUP_INT8 acConfIndex[CALL_D_MAX_LENGTH_NUM];        /**< �������� */
    TUP_UINT32 ulSvrAutoAnswer;                         /**< �������Ƿ�ָʾ�Զ����� */
    TUP_UINT32 ulSvrAutoAnswerTime;
    CALL_S_SCA_CALL_INFO stScaCallInfo;                 /**< ����������Ϣ�������ڻ��������ʱ���ϱ� */
    CALL_E_CONF_MODE eConfMode;                         /**< ����ģʽ:�ںϻ��顢UC���� */
    CALL_E_CALL_TYPE eCallType;                         /**< ��������:��Ƶ����Ƶ */
} CALL_S_CONF_INFO;


/**
 * �᳡�������
 */
typedef struct tagCALL_S_CONF_CREATE_RESULT
{
    TUP_UINT32 ulConfID;                                /**< ������ƿ�ID */
    TUP_UINT32 ulResult;                                /**< ������ */
    CALL_E_SERVERCONF_TYPE eConfType;                   /**< �������᳡���� */
    TUP_CHAR acPasscode[CALL_D_PASSCODE_LENGTH];        /**< ��������� */
} CALL_S_CONF_CREATE_RESULT;


/**
 * ���ݻ��������ز���
 */
typedef struct tagCALL_S_DATACONF_PARAM
{
    TUP_UINT32          ulConfID;                                   /**< ���鱾�ؿ���id*/
    TUP_UINT32          ulCallID;                                   /**< ��Ӧ�ĺ���ID */
    CALL_E_CONF_ROLE    enRole;                                     /**< �����û������н�ɫ*/
    TUP_CHAR            acDataConfID[CALL_D_DATACONF_PARAM_LENGTH]; /**< �������᳡id */
    TUP_CHAR            acAuthKey[CALL_D_DATACONF_PARAM_LENGTH];    /**< �᳡��Ȩ�� */
    TUP_CHAR            acPassCode[CALL_D_MAX_LENGTH_NUM];          /**< ��������� */
    TUP_CHAR            acCmAddr[CALL_D_DATACONF_CMADDR_LENGTH];    /**< ���ܵ�ַ���˿�*/
    TUP_CHAR            acGroupUri[CALL_D_MAX_LENGTH_NUM];          /**< Ⱥ��URI */    
    TUP_CHAR            acExtConfType[CALL_D_CONF_TYPE_MAX_LEN];    /**< ��������, ��󳤶�20 */
    TUP_CHAR            acCharman[CALL_D_DATACONF_PARAM_LENGTH];    /**< ������UC����*/
    TUP_CHAR            bP2PDataConf;                               /**< �Ƿ��Ե����ݻ��� */
} CALL_S_DATACONF_PARAM;


/**
 * �������Ϣ
 */
typedef struct tagCALL_S_CONF_MEMBER
{
    TUP_CHAR acAttendeeNumber[CALL_D_MAX_LENGTH_NUM];               /**< ���� */
    TUP_CHAR acAttendeeFullNumber[CALL_D_MAX_LENGTH_NUM];           /**< ����߳� ���� */
    CALL_E_CONF_ROLE enRole;                                        /**< ��ɫ */
    CALL_E_CONF_ATTENDEE_TYPE enAttendeeType;                       /**< ���������*/
    CALL_E_CONF_ATTENDEE_STATE enState;                             /**< ״̬ */
    TUP_UINT32 ulRight;                                             /**< ����Ȩ  1��  0��  */
    TUP_UINT32 ulAttendeeID;                                        /**< �����ID , ����ָ��ʹ���ĸ����� */
    TUP_CHAR acLinkDesktop[CALL_D_CONF_LINK_NUM_LENGTH];            /**< USM�£�����PC���� */
    TUP_CHAR acLinkIPPhone[CALL_D_CONF_LINK_NUM_LENGTH];            /**< USM�£������������� */
} CALL_S_CONF_MEMBER;


/**
 * ��������Ϣ 
 */
typedef struct tagCALL_S_CONF_SPEAKER
{
    TUP_CHAR acFirstSpeakMem[CALL_D_MAX_LENGTH_NUM];        /**< ������һ�����˺��� */
    TUP_CHAR acSecondSpeakMem[CALL_D_MAX_LENGTH_NUM];       /**< �����ڶ������˺��� */
} CALL_S_CONF_SPEAKER;


/**
 * ��Ƶ�޸Ľ�� 
 */
typedef struct tagCALL_S_MODIFY_VIDEO_RESULT
{
    TUP_UINT32 ulCallID;                          /**< ����ID */
    TUP_UINT32 ulResult;                          /**< ��� */
    TUP_BOOL  bIsVideo;                           /**< �Ƿ���Ƶ */
    TUP_UINT32 ulOrientType;                      /**< ��Ƶ�����������0: �豸Ĭ��ֵ 1��������2��������3��������� */
    CALL_E_VIDEO_MOD_RESULT enVideoModRes;        /**< ��Ƶ������� */
}CALL_S_MODIFY_VIDEO_RESULT;


/**
 * ��Ƶ������Ϣ
 */
typedef struct tagCALL_S_VIDEOWND_INFO
{
    TUP_UINT32 ulVideoWndType;                      /**< ��Ƶ��������:CALL_E_VIDEOWND_TYPE */
    TUP_INT32 ucCoordinate[CALL_E_COORDINATE_BUTT]; /**< ������Ϣ X1,Y1,w,h,Z*/
    TUP_UPTR ulRender;                              /**< ���ھ��*/
    TUP_INT32 ulIndex;                              /**< �������*/
    TUP_UINT32 ulSessionID;                         /**< ����Ԥ��sessionֵ*/
    TUP_UINT32 ulRefCount;                          /**< ʹ�����ü���*/
    TUP_UINT32 ulDisplayType;                       /**< ��ʾģʽ(8950��ö������CALL_E_VIDEOWND_DISPLAY_TYPE��������Ʒ��ֱ�Ӹ�ֵ 0:����ģʽ 1:(������)�ڱ�ģʽ 2:(������)�ü�ģʽ)*/
    TUP_CHAR  acStartImage[CALL_D_MAX_LENGTH_NUM];  /**< ��Ƶ��ʾ��ʼͼ�񣬱���Ϊjpegͼ���ҳ�����8�ı���*/
} CALL_S_VIDEOWND_INFO, CALL_S_VIDEOCONFWND_INFO;


/**
 * UPORTAL TOKEN ˢ����Ϣ��Ӳ�ն�ʹ��
 */
typedef struct tagCALL_S_UPORTAL_TOKEN_REFRESH_INFO
{
    TUP_CHAR acToken[CALL_D_MAX_TOKEN_LENGTH];          /**< tokenֵ */
    TUP_CHAR acEabServer[CALL_D_MAX_SERVER_LENGTH];     /**< ��ҵͨѶ¼server */
    TUP_CHAR acGroupServer[CALL_D_MAX_SERVER_LENGTH];   /**< ͷ������� */
    TUP_CHAR acUsername[CALL_D_MAX_USERNAME_LENGTH];    /**< �û��� */
    TUP_UINT32 ulExpire;                                /**< �ϻ�ʱ�� */
}CALL_S_UPORTAL_TOKEN_REFRESH_INFO;


/**
 * ��Ƶ���ڿ�������
 */
typedef enum tagCALL_E_VIDEOWND_CTRL_TYPE
{
    CALL_E_VIDEOWND_MOVE,           /**< �����ƶ�����Z��ı�����ͨ���ı�Z�� */
    CALL_E_VIDEOWND_CLOSE,          /**< ���ڹر�  */
    CALL_E_VIDEOWND_ZOOM,           /**< ��������  */
    CALL_E_VIDEOWND_DISPLAYTYPE,    /**< ��ʾģʽ  */
    CALL_E_VIDEOWND_CTRL_BUTT
} CALL_E_VIDEOWND_CTRL_TYPE;


/**
 * ���ô���
 */
typedef enum tagCALL_E_CFG_MAJOR_TYPE
{
    CALL_E_CFG_CALLENV = 1,     /**< �������� */
    CALL_E_CFG_SERVER,          /**< ��������ַ */
    CALL_E_CFG_NET,             /**< ��������ӿڵ�ַ */
    CALL_E_CFG_USERAGENT,       /**< �û����� */
    CALL_E_CFG_SERVRIGHT,       /**< ҵ��Ȩ�� */
    CALL_E_CFG_DSCP,            /**< DSCP */    
    CALL_E_CFG_SIP,             /**< SIP�������� */
    CALL_E_CFG_SIPGLOBAL,       /*<  SIP �Ի���INFO��������*/
    CALL_E_CFG_ACCOUNT,         /**< �˺� */
    CALL_E_CFG_COMPATIBLE_PARAM,/**< �˺� */
    CALL_E_CFG_CONF,            /**< �����������*/
    CALL_E_CFG_MEDIA,           /**< ý��ȫ������*/
    CALL_E_CFG_AUDIO,           /**< ��Ƶ����*/
    CALL_E_CFG_VIDEO,           /**< ��Ƶ���� & ��������*/
    CALL_E_CFG_BFCP,            /**< ����BFCP����*/
    CALL_E_CFG_MOBILE_VOICEMAIL,/**< �ƶ���������Ȩ��*/
    CALL_E_CFG_BUTT
}CALL_E_CFG_MAJOR_TYPE;


/**
 * �������Ӧ����������
 */
typedef enum tagCALL_E_CFG_DATA_TYPE
{
    CALL_E_CFG_DATA_TYPE_INT = 0x01,       /**< ���� */
    CALL_E_CFG_DATA_TYPE_STRING = 0x02,    /**< �ַ��� */         
    CALL_E_CFG_DATA_TYPE_STRUCTURE = 0x04, /**< �ṹ */    
    CALL_E_CFG_DATA_TYPE_BOOL = 0x08,      /**< BOOL */  
    CALL_E_CFG_DATA_TYPE_PTR = 0x10,       /**< ָ�� */  
    CALL_E_CFG_DATA_TYPE_BUTT,

} CALL_E_CFG_DATA_TYPE;


#define CFG_ID_DEF(major,data_type,id,index)    ((major)<<24|((data_type) << 16)|(id) <<8|(index))

#define GET_CFG_DATA_TYPE(cfgid)            ((cfgid>>16)&0x000000FF)
#define GET_CFG_MAJOR_TYPE(cfgid)           ((cfgid>>24)&0x000000FF)
#define GET_CFG_ID(cfgid)                   ((cfgid>>8)&0x000000FF)
#define GET_CFG_INDEX(cfgid)                ((cfgid)&0x000000FF)


/**
 * ������˵��
 * <br>1.CALL_D_CFG_NET_NETADDRESS �����������Ҫ�ŵ��������������ȥ����socket��
 * <br>�����һ�ε��ú󣬳��Ǻ��������ַ����������ٵ��á�
 * <br>2.ʹ��Ĭ��ֵ��ѡ���ò����ã��������п�����
 * <br>3.�������ýӿڵ�˳��һ���ǰ�sip��ص�������ŵ����棬��ͬ�Ĺ������һ��
 * <br>4.���Ҫ�������У���Ҫ���õ�ѡ��
 * <br>  CALL_D_CFG_SERVER_REG_PRIMARY  ����sipע���������ַ
 * <br>  CALL_D_CFG_ENV_USEAGENT        �����Ӧ��useragent������"Huawei TE Desktop"
 * <br>  CALL_D_CFG_ENV_PRODUCT_TYPE    ��Ʒ����
 * <br>  CALL_D_CFG_NET_NETADDRESS      ���������ַ
 * <br>  CALL_D_CFG_MEDIA_SDP_CT        TE��Ʒ��������
 * <br>  CALL_D_CFG_COMPATIBLE_PARAM_OUTGOINGCODE       ��ΪUC��������
 * <br>  CALL_D_CFG_COMPATIBLE_PARAM_SELFNUM            ��ΪUC��������
 * <br>5.CALL_D_CFG_SIP_USE_VPP_CALLID  ʹ��vpp��callid������������ַ����һЩ�м���Ԫ��������ַ�滻������ʱ����Կ��ǰ����ѡ����Ϊfalse
 * <br>6.CALL_D_CFG_SIP_SESSIONTIMER_LENIENT �������̵Ĳ�Ʒ���Ự������Э��û���ϸ����أ�Ϊ���ܹ��Խ�������������Ϊture
 * <br>7.CALL_D_CFG_SIP_STRICT_CHECK_CSEQ ʹ��UDP��ʽʱ����ʱ����յ��İ�������ģ�Ϊ����vpp�ܹ����ݣ�������Ϊfalse�����ϸ���
 * <br>8.CALL_D_CFG_SIP_TLS_VERSION ���������CALL_D_CFG_NET_NETADDRESSǰ
*/
#define CALL_D_CFG_NOTE "call config note"


#define CALL_D_CFG_SERVER_REG_PRIMARY     CFG_ID_DEF(CALL_E_CFG_SERVER,CALL_E_CFG_DATA_TYPE_STRUCTURE,0x01,0) /**< ����ע��������������Ӧ�ṹ��ΪCALL_S_SERVER_CFG��Ĭ��ֵΪ�ա�@see CALL_D_CFG_NOTE*/
#define CALL_D_CFG_SERVER_REG_BACKUP1     CFG_ID_DEF(CALL_E_CFG_SERVER,CALL_E_CFG_DATA_TYPE_STRUCTURE,0x02,0) /**< ����ע�ᱸ�ݷ�����1����Ӧ�ṹ��ΪCALL_S_SERVER_CFG��Ĭ��ֵΪ�ա�*/
#define CALL_D_CFG_SERVER_REG_BACKUP2     CFG_ID_DEF(CALL_E_CFG_SERVER,CALL_E_CFG_DATA_TYPE_STRUCTURE,0x03,0) /**< ����ע�ᱸ�ݷ�����3����Ӧ�ṹ��ΪCALL_S_SERVER_CFG��Ĭ��ֵΪ�ա�*/
#define CALL_D_CFG_SERVER_REG_BACKUP3     CFG_ID_DEF(CALL_E_CFG_SERVER,CALL_E_CFG_DATA_TYPE_STRUCTURE,0x04,0) /**< ����ע�ᱸ�ݷ�����3����Ӧ�ṹ��ΪCALL_S_SERVER_CFG��Ĭ��ֵΪ�ա�*/
#define CALL_D_CFG_SERVER_REG_LOCAL       CFG_ID_DEF(CALL_E_CFG_SERVER,CALL_E_CFG_DATA_TYPE_STRUCTURE,0x05,0) /**< ����ע�᱾�ط���������Ӧ�ṹ��ΪCALL_S_SERVER_CFG��Ĭ��ֵΪ�ա�*/
#define CALL_D_CFG_SERVER_PROXY_PRIMARY   CFG_ID_DEF(CALL_E_CFG_SERVER,CALL_E_CFG_DATA_TYPE_STRUCTURE,0x11,0) /**< ����ע�����������������Ӧ�ṹ��ΪCALL_S_SERVER_CFG��Ĭ��ֵΪ�ա�*/
#define CALL_D_CFG_SERVER_PROXY_BACKUP1   CFG_ID_DEF(CALL_E_CFG_SERVER,CALL_E_CFG_DATA_TYPE_STRUCTURE,0x12,0) /**< ����ע�ᱸ�ݴ��������1����Ӧ�ṹ��ΪCALL_S_SERVER_CFG��Ĭ��ֵΪ�ա�*/   
#define CALL_D_CFG_SERVER_PROXY_BACKUP2   CFG_ID_DEF(CALL_E_CFG_SERVER,CALL_E_CFG_DATA_TYPE_STRUCTURE,0x13,0) /**< ����ע�ᱸ�ݴ��������2����Ӧ�ṹ��ΪCALL_S_SERVER_CFG��Ĭ��ֵΪ�ա�*/    
#define CALL_D_CFG_SERVER_PROXY_BACKUP3   CFG_ID_DEF(CALL_E_CFG_SERVER,CALL_E_CFG_DATA_TYPE_STRUCTURE,0x14,0) /**< ����ע�ᱸ�ݴ��������3����Ӧ�ṹ��ΪCALL_S_SERVER_CFG��Ĭ��ֵΪ�ա�*/ 
#define CALL_D_CFG_SERVER_PROXY_LOCAL     CFG_ID_DEF(CALL_E_CFG_SERVER,CALL_E_CFG_DATA_TYPE_STRUCTURE,0x15,0) /**< ����ע�᱾�ش������������Ӧ�ṹ��ΪCALL_S_SERVER_CFG��Ĭ��ֵΪ�ա�*/
#define CALL_D_CFG_SERVER_UMS_PRIMARY     CFG_ID_DEF(CALL_E_CFG_SERVER,CALL_E_CFG_DATA_TYPE_STRUCTURE,0x21,0) /**< UMS������������Ӧ�ṹ��ΪCALL_S_SERVER_CFG��Ĭ��ֵΪ�ա�*/
#define CALL_D_CFG_SERVER_UMS_BACKUP      CFG_ID_DEF(CALL_E_CFG_SERVER,CALL_E_CFG_DATA_TYPE_STRUCTURE,0x22,0) /**< UMS���ݷ���������Ӧ�ṹ��ΪCALL_S_SERVER_CFG��Ĭ��ֵΪ�ա�*/

#define CALL_D_CFG_ENV_SOLUTION                  CFG_ID_DEF(CALL_E_CFG_CALLENV,CALL_E_CFG_DATA_TYPE_INT,0x01,0) /**< �������(����)��������Ӧö��ΪCALL_E_NET_ENVIRONMENT��Ĭ��ֵΪCALL_E_NET_UC1X��*/ 
#define CALL_D_CFG_ENV_DISASTER_RECOVERY_MODE    CFG_ID_DEF(CALL_E_CFG_CALLENV,CALL_E_CFG_DATA_TYPE_INT,0x02,0) /**< ����ģʽ����Ӧö��ΪCALL_E_REG_FAILOVER_MODE��Ĭ��ֵΪCALL_E_REG_FAILOVER_MODE_REGMASTER��*/ 
#define CALL_D_CFG_ENV_PRODUCT_TYPE              CFG_ID_DEF(CALL_E_CFG_CALLENV,CALL_E_CFG_DATA_TYPE_INT,0x03,0) /**< ��Ʒ���ͣ���Ӧö��ΪCALL_E_PRODUCT_TYPE��Ĭ��ֵΪCALL_E_PRODUCT_TYPE_PHONE��@see CALL_D_CFG_NOTE*/
#define CALL_D_CFG_ENV_USEAGENT                  CFG_ID_DEF(CALL_E_CFG_CALLENV,CALL_E_CFG_DATA_TYPE_STRING,0x04,0)  /**< �û������ַ�����Ĭ��Ϊ�ա�@see CALL_D_CFG_NOTE*/  

#define CALL_D_CFG_SERVRIGHT_DND        CFG_ID_DEF(CALL_E_CFG_SERVRIGHT,CALL_E_CFG_DATA_TYPE_STRUCTURE,CALL_E_SERVICE_RIGHT_TYPE_DONOTDISTURB,0) /**< ҵ��Ȩ������:DND����Ӧ�ṹ��ΪCALL_S_SERVICE_RIGHT_CFG��Ĭ��ֵΪ�ա�*/
#define CALL_D_CFG_SERVRIGHT_CFU        CFG_ID_DEF(CALL_E_CFG_SERVRIGHT,CALL_E_CFG_DATA_TYPE_STRUCTURE,CALL_E_SERVICE_RIGHT_TYPE_CALLFORWARDING_UNCONDITIONAL,0) /**< ҵ��Ȩ������:CFU����Ӧ�ṹ��ΪCALL_S_SERVICE_RIGHT_CFG��Ĭ��ֵΪ�ա�*/ 
#define CALL_D_CFG_SERVRIGHT_CFB        CFG_ID_DEF(CALL_E_CFG_SERVRIGHT,CALL_E_CFG_DATA_TYPE_STRUCTURE,CALL_E_SERVICE_RIGHT_TYPE_CALLFORWARDING_ONBUSY,0) /**< ҵ��Ȩ������:CFB����Ӧ�ṹ��ΪCALL_S_SERVICE_RIGHT_CFG��Ĭ��ֵΪ�ա�*/
#define CALL_D_CFG_SERVRIGHT_CFNR       CFG_ID_DEF(CALL_E_CFG_SERVRIGHT,CALL_E_CFG_DATA_TYPE_STRUCTURE,CALL_E_SERVICE_RIGHT_TYPE_CALLFORWARDING_OFFLINE,0) /**< ҵ��Ȩ������:CFNR����Ӧ�ṹ��ΪCALL_S_SERVICE_RIGHT_CFG��Ĭ��ֵΪ�ա�*/
#define CALL_D_CFG_SERVRIGHT_CFNA       CFG_ID_DEF(CALL_E_CFG_SERVRIGHT,CALL_E_CFG_DATA_TYPE_STRUCTURE,CALL_E_SERVICE_RIGHT_TYPE_CALLFORWARDING_NOREPLY,0) /**< ҵ��Ȩ������:CFNA����Ӧ�ṹ��ΪCALL_S_SERVICE_RIGHT_CFG��Ĭ��ֵΪ�ա�*/
#define CALL_D_CFG_SERVRIGHT_CALLWAIT   CFG_ID_DEF(CALL_E_CFG_SERVRIGHT,CALL_E_CFG_DATA_TYPE_STRUCTURE,CALL_E_SERVICE_RIGHT_TYPE_CALL_WAIT,0) /**< ҵ��Ȩ������:CALLWAIT����Ӧ�ṹ��ΪCALL_S_SERVICE_RIGHT_CFG��Ĭ��ֵΪ�ա�*/

#define CALL_D_CFG_DSCP_ENABLE   CFG_ID_DEF(CALL_E_CFG_DSCP,CALL_E_CFG_DATA_TYPE_BOOL,0x1,0)  /**< DSCPʹ�����ã�ȡֵtrue/false��Ĭ��ֵΪfalse��*/
#define CALL_D_CFG_DSCP_AUDIO    CFG_ID_DEF(CALL_E_CFG_DSCP,CALL_E_CFG_DATA_TYPE_INT,0x2,0)   /**< ��Ƶͨ��DSCP���ã�ȡֵ[0,64)��Ĭ��ֵΪ0��*/
#define CALL_D_CFG_DSCP_VIDEO    CFG_ID_DEF(CALL_E_CFG_DSCP,CALL_E_CFG_DATA_TYPE_INT,0x3,0)   /**< ��Ƶͨ��DSCP���ã�ȡֵ[0,64)��Ĭ��ֵΪ0��*/
#define CALL_D_CFG_DSCP_SIP      CFG_ID_DEF(CALL_E_CFG_DSCP,CALL_E_CFG_DATA_TYPE_INT,0x4,0)   /**< SIP����ͨ��DSCP���ã�ȡֵ[0,64)��Ĭ��ֵΪ0��*/
#define CALL_D_CFG_DSCP_DATA     CFG_ID_DEF(CALL_E_CFG_DSCP,CALL_E_CFG_DATA_TYPE_INT,0x5,0)   /**< ����ͨ��DSCP���ã�ȡֵ[0,64)��Ĭ��ֵΪ0��*/

#define CALL_E_CFG_CONF_ENABLE_INTERCONF            CFG_ID_DEF(CALL_E_CFG_CONF, CALL_E_CFG_DATA_TYPE_BOOL, 0x1, 0)   /**< ��������:����ֵ������ʹ�á�*/
#define CALL_E_CFG_CONF_MS_ADDR                     CFG_ID_DEF(CALL_E_CFG_CONF, CALL_E_CFG_DATA_TYPE_STRING, 0x4, 0) /**< ��������:MS��ַ���ַ�����Ĭ��Ϊ�ա�*/ 
#define CALL_E_CFG_CONF_APPAGENT_ADDR               CFG_ID_DEF(CALL_E_CFG_CONF, CALL_E_CFG_DATA_TYPE_STRING, 0x5, 0) /**< ��������:APP Agent��ַ���ַ�����Ĭ��Ϊ�ա�*/ 
#define CALL_D_CFG_COMPATIBLE_PARAM_SELFNUM         CFG_ID_DEF(CALL_E_CFG_COMPATIBLE_PARAM,CALL_E_CFG_DATA_TYPE_STRING,0x2,0)   /**< ��������:���˺��룬�ַ�����Ĭ��Ϊ�գ���ΪUC��������Ҫʹ�� ��*/ 
#define CALL_D_CFG_COMPATIBLE_PARAM_OUTGOINGCODE    CFG_ID_DEF(CALL_E_CFG_COMPATIBLE_PARAM,CALL_E_CFG_DATA_TYPE_STRING,0x3,0)   /**< ��������:�����룬�ַ�����Ĭ��Ϊ�ա�*/ 

#define CALL_D_CFG_SIP_PORT                 CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x1, 0)  /**< SIP�˿ڣ�ȡֵ[1024,65535]��Ĭ��ֵΪ5060��*/
#define CALL_D_CFG_SIP_REGIST_TIMEOUT       CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x2, 0)  /**< ע��������ʱʱ�䣬ȡֵ��ΧTUPδ�����ƣ���Ʒ��Ҫ����ʵ������Ҫ�����ã�Ĭ��ֵΪ300s��*/
#define CALL_D_CFG_SIP_SUBSCRIBE_TIMEOUT    CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x3, 0)  /**< ����������ʱʱ�䣬ȡֵ��ΧTUPδ�����ƣ���Ʒ��Ҫ����ʵ������Ҫ�����ã�Ĭ��ֵΪ300s��*/
#define CALL_D_CFG_SIP_REREGISTER_TIMEOUT   CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x4, 0)  /**< ע��ʧ�ܺ�����ע��ĳ�ʱʱ�䣬ȡֵ��ΧTUPδ�����ƣ���Ʒ��Ҫ����ʵ������Ҫ�����ã�Ĭ��ֵΪ150s��*/
#define CALL_D_CFG_SIP_SWITCHCALL_TIMEOUT   CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x5, 0)  /**< ��ע��Invite�л�ʱ����ȡֵ��ΧTUPδ�����ƣ���Ʒ��Ҫ����ʵ������Ҫ�����ã�Ĭ��ֵΪ0��*/
#define CALL_D_CFG_SIP_SESSIONTIMER_ENABLE  CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_BOOL,   0x6, 0)  /**< �Ự�������أ�Ĭ�Ϲرա�*/
#define CALL_D_CFG_SIP_SESSIONTIME          CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x7, 0)  /**< �Ự������ȡֵ��ΧTUPδ�����ƣ���Ʒ��Ҫ����ʵ������Ҫ�����ã�Ĭ��ֵΪ0s��*/
#define CALL_D_CFG_SIP_REJECT_TYPE          CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x8, 0)  /**< �ܽӺ��лظ������Ӧö��ΪCALL_E_REJECTCALL_TYPE��Ĭ��ֵΪCALL_D_REJECTTYPE_486��*/ 
#define CALL_D_CFG_SIP_TRANS_MODE           CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x9, 0)  /**< �����ģʽ����Ӧö��ΪCALL_E_TRANSPORTMODE��Ĭ��ֵΪCALL_E_TRANSPORTMODE_UDP��*/ 
#define CALL_D_CFG_SIP_TLS_ROOTCERTPATH     CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_STRING, 0xA, 0)  /**< TLS��֤��·�����ַ�����Ĭ��Ϊ�ա�*/
#define CALL_D_CFG_SIP_SUPPORT_100REL       CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_BOOL,   0xB, 0)  /**< ֧��100Rel��Ĭ�Ϲرա�*/
#define CALL_D_CFG_SIP_ENABLE_REG_SUB       CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_BOOL,   0xC, 0)  /**< �Ƿ�������ע�ᣬĬ�Ϲرա�*/
#define CALL_D_CFG_SIP_ENABLE_CORPORATE_DIRECTORY CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_BOOL, 0xD, 0) /**< �Ƿ������������ַ�����ն�������SC���ģ�,Ĭ�Ϲرա�*/
#define CALL_D_CFG_SIP_ENABLE_PRESENCE_TE   CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_BOOL,   0xE, 0)  /**< �Ƿ�����������״̬���ģ��ն�������SC���ģ�,Ĭ�Ϲرա�*/
#define CALL_D_CFG_SIP_REJECT_VIDEO_TYPE    CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0xF, 0)  /**< �ܽ���Ƶ�ظ������Ӧö��ΪCALL_E_REJECTCALL_TYPE��Ĭ��ֵΪCALL_D_REJECTVIDEOTYPE_200��*/
#define CALL_D_CFG_SIP_USE_VPP_CALLID       CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_BOOL,   0x10, 0) /**< �Ƿ�Ĭ��ʹ��vpp���ɵ�callid��Ĭ���ǡ�*/
#define CALL_D_CFG_SIP_SOCKET_USE_All_ZERO_IP  CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_BOOL,0x11, 0) /**< �Ƿ�ʹ��ȫ��IP����socket��Ĭ�Ϸ�*/
#define CALL_D_CFG_SIP_SESSION_UPDATEMODE   CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x12, 0) /**< �Ự������refreshģʽ����Ӧö��ΪCALL_E_SESSION_REFRESHER��Ĭ��ֵΪCALL_E_REFRESHER_UAC��*/
#define CALL_D_CFG_SIP_SESSIONTIMER_LENIENT CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_BOOL,   0x13, 0) /**< session timer�Ƿ���ݷǱ�׼��ʽ��Ĭ�Ϸ�*/
#define CALL_D_CFG_SIP_SUB_AUTH_TYPE        CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_BOOL,   0x14, 0) /**< �Ƿ�����֤��ʽ��Ĭ�ϲ����ġ�*/
#define CALL_D_CFG_SIP_STRICT_CHECK_CSEQ    CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_BOOL,   0x15, 0) /**< �Ƿ��ϸ���CSEQ��Ĭ���ϸ��⡣*/
#define CALL_D_CFG_SIP_ANONYMOUSNUM         CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_STRING, 0x16, 0) /**< �������к��룬�ַ�����Ĭ��Ϊ�ա�*/ 
#define CALL_D_CFG_SIP_TLS_NOSTANDARD       CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_BOOL,   0x17, 0) /**< �Ƿ����TLS�Ǳ��ֶ�,falseΪ�����,trueΪ���(Ĭ��Ϊfalse)��*/
#define CALL_D_CFG_SIP_REFER_AUDVIE_MODE    CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x18, 0) /**< �յ�REFER����invite����Ƶ/��Ƶ��ģʽ��0��ʾ���ݱ�ת��ͨ��ѡ��1��ʾ�����Ƿ�Э�̹���Ƶѡ��*/
#define CALL_D_CFG_SIP_ALLOWMESSAGE         CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x19, 0) /**< �Ƿ�֧��MESSAGE������Ĭ���ǡ�*/
#define CALL_D_CFG_SIP_ALLOWPRACK           CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x20, 0) /**< �Ƿ�֧��PRACK������Ĭ���ǡ�*/
#define CALL_D_CFG_SIP_ALLOWUPDATE          CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x21, 0) /**< �Ƿ�֧��UPDATE������Ĭ���ǡ�*/
#define CALL_D_CFG_SIP_ALLOWSUBSCRIBE       CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x22, 0) /**< �Ƿ�֧��SUBSCRIBE������Ĭ���ǡ�*/
#define CALL_D_CFG_SIP_ALLOWINFO            CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x23, 0) /**< �Ƿ�֧��INFO������Ĭ���ǡ�*/
#define CALL_D_CFG_SIP_ALLOWREFER           CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x24, 0) /**< �Ƿ�֧��REFER������Ĭ���ǡ�*/
#define CALL_D_CFG_SIP_ALLOWNOTIFY          CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x25, 0) /**< �Ƿ�֧��NOTIFY������Ĭ���ǡ�*/
#define CALL_D_CFG_SIP_SUB_SERVICE_RIGHT    CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_BOOL,   0x26, 0) /**< ���� as-feature-event��Ĭ�Ϲرա�*/
#define CALL_D_CFG_SIPGLOBAL_CONTENT_TYPE   CFG_ID_DEF(CALL_E_CFG_SIPGLOBAL, CALL_E_CFG_DATA_TYPE_STRUCTURE, 0x1, 0) /**< ���öԻ���INFO��Ϣ*/


#define CALL_D_CFG_SIP_TLS_VERSION          CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_INT,    0x27, 0) /**< TLS֧�ֵİ汾����������tls1.0 tls1.1 tls1.2��������ϣ�
																												* <br> ʹ��CALL_D_TLSVERSION_V1_0��CALL_D_TLSVERSION_V1_1��CALL_D_TLSVERSION_V1_2��
																												* <br> ���ڵ�������ʹ�á�|����������Ĭ���� tls1.1 �� tls1.2 */

#define CALL_D_CFG_SIP_REFER_AUTO_BYE       CFG_ID_DEF(CALL_E_CFG_SIP, CALL_E_CFG_DATA_TYPE_BOOL,   0x28, 0)/**< �յ�refer���Զ�bye����һ·,Ĭ�ϲ����� */

#define CALL_D_CFG_MEDIA_SRTPMKI            CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_BOOL,      0x1,0)  /**< ȫ��ý������:SRTP�Ƿ��mki��ʽ��Ĭ�Ϸ� */
#define CALL_D_CFG_MEDIA_SRTP_MODE          CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_INT,       0x2,0)  /**< ȫ��ý������:SRTPģʽ����Ӧö��ΪCALL_E_SRTP_MODE��Ĭ��ֵΪCALL_E_SRTP_MODE_DISABLE��*/ 
#define CALL_D_CFG_MEDIA_MERGE_SRTP_RTP     CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_BOOL,      0x3,0)  /**< ȫ��ý������:�Ƿ�ϲ�SRTP��RTP��m�У�Ĭ�Ϸ� */
#define CALL_D_CFG_MEDIA_RTP_PRIORITY       CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_INT,       0x4,0)  /**< ȫ��ý������:ý������rtp��srtp����˳�򣬶�Ӧö��ΪSIPC_TUP_SRTP_PRI_E��Ĭ��ֵΪSIPC_TUP_SRTP_PRI��*/ 
#define CALL_D_CFG_MEDIA_CRYPTOSUITE        CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_STRING,    0x5,0)  /**< ȫ��ý������:SRTP�����ף��ַ�����Ĭ��"1,2"������1��AES_CM_128_HMAC_SHA1_80  2��AES_CM_128_HMAC_SHA1_32��*/ 
#define CALL_D_CFG_MEDIA_SDP_OLINE_INFO     CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_STRUCTURE, 0x6,0)  /**< ȫ��ý������:����SDP����Ӧ�ṹ��CALL_S_SDP_OLINE_INFO��Ĭ��{��huawei��,"23293","1"} */
#define CALL_D_CFG_MEDIA_MOS_TIME           CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_INT,       0x7,0)  /**< ȫ��ý������:MOSֵ�ϱ����ʱ�䣬��λ:�룬ȡֵ��ΧTUPδ�����ƣ���Ʒ��Ҫ����ʵ������Ҫ�����ã�Ĭ��5�� */
#define CALL_D_CFG_MEDIA_MOS_THRESHOLD      CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_INT,       0x8,0)  /**< ȫ��ý������:MOSֵ�ϱ���ֵ��ȡֵ[0��5]��Ĭ��3.6 */
#define CALL_D_CFG_MEDIA_MOS_SENDINFOSWITCH CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_BOOL,      0x9,0)  /**< ȫ��ý������:MOSֵ�ϱ�ͨ��INFOSIP���������أ�Ĭ�Ϸ� */
#define CALL_D_CFG_MEDIA_SENDONLYFREE       CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_BOOL,      0xA,0)  /**< ȫ��ý������:ý�巽��Ϊsendonly���Ƿ��ͷ���Դ�����ն�Ĭ�Ϸ�Ӳ�ն�Ĭ���� */
#define CALL_D_CFG_MEDIA_USEPACKMODE        CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_BOOL,      0xB,0)  /**< ȫ��ý������:H264��ƵЭ��ʱ���Ƿ��жϴ��ģʽ�����ն�Ĭ���ǣ�Ӳ�ն�Ĭ�Ϸ� */
#define CALL_D_CFG_MEDIA_RECORDFILE_INFO    CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_STRUCTURE, 0xC,0)  /**< ȫ��ý������:�����ļ�������Ϣ����Ӧ�ṹ��CALL_S_RECORDFILE_INFO��Ĭ��{0,100,8000,0} */
#define CALL_D_CFG_MEDIA_SETQOS_INFO        CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_STRUCTURE, 0xD,0)  /**< ȫ��ý������:����qos�ϱ�����Ӧ�ṹ��CALL_S_SETQOS_INFO��Ĭ�Ͽ� */
#define CALL_D_CFG_MEDIA_ENABLE_DATA        CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_BOOL,      0xD,0)  /**< ȫ��ý������:�������أ�Ĭ�Ϸ� */
#define CALL_D_CFG_MEDIA_FORCE_IDR_INFO     CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_BOOL,      0xE,0)  /**< ȫ��ý������:�Ƿ�ǿ�ƴ�info idr������շ���Ĭ�Ϸ� */
#define CALL_D_CFG_MEDIA_SDP_CT             CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_INT,       0xF,0)  /**< ȫ��ý������:sdp CTֵ��ȡֵ��ΧTUPδ�����ƣ���Ʒ��Ҫ����ʵ������Ҫ�����ã�Ĭ��ֵ0��*/
#define CALL_D_CFG_MEDIA_LOOSE_PORT_NEGO    CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_BOOL,      0x10,0) /**< ȫ��ý������:�Ƿ�֧��loose-port-nego�����ϸ�˿�Э�̣���Ĭ�Ϸ� */
#define CALL_D_CFG_MEDIA_WND_PARAM          CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_STRUCTURE, 0x11, 0)/**< ȫ��ý������:��Ƶ��ʾ�������ԣ�����/����/��ת������Ӧ�ṹ��CALL_S_VIDEO_RENDER_INFO��Ĭ��{1,1,1} */
#define CALL_D_CFG_MEDIA_IFRAME_METHOD      CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_BOOL,      0x12,0) /**< ȫ��ý������:I֡���ƣ�Ĭ�Ϸ� */
#define CALL_D_CFG_MEDIA_FLUID_CONTROL      CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_BOOL,      0x13,0) /**< ȫ��ý������:���أ�Ĭ�Ϸ� */
#define CALL_D_CFG_MEDIA_DEL_PORT0_LINE     CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_BOOL,      0x14,0) /**< ȫ��ý������:ɾ����Чý���У�Ĭ�Ϸ� */
#define CALL_D_CFG_VIDEOSESSION_PREVIEWTYPE CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_INT,       0x15, 0)/**< ȫ��ý������:��ƵԤ�����ͣ�0�������κ�Ԥ��������Ϊ2��Ϊ��ƵԤ����Ĭ��Ϊ0�� */
#define CALL_D_CFG_MEDIA_ENABLE_BFCP        CFG_ID_DEF(CALL_E_CFG_MEDIA,  CALL_E_CFG_DATA_TYPE_BOOL,      0x17,0) /**< ȫ��ý������:BFCP���أ�����CALL_D_CFG_NET_NETADDRESS֮ǰ���ã�Ĭ�Ϸ� */

#define CALL_D_CFG_AUDIO_CODEC              CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_STRING,     0x1, 0) /**< ��Ƶ����:��Ƶ��������ȼ���ȡֵΪ��Ƶ������ӦPTֵ�������ִ����Զ��ŷָ��"112,98,18,9,8,0"��*/
#define CALL_D_CFG_AUDIO_ANR                CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_INT,        0x2, 0) /**< ��Ƶ����:�������ƣ�[0,4] 0���ر�  1-4����ֵԽ����������ǿ��Խ��  Ĭ�Ϲر� */
#define CALL_D_CFG_AUDIO_AEC                CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_INT,        0x3, 0) /**< ��Ƶ����:����������0�ر� 1������Ĭ�Ϲرգ����鿪����*/
#define CALL_D_CFG_AUDIO_AGC                CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_INT,        0x4, 0) /**< ��Ƶ����:�Զ����棬0�ر� 1������Ĭ�Ϲرա�*/
#define CALL_D_CFG_AUDIO_DTMF_MODE          CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_INT,        0x5, 0) /**< ��Ƶ����:DTMFģʽ����Ӧö��ΪCALL_E_DTMF_MODE��Ĭ��ֵΪCALL_E_DTMF_MODE_RFC2833��*/ 
#define CALL_D_CFG_AUDIO_DTMF_PT            CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_INT,        0x6, 0) /**< ��Ƶ����:DTMF PTֵ��ȡֵ[0,127]��Ĭ��ֵ97��*/
#define CALL_D_CFG_AUDIO_ILBCMODE           CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_INT,        0x7, 0) /**< ��Ƶ����:ILBC���ʱ����ȡֵ20 �� 30��Ĭ��ֵ20 */    
#define CALL_D_CFG_AUDIO_PACKETTIME         CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_INT,        0x8, 0) /**< ��Ƶ����:���ʱ��,��ILBC����Ч��ȡֵ20��30��40��Ĭ��ֵ20 */
#define CALL_D_CFG_AUDIO_NETATELEVEL        CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_INT,        0x9, 0) /**< ��Ƶ����:�Ƿ��NET-ATE��Ĭ���ǡ�*/
#define CALL_D_CFG_AUDIO_VADFLAG            CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_BOOL,       0xA, 0) /**< ��Ƶ����:Vad���ñ�־λ��0�ر� 1������Ĭ�Ϲرա�*/
#define CALL_D_CFG_AUDIO_CLOCKRATE          CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_INT,        0xB, 0) /**< ��Ƶ����:����Ƶ�ʣ����ݱ���벻ͬ������ҵ��ͨ�õ�Ĭ��ֵ */
#define CALL_D_CFG_AUDIO_CHANNELS           CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_INT,        0xC, 0) /**< ��Ƶ����:����������Ĭ��ֵ1��*/
#define CALL_D_CFG_AUDIO_BITS               CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_INT,        0xD, 0) /**< ��Ƶ����:����λ�������ݱ���벻ͬ������ҵ��ͨ�õ�Ĭ��ֵ */
#define CALL_D_CFG_AUDIO_PORT_RANGE         CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0xE, 0) /**< ��Ƶ����:��Ƶ�˿ڷ�Χ����Ӧ�ṹ��CALL_S_RTP_PORT_RANGE��Ĭ��{10500,10519} */
#define CALL_D_CFG_AUDIO_PLAYFILE_ADDITIONINFO         CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0xF, 0) /**< ��Ƶ����:������Ƶ�ļ�������Ϣ����Ӧ�ṹ��CALL_S_AUDIO_PLAYFILE_ADDITIONINFO��Ĭ��{CALL_FILE_FORMAT_WAV} */
#define CALL_D_CFG_AUDIO_RFC2198            CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x10, 0) /**< ��Ƶ����:��Ƶ�������ã���Ӧ�ṹ��CALL_S_AUDIO_RFC2198��Ĭ��Ϊ�� */
#define CALL_D_CFG_AUDIO_BAND_LIMIT         CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x11, 0) /**< ��Ƶ����:�ʹ������ã���Ӧ�ṹ��CALL_S_AUDIO_BAND_LIMIT��Ĭ��Ϊ�� */
#define CALL_D_CFG_AUDIO_CLOSE_WAIT         CFG_ID_DEF(CALL_E_CFG_AUDIO, CALL_E_CFG_DATA_TYPE_INT,        0x12, 0) /**< ��Ƶ����:��Ƶͨ���رյȴ�ʱ������λms��Ĭ��Ϊ0*/

#define CALL_D_CFG_VIDEO_LEVEL              CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x1, 0) /**< ��Ƶ����:���뼶���Լ��������ƣ���Ӧ�ṹ��CALL_S_VIDEO_LEVEL��Ĭ��{0,0,0,0} */
#define CALL_D_CFG_DATA_LEVEL               CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x1, 1) /**< ��������:���뼶���Լ��������ƣ���Ӧ�ṹ��CALL_S_VIDEO_LEVEL��Ĭ��{0,0,0,0} */
#define CALL_D_CFG_VIDEO_DEFAULT_IMAGE      CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRING,     0x2, 0) /**< ��Ƶ����:����Ƶʱʹ�õ�ͼƬ��ͼƬ������bmp��ʽ�ģ�Ĭ�Ͽ�*/
#define CALL_D_CFG_VIDEO_ARQ                CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_BOOL,       0x3, 0) /**< ��Ƶ����:�Ƿ��������ش���0�ر� 1������Ĭ�Ϲرա�*/
#define CALL_D_CFG_DATA_ARQ                 CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_BOOL,       0x3, 1) /**< ��������:�Ƿ��������ش���0�ر� 1������Ĭ�Ϲرա�*/
#define CALL_D_CFG_VIDEO_TACTIC             CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_INT,        0x4, 0) /**< ��Ƶ����:���� 0 ͼ����������  1 �������ȣ�Ĭ��ͼ���������ȡ�*/
#define CALL_D_CFG_DATA_TACTIC              CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_INT,        0x4, 1) /**< ��������:���� 0 ͼ����������  1 �������ȣ�Ĭ��ͼ���������ȡ�*/
#define CALL_D_CFG_VIDEO_CODEC              CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRING,     0x5, 0) /**< ��Ƶ����:��������ȼ�����ǰ��֧��H263&H264��ȡֵ��ƵƵ������ӦPTֵ�������ִ����Զ��ŷָ��"106,34"��*/
#define CALL_D_CFG_DATA_CODEC               CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRING,     0x5, 1) /**< ��������:��������ȼ�����ǰ��֧��H263&H264��ȡֵ��ƵƵ������ӦPTֵ�������ִ����Զ��ŷָ��"106,34"��*/
#define CALL_D_CFG_VIDEO_ERRORCORRECTING    CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_BOOL,       0x6, 0) /**< ��Ƶ����:�Ƿ�������У�鹦�ܣ�0�ر� 1������Ĭ�Ϲرա�*/
#define CALL_D_CFG_DATA_ERRORCORRECTING     CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_BOOL,       0x6, 1) /**< ��������:�Ƿ�������У�鹦�ܣ�0�ر� 1������Ĭ�Ϲرա�*/
#define CALL_D_CFG_VIDEO_FRAMESIZE          CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x7, 0) /**< ��Ƶ����:�ֱ��ʣ���Ӧ�ṹ��CALL_S_VIDEO_FRAMESIZE��Ĭ��{11,0,11} */
#define CALL_D_CFG_DATA_FRAMESIZE           CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x7, 1) /**< ��������:�ֱ��ʣ���Ӧ�ṹ��CALL_S_VIDEO_FRAMESIZE��Ĭ��{11,0,11} */
#define CALL_D_CFG_VIDEO_DATARATE           CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x8, 0) /**< ��Ƶ����:���ʣ���Ӧ�ṹ��CALL_S_VIDEO_DATARATE��Ĭ��{4096,0,0,1920} */
#define CALL_D_CFG_DATA_DATARATE            CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x8, 1) /**< ��������:���ʣ���Ӧ�ṹ��CALL_S_VIDEO_DATARATE��Ĭ��{4096,0,0,1920} */
#define CALL_D_CFG_VIDEO_HDACCELERATE       CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x9, 0) /**< ��Ƶ����:Ӳ�����٣���Ӧ�ṹ��CALL_S_VIDEO_HDACCELERATE��Ĭ��{VOS_TRUE,VOS_TRUE} */
#define CALL_D_CFG_DATA_HDACCELERATE        CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x9, 1) /**< ��������:Ӳ�����٣���Ӧ�ṹ��CALL_S_VIDEO_HDACCELERATE��Ĭ��{VOS_TRUE,VOS_TRUE} */
#define CALL_D_CFG_VIDEO_FRAMERATE          CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0xA, 0) /**< ��Ƶ����:֡�ʣ���Ӧ�ṹ��CALL_S_VIDEO_FRAMERATE��Ĭ��{30,15} */
#define CALL_D_CFG_DATA_FRAMERATE           CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0xA, 1) /**< ��������:֡�ʣ���Ӧ�ṹ��CALL_S_VIDEO_FRAMERATE��Ĭ��{30,15} */
#define CALL_D_CFG_VIDEO_KEYFRAMEINTERVAL   CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_INT,        0xC, 0) /**< ��Ƶ����:�ؼ�֡��� ȡֵ[0,30] ��λΪs��Ĭ��10��*/
#define CALL_D_CFG_DATA_KEYFRAMEINTERVAL    CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_INT,        0xC, 1) /**< ��������:�ؼ�֡��� ȡֵ[0,30] ��λΪs��Ĭ��10��*/
#define CALL_D_CFG_VIDEO_ARS                CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0xD, 0) /**< ��Ƶ����:Ars�������ã���Ӧ�ṹ��CALL_S_VIDEO_ARS��Ĭ��{VOS_TRUE,VOS_TRUE,255,VOS_TRUE,VOS_TRUE,VOS_FALSE} */
#define CALL_D_CFG_DATA_ARS                 CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0xD, 1) /**< ��������:Ars�������ã���Ӧ�ṹ��CALL_S_VIDEO_ARS��Ĭ��{VOS_TRUE,VOS_TRUE,255,VOS_TRUE,VOS_TRUE,VOS_FALSE} */
#define CALL_D_CFG_VIDEO_CAPTURE_ROTATION   CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_INT,        0xE, 0) /**< ��Ƶ����:����ͷ�ɼ��Ƕ� {0,1,2,3} �����ƶ�ƽ̨��Ч��Ĭ��Ϊ0��*/
#define CALL_D_CFG_VIDEO_PORT_RANGE         CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0xF, 0) /**< ��Ƶ����:�˿ڷ�Χ����Ӧ�ṹ��CALL_S_RTP_PORT_RANGE��Ĭ��{10520,10539} */
#define CALL_D_CFG_DATA_PORT_RANGE          CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0xF, 1) /**< ��������:�˿ڷ�Χ����Ӧ�ṹ��CALL_S_RTP_PORT_RANGE��Ĭ��{10540,10569} */
#define CALL_D_CFG_DATA_CAPTURE_FUNC        CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_PTR,        0x10,1) /**< ��������:ץ������ָ�룬��Ĭ�Ͽ� */
#define CALL_D_CFG_VIDEO_NETLOSSRATE        CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_INT,        0x11,0) /**< ��Ƶ����:��ʼ���綪���ٷ��ʣ��������ø�HME����fec��ʼ���࣬ȡֵ[0,100]��Ĭ��20��*/
#define CALL_D_CFG_DATA_NETLOSSRATE         CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_INT,        0x11,1) /**< ��������:��ʼ���綪���ٷ��ʣ��������ø�HME����fec��ʼ���࣬ȡֵ[0,100]��Ĭ��20��*/
#define CALL_D_CFG_VIDEO_PARAM_TABLE        CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x12,0) /**< ��Ƶ����:������Ƶ������������񣬶�Ӧ�ṹ��CALL_S_VIDEO_PARAM_TABLE��Ĭ�Ͽ� */
#define CALL_D_CFG_VIDEO_LOWBANDWIDTH_ABILITY   CFG_ID_DEF(CALL_E_CFG_VIDEO,  CALL_E_CFG_DATA_TYPE_BOOL,  0x13,0) /**< ��Ƶ����:�Ƿ�ӵ�еʹ����ܣ�����ҵ����Ҫ(0:��ʹ��-UC,1:ʹ��-TE,Ĭ��Ϊ0) */
#define CALL_D_CFG_VIDEO_H264_QUALITY_LEVEL CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x14,0) /**< ��Ƶ����:��ƵH264 BP/HP���ã���Ӧ�ṹ��CALL_S_VIDEO_H264_QUALITY_LEVEL_TABLE��Ĭ�Ͽ� */
#define CALL_D_CFG_DATA_H264_QUALITY_LEVEL  CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x14,1) /**< ��������:����H264 BP/HP���ã���Ӧ�ṹ��CALL_S_VIDEO_H264_QUALITY_LEVEL_TABLE��Ĭ�Ͽ� */
#define CALL_D_CFG_VIDEO_CT_LEVEL_TABLE     CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x15,0) /**< ��Ƶ����:����ct(�������������CALL_D_CFG_MEDIA_SDP_CT֮ǰ����)����Ӧ�ṹ��CALL_S_VIDEO_CT_LEVEL_TABLE��Ĭ�Ͽ� */
#define CALL_D_CFG_VIDEO_CAP_ROTATE_CTRL_MODE CFG_ID_DEF(CALL_E_CFG_VIDEO, CALL_E_CFG_DATA_TYPE_BOOL,     0x16,0) /**< ��Ƶ����:����ͷ�Ƕȿ���ģʽ(0:SDPЭ��ģʽ-UC,1:�ӿڿ���ģʽ-TE,Ĭ��Ϊ0) */
#define CALL_D_CFG_VIDEO_CLARITY_FLUENCY_ENABLE  CFG_ID_DEF(CALL_E_CFG_VIDEO,  CALL_E_CFG_DATA_TYPE_BOOL,  0x17,0)/**< ��Ƶ����:�Ƿ�ʹ�������������Ա� ����ҵ����Ҫ(0:��ʹ��-UC,1:ʹ��-TE,Ĭ��Ϊ0) */

#define CALL_D_CFG_BFCP_PARAM          CFG_ID_DEF(CALL_E_CFG_BFCP, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x1,0) /**< ����sdpЭ�̲�������Ӧ�ṹ��CALL_S_BFCP_PARAM��Ĭ��{1,1,1} */
#define CALL_D_CFG_BFCP_PORT_RANGE     CFG_ID_DEF(CALL_E_CFG_BFCP, CALL_E_CFG_DATA_TYPE_STRUCTURE,  0x2,0) /**< BFCP�˿ڷ�Χ(CALL_S_BFCP_PORT_RANGE)��Ҫ�����ñ��ص�ַǰ���ã�Ĭ��{10560} */

#define CALL_D_CFG_NET_NETADDRESS           CFG_ID_DEF(CALL_E_CFG_NET, CALL_E_CFG_DATA_TYPE_STRUCTURE, 0x1, 0) /**< ���ص�ַ��sipʹ�ã���ý��û�е�������ʱ����ý��Ҳ�������ַ����Ӧ�ṹ��CALL_S_IF_INFO��Ĭ�Ͽ� */
#define CALL_D_CFG_AUDIO_NETADDRESS         CFG_ID_DEF(CALL_E_CFG_NET, CALL_E_CFG_DATA_TYPE_STRING,    0x2, 0) /**< ������Ƶʹ�õ�ַ��IP��ַ�ַ�����Ĭ�Ͽ� */
#define CALL_D_CFG_VDIEO_NETADDRESS         CFG_ID_DEF(CALL_E_CFG_NET, CALL_E_CFG_DATA_TYPE_STRING,    0x3, 0) /**< ������Ƶʹ�õ�ַ����ǰ�ݲ�֧�֣�IP��ַ�ַ�����Ĭ�Ͽ� */

#define CALL_D_CFG_ACCOUNT_AUTH             CFG_ID_DEF(CALL_E_CFG_ACCOUNT, CALL_E_CFG_DATA_TYPE_STRUCTURE, 0x1, 0)/**< �˺����ã���Ӧ�ṹ��CALL_S_SIP_AUTH_CFG��Ĭ�Ͽ� */


/**�ƶ���������Ȩ������*/
#define CALL_D_CFG_MOBILE_VVM_RIGHT         CFG_ID_DEF(CALL_E_CFG_MOBILE_VOICEMAIL, CALL_E_CFG_DATA_TYPE_BOOL, 0x1, 0) /**< �Ƿ�֧���ƶ���������Ȩ�ޣ�Ĭ�Ϸ� */


/**
 * ����������
 */
typedef struct tagCALL_S_SERVER_CFG
{
     TUP_CHAR server_address[CALL_D_MAX_URL_LENGTH];   /**< ��������ַ��IP��ַ�ִ���������ַ */
     TUP_UINT32 server_port;                           /**< �������˿� */
} CALL_S_SERVER_CFG;


/**
 * ҵ��Ȩ������
 */
typedef struct tagCALL_S_SERVICE_RIGHT_CFG
{
    TUP_UINT32   ulRight;                                                  /**< �Ƿ���Ȩ��:0 �ޣ�1 �� */
    TUP_CHAR     acActiveAccessCode[CALL_D_ACCESSCODE_MAX_LENGTH];         /**< �Ǽ������� */
    TUP_CHAR     acDeactiveAccessCode[CALL_D_ACCESSCODE_MAX_LENGTH];       /**< ȡ���Ǽ�������*/
}CALL_S_SERVICE_RIGHT_CFG;



/**
 * ͳһ�����ַ����ӿ���Ϣ���ݽṹ
 */
typedef struct tagCALL_S_IF_INFO 
{
    CALL_E_IP_PROTOCOL_TYPE  ulType;                /**< �����ַ���� */
    union
    {
        TUP_UINT32 ulIPv4;                          /**< IPv4��ַ */
        TUP_UINT8  aucIPv6[CALL_D_IP_LENGTH];       /**< IPv6��ַ������16�ֽ� */
    }uAddress;
    union
    {
        TUP_UINT32 ulNetMask;                       /**< IPv4�������� */
        TUP_UINT8  ulPrefixLen;                     /**< IPv6��ַǰ׺���� */
    }uMask;
    union
    {
        TUP_UINT32 ulIPv4;                          /**< ����IPv4��ַ */
        TUP_UINT8  aucIPv6[CALL_D_IP_LENGTH];       /**< ����IPv6��ַ������16�ֽ� */
    }uGateWay;
} CALL_S_IF_INFO;


/**
 * �豸��Ϣ
 */
typedef struct tagCALL_S_DEVICEINFO
{
    TUP_UINT32 ulIndex;                             /**< �豸��Ӧ��index */
    TUP_CHAR   strName[CALL_D_MAX_DISPLAY_NAME];    /**< �豸���� */
} CALL_S_DEVICEINFO;


/**
 * ��Ƶˢ���¼���Ϣ
 */
typedef struct tagCALL_S_REFRESH_VIEW
{
    TUP_UINT32 ulCallID;                            /**< ͨ��ID */
    CALL_E_REFRESHVIEW_MIDEATYPE enMeidaType;       /**< viewˢ��ý������ */
    CALL_E_REFRESHVIEW_EVENT enEvent;               /**< viewˢ���¼� */
} CALL_S_REFRESH_VIEW;


 
/**
 * ����ɹ��¼���Ϣ
 */
typedef struct tagCALL_S_DECODE_SUCCESS
{
    TUP_UINT32 ulCallID;                            /**< ͨ��ID */
    CALL_E_DECODE_SUCCESS_MIDEATYPE enMeidaType;    /**< ý������ */
} CALL_S_DECODE_SUCCESS;


/**
 * ��ƵLEVEL
 */
typedef struct tagCALL_S_VIDEO_LEVEL
{
    TUP_UINT32 ulLevel;         /**< H264��level {10,11,12,13,20,21,22,30,31,32,40,41,42,50,51}  */
    TUP_UINT32 ulMaxMBPS;       /**< H264��max-bmps  0��ʾʹ�ö�Ӧ�����Ĭ��ֵ */
    TUP_UINT32 ulMaxFS;         /**< H264��max-fs    0��ʾʹ�ö�Ӧ�����Ĭ��ֵ */
    TUP_UINT32 ulMaxBR;         /**< H264��max-br    0��ʾʹ�ö�Ӧ�����Ĭ��ֵ */
} CALL_S_VIDEO_LEVEL;


/**
 * SDP O����Ϣ
 */
typedef struct tagCALL_S_SDP_OLINE_INFO
{
    TUP_CHAR acUserName[CALL_D_MAX_LENGTH_NUM];        /**< �û���          eg. "huawei" */
    TUP_CHAR acSessionId[CALL_D_MAX_LENGTH_NUM];       /**< SessionID       eg. "23293" */
    TUP_CHAR acSessionVersion[CALL_D_MAX_LENGTH_NUM];  /**< Session version eg. "1" */
} CALL_S_SDP_OLINE_INFO;


/**
 * SRTP��Ϣ
 */
typedef struct tagCALL_S_SRTP_INFO
{
    TUP_BOOL bMkiMode;                                /**< �Ƿ�֧��MKI��Ĭ�Ϲر� */
    TUP_CHAR acCryptoSuite[CALL_D_MAX_LENGTH_NUM];    /**< �����ף���"1,2"����ʾ1��AES_CM_128_HMAC_SHA1_80(Ĭ��)    2��AES_CM_128_HMAC_SHA1_32*/
} CALL_S_SRTP_INFO;


/**
 * ��Ƶ����
 */
typedef struct tagCALL_S_VIDEO_DATARATE
{
    TUP_UINT32 ulDataRate;              /**< ƽ�����ʣ���λ:bps��ȡֵ[MinDataRate, MaxDataRate]��Ĭ��ֵ4096 */
    TUP_UINT32 ulMinDataRate;           /**< ��С����(��ѡ)����λ:bps��ȡֵ[10, DataRate]��Ĭ��ֵ10  */
    TUP_UINT32 ulMaxDataRate;           /**< �������(��ѡ)����λ:bps��ȡֵ[DataRate, 30000]��Ĭ��ֵ30000  */
    TUP_UINT32 ulMaxBw;                 /**< ��������ӦSDP��AS�ֶΣ���λ:kbps��ȡֵ[64, 2048]��Ĭ��ֵ1920  */
} CALL_S_VIDEO_DATARATE;


/**
 * ��Ƶ֡��
 */
typedef struct tagCALL_S_VIDEO_FRAMERATE
{
    TUP_UINT32 uiFrameRate;             /**< ֡�ʣ���λ:fps��ȡֵ[1, 30]��Ĭ��ֵ30  */
    TUP_UINT32 uiMinFrameRate;          /**< ��С֡�ʣ���λ:fps��ȡֵ[1, FrameRate]��Ĭ��ֵ15  */
} CALL_S_VIDEO_FRAMERATE;


/**
 * ��Ƶ�ֱ���
 */
typedef struct tagCALL_S_VIDEO_FRAMESIZE
{
    TUP_UINT32 uiFramesize;             /**< ����ֱ��� */
    TUP_UINT32 uiMinFramesize;          /**< ��С����ֱ��� */
    TUP_UINT32 uiDecodeFrameSize;       /**< �������ֱ��� */
} CALL_S_VIDEO_FRAMESIZE;


/**
 * ��Ƶ�������������Ϣ
 */
typedef struct tagCALL_S_VIDEO_HDACCELERATE
{
    TUP_UINT32 ulHdEncoder;             /**< ���������� 0:��Ӳ������ 1:Ӳ������ */
    TUP_UINT32 ulHdDecoder;             /**< ���������� 0:��Ӳ������ 1:Ӳ������ */
} CALL_S_VIDEO_HDACCELERATE;


/**
 * ��ƵARS��Ϣ
 */
typedef struct tagCALL_S_VIDEO_ARS
{
    TUP_BOOL bArs;                      /**< �Ƿ�֧��ARS��Ĭ��TURE */
    TUP_BOOL bArsCtrlFec;               /**< �����Զ����ڿ��� trueΪ�򿪣�falseΪ�رգ���ars���ش���Ч��Ĭ��TURE */
    TUP_UINT32 ulMaxFecProFac;          /**< ARS FEC���������ֵ����bArsCtrlFecΪtrueʱ��Ч��Ĭ��ֵ255 */
    TUP_BOOL  bArsCtrlBitRate;          /**< �����Զ����ڿ��� trueΪ�򿪣�falseΪ�رգ���ars���ش���Ч��Ĭ��TURE */
    TUP_BOOL  bArsCtrlFrameRate;        /**< ֡���Զ����ڿ��� trueΪ�򿪣�falseΪ�رգ���ars���ش���Ч��Ĭ��TURE */
    TUP_BOOL  bArsCtrlFrameSize;        /**< �ֱ����Զ����ڿ��� trueΪ�򿪣�falseΪ�رգ���ars���ش���Ч��Ĭ��FALSE */
} CALL_S_VIDEO_ARS;


/**
 * ��Ƶ��ʾ��������
 */
typedef struct tagCALL_S_VIDEO_RENDER_INFO
{
    CALL_E_VIDEOWND_TYPE enRenderType;  /**< ��������ö��ֵ */ 
    TUP_UINT32 ulDisplaytype;           /**< ������ʾģʽ 0:����ģʽ 1:(������)�ڱ�ģʽ 2:(������)�ü�ģʽ 3:(�豣֤���ڳߴ� >= ͼ��ߴ�)��ԭʼ�ֱ�����ʾ */
    TUP_UINT32 ulMirrortype;            /**< ���ھ���ģʽ 0:��������(Ĭ��ֵ) 1:���¾���(Ŀǰδ֧��) 2:���Ҿ��� */
}CALL_S_VIDEO_RENDER_INFO;



/**
 * ��Ƶ����
 */
typedef struct tagCALL_S_VIDEO_ORIENT
{
    TUP_UINT32 ulChoice;         /**< ��Ƶ��������� 1��������2��������3���������  */ 
    TUP_UINT32 ulPortrait;       /**< ������Ƶ������ʱ����ת���Ƕ� 0��0�ȣ�1��90�ȣ�2��180�ȣ�3��270�ȣ�*/ 
    TUP_UINT32 ulLandscape;      /**< ������Ƶ������ʱ����ת���Ƕ� 0��0�ȣ�1��90�ȣ�2��180�ȣ�3��270�ȣ�*/ 
    TUP_UINT32 ulSeascape;       /**< ���������Ƶ������ʱ����ת���Ƕ� 0��0�ȣ�1��90�ȣ�2��180�ȣ�3��270�ȣ�*/ 
}CALL_S_VIDEO_ORIENT; //4


/**
 * RTP�˿ڷ�Χ
 */
typedef struct tagCALL_S_RTP_PORT_RANGE
{
    TUP_UINT32 ulMinPort;       /**< ��С�˿� */ 
    TUP_UINT32 ulMaxPort;       /**< ���˿� */ 
} CALL_S_RTP_PORT_RANGE;


/**
 * BFCP�˿ڷ�Χ
 */
typedef struct tagCALL_S_BFCP_PORT_RANGE
{
    TUP_UINT32 ulMinPort;       /**< ��С�˿� */ 
    TUP_UINT32 ulMaxPort;       /**< ���˿ڣ�Ŀǰ���ã�������չ */
} CALL_S_BFCP_PORT_RANGE;


/**
 * ��Ƶ����(RFC2198)����
 */
typedef struct tagCALL_S_AUDIO_RFC2198
{
    TUP_BOOL bSwitch;               /**< �Ƿ�����2198�ֶ����ࡣ 0�������� 1������ */
    TUP_UINT32 uiRedPT;             /**< ��Ҫ�ֶ������pt����Χ[98,127] */
    TUP_UINT32 uiRedLevel;          /**< ���༶�� [0,3] */
} CALL_S_AUDIO_RFC2198;


/**
 * �ʹ�������
 */
typedef struct tagCALL_S_AUDIO_BAND_LIMIT
{
    TUP_UINT32 uiLowestBandWidth;                               /**< ��Ƶ�ʹ������ƣ��ܴ������ֵ  */
    TUP_CHAR   szLowestAudioCodec[CALL_D_MAX_CODEC_LIST_LEN+1]; /**< ��Ƶ�ʹ��������б�  */

    TUP_UINT32 uiLowerBandWidth;                                /**< С������������Ƶ���У�ʹ�õͱ�����б�  */
    TUP_CHAR   szLowerAudioCodec[CALL_D_MAX_CODEC_LIST_LEN+1];  /**< �ϵʹ��������б� */
} CALL_S_AUDIO_BAND_LIMIT;


/**
 * SRTPģʽ
 */
typedef enum tagCALL_E_SRTP_MODE
{
    CALL_E_SRTP_MODE_DISABLE,       /**< ������ */
    CALL_E_SRTP_MODE_OPTION,        /**< ��ѡ */
    CALL_E_SRTP_MODE_FORCE,         /**< ǿ�� */
    CALL_E_SRTP_MODE_BUTT
} CALL_E_SRTP_MODE;


/**
 * �����ģʽ
 */
typedef enum tagCALL_E_TRANSPORTMODE
{
    CALL_E_TRANSPORTMODE_UDP,       /**< UDP */
    CALL_E_TRANSPORTMODE_TLS,       /**< TLS */
    CALL_E_TRANSPORTMODE_TCP,       /**< TCP */
    CALL_E_TRANSPORTMODE_DEFAULT,   /**< Ĭ��ʹ�ù��ô��䷽ʽ */
    CALL_E_TRANSPORTMODE_SVN,       /**< UDP */
    CALL_E_TRANSPORTMODE_BUTT
} CALL_E_TRANSPORTMODE;


/**
 * ��Ƶ������
 */
typedef struct tagCALL_S_VIDEO_PARAM_SET
{
	TUP_UINT32 ulBps;               /**< ��Ƶ���� */
	TUP_UINT32 ulWidth;             /**< ͼ���� */
	TUP_UINT32 ulHeight;            /**< ͼ��߶� */
	TUP_UINT32 ulFps;               /**< ���֡�� */
	TUP_UINT32 uiMaxBitrate;        /**< ������� */
} CALL_S_VIDEO_PARAM_SET;


/**
 * ��Ƶ������������
 */
typedef struct tagCALL_S_VIDEO_PARAM_TABLE
{
    CALL_S_VIDEO_PARAM_SET *pstVideoParamSet;   /**< ��Ƶ���������� */
    TUP_UINT32 ulTableLineNum;                  /**< ������ */
    TUP_BOOL bVideoSmoother;                    /**< true��ʾ������false��ʾ������ */
    TUP_BOOL bLowerLevel;                       /**< �Ƿ񽵼��� */
} CALL_S_VIDEO_PARAM_TABLE;


/**
 * ��ƵCT����
 */
typedef struct tagCALL_S_VIDEO_CT_LEVEL_SET
{
    TUP_UINT32 ulCT;                /**< CTֵ */
    CALL_S_VIDEO_LEVEL stLevel;     /**< ��Ӧ���� */
} CALL_S_VIDEO_CT_LEVEL_SET;


/**
 * ��ƵCT�����
 */
typedef struct tagCALL_S_VIDEO_CT_LEVEL_TABLE
{
    TUP_UINT32 ulLen;                       /**< ��񳤶� */
    CALL_S_VIDEO_CT_LEVEL_SET *pstLevelSet; /**< ��ƵCT����� */
} CALL_S_VIDEO_CT_LEVEL_TABLE;


/**
 * BFCP����������
 */
typedef enum tagCALL_E_BFCP_START_ERROR
{
    CALL_E_BFCP_START_ERROR_NO_ERROR             = 0,   /**< �����ɹ� */
    CALL_E_BFCP_START_ERROR_REQUEST_FLOOR_DENIED = 1,   /**< ����˾ܾ��������� */ 
    CALL_E_BFCP_START_ERROR_UDP_NETWORK_ERROR    = 2,   /**< udp������ʱ */
    CALL_E_BFCP_START_ERROR_TCP_NETWORK_ERROR    = 3,   /**< TCP��·�쳣��������� */
    CALL_E_BFCP_START_ERROR_NO_RESPOND_FROM_PEER = 4,   /**< ���˷��ͱ���(�ط�)��û���յ��Է���Ӧ */
    CALL_E_BFCP_START_ERROR_REQUEST_FLOOR_FAILED = 5,   /**< ��������ʧ��,Ŀǰ������Э�̽�ɫ�任���� */
    CALL_E_BFCP_START_ERROR_FORCE_REQUEST_FAILED = 6,   /**< ��Ϊc����������ʧ�� */
}CALL_E_BFCP_START_ERROR;



#define TUP_MAX_CODEC_NAME_LEN 31   /**< ��������Ƴ��� */
#define CODEC_NAME_H264           "H264"


/**
 * H264��Ƶ�����������
 */
typedef struct tagCALL_S_VIDEO_H264_QUALITY_LEVEL_PARAM_SET
{
    char       codecName[TUP_MAX_CODEC_NAME_LEN]; /**< �Ѿ�ע������� */
    TUP_UINT8      uiPt;        /**< Ĭ�ϵĸ�������ֵ */
    TUP_UINT16 uiProfileIdc;    /**< ��Ƶ��ʾ����HP:100 MP77 BP:66��Ĭ��ΪBP */
    TUP_UINT8  uiPacketMode;    /**< ���ģʽ,H264����.ȡֵ��Χ[0,1,2],Ӳ�ն�Ŀǰû�� */
    TUP_BOOL blevelAsymmetry;   /**< ���Գ�Э�̱�־λ��trueΪ���Գ�Э�̣�falseΪ�Գ�Э�̣�Ĭ��Ϊ���Գ�Э�� */ 
    TUP_UINT32 uiPriority;      /**< �������ȼ�����1��ʼ��������3��codec�������ȼ�����ֱ�Ϊ1��2��3��������ԽС���ȼ�Խ�� */

}CALL_S_VIDEO_H264_QUALITY_LEVEL_PARAM_SET;


/**
 * H264��Ƶ�������������
 */
typedef struct tagCALL_S_VIDEO_H264_QUALITY_LEVEL_TABLE
{
    TUP_UINT32 uiParamSetNumber;  /**< ��񳤶� */
    CALL_S_VIDEO_H264_QUALITY_LEVEL_PARAM_SET *pstVideoH264QualityLevelParamSet; /**< H264��Ƶ������������� */
}CALL_S_VIDEO_H264_QUALITY_LEVEL_TABLE;


/**
�Ի���INFO ���� �μ�:CALL_D_CFG_SIP_CONTENT_TYPE
*/
typedef struct tagCALL_S_CONTENT_TYPE
{
    TUP_CHAR media_type[CALL_D_MAX_CONTENT_TYPE_LEN];               /**< �Ի��� info ��Ϣ ������*/
    TUP_CHAR sub_media_type[CALL_D_MAX_CONTENT_TYPE_LEN];           /**< �Ի��� info ��Ϣ ������*/
} CALL_S_CONTENT_TYPE;

/**
�Ի���INFO ��Ϣ�ṹ
*/
typedef struct tagCALL_S_DIALOG_INFO
{
    TUP_CHAR media_type[CALL_D_MAX_CONTENT_TYPE_LEN];              /**< �Ի��� info ��Ϣ ������*/
    TUP_CHAR sub_media_type[CALL_D_MAX_CONTENT_TYPE_LEN];          /**< �Ի��� info ��Ϣ ������*/  
    TUP_CHAR body[CALL_D_MAX_INFO_BODY_LEN];                       /**< �Ի��� info ��Ϣ ����*/ 
} CALL_S_DIALOG_INFO;



/**
 * @brief ����ҵ���¼�֪ͨ�ص���������
 * 
 * @param [in] TUP_UINT32 msgid   <b>:</b> �¼�ID @see tagCALL_E_CALL_EVENT
 * @param [in] TUP_UINT32 param1  <b>:</b> ����1������μ���ͬ�¼�ID��˵��
 * @param [in] TUP_UINT32 param2  <b>:</b> ����2������μ���ͬ�¼�ID��˵��
 * @param [in] TUP_VOID *data     <b>:</b> ��Ϣ�������ݣ�����μ���ͬ�¼�ID��˵��
 * @retval typedef TUP_VOID (* <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��ʼ���ɹ�����ã�������Ҫʵ�ֻص��������ص���Ϣָ������������ڲ����������ײ���ܻ��ͷţ����³������
 * @see tup_call_register_process_notifiy
 **/
typedef TUP_VOID (*CALL_FN_CALLBACK_PTR)(TUP_UINT32 msgid, TUP_UINT32 param1, TUP_UINT32 param2, TUP_VOID *data);

/**
 * @brief �������Զ�����־����
 * 
 * @param [in] const TUP_INT8 *app_name  <b>:</b> ģ����
 * @param [in] TUP_UINT32 level          <b>:</b> ��־����
 * @param [in] const TUP_INT8* function  <b>:</b> ������
 * @param [in] const TUP_INT8* filename  <b>:</b> �ļ���
 * @param [in] TUP_UINT32 line_num       <b>:</b> �к�
 * @param [in] const TUP_INT8 *format    <b>:</b> ��ʽ
 * @param [in] ...                       <b>:</b> �ɱ����
 * @retval typedef TUP_VOID (* <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �˺��������������ã���ΪԤ���ӿ�
 * @see tup_call_register_logfun
 **/
typedef TUP_VOID (*CALL_FN_DEBUG_CALLBACK_PTR)(const TUP_INT8 *app_name, TUP_UINT32 level,
                            const TUP_INT8* function, const TUP_INT8* filename, TUP_UINT32 line_num, const TUP_INT8 *format, ...);



#ifdef __cplusplus
#if __cplusplus
}
#endif /*  __cpluscplus */
#endif /*  __cpluscplus */


#endif  /* __CALL_DEF_H__ */

/** @}*/

/*
* History: \n
* 2012-12-10, ��ʼ�����ļ��� \n
* 2015-12-30, TUP V100R001C50 TR5 ���������´��ļ��� \n
 *
* vi: set expandtab ts=4 sw=4 tw=80:
*/

