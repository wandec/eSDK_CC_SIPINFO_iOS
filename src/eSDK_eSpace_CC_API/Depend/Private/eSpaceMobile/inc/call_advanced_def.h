/** 
* @file call_advanced_def.h
* 
* Copyright(C), 2012-2015, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
* 
* ������TUP ������ϵͳ�߼�ҵ����ͷ�ļ��� \n
*/


/**
*
*  @{
*/
 

#ifndef __CALL_ADVANCED_DEF_H__
#define __CALL_ADVANCED_DEF_H__

/*******************************************************************************
 *   ���ļ���Ҫ����������ͷ�ļ�
 *******************************************************************************/
#include "tup_def.h"
#include "call_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /*  __cpluscplus */
#endif /*  __cpluscplus */



#define CALL_D_MAX_STR_LENGTH                       (256)   /**< ͨ���ַ�����󳤶� */
#define CALL_D_512_STR_LENGTH                       (512)   /**< 512�ֽڳ��� */
#define CALL_D_256_STR_LENGTH                       (256)   /**< 256�ֽڳ��� */
#define CALL_D_128_STR_LENGTH                       (128)   /**< 128�ֽڳ��� */
#define CALL_D_64_STR_LENGTH                        (64)    /**< 64�ֽڳ��� */
#define CALL_D_32_STR_LENGTH                        (32)    /**< 32�ֽڳ��� */
#define CALL_D_16_STR_LENGTH                        (16)    /**< 16�ֽڳ��� */

#define CALL_D_AUDIO_EQ_MAX_BANDS                   (10)    /**< ��ƵEQ BAND�����*/
#define CALL_D_MAX_LOCAL_CONFER_CALL_NUM            (5)     /**< ������·��*/

#define CALL_D_MAXNUM_GET_MEETING_INFO_PER_PAGE     (10)    /**< GET CONF LIST ÿ�λ�õ����MEETING ��Ϣ����*/
#define CALL_D_CONF_MAX_PW_LEN                      (10)    /**< ���������������󳤶� */
#define CALL_D_MAX_BITFLAG_LEN                      (33)    /**< ������չ��ʶ���� */
#define CALL_D_MAX_SERVERCONF_ATTENDEE              (20)    /**< ����������� */

#define CALL_D_MAX_HISTORY_NUM                      (5)     /**< ��ʷ��¼�����������IMSǰת*/
#define CALL_D_MAX_FOWARD_NUM                       (24)    /**< ���ǰת���ƿ鴦�����*/
#define CALL_D_MAX_UM_MSG_LENGTH                (4 * 1024)  /**< UM��Ϣ����ֽڳ���*/


#define CALL_D_MAX_PAGING_NUM                       (10)    /**< Paging�����ֵ */
#define CALL_D_MAX_HUNTGROUP_NUM                    (10)    /**< HuntGroup�����ֵ */

#define CALL_D_MAX_PRESET_MSG_LENGTH                (100)   /**< Ԥ����Ϣ�ַ�����󳤶� */
#define CALL_D_MAX_NAMESPACE                        (12)    /**< APP���ֿռ���󳤶� */

#define CALL_D_EADDR_ENTERPRISE_STAFFNO_LEN         32      /**< ������󳤶�*/
#define CALL_D_EADDR_ENTERPRISE_STAFFACCOUNT_LEN    128     /**< �˺���󳤶�*/
#define CALL_D_EADDR_ENTERPRISE_NAME_LEN            128     /**< ������󳤶�*/
#define CALL_D_EADDR_ENTERPRISE_NUM_LEN             33      /**< ������󳤶�*/
#define CALL_D_EADDR_ENTERPRISE_DEPT_LEN            256     /**< ����������󳤶�*/
#define CALL_D_EADDR_ENTERPRISE_COMMON_LEN          128     /**< ͨ����󳤶�*/
#define CALL_D_EADDR_ENTERPRISE_EMAIL_LEN           256     /**< EMAIL��󳤶�*/
#define CALL_D_EADDR_ENTERPRISE_URI_LEN             128     /**< URI��󳤶�*/
#define CALL_D_EADDR_ENTERPRISE_AVATARID_LEN        (144)   /**< ͷ��ID��󳤶� */
#define CALL_D_EADDR_ENTERPRISE_ADDRESS_LEN         256     /**< ��ַ��󳤶�*/

#define CALL_CONF_SUBJECT_MAX_STR_LEN               (1024)  /**< ����������󳤶�*/


/**
 * ������Ƶ����Ԥ��ʱ��ʹ�õĽṹ��
 */
typedef struct tagCALL_S_VIDEOCONF_VIDEO_PARAM
{
    TUP_UINT32 xResolution;     /**< x�ֱ���(��) */
    TUP_UINT32 yResolution;     /**< y�ֱ���(��) */
    TUP_UINT32 nBitRate;        /**< ����*/
} CALL_S_VIDEOCONF_VIDEO_PARAM;


/**
 * ��Ƶ�����豸�β�
 */
typedef enum tagCALL_E_VIDEOCONF_DEVICE_INPUT_STATUS
{
    CALL_E_VIDEOCONF_DEVICE_INPUT_STATUS_START,     /**< ��Ч  */
    CALL_E_VIDEOCONF_DEVICE_INPUT_STATUS_INPUT,     /**< ����  */
    CALL_E_VIDEOCONF_DEVICE_INPUT_STATUS_OUTPUT,    /**< �γ�  */
    CALL_E_VIDEOCONF_DEVICE_INPUT_STATUS_BUTT
} CALL_E_VIDEOCONF_DEVICE_INPUT_STATUS;


/** 
 * ��Ƶ�����豸״̬
 */
typedef enum tagCALL_E_VIDEOCONF_DEVICE_STATUS
{
    CALL_E_VIDEOCONF_DEVICE_LOCAL_STATUS_CLOSE = 0, /**< �ر�״̬  */
    CALL_E_VIDEOCONF_DEVICE_LOCAL_STATUS_OPEN = 1,  /**< ��״̬  */
    CALL_E_VIDEOCONF_DEVICE_LOCAL_STATUS_RESUME = 2,/**< �ָ�  */
    CALL_E_VIDEOCONF_DEVICE_LOCAL_STATUS_PAUSE = 4, /**< ��ͣ  */
    CALL_E_VIDEOCONF_DEVICE_LOCAL_STATUS_ERROR = 5, /**< ����״̬  */
    CALL_E_VIDEOCONF_DEVICE_LOCAL_STATUS_BUTT
} CALL_E_VIDEOCONF_DEVICE_STATUS;


/** 
 * ��ҵ��ַ������
 */
typedef enum tagCALL_E_EUA_TYPE
{
    CALL_E_EUA_TYPE_INVALID = 0,                    /**< ��Ч���� */
    CALL_E_EUA_TYPE_FTP,                            /**< FTP���� */
    CALL_E_EUA_TYPE_LDAP                            /**< LDAP���� */
}CALL_E_EUA_TYPE;


/** 
 * ��Ƶ����˫��״̬
 */
typedef struct tagCALL_S_VIDEOCONF_DOUBLESTREAM_STATUS
{
    TUP_CHAR szAttendNum[CALL_D_MAX_STR_LENGTH];    /**< ����ߺ��� */ 
    TUP_UINT32 xResolution;                         /**< x�ֱ���(��)  */
    TUP_UINT32 yResolution;                         /**< y�ֱ���(��)  */

    TUP_UINT32 bHighOrLowChannel;                   /**< ��ǰ���뵽�������ǵ���  */
    TUP_UINT32  bDoubleStream;                      /**< �Ƿ�˫��  */
    TUP_BOOL bOwnLowStream;                         /**< �Ƿ�ӵ�е���  */
    TUP_BOOL bFlowCtrl;                             /**< �Ƿ������ظ澯����  */
} CALL_S_VIDEOCONF_DOUBLESTREAM_STATUS;


/** 
 * ͨ��IPTҵ����Ϣ����
 */
typedef struct tagCALL_S_SERVICE_INFO
{
    TUP_UINT32   ulRight;                                           /**< ҵ��Ȩ��״̬ @see tagCALL_E_SEVICERIGHT_STATUS */
    TUP_UINT32   ulRegister;                                        /**< ҵ��Ǽ�״̬ @see tagCALL_E_SEVICEREGISTER_STATUS */
    TUP_CHAR     acActiveAccessCode[CALL_D_ACCESSCODE_MAX_LENGTH];  /**< �Ǽ������� */
    TUP_CHAR     acDeactiveAccessCode[CALL_D_ACCESSCODE_MAX_LENGTH];/**< ע�������� */
} CALL_S_SERVICE_INFO;



/**
 * IPTҵ��������Ϣ
 */
typedef struct tagCALL_S_SERVICE_PARAM
{
    TUP_CHAR         acCallForwardUnconditionNum[CALL_D_MAX_LENGTH_NUM];/**< ������ǰת���� */
    TUP_CHAR         acCallForwardOnBusyNum[CALL_D_MAX_LENGTH_NUM];     /**< ��æǰת���� */ 
    TUP_CHAR         acCallForwardNoReplyNum[CALL_D_MAX_LENGTH_NUM];    /**< ��Ӧ��ǰת���� */ 
    TUP_CHAR         acCallForwardOfflineNum[CALL_D_MAX_LENGTH_NUM];    /**< ��Ӧ��ǰת���� */ 
    TUP_CHAR         acVoiceMailGetNum[CALL_D_MAX_LENGTH_NUM];          /**< ����������ȡ���� */
    TUP_CHAR         acTurnPhoneNum[CALL_D_MAX_LENGTH_NUM];             /**< �ֻ��ֻ�:ת�Ƶ����������� */
    TUP_CHAR         acTurnMobileNum[CALL_D_MAX_LENGTH_NUM];            /**< �ֻ��ֻ�:ת�Ƶ��ֻ������� */
    TUP_UINT32       ulEaddrSearchType;                                 /**< ��ҵ��ַ���������� TODO */
    TUP_CHAR         acAbbrDial[CALL_D_ACCESSCODE_MAX_LENGTH];          /**< ��λ����ҵ�������� */
    TUP_UINT32       ulVoiceMailSupportType;                            /**< ��������֧�����ͣ�Ԥ���ֶΣ���δʹ�� */
    TUP_CHAR         acVoiceMailNumber[CALL_D_MAX_LENGTH_NUM];          /**< ����������� */
    TUP_CHAR         acVoiceMailSPIN[CALL_D_MAX_LENGTH_NUM];            /**< ����������ȡ��SPIN���� */
    TUP_UINT32       ulVVMHttpsSupport;                                 /**< vvm�Ƿ�֧��https */

    TUP_UINT32       ulCallLimitType;                                   /**< �����޺����� TODO */
    TUP_CHAR         acCallLimitCode[CALL_D_MAX_LENGTH_NUM];            /**< �����޺������� */

    TUP_UINT32       ulHotLineEnable;                                   /**< ����ʹ�ܱ�ʶ */
    TUP_CHAR         acHotLineNumber[CALL_D_128_STR_LENGTH];            /**< ���ߺ��� */
    TUP_UINT32       ulHotLineDelayTime;                                /**< ����ʱ�� */
    TUP_UINT32       ulHotLineType;                                     /**< �������� */

    TUP_BOOL         bIsChangeCFUNum;                                   /**< �Ƿ������������ǰת���� */

} CALL_S_SERVICE_PARAM;


