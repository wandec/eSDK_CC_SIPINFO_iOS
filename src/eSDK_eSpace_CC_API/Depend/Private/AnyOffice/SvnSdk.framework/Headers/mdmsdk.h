/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : mdmsdk.c
  版 本 号   : 初稿
  作    者   : kongsheng
  生成日期   : 2013年12月6日
  最近修改   :
  功能描述   : 资产管理模块相关函数
  函数列表   :
  修改历史   :
  1.日    期   : 2013年12月6日
    作    者   : kongsheng
    修改内容   : 创建文件

******************************************************************************/
#ifndef __MDMSDK_H__
#define __MDMSDK_H__
#include "mdmsdk_api.h"
#include "svn_file_api_ex.h"
#include "secentry/common/secentry_pub.h"
#include "svn_define.h"
#include "secentry/diagnose/Diagnose_Pub.h"
#include "secentry/cmtm/cmtm_main.h"






 
#define MDMSDK_ASSERT_BINDED_BY_USER                                         1  /* 已经被当前登录用户绑定*/
#define MDMSDK_ASSERT_APPROVING                                                   2  /*不区分是否开启多用户功能：未绑定&正在审批*/
#define MDMSDK_ASSERT_BYOND_LIMINT                                             3  /*不区分是否开启多用户功能：超过允许绑定设备数量*/
#define MDMSDK_ASSERT_BINDED_BY_OTHERS                                    4  /*   该设备已被其他用户绑定*/
#define MDMSDK_ASSERT_REG_BY_OTHERS                                          5 /*不区分是否开启多用户功能*/
#define MDMSDK_ASSERT_NONBINDED                                                  6  /*未绑定&可绑定*/
#define MDMSDK_ASSERT_BINDED_FAILED                                           7  /* 注册通过但是未查看过保密协议*/
#define MDMSDK_ASSERT_AGREEMENT_NOREAD                                   8 /*注册通过但是未查看过保密协议*/
#define MDMSKD_ASSERT_AGREEMENT_NOREAD_OTHERS                    9 /*注册通过但是未查看过保密协议*/
#define MDMSDK_ASSERT_BINDED_MULTIUSER                                    10 /*已经被其它用户绑定-----与ASSERT_BINDED_BY_OTHERS对应*/
#define MDMSDK_ASSERT_LOGON_TIMEOUT                                         12 /*该设备超期未登录:对于多用户，没有任何一个用户登录过该设备*/

#define MDMSDK_KICKOFF                                                                    15
#define MDMSDK_NO_CHECKRESULT                                                     16

#define MDMDSDK_UNKOWN_ERROR                                                       0xFFFF

#define MDMSDK_MAX_CURL_URL_LEN                                                  640
#define MDMSDK_CONTENT_RETURN_LEN                                             8
#define MDMSDK_POST_URI_MAX_LEN                                                 16384

#define MDMSDK_ERR                                                                            0x0bad
#define MDMSDK_OK                                                                              0

#define MDMSDK_MAX_DEV_ID_LEN                                                      64

#define MDMSDK_DEFAULT_GWPORT                                                     443

#define MDMSDK_TIMOUT                                                                      15

#define MDMSDK_HTTP_RESP_CODE_OK       200 
#define MDMSDK_ELEMENT_MAX_LEN  (64)


#define SVN_GLOBAL_SSL (1<<0)
#define SVN_GLOBAL_WIN32 (1<<1)
#define SVN_GLOBAL_ALL (SVN_GLOBAL_SSL|SVN_GLOBAL_WIN32)

#ifndef  SvnHttp
#define SvnHttp void
#endif

