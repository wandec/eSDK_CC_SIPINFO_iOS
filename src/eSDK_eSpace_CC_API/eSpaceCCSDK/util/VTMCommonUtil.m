//
//  VTMCommonUtil.m
//  VTMSDK
//
//  Created by gaoshuming on 15/10/16.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import "VTMCommonUtil.h"
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if.h>
#include <ifaddrs.h>

#define IOS_CELLULAR    @"pdp_ip0"
#define IOS_WIFI        @"en0"
#define IOS_VPN         @"utun0"
#define IP_ADDR_IPv4    @"ipv4"
#define IP_ADDR_IPv6    @"ipv6"

@implementation VTMCommonUtil

+ (NSString *)localIPAddress
{
    
    NSString *address = @"error";
    struct ifaddrs *interfaces = NULL;
    struct ifaddrs *temp_addr = NULL;
    int success = 0;
    // retrieve the current interfaces - returns 0 on success
    success = getifaddrs(&interfaces);
    
    if (success == 0) {
        // Loop through linked list of interfaces
        temp_addr = interfaces;
        while(temp_addr != NULL) {
            
            if(temp_addr->ifa_addr->sa_family == AF_INET) {
                // Check if interface is en0 which is the wifi connection on the iPhone
                // it may also be en1 on your ipad3.
                if([[NSString stringWithUTF8String:temp_addr->ifa_name] isEqualToString:@"en0"]) {
                    // Get NSString from C String
                    address = [NSString stringWithUTF8String:inet_ntoa(((struct sockaddr_in *)temp_addr->ifa_addr)->sin_addr)];
                }
            }
            
            temp_addr = temp_addr->ifa_next;
        }
    }
    
    // Free memory
    freeifaddrs(interfaces);
    return address;
}

+ (NSDictionary *)getIPAddresses
{
    NSMutableDictionary *addresses = [NSMutableDictionary dictionaryWithCapacity:8];
    
    // retrieve the current interfaces - returns 0 on success
    struct ifaddrs *interfaces;
    if(!getifaddrs(&interfaces)) {
        // Loop through linked list of interfaces
        struct ifaddrs *interface;
        for(interface=interfaces; interface; interface=interface->ifa_next) {
            if(!(interface->ifa_flags & IFF_UP) /* || (interface->ifa_flags & IFF_LOOPBACK) */ ) {
                continue; // deeply nested code harder to read
            }
            const struct sockaddr_in *addr = (const struct sockaddr_in*)interface->ifa_addr;
            char addrBuf[ MAX(INET_ADDRSTRLEN, INET6_ADDRSTRLEN) ];
            if(addr && (addr->sin_family==AF_INET || addr->sin_family==AF_INET6)) {
                NSString *name = [NSString stringWithUTF8String:interface->ifa_name];
                NSString *type;
                if(addr->sin_family == AF_INET) {
                    if(inet_ntop(AF_INET, &addr->sin_addr, addrBuf, INET_ADDRSTRLEN)) {
                        type = IP_ADDR_IPv4;
                    }
                } else {
                    const struct sockaddr_in6 *addr6 = (const struct sockaddr_in6*)interface->ifa_addr;
                    if(inet_ntop(AF_INET6, &addr6->sin6_addr, addrBuf, INET6_ADDRSTRLEN)) {
                        type = IP_ADDR_IPv6;
                    }
                }
                if(type) {
                    NSString *key = [NSString stringWithFormat:@"%@/%@", name, type];
                    addresses[key] = [NSString stringWithUTF8String:addrBuf];
                }
            }
        }
        // Free memory
        freeifaddrs(interfaces);
    }
    return [addresses count] ? addresses : nil;
}

+(BOOL)isValidIP:(NSString *)ip
{
    if ([ip length] == 0)
    {
        return NO;
    }
    NSString *ipStr = [NSString stringWithString:ip];
    NSError *error = nil;
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"^(2\\d{0,2}|1\\d{0,2}|[1-9]\\d|[1-9]).\\d{0,3}.\\d{0,3}.\\d{0,3}$" options:0 error:&error];
    
    if (regex != nil)
    {
        NSTextCheckingResult *firstMatch=[regex firstMatchInString:ipStr options:0 range:NSMakeRange(0, [ipStr length])];
        
        //如果没匹配到,就是格式不对了.
        if (!firstMatch)
        {
            return NO;
        }
    }
    
    NSArray *ipSectionarray = [ip componentsSeparatedByString:@"."];
    
    //先把ip拆开成字符串数组,如果不是4段,则ip地址不合法
    if ([ipSectionarray count] != 4)
    {
        return NO;
    }
    
    for (NSString *tempStr in ipSectionarray)
    {
        //不能有某个字段大于255
        if(tempStr.integerValue > 255)
        {
            return NO;
        }
    }
    return YES;
}

+ (BOOL)isValidPort:(NSInteger)port
{
    if ( port > 65535 || port <= 0)
    {
        return NO;
    }
    return YES;
}

@end
