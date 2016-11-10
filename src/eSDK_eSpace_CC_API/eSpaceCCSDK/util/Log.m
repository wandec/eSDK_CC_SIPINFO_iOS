//
//  Log.m
//  VTMSDK
//
//  Created by gaoshuming on 15/10/13.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import "Log.h"
#import "eSDKLogDataType.h"
#import "CallServiceImp.h"

static bool g_isLogEnabled = false;
static unsigned int g_logLevel[LOG_CATEGORY] = {3};

void setDBLogEnabledOpt(bool isLogEnabled)
{
    g_isLogEnabled = isLogEnabled;
    [CallServiceImp setLoggerSwitch:isLogEnabled];
}

@implementation Log

void logInit()
{
    //默认写在document目录下
    NSArray* paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString* docDir = [paths objectAtIndex:0];
    NSString* logFilePath = [docDir stringByAppendingPathComponent:@"/VTMSDKLog"];
    NSLog(@"logFilePath:%@",logFilePath);
    [[eSDKIOSLog getInstance] logInit:@"VTM" iniFile:@"" logLevel:g_logLevel logPath:logFilePath];
}

void logUnit()
{
    [[eSDKIOSLog getInstance] logFini:@"VTM"];
    [CallServiceImp setLoggerSwitch:NO];
}

void logDbg(NSString *format, ...)
{
    if (!g_isLogEnabled) {
        return;
    }
    
    va_list args;
    va_start(args,format);
    NSString *printfMsg = [[NSString alloc] initWithFormat:format arguments:args];
    va_end(args);
    
    NSLog(@"%@",printfMsg);
    [[eSDKIOSLog getInstance] logRunDebug:@"VTM" param:printfMsg];
}

void logInfo(NSString *format, ...)
{
    if (!g_isLogEnabled) {
        return;
    }
    
    va_list args;
    va_start(args,format);
    NSString *printfMsg = [[NSString alloc] initWithFormat:format arguments:args];
    va_end(args);
    
    NSLog(@"%@",printfMsg);
    [[eSDKIOSLog getInstance] logRunInfo:@"VTM" param:printfMsg];
}

void logWarn(NSString *format, ...)
{
    if (!g_isLogEnabled) {
        return;
    }
    
    va_list args;
    va_start(args,format);
    NSString *printfMsg = [[NSString alloc] initWithFormat:format arguments:args];
    va_end(args);
    
    NSLog(@"%@",printfMsg);
    [[eSDKIOSLog getInstance] logRunWarn:@"VTM" param:printfMsg];
}

void logErr(NSString *format, ...)
{
    if (!g_isLogEnabled) {
        return;
    }
    
    va_list args;
    va_start(args,format);
    NSString *printfMsg = [[NSString alloc] initWithFormat:format arguments:args];
    va_end(args);
    
    NSLog(@"%@",printfMsg);
    [[eSDKIOSLog getInstance] logRunError:@"VTM" param:printfMsg];
}


@end