/** 
 * ���ؽ����յ���message ��������meeting ��Ϣת�������洦�� TODO
 */
typedef struct tagCALL_S_UM_MEETING_MSG
{
    TUP_CHAR acMeetingTopic[CALL_D_MAX_STR_LENGTH];         /**< ��������*/
    TUP_CHAR acMeetingTime[CALL_D_64_STR_LENGTH];           /**< ����ʱ��*/
    TUP_CHAR acConvener[CALL_D_64_STR_LENGTH];              /**< �����ټ���*/
    TUP_CHAR acAttendee[CALL_D_MAX_SERVERCONF_ATTENDEE* CALL_D_64_STR_LENGTH];  /** ���������,���20��*/
    TUP_CHAR acHost[CALL_D_64_STR_LENGTH];                  /**< ������*/
    TUP_CHAR acHostID[CALL_D_64_STR_LENGTH];                /**< ������id*/
    TUP_CHAR acConfID[CALL_D_128_STR_LENGTH];               /**< ����id*/
    TUP_CHAR acAccessNumber[CALL_D_64_STR_LENGTH];          /**< ���������*/
    TUP_CHAR acSecurityCode[CALL_D_64_STR_LENGTH];          /**< ���鰲ȫ�ţ���ϯ����*/
    TUP_CHAR acStartDate[CALL_D_64_STR_LENGTH];             /**< ���鿪ʼʱ��*/
    TUP_CHAR acValidityPeriodDate[CALL_D_64_STR_LENGTH];    /**< ������Чʱ��*/
    TUP_CHAR acIMContent[CALL_D_MAX_STR_LENGTH * 2];        /**< ��������*/
} CALL_S_UM_MEETING_MSG;

/**
 * ҵ��Ȩ��������
 */
typedef struct tagCALL_S_SERVICERIGHT_CFG
{
    CALL_S_SERVICE_INFO   astSrvInfo[CALL_E_SERVICE_RIGHT_TYPE_BUTT];  /**< IPTҵ����Ϣ��������CALL_E_SERVICE_RIGHT_TYPE ��Ӧ */
    CALL_S_SERVICE_PARAM  stServiceParam;           /**< IPTҵ��������Ϣ */
    TUP_CHAR acIntercomNum[CALL_D_MAX_LENGTH_NUM];  /**< intercom���� */
} CALL_S_SERVICERIGHT_CFG;


/**
 * ������·״̬
 */
typedef enum tagCALL_E_SCASTATE
{
    CALL_E_SCASTATE_IDLE,                /**< ����״̬ */
    CALL_E_SCASTATE_SEIZED,              /**< ռ��״̬ */
    CALL_E_SCASTATE_ALERTING,            /**< ���������� */
    CALL_E_SCASTATE_ACTIVE,              /**< ͨ���� */
    CALL_E_SCASTATE_PROGRESSING,         /**< ������ */
    CALL_E_SCASTATE_HELD,                /**< ����״̬ */
    CALL_E_SCASTATE_HELD_PRIVATE,        /**< ˽�˱���״̬ */
    CALL_E_SCASTATE_BRIDGE_ACTIVE,       /**< bridge����״̬ */
    CALL_E_SCASTATE_LOCK,                /**< ˽�л�״̬ */
    CALL_E_SCASTATE_TERM,                /**< �����ս�*/
    CALL_E_SCASTATE_BUTT
} CALL_E_SCASTATE;


/**
 * ���ػ���᳡״̬
 */
typedef enum tagCALL_E_LOCAL_CONF_STATE
{
    CALL_E_LOCAL_CONF_STATE_IDLE,        /**< �������̬ */
    CALL_E_LOCAL_CONF_STATE_INIT,        /**< �����ʼ̬ */
    CALL_E_LOCAL_CONF_STATE_LIVE,        /**< ���鼤��̬ */
    CALL_E_LOCAL_CONF_STATE_HOLD,        /**< ���鱣��̬ */
    CALL_E_LOCAL_CONF_STATE_END,         /**< �������̬ */
    CALL_E_LOCAL_CONF_STATE_BUTT         /**< ������Ч̬ */
} CALL_E_LOCAL_CONF_STATE;


/**
 * ���ػ���Ļ�������
 */
typedef enum tagCALL_E_LOCAL_CONF_TYPE
{
    CALL_E_LOCAL_CONFTYPE_HOLD,         /**< ��������ʱ�᳡������*/
    CALL_E_LOCAL_CONFTYPE_NOHOLD,       /**< ��������ʱ�᳡�ճ�����(���豣�ֻ᳡)*/
    CALL_E_LOCAL_CONF_BUTT
} CALL_E_LOCAL_CONF_TYPE_ENUM;


/**
 * ����߷���״̬
 */
typedef enum tagCALL_E_LOCAL_CONFREE_TALK_STATE
{
    CALL_E_LOCAL_CONFREE_TALK_STATE_IDLE,       /**< ����̬ */
    CALL_E_LOCAL_CONFREE_TALK_STATE_SPEAKING,   /**< ����̬ */
    CALL_E_LOCAL_CONFREE_STATE_BUTT             /**< ��Ч̬ */
} CALL_E_LOCAL_CONFREE_TALK_STATE;


/** 
 * �����޺�����
 */
typedef enum tagCALL_E_CALL_LIMIT_TYPE
{
    CALL_E_CALL_LIMIT_NONE,                     /**< ������ */
    CALL_E_CALL_LIMIT_HOME,                     /**< �����޺� */
    CALL_E_CALL_LIMIT_INTERNATIONAL,            /**< �����޺� */
    CALL_E_CALL_LIMIT_BOTH,                     /**< �����޺�+�����޺� */
    CALL_E_CALL_LIMIT_BUTT
} CALL_E_CALL_LIMIT_TYPE;


/**
 * ��ϵ��״̬
 */
typedef enum  tagCALL_E_CONTACT_STATUS
{
    CALL_E_CONTACT_STATUS_OFFLINE,       /**< ���ߣ����ֳ���---���նˡ�Ӳ�նˡ�CC�ϱ���BLF(Subscription-State: terminated;reason=probation) */
    CALL_E_CONTACT_STATUS_ONLINE,        /**< ���У����ֳ���---���նˡ�Ӳ�նˡ�BLF(terminated) */
    CALL_E_CONTACT_STATUS_BUSY,          /**< æµ�����ֳ���---���ն� */
    CALL_E_CONTACT_STATUS_LEAVE,         /**< �뿪�����ֳ���---���ն� */
    CALL_E_CONTACT_STATUS_DND,           /**< DND �����ֳ���---���նˡ�Ӳ�ն� */
    CALL_E_CONTACT_STATUS_CALLING,       /**< ͨ���У����ֳ���---���նˡ�Ӳ�նˡ�CC�ϱ���BLF(confirmed) */
    CALL_E_CONTACT_STATUS_BUSY_CALLING,  /**< �����У����ֳ���---���� */
    CALL_E_CONTACT_STATUS_BUSY_MEETING,  /**< ������������ */

    CALL_E_CONTACT_STATUS_RINGING,       /**< �������壬���ֳ���---CC�ϱ���BLF(early) */
    CALL_E_CONTACT_STATUS_DAILNUM,       /**< ժ�����ţ����ֳ���---CC�ϱ� */
    CALL_E_CONTACT_STATUS_OFFHOOK,       /**< ժ�������ֳ���---CC�ϱ� */
    CALL_E_CONTACT_STATUS_ONHOOK,        /**< �һ������ֳ���---CC�ϱ� */

    CALL_E_CONTACT_STATUS_UNDND,         /**< ȡ��DND �����ֳ���---���նˡ�Ӳ�նˣ������ڷ���! */
    CALL_E_CONTACT_STATUS_UNBUSY,        /**< ȡ��æµ�������뷢��! */

    CALL_E_CONTACT_STATUS_UNKNOWN,       /**< δ֪״̬  */
    CALL_E_CONTACT_STATUS_PHONE_ONLINE,  /**< ��������  */
    CALL_E_CONTACT_STATUS_BUTT           /**< ��Ч״̬ */
} CALL_E_CONTACT_STATUS;


/** 
 * ��������������
 */
typedef enum tagCALL_E_CONFTYPE
{
    CALL_E_CONFTYPE_PRERECE_VOICE = 10,  /**< �ںϻ�������*/
    CALL_E_CONFTYPE_PRERECE_VIDEO,       /**< �ںϻ�����Ƶ*/
    CALL_E_CONFTYPE_PRERECE_MULTIMEDIA,  /**< �ںϻ����ý��*/
    CALL_E_CONFTYPE_UC_VOICE,            /**< UC��������*/
    CALL_E_CONFTYPE_UC_VIDEO,            /**< UC��ʱ��Ƶ����*/
    CALL_E_CONFTYPE_UC_MULTIMEDIA,       /**< UC��ý�����*/
    CALL_E_CONFTYPE_BUTT
} CALL_E_CONFTYPE;


/** 
 * �Ƿ���ʾ���ն˺���
 */
typedef enum tagCALL_E_LINKAGE_STATE 
{
    CALL_E_LINKAGE_STATE_DISPSOFTTEL,      /**< ��ʾ */
    CALL_E_LINKAGE_STATE_NOT_DISPSOFTTEL,  /**< ����ʾ */
    CALL_E_LINKAGE_STATE_BUTT       
}CALL_E_LINKAGE_STATE;


/**
 * ��֤��ʽ
 */
typedef enum tagCALL_E_AUTH_TYPE 
{
    CALL_E_AUTH_TYPE_NO,        /**< ��̬ע��δ��֤ */
    CALL_E_AUTH_TYPE_LOCAL,     /**< ����ע�� */
    CALL_E_AUTH_TYPE_EXTERNAL,  /**< �ⲿע�� */     
    CALL_E_AUTH_TYPE_BUTT
}CALL_E_AUTH_TYPE;


