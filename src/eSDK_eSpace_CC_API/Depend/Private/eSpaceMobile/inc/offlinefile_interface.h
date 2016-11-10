/** 
* @file offlinefile_interface.h
* 
* Copyright(C), 2012-2015, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
* 
* ������TUP IM ��¼��ϵͳ�����ӿڽṹ�嶨��ͷ�ļ��� \n
*/

/**
*
*  @{
*/

#ifndef __OFFLINEFILE_INTERFACE_H__
#define __OFFLINEFILE_INTERFACE_H__

// ���ļ���Ҫ������ͷ�ļ�
#include "offlinefile_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /*  __cpluscplus */
#endif /*  __cpluscplus */



/**
 * @brief �ļ������¼��ʼ��
 * 
 * @param [in] const OFFLINE_INITCONFIG* pstConfig    <b>:</b> ��ʼ��������Ϣ
 * @param [in] const OFFLINE_LOGININFO* pstLoginInfo  <b>:</b> ��¼��Ϣ
 * @param [in] const OFFLINE_USERINFO* pstUserInfo    <b>:</b> ��¼�û���Ϣ
 * @param [in] TUP_ULONG* pLogInResult                <b>:</b> ��¼����������������룩
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �����ӿڣ��Ƽ�ʹ��tup_offlinefile_init&tup_offlinefile_login
 * @see tup_offlinefile_uninitlogout
 **/
TUP_API TUP_RESULT tup_offlinefile_initlogin(const OFFLINE_INITCONFIG* pstConfig, 
                                             const OFFLINE_LOGININFO* pstLoginInfo, 
                                             const OFFLINE_USERINFO* pstUserInfo, 
                                             TUP_ULONG* pLogInResult);
/**
 * @brief �ļ������ʼ��
 * 
 * @param [in] OFFLINE_INITCONFIG* config <b>:</b> ��ʼ��������Ϣ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_offlinefile_uninit
 **/
TUP_API TUP_RESULT tup_offlinefile_init(const OFFLINE_INITCONFIG* config);


/**
 * @brief ������־
 * 
 * @param [in] const OFFLINE_LOGCONFIG* config ��־���ò���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �Ѿ���ʼ����֧�ֶ�̬������ر���־��Ĭ�Ϲر�
 * @see tup_offlinefile_closelog
 **/
TUP_API TUP_RESULT tup_offlinefile_openlog(const OFFLINE_LOGCONFIG* config);

/**
 * @brief �ر���־
 * 
 * @param [in] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �Ѿ���ʼ����֧�ֶ�̬������ر���־��Ĭ�Ϲر�
 * @see tup_offlinefile_openlog
 **/
TUP_API TUP_RESULT tup_offlinefile_closelog();

/**
 * @brief �ļ������¼
 * 
 * @param [in] const OFFLINE_LOGININFO * pstLogInfo <b>:</b> ��¼��Ϣ
 * @param [in] const OFFLINE_USERINFO * pstUserInfo  <b>:</b> ��¼�û���Ϣ
 * @param [out] TUP_ULONG * pLogInResult <b>:</b> ��¼���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_offlinefile_logout
 **/
TUP_API TUP_RESULT tup_offlinefile_login(const OFFLINE_LOGININFO* pstLoginInfo, 
                                         const OFFLINE_USERINFO* pstUserInfo, 
                                         TUP_ULONG* pLogInResult);


/**
 * @brief �ļ��ϴ����첽�ӿڣ����ú�ֱ�ӷ��أ�ͨ���ص�֪ͨ�ϲ���Ⱥʹ�������
 * 
 * @param [in] OFFLINE_UP_FILEINFO* pUpFileInfo <b>:</b> �ļ��ϴ���Ϣ��֧�ִ���һ���ļ�
 * @param [in] OffLineTransProgressNotify offLineProgNotifyFunc  <b>:</b> ���̻ص�������֪ͨ�ϲ��ļ��������
 * @param [in] OffLineFileRspNotify offLineRspNotifyFunc  <b>:</b> �ϴ�������Ӧ�ص����ɻ�ȡ�����롢״̬����������Ϣ
 * @param [out] OFFLINEHANDLE* pFileHandle <b>:</b> �ļ���������Σ�
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_offlinefile_downloadfile
 * @see tup_offlinefile_deletefile
 * @see tup_offlinefile_release
 * @see tup_offlinefile_cancel
 **/
TUP_API TUP_RESULT tup_offlinefile_uploadfile(const OFFLINE_UP_FILEINFO* pUpFileInfo, 
                                              OFFLINEHANDLE* pFileHandle, 
                                              OffLineTransProgressNotify offLineProgNotifyFunc, 
                                              OffLineFileRspNotify offLineRspNotifyFunc);


/**
 * @brief ��ȡ������URL
 * 
 * @param [in] OFFLINEHANDLE fileHandle <b>:</b> �ļ����
 * @param [out] TUP_CHAR** ppcResumeUpURL <b>:</b> �������ϴ�URL
 * @param [out] TUP_CHAR** ppcFileId <b>:</b> �������ļ�id
 * @param [out] TUP_CHAR** ppcResumeDownURL <b>:</b> ����������URL
 * @param [out] TUP_CHAR** ppcMd5 <b>:</b> ������md5
 * @param [out] TUP_CHAR** ppcSignature <b>:</b> ��������ȡ����Ϣ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention 
 * @see tup_offlinefile_downloadfile
 **/
