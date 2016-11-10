//
//  SettingInfo.m
//  VTMCallDemo
//
//  Created by gaoshuming on 15/10/30.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import "SettingInfo.h"

static NSString *const DEFAULT_ACCESSCODE = @"2001";
static NSString * const DEFAULT_SERVER = @"172.22.8.69";
static NSInteger const DEFAULT_PORT = 5060;
static NSString * const DEFAULT_LASTLOGINACCOUNT= @"";
static NSInteger const DEFAULT_LOCAL_PORT = 5070;

NSString * const KeyLastLoginAccount = @"LastLoginAccount";
NSString * const KeyServerIP = @"ServerIP";
NSString * const KeyServerPort = @"ServerPort";
NSString * const KeyAccessCode = @"accessCode";
NSString * const KeyLocalPort = @"KeyLocalPort";

SettingInfo *setting_info = nil;

@implementation SettingInfo

+(SettingInfo *)sharedInstance
{
    @synchronized(self)
    {
        if (setting_info == nil) {
            setting_info = [[SettingInfo alloc]init];
        }
    }
    return setting_info;
}

-(instancetype)init
{
    self = [super init];
    if (self)
    {
        self.serverIP = @"";
        self.port = @"";
        self.accessCode = @"";
        self.lastAccount = @"";
        self.localPort = @"";
    }
    return self;
}

-(BOOL)loadConfigInfo
{
    NSString *filePath = [self configFilePath];
    NSFileManager *manager = [NSFileManager defaultManager];
    if ([manager fileExistsAtPath:filePath])
    {
        _dataDic = [NSDictionary dictionaryWithContentsOfFile:filePath];
    }
    if (_dataDic)
    {
        self.lastAccount = [_dataDic objectForKey:KeyLastLoginAccount];
        self.serverIP = [_dataDic objectForKey:KeyServerIP];
        self.port = [_dataDic objectForKey:KeyServerPort];
        self.accessCode = [_dataDic objectForKey:KeyAccessCode];
        self.localPort = [_dataDic objectForKey:KeyLocalPort];
        return YES;
    }
    else 
    {
        self.lastAccount = DEFAULT_LASTLOGINACCOUNT;
        self.serverIP = DEFAULT_SERVER;
        self.port = [NSString stringWithFormat:@"%ld",(long)DEFAULT_PORT];
        self.accessCode = DEFAULT_ACCESSCODE;
        self.localPort = [NSString stringWithFormat:@"%ld",(long)DEFAULT_LOCAL_PORT];
    }
    
    return NO;
}

-(BOOL)saveConfigInfo
{
    NSMutableDictionary *currentConfigDic = [NSMutableDictionary dictionary];
    [currentConfigDic setObject:[self getNotNilStr:self.lastAccount] forKey:KeyAccessCode];
    [currentConfigDic setObject:[self getNotNilStr:self.serverIP] forKey:KeyServerIP];
    [currentConfigDic setObject:[self getNotNilStr:self.port] forKey:KeyServerPort];
    [currentConfigDic setObject:[self getNotNilStr:self.accessCode] forKey:KeyAccessCode];
    
    NSString *configFilePath = [self configFilePath];
    [currentConfigDic writeToFile:configFilePath atomically:YES];
    
    return YES;
}

-(NSString*)configFilePath
{
    NSArray * docPathArray = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *docPath = [docPathArray objectAtIndex:0];
    NSString *filePath = [docPath stringByAppendingPathComponent:@"callConfig.plist"];
    return filePath;
}

- (NSString*)getNotNilStr:(NSString*)orignalStr
{
    NSString *resultStr = @"";
    if ([orignalStr length] > 0)
    {
        resultStr = [NSString stringWithString:orignalStr];
    }
    return resultStr;
}

@end
