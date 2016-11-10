//
//  ECSUtils.h
//  VTMSDK
//
//  Created by gaoshuming on 15/10/13.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ECSUtils : NSObject

#pragma mark -
#pragma mark 枚举值调试信息管理

typedef enum
{
    /* SDK 1 ~ 99 */
    EnumDescType_CallServiceEvt		= 1,
    EnumDescType_CallServiceState	= 2,
    EnumDescType_LoginState			= 3,
    EnumDescType_LoginCompStatus	= 4,
    EnumDescType_FastSDK_REG_NotifyID	= 5,
    EnumDescType_FastSDK_CALL_NotifyID	= 6,
    EnumDescType_FastSDK_SUB_NotifyID	= 7,
    EnumDescType_SVNCompStatus		= 8,
    EnumDescType_eConf_Callback_Notify = 9,
    EnumDescType_TUP_Call_Notifications = 10,
    /* Custom 100 ~ 999 */
    
    EnumDescType_Unknown
}EnumDescType;

+ (NSString *)enumDescription:(NSInteger)enumValue forType:(EnumDescType)type;
+ (void)addEnumDescription:(NSString *)desc forEnum:(NSInteger)enumValue forType:(EnumDescType)type;
+ (void)addEnumDescription:(NSString *)desc forEnum:(NSInteger)enumValue forIdentity:(const char *)identity;
+ (NSString *)enumDescription:(NSInteger)enumValue forIdentity:(const char *)identity;

+ (NSString*)addDomainField:(NSString*)inString domain:(NSString*)domain;
+ (NSString*)removeDomainField:(NSString*)inString;
+ (NSString*)addPrefix:(NSString*)inString prefix:(NSString*)prefix;
+ (NSString*)removePrefix:(NSString*)inString prefix:(NSString*)prefix;
+(NSString*)domainFromNumber:(NSString*)number;
+ (NSString *)notNilString:(NSString *)inString;


#define ECSUTILES_ADD_ENUM_DESCRIPTION(enumValue, type) do { [ECSUtils addEnumDescription:[NSString stringWithFormat:@"%s", #enumValue] forEnum:enumValue forType:type]; } while(0)

#define RETURN_NO_IF_PARAM_TEXT_EMPTY(param) do { if (nil == param || ![param isKindOfClass:[NSString class]] || [param length] == 0) { logErr(@"Invalid string : %s is empty.",(#param)); return NO; } } while(0)

#define RETURN_IF_PARAM_TEXT_EMPTY(param) do { if (nil == param || ![param isKindOfClass:[NSString class]] || [param length] == 0) { logErr(@"Invalid string : %s is empty.",(#param)); return; } } while(0)

#define RETURN_NO_IF_PARAM_NIL(param) do { if (nil == param) { logErr(@"Invalid param : %s is nil.",(#param)); return NO; } } while(0)

@end
