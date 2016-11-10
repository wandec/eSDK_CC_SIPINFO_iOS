//
//  CallingUtils.h
//  VTMCallDemo
//
//  Created by gaoshuming on 15/10/30.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CallingUtils : NSObject

+ (NSString*)dateToString:(NSDate*)date;

+ (BOOL)isIPValid:(NSString*)ipStr;

/**
 *  判断字符串是否为数字
 *
 *  @param inputStr 输入字符串
 *
 *  @return 是否为数字
 */
+ (BOOL)isNumber:(NSString*)inputStr;

/**
 *  显示一个提示框,提示框只有一个确认按钮
 *
 *  @param title   提示框的标题
 *  @param content 要提示的内容
 */
+ (void)showAlertWithTitle:(NSString*)title content:(NSString*)content;

/**
 *  判断一个端口的值是否合法
 *
 *  @param port 端口的值
 *
 *  @return 是否合法
 */
+ (BOOL)isValidPort:(NSInteger)port;

/**
 *  显示一个提示框,提示框只有一个确认按钮
 *
 *  @param title    标题
 *  @param content  内容
 *  @param delegate 提示框的代理
 */
+ (void)showAlertWithTitle:(NSString *)title content:(NSString *)content andDelegate:(id)delegate;

@end
