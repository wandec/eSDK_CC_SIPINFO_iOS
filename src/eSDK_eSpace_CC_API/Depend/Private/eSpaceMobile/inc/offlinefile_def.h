/** 
* @file offlinefile_def.h
* 
* Copyright(C), 2012-2015, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
* 
* ������TUP IM �����ļ���ϵͳ�����ӿڽṹ�嶨��ͷ�ļ��� \n
*       �����ڴ�ʹ��ԭ�򣬲���˭����˭�ͷŵ�ԭ��        \n
*/

/**
*
*  @{
*/



#ifndef __OFFLINEFILE_DEF_H__
#define __OFFLINEFILE_DEF_H__

#include "tup_def.h"
#include "httpapi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */


#ifdef __cplusplus
#define OFFLINE_NULL    0
#else
#define OFFLINE_NULL    ((void *)0)
#endif

// �ļ����
typedef unsigned long               OFFLINEHANDLE;

#define OFFLINE_D_MAX_FILENAME      255                     /**< ��ļ������� */
#define OFFLINE_D_DEFAULT_CTRL_NUM  100                     /**< Ĭ��֧�ֵĿ��ƿ����� */
#define OFFLINE_D_MAX_URL_NUM       6                       /**< ��������ַ�б����ֵ */
#define OFFLINE_D_MAX_UPLOAD_NUM    3                       /**< �����ϴ�������ļ��� */


#define EN_OFFLINE_ERR_STATR        0x08006100UL                    /**< �����ļ�������ʼ�����룺TUP_ERR_SECTION & TUP_IM_ERR_SUB_SECTION & IM��ģ��(0x01 << 8) */    
#define EN_OFFLINE_CURLE_ERR_START  (0x08006100UL + 0x64UL)         /**< HTTP��Curl������ */

/**
 * �����ļ�ģ�������
 */
