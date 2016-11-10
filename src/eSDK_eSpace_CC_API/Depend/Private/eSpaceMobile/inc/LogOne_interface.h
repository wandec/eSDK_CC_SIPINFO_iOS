/*******************************************************************************
* ��Ȩ         :   2010-2011, Huawei Tech.Co.,Ltd
* ����         :   �ն˹���ƽ̨�Ŷ� 
* ����         :   2014-5-5
* �汾��       :   TUP V100R001C30
* ����         :   ͳһ��־�ӿ�ͷ�ļ�
* ��ʷ��¼     :   
******************************************************************************/

#ifndef LOGONE_INTERFACE_H
#define LOGONE_INTERFACE_H

//#include "LogOne.h"

#if 1
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#endif

typedef void * LOGONE_HANLE;

#if 0
/* �ر���־�ļ� */
typedef enum tagLOGONE_E_LOG_LEVEL
{
	LOGONE_E_LOG_ERROR = 0,    // ����(������־)
	LOGONE_E_LOG_WARNING,      // �澯(������־)
	LOGONE_E_LOG_INFO,         // ��ʾ(������־)
    LOGONE_E_LOG_DEBUG         // ����(������־)
}LOGONE_E_LOG_LEVEL;

#endif

/* �ر���־�ļ� */
typedef enum tagE_LOG_LEVEL
{
	E_LOG_ERROR = 0,    // ����(������־)
	E_LOG_WARNING,      // �澯(������־)
	E_LOG_INFO,         // ��ʾ(������־)
    E_LOG_DEBUG         // ����(������־)
}E_LOG_LEVEL;


#ifdef  _lint
#ifndef __FUNCTION__
#define __FUNCTION__	""
#endif
#endif

#define BASIC_INFO				__FUNCTION__, __FILE__, __LINE__

typedef struct tagLOGONE_S_CONFIG
{
    char *          pucPath;        /* ��־�ļ�·�� */
    int             lMaxSizeKB;     /* ��־��С����λKB */
    int             lFileCount;     /* ֧����־�ļ��ܸ��� */
    E_LOG_LEVEL     enLogLevel;     /* ��־���� */
}LOGONE_S_CONFIG, *LOGONE_S_CONFIG_PTR;


/*****************************************************************************
 �� �� ��  : LogOne_StartLog
 ��������  : ��־ģ���ʼ���ӿڣ�����ʹ�ø�ģ����־����ӿ����մ�ӡ��ͬһ��
             ��־�ļ���
 �������  : const VOS_UINT8* szPath  
 �������  : ��
 �� �� ֵ  : LOGONE_HANLE
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2014��5��5��
    ��    ��   : jianghaiping 00191694
    �޸�����   : �����ɺ���

*****************************************************************************/
LOGONE_HANLE LogOne_StartLog(const LOGONE_S_CONFIG_PTR pstLogConfig);


/*****************************************************************************
 �� �� ��  : LogOne_CloseLog
 ��������  : �ر���־��ӡ,�������µ���LogOne_StartLog������־
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2014��5��5��
    ��    ��   : jianghaiping 00191694
    �޸�����   : �����ɺ���

*****************************************************************************/
void     LogOne_CloseLog();


/*****************************************************************************
 �� �� ��  : LogOne_SetPrintLevel
 ��������  : ����ͳһ��־����
 �������  : E_LOG_LEVEL enLogLevel  
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2014��5��5��
    ��    ��   : jianghaiping 00191694
    �޸�����   : �����ɺ���

*****************************************************************************/
void   LogOne_SetPrintLevel(E_LOG_LEVEL enLogLevel);


/*****************************************************************************
 �� �� ��  : LogOne_Outputf
 ��������  : ��־����ӿ�
 �������  : VOS_INT8  *pszModelName     
             E_LOG_LEVEL enLogLevel      
             const VOS_CHAR* szFunction  
             const VOS_CHAR* szFile      
             VOS_INT32 iLine             
             const VOS_INT8 *pszFmt      
             ...                         
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2014��5��5��
    ��    ��   : jianghaiping 00191694
    �޸�����   : �����ɺ���

*****************************************************************************/
void     LogOne_Outputf(char  *pszModelName, 
                                    E_LOG_LEVEL enLogLevel, const char* szFunction,
                                    const char* szFile, int iLine, const char *pszFmt, ...);


//todo chenyake
void  LogOne_Outputf_test(char  *pszModelName, E_LOG_LEVEL enLogLevel, const char* szFunction,
                                    const char* szFile, int iLine, const char *pszFmt, va_list valist);


#define LOGONE_D_OUTPUT(pszModelName, ulLevel, fmt,...) \
        LogOne_Outputf(pszModeName, ulLevel, BASIC_INFO, ##fmt)

#define LOGONE_D_DEBUG(pszModelName, fmt,...) \
        LogOne_Outputf(pszModelName, E_LOG_DEBUG, BASIC_INFO, ##fmt)

#define LOGONE_D_INFO(pszModelName, fmt,...) \
        LogOne_Outputf(pszModelName, E_LOG_INFO, BASIC_INFO, ##fmt)
        
#define LOGONE_D_WARNING(pszModelName, fmt,...) \
        LogOne_Outputf(pszModelName, E_LOG_WARNING, BASIC_INFO, ##fmt)

#define LOGONE_D_ERROR(pszModelName, fmt,...) \
        LogOne_Outputf(pszModelName, E_LOG_ERROR, BASIC_INFO, ##fmt)

#if 1
#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#endif

#endif //LOGONE_INTERFACE_H