/**
 * ��ϵ����Ϣ
 */
typedef struct tagCALL_S_CONTACT_INFO
{
    TUP_UINT32  ulIndex;                                            /**< ��ǰ������·��ʶ */
    TUP_INT8    StaffAccount[CALL_D_EADDR_ENTERPRISE_STAFFACCOUNT_LEN]; /**< UC�˺� */
    TUP_INT8    PersonName[CALL_D_EADDR_ENTERPRISE_NAME_LEN];       /**< ���� */
    TUP_UINT32  Sex;                                                /**< �Ա� */
    TUP_INT8    Staffno[CALL_D_EADDR_ENTERPRISE_STAFFNO_LEN] ;      /**< ���� */
    TUP_INT8    IPNum[CALL_D_EADDR_ENTERPRISE_NUM_LEN];             /**< IP���� */
    TUP_INT8    DeptName[CALL_D_EADDR_ENTERPRISE_DEPT_LEN];         /**< �������� */
    TUP_INT8    Title[CALL_D_EADDR_ENTERPRISE_COMMON_LEN];          /**< ְ�� */
    TUP_INT8    CellPhone[CALL_D_EADDR_ENTERPRISE_NUM_LEN];         /**< �ֻ����� */
    TUP_INT8    Seatphone[CALL_D_EADDR_ENTERPRISE_NUM_LEN];         /**< �������� */
    TUP_INT8    Otherphone[CALL_D_EADDR_ENTERPRISE_NUM_LEN];        /**< ������� */
    TUP_INT8    Otherphone2[CALL_D_EADDR_ENTERPRISE_NUM_LEN];       /**< �������2 */
    TUP_INT8    homephone[CALL_D_EADDR_ENTERPRISE_NUM_LEN];         /**< ��ͥ���� */
    TUP_INT8    Email[CALL_D_EADDR_ENTERPRISE_EMAIL_LEN];           /**< email */
    TUP_INT8    Address[CALL_D_EADDR_ENTERPRISE_ADDRESS_LEN];       /**< ��ַ */
    TUP_UINT32  ulState;                                            /**< ����״̬ TODO */
    TUP_INT8    acuriDomain[CALL_D_EADDR_ENTERPRISE_URI_LEN];       /**< TODO */
    TUP_INT8    acAvatarID[CALL_D_EADDR_ENTERPRISE_AVATARID_LEN];   /**< ͷ��ID */
    CALL_E_LINKAGE_STATE    enLinkageState;                         /**< ���ն˺�����ʾ״̬ */
} CALL_S_CONTACT_INFO, *CALL_S_CONTACT_INFO_PTR;

/**
 * ��ϵ�˼���״̬��Ϣ
 */
typedef struct tagCALL_S_CONTACT_STATUS
{
    TUP_UINT32 ulSipAccountID;              /**< �˺�ID */
    TUP_CHAR acNo[33];                      /**< ���� */
    CALL_E_CONTACT_STATUS enContactStatus;  /**< ״̬ */
} CALL_S_CONTACT_STATUS, *CALL_S_CONTACT_STATUS_PTR;


/** 
 * ״̬��Ϣ
 */
typedef struct tagCALL_S_STATUS
{
    TUP_UINT32 ulNum;                       /**< ��ϵ�˼���״̬��Ϣ���� */
    CALL_S_CONTACT_STATUS* pstStatus;       /**< ��ϵ�˼���״̬��Ϣ���� */
} CALL_S_STATUS, *CALL_S_STATUS_PTR;


/**
 * ��ϵ��״̬֪ͨ
 */
typedef struct tagCALL_S_CONTACT_NTF
{
    TUP_UINT8  ucContactNameLen;            /**< ��ϵ�˱������� */
    TUP_UINT8  ucOnlineState;               /**< ����״̬: 1-���У�����-��æ */
    TUP_UINT8  ucProtocolType;              /**< Э������ 0-H323, 2-SIP */
    TUP_CHAR   acContactName[CALL_D_256_STR_LENGTH]; /**< ��ϵ�˱��� */
}CALL_S_CONTACT_NTF, *CALL_S_CONTACT_NTF_PTR;


/**
 * ����״̬����֪ͨ(����huawei_ido)
 */
typedef struct tagCALL_S_IDO_ONLINE
{
    TUP_UINT32 ulErrCode;               /**< �����붨��:0-�ɹ���0x1-δ�������߹��� 0x2-�����ն������� 0xffffffff-ϵͳ�ڲ����� */
    TUP_BOOL bIsLastPack;               /**< �Ƿ����һ�� */
    TUP_UINT16 uContactCount;           /**< �˺Ÿ��� */
    CALL_S_CONTACT_NTF *pstContactInfo; /**< ��ϵ����Ϣ */
}CALL_S_IDO_ONLINE, *CALL_S_IDO_ONLINE_PTR;


/**
 * �����ַ������֪ͨ(����huawei_ido)
 */
typedef struct tagCALL_S_IDO_NETADDRESS
{
    CALL_E_EUA_TYPE eEUAType;                       /**< EUA���� ftp ���� ldap */
    TUP_CHAR  acAddress[CALL_D_512_STR_LENGTH];     /**< ��������ַ�������ַ�á�;������ */
    TUP_CHAR  acUserName[CALL_D_MAX_STR_LENGTH];    /**< �û��� */
    TUP_UINT32 uiPasswordLen;                       /**< ����� */
    TUP_CHAR  acPassword[CALL_D_MAX_STR_LENGTH];    /**< ���� */
    TUP_CHAR  acFilePath[CALL_D_MAX_STR_LENGTH];    /**< ��ַ���ļ�·�� */
    TUP_CHAR  acDNValue[CALL_D_MAX_STR_LENGTH];     /**< DNֵ */
    TUP_CHAR  acVersion[CALL_D_MAX_STR_LENGTH];     /**< �汾��Ϣ */
}CALL_S_IDO_NETADDRESS, *CALL_S_IDO_NETADDRESS_PTR;


/** �˺ű���(����huawei_ido) */
typedef struct tagCALL_S_IDO_FORCEUNREG
{
    TUP_BOOL   bIsKickOff;                              /**< �Ƿ��ߣ�4�ֽ� */
    TUP_UINT8  ucIpType;                                /**< ��ַ���ͣ�1�ֽ� */
    TUP_UINT8  acIpAddress[CALL_D_16_STR_LENGTH + 1];   /**< ��ַ��16�ֽ�*/
}CALL_S_IDO_FORCEUNREG, *CALL_S_IDO_FORCEUNREG_PTR;


/**
 * ͬ�����֪ͨ�ϱ���ϢЯ��������
*/
typedef struct tagCALL_S_TIPINFO
{
    TUP_CHAR acCallerNo[CALL_D_MAX_STR_LENGTH];   /**< ���к��� */
    TUP_CHAR acRingNo[CALL_D_MAX_STR_LENGTH];     /**< ������� */
} CALL_S_TIPINFO, *CALL_S_TIPINFO_PTR;


/**
 * ����������Ϣ
 */
typedef struct tagCALL_S_JOINT_CMD_INFOS
{
    TUP_UINT32 ulSipAccountID;                  /**< �˺�ID */
    TUP_UINT32 ulCallID;                        /**< ����ID */
    TUP_UINT32 ulTransferOriginID;              /**< TODO */
    TUP_UINT32 ulConfID;                        /**< ����ID */
    TUP_UINT32 ulLineID;                        /**< ��·ID */
    CALL_E_CALL_EVENT enJointCmdMsg;            /**< ��Ϣ���� */
    TUP_CHAR acCallNum[CALL_D_MAX_STR_LENGTH];  /**< �绰���� */
    TUP_UINT32  ulCallNumLen;                   /**< �绰���볤�� */
    TUP_UINT32 ulResult;                        /**< 0 : �ɹ�������: ʧ��*/
} CALL_S_JOINT_CMD_INFOS;


/**
 * ���������ںϻ����ϱ�֪ͨ��Ϣ�ṹ
 */
typedef struct tagCALL_S_JOINMSCONF_INFO
{
    TUP_UINT32 ulSipAccountID;                      /**< �˺�ID */
    TUP_UINT32 ulCallID;                            /**< ����ID */
    TUP_UINT32 ulConfID;                            /**< ����ID */
    CALL_E_CONFTYPE enConfType;                     /**< �������� */
    TUP_CHAR acConfId[CALL_D_MAX_PASSCODE_LENGTH];  /**< ��������� */ 
} CALL_S_JOINMSCONF_INFO;


#define CALL_D_CTD_BIND_NUM_MAX_LEN 255             /**< CTD�󶨺�����󳤶� */


/**
 * CTD ֪ͨ��Ϣ�ṹ
 */
typedef struct tagCALL_S_CTD_INFO_BODY
{
    TUP_UINT32   ulServiceType;     /**< ҵ�����ͣ������������� */
    TUP_UINT32   ulCmdType;         /**< �������ͣ������������� */
    TUP_UINT32   ulCtdCallId;       /**< CTD����ID */
    TUP_CHAR     acAttendeeEid[64][CALL_D_CTD_BIND_NUM_MAX_LEN + 1]; /**< Ԥ������δʹ�� */
    TUP_UINT32   ulAttendeeNum;     /**< Ԥ������δʹ�� */
    TUP_CHAR     acCtdCallerNum[CALL_D_CTD_BIND_NUM_MAX_LEN + 1];   /**< CTD���к��� */
    TUP_CHAR     acCtdCalleeNum[CALL_D_CTD_BIND_NUM_MAX_LEN + 1];   /**< CTD���к��� */
}CALL_S_CTD_INFO_BODY;


/**
 * ��ƵEQ��������
 */
typedef enum tagCALL_E_EQ_PARAMS_DIRECTION
{
    CALL_E_EQ_PARAMS_DIRECTION_NONE = 0x00,
    CALL_E_EQ_PARAMS_DIRECTION_UP   = 0x01,       /**< ���з������ */
    CALL_E_EQ_PARAMS_DIRECTION_DOWN = 0x02,       /**< ���з������ */

    CALL_E_EQ_PARAMS_DIRECTION_INVALID = 0xff
}CALL_E_EQ_PARAMS_DIRECTION;


/**
 * ��ƵEQ����
 */