typedef enum tagOFFLINE_E_ERRORCODE{
    EN_OFFLINE_OK = 0,
    EN_OFFLINE_INIT_FAIL = EN_OFFLINE_ERR_STATR + 1,    /**< 1 Init fail */
    EN_OFFLINE_UNINIT,                          /**< 2 uninit */
    EN_OFFLINE_INVALID_PARAM,                   /**< 3 invalid param */
    EN_OFFLINE_INVALID_HANDLE,                  /**< 4 invalid handle */ 
    EN_OFFLINE_HANDLE_INUSE,                    /**< 5 handle in using, can't be set*/ 
    EN_OFFLINE_HANDLE_STATE_ERROR,              /**< 6 current handle state not support this operation*/
    EN_OFFLINE_ALLOC_MEM_FAIL,                  /**< 7 alloc fail */
    EN_OFFLINE_CREATE_HANDLE_FAIL,              /**< 8 alloc handle fail */
    EN_OFFLINE_INVALID_TLS_MODE,                /**< 9 tls mode error */
    EN_OFFLINE_INVALID_URL,                     /**< 10 invalid URL */
    EN_OFFLINE_INVALID_HEAD_TYPE,               /**< 11 invalid head type */
    EN_OFFLINE_OPEN_LOG_FAIL,                   /**< 12 open log file fail */
    EN_OFFLINE_WRITE_LOG_FAIL,                  /**< 13 write log file fail */
    EN_OFFLINE_INVALID_FILEPATH,                /**< 14 invalid file path */
    EN_OFFLINE_HANDLE_RELEASED,                 /**< 15 handle has been released */
    EN_OFFLINE_CREATE_MUTEX_FAIL,               /**< 16 create mutex fail */
    EN_OFFLINE_LOCK_MUTEX_FAIL,                 /**< 17 lock mutex fail*/
    EN_OFFLINE_UNLOCK_MUTEX_FAIL,               /**< 18 unlock mutex fail */
    EN_OFFLINE_CREATE_THREAD_FAIL,              /**< 19 create thread fail */
    EN_OFFLINE_NOT_SUPPORT,                     /**< 20 not support this function */
    EN_OFFLINE_SVN_SOCKET_CREATE_FAIL,          /**< 21 svn socket create fail */
    EN_OFFLINE_SVN_SOCKET_CONNECT_FAIL,         /**< 22 svn socket connect fail */
    EN_OFFLINE_SVN_SOCKET_SLECET_FAIL,          /**< 23 svn socket select fail */
    EN_OFFLINE_SVN_SOCKET_SEND_FAIL,            /**< 24 svn socket send fail */
    EN_OFFLINE_SVN_SOCKET_RECV_FAIL,            /**< 25 svn socket recv fail */
    EN_OFFLINE_GETHOSTNAME_FAIL,                /**< 26 get hostname fail */
    EN_OFFLINE_NET_NTOA_FAIL,                   /**< 27 IP net transfer fail*/
    EN_OFFLINE_RESPONSE_PARSE_ERR,              /**< 28 response parse fail */
    EN_OFFLINE_INVALID_AUTH_MODE,               /**< 29.invalid auth mode */
    EN_OFFLINE_NOT_LOGIN,                       /**< 30 is not login  */
    EN_OFFLINE_LOGINING,                        /**< 31 is  logining  */
    EN_OFFLINE_UPLOAD_DOWNLOAD_TIMEOUT,         /**< 32 is  TIMEOUT  */
    EN_OFFLINE_LOGINED,                         /**< 33 is  logined  */
    EN_OFFLINE_INITED,                          /**< 34 is  inited  */
    EN_OFFLINE_LOGPATH_TOOLONG,                 /**< 35 is  LogPath is too long */
    EN_OFFLINE_LOGPATH_EMPTY,                   /**< 36 is  LogPath is empty */

    EN_OFFLINE_CURLE_UNSUPPORTED_PROTOCOL = EN_OFFLINE_CURLE_ERR_START + 1,    /**< 101 */
    EN_OFFLINE_CURLE_FAILED_INIT,             /**< 102 */
    EN_OFFLINE_CURLE_URL_MALFORMAT,           /**< 103 */
    EN_OFFLINE_CURLE_NOT_BUILT_IN,            /**< 104 */
    EN_OFFLINE_CURLE_COULDNT_RESOLVE_PROXY,   /**< 105 */
    EN_OFFLINE_CURLE_COULDNT_RESOLVE_HOST,    /**< 106 */
    EN_OFFLINE_CURLE_COULDNT_CONNECT,         /**< 107 */
    EN_OFFLINE_CURLE_FTP_WEIRD_SERVER_REPLY,  /**< 108 */
    EN_OFFLINE_CURLE_REMOTE_ACCESS_DENIED,    /**< 109 a service was denied by the server
                                                        <br>due to lack of access - when login fails
                                                        <br>this is not returned. */
    EN_OFFLINE_CURLE_FTP_ACCEPT_FAILED,       /**< 110 */
    EN_OFFLINE_CURLE_FTP_WEIRD_PASS_REPLY,    /**< 111 */
    EN_OFFLINE_CURLE_FTP_ACCEPT_TIMEOUT,      /**< 112 - timeout occurred accepting server*/
    EN_OFFLINE_CURLE_FTP_WEIRD_PASV_REPLY,    /**< 113 */
    EN_OFFLINE_CURLE_FTP_WEIRD_227_FORMAT,    /**< 114 */
    EN_OFFLINE_CURLE_FTP_CANT_GET_HOST,       /**< 115 */
    EN_OFFLINE_CURLE_OBSOLETE16,              /**< 116 - NOT USED */
    EN_OFFLINE_CURLE_FTP_COULDNT_SET_TYPE,    /**< 117 */
    EN_OFFLINE_CURLE_PARTIAL_FILE,            /**< 118 */
    EN_OFFLINE_CURLE_FTP_COULDNT_RETR_FILE,   /**< 119 */
    EN_OFFLINE_CURLE_OBSOLETE20,              /**< 120 - NOT USED */
    EN_OFFLINE_CURLE_QUOTE_ERROR,             /**< 121 - quote command failure */
    EN_OFFLINE_CURLE_OFFLINE_RETURNED_ERROR,     /**< 122 */
    EN_OFFLINE_CURLE_WRITE_ERROR,             /**< 123 */
    EN_OFFLINE_CURLE_OBSOLETE24,              /**< 124 - NOT USED */
    EN_OFFLINE_CURLE_UPLOAD_FAILED,           /**< 125 - failed upload "command" */
    EN_OFFLINE_CURLE_READ_ERROR,              /**< 126 - couldn't open/read from file */
    EN_OFFLINE_CURLE_OUT_OF_MEMORY,           /**< 127 - CURLE_OUT_OF_MEMORY may sometimes indicate a conversion error
                                                        <br>instead of a memory allocation error if CURL_DOES_CONVERSIONS is defined */
    EN_OFFLINE_CURLE_OPERATION_TIMEDOUT,      /**< 128 - the timeout time was reached */
    EN_OFFLINE_CURLE_OBSOLETE29,              /**< 129 - NOT USED */
    EN_OFFLINE_CURLE_FTP_PORT_FAILED,         /**< 130 - FTP PORT operation failed */
    EN_OFFLINE_CURLE_FTP_COULDNT_USE_REST,    /**< 131 - the REST command failed */
    EN_OFFLINE_CURLE_OBSOLETE32,              /**< 132 - NOT USED */
    EN_OFFLINE_CURLE_RANGE_ERROR,             /**< 133 - RANGE "command" didn't work */
    EN_OFFLINE_CURLE_OFFLINE_POST_ERROR,         /**< 134 */
    EN_OFFLINE_CURLE_SSL_CONNECT_ERROR,       /**< 135 - wrong when connecting with SSL */
    EN_OFFLINE_CURLE_BAD_DOWNLOAD_RESUME,     /**< 136 - couldn't resume download */
    EN_OFFLINE_CURLE_FILE_COULDNT_READ_FILE,  /**< 137 */
    EN_OFFLINE_CURLE_LDAP_CANNOT_BIND,        /**< 138 */
    EN_OFFLINE_CURLE_LDAP_SEARCH_FAILED,      /**< 139 */
    EN_OFFLINE_CURLE_OBSOLETE40,              /**< 140 - NOT USED */
    EN_OFFLINE_CURLE_FUNCTION_NOT_FOUND,      /**< 141 */
    EN_OFFLINE_CURLE_ABORTED_BY_CALLBACK,     /**< 142 */
    EN_OFFLINE_CURLE_BAD_FUNCTION_ARGUMENT,   /**< 143 */
    EN_OFFLINE_CURLE_OBSOLETE44,              /**< 144 - NOT USED */
    EN_OFFLINE_CURLE_INTERFACE_FAILED,        /**< 145 - CURLOPT_INTERFACE failed */
    EN_OFFLINE_CURLE_OBSOLETE46,              /**< 146 - NOT USED */
    EN_OFFLINE_CURLE_TOO_MANY_REDIRECTS ,     /**< 147 - catch endless re-direct loops */
    EN_OFFLINE_CURLE_UNKNOWN_OPTION,          /**< 148 - User specified an unknown option */
    EN_OFFLINE_CURLE_TELNET_OPTION_SYNTAX ,   /**< 149 - Malformed telnet option */
    EN_OFFLINE_CURLE_OBSOLETE50,              /**< 150 - NOT USED */
    EN_OFFLINE_CURLE_PEER_FAILED_VERIFICATION, /**< 151 - peer's certificate or fingerprint wasn't verified fine */
    EN_OFFLINE_CURLE_GOT_NOTHING,             /**< 152 - when this is a specific error */
    EN_OFFLINE_CURLE_SSL_ENGINE_NOTFOUND,     /**< 153 - SSL crypto engine not found */
    EN_OFFLINE_CURLE_SSL_ENGINE_SETFAILED,    /**< 154 - can not set SSL crypto engine as default */
    EN_OFFLINE_CURLE_SEND_ERROR,              /**< 155 - failed sending network data */
    EN_OFFLINE_CURLE_RECV_ERROR,              /**< 156 - failure in receiving network data */
    EN_OFFLINE_CURLE_OBSOLETE57,              /**< 157 - NOT IN USE */
    EN_OFFLINE_CURLE_SSL_CERTPROBLEM,         /**< 158 - problem with the local certificate */
    EN_OFFLINE_CURLE_SSL_CIPHER,              /**< 159 - couldn't use specified cipher */
    EN_OFFLINE_CURLE_SSL_CACERT,              /**< 160 - problem with the CA cert (path?) */
    EN_OFFLINE_CURLE_BAD_CONTENT_ENCODING,    /**< 161 - Unrecognized/bad encoding */
    EN_OFFLINE_CURLE_LDAP_INVALID_URL,        /**< 162 - Invalid LDAP URL */
    EN_OFFLINE_CURLE_FILESIZE_EXCEEDED,       /**< 163 - Maximum file size exceeded */
    EN_OFFLINE_CURLE_USE_SSL_FAILED,          /**< 164 - Requested FTP SSL level failed */
    EN_OFFLINE_CURLE_SEND_FAIL_REWIND,        /**< 165 - Sending the data requires a rewind that failed */
    EN_OFFLINE_CURLE_SSL_ENGINE_INITFAILED,   /**< 166 - failed to initialise ENGINE */
    EN_OFFLINE_CURLE_LOGIN_DENIED,            /**< 167 - user, password or similar was not accepted and we failed to login */
    EN_OFFLINE_CURLE_TFTP_NOTFOUND,           /**< 168 - file not found on server */
    EN_OFFLINE_CURLE_TFTP_PERM,               /**< 169 - permission problem on server */
    EN_OFFLINE_CURLE_REMOTE_DISK_FULL,        /**< 170 - out of disk space on server */
    EN_OFFLINE_CURLE_TFTP_ILLEGAL,            /**< 171 - Illegal TFTP operation */
    EN_OFFLINE_CURLE_TFTP_UNKNOWNID,          /**< 172 - Unknown transfer ID */
    EN_OFFLINE_CURLE_REMOTE_FILE_EXISTS,      /**< 173 - File already exists */
    EN_OFFLINE_CURLE_TFTP_NOSUCHUSER,         /**< 174 - No such user */
    EN_OFFLINE_CURLE_CONV_FAILED,             /**< 175 - conversion failed */
    EN_OFFLINE_CURLE_CONV_REQD,               /**< 176 - caller must register conversion
                                    <br>callbacks using curl_easy_setopt options
                                    <br>CURLOPT_CONV_FROM_NETWORK_FUNCTION,
                                    <br>CURLOPT_CONV_TO_NETWORK_FUNCTION, and
                                    <br>CURLOPT_CONV_FROM_UTF8_FUNCTION */
    EN_OFFLINE_CURLE_SSL_CACERT_BADFILE,      /**< 177 - could not load CACERT file, missing or wrong format */
    EN_OFFLINE_CURLE_REMOTE_FILE_NOT_FOUND,   /**< 178 - remote file not found */
    EN_OFFLINE_CURLE_SSH,                     /**< 179 - error from the SSH layer, somewhat
                                    <br>generic so the error message will be of
                                    <br>interest when this has happened */
    EN_OFFLINE_CURLE_SSL_SHUTDOWN_FAILED,     /**< 180 - Failed to shut down the SSL connection */
    EN_OFFLINE_CURLE_AGAIN,                   /**< 181 - socket is not ready for send/recv, wait till it's ready and try again */
    EN_OFFLINE_CURLE_SSL_CRL_BADFILE,         /**< 182 - could not load CRL file, missing or wrong format */
    EN_OFFLINE_CURLE_SSL_ISSUER_ERROR,        /**< 183 - Issuer check failed. */
    EN_OFFLINE_CURLE_FTP_PRET_FAILED,         /**< 184 - a PRET command failed */
    EN_OFFLINE_CURLE_RTSP_CSEQ_ERROR,         /**< 185 - mismatch of RTSP CSeq numbers */
    EN_OFFLINE_CURLE_RTSP_SESSION_ERROR,      /**< 186 - mismatch of RTSP Session Ids */
    EN_OFFLINE_CURLE_FTP_BAD_FILE_LIST,       /**< 187 - unable to parse FTP file list */
    EN_OFFLINE_CURLE_CHUNK_FAILED,            /**< 188 - chunk callback reported error */

    EN_OFFLINE_CURL_CREATE_HANDLE_FAIL = (EN_OFFLINE_ERR_STATR + 201),   /**< 201 */
    EN_OFFLINE_CURL_SET_HEAD_FAIL,                     /**< 202 */


    EN_OFFLINE_LOGIN_FAILED,                /**< EN_OFFLINE_ERR_STATR+203: ��¼ʧ�� */
    EN_OFFLINE_LOAD_NSCALIB_FAIL,           /**< EN_OFFLINE_ERR_STATR+204: Load NscaMiniLib failed �����ʲ�У������ʧ�� */
    EN_OFFLINE_GET_NSCAFUNC_FAIL,           /**< EN_OFFLINE_ERR_STATR+205: Get NscaFunc failed �����ʲ�У���ӿڻ�ȡʧ�� */
    EN_OFFLINE_CHECKLABEL_TRUE,             /**< EN_OFFLINE_ERR_STATR+206: The document has label �ĵ��к����ʲ���ǩ */
    EN_OFFLINE_INVALID_FILEINFO,            /**< EN_OFFLINE_ERR_STATR+207: Invalid file info ������ļ���Ϣ���� */
    EN_OFFLINE_INVALID_FILEMD5,             /**< EN_OFFLINE_ERR_STATR+208: Invalid file SHA1 ������ļ���MD5���� */
    EN_OFFLINE_GETSHARELINK_FAIL,           /**< EN_OFFLINE_ERR_STATR+209: ��ȡ����ʧ��*/
    EN_OFFLINE_INVALID_SERVERMODE,          /**< EN_OFFLINE_ERR_STATR+210: ����ķ���������*/
    EN_OFFLINE_PRUPLOAD_EXIST,              /**< EN_OFFLINE_ERR_STATR+211: Ԥ�ϴ��ļ��Ѵ���*/
    EN_OFFLINE_PRUPLOAD_FAIL,               /**< EN_OFFLINE_ERR_STATR+212: Ԥ�ϴ��ļ�ʧ��*/
    EN_OFFLINE_UPLOAD_FAIL,                 /**< EN_OFFLINE_ERR_STATR+213: �ϴ��ļ�ʧ��*/
    EN_OFFLINE_MORETHAN_TRANSMAX,           /**< EN_OFFLINE_ERR_STATR+214: �ϴ��ļ������������3G*/
    EN_OFFLINE_DELETEFILE_FAIL,             /**< EN_OFFLINE_ERR_STATR+215: ɾ���ļ�ʧ��*/
    EN_OFFLINE_FINISHFILE_FAIL,             /**< EN_OFFLINE_ERR_STATR+216: ��ɷ�Ƭ����ʧ��*/
    EN_OFFLINE_PARTCOUNT_LARGER,            /**< EN_OFFLINE_ERR_STATR+217: ��Ƭ��Ƭ������HTTP������*/
    EN_OFFLINE_OPENFILE_FAIL,               /**< EN_OFFLINE_ERR_STATR+218: ���ļ�ʧ��*/
    EN_OFFLINE_UPLOADFILE_FINISHING,        /**< EN_OFFLINE_ERR_STATR+219: �ļ��ϴ���������*/
    EN_OFFLINE_RESUMEURL_NULL,              /**< EN_OFFLINE_ERR_STATR+220: ������URLΪ��*/
    EN_OFFLINE_DISK_FULL,                   /**< EN_OFFLINE_ERR_STATR+221: �������ռ���*/
    EN_OFFLINE_ERROR_EXPIREDAT,             /**< EN_OFFLINE_ERR_STATR+222: ����ˢ��tokenֵ*/
    EN_OFFLINE_ERROR_INITPARTINFO,          /**< EN_OFFLINE_ERR_STATR+223: ���̳�ʼ����Ƭ��Ϣʧ��*/  
    EN_OFFLINE_ERRORCODE_BUTT               /**< never used */
}OFFLINE_E_ERRORCODE;