#define SVN_HTTP_ERR -1 
#define SVN_HTTP_OK 0
#define SVNHTTPTYPE_LONG          0
#define SVNHTTPTYPE_OBJECTPOINT   10000
#define SVNHTTPTYPE_FUNCTIONPOINT 20000
#define SVNHTTPTYPE_OFF_T         30000
#define	SVNHTTPTYPE_POINT		  40000
typedef enum 
{
	SVN_HTTPOPT_DNS_CACHE_TIMEOUT = SVNHTTPTYPE_LONG + 92,

	/* remember we want this enabled */
	SVN_HTTPOPT_DNS_USE_GLOBAL_CACHE = SVNHTTPTYPE_LONG + 91,

	 /* set a list of cipher we want to use in the SSL connection */
	SVN_HTTPOPT_SSL_CIPHER_LIST = SVNHTTPTYPE_OBJECTPOINT + 83,

	/*
	* This is the path name to a file that contains random data to seed
	* the random SSL stuff with. The file is only used for reading.
	*/
	SVN_HTTPOPT_RANDOM_FILE =SVNHTTPTYPE_OBJECTPOINT + 76,

	/*
	* The Entropy Gathering Daemon socket pathname
	*/
	SVN_HTTPOPT_EGDSOCKET =SVNHTTPTYPE_OBJECTPOINT + 77,

	/*
	* Set the absolute number of maximum simultaneous alive connection that
	* libcurl is allowed to have.
	*/
	SVN_HTTPOPT_MAXCONNECTS =SVNHTTPTYPE_LONG + 71,

	/*
	* When this transfer is done, it must not be left to be reused by a
	* subsequent transfer but shall be closed immediately.
	*/
	SVN_HTTPOPT_FORBID_REUSE =SVNHTTPTYPE_LONG + 75	,

	/*
	* This transfer shall not use a previously cached connection but
	* should be made with a fresh new connect!
	*/
	SVN_HTTPOPT_FRESH_CONNECT = SVNHTTPTYPE_LONG + 74,

	/*
	* Verbose means infof() calls that give a lot of information about
	* the connection and transfer procedures as well as internal choices.
	*/
	SVN_HTTPOPT_VERBOSE = SVNHTTPTYPE_LONG + 41,

	/*
	* Set to include the header in the general data output stream.
	*/
	SVN_HTTPOPT_HEADER = SVNHTTPTYPE_LONG + 42,

	/*
	* Shut off the internal supported progress meter
	*/
	SVN_HTTPOPT_NOPROGRESS = SVNHTTPTYPE_LONG + 43,

	/*
	* Do not include the body part in the output data stream.
	*/
	SVN_HTTPOPT_NOBODY = SVNHTTPTYPE_LONG + 44,

	/*
	* Don't output the >=300 error code HTML-page, but instead only
	* return error.
	*/
	SVN_HTTPOPT_FAILONERROR = SVNHTTPTYPE_LONG + 45,

	/*
	* We want to sent data to the remote host. If this is HTTP, that equals
	* using the PUT request.
	*/
	SVN_HTTPOPT_UPLOAD = SVNHTTPTYPE_LONG + 46,
	SVN_HTTPOPT_PUT = SVNHTTPTYPE_LONG + 54,

	/*
	* Try to get the file time of the remote document. The time will
	* later (possibly) become available using curl_easy_getinfo().
	*/
	SVN_HTTPOPT_FILETIME = SVNHTTPTYPE_LONG + 69,

	/*
	* An FTP option that modifies an upload to create missing directories on
	* the server.
	*/
	SVN_HTTPOPT_FTP_CREATE_MISSING_DIRS = SVNHTTPTYPE_LONG + 110,

	/*
	* Option that specifies how quickly an server response must be obtained
	* before it is considered failure. For pingpong protocols.
	*/
	SVN_HTTPOPT_SERVER_RESPONSE_TIMEOUT = SVNHTTPTYPE_LONG + 112,

	/*
	* TFTP option that specifies the block size to use for data transmission
	*/
	SVN_HTTPOPT_TFTP_BLKSIZE = SVNHTTPTYPE_LONG + 178,

	/*
	* An option that changes the command to one that asks for a list
	* only, no file info details.
	*/
	SVN_HTTPOPT_DIRLISTONLY = SVNHTTPTYPE_LONG + 48,

	/*
	* We want to upload and append to an existing file.
	*/
	SVN_HTTPOPT_APPEND = SVNHTTPTYPE_LONG + 50,

	/*
	* How do access files over FTP.
	*/
	SVN_HTTPOPT_FTP_FILEMETHOD = SVNHTTPTYPE_LONG + 138,

	/*
	* Parse the $HOME/.netrc file
	*/
	SVN_HTTPOPT_NETRC = SVNHTTPTYPE_LONG + 51,

	/*
	* Use this file instead of the $HOME/.netrc file
	*/
	SVN_HTTPOPT_NETRC_FILE =SVNHTTPTYPE_OBJECTPOINT + 118,

	/*
	* This option was previously named 'FTPASCII'. Renamed to work with
	* more protocols than merely FTP.
	*
	* Transfer using ASCII (instead of BINARY).
	*/
	SVN_HTTPOPT_TRANSFERTEXT = SVNHTTPTYPE_LONG + 53,
	
	/*
	* Set HTTP time condition. This must be one of the defines in the
	* curl/curl.h header file.
	*/
	SVN_HTTPOPT_TIMECONDITION = SVNHTTPTYPE_LONG + 33,

	/*
	* This is the value to compare with the remote document with the
	* method set with SVN_HTTPOPT_TIMECONDITION
	*/
	SVN_HTTPOPT_TIMEVALUE = SVNHTTPTYPE_LONG + 34,

	/*
	* Set explicit SSL version to try to connect with, as some SSL
	* implementations are lame.
	*/
	SVN_HTTPOPT_SSLVERSION = SVNHTTPTYPE_LONG + 32,

	/*
	* Switch on automatic referer that gets set if curl follows locations.
	*/
	SVN_HTTPOPT_AUTOREFERER = SVNHTTPTYPE_LONG + 58,

	/*
	* String to use at the value of Accept-Encoding header.
	*
	* If the encoding is set to "" we use an Accept-Encoding header that
	* encompasses all the encodings we support.
	* If the encoding is set to NULL we don't send an Accept-Encoding header
	* and ignore an received Content-Encoding header.
	*
	*/
	SVN_HTTPOPT_ACCEPT_ENCODING = SVNHTTPTYPE_OBJECTPOINT + 102,


	SVN_HTTPOPT_TRANSFER_ENCODING = SVNHTTPTYPE_LONG + 207,

	/*
	* Follow Location: header hints on a HTTP-server.
	*/
	SVN_HTTPOPT_FOLLOWLOCATION = SVNHTTPTYPE_LONG + 52,

	/*
	* Send authentication (user+password) when following locations, even when
	* hostname changed.
	*/
	SVN_HTTPOPT_UNRESTRICTED_AUTH = SVNHTTPTYPE_LONG + 105,

	/*
	* The maximum amount of hops you allow curl to follow Location:
	* headers. This should mostly be used to detect never-ending loops.
	*/
	SVN_HTTPOPT_MAXREDIRS = SVNHTTPTYPE_LONG + 68,

	/*
	* Set the behaviour of POST when redirecting
	* CURL_REDIR_GET_ALL - POST is changed to GET after 301 and 302
	* CURL_REDIR_POST_301 - POST is kept as POST after 301
	* CURL_REDIR_POST_302 - POST is kept as POST after 302
	* CURL_REDIR_POST_ALL - POST is kept as POST after 301 and 302
	* other - POST is kept as POST after 301 and 302
	*/
	SVN_HTTPOPT_POSTREDIR = SVNHTTPTYPE_LONG + 161,

	/* Does this option serve a purpose anymore? Yes it does, when
	SVN_HTTPOPT_POSTFIELDS isn't used and the POST data is read off the
	callback! */
	SVN_HTTPOPT_POST = SVNHTTPTYPE_LONG + 47,
	
	/*
	* A string with POST data. Makes curl HTTP POST. Even if it is NULL.
	* If needed, SVN_HTTPOPT_POSTFIELDSIZE must have been set prior to
	*  SVN_HTTPOPT_COPYPOSTFIELDS and not altered later.
	*/
	SVN_HTTPOPT_COPYPOSTFIELDS = SVNHTTPTYPE_OBJECTPOINT + 165,

	/*
	* Like above, but use static data instead of copying it.
	*/
	SVN_HTTPOPT_POSTFIELDS = SVNHTTPTYPE_OBJECTPOINT + 15,

	/*
	* The size of the POSTFIELD data to prevent libcurl to do strlen() to
	* figure it out. Enables binary posts.
	*/
	SVN_HTTPOPT_POSTFIELDSIZE = SVNHTTPTYPE_LONG + 60,
	
	/*
	* The size of the POSTFIELD data to prevent libcurl to do strlen() to
	* figure it out. Enables binary posts.
	*/
	SVN_HTTPOPT_POSTFIELDSIZE_LARGE = SVNHTTPTYPE_OFF_T + 120,


	/*
	* Set to make us do HTTP POST
	*/
	SVN_HTTPOPT_HTTPPOST = SVNHTTPTYPE_OBJECTPOINT + 24,

	/*
	* String to set in the HTTP Referer: field.
	*/
	SVN_HTTPOPT_REFERER = SVNHTTPTYPE_OBJECTPOINT + 16,

	/*
	* String to use in the HTTP User-Agent field
	*/
	SVN_HTTPOPT_USERAGENT = SVNHTTPTYPE_OBJECTPOINT + 18,

	/*
	* Set a list with HTTP headers to use (or replace internals with)
	*/
	SVN_HTTPOPT_HTTPHEADER = SVNHTTPTYPE_OBJECTPOINT + 23,

	/*
	* Set a list of aliases for HTTP 200 in response header
	*/
	SVN_HTTPOPT_HTTP200ALIASES = SVNHTTPTYPE_OBJECTPOINT + 104,

	/*
	* Cookie string to send to the remote server in the request.
	*/
	SVN_HTTPOPT_COOKIE = SVNHTTPTYPE_OBJECTPOINT + 22,

	/*
	* Set cookie file to read and parse. Can be used multiple times.
	*/
	SVN_HTTPOPT_COOKIEFILE = SVNHTTPTYPE_OBJECTPOINT + 31,

	/*
	* Set cookie file name to dump all cookies to when we're done.
	*/
	SVN_HTTPOPT_COOKIEJAR = SVNHTTPTYPE_OBJECTPOINT + 82,

	/*
	* Set this option to TRUE to start a new "cookie session". It will
	* prevent the forthcoming read-cookies-from-file actions to accept
	* cookies that are marked as being session cookies, as they belong to a
	* previous session.
	*
	* In the original Netscape cookie spec, "session cookies" are cookies
	* with no expire date set. RFC2109 describes the same action if no
	* 'Max-Age' is set and RFC2965 includes the RFC2109 description and adds
	* a 'Discard' action that can enforce the discard even for cookies that
	* have a Max-Age.
	*
	* We run mostly with the original cookie spec, as hardly anyone implements
	* anything else.
	*/
	SVN_HTTPOPT_COOKIESESSION = SVNHTTPTYPE_LONG + 96,

	SVN_HTTPOPT_COOKIELIST = SVNHTTPTYPE_OBJECTPOINT + 135,

	/*
	* Set to force us do HTTP GET
	*/
	SVN_HTTPOPT_HTTPGET = SVNHTTPTYPE_LONG + 80,

	/*
	* This sets a requested HTTP version to be used. The value is one of
	* the listed enums in curl/curl.h.
	*/
	SVN_HTTPOPT_HTTP_VERSION = SVNHTTPTYPE_LONG + 84,

	/*
	* Set HTTP Authentication type BITMASK.
	*/
	SVN_HTTPOPT_HTTPAUTH = SVNHTTPTYPE_LONG + 107,

	/*
	* Set a custom string to use as request
	*/
	SVN_HTTPOPT_CUSTOMREQUEST = SVNHTTPTYPE_OBJECTPOINT + 36,

	/*
	* Tunnel operations through the proxy instead of normal proxy use
	*/
	SVN_HTTPOPT_HTTPPROXYTUNNEL = SVNHTTPTYPE_LONG + 61,

	/*
	* Explicitly set HTTP proxy port number.
	*/
	SVN_HTTPOPT_PROXYPORT = SVNHTTPTYPE_LONG + 59,

	/*
	* Set HTTP Authentication type BITMASK.
	*/
	SVN_HTTPOPT_PROXYAUTH = SVNHTTPTYPE_LONG + 111,

	/*
	* Set proxy server:port to use as HTTP proxy.
	*
	* If the proxy is set to "" we explicitly say that we don't want to use a
	* proxy (even though there might be environment variables saying so).
	*
	* Setting it to NULL, means no proxy but allows the environment variables
	* to decide for us.
	*/
	SVN_HTTPOPT_PROXY = SVNHTTPTYPE_OBJECTPOINT + 4,

	/*
	* Set proxy type. HTTP/HTTP_1_0/SOCKS4/SOCKS4a/SOCKS5/SOCKS5_HOSTNAME
	*/
	SVN_HTTPOPT_PROXYTYPE = SVNHTTPTYPE_LONG + 101,

	/*
	* set transfer mode (;type=<a|i>) when doing FTP via an HTTP proxy
	*/
	SVN_HTTPOPT_PROXY_TRANSFER_MODE = SVNHTTPTYPE_LONG + 166,

	/*
	* Set gssapi service name
	*/
	SVN_HTTPOPT_SOCKS5_GSSAPI_SERVICE = SVNHTTPTYPE_OBJECTPOINT + 179,

	/*
	* set flag for nec socks5 support
	*/
	SVN_HTTPOPT_SOCKS5_GSSAPI_NEC = SVNHTTPTYPE_LONG + 180,

	/*
	* Custom pointer to pass the header write callback function
	*/
	SVN_HTTPOPT_WRITEHEADER = SVNHTTPTYPE_OBJECTPOINT + 29,

	/*
	* Error buffer provided by the caller to get the human readable
	* error string in.
	*/
	SVN_HTTPOPT_ERRORBUFFER = SVNHTTPTYPE_OBJECTPOINT + 10,

	/*
	* FILE pointer to write to or include in the data write callback
	*/
	SVN_HTTPOPT_FILE = SVNHTTPTYPE_OBJECTPOINT + 1,

	/*
	* Use FTP PORT, this also specifies which IP address to use
	*/
	SVN_HTTPOPT_FTPPORT = SVNHTTPTYPE_OBJECTPOINT + 17,


	SVN_HTTPOPT_FTP_USE_EPRT = SVNHTTPTYPE_LONG + 106,

	SVN_HTTPOPT_FTP_USE_EPSV = SVNHTTPTYPE_LONG + 85,

	SVN_HTTPOPT_FTP_USE_PRET = SVNHTTPTYPE_LONG + 188,

	SVN_HTTPOPT_FTP_SSL_CCC = SVNHTTPTYPE_LONG + 154,

	/*
	* Enable or disable FTP_SKIP_PASV_IP, which will disable/enable the
	* bypass of the IP address in PASV responses.
	*/
	SVN_HTTPOPT_FTP_SKIP_PASV_IP = SVNHTTPTYPE_LONG + 137,

	/*
	* FILE pointer to read the file to be uploaded from. Or possibly
	* used as argument to the read callback.
	*/
	SVN_HTTPOPT_INFILE = SVNHTTPTYPE_OBJECTPOINT + 9,
	
	/*
	* If known, this should inform curl about the file size of the
	* to-be-uploaded file.
	*/
	SVN_HTTPOPT_INFILESIZE = SVNHTTPTYPE_LONG + 14,

	/*
	* If known, this should inform curl about the file size of the
	* to-be-uploaded file.
	*/
	SVN_HTTPOPT_INFILESIZE_LARGE = SVNHTTPTYPE_OFF_T + 115,
	
	/*
	* The low speed limit that if transfers are below this for
	* SVN_HTTPOPT_LOW_SPEED_TIME, the transfer is aborted.
	*/
	SVN_HTTPOPT_LOW_SPEED_LIMIT = SVNHTTPTYPE_LONG + 19,

	/*
	* When transfer uploads are faster then SVN_HTTPOPT_MAX_SEND_SPEED_LARGE
	* bytes per second the transfer is throttled..
	*/
	SVN_HTTPOPT_MAX_SEND_SPEED_LARGE = SVNHTTPTYPE_OFF_T + 145,

	/*
	* When receiving data faster than SVN_HTTPOPT_MAX_RECV_SPEED_LARGE bytes per
	* second the transfer is throttled..
	*/
	SVN_HTTPOPT_MAX_RECV_SPEED_LARGE = SVNHTTPTYPE_OFF_T + 146,

	/*
	* The low speed time that if transfers are below the set
	* SVN_HTTPOPT_LOW_SPEED_LIMIT during this time, the transfer is aborted.
	*/
	SVN_HTTPOPT_LOW_SPEED_TIME = SVNHTTPTYPE_LONG + 20,

	/*
	* The URL to fetch.
	*/
	SVN_HTTPOPT_URL = SVNHTTPTYPE_OBJECTPOINT + 2,

	/*
	* The port number to use when getting the URL
	*/
	SVN_HTTPOPT_PORT = SVNHTTPTYPE_LONG + 3,

	/*
	* The maximum time you allow curl to use for a single transfer
	* operation.
	*/
	SVN_HTTPOPT_TIMEOUT = SVNHTTPTYPE_LONG + 13,
	

	SVN_HTTPOPT_TIMEOUT_MS = SVNHTTPTYPE_LONG + 155,

	/*
	* The maximum time you allow curl to use to connect.
	*/
	SVN_HTTPOPT_CONNECTTIMEOUT = SVNHTTPTYPE_LONG + 78,

	SVN_HTTPOPT_CONNECTTIMEOUT_MS = SVNHTTPTYPE_LONG + 156,

	/*
	* user:password to use in the operation
	*/
	SVN_HTTPOPT_USERPWD = SVNHTTPTYPE_OBJECTPOINT + 5,

	/*
	* authentication user name to use in the operation
	*/
	SVN_HTTPOPT_USERNAME = SVNHTTPTYPE_OBJECTPOINT + 173,

	/*
	* authentication password to use in the operation
	*/
	SVN_HTTPOPT_PASSWORD = SVNHTTPTYPE_OBJECTPOINT + 174,

	/*
	* List of RAW FTP commands to use after a transfer
	*/
	SVN_HTTPOPT_POSTQUOTE = SVNHTTPTYPE_OBJECTPOINT + 39,

	/*
	* List of RAW FTP commands to use prior to RETR (Wesley Laxton)
	*/
	SVN_HTTPOPT_PREQUOTE = SVNHTTPTYPE_OBJECTPOINT + 93,

	/*
	* List of RAW FTP commands to use before a transfer
	*/
	SVN_HTTPOPT_QUOTE = SVNHTTPTYPE_OBJECTPOINT + 28,

	/*
	* List of NAME:[address] names to populate the DNS cache with
	* Prefix the NAME with dash (-) to _remove_ the name from the cache.
	*
	* Names added with this API will remain in the cache until explicitly
	* removed or the handle is cleaned up.
	*
	* This API can remove any name from the DNS cache, but only entries
	* that aren't actually in use right now will be pruned immediately.
	*/
	SVN_HTTPOPT_RESOLVE = SVNHTTPTYPE_OBJECTPOINT + 203,

	/*
	* Progress callback function
	*/
	SVN_HTTPOPT_PROGRESSFUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 56,

	/*
	* Custom client data to pass to the progress callback
	*/
	SVN_HTTPOPT_PROGRESSDATA = SVNHTTPTYPE_OBJECTPOINT + 57,

	/*
	* user:password needed to use the proxy
	*/
	SVN_HTTPOPT_PROXYUSERPWD = SVNHTTPTYPE_OBJECTPOINT + 6,

	/*
	* authentication user name to use in the operation
	*/
	SVN_HTTPOPT_PROXYUSERNAME = SVNHTTPTYPE_OBJECTPOINT + 175,

	/*
	* authentication password to use in the operation
	*/
	SVN_HTTPOPT_PROXYPASSWORD = SVNHTTPTYPE_OBJECTPOINT + 176,

	/*
	* proxy exception list
	*/
	SVN_HTTPOPT_NOPROXY= SVNHTTPTYPE_OBJECTPOINT + 177,

	/*
	* What range of the file you want to transfer
	*/
	SVN_HTTPOPT_RANGE = SVNHTTPTYPE_OBJECTPOINT + 7,

	/*
	* Resume transfer at the give file position
	*/
	SVN_HTTPOPT_RESUME_FROM = SVNHTTPTYPE_LONG + 21,

	/*
	* Resume transfer at the give file position
	*/
	SVN_HTTPOPT_RESUME_FROM_LARGE = SVNHTTPTYPE_OFF_T + 116,

	/*
	* stderr write callback.
	*/
	SVN_HTTPOPT_DEBUGFUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 94,

	/*
	* Set to a void * that should receive all error writes. This
	* defaults to SVN_HTTPOPT_STDERR for normal operations.
	*/
	SVN_HTTPOPT_DEBUGDATA = SVNHTTPTYPE_OBJECTPOINT + 95,

	/*
	* Set to a FILE * that should receive all error writes. This
	* defaults to stderr for normal operations.
	*/
	SVN_HTTPOPT_STDERR = SVNHTTPTYPE_OBJECTPOINT + 37,

	/*
	* Set header write callback
	*/
	SVN_HTTPOPT_HEADERFUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 79,

	/*
	* Set data write callback
	*/
	SVN_HTTPOPT_WRITEFUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 11,

	/*
	* Read data callback
	*/
	SVN_HTTPOPT_READFUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 12,
	
	/*
	* Seek callback. Might be NULL.
	*/
	SVN_HTTPOPT_SEEKFUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 167,

	/*
	* Seek control callback. Might be NULL.
	*/
	SVN_HTTPOPT_SEEKDATA = SVNHTTPTYPE_OBJECTPOINT + 168,

	/*
	* "Convert from network encoding" callback
	*/
	SVN_HTTPOPT_CONV_FROM_NETWORK_FUNCTION		= SVNHTTPTYPE_FUNCTIONPOINT + 142,

	/*
	* "Convert to network encoding" callback
	*/
	SVN_HTTPOPT_CONV_TO_NETWORK_FUNCTION		= SVNHTTPTYPE_FUNCTIONPOINT + 143,

	/*
	* "Convert from UTF-8 encoding" callback
	*/
	SVN_HTTPOPT_CONV_FROM_UTF8_FUNCTION			= SVNHTTPTYPE_FUNCTIONPOINT + 144,

	/*
	* I/O control callback. Might be NULL.
	*/
	SVN_HTTPOPT_IOCTLFUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 130,

	/*
	* I/O control data pointer. Might be NULL.
	*/
	SVN_HTTPOPT_IOCTLDATA = SVNHTTPTYPE_OBJECTPOINT + 131,

	/*
	* String that holds file name of the SSL certificate to use
	*/
	SVN_HTTPOPT_SSLCERT = SVNHTTPTYPE_OBJECTPOINT + 25,

	/*
	* String that holds file type of the SSL certificate to use
	*/
	SVN_HTTPOPT_SSLCERTTYPE = SVNHTTPTYPE_OBJECTPOINT + 86,

	/*
	* String that holds file name of the SSL key to use
	*/
	SVN_HTTPOPT_SSLKEY = SVNHTTPTYPE_OBJECTPOINT + 87,

	/*
	* String that holds file type of the SSL key to use
	*/
	SVN_HTTPOPT_SSLKEYTYPE = SVNHTTPTYPE_OBJECTPOINT + 88,

	/*
	* String that holds the SSL or SSH private key password.
	*/
	SVN_HTTPOPT_KEYPASSWD = SVNHTTPTYPE_OBJECTPOINT + 26,

	/*
	* String that holds the SSL crypto engine.
	*/
	SVN_HTTPOPT_SSLENGINE = SVNHTTPTYPE_OBJECTPOINT + 89,

	/*
	* flag to set engine as default.
	*/
	SVN_HTTPOPT_SSLENGINE_DEFAULT = SVNHTTPTYPE_LONG + 90,

	/*
	* Kludgy option to enable CRLF conversions. Subject for removal.
	*/
	SVN_HTTPOPT_CRLF = SVNHTTPTYPE_LONG + 27,

	/*
	* Set what interface or address/hostname to bind the socket to when
	* performing an operation and thus what from-IP your connection will use.
	*/
	SVN_HTTPOPT_INTERFACE = SVNHTTPTYPE_OBJECTPOINT + 62,

	/*
	* Set what local port to bind the socket to when performing an operation.
	*/
	SVN_HTTPOPT_LOCALPORT = SVNHTTPTYPE_LONG + 139,

	/*
	* Set number of local ports to try, starting with SVN_HTTPOPT_LOCALPORT.
	*/
	SVN_HTTPOPT_LOCALPORTRANGE = SVNHTTPTYPE_LONG + 140,

	/*
	* A string that defines the kerberos security level.
	*/
	SVN_HTTPOPT_KRBLEVEL = SVNHTTPTYPE_OBJECTPOINT + 63,

	/*
	* Enable peer SSL verifying.
	*/
	SVN_HTTPOPT_SSL_VERIFYPEER = SVNHTTPTYPE_LONG + 64,

	/*
	* Enable verification of the CN contained in the peer certificate
	*/
	SVN_HTTPOPT_SSL_VERIFYHOST = SVNHTTPTYPE_LONG + 81,

	/* since these two options are only possible to use on an OpenSSL-
	powered libcurl we #ifdef them on this condition so that libcurls
	built against other SSL libs will return a proper error when trying
	to set this option! */
	/*
	* Set a SSL_CTX callback
	*/
	SVN_HTTPOPT_SSL_CTX_FUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 108,

	/*
	* Set a SSL_CTX callback parameter pointer
	*/
	SVN_HTTPOPT_SSL_CTX_DATA = SVNHTTPTYPE_OBJECTPOINT + 109,

	SVN_HTTPOPT_CERTINFO = SVNHTTPTYPE_LONG + 172,

	/*
	* Set CA info for SSL connection. Specify file name of the CA certificate
	*/
	SVN_HTTPOPT_CAINFO = SVNHTTPTYPE_OBJECTPOINT + 65,

	/*
	* Set CA path info for SSL connection. Specify directory name of the CA
	* certificates which have been prepared using openssl c_rehash utility.
	*/
	/* This does not work on windows. */
	SVN_HTTPOPT_CAPATH = SVNHTTPTYPE_OBJECTPOINT + 97,

	/*
	* Set CRL file info for SSL connection. Specify file name of the CRL
	* to check certificates revocation
	*/
	SVN_HTTPOPT_CRLFILE = SVNHTTPTYPE_OBJECTPOINT + 169,

	/*
	* Set Issuer certificate file
	* to check certificates issuer
	*/
	SVN_HTTPOPT_ISSUERCERT = SVNHTTPTYPE_OBJECTPOINT + 170,

	/*
	* Set a linked list of telnet options
	*/
	SVN_HTTPOPT_TELNETOPTIONS = SVNHTTPTYPE_OBJECTPOINT + 70,

	/*
	* The application kindly asks for a differently sized receive buffer.
	* If it seems reasonable, we'll use it.
	*/
	SVN_HTTPOPT_BUFFERSIZE = SVNHTTPTYPE_LONG + 98,

	/*
	* Set the maximum size of a file to download.
	*/
	SVN_HTTPOPT_MAXFILESIZE = SVNHTTPTYPE_LONG + 114,


	/*
	* Make transfers attempt to use SSL/TLS.
	*/
	SVN_HTTPOPT_USE_SSL = SVNHTTPTYPE_LONG + 119,

	/*
	* Set a specific auth for FTP-SSL transfers.
	*/
	SVN_HTTPOPT_FTPSSLAUTH = SVNHTTPTYPE_LONG + 129,


	SVN_HTTPOPT_IPRESOLVE = SVNHTTPTYPE_LONG + 113,

	/*
	* Set the maximum size of a file to download.
	*/
	SVN_HTTPOPT_MAXFILESIZE_LARGE = SVNHTTPTYPE_OFF_T + 117,

	/*
	* Enable or disable TCP_NODELAY, which will disable/enable the Nagle
	* algorithm
	*/
	SVN_HTTPOPT_TCP_NODELAY = SVNHTTPTYPE_LONG + 121,


	SVN_HTTPOPT_FTP_ACCOUNT = SVNHTTPTYPE_OBJECTPOINT + 134,

	SVN_HTTPOPT_IGNORE_CONTENT_LENGTH = SVNHTTPTYPE_LONG + 136,

	/*
	* No data transfer, set up connection and let application use the socket
	*/
	SVN_HTTPOPT_CONNECT_ONLY = SVNHTTPTYPE_LONG + 141,


	SVN_HTTPOPT_FTP_ALTERNATIVE_TO_USER = SVNHTTPTYPE_OBJECTPOINT + 147,

	/*
	* socket callback function: called after socket() but before connect()
	*/
	SVN_HTTPOPT_SOCKOPTFUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 148,

	/*
	* socket callback data pointer. Might be NULL.
	*/
	SVN_HTTPOPT_SOCKOPTDATA = SVNHTTPTYPE_OBJECTPOINT + 149,

	/*
	* open/create socket callback function: called instead of socket(),
	* before connect()
	*/
	SVN_HTTPOPT_OPENSOCKETFUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 163,

	/*
	* socket callback data pointer. Might be NULL.
	*/
	SVN_HTTPOPT_OPENSOCKETDATA = SVNHTTPTYPE_OBJECTPOINT + 164,

	/*
	* close socket callback function: called instead of close()
	* when shutting down a connection
	*/
	SVN_HTTPOPT_CLOSESOCKETFUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 208,

	/*
	* socket callback data pointer. Might be NULL.
	*/
	SVN_HTTPOPT_CLOSESOCKETDATA = SVNHTTPTYPE_OBJECTPOINT + 209,


	SVN_HTTPOPT_SSL_SESSIONID_CACHE = SVNHTTPTYPE_LONG + 150,


	SVN_HTTPOPT_SSH_AUTH_TYPES = SVNHTTPTYPE_LONG + 151,

	/*
	* Use this file instead of the $HOME/.ssh/id_dsa.pub file
	*/
	SVN_HTTPOPT_SSH_PUBLIC_KEYFILE = SVNHTTPTYPE_OBJECTPOINT + 152,

	/*
	* Use this file instead of the $HOME/.ssh/id_dsa file
	*/
	SVN_HTTPOPT_SSH_PRIVATE_KEYFILE = SVNHTTPTYPE_OBJECTPOINT + 153,

	/*
	* Option to allow for the MD5 of the host public key to be checked
	* for validation purposes.
	*/
	SVN_HTTPOPT_SSH_HOST_PUBLIC_KEY_MD5 = SVNHTTPTYPE_OBJECTPOINT + 162,

	/*
	* Store the file name to read known hosts from.
	*/
	SVN_HTTPOPT_SSH_KNOWNHOSTS = SVNHTTPTYPE_OBJECTPOINT + 183,

	/* setting to NULL is fine since the ssh.c functions themselves will
	then rever to use the internal default */
	SVN_HTTPOPT_SSH_KEYFUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 184,

	/*
	* Custom client data to pass to the SSH keyfunc callback
	*/
	SVN_HTTPOPT_SSH_KEYDATA = SVNHTTPTYPE_OBJECTPOINT + 185,

	/*
	* disable libcurl transfer encoding is used
	*/
	SVN_HTTPOPT_HTTP_TRANSFER_DECODING = SVNHTTPTYPE_LONG + 157,

	/*
	* raw data passed to the application when content encoding is used
	*/
	SVN_HTTPOPT_HTTP_CONTENT_DECODING = SVNHTTPTYPE_LONG + 158,

	/*
	* Uses these permissions instead of 0644
	*/
	SVN_HTTPOPT_NEW_FILE_PERMS = SVNHTTPTYPE_LONG + 159,

	/*
	* Uses these permissions instead of 0755
	*/
	SVN_HTTPOPT_NEW_DIRECTORY_PERMS = SVNHTTPTYPE_LONG + 160,

	/*
	* We always get longs when passed plain numericals, but for this value we
	* know that an unsigned int will always hold the value so we blindly
	* typecast to this type
	*/
	SVN_HTTPOPT_ADDRESS_SCOPE = SVNHTTPTYPE_LONG + 171,

	/* set the bitmask for the protocols that are allowed to be used for the
	transfer, which thus helps the app which takes URLs from users or other
	external inputs and want to restrict what protocol(s) to deal
	with. Defaults to SVNPROTO_ALL. */
	SVN_HTTPOPT_PROTOCOLS = SVNHTTPTYPE_LONG + 181,

	/* set the bitmask for the protocols that libcurl is allowed to follow to,
	as a subset of the SVN_HTTPOPT_PROTOCOLS ones. That means the protocol needs
	to be set in both bitmasks to be allowed to get redirected to. Defaults
	to all protocols except FILE and SCP. */
	SVN_HTTPOPT_REDIR_PROTOCOLS = SVNHTTPTYPE_LONG + 182,


	SVN_HTTPOPT_MAIL_FROM = SVNHTTPTYPE_OBJECTPOINT + 186,

	/* get a list of mail recipients */
	SVN_HTTPOPT_MAIL_RCPT = SVNHTTPTYPE_OBJECTPOINT + 187,

	/*
	* Set the RTSP request method (OPTIONS, SETUP, PLAY, etc...)
	* Would this be better if the RTSPREQ_* were just moved into here?
	*/
	SVN_HTTPOPT_RTSP_REQUEST = SVNHTTPTYPE_LONG + 189,//=============================================;


	/*
	* Set the RTSP Session ID manually. Useful if the application is
	* resuming a previously established RTSP session
	*/
	SVN_HTTPOPT_RTSP_SESSION_ID = SVNHTTPTYPE_OBJECTPOINT + 190,

	/*
	* Set the Stream URI for the RTSP request. Unless the request is
	* for generic server options, the application will need to set this.
	*/
	SVN_HTTPOPT_RTSP_STREAM_URI = SVNHTTPTYPE_OBJECTPOINT + 191,

	/*
	* The content of the Transport: header for the RTSP request
	*/
	SVN_HTTPOPT_RTSP_TRANSPORT = SVNHTTPTYPE_OBJECTPOINT + 192,

	/*
	* Set the CSEQ number to issue for the next RTSP request. Useful if the
	* application is resuming a previously broken connection. The CSEQ
	* will increment from this new number henceforth.
	*/
	SVN_HTTPOPT_RTSP_CLIENT_CSEQ = SVNHTTPTYPE_LONG + 193,


	/* Same as the above, but for server-initiated requests */
	SVN_HTTPOPT_RTSP_SERVER_CSEQ = SVNHTTPTYPE_LONG + 194,


	SVN_HTTPOPT_INTERLEAVEDATA = SVNHTTPTYPE_OBJECTPOINT + 195,

	/* Set the user defined RTP write function */
	SVN_HTTPOPT_INTERLEAVEFUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 196,


	SVN_HTTPOPT_WILDCARDMATCH = SVNHTTPTYPE_LONG + 197,

	SVN_HTTPOPT_CHUNK_BGN_FUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 198,


	SVN_HTTPOPT_CHUNK_END_FUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 199,


	SVN_HTTPOPT_FNMATCH_FUNCTION = SVNHTTPTYPE_FUNCTIONPOINT + 200,

	SVN_HTTPOPT_CHUNK_DATA = SVNHTTPTYPE_OBJECTPOINT + 201,


	SVN_HTTPOPT_FNMATCH_DATA = SVNHTTPTYPE_OBJECTPOINT + 202,


	SVN_HTTPOPT_TLSAUTH_USERNAME = SVNHTTPTYPE_OBJECTPOINT + 204,


	SVN_HTTPOPT_TLSAUTH_PASSWORD = SVNHTTPTYPE_OBJECTPOINT + 205,


	SVN_HTTPOPT_TLSAUTH_TYPE = SVNHTTPTYPE_OBJECTPOINT + 206,

	SVN_HTTPOPT_DNS_SERVERS = SVNHTTPTYPE_OBJECTPOINT + 211,

	/*	多媒体隧道控制选项  */
	SVN_HTTPOPT_MTM = SVNHTTPTYPE_POINT + 1,	

	/*Add by yangjiemiao yKF70953 2012-08-23 增加options操作*/
	SVN_HTTPOPT_OPTIONS = SVNHTTPTYPE_POINT + 2,

    /* BEGIN: Added for PN:TCP over UDP 整改 by y90004712, 2013/8/16 */
    SVN_HTTPOPT_TUNNEL_TYPE = SVNHTTPTYPE_POINT + 3,
    /* END:   Added for PN:TCP over UDP 整改 by y90004712, 2013/8/16 */

    /* BEGIN: Added for PN:增加http交互取消机制 by y90004712, 2013/11/1 */
    SVN_HTTPOPT_CANCEL_CALLBACK = SVNHTTPTYPE_POINT + 4,
    SVN_HTTPOPT_CANCEL_DATA = SVNHTTPTYPE_POINT + 5,
    /* END:   Added for PN:增加http交互取消机制 by y90004712, 2013/11/1 */

}SVN_HTTPOPT;