typedef struct tagCALL_S_AUDIO_EQ_PARAMS
{
    TUP_INT32 iSampleRate;                           /**< �����ʣ�֧��8000��16000��48000���ֲ�����*/

    TUP_INT32 iBand_Q[CALL_D_AUDIO_EQ_MAX_BANDS];    /**< Ƶ�ʿ�ȣ�����ֵΪ�˲���Qֵ��Ӧ��Q26����ֵ��Ҫ������
                                                        <br> 1����һ���˲��������һ���˲�������Ϊ����˲������м�Ϊ��ֵ�˲���
                                                        <br> 2������˲���Qֵ���÷�Χ[0.03125, 0.70711]����ӦQ26����ֵ[94906266, 2147483647]
                                                        <br> 3����ֵ�˲���Qֵ���÷�Χ[0.03125, 64]����ӦQ26����ֵ[1048576, 2147483647]*/
    TUP_INT16 sBand_f0[CALL_D_AUDIO_EQ_MAX_BANDS];   /**< �ɵ�Ƶ������Ƶ�ʣ���ͬ�����ʡ���ͬ�˲�����Χ��ͬ��Ҫ������:
                                                        <br> ������8K:��Ƶ����˲�������һƵ�Σ�����Ƶ�ʷ�ΧΪ:10Hz~2000Hz
                                                        <br> ��ֵ�˲������м�Ƶ�Σ�����Ƶ�ʷ�ΧΪ:60Hz~3000Hz
                                                        <br> ��Ƶ����˲��������Ƶ�Σ�����Ƶ�ʷ�ΧΪ:1000Hz~3800Hz
                                                        <br> ������16K:��Ƶ����˲�������һƵ�Σ�����Ƶ�ʷ�ΧΪ:10Hz~4000Hz
                                                        <br> ��ֵ�˲������м�Ƶ�Σ�����Ƶ�ʷ�ΧΪ:60Hz~6000Hz
                                                        <br> ��Ƶ����˲��������Ƶ�Σ�����Ƶ�ʷ�ΧΪ:1000Hz~7800Hz
                                                        <br> ������48K:��Ƶ����˲�������һƵ�Σ�����Ƶ�ʷ�ΧΪ:10Hz~8000Hz
                                                        <br> ��ֵ�˲������м�Ƶ�Σ�����Ƶ�ʷ�ΧΪ:60Hz~16000Hz
                                                        <br> ��Ƶ����˲��������Ƶ�Σ�����Ƶ�ʷ�ΧΪ:1000Hz~22000Hz */
    TUP_INT16 sDBgain[CALL_D_AUDIO_EQ_MAX_BANDS];    /**< �ɵ�Ƶ�����棬���÷�Χ[-24, 24]dB*/
                                                          
    TUP_INT32 iNBand;                                /**< Ƶ���������÷�Χ[0, 10]��0����ر�EQ*/

    TUP_INT32 iACLPEnabled;                          /**< ����ģ���־: 1��ʾ������0��ʾ�ر�*/

}CALL_S_AUDIO_EQ_PARAMS;


/**
 * ��ƵAEC����
 */
typedef struct tagCALL_S_AUDIO_AEC_PARAMS
{
    TUP_UINT8   ucCngMode;              /**< ��������ģʽ: ��رգ�����򿪣�Ĭ�ϴ�, */  
    TUP_UINT8   ucPureDelay;            /**< ������, ȡֵ<br>0:0ms, 1:10ms, 2:20ms, 3:30ms, 4:40ms, 5:50ms, 6:60ms, Ĭ��Ϊ0ms*/
    TUP_UINT16  usNearAllPassEnergy;    /**< �жϽ����Ƿ�͸����Զ��������ֵ, ȡֵ<br>0:-59dBm0, 1:-49dBm0, 2:-39dBm0, Ĭ��Ϊ1 */
    TUP_UINT8   ucNearCleanSupEnergy;   /**< �жϽ����Ƿ�Ϊ������֡����ֵ, ȡֵ<br>0:12dB, 1:15dB, 2:18dB, Ĭ��Ϊ2,  */
    TUP_UINT8   ucMode;                 /**< ����ģʽ��ȡֵ<br>0:��Ͳ, 1:����, Ĭ��Ϊ��Ͳģʽ */
    TUP_UINT8   ucSampleRate;           /**< ������, ȡֵ<br>0:8K,1:16K,2:24K,3:48K, Ĭ��Ϊ48K, Ŀǰ��֧��24K������ */
}CALL_S_AUDIO_AEC_PARAMS;


/**
 * ��ƵEQ���ò���
 */
typedef struct tagCALL_S_AUDIO_EQ_CONFIG
{
    CALL_E_EQ_PARAMS_DIRECTION   eParamsDirection;  /**< ������־λ������or���� CALL_E_EQ_PARAMS_DIRECTION*/
    TUP_INT32 iMode;                                /**< EQ״̬����0��ʾ��EQ��0��ʾ�ر�EQ */
    CALL_S_AUDIO_EQ_PARAMS stEqCfg_8K;              /**< ������Ϊ8Kʱ��EQ�����б� */
    CALL_S_AUDIO_EQ_PARAMS stEqCfg_16K;             /**< ������Ϊ16Kʱ��EQ�����б� */
    CALL_S_AUDIO_EQ_PARAMS stEqCfg_48K;             /**< ������Ϊ48Kʱ��EQ�����б� */
    TUP_CHAR acVolMap[CALL_D_MAX_STR_LENGTH];       /**< ��������ĵ��ڷ�Χӳ����ö��ŷֿ�ÿ��ֵ */
    TUP_UINT32 ulMicVolume;                         /**< MIC��������[0-10000] */
}CALL_S_AUDIO_EQ_CONFIG;




/**
 * ��ǰ��������Ϣ
 */
typedef struct tagCALL_S_CURRENT_SIPSERVER
{
    TUP_CHAR acCurrentRegAddress[CALL_D_MAX_STR_LENGTH];    /**< ��ǰʹ�õ�SIPע���������ַ */
    TUP_UINT32 ulCurrentRegPort;                            /**< ��ǰʹ�õ�SIPע��������˿� */

    TUP_CHAR acCurrentProxyAddress[CALL_D_MAX_STR_LENGTH];  /**< ��ǰʹ�õĴ����������ַ */
    TUP_UINT32 ulCurrentProxyPort;                          /**< ��ǰʹ�õĴ���������˿� */
} CALL_S_CURRENT_SIPSERVER;


/**
 * SIP��ַ��Ϣ
 */
typedef struct tagCALL_S_SIP_ADDR_INFO
{
    TUP_CHAR acSipAddress[CALL_D_64_STR_LENGTH];
    TUP_INT32 iPort;
} CALL_S_SIP_ADDR_INFO;


/**
 * �������Ϣ
 */
typedef struct tagCALL_S_CONFEREE_INFO
{
    TUP_UINT32 ulCallID;                              /**< �������·ͨ��ID����ЧIDΪ0xFFFFFFFF */
    TUP_BOOL bIsMuted;                                /**< ������Ƿ񱻾��� */
    CALL_E_LOCAL_CONFREE_TALK_STATE enTalkState;      /**< �����˵��״̬ */
} CALL_S_CONFEREE_INFO;



/**
 * �������·�б�
 */
typedef struct tagCALL_S_CONFER_CALLID_LIST
{
    CALL_S_CONFEREE_INFO astConfereeList[CALL_D_MAX_LOCAL_CONFER_CALL_NUM];    /**< ������б�*/
    TUP_UINT32 ulCnt;                                                          /**< ��������� */
} CALL_S_CONFER_CALLID_LIST;



/**
 * ���ػ�����Ϣ
 */
typedef struct tagCALL_S_CONFER_LOCAL_INFO
{
    TUP_UINT32 ulConfID;                          /**< ���ػ���᳡ID */
    TUP_UINT32 ulSipAccountID;                    /**< ���ػ�����ϯSipID */
    TUP_UINT32 ulCreatorCallID;                   /**< �����᳡��·��CallID */
    TUP_UINT32 ulCreatorLineID;                   /**< ���鴴����·��ID */
    CALL_E_LOCAL_CONF_STATE   enConfState;        /**< �᳡״̬ */
    CALL_E_LOCAL_CONF_TYPE_ENUM enLocConfType;    /**< ���ػ�������*/
    CALL_S_CONFER_CALLID_LIST stConfCallIDList;   /**< �����CallID�б�*/
} CALL_S_CONFER_LOCAL_INFO;



/**
 * Desktop�˵�����
 */
typedef struct tagDesktop_Menu_Cfg
{
    TUP_UINT32 ulMessageButton;
    TUP_UINT32 ulEnableLogout;
} CALL_S_SERVICE_EXTENSION_CFG;


/** 
 * �������з���Ϣ
 */
typedef struct tagCALL_S_PICKUP_REMOTE_INFO
{
    TUP_CHAR acTelNum[CALL_D_MAX_STR_LENGTH];   /**<  ָ���������з����� */
    TUP_CHAR acDisplayName[CALL_D_64_STR_LENGTH];  /**< ָ���������з���ʾ���� */
} CALL_S_PICKUP_REMOTE_INFO;


/** 
 * ������״̬(���� OR ����)
 */
typedef enum tagCALL_E_CALLINFO_ORIGINATE
{
    CALL_E_CALLINFO_ORIGINATE_FROM,                      /**< ������״̬Ϊ���ߺ��� */
    CALL_E_CALLINFO_ORIGINATE_TO,                        /**< ������״̬Ϊ�����ߺ��� */
    CALL_E_CALLINFO_ORIGINATE_BUTT,                      /**< ������״̬��Դδ֪ */
}CALL_E_CALLINFO_ORIGINATE;


/** 
 * �����ߺ�����Ϣ
 */
typedef struct tagCALL_S_SCA_CALLINFO
{
    TUP_UINT32 ulSipAccountID;                      /**< �˻�ID */
    TUP_UINT32 ulAppearanceIndex;                   /**< ��·�� */
    TUP_UINT32 ulAppearanceState;                   /**< ��·״̬ ��SIP_E_SCASTATE*/
    CALL_E_CALLINFO_ORIGINATE enOriginateType;      /**< ������״̬��Դ */
    TUP_CHAR acDisplayName[CALL_D_MAX_DISPLAY_NAME];/**< ������ͨ����Ϣ��ʾ���� */
    TUP_CHAR acDisplayNum[CALL_D_MAX_LENGTH_NUM];   /**< ������ͨ����Ϣ��ʾ���� */
} CALL_S_SCA_CALLINFO;



/** 
 * Reinvite�¼��ϱ�
 */
