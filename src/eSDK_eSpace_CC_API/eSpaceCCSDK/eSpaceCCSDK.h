//
//  eSpaceCCSDK.h
//  eSpaceCCSDK
//
//  Created by gaoshuming on 15/11/3.
//  Copyright © 2015年 gaoshuming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTMCommonDefine.h"

@interface eSpaceCCSDK : NSObject

/**
 *  创建eSpaceCCSDK单例
 *
 */
+(eSpaceCCSDK *)sharedInstance;

/**
 *  加载VTMSDK
 *
 *
 *  @return 是否加载成功
 */
-(BOOL)loadeSpaceCCSDK;

/**
 *  卸载eSpaceCCSDK
 */
-(BOOL)unloadeSpaceCCSDK;

/*
 * 设置是否打开VTM日志开关
 *
 */
-(void)setLogSwitch:(BOOL)openOrClose;


/**
 设置服务器地址和端口号等信息

 @param serverIP 服务器地址
 @param serverPort 服务器端口号
 @param anonymousCard 卡名
 @param localPort 本地端口号
 @return RET_OK 表示成功,其他表示失败
 */
- (short)setHostAddr:(NSString*)serverIP withPort:(NSUInteger)serverPort withCard:(NSString *)anonymousCard localPort:(NSString *)localPort;

/**
 *  发起匿名呼叫
 *  @param accessCode 访问接入码
 *  @return VTM_METHOD_RETCODE,接口调用成功只是表示呼叫请求发出去了
 */
-(short)anonymousCallWithAccessCode:(NSString *)accessCode;

/**
 *	释放通话
 * @return VTM_METHOD_RETCODE
 */
- (short)releaseCall;

/**
 *  收到返回的语音后发送消息
 *  @return 0，接口调用成功表示发送消息成功
 */
-(short)sendMessageWithMediaType:(NSString *)mediaType subType:(NSString *)subMediaType body:(NSString *)infoBody;

/*
 * 检测是否是WiFi环境
 * @return  0 非WiFi
 *          1 WiFi
 */
-(int)checkIfInWifiOrNot;

/*
 * 日志回调
 *
 * @param serverPath 日志采集配置文件地址
 *
 * @return nil
 *
 */
//-(void)setCallBack:(NSString *)serverPath;

@end
