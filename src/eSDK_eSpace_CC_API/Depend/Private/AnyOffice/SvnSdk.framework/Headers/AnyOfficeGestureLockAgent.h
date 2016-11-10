//
//  AnyOfficeGestureLockAgent.h
//  anyofficesdk
//
//  Created by SDK_Fanjiepeng on 15/6/29.
//  Copyright (c) 2015年 fanjiepeng. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol GestureLockDelegate <NSObject>

-(void)CodeErrorTimesReachLimit;

@end

@interface AnyOfficeGestureLockAgent : NSObject

@property (nonatomic,assign) id<GestureLockDelegate>delegate;

+(AnyOfficeGestureLockAgent*)getInstance;

//设置手势密码代理
-(void)setGestureLockDelegate:(id<GestureLockDelegate>)delegate;

//启动手势密码
-(BOOL)startGestrueLock;

//停止手势密码
-(BOOL)stopGestrueLock;

//设置手势密码锁定时间
-(void)setLockTime:(unsigned int)secondTime;

//设置手势密码 弹出设置手势密码界面
-(void)setGestureLock;

//执行锁定，弹出锁定界面，等待用户解锁
-(void)verifyGestureLock;

//忘记/修改手势密码
-(void)modifyGestureLock;

//判断是否存在手势密码
+(BOOL)isExistGestureLockCode;

//开启手势密码
-(void)enableGestureLock;

//关闭手势密码
-(void)disableGestureLock;

//判断是否开启手势密码
-(BOOL)isEnableGestureLock;

//使锁定界面消失
-(void)dismissGestureLockVC;

//复位锁屏配置 登录密码错误次数置零／手势密码错误次数置零／清除锁定状态
+(void)resetGestureLockConfiguration;

@end


@interface UIWindow (AnyOfficeGestureLockAgent)

@end