//
//  Log.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/13.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "eSDKIOSLog.h"

@interface Log : NSObject

#if defined(__cplusplus)
#define LOG_EXTERN extern "C"
#else
#define LOG_EXTERN extern
#endif

LOG_EXTERN void logInit();
LOG_EXTERN void logUnit();
LOG_EXTERN void logDbg(NSString *format, ...);
LOG_EXTERN void logInfo(NSString *format, ...);
LOG_EXTERN void logWarn(NSString *format, ...);
LOG_EXTERN void logErr(NSString *format, ...);
LOG_EXTERN void setDBLogEnabledOpt(bool isLogEnabled);

@end
