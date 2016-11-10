//
//  CallingUtils.m
//  VTMCallDemo
//
//  Created by gaoshuming on 15/10/30.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import "CallingUtils.h"
#import <UIKit/UIKit.h>

@implementation CallingUtils

+ (NSString*)dateToString:(NSDate*)date
{
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
    NSString *result =nil;
    result = [dateFormatter stringFromDate:date];
    return result;
}

+ (BOOL)isIPValid:(NSString*)ip
{
    
    if ([ip length] == 0)
    {
        return NO;
    }
    NSString *ipStr = [NSString stringWithString:ip];
    NSError *error = nil;
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"^((?:(?:25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d)))\\.){3}(?:25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d))))$" options:0 error:&error];
    
    if (regex != nil)
    {
        NSTextCheckingResult *firstMatch=[regex firstMatchInString:ipStr options:0 range:NSMakeRange(0, [ipStr length])];
        
        //如果没匹配到,就是格式不对了.
        if (!firstMatch)
        {
            return NO;
        }
        else
        {
            return YES;
        }
    }
    return NO;
}


+ (BOOL)isNumber:(NSString*)inputStr
{
    if ([inputStr length] == 0)
    {
        return NO;
    }
    
    NSError *error = nil;
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"^\\d{1,}$" options:0 error:&error];
    
    if (regex != nil)
    {
        NSTextCheckingResult *firstMatch=[regex firstMatchInString:inputStr options:0 range:NSMakeRange(0, [inputStr length])];
        
        //如果没匹配到,就是格式不对了.
        if (!firstMatch)
        {
            return NO;
        }
        else
        {
            return YES;
        }
    }
    return NO;
}

+ (void)showAlertWithTitle:(NSString*)title content:(NSString*)content
{
    UIAlertView *alertView = [[UIAlertView alloc]initWithTitle:title message:content delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alertView show];
}

+ (BOOL)isValidPort:(NSInteger)port
{
    if(port > 65535 || port <= 0)
    {
        return NO;
    }
    return YES;
}

+ (void)showAlertWithTitle:(NSString *)title content:(NSString *)content andDelegate:(id)delegate
{
    UIAlertView *alertView = [[UIAlertView alloc] init];
    alertView.title = title;
    alertView.message = content;
    alertView.delegate = delegate;
    [alertView addButtonWithTitle:@"确定"];
    [alertView addButtonWithTitle:@"取消"];
    
    [alertView show];
}

@end