TUP_API TUP_RESULT tup_offlinefile_getresumeupurl(OFFLINEHANDLE fileHandle, TUP_CHAR** ppcFileId,
                                                  TUP_CHAR** ppcResumeUpURL, 
                                                  TUP_CHAR** ppcResumeDownURL,
                                                  TUP_CHAR** ppcMd5,
                                                  TUP_CHAR** ppcSignature);


/**
 * @brief �ļ����أ��첽�ӿڣ����ú�ֱ�ӷ��أ�ͨ���ص���֪ͨ�ϲ���Ⱥʹ�������
 * 
 * @param [in] const OFFLINE_DOWN_FILEINFO* pDownFileInfo <b>:</b> �ļ�������Ϣ
 * @param [in] OffLineTransProgressNotify offLineProgNotifyFunc  <b>:</b> ���̻ص�������֪ͨ�ϲ��ļ��������
 * @param [in] OffLineFileRspNotify offLineRspNotifyFunc  <b>:</b> ��Ӧ�ص����ɻ�ȡ�����롢״̬����Ϣ
 * @param [out] OFFLINEHANDLE* pFileHandle <b>:</b> �ļ���������Σ�
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_offlinefile_uploadfile
 * @see tup_offlinefile_getresumeupurl
 * @see tup_offlinefile_deletefile
 * @see tup_offlinefile_release
 * @see tup_offlinefile_cancel
 **/
TUP_API TUP_RESULT tup_offlinefile_downloadfile(const OFFLINE_DOWN_FILEINFO* pDownFileInfo, 
                                                OFFLINEHANDLE* pcFileHandle,         
                                                OffLineTransProgressNotify offLineProgNotifyFunc, 
                                                OffLineFileRspNotify offLineRspNotifyFunc);


/**
 * @brief ɾ���ϴ����ļ�
 * 
 * @param [in] OFFLINE_DELETEFILE* pcDeleteFile <b>:</b> ɾ���ļ�����Ϣ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_offlinefile_uploadfile
 * @see tup_offlinefile_downloadfile
 * @see tup_offlinefile_release
 * @see tup_offlinefile_cancel
 **/
TUP_API TUP_RESULT tup_offlinefile_deletefile(OFFLINE_DELETEFILE* pcDeleteFile);


/**
 * @brief ɾ���ϴ����ļ�
 * 
 * @param [in] TUP_CHAR* pcChar <b>:</b> �Խ����̶�ӦfileID�� �Խ�UM��Ӧdownloadurl
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �����ӿڣ�����ʹ��tup_offlinefile_deletefile
 *            
 * @see tup_offlinefile_delete
 **/
TUP_API TUP_RESULT tup_offlinefile_delete(TUP_CHAR* pcChar);



/**
 * @brief ȡ���ļ�����
 * 
 * @param [in] OFFLINEHANDLE fileHandle <b>:</b> �ļ����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention 
 * @see tup_offlinefile_uploadfile
 * @see tup_offlinefile_downloadfile
 * @see tup_offlinefile_deletefile
 * @see tup_offlinefile_cancel
 **/
TUP_API TUP_RESULT tup_offlinefile_release(OFFLINEHANDLE fileHandle);


/**
 * @brief ������Ƭ�����ȡ���ļ����䣬��ʱ������������ɾ���Ѿ����ص��ļ�
 * 
 * @param [in] OFFLINEHANDLE fileHandle <b>:</b> �ļ����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_offlinefile_uploadfile
 * @see tup_offlinefile_downloadfile
 * @see tup_offlinefile_deletefile
 * @see tup_offlinefile_release
 **/
TUP_API TUP_RESULT tup_offlinefile_cancel(OFFLINEHANDLE fileHandle);


/**
 * @brief �ļ������ó���ȥ��ʼ��
 * 
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �����ӿڣ��Ƽ�ʹ��tup_offlinefile_uninit&tup_offlinefile_logout
 * @see tup_offlinefile_initlogin
 **/
TUP_API TUP_RESULT tup_offlinefile_uninitlogout();

/**
 * @brief �ǳ�
 * 
 * @param [in] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 *            
 * @see tup_offlinefile_login
 **/
TUP_API TUP_RESULT tup_offlinefile_logout();


/**
 * @brief ȥ��ʼ��
 * 
 * @param [in] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 *            
 * @see tup_offlinefile_init
 **/
TUP_API TUP_RESULT tup_offlinefile_uninit();

#ifdef __cplusplus
#if __cplusplus
}
#endif /*  __cpluscplus */
#endif /*  __cpluscplus */


#endif  // __OFFLINEFILE_INTERFACE_H__

/*
* History: \n
* 2012-12-10, ��ʼ�����ļ��� \n
* 2015-12-30, TUP V100R001C50 TR5 ���������´��ļ��� \n
 *
* vi: set expandtab ts=4 sw=4 tw=80:
*/