#define SVNINFO_STRING	0x100000
#define SVNINFO_LONG	0x200000
#define SVNINFO_DOUBLE	0x300000
#define SVNINFO_SLIST   0x400000
typedef enum  
{
	SVN_HTTPINFO_NONE, /* first, never use this */
	SVN_HTTPINFO_EFFECTIVE_URL				= SVNINFO_STRING + 1,
	SVN_HTTPINFO_RESPONSE_CODE				= SVNINFO_LONG   + 2,
	SVN_HTTPINFO_TOTAL_TIME					= SVNINFO_DOUBLE + 3,
	SVN_HTTPINFO_NAMELOOKUP_TIME			= SVNINFO_DOUBLE + 4,
	SVN_HTTPINFO_CONNECT_TIME				= SVNINFO_DOUBLE + 5,
	SVN_HTTPINFO_PRETRANSFER_TIME			= SVNINFO_DOUBLE + 6,
	SVN_HTTPINFO_SIZE_UPLOAD				= SVNINFO_DOUBLE + 7,
	SVN_HTTPINFO_SIZE_DOWNLOAD				= SVNINFO_DOUBLE + 8,
	SVN_HTTPINFO_SPEED_DOWNLOAD				= SVNINFO_DOUBLE + 9,
	SVN_HTTPINFO_SPEED_UPLOAD				= SVNINFO_DOUBLE + 10,
	SVN_HTTPINFO_HEADER_SIZE				= SVNINFO_LONG   + 11,
	SVN_HTTPINFO_REQUEST_SIZE				= SVNINFO_LONG   + 12,
	SVN_HTTPINFO_SSL_VERIFYRESULT			= SVNINFO_LONG   + 13,
	SVN_HTTPINFO_FILETIME					= SVNINFO_LONG   + 14,
	SVN_HTTPINFO_CONTENT_LENGTH_DOWNLOAD	= SVNINFO_DOUBLE + 15,
	SVN_HTTPINFO_CONTENT_LENGTH_UPLOAD		= SVNINFO_DOUBLE + 16,
	SVN_HTTPINFO_STARTTRANSFER_TIME			= SVNINFO_DOUBLE + 17,
	SVN_HTTPINFO_CONTENT_TYPE				= SVNINFO_STRING + 18,
	SVN_HTTPINFO_REDIRECT_TIME				= SVNINFO_DOUBLE + 19,
	SVN_HTTPINFO_REDIRECT_COUNT				= SVNINFO_LONG   + 20,
	SVN_HTTPINFO_PRIVATE					       = SVNINFO_STRING + 21,
	SVN_HTTPINFO_HTTP_CONNECTCODE			= SVNINFO_LONG   + 22,
	SVN_HTTPINFO_HTTPAUTH_AVAIL				= SVNINFO_LONG   + 23,
	SVN_HTTPINFO_PROXYAUTH_AVAIL			= SVNINFO_LONG   + 24,
	SVN_HTTPINFO_OS_ERRNO					= SVNINFO_LONG   + 25,
	SVN_HTTPINFO_NUM_CONNECTS				= SVNINFO_LONG   + 26,
	SVN_HTTPINFO_SSL_ENGINES				       = SVNINFO_SLIST  + 27,
	SVN_HTTPINFO_COOKIELIST					= SVNINFO_SLIST  + 28,
	SVN_HTTPINFO_LASTSOCKET					= SVNINFO_LONG   + 29,
	SVN_HTTPINFO_FTP_ENTRY_PATH				= SVNINFO_STRING + 30,
	SVN_HTTPINFO_REDIRECT_URL				= SVNINFO_STRING + 31,
	SVN_HTTPINFO_PRIMARY_IP					= SVNINFO_STRING + 32,
	SVN_HTTPINFO_APPCONNECT_TIME			= SVNINFO_DOUBLE + 33,
	SVN_HTTPINFO_CERTINFO					= SVNINFO_SLIST  + 34,
	SVN_HTTPINFO_CONDITION_UNMET			= SVNINFO_LONG   + 35,
	SVN_HTTPINFO_RTSP_SESSION_ID			= SVNINFO_STRING + 36,
	SVN_HTTPINFO_RTSP_CLIENT_CSEQ			= SVNINFO_LONG   + 37,
	SVN_HTTPINFO_RTSP_SERVER_CSEQ			= SVNINFO_LONG   + 38,
	SVN_HTTPINFO_RTSP_CSEQ_RECV				= SVNINFO_LONG   + 39,
	SVN_HTTPINFO_PRIMARY_PORT				= SVNINFO_LONG   + 40,
	SVN_HTTPINFO_LOCAL_IP					= SVNINFO_STRING + 41,
	SVN_HTTPINFO_LOCAL_PORT					= SVNINFO_LONG   + 42,

	SVN_HTTPINFO_LASTONE					= 42

}SVN_HTTPINFO;

