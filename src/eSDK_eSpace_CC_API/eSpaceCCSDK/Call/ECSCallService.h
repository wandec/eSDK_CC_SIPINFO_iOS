//
//  ECSCallService.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/20.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ECSCallService : NSObject

+ (ECSCallService*)sharedInstance;
+ (void)destroyInstance;
/**
 *  对fast底层做初始化设置
 */
-(void)makeInitConfigure;

#pragma mark - Call

/*!
 @method
 @abstract   判断是否存在通话
 @discussion
 */
- (BOOL)isCallServiceIdle;

/*!
 @function
 @abstract   开始语音呼叫
 @discussion
 @param      calleeNumber(被叫方号码，可以为[号码]或[号码@域名]格式)
 @result     YES/NO
 */
-(BOOL)startCall:(NSString*)calleeNumber;

/*!
 @method
 @abstract   结束通话
 @discussion
 */
- (BOOL)closeCall;


@end

@interface ECSCallService (Deprecated)

-(NSString*)currentCallId;

@end





