//
//  SubNotifyResult.m
//  VTMSDK
//
//  Created by gaoshuming on 15/10/20.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import "SubNotifyResult.h"

@implementation SubNotifyResult

@synthesize  subscriptionState;
@synthesize  statusCode;

- (void)setStatusCode:(NSString *)originalStatusCode {
    if ([originalStatusCode length] < [@"SIP/2.0 xxx" length]) {
        return;
    }
    
    if ([originalStatusCode hasPrefix:@"SIP/2.0 "]) {
        statusCode = [[NSString alloc] initWithString:[originalStatusCode substringWithRange:NSMakeRange(8, 3)]];
    }
}

- (BOOL)isDataValid {
    BOOL isInvalid = ([subscriptionState length] == 0 || [statusCode length] == 0);
    return isInvalid ? NO : YES;
}

- (BOOL)isResultTrying {
    if ([self.statusCode length] <= 0) {
        return NO;
    }
    return [statusCode intValue] < 200;
}

- (BOOL)isResultSuccess {
    if ([self.statusCode length] <= 0) {
        return NO;
    }
    return ([statusCode intValue] >= 200 && [statusCode intValue] < 300);
}

@end

@implementation ConfInviteInfo

@synthesize  callerNum;
@synthesize  confId;
@synthesize confType;

-(id)init{
    self = [super init];
    if (self != nil) {
        callerNum = nil;
        confId = nil;
        confType = nil;
    }
    
    return self;
}

@end