#define MDMSDKLOG_LogE(...) WriteLog(DIAGNOSE_ERR_LOG_INFO_ID, SYS_ERR_LOG, __FUNCTION__, __LINE__,  __VA_ARGS__)
#define MDMSDKLOG_LogW(...) WriteLog(DIAGNOSE_ERR_LOG_INFO_ID, SYS_WARN_LOG, __FUNCTION__, __LINE__,  __VA_ARGS__)
#define MDMSDK_CHECKASSETBIND_PAGE "anyofficecheckassetbind.html?UserID=%d&SessionID=%d&DeviceID=%s&language=%s&OS=%s&PackageName=%s&DummyDeviceID=%s&UUID=%s&ClientVersion=%s&"
#define MDMSDK_KICKOFF_RES     "kickedoff"
#define MDMSDK_CHE_RES        "requestcheckresult"
#define MDMSDK_SVN_URL         "https://%s:%d/%s"

/* BEGIN:   Added for PN:DTS2014041602406 by LiJingjin 90004727, 2014/4/16 */
#define MDMSDK_GETVIOLATIONINFO_PAGE "mdm/%d/%d/Mdm/getViolationInfoByDeviceId.html?deviceId=%s"
/* END:   Added for PN:DTS2014041602406 by LiJingjin 90004727, 2014/4/16 */

