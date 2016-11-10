//
//  eSDKIOSLog.h
//  eSDKIOSLog
//  This class is ios logger interface which is added by w00321336, it's a sington class
//  Created by w00321336 on 15-2-13.
//  Copyright (c) 2015年 l00206777. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "eSDKLogDataType.h"
@class LoggerAdaptor;
@interface eSDKIOSLog : NSObject
@property (nonatomic, retain) LoggerAdaptor *objLogger;

//Sington instance
+ (id)getInstance;

//Rewrite for sington purpose
+(id)allocWithZone:(NSZone *)zone;

//Logger init
-(int)logInit:(NSString*)product iniFile:(NSString*)iniFile logLevel:(unsigned int [])level logPath:(NSString*)path;
//Logger uninit
-(int)logFini:(NSString*)product;

/*
 * Below is logger's operations
 */
-(void)logInterfaceInfo:(NSString*)product
          interfaceType:(NSString*)interfaceType
           protocolType:(NSString*)protocolType
          interfaceName:(NSString*)interfaceName
             sourceAddr:(NSString*)sourceAddr
             targetAddr:(NSString*)targetAddr
          transactionID:(NSString*)transactionID
                reqTime:(NSString*)reqTime
               respTime:(NSString*)respTime
             resultCode:(NSString*)resultCode
                 params:(NSString*)params,...;

-(void)logInterfaceError:(NSString*)product
           interfaceType:(NSString*)interfaceType
            protocolType:(NSString*)protocolType
           interfaceName:(NSString*)interfaceName
              sourceAddr:(NSString*)sourceAddr
              targetAddr:(NSString*)targetAddr
           transactionID:(NSString*)transactionID
                 reqTime:(NSString*)reqTime
                respTime:(NSString*)respTime
              resultCode:(NSString*)resultCode
                  params:(NSString*)params,...;

-(void) logOperateDebug:(NSString*) product
             moduleName:(NSString*) moduleName
               userName:(NSString*) userName
             clientFlag:(NSString*) clientFlag
             resultCode:(NSString*) resultCode
                keyInfo:(NSString*) keyInfo
                 params:(NSString*) params,...;

-(void) logOperateInfo:(NSString*) product
            moduleName:(NSString*) moduleName
              userName:(NSString*) userName
            clientFlag:(NSString*) clientFlag
            resultCode:(NSString*) resultCode
               keyInfo:(NSString*) keyInfo
                params:(NSString*) params,...;

-(void) logOperateWarn:(NSString*) product
            moduleName:(NSString*) moduleName
              userName:(NSString*) userName
            clientFlag:(NSString*) clientFlag
            resultCode:(NSString*) resultCode
               keyInfo:(NSString*) keyInfo
                params:(NSString*) params,...;

-(void) logOperateError:(NSString*) product
             moduleName:(NSString*) moduleName
               userName:(NSString*) userName
             clientFlag:(NSString*) clientFlag
             resultCode:(NSString*) resultCode
                keyInfo:(NSString*) keyInfo
                 params:(NSString*) params,...;


-(void) logRunDebug:(NSString*) product param:(NSString*) param;
-(void) logRunWarn:(NSString*) product param:(NSString*) param;
-(void) logRunError:(NSString*) product param:(NSString*) param;
-(void) logRunInfo:(NSString*) product param:(NSString*) param;

-(void) esdk_log_setSendLogStrategy:(unsigned int)period wifiFlag:(unsigned int) wifiFlag serverPath:(const char*) serverPath;
-(void) setCallBackMethod:(WifiInfoCallBack)method;
-(int) initMobileLog:(const char*) product;

@end

//Log instance define
#define IOSLogInstance [eSDKIOSLog getInstance];