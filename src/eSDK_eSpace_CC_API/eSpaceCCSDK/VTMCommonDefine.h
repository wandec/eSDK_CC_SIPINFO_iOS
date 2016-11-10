//
//  VTMCommonDefine.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/14.
//  Copyright © 2015年 wangchan. All rights reserved.
//


//VTM登陆状态(针对登陆时候有意义,做匿名呼叫时候,不涉及登陆状态)
typedef NS_ENUM(NSUInteger, LOGIN_STATUS)
{
    STATUS_NOT_LOGIN,//未登陆
    STATUS_LOGIN,//已登陆
    STATUS_ERROR//登陆状态错误，可能原因是登陆失败或者心跳失败
};

//呼叫模式
typedef NS_ENUM(NSUInteger, CALL_MODE)
{
    UNKNOWN_MODE,//未知的呼叫模式
    COMMON_MODE,//普通模式,即登陆后发起呼叫
    ANONYMOUS_MODE//匿名呼叫模式
};

//日志级别
typedef NS_ENUM(NSInteger, LOG_LEVEL)
{
    LOG_ERROR   = 0,		//错误级别
    LOG_WARNING = 1,		//警告级别
    LOG_INFO    = 2,		//一般级别
    LOG_DEBUG   = 3			//调试级别
};

typedef NS_ENUM(NSInteger, VTM_METHOD_RETCODE)
{
    RET_OK = 0,//方法调用成功
    RET_COMMON_EEROR = 2,//一般错误
    RET_NOT_LOGIN = 6,//未登陆
    RET_ALREADY_LOGIN = 8,//已登陆
    RET_PARAM_ERROR = 9,//参数错误
    RET_STATUS_ERROR = 11,//当前状态错误
    RET_NO_CALL_RELEASE = 18,//当前没有可释放的呼叫
    RET_NOT_SUPPORT = 27,//不支持
    RET_NO_PERMISION = 28,//没有权限
    RET_UNKNONW_ERROR = 499 //未知错误
};