typedef enum
{
    CALL_E_REINVITE_PNOTIFICATION_NONE,             /**< ��Ч�¼� */
    CALL_E_REINVITE_PNOTIFICATION_HOLD,             /**< �����¼� */
    CALL_E_REINVITE_PNOTIFICATION_UNHOLD,           /**< ȡ�������¼� */
    CALL_E_REINVITE_PNOTIFICATION_BUTT
} CALL_E_REINVITE_TYPE;


/**
 * �����޺��Ǽ�ԭ����
 */
typedef enum tagCALL_E_CAUSE_RESON
{
    CALL_E_CAUSE_NORMAL = 0,        /**< �ɹ� */
    CALL_E_CAUSE_FAILURE,           /**< ʧ�� */
    CALL_E_CAUSE_LOCKED,            /**< ���� */
    CALL_E_CAUSE_NOLINE,            /**< �޿�����· */
    CALL_E_CAUSE_BUSY,              /**< �û�æ */
    CALL_E_CAUSE_BUTT
} CALL_E_CAUSE_RESON;


/**
 * �Զ��غ���Ϣ�ṹ
 */
typedef struct tagCALL_S_ACB_INFO
{
    TUP_UINT32 ulTime1;                             /**< �������õĻغ���ʱʱ��*/
    TUP_CHAR acCalleeNum[CALL_D_MAX_STR_LENGTH];    /**< �غ����� */
    TUP_UINT32 ulOverTime;                          /**< �غ�ʣ��ʱ�� */
} CALL_S_ACB_INFO;


/**
 * ��¼����(¼*��)���֪ͨ��Ϣ�ṹ
 */   
typedef struct tagCALL_S_RECORD_INFO
{
    TUP_BOOL bRecordStatus;         /**< �Ƿ���(¼*��)״̬ */
    TUP_BOOL bRecordRight;          /**< �Ƿ���(¼*��)Ȩ�� */
}CALL_S_RECORD_INFO;


/**
 * ҵ��Ǽ�״̬
 */   
typedef enum tagCALL_E_SEVICEREGISTER_STATUS
{
    CALL_E_SEVICEREGISTER_LACK = 0,     /**< û�Ǽ� */
    CALL_E_SEVICEREGISTER_HAVE          /**< �еǼ� */
} CALL_E_SEVICEREGISTER_STATUS;


/**
 * ����״̬
 */
typedef enum tagCALL_E_SUB_STATE
{
    CALL_E_SUB_STATE_UNSUB,     /**<δ���� */
    CALL_E_SUB_STATE_SUBING,    /**<������ */
    CALL_E_SUB_STATE_DESUBING,  /**<ȥ������ */
    CALL_E_SUB_STATE_SUBED,     /**< �Ѷ��� */
    CALL_E_SUB_STATE_BUTT       /**<������Ч״̬ */
} CALL_E_SUB_STATE;


/**
 * ��·����
 */
typedef enum tagCALL_E_LINETYPE
{
    CALL_E_LINETYPE_NORMAL,             /**< ��ͨ������· */
    CALL_E_LINETYPE_SCA,                /**< ��������· */
    CALL_E_LINETYPE_BUTT
} CALL_E_LINE_TYPE;


/**
 * Ӳ��(����ͷ)����
 */
typedef struct tagCALL_S_HARDWARE_PARAMS
{
    TUP_UINT32 ulBright;                /**< ���� [1,100]Ĭ��50 */
    TUP_UINT32 ulContrast;              /**< �Աȶ� [1,100]Ĭ��50 */
    TUP_UINT32 ulDigitalZoom;           /**< ���ֱ䱶 [1,100]Ĭ��50 */

} CALL_S_HARDWARE_PARAMS;


/**
 * �Զ��غ�(ACB)�Ǽ�ҵ������
 */
typedef struct tagCALL_S_ACB_SERVICE_DATA
{
    TUP_CHAR   acACBCallNum[CALL_D_MAX_STR_LENGTH];      /**< �غ����� */
    TUP_UINT32 ulACBCallNumLenl;                         /**< �غ����볤�� */
} CALL_S_ACB_SERVICE_DATA;


/**
 * �����޺��Ǽ�ҵ������
 */
typedef struct tagCALL_S_CALL_BARRING_SERVICE_DATA
{
    TUP_CHAR   aszPassword[CALL_D_MAX_STR_LENGTH];    /**< �����޺������� */
    TUP_UINT32 ulPasswordLen;                         /**< ���볤�� */
    TUP_UINT32 ulLimitType;                           /**< �����޺������� */
} CALL_S_CALL_BARRING_SERVICE_DATA;



/** ��ǰת��Ŀ�ĺ�����֪ͨ�ṹ(����IMS������) */
typedef struct tagCALL_S_HISTORY_INFO
{
    TUP_UINT32 ulCnt;           /**< ������� */
    TUP_CHAR   aszHistoryNum[CALL_D_MAX_HISTORY_NUM][CALL_D_128_STR_LENGTH]; /**< ������Ϣ���� */
} CALL_S_HISTORY_INFO;


/**
 * Paging ҵ������֪ͨ�ṹ
 */
typedef struct tagCALL_S_PAGING_GROUP
{
    TUP_CHAR aszGroupName[CALL_D_MAX_LENGTH_NUM];   /**< Paging ���� */
    TUP_CHAR aszGroupNumber[CALL_D_MAX_LENGTH_NUM]; /**< Paging ��� */
}CALL_S_PAGING_GROUP;


/**
 * DNDģʽ
 */
typedef enum tagCALL_E_DND_TYPE
{
    CALL_E_DND_TYPE_SERVER = 0,    /**< ������DND */
    CALL_E_DND_TYPE_LOCAL,         /**< ����DND */
    CALL_E_DND_TYPE_BUTT
} CALL_E_DND_TYPE;


/**
 * LOCAL DND����ģʽ
 */
typedef enum tagCALL_E_LOCALDND_TYPE
{
    CALL_E_LOCALDND_TYPE_REJECT = 0,      /**< ����ܽ� */
    CALL_E_LOCALDND_TYPE_RINGOFF,         /**< ���粻���� */
    CALL_E_LOCALDND_TYPE_BUTT
} CALL_E_LOCALDND_TYPE;


/** 
 * DND���ݽṹ
 */
typedef struct tagCALL_S_CALL_DND_DATA
{
    TUP_BOOL bSwitch;                       /**< �Ƿ����л�DND������������Ǽ� */
    TUP_BOOL bNeedStartLocalDND;            /**< ��������ɹ����Ƿ���Ҫ���𱾵�DND�Ǽ� */
    TUP_BOOL bSetenableLocalDND;            /**< �Ƿ���Ҫ����enableLocalDND */
    CALL_E_LOCALDND_TYPE enLocalDNDType;    /**< ����DND���� */
    TUP_CHAR acRecvNotifyApp[CALL_D_MAX_NAMESPACE];  /**< ���ͽ����Ŀ�ĵ�ģ��ID*/
} CALL_S_CALL_DND_DATA;


/**
 * ǰת����
 */
typedef enum tatCALL_E_FORWARD_TYPE
{
    CALL_E_FORWARD_TYPE_UNCONDITION,        /**< ������ǰת*/
    CALL_E_FORWARD_TYPE_ONBUSY,             /**< ��æǰת*/
    CALL_E_FORWARD_TYPE_NOREPLY,            /**< ��Ӧ��ǰת*/
    CALL_E_FORWARD_TYPE_OFFLINE,            /**< ����ǰת*/
    CALL_E_FORWARD_TYPE_BUTT
} CALL_E_FORWARD_TYPE;


/**
 * ǰתĿ�����Ͷ���
 */
typedef enum tagCALL_E_FORWARD_DEST_TYPE
{
    CALL_E_FORWARD_DEST_TYPE_PHONENUM = 0,  /**< ǰת����������*/
    CALL_E_FORWARD_DEST_TYPE_VOICEMAIL,     /**< ǰת����������*/
    CALL_E_FORWARD_DEST_TYPE_BUTT
} CALL_E_FORWARD_DEST_TYPE;


/**
 * ǰת�����ر�
 */
typedef enum tagCALL_E_FORWARD_ONOFF_TYPE
{
    CALL_E_FORWARD_ONOFF_TYPE_ON = 0,       /**< ǰת���ܿ� */
    CALL_E_FORWARD_ONOFF_TYPE_OFF,          /**< ǰת���ܹ� */
    CALL_E_FORWARD_ONOFF_TYPE_BUTT
} CALL_E_FORWARD_ONOFF_TYPE;

/**
 * ǰת��Ϣ�ṹ��
 */
typedef struct tagCALL_S_FORWARD_INFO
{
    TUP_UINT32 ulSipAccountID;                      /**< �˻�ID*/
    CALL_E_FORWARD_TYPE  enFwdType;                 /**< ǰת����*/
    CALL_E_FORWARD_ONOFF_TYPE enOnOff;              /**< ������ر�    0���� 1�ر�*/
    CALL_E_FORWARD_DEST_TYPE enDstType;             /**< Ŀ������  0����  1��������*/
    TUP_CHAR    acDestNum[CALL_D_MAX_LENGTH_NUM];   /**< ǰתĿ�ĺ��� ���Ϊ�������䣬����Ϊ��*/
    TUP_UINT32  ulResult;                           /**< ǰ�������0�ɹ���1ʧ�ܣ�1��ʼֵ*/
} CALL_S_FORWARD_INFO, *CALL_S_FORWARD_INFO_PTR;


/**
 * ����������/ȡ��ǰת���н����Ϣ�ṹ
 */
typedef struct tagCALL_S_FORWARD_RESULT_INFO
{
    TUP_UINT32 ulSipAccountID;                      /**< �˻�ID */
    TUP_UINT32 ulCallId;                            /**< ����ID */
    CALL_E_FORWARD_TYPE  enFwdType;                 /**< ǰת���� */
    CALL_E_FORWARD_DEST_TYPE enDstType;             /**< Ŀ������ */
    CALL_E_FORWARD_ONOFF_TYPE enOnOff;              /**< ������ر�, 0���� 1�ر� */
    TUP_CHAR    acDestNum[CALL_D_MAX_LENGTH_NUM];   /**< ǰתĿ�ĺ��� ���Ϊ�������䣬����Ϊ�� */
    TUP_UINT32  ulResult;                           /**< ǰ�������0�ɹ���1ʧ�ܣ�1��ʼֵ */
} CALL_S_FORWARD_RESULT_INFO;


/**
 * ������ǰת���֪ͨ���ݽṹ
 */
