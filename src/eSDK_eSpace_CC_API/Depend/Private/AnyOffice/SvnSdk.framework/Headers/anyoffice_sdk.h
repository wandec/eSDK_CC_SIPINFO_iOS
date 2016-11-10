/******************************************************************************

                  ��Ȩ���� (C), 2001-2014, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : anyoffice_sdk.h
  �� �� ��   : ����
  ��    ��   : zhangyantao 00103873
  ��������   : 2014��7��9��
  ����޸�   :
  ��������   : AnyOffice SDK ��ʼ����ȥ��ʼ��
  �����б�   :
*
*
  �޸���ʷ   :
  1.��    ��   : 2014��7��9��
    ��    ��   : zhangyantao 00103873
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __ANYOFFICE_SDK_H__
#define __ANYOFFICE_SDK_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*----------------------------------------------*
 * ͷ�ļ�                                       *
 *----------------------------------------------*/
#include "tools_common.h"
#include "svn_define.h"
/*----------------------------------------------*
 * ��������                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �궨��                                       *
 *----------------------------------------------*/
#define ANYOFFICE_COMMON_OK   0
#define ANYOFFICE_ERROR_COMMON_UNDEFINED       1
#define ANYOFFICE_ERROR_COMMON_PARAMETER       2
#define ANYOFFICE_ERROR_COMMON_OUTOFMEMORY     3

#define ANYOFFICE_ERROR_COMMON_TCP_CONNECT_FAILED   -1
#define ANYOFFICE_ERROR_COMMON_PROXY_CONNECT_FAILED -2
#define ANYOFFICE_ERROR_COMMON_INVALID_PROXY        -3
#define ANYOFFICE_ERROR_CONMON_TLS_SHAKEHAND_FAILED -4
#define ANYOFFICE_ERROR_COMMON_UNAUTHORIED          -5
#define ANYOFFICE_ERROR_COMMON_GATEWAY_EXCEPTION    -99
#define ANYOFFICE_ERROR_COMMON_INTERNAL_EXCEPTION   -100

#define ANYOFFICE_ERROR_COMMON_UNINITIALIZED        -1001
#define ANYOFFICE_ERROR_COMMON_REQUIRE_APPAUTHEN    -1002  /* Ӧ����֤ʧ��,Ӧ�÷Ƿ� */
#define ANYOFFICE_ERROR_COMMON_REQUIRE_USERAUTHEN   -1003
#define ANYOFFICE_ERROR_COMMON_REQUIRE_GET_POLICY   -1004
#define ANYOFFICE_ERROR_COMMON_REQUIRE_LOGIN        -1005
#define ANYOFFICE_ERROR_COMMON_VERSION_MISSMATCH    -1006
#define ANYOFFICE_ERROR_COMMON_INVALID_PARAMETER    -1007
#define ANYOFFICE_ERROR_COMMON_NOFUNCTION           -1008  /*no license, or no function is enabled*/
#define ANYOFFICE_ERROR_COMMON_CHK_CERT_BIND_FAIL       -1009  /*ckcert fail �����ط���*/
#define ANYOFFICE_ERROR_COMMON_CHK_CERT_UNKNOW_FAIL       -1010  /*δ֪���� ����֤��У��ʧ�ܣ������������쳣���£��ɿͻ�������*/


#define ANYOFFICE_ERROR_APP_INVALID_APPID           -2001
#define ANYOFFICE_ERROR_APP_INVALID_SIGNATURE       -2002


#define ANYOFFICE_ERROR_GATEWAY_INVALID_TOKEN       -3001
#define ANYOFFICE_ERROR_GATEWAY_REQUIRE_USER        -3006
#define ANYOFFICE_ERROR_GATEWAY_REQUIRE_CONFIG      -3007

/* BEGIN: Modified by wenliang/90006494, for: DTS2015082705428  ��̨��������L4������ ,2015/9/25 */
#define ANYOFFICE_ERROR_GATEWAY_MDM_DEVICE_IS_NULL_OR_NOT_APPROVED     (-3008)    /* �ն˲����ڻ���δ���� */
#define ANYOFFICE_ERROR_GATEWAY_MDM_REGISTER_LIMIT                     (-3009)    /* �û�ע���ն��������� */
#define ANYOFFICE_ERROR_GATEWAY_MDM_SDK_OVER_TOP_LIMIT                 (-3010)    /* ����ϵͳ�ն˹�����ߣ�100w */
/* END: Modified by wenliang/90006494, for: DTS2015082705428  ��̨��������L4������ ,2015/9/25 */