/**
 * �ļ��������������
 */
typedef enum OFFLINE_SERVER_MODE
{
    OFFLINE_TRANSFER_NONE           = 0,
    OFFLINE_TRANSFER_CLOUDSTORE     = 1,        /**< ��ΪUC�����̣� */
    OFFLINE_TRANSFER_UM             = 2,        /**< ����UM */
    OFFLINE_TRANSFER_BUIT
}OFFLINE_SERVER_MODE;

/**
 * ��־����
 */
typedef enum
{
    OFFLINE_LOG_NONE        = 0,    /**< ��־�ر� */
    OFFLINE_LOG_ERROR       = 1,    /**< ERROR ���� */
    OFFLINE_LOG_WARNING     = 2,    /**< WARNING ���� */
    OFFLINE_LOG_INFO        = 3,    /**< INFOMATION ���� */
    OFFLINE_LOG_DEBUG       = 4,    /**< DEBUG ���� */
    OFFLINE_LOG_BUIT
}OFFLINE_LOG_LEVEL;

/**
 * ��־����
 */
typedef struct tagST_OFFLINE_LOGCONFIG
{
    OFFLINE_LOG_LEVEL       enLevel;            /**< ��־���� */
    TUP_UINT32              uiLogFileSize;      /**< ��־�ļ����size (��λ��M��ȡֵ��Χ[1,50]�� */
    TUP_CHAR*               pcFilePath;         /**< ��־����·�� */

    tagST_OFFLINE_LOGCONFIG()
    {
        enLevel         = OFFLINE_LOG_NONE;
        uiLogFileSize   = 3;
        pcFilePath      = OFFLINE_NULL;        
    }
}OFFLINE_LOGCONFIG;