typedef struct tagCALL_S_FORWARD_SERVICE
{
    TUP_CHAR acRecvNotifyApp[CALL_D_MAX_NAMESPACE];                 /**< ���ͽ����Ŀ�ĵ�ģ��ID */
    TUP_UINT32  ulFwdNum;                                           /**< ǰת���еĸ��� */
    CALL_S_FORWARD_RESULT_INFO  pstFwdResult[CALL_D_MAX_FOWARD_NUM];/**< ǰת��� */
} CALL_S_FORWARD_SERVICE , *CALL_S_FORWARD_SERVICE_PTR;


/**
 * �Զ��غ�(ACB)������Ϣ����
 */
typedef struct tagCALL_S_ACBCALL_REQ_INFO
{
    TUP_UINT32 ulSipAccountID;                      /**< �˻�ID */
    TUP_CHAR acRemoteNum[CALL_D_MAX_STR_LENGTH];    /**< Զ�˺��� */
}CALL_S_ACB_REQ_INFO;

 
/** 
 * ǰתҵ�����ݽṹ
 */
typedef struct tagCALL_S_CALL_FORWARD_SERVICE_DATA
{
    TUP_CHAR    astDestNum[CALL_D_MAX_LENGTH_NUM]; /**< ǰת����*/
    TUP_UINT32 ulDestNumLen;                       /**< ǰת���볤��*/
} CALL_S_CALL_FORWARD_SERVICE_DATA;


/** 
 * HuntGroupҵ�����ݽṹ
 */
typedef struct tagCALL_S_HUNTGROUP_DATA
{
    TUP_CHAR   aszGroupNumber[CALL_D_MAX_LENGTH_NUM];  /**< HuntGroup���*/
}CALL_S_HUNTGROUP_DATA;



/** 
 * IPTҵ������������
 */
typedef union tagCALL_U_IPT_DATA
{
    CALL_S_ACB_SERVICE_DATA stACBData;                  /**< �Զ��غ�ҵ������*/
    CALL_S_CALL_BARRING_SERVICE_DATA stCallBarringData; /**< �����޺�ҵ������*/
    CALL_S_CALL_FORWARD_SERVICE_DATA stCallForwardData; /**< ����ǰתҵ������*/
    CALL_S_CALL_DND_DATA stDNDData;                     /**< DND��ҵ������*/
    CALL_S_HUNTGROUP_DATA stHuntGroupData;              /**< HuntGroupҵ������*/
} CALL_U_IPT_DATA;

/** IPTҵ������ */
typedef struct tagCALL_S_IPT_DATA
{
    TUP_CHAR  acRecvNotifyApp[CALL_D_MAX_NAMESPACE];    /**< ���ͽ����Ŀ�ĵ�ģ��ID */
    CALL_E_SERVICE_CALL_TYPE enIPTServiceType;          /**< IPTҵ������ */
    CALL_U_IPT_DATA unIPTData;                          /**< ҵ������������ */
    TUP_BOOL bCancelNextOpIfFail;                       /**< �Ǽ�ʧ��ʱ�Ƿ�ȡ����һ��IPTҵ�� */
} CALL_S_IPT_DATA;


/**
 * ���ӻ����������ѯ��Ϣ�ṹ 
 */
typedef struct tag_CALL_VVM_QUERY_MSG
{
    TUP_UINT32 ulSipAccountID;                  /**< �˻�ID */
    TUP_UINT32 ulPageLimit;                     /**< TODO */
    TUP_UINT32 ulOrderType;                     /**< TODO */
    TUP_CHAR acPrevMsgID[CALL_D_64_STR_LENGTH]; /**< TODO */
} CALL_S_VVM_QUERY_MSG;


/**
 * ���ӻ���������ת����Ϣ�ṹ 
 */
typedef struct tag_CALL_VVM_FWD_MSG
{
    TUP_UINT32 ulSipAccountID;                  /**< �˻�ID */
    TUP_CHAR acMsgID[CALL_D_64_STR_LENGTH];     /**< ��ϢID */
    TUP_CHAR acDstNum[CALL_D_MAX_LENGTH_NUM];   /**< Ŀ�ĺ��� */
} CALL_S_VVM_FWD_MSG;


/**
 * ���ӻ���������ɾ����Ϣ�ṹ 
 */
typedef struct tag_CALL_VVM_DEL_MSG
{
    TUP_UINT32 ulSipAccountID;                  /**< �˻�ID */
    TUP_BOOL bIsDelAllMsg;                      /**< �Ƿ�ɾ��������Ϣ */
    TUP_CHAR acMsgID[CALL_D_64_STR_LENGTH];     /**< ��ϢID */
} CALL_S_VVM_DEL_MSG;


 /**
  * �ź�������
  */
typedef enum tagCALL_E_SIGTONE_TYPE
{
    CALL_E_SIGNAL_DIAL,    /**< ������ */
    CALL_E_SIGNAL_BACK,    /**< ������ */
    CALL_E_SIGNAL_BUSY,    /**< æ�� */
    CALL_E_SIGNAL_ALERT,   /**< �澯�� */
    CALL_E_SIGNAL_WAIT,    /**< ������ʾ�� */
    CALL_E_SIGNAL_BUTT     /**< δ֪���� */
} CALL_E_SIGTONE_TYPE;
 

/**
 * UM��Ϣ����
 */
typedef enum tagCALL_E_UM_MSG_TYPE
{
    CALL_E_UM_TYPE_IM,      /**< IM��Ϣ*/
    CALL_E_UM_TYPE_CONF,    /**< ������Ϣ*/
    CALL_E_UM_TYPE_BUTT
} CALL_E_UM_MSG_TYPE;


/**
 * UM��Ϣ��Ϣ����
 */
typedef struct tagCALL_S_UM_MSG
{
    CALL_E_UM_MSG_TYPE  eMsgType;                       /**< ����Ϣ����, �����Ϳ����Ժ����չ*/
    TUP_UINT32 ulSipAccountID;                          /**< ���ո�IM��Ϣ���˺�ID */
    TUP_UINT32 ulUMContextLen;                          /**< UM ��ϢContext���� */
    TUP_CHAR szFromUserNum[CALL_D_MAX_STR_LENGTH];      /**< UM ��Ϣ��Դ����  */
    TUP_CHAR szSrcPrority[CALL_D_MAX_STR_LENGTH];       /**< MsgExt.SrcPrority �ֶ�*/
    TUP_CHAR szHasAttachment[CALL_D_MAX_STR_LENGTH];    /**< MsgExt.HasAttachment �ֶ�*/
    TUP_CHAR szHistoryMsgNotify[CALL_D_MAX_STR_LENGTH]; /**< HistoryMsgNotify �ֶ�*/
    TUP_CHAR acLocalMsgID [CALL_D_MAX_STR_LENGTH];      /**< MsgExt.localMsgID �ֶ�*/
    TUP_CHAR acMsgSvcType [CALL_D_MAX_STR_LENGTH];      /**< MsgExt.msgSvcType ֵ */
    TUP_CHAR acMsgSort [CALL_D_MAX_STR_LENGTH];         /**< MsgExt.msgSort ֵ */
    TUP_CHAR acMsgExt [CALL_D_MAX_STR_LENGTH];          /**< MsgExt�ֶ� */
    TUP_CHAR acValidTime[CALL_D_MAX_STR_LENGTH];        /**< ValidTime�ֶ� */
    TUP_CHAR acSubmitTime [CALL_D_MAX_STR_LENGTH];      /**< submitTime�ֶ� */
    TUP_CHAR acAnonMsg [CALL_D_MAX_STR_LENGTH];         /**< anonMsg�ֶ� */
    TUP_CHAR acNsImdn [CALL_D_MAX_STR_LENGTH];          /**< Ns:Imdn�ֶ� */
    TUP_CHAR acMessageID [CALL_D_MAX_STR_LENGTH];       /**< imdn.Message-ID�ֶ� */
    TUP_CHAR acContentType [CALL_D_MAX_STR_LENGTH];     /**< content-type�ֶ�*/
    TUP_CHAR acEncode[CALL_D_MAX_STR_LENGTH];           /**< content-transfer-encoding�ֶ� */
    TUP_CHAR acUMContext[CALL_D_MAX_UM_MSG_LENGTH];     /**< UM����*/
} CALL_S_UM_MSG;



/**
 * ���оܽӻظ���������
 */
typedef enum tagCALL_E_REJECTCALL_TYPE
{
    CALL_D_REJECTTYPE_486 = 1,  /**< 486 */
    CALL_D_REJECTTYPE_603,      /**< 603 */
    CALL_D_REJECTTYPE_404,      /**< 404 */
    CALL_D_REJECTTYPE_480,      /**< 480 */
    CALL_D_REJECTTYPE_403,      /**< 403 */
    CALL_D_REJECTTYPE_BUTT    
}CALL_E_REJECTCALL_TYPE;


/**
 * Я����REFRESHER��������
 */
typedef enum tagCALL_E_SESSION_REFRESHER
{
    CALL_E_REFRESHER_UAC,       /**< uac */
    CALL_E_REFRESHER_UAS,       /**< uas */
    CALL_E_REFRESHER_UNDEFINED, /**< δ���� */
    CALL_E_REFRESHER_BUIT   
}CALL_E_SESSION_REFRESHER;


/**
 * ��Ƶ�ܽӻظ���������
 */
typedef enum tagCALL_E_REJECTVIDEO_TYPE
{
    CALL_D_REJECTVIDEOTYPE_200, /**< 200 */
    CALL_D_REJECTVIDEOTYPE_603, /**< 603 */
    CALL_D_REJECTVIDEOTYPE_BUTT    
}CALL_E_REJECTVIDEO_TYPE;


/**
 * ����������Ϣ
 */
typedef struct tagCALL_S_CONF_SUBJECT
{
    TUP_UINT32 ulConfID;        /**< ����ID */
    TUP_CHAR acSubject[CALL_CONF_SUBJECT_MAX_STR_LEN];  /**< �������� */
}CALL_S_CONF_SUBJECT;


/**
 * ���������
 */
typedef struct tagCALL_S_CONF_CONNECT_RESULT
{
    TUP_UINT32 ulConfID;
    TUP_UINT32 ulCallID;
    TUP_UINT32 ulResult;
    CALL_E_CONF_MODE enConfMode;
    CALL_E_CALL_TYPE enCallType;
}CALL_S_CONF_CONNECT_RESULT;


/**
 * ��������߽��
 */
