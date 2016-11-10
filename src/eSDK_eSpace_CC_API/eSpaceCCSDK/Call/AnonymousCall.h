//
//  AnonymousCall.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/13.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECSCallService.h"

@interface AnonymousCall : NSObject

@property (nonatomic,readonly)ECSCallService *callService;

+(AnonymousCall *)sharedInstance;

/**
 *  销毁全局的匿名呼叫实例
 */
+ (void)destroyInstance;

/**
 *  是否处于通话中
 *
 *  @return 是否处于通话中
 */
-(BOOL)isInCall:(NSString *)accessCode;


/**
 *	结束呼叫
 *
 *	@return	结束请求是否发出
 */
-(BOOL)closeCall;


@end