#define MDMSDK_MALLOC(info,length) malloc(length)
#define MDMSDK_REMALLOC(pOldMemPtr,ulNewSize) realloc(pOldMemPtr,ulNewSize)
#define MDMSDK_SAFE_FREE(data) \
    if(data) \
    {\
        free(data);\
        (data) = NULL; \
    }

typedef struct tagHiworkUserInfo
{
    ULONG ulUserID;                                                             /*SVN网关返回的用户ID*/
    ULONG ulSessionID;                                                        /*SVN网关返回的Session ID*/  
    UCHAR aucDeviceID[MDMSDK_MAX_DEV_ID_LEN];           /*DeviceID*/   

}HIWORK_USER_INFO_S;

/*HTTP响应消息体结构体*/
typedef struct tagHttpRespBuf 
{
    char *pszBuf;       /*消息体内容*/
    size_t size;        /*消息体大小*/
}HTTP_RESP_BUF_S;

/*HTTP响应结构体*/
typedef struct tagHttpResponse
{
    LONG lHttpRes;
    /* END:   Added by panbinxian, 2013/10/21 */
    long lResponseCode;             /*响应码*/
    struct http_slist *pstCookies;  /*响应cookie*/
    HTTP_RESP_BUF_S stResponseBuf;  /*消息体*/
}HTTP_RESPONSE_S;

#endif
