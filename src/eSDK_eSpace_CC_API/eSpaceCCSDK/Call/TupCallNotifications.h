//
//  TupCallNotifications.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/13.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "call_advanced_def.h"
#import "call_advanced_interface.h"
#import "call_def.h"
#import "call_interface.h"

@class TupCallNotifications;

@protocol TupCallNotificationsHandler <NSObject>

- (void)onRecvNotification:(TupCallNotifications *)notification;


@end

@interface TupCallNotifications : NSObject

@property (nonatomic, assign) CALL_E_CALL_EVENT msgId;
@property (nonatomic, assign) TUP_UINT32 param1;
@property (nonatomic, assign) TUP_UINT32 param2;
@property (nonatomic, assign) void* data;

+ (void)setHandler:(id<TupCallNotificationsHandler>)handler;
+ (void)resetHandler;

@end

TUP_VOID onTupCallNotifications(TUP_UINT32 msgid, TUP_UINT32 param1, TUP_UINT32 param2, void *data);