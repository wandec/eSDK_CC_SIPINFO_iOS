//
//  CallServiceImp.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/13.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECSDefines.h"
#import "tup_def.h"
#import "SIPDiaglogInfo.h"

@interface CallServiceImp : NSObject
{
    BOOL isCallConnect_;
    BOOL isRegToMainServer_;
    BOOL isNeedAddDomainForHuaweiUC_;
    
}
@property (nonatomic,copy) NSString *localIPAddress;
@property (nonatomic,copy) NSString *outgoingAccountCode;
@property (nonatomic,copy) NSString *selfUserDomain;

@property (nonatomic, copy) NSString * callId;
@property (nonatomic, copy) NSString * sessionId;

@property (nonatomic,copy) NSString *voipNumber;

@property (nonatomic,copy) NSString *countryCode;

+(CallServiceImp *)sharedInstance;
+(CallServiceImp *)destroyInstance;

/*
 @method
 @abstract   设置日志开关
 @discussion
 */
+ (void)setLoggerSwitch:(BOOL)isLoggerOn;

/*
 @function
 @abstract   创建通话
 @discussion
 @param      callType(EN_CALL_TYPE, 媒体类型，语音或视频),calleeNumber(被叫方号码)
 @result
 */
+ (BOOL)startCall:(EN_CALL_TYPE)callType calleeNumber:(NSString *)calleeNumber;

+ (BOOL)playVoiceMsgWithMailShortCode:(NSString *)shortCode;
+ (BOOL)answerCallWithSendMode:(CallServiceAudioSendMode)audioSendMode isAudioOnly:(BOOL)isAudioOnly;

+ (BOOL)sendDTMF:(NSInteger)dialNum;

+ (BOOL)holdCall;

+(void)closeCall;

// 发送消息
-(BOOL)sendSIPDiaglogInfo:(SIPDiaglogInfo *)sipInfo;

/*!
 @method
 @abstract   更新SIP数据，并向服务器注册
 @discussion
 */
+ (BOOL)updateInfoAndRegisterToServer:(BOOL)isToMainServer;
/*
 @ SIP 相关配置
 */
-(void)configSipStack;
/*
 *  
 */
- (void)updateSIPInfo:(BOOL)isToMainServer;

@end