typedef struct tagCALL_S_CONF_ADDATTENDEE_RESULT
{
    TUP_UINT32 ulConfID;
    TUP_UINT32 ulResult;
    TUP_UINT32 ulAttendeeCount;
    TUP_CHAR *pcAttendee;
}CALL_S_CONF_ADDATTENDEE_RESULT;


/**
 * ͨ����ת�����֪ͨ
 */
typedef struct tagCALL_S_CONF_BETRANSFERTOCONF
{
    TUP_UINT32 ulConfID;        /**< ����ID */
    TUP_UINT32 ulCallID;        /**< ����ID */
    TUP_INT8 acGroupUri[CALL_D_MAX_LENGTH_NUM];     /**< ��URI */
    TUP_INT8 acConfIndex[CALL_D_MAX_LENGTH_NUM];    /**< �������� */
    CALL_E_SERVERCONF_TYPE eConfType;               /**< �������� */
    CALL_E_CONF_MODE eConfMode;                     /**< ����ģʽ */
}CALL_S_CONF_BETRANSFERTOCONF;


/**
 * ͨ��ת������(�ɹ���ʧ��)
 */
typedef struct tagCALL_S_CONF_TRANSFERTOCONF_RESULT
{
    TUP_UINT32 ulConfID;        /**< ����ID */
    TUP_UINT32 ulCallID;        /**< ����ID */
    TUP_UINT32 ulResult;        /**< ���:0�ɹ������� ʧ�� */
}CALL_S_CONF_TRANSFERTOCONF_RESULT;


/**
 * һ�����������
 */
typedef struct tagCALL_S_ONEKEY_TO_CONF_RESULT
{
    TUP_UINT32 ulCallID;        /**< ����ID */
    TUP_UINT32 ulResult;        /**< ���:0�ɹ������� ʧ�� */
    CALL_E_CONFTYPE eConfType;  /**< �������� */
}CALL_S_ONEKEY_TO_CONF_RESULT,CALL_S_CONF_CONNECT_ONEKEY_TO_CONF_RESULT;


/**
 * ��Ƶý��ģʽ
 */
typedef enum tagCALL_E_AUDIO_MODE
{
    CALL_AUDIO_MODE_NONE     =   0x00,  /**< ��Чģʽ */
    CALL_AUDIO_MODE_LOCAL    =   0x01,  /**< pc����ģʽ */
    CALL_AUDIO_MODE_VM_LOCAL =   0x02,  /**< ���ϱ�����Ƶģʽ */
    CALL_AUDIO_MODE_TC       =   0x04,  /**< TCģʽ */

    CALL_AUDIO_MODE_INVALID  =   0xFF
}CALL_E_AUDIO_MODE;


/**
 * TC�ļ�ֵ��ÿ��ֵ��Ӧһ���̶����ļ������ݿͻ���ֵһһ��Ӧ
 */
typedef enum tagCALL_E_TC_FILE_VALUE
{
    CALL_TC_FILE_INCOMINGIM,        /**< ��IM��Ϣ���� incomingim */
    CALL_TC_FILE_INCOMINGCALL,      /**< ���籾�ط��� incomingcall */
    CALL_TC_FILE_CALLHOLD,          /**< ���ֱ��ط��� callhold */
    CALL_TC_FILE_RINGBACKTONE,      /**< ringbacktone */
    CALL_TC_FILE_NUM0,              /**< num0 0 */
    CALL_TC_FILE_NUM1,              /**< num1 1 */
    CALL_TC_FILE_NUM2,              /**< num2 2 */
    CALL_TC_FILE_NUM3,              /**< num3 3 */
    CALL_TC_FILE_NUM4,              /**< num4 4 */
    CALL_TC_FILE_NUM5,              /**< num5 5 */
    CALL_TC_FILE_NUM6,              /**< num6 6 */
    CALL_TC_FILE_NUM7,              /**< num7 7 */
    CALL_TC_FILE_NUM8,              /**< num8 8 */
    CALL_TC_FILE_NUM9,              /**< num9 9 */
    CALL_TC_FILE_NUMXING,           /**< numxin * */
    CALL_TC_FILE_NUMJING,           /**< numjin # */
    CALL_TC_FILE_CALLOUT,           /**< callout, */
    CALL_TC_FILE_ROLLBACK           /**< rollback ������ */
}CALL_E_TC_FILE_VALUE;


#define DM_MAX_DIALNUMBER_LEN  32   /**< ��ͼ������󳤶� */


/**
 * ��ͼת�����
 */
typedef struct tagDMRESULT
{
    TUP_UINT32 uiLength;                    /**< ƥ��ĳ��Ȼ����滻��ĺ��볤�� */
    TUP_CHAR pszNUM[DM_MAX_DIALNUMBER_LEN]; /**< �滻��ĺ��� */
}DMRESULT;



/**
 * ���������ı�֪ͨ��Ϣ�ṹ
 */
typedef struct tagCALL_S_NETQUALITY_CHANGE
{
    TUP_UINT32 ulCallID;        /**< ����ID */   
    TUP_UINT32 uLNetError;      /**< ������� 0 : û�д��� 1 : ���緢�˴��� 2 : �����ն˴��� 3 : �����շ������� */
    TUP_UINT32 ulNetLevel;      /**< ���������ȼ�����net-errorΪ0��ֵ��Ч [0,5]  */
}CALL_S_NETQUALITY_CHANGE;


/**
 * ��������ͳ����Ϣ
 */
typedef struct tagCALL_S_STATISTIC_NETINFO
{
    TUP_UINT32 ulCallID;        /**< ����ID */  
    TUP_UINT32 ulLost;          /**< �����ʣ���λ% */
    TUP_UINT32 ulDelay;         /**< ʱ�� ���� */
    TUP_UINT32 ulJitter;        /**< ���� ���� */
}CALL_S_STATISTIC_NETINFO;


/**
 * �ļ���ʽ 
 */
typedef enum  tagCALL_E_FILE_FORMAT
{
    CALL_FILE_FORMAT_PCM = 0,   /**< PCM�ļ���ʽ */  
    CALL_FILE_FORMAT_WAV = 1,   /**< WAV�ļ���ʽ��Ŀǰ֧��PCM_ALAW��PCM_ULAW��PCM */  
    CALL_FILE_FORMAT_AMR = 2,   /**< AMR�ļ���ʽ��Ŀǰ֧�ֵ�ͨ��AMR-NB */  
}CALL_E_FILE_FORMAT;


/**
 * ������Ƶ�ļ�������Ϣ
 */
typedef struct tagCALL_S_AUDIO_PLAYFILE_ADDITIONINFO
{
    CALL_E_FILE_FORMAT enFileFormat;    /**< �ļ���ʽ */
} CALL_S_AUDIO_PLAYFILE_ADDITIONINFO;


/**
 * Ԥ��EQ����
 */
typedef enum tagCALL_E_PRESET_EQ_TYPE
{
    CALL_E_PRESET_EQ_TYPE_RECOMMEND,    /**< �Ƽ���Ч */
    CALL_E_PRESET_EQ_TYPE_NORTHAMERICA, /**< ������Ч */
    CALL_E_PRESET_EQ_TYPE_AUSTRALIA,    /**< ������Ч */
    CALL_E_PRESET_EQ_TYPE_TIA920,       /**< TIA920��Ч */
    CALL_E_PRESET_EQ_TYPE_BUTT
}CALL_E_PRESET_EQ_TYPE;


/**
 * ��Ƶ����
 */
typedef struct tagCALL_S_VIDEO_OPERATION
{
    TUP_UINT32 ulCallID;        /**< ����ID */
    TUP_UINT32 ulOperation;     /**< ������ȡֵ:
                                 <br>open 0x01��close 0x02��start 0x04��stop 0x08 */
    TUP_UPTR   ulRenderHanle;   /**< ����������Ƶ���ھ��  */
    TUP_UINT32 ulType;          /**< Զ�˻��߱��� 1������ 2��Զ��  */
}CALL_S_VIDEO_OPERATION;


/**
 * ��Ƶ(����)��С���
 */
typedef struct tagCALL_S_VIDEO_FRAMESIZE_CHANGE
{
    TUP_UINT32 ulCallID;        /**< ����ID */
    TUP_UINT32 ulWidth;         /**< ����� */
    TUP_UINT32 ulHeight;        /**< ����� */
}CALL_S_VIDEO_FRAMESIZE_CHANGE;


/**
 * ý�������Ϣ
 */
typedef struct tagCALL_S_MEDIA_ERRORINFO
{
    TUP_UINT32 ulCallID;        /**< ����ID */
    TUP_UINT32 ulMediaType;     /**< ý�����ͣ�  0 : δ֪���͡�1 : ��Ƶ��  2 : ��Ƶ�� 3 : ����  */
    TUP_UINT32 ulErrorType;     /**< ��������:   0 : δ֪���� 1 : �������ʹ��� 2 : �������մ���  */
}CALL_S_MEDIA_ERRORINFO;


/**
 * �Ự����ʹ�õı��������Ϣ
 */
typedef struct tagCALL_S_SESSION_CODEC
{
    TUP_UINT32 ulCallID;        /**< ����ID */
    TUP_UINT32 ulMediaType;     /**< ý�����ͣ�  0 : δ֪���͡�1 : ��Ƶ��  2 : ��Ƶ�� 3 : ���� */
    TUP_UINT32 ulCodecType;     /**< ����������ͣ� 0 : δ֪���͡� 1 : ��������2 : �������� */
    TUP_CHAR   acCodecName[CALL_MAX_CODEC_NAME_LEN]; /**< ��������� */
}CALL_S_SESSION_CODEC;


/**
 *  �豸��Ϣ
 */
typedef struct tagCALL_S_DEVICE_INFO
{
    TUP_UINT8 uiIndex;          /**< �豸��Ӧ��index */
    TUP_UINT8 uiOrienation;     /**< ��Ƶ�豸��Ϣר�ã�Ӳ�ն˿��Բ���Ҫ��������ƶ��豸���� */
    TUP_CHAR  strName[CALL_D_MAX_LENGTH_NUM]; /**< �豸���� */
}CALL_S_DEVICE_INFO;


/**
 * ��Ƶ����/����豸��Ϣ
 */
typedef struct tagCALL_S_AUDIO_DEVICE_INFO
{
    TUP_UINT8 uiInputNum;         /**< �����豸��Ŀ */
    TUP_UINT8 uiOutputNum;        /**< ����豸��Ŀ */
    CALL_S_DEVICE_INFO stInputDevice[CALL_D_MAX_DEVICE_NUM];   /**< ��Ƶ�����豸 */
    CALL_S_DEVICE_INFO stOutPutDevice[CALL_D_MAX_DEVICE_NUM];  /**< ��Ƶ����豸 */
}CALL_S_AUDIO_DEVICE_INFO;