/**
 * �ļ������ʼ������
 */
typedef struct tagST_OFFLINE_INITCONFIG
{
    OFFLINE_LOGCONFIG       stLogConfig;        /**< ��־������Ϣ */
    TUP_UINT                uiHandleNum;        /**< ��֧�ֵĿ��ƿ�����������OFFLINE_D_MAX_MUTI_TRANS�� */
    TUP_BOOL                bUseSvn;            /**< �Ƿ���svn��Ĭ�Ϲر�*/
    TUP_BOOL                bUseSvnFile;        /**< �Ƿ����ʱ���д�ļ�����svn�ӽ��ܷ�ʽ��Ĭ�Ϲر� */
    
    tagST_OFFLINE_INITCONFIG()
    {
        uiHandleNum = 0;
        bUseSvn = TUP_FALSE;
        bUseSvnFile  = TUP_FALSE;
    }

}OFFLINE_INITCONFIG;

/**
 * ��������ַ
 */
typedef struct tagST_OFFLINE_SERVERINFO
{
    TUP_CHAR*           pcHostIP;        /**< ������IP��ַ */
    TUP_UINT            uiHostPort;      /**< �������˿ں� */
    TUP_CHAR*           pcUrl;           /**< ���������url */
    EN_TLS_MODE         enTlsMode;       /**< https�����TLSģʽ */

    tagST_OFFLINE_SERVERINFO()
    {
        pcHostIP        = OFFLINE_NULL;
        uiHostPort      = 0;
        pcUrl           = OFFLINE_NULL;
        enTlsMode       = EN_TLS_CLOSE;
    }
}OFFLINE_SERVERINFO;

