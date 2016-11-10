//
//  VTMCommonUtil.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/16.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VTMCommonUtil : NSObject


/*************************************************
 函数名称：getIPAddress
 函数描述：获取本地ip，即eth0网口上的ip
 输入参数：无
 输出参数：
 返回值：  本地ip
 其他：	  NA
 *************************************************/
+ (NSString*)localIPAddress;

/**
 *  判断ip是否合法
 *
 *  @param ip 待检测ip字符串
 *
 *  @return ip是否合法
 */
+(BOOL)isValidIP:(NSString*)ip;

/**
 *  判断端口号是否合法
 *
 *  @param port 端口号
 *
 *  @return 是否合法
 */
+ (BOOL)isValidPort:(NSInteger)port;

+ (NSDictionary *)getIPAddresses;

@end
