//
//  ECSUtils.m
//  VTMSDK
//
//  Created by gaoshuming on 15/10/13.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import "ECSUtils.h"

@implementation ECSUtils

+ (NSString*)addDomainField:(NSString*)inString domain:(NSString*)domain
{
    if (([inString length] <= 0) || ([domain length] <= 0))
        return inString;
    
    return [NSString stringWithFormat:@"%@@%@", inString, domain];
}

+ (NSString*)removeDomainField:(NSString*)inString
{
    if ([inString length] <= 0)
    {
        return inString;
    }
    
    NSRange range = [inString rangeOfString:@"@"];
    
    if (range.length != 0)
    {
        range = NSMakeRange(0, range.location);
        return [inString substringWithRange:range];
    }
    else
    {
        return inString;
    }
}

+ (NSString*)addPrefix:(NSString*)inString prefix:(NSString*)prefix
{
    if ([inString length] <= 0 || [prefix length] <= 0)
    {
        return inString;
    }
    
    return [NSString stringWithFormat:@"%@%@", prefix, inString];
}

+ (NSString*)removePrefix:(NSString*)inString prefix:(NSString*)prefix
{
    if ([inString length] <= 0 || [prefix length] <= 0)
    {
        return inString;
    }
    
    if ([inString hasPrefix:prefix]) {
        return [inString substringFromIndex:[prefix length]];
    }
    else {
        return inString;
    }
}

//
static NSMutableDictionary * s_enumDescriptions = nil;

+ (NSMutableDictionary *)enumDescriptions
{
    if (nil == s_enumDescriptions)
    {
        s_enumDescriptions = [[NSMutableDictionary alloc] init];
    }
    return s_enumDescriptions;
}

+ (NSString *)notNilString:(NSString *)inString {
    return inString == nil ? @"" : inString;
}

+ (void)addEnumDescription:(NSString *)desc forEnum:(NSInteger)enumValue forType:(EnumDescType)type;
{
    if (nil == desc)
    {
        return;
    }
    [[ECSUtils enumDescriptions] setObject:desc	forKey:[NSString stringWithFormat:@"%d-%d", type, enumValue]];
}

+ (NSString *)enumDescription:(NSInteger)enumValue forType:(EnumDescType)type
{
    return [ECSUtils notNilString:[[ECSUtils enumDescriptions] objectForKey:[NSString stringWithFormat:@"%d-%d", type, enumValue]]];
}

+ (void)addEnumDescription:(NSString *)desc forEnum:(NSInteger)enumValue forIdentity:(const char *)identity {
    if (nil == desc || NULL == identity)
    {
        return;
    }
    [[ECSUtils enumDescriptions] setObject:desc	forKey:[NSString stringWithFormat:@"%s-%d", identity, enumValue]];
}

+ (NSString *)enumDescription:(NSInteger)enumValue forIdentity:(const char *)identity {
    if (NULL == identity) {
        return @"";
    }
    return [ECSUtils notNilString:[[ECSUtils enumDescriptions] objectForKey:[NSString stringWithFormat:@"%s-%d", identity, enumValue]]];
}

+(NSString*)domainFromNumber:(NSString*)number
{
    if ([number length] <= 0)
    {
        return @"";
    }
    
    NSRange range = [number rangeOfString:@"@"];
    
    if (range.length != 0)
    {
        range = NSMakeRange(range.location + 1, [number length] - range.location - 1);
        return [number substringWithRange:range];
    }
    else
    {
        return @"";
    }
}



@end