/**
 * ��������ַ�б�
 */
typedef struct tagST_OFFLINE_SERVERLIST
{
    OFFLINE_SERVERINFO stServerUrl[OFFLINE_D_MAX_URL_NUM];  /**< ������url�б�*/
    TUP_UINT32 ulCnt;                                       /**< ���������� */
}OFFLINE_SERVERLIST;

/**
 * �ļ������¼��������Ϣ
 */
typedef struct tagST_OFFLINE_LOGININFO
{
    EN_TLS_MODE                 enTlsMode;          /**< TLS ģʽ(default value is 1) */
    ST_HTTP_TLS_PARA            stTlsPara;          /**< TLS ������Ϣ(default set pcCaCertPath for CA Path) */
    TUP_CHAR*                   pcLocalIP;          /**< ����IP������ */
    TUP_UINT                    timeout;            /**< ���ӳ�ʱʱ�䣬Ĭ��Ϊ0 */
    TUP_UINT                    tryConnectTimeout;  /**< �������ӳ�ʱʱ�� */

    TUP_BOOL                    bEncryTrans;        /**< �Ƿ���ܴ��䣨�ϴ��������ļ��Ƿ����-https�� */
    OFFLINE_SERVER_MODE         enServerMode;       /**< ���������� */
    OFFLINE_SERVERLIST          stHttpSerList;      /**< HTTP�������б� */
    OFFLINE_SERVERLIST          stHttpsSerList;     /**< HTTPS�������б� */
    TUP_LONG                    lServerExpiredAt;   /**< ̽�������ˢ��ʱ�䣬��λ���� */

    TUP_UINT64                  ulMaxFileSize;      /**< �ļ���С������ƣ�Ĭ��3G����λ��byte */
    TUP_BOOL                    bPartTrans;         /**< �Ƿ�֧�ַ�Ƭ���䣬Ĭ�ϲ�֧��false */
    TUP_UINT64                  ulMinPartSize;      /**< ��Ƭ�����ļ�����С���ƣ�С�ڴ�size�������з�Ƭ����Ĭ��40M����λ��byte */
    TUP_UINT64                  ulPartTransSize;    /**< ��Ƭ����ÿƬ��С��Ĭ��5M����λ��byte */

    tagST_OFFLINE_LOGININFO()
    {
        enTlsMode           = EN_TLS_CLOSE;
        pcLocalIP           = OFFLINE_NULL;
        timeout             = 0;
        tryConnectTimeout   = 0;

        bEncryTrans         = TUP_TRUE;
        enServerMode        = OFFLINE_TRANSFER_NONE;
        lServerExpiredAt    = 0;

        ulMaxFileSize       = 0;
        bPartTrans          = TUP_FALSE;
        ulMinPartSize       = 0;
        ulPartTransSize     = 0;        
    }
}OFFLINE_LOGININFO;

