//
//  SettingInfo.h
//  VTMCallDemo
//
//  Created by gaoshuming on 15/10/30.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SettingInfo : NSObject

@property (nonatomic,copy) NSString *serverIP;
@property (nonatomic,copy) NSString *port;
@property (nonatomic,copy) NSString *accessCode;
@property (nonatomic,copy) NSString *lastAccount;
@property (nonatomic,copy) NSString *localPort;

@property (nonatomic,strong) NSDictionary *dataDic;

+(SettingInfo *)sharedInstance;

-(BOOL)loadConfigInfo;
-(BOOL)saveConfigInfo;

@end
