//
//  AccountInfo.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/15.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AccountInfo : NSObject

@property (nonatomic,copy) NSString *anonymousCardName;//匿名呼叫
@property (nonatomic,copy) NSString *accessCode;//匿名呼叫时候的呼叫访问接入码
@property (nonatomic,copy) NSString *identifyCode;//做isa访问时候用的一个标识码
@property (nonatomic,copy) NSString *calledNumber;//匿名呼叫呼叫接入码

@property (nonatomic,copy) NSString *strSipServerIP; //
@property (nonatomic,copy) NSString *strSipServerPort;
@property (nonatomic,retain) NSString *vtmNo;
@property (nonatomic,assign) BOOL sipISEncoded;

//入口服务器配置信息 IP和端口号
@property (copy, nonatomic)   NSString *entryServerIp;
@property (copy, nonatomic)   NSString *entryServerPort;

@property (nonatomic,copy) NSString *cookie;

+(AccountInfo *)sharedInstance;
+(AccountInfo *)destroyInstance;

@end