/**
 * ��¼���û���Ϣ
 */
typedef struct tagST_OFFLINE_USERINFO
{
    TUP_CHAR*   pcLoginName;        /**< �û��������� */
    TUP_CHAR*   pcPassword;         /**< �û����룬���� */
    TUP_CHAR*   pcAppName;          /**< Ӧ�����ƣ��磺eSpace������ѡ */
    TUP_CHAR*   pcLoginType;        /**< ��¼���ͣ����UM��������1Ϊ�����Ȩ��2Ϊָ�Ƽ�Ȩ��3Ϊticketί�м�Ȩ�����̲�֧�֣���δ֧�֣� */

    TUP_CHAR*   pcDeviceType;       /**< pc android ios web������ */
    TUP_CHAR*   pcDeviceName;       /**< �ͻ�������,PC������,�ֻ��ͺţ����� */
    TUP_CHAR*   pcDeviceOS;         /**< �ͻ��� ����ϵͳ������ */
    TUP_CHAR*   pcDeviceSN;         /**< �ͻ���Ψһ���кţ����� */
    TUP_CHAR*   pcDeviceVersion;    /**< �ͻ��˰汾������  */

    tagST_OFFLINE_USERINFO()
    {
        pcLoginName     = OFFLINE_NULL;
        pcPassword      = OFFLINE_NULL;
        pcAppName       = OFFLINE_NULL;
        pcLoginType     = OFFLINE_NULL;

        pcDeviceType    = OFFLINE_NULL;
        pcDeviceName    = OFFLINE_NULL;
        pcDeviceOS      = OFFLINE_NULL;
        pcDeviceSN      = OFFLINE_NULL;
        pcDeviceVersion = OFFLINE_NULL;
    }
}OFFLINE_USERINFO;



/**
 * �ļ������ļ�ģʽ
 */
