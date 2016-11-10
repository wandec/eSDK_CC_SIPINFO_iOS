#ifndef __ANYOFFICE_HTTP_CLIENT_H__

                  ��Ȩ���� (C), 2001-2014, ��Ϊ�������޹�˾

  �� �� ��   : anyoffice_httpclient.h
  �� �� ��   : ����
  ��    ��   : zhangyantao 00103873
  ��������   : 2014��7��18��
  ����޸�   :
  ��������   : HTTP �ͻ��ˣ�����������HTTPSͨ��
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2014��7��18��
    ��    ��   : zhangyantao 00103873
    �޸�����   : �����ļ�
#include "tools_string.h"
extern "C" {
#endif




//˫��У�����ϵͳ��ʶ
#define HTTP_CLIENT_OS_VALUE_ANDROID                 1

/* HTTPͷ������������ͷ����Ӧͷ��ʹ�øýṹ */
typedef struct tagHttpClientVRBList
{
    CHAR                        *pcType;  /* ͷ���ͣ���Content-Type */
    CHAR                        *pcValue; /* ͷ��ֵ����application/vnd.ms-sync.wbxml */
    struct tagHttpClientVRBList *pNext;       /* ������һ��ͷ�ڵ� */
}HTTP_CLIENT_VRB_LIST_S;

/* HTTP ������ */
typedef struct tagHttpClientRequestLine
{
    ULONG ulMethod;     /* ���󷽷�����POST,OPTIONS */
    ULONG ulSSLEnable;
    ULONG ulPort;
    CHAR  *pcURL;        /* ������URL����֧���ض������Ӧֱ�ӽ��д��� */
    CHAR  *pcHost;       /* Host, */
    CHAR  *pcPath;
    HTTP_CLIENT_VRB_LIST_S *pstParamList;  /* �����б� */
}HTTP_CLIENT_REQUEST_LINE_S;


/* HTTP��Ϣ��ṹ */
typedef struct tagHttpClientBody
{
    ULONG      ulContentLen;   /* http��Ӧͷ�е�content-length���� */
    ULONG      ulBodyLen;      /* ��Ϣ�峤�� */
    CHAR       *pcbody;        /* ��Ϣ������ */
}HTTP_CLIENT_BODY_S;

typedef struct tagHttpClientRequest
{
    HTTP_CLIENT_REQUEST_LINE_S    *pstReqLine;   /* HTTP ������ */
    HTTP_CLIENT_VRB_LIST_S        *pstHeadList;  /* HTTPͷ������ */
    HTTP_CLIENT_BODY_S            stHttpBody;    /* HTTP��Ϣ�� */

typedef struct tagHttpClientResponse
{
    ULONG                        ulStatusCode;   /* HTTP״̬�� */
    CHAR                         *pcRedirectURL;
    HTTP_CLIENT_VRB_LIST_S       *pstHeadList;   /* HTTPͷ������ */ 
    struct http_slist            *pstCookies;  /*��Ӧcookie*/
    HTTP_CLIENT_BODY_S           stHttpBody;     /* HTTP��Ϣ�� */
}HTTP_CLIENT_RESPONSE_S;

 typedef ULONG (*HTTP_Client_IOCallBack)(
{
    ULONG ulL4VPNFlag;
    HTTP_CLIENT_REQUEST_S *pstRequest, 
    HTTP_CLIENT_RESPONSE_S *pstResponse);

#ifdef __cplusplus
}
#endif




#endif
