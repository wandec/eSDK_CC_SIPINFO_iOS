//
//  ECSNotificationCenter.m
//  VTMSDK
//
//  Created by gaoshuming on 15/10/20.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import "ECSNotificationCenter.h"
#import "Log.h"

@implementation ECSNotificationCenter

+ (void)postNotification:(NSNotification *)notification
{
    if (notification == nil)
    {
        //		SDK_ERROR_LOG("notification is nil");
        logErr(@"notification is nil");
        return;
    }
    if ([notification name] == nil)
    {
        logErr(@"notification name is nil");
        return;
    }
    logDbg(@"%s",[[notification name] UTF8String]);
    [[NSNotificationCenter defaultCenter] postNotification:notification];
}

+ (void)postNotificationName:(NSString *)aName object:(id)anObject
{
    if (aName == nil)
    {
        logErr(@"notification name is nil");
        return;
    }
    logDbg(@"%s",[aName UTF8String]);
    [[NSNotificationCenter defaultCenter] postNotificationName:aName object:anObject];
}

+ (void)postNotificationName:(NSString *)aName object:(id)anObject userInfo:(NSDictionary *)aUserInfo
{
    if (aName == nil)
    {
        logErr(@"notification name is nil");
        return;
    }
    logDbg(@"%s",[aName UTF8String]);
    [[NSNotificationCenter defaultCenter] postNotificationName:aName object:anObject userInfo:aUserInfo];
}

+ (void)postNotificationName:(NSString *)aName object:(id)anObject withUserObject:(id)userObject forKey:(NSString *)userKey {
    if (aName == nil)
    {
        logErr(@"notification name is nil");
        return;
    }
    logDbg(@"%s",[aName UTF8String]);
    
    NSDictionary * aUserInfo = nil;
    if (nil != userObject && 0 != [userKey length]) {
        aUserInfo = [NSDictionary dictionaryWithObject:userObject forKey:userKey];
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:aName object:anObject userInfo:aUserInfo];
}

+ (void)postNotificationName:(NSString *)aName object:(id)anObject withUserObject:(id)userObject forKey:(NSString *)userKey withUserObject2:(id)userObject2 forKey2:(NSString *)userKey2 {
    if (aName == nil)
    {
        logErr(@"notification name is nil");
        return;
    }
    logDbg(@"%s",[aName UTF8String]);
    
    NSDictionary * aUserInfo = nil;
    if (nil != userObject && 0 != [userKey length] && nil != userObject2 && 0 != [userKey2 length]) {
        aUserInfo = [NSDictionary dictionaryWithObjectsAndKeys:userObject, userKey, userObject2, userKey2, nil];
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:aName object:anObject userInfo:aUserInfo];
}

@end