typedef enum OFFLINE_FILE_TYPE
{
    OFFLINE_TYPE_FILE    = 0,               /**< �ļ�ģʽ */
    OFFLINE_TYPE_FOLDER  = 1,               /**< �ļ���ģʽ */
    OFFLINE_TYPE_BUTT
}OFFLINE_FILE_TYPE;

/**
 * �ļ������ϲ�ص�����
 */
typedef enum OFFLINE_CALLBACK_TYPE
{
    OFFLINE_CALLBACK_PREUPLOAD     = 0,        /**< Ԥ�ϴ��ص� */
    OFFLINE_CALLBACK_UPLOAD        = 1,        /**< �ϴ��ص� */
    OFFLINE_CALLBACK_DOWNLOAD      = 2,        /**< ���ػص� */
    OFFLINE_CALLBACK_UPLOAD_PART   = 3,        /**< �ϴ���Ƭ�ص� */
    OFFLINE_CALLBACK_BUTT
}OFFLINE_CALLBACK_TYPE;


/**
 * �ϴ��ļ���Ϣ
 */
typedef struct tagST_OFFLINE_UP_FILEINFO
{
    TUP_CHAR*               pcFilePath;         /**< ������ļ�����·���������ļ�������Σ� */
    TUP_CHAR*               pcFileName;         /**< ������ļ�������Σ�  */ 
    TUP_CHAR*               pcResumeFileId;     /**< ������fileid����һ���ϴ���Ϊ�� */
    TUP_CHAR*               pcResumeUpURL;      /**< ������UploadURL����һ���ϴ���Ϊ�� */
    TUP_CHAR*               pcResumeDownURL;    /**< ������DownloadURL����һ���ϴ���Ϊ�� */
    TUP_CHAR*               pcResumeMd5;        /**< �������ļ�md5����һ���ϴ���Ϊ�� */
    TUP_CHAR*               pcResumeSignature;  /**< UM�������ļ���ȡ�룬��һ���ϴ���Ϊ�� */
    void *                  userInfo;           /**< �û���Ϣ����Σ�����Ϊ�� */
    TUP_BOOL                bDeleteFile;        /**< �Ƿ�����ɾ���ļ���true or false�� */
    TUP_BOOL                bUseSvnFile;        /**< �Ƿ����MDM���ܣ�true or false�� */
    
    TUP_CHAR*               pcFileType;         /**< �ļ�����,normal�����ͨ�����ļ���group��Ⱥ�ļ���circle������Ȧ�ļ� */
    TUP_CHAR*               pcOperationToken;   /**< ����operationTokenʹ�� */
    TUP_CHAR*               pcGroupId;          /**< ȺID������ϴ�����Ⱥ�ļ�����ָ�� */

    tagST_OFFLINE_UP_FILEINFO()
    {
        pcFilePath          = OFFLINE_NULL;
        pcFileName          = OFFLINE_NULL;
        pcResumeFileId      = OFFLINE_NULL;
        pcResumeUpURL       = OFFLINE_NULL;
        pcResumeDownURL     = OFFLINE_NULL;
        pcResumeMd5         = OFFLINE_NULL;
        pcResumeSignature   = OFFLINE_NULL;
        userInfo            = OFFLINE_NULL;
        bDeleteFile         = TUP_FALSE;
        bUseSvnFile         = TUP_FALSE;
        pcFileType          = OFFLINE_NULL;
        pcOperationToken    = OFFLINE_NULL;
        pcGroupId           = OFFLINE_NULL;
    }
}OFFLINE_UP_FILEINFO;

/**
 * ����������Ϣ
 */
typedef struct tagST_OFFLINE_PlainAccess
{
    TUP_CHAR*   pcplainAccessCode;          /**< ������ȡ�루��ѡ�� */
    TUP_CHAR*   pctype;                     /**< �������ص��ļ����͡�original ԭʼ�ļ���thumbnail ����ͼ����ѡ�� */
    TUP_CHAR*   pcheight;                   /**< ����ͼ�߶ȡ�typeΪthumbnailʱ��ѡ��type����thumbnail��û��ʵ�����壬���Բ����� */
    TUP_CHAR*   pcwidth;                    /**< ����ͼ��ȡ�typeΪthumbnailʱ��ѡ��type����thumbnail��û��ʵ�����壬���Բ����� */

    tagST_OFFLINE_PlainAccess()
    {
        pcplainAccessCode = HTTP_NULL;
        pctype = HTTP_NULL;
        pcheight = HTTP_NULL;
        pcwidth = HTTP_NULL;
    }

}OFFLINE_PlainAccess;

/**
 * �����ļ���Ϣ
 */