#define ANYOFFICE_ERROR_LOGIN_MISTAKE_ERR            -1       /* ��������:LOGIN_FAILLOG_ANYOFFICE_MISTAKE */
#define ANYOFFICE_ERROR_LOGIN_SYSTEM_BUSY            -3       /* ��������ʧ:LOGIN_FAILLOG_ANYOFFICE_NOGATEWAY */
#define ANYOFFICE_ERROR_LOGIN_GATEWAY_CONNECT_ERR   -4       /* ��������ʧ:LOGIN_FAILLOG_ANYOFFICE_NOGATEWAY */
#define ANYOFFICE_ERROR_LOGIN_USERINFO_ERR           -5       /* �û����������:LOGIN_FAILLOG_ANYOFFICE_ERRORPASSWORD */
#define ANYOFFICE_ERROR_LOGIN_USERINFO_NO_PASSWORD  -9       /*û������*/
#define ANYOFFICE_ERROR_LOGIN_GATEWAY_PORT_ERR       -97     /* �˿ں�Ϊ�� */
#define ANYOFFICE_ERROR_LOGIN_GATEWAY_ADDRESS_ERR   -98      /* ���ص�ַΪ�� */
#define ANYOFFICE_ERROR_LOGIN_MAILINFO_ERR           -99       /* �ʼ���ַ�쳣:LOGIN_FAILLOG_ANYOFFICE_ERROREMAIL */
#define ANYOFFICE_ERROR_LOGIN_GATEWAYINFO_ERR        -100       /* ���������ò����쳣:LOGIN_FAILLOG_ANYOFFICE_ERRORSEVER */
#define ANYOFFICE_ERROR_LOGIN_CANOFFLINELOGIN_ERR        -100       /* ���������ò����쳣:LOGIN_FAILLOG_ANYOFFICE_ERRORSEVER */
#define ANYOFFICE_ERROR_LOGIN_EXCEPTION              -101   /* δ֪�쳣:LOGIN_FAILLOG_ANYOFFICE_EXCEPTION */
#define ANYOFFICE_ERROR_LOGIN_LICENSE_VISIT_LIMIT_ERR  -102/*licenseδ��������*/
#define ANYOFFICE_ERROR_LOGIN_POLICY_ENC_CHANGED  -103     /* �ӽ��ܲ����л� */
#define ANYOFFICE_ERROR_LOGIN_DB_CORRUPT -104            /* ���ݿ�����ļ��� */
#define ANYOFFICE_ERROR_LOGIN_MAILISLOGIN_ANDCFGISCHANGED -105            /*δɱ���������Ѿ��ɹ���¼�������ε�¼���ص�ַ\�ʼ���ַ\�û������޸�,��Ҫ�û��˳��ص�¼(ɱ����)*/
#define ANYOFFICE_ERROR_LOGINE_OFFLINE              -95
#define ANYOFFICE_ERROR_LOGIN_CHANGE_ACCOUNT -96
#define ANYOFFICE_ERROR_ALREADY_EXIST -106           /*�����ļ��Ѿ�����*/
#define ANYOFFICE_ERROR_USER_NOSWITCH -107           /*û�з����û��л�*/

#define ANYOFFICE_ERROR_LOGIN_LONG_TIME_OFFLINE -110 /*����δ��¼��ֹ���ߵ�¼*/

#define ANYOFFICE_SDK_ENTRY_VERSION_MAX_LEN 256
#define ANYOFFICE_ERROR_AUTH_NO_CLIENT_CERT -4000 /*˫��У�麯�������������֤�飬�򷵻ش���*/

#define CSR_NO_MEMORY               1
#define CSR_ARG_ERR                 2
#define CSR_ERR_DN_TEMPLATE         3
#define CSR_ERR_GET_CONFIG          4
#define CSR_HTTP_CON_ERR            5
#define CSR_HTTP_RESPONSE_ERR       6

const unsigned char* AnyOffice_API_getEntryVersion();

void AnyOffice_API_setEntryVersion(unsigned char *pucEntryVersion);

INT32 AnyOffice_API_InitEnv(CHAR *pcUserName, CHAR *pcWorkPath);

INT32 AnyOffice_API_ResetEnv();

ULONG AnyOffice_API_CleanEnv(void);

VOID AnyOffice_API_SetLogCallBack(SVN_WriteLogCallback pfCallBackWriteLog);
typedef VOID (*TreatCACallback)();
VOID AnyOffice_API_SetCATreatCallback(TreatCACallback pfCallbackTreatCA);

/* BEGIN:Add by zhongyongcai for webos,2015-05-5*/
#ifdef ANYOFFICE_ATELIEROS
void AnyOffice_SDK_SetPackageName(char* pcPackageName);
#endif
/* END:Add by zhongyongcai for webos,2015-05-5*/


/*****************************************************************************
 �� �� ��  : AnyOffice_API_Apply_Certificate
 ��������  : �����ṩ֤�����빦��
 �������  : CSR_PRE_INFO_S *pstCsrPreInfo           
             SVN_CLIENTCERT_INFO_S **ppstClientCert  
 �������  : CSR_PRE_INFO_S *pstCsrPreInfo    
 �� �� ֵ  : CSR_NO_MEMORY               1 �ڴ�����ʧ��
             CSR_ARG_ERR                 2 ��������
             CSR_ERR_DN_TEMPLATE         3 DNģ�����
             CSR_ERR_GET_CONFIG          4 ��ȡConfiguration filesʧ��
             CSR_HTTP_CON_ERR            5 http����ʧ��
             CSR_HTTP_RESPONSE_ERR       6 http responseʧ��
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2015��7��10��
    ��    ��   : suyaodong
    �޸�����   : �����ɺ���

*****************************************************************************/
struct tag_CSR_PRE_INFO_S;
int AnyOffice_API_Apply_Certificate(struct tag_CSR_PRE_INFO_S  *pstCsrPreInfo,SVN_CLIENTCERT_INFO_S **pstClientCert );

/*****************************************************************************
 �� �� ��  : AnyOffice_API_Check_Cert_Bind
 ��������  : ���ͻ���֤���Ƿ��
 �������  : ��
 �� �� ֵ  : LONG
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2015��7��30��
    ��    ��   : suyaodong
    �޸�����   : �����ɺ���

*****************************************************************************/
LONG AnyOffice_API_Check_Cert_Bind();

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif

