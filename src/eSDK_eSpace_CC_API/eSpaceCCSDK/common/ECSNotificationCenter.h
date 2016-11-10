//
//  ECSNotificationCenter.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/20.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ECSNotificationCenter : NSObject

+ (void)postNotification:(NSNotification *)notification;
+ (void)postNotificationName:(NSString *)aName object:(id)anObject;
+ (void)postNotificationName:(NSString *)aName object:(id)anObject userInfo:(NSDictionary *)aUserInfo;
+ (void)postNotificationName:(NSString *)aName object:(id)anObject withUserObject:(id)userObject forKey:(NSString *)userKey;
+ (void)postNotificationName:(NSString *)aName object:(id)anObject withUserObject:(id)userObject forKey:(NSString *)userKey withUserObject2:(id)userObject2 forKey2:(NSString *)userKey2;

@end