typedef struct tagST_OFFLINE_DOWN_FILEINFO
{    
    TUP_CHAR*   pcFilePath;                 /**< �����ļ��洢�ľ���·�� */
    TUP_CHAR*   pcFileDownUrl;              /**< ����URL */
    void*       userInfo;                   /**< �û���Ϣ����Σ� */
    TUP_BOOL    bDownDelete;                /**< ���غ��Ƿ�ɾ�� */
    TUP_BOOL                bUseSvnFile;    /**< �Ƿ����MDM���ܣ�true or false�� */
    OFFLINE_PlainAccess*    pPlainAccess;   /**< ����������Ϣ����û����Ϊ�գ� */

    tagST_OFFLINE_DOWN_FILEINFO()
    {
        pcFilePath      = OFFLINE_NULL;
        pcFileDownUrl   = OFFLINE_NULL;
        userInfo        = OFFLINE_NULL;
        bDownDelete     = TUP_FALSE;
        pPlainAccess    = OFFLINE_NULL;
        bUseSvnFile     = TUP_FALSE;
    }

}OFFLINE_DOWN_FILEINFO;

/**
 * �ļ�������Ӧ��Ϣ
 */
typedef struct tagST_OFFLINE_RSPFILEINFO
{
    OFFLINE_CALLBACK_TYPE   enCallbackType;

    TUP_CHAR*               pcFileId;           /**< �ļ�ID��Ϣ */
    TUP_CHAR*               pcPlainAccessCode;  /**< �ļ�������ȡ�� */
    TUP_CHAR*               pcUrl;              /**< �ļ�����URL */
    OFFLINEHANDLE           ulHandle;           /**< �ļ������Ϣ */

    TUP_ULONG               ulStatusCode;       /**< ������������ */
    TUP_CHAR*               pcCodeMsg;          /**< ��������Ϣ */

    tagST_OFFLINE_RSPFILEINFO()
    {
        enCallbackType      = OFFLINE_CALLBACK_BUTT;
        pcFileId            = OFFLINE_NULL;
        pcPlainAccessCode   = OFFLINE_NULL;
        pcUrl               = OFFLINE_NULL;
        ulHandle            = 0;

        ulStatusCode        = 0;
        pcCodeMsg           = OFFLINE_NULL;
    }

}OFFLINE_RSPFILEINFO;


/** 
 *�ļ�������Ӧ��Ϣ
 */
typedef struct tagST_OFFLINE_DELETEFILE
{
    TUP_CHAR*          pcChar;             /**< �Խ����̶�ӦfileID�� �Խ�UM��Ӧdownloadurl */
    TUP_CHAR*          pcOperationToken;   /**< ����operationTokenʹ�� */
    TUP_CHAR*          pcSignature;        /**< UM��ȡ�� */

    tagST_OFFLINE_DELETEFILE()
    {
        pcChar              = OFFLINE_NULL;
        pcOperationToken    = OFFLINE_NULL;
        pcSignature         = OFFLINE_NULL;
    }

}OFFLINE_DELETEFILE;


/**
 * @brief �ļ���������Ӧ֪ͨ
 * 
 * @param [in] OFFLINEHANDLE fileHandle         <b>:</b> �ļ����
 * @param [in] TUP_ULONG enCode                 <b>:</b> ������
 * @param [in] OFFLINE_RSPFILEINFO *pstFileRsp  <b>:</b> ������Ӧ
 * @param [in] void *userInfo                   <b>:</b> �û��Զ�����Ϣ
 * @param [out] NA
 * @retval typedef int (* <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see 
 **/
typedef int (*OffLineFileRspNotify)(OFFLINEHANDLE fileHandle, TUP_ULONG enCode, OFFLINE_RSPFILEINFO *pstFileRsp, void *userInfo);


/**
 * @brief �ļ��������(����)֪ͨ
 * 
 * @param [in] OFFLINEHANDLE fileHandle  <b>:</b> �ļ����
 * @param [in] TUP_UINT64 ulTotal        <b>:</b> ��Ҫ�����������С
 * @param [in] TUP_UINT64 ulNow          <b>:</b> �Ѿ�����Ĵ�С
 * @param [in] void *userInfo            <b>:</b> �û��Զ�����Ϣ
 * @param [out] NA
 * @retval typedef void (* <b>:</b> 
 * 
 * @attention NA
 * @see 
 **/
typedef void (*OffLineTransProgressNotify)(OFFLINEHANDLE fileHandle, TUP_UINT64 ulTotal, TUP_UINT64 ulNow, void *userInfo);


#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */


#endif  /* __OFFLINEFILE_DEF_H__ */

/** @}*/

/*
* History: \n
* 2012-12-10, ��ʼ�����ļ��� \n
* 2015-12-30, TUP V100R001C50 TR5 ���������´��ļ��� \n
 *
* vi: set expandtab ts=4 sw=4 tw=80:
*/