/**
 * ��Ƶ����/����豸��Ϣ
 */
typedef struct tagCALL_S_VIDEO_DEVICE_INFO
{
    TUP_UINT8 uiCaptureNum;                             /**< ����ͷ��Ŀ */
    CALL_S_DEVICE_INFO stCapture[CALL_D_MAX_DEVICE_NUM];/**< ��Ƶ�豸��Ϣ */
}CALL_S_VIDEO_DEVICE_INFO;


/**
 * ¼*���ļ�������Ϣ
 */
typedef struct tagCALL_S_RECORDFILE_INFO
{
    TUP_UINT32 ulCaptureIndex;  /**< ���������豸���� */
    TUP_UINT32 ulFileSize;      /**< �ļ���С��ʾ�澯������ļ������Ĵ�С��������֪ͨ����Ӱ�칦�ܣ�Ĭ��100M,��Ƶ������Ҫ */
    TUP_UINT32 ulSampleFreq;    /**< ������ */
    TUP_UINT32 ulRate;          /**< ���� */
    TUP_INT8   acCodecName[CALL_MAX_CODEC_NAME_LEN];   /**< �������� */
}CALL_S_RECORDFILE_INFO;


/**
 * QoS�ϱ�������Ϣ
 */
typedef struct tagCALL_S_SETQOS_INFO
{
    TUP_BOOL   bIsNotifyQos;    /**< �Ƿ���Qos�ϱ���Ĭ��false��������true����  */
    TUP_UINT32 ulQosTime;       /**< �ϱ����  */
    TUP_FLOAT  fMosVal;         /**< mos��ֵ */
    TUP_UINT32 ulLostVal;       /**< �����ʷ�ֵ */
    TUP_UINT32 ulJitterVal;     /**< ������ֵ */
    TUP_UINT32 ulDelayVal;      /**< ʱ�ӷ�ֵ */
}CALL_S_SETQOS_INFO;


/**
 * QoS�ϱ���Ϣ(�ϱ���������)
 */
typedef struct tagCALL_S_NOTIFYQOS_INFO
{
    TUP_UINT32 ulCallID;        /**< ����ID */
    TUP_FLOAT  fMosValue;       /**< mosƽ��ֵ */
    TUP_UINT32 ulLostValue;     /**< JB������ƽ��ֵ */
    TUP_UINT32 ulNetLostValue;  /**< ���綪����ƽ��ֵ */
    TUP_UINT32 ulJitterValue;   /**< ����ƽ��ֵ */
    TUP_UINT32 ulDelayValue;    /**< ʱ��ƽ��ֵ */
    TUP_UINT32 ulabnormityTime; /**< �쳣ʱ�� */
    TUP_UINT32 uiTcErrorNum;    /**< TC �쳣�� */
    
    TUP_CHAR acAudioCodec[CALL_D_MAX_AUDIO_CODEC_LEN]; /**< ��Ƶ����� "G722,PCMA,PCMU,G729,iLBC,telephone-event,red"*/
    TUP_CHAR acLocalIP[CALL_D_IP_LENGTH];              /**< ����IP*/
    TUP_CHAR acRemoteIP[CALL_D_IP_LENGTH];             /**< Զ��IP*/
    TUP_CHAR acHMEVersion[CALL_D_HMEVERSION_LENGTH];   /**< HME�汾*/
    TUP_CHAR acTCVersion[CALL_D_HMEVERSION_LENGTH];    /**< TC�汾,û�еĻ�Ϊ��*/
}CALL_S_NOTIFYQOS_INFO;


/**
 * QoS�ϱ���Ϣ(�ϱ�����UI)
 */
typedef struct tagCALL_S_NOTIFYLOACLQOS_INFO
{
    TUP_UINT32 ulCallID;        /**< ����ID */
    TUP_FLOAT  fMosValue;       /**< mosƽ��ֵ */
    TUP_UINT32 ulLostValue;     /**< JB������ƽ��ֵ */
    TUP_UINT32 ulNetLostValue;  /**< ���綪����ƽ��ֵ */
    TUP_UINT32 ulJitterValue;   /**< ����ƽ��ֵ */
    TUP_UINT32 ulDelayValue;    /**< ʱ��ƽ��ֵ */
}CALL_S_NOTIFYLOACLQOS_INFO;


/**
 * �Ự�޸���ɽ����Ϣ
 */
typedef struct tagCALL_S_SESSION_MODIFIED
{
    TUP_UINT32 ulCallID;                                /**< ����ID */
    TUP_BOOL bIsFocus;                                  /**< �Ƿ��isfoucs��ʶ���ƶ����鳡��ʹ��*/  
    TUP_INT8 acServerConfType[CALL_D_MAX_LENGTH_NUM];   /**< �������ͣ��ƶ����鳡��ʹ��*/  
    TUP_INT8 acServerConfID[CALL_D_MAX_LENGTH_NUM];     /**< ����ID, �ƶ����鳡��ʹ��*/
    TUP_UINT32 ulOrientType;                            /**< �ƶ���Ƶ���������*/
    TUP_INT8 acLocalAddr[CALL_D_IP_LENGTH];             /**< �ƶ��ϱ����ص�ַ*/
    TUP_INT8 acRemoteAddr[CALL_D_IP_LENGTH];            /**< �ƶ��ϱ�Զ�˵�ַ*/
    CALL_E_REINVITE_TYPE enHoldType;                    /**< ���п��յ�reinvie����*/
    CALL_E_MEDIA_SENDMODE enAudioSendMode;              /**< ��Ƶý�巽��*/
    CALL_E_MEDIA_SENDMODE enVideoSendMode;              /**< ��Ƶý�巽��*/
    CALL_E_MEDIA_SENDMODE enDataSendMode;               /**< ����ý�巽��*/
}CALL_S_SESSION_MODIFIED;


/**
 * �˺ŵ��û���
 */
typedef struct tagCALL_S_ACCOUNT_USER_NAME
{
    TUP_UINT32 ulAccountID;                         /**< �˻�ID */
    TUP_CHAR acUserName[CALL_D_128_STR_LENGTH];     /**< �û���,�������ʱ,û��UC�˺ŵ�������ϱ� */
}CALL_S_ACCOUNT_USER_NAME;


/**
 * BFCP����
 */
typedef struct tagCALL_S_BFCP_PARAM
{
    TUP_UINT32 uiTransType; /**< �����������ͣ�1��ʾUDP��2��ʾTCP, Э�̵Ľ��������invite��Ϊ׼*/
    TUP_UINT32 uiFloorCtrl; /**< �����������ͣ�1��ʾc-only,2��ʾs-only*/
    TUP_UINT32 uiSetup;     /**< �û���TCP����BFCP����ʱ�涨�������ӵ�һ����1��ʾactive��2��ʾpassive*/
}CALL_S_BFCP_PARAM;



#define CALL_NTF_TEST_BASE     CALL_E_EVT_BUTT                      /**< �Զ�������֪ͨ�¼���ʼID */
#define CALL_NTF_VIDEO_FIRST_PACKET_TEST    (CALL_NTF_TEST_BASE+1)  /**< �յ���һ����Ƶ����Ϣ */
#define CALL_NTF_AUDIO_FIRST_PACKET_TEST    (CALL_NTF_TEST_BASE+2)  /**< �յ���һ����Ƶ����Ϣ */

#define CALL_DEC_PT_NUM_MAX 18      /**< ����PTֵ������ */


/**
 * ��Ƶ������Ϣ
 */
typedef struct tagCALL_VIDEO_BASE_INFO
{
    TUP_UINT32  uiCallID;                                   /**< ����ID */    
    TUP_CHAR    acCodecName[CALL_MAX_CODEC_NAME_LEN+1];     /**< ������� */ 
    TUP_UINT16  usEncPt;                                    /**< ����PTֵ */ 
    TUP_UINT16  ausDecPt[CALL_DEC_PT_NUM_MAX];              /**< ����PTֵ�б� */ 
    TUP_UINT16  usDecPtNum;                                 /**< ����PTֵ�б���� */ 
}CALL_VIDEO_BASE_INFO;


/**
 * ��Ƶ������Ϣ
 */
typedef struct tagCALL_AUDIO_BASE_INFO
{
    TUP_UINT32  uiCallID;                                   /**< ����ID */    
    TUP_CHAR    acCodecName[CALL_MAX_CODEC_NAME_LEN+1];     /**< ������� */ 
    TUP_UINT16  usEncPt;                                    /**< ����PTֵ */
    TUP_UINT16  usDecPt;                                    /**< ����PTֵ */
}CALL_AUDIO_BASE_INFO;


/**
 * �����Զ������Ի�����Ϣ
 */
typedef union tagCALL_U_TEST_INFO
{
    CALL_AUDIO_BASE_INFO stAudioBaseInfo;                   /**< ��Ƶ������Ϣ */    
    CALL_VIDEO_BASE_INFO stVideoBaseInfo;                   /**< ��Ƶ������Ϣ */   
}CALL_U_TEST_INFO;


/**
 * �����Զ������Ի�����Ϣ֪ͨ
 */
typedef struct tagCALL_S_TEST_NOTIFY
{
    TUP_UINT32 uiNotifyType;
    CALL_U_TEST_INFO unInfo;
} CALL_S_TEST_NOTIFY;


/**
 * @brief �Զ������Իص�����
 * 
 * @param [in] TUP_VOID* pUserContext         <b>:</b> �û���Ϣ
 * @param [in] CALL_S_TEST_NOTIFY* punNotify  <b>:</b> �����Զ������Ի�����Ϣ֪ͨ�ṹ
 * @param [out] NA
 * @retval typedef TUP_VOID (* <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention Ԥ������û��ʹ��
 * @see NA
 **/
typedef TUP_VOID (*TEST_CALL_BACK)(TUP_VOID* pUserContext, CALL_S_TEST_NOTIFY* punNotify); 



#ifdef __cplusplus
#if __cplusplus
}
#endif /*  __cpluscplus */
#endif /*  __cpluscplus */


#endif  /* __CALL_ADVANCED_DEF_H__*/

/** @}*/

/*
* History: \n
* 2012-12-10, ��ʼ�����ļ��� \n
* 2015-12-30, TUP V100R001C50 TR5 ���������´��ļ��� \n
*
* vi: set expandtab ts=4 sw=4 tw=80:
*/


