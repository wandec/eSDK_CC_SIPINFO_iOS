//
//  AnonymousCall.m
//  VTMSDK
//
//  Created by gaoshuming on 15/10/13.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import "AnonymousCall.h"
#import "AccountInfo.h"
#import "Log.h"
#import "VTMNotificationsDefine.h"


//NSString *const CALL_NUMBER = @"2001";
//NSString *const SERVERIP = @"172.22.8.69";
//NSString *const PORT = @"5060";

NSString * const VTM_RETURN_CODE = @"retcode";
NSString * const VTM_RETURNCODE_SUCCESS  = @"0000";
NSString * const VTM_RETCODE_NETWORK_ERROR = @"-1";
NSString * const VTM_RETCODE_HTTP_ERROR = @"-2";

/******************************* 匿名呼叫 ***************************/

const NSTimeInterval IAS_CALL_INFO_QUERY_INTER = 1.0f;//发起匿名呼叫请求后,如果获取到了sessionid,之后就开始做呼叫排队状态获取.这个时候为了网络性能考虑,1s轮询一次.

static AnonymousCall *anonymousCall = nil;

@interface AnonymousCall ()

@end

@implementation AnonymousCall

+(AnonymousCall *)sharedInstance
{
    @synchronized(self) {
        if (anonymousCall == nil) {
            anonymousCall = [[AnonymousCall alloc]init];
        }
    }
    return anonymousCall;
}

+ (void)destroyInstance
{
    @synchronized(self)
    {
        if (anonymousCall)
        {
            anonymousCall = nil;
        }
    }
}

-(instancetype)init
{
    self = [super init];
    if (self) {
        _callService = [ECSCallService sharedInstance];
    }
    return self;
}

+ (id)allocWithZone:(struct _NSZone *)zone
{
    @synchronized(self)
    {
        if (nil == anonymousCall)
        {
            anonymousCall = [super allocWithZone:zone];
        }
    }
    return anonymousCall;
}


-(BOOL)isInCall:(NSString *)accessCode
{
    [self.callService makeInitConfigure];
    
    [[ECSCallService sharedInstance] isCallServiceIdle];
    
    BOOL isMakeCallOK = [self.callService startCall:accessCode];
    
    if (!isMakeCallOK)
    {
        NSLog(@"停止呼叫");
    }
    return YES;
}

-(BOOL)closeCall
{
    NSAssert( nil != self.callService, @"call service not init.");
    BOOL isSuccess = NO;
    isSuccess = [self.callService closeCall];
    return isSuccess;
}

@end
