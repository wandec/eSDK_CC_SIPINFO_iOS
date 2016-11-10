//
//  SubNotifyResult.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/20.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SubNotifyResult : NSObject
{
    NSString*  subscriptionState;
    NSString*  statusCode;
}

@property(nonatomic, copy)  NSString*  subscriptionState;
@property(nonatomic, copy)  NSString*  statusCode;

- (BOOL)isDataValid;

- (BOOL)isResultTrying;

- (BOOL)isResultSuccess;


@end

/* Report multi-conf invite to service manager */
@interface ConfInviteInfo : NSObject
{
    NSString*    callerNum;
    NSString*    confId;
    NSString*    confType;
}

@property(nonatomic, retain)  NSString*  callerNum;
@property(nonatomic, retain)  NSString*  confId;
@property(nonatomic, retain)  NSString*  confType;

@end
