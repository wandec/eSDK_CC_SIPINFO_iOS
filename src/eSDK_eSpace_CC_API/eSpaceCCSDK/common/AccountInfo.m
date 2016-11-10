//
//  AccountInfo.m
//  VTMSDK
//
//  Created by gaoshuming on 15/10/15.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import "AccountInfo.h"

static NSString * const DEFAULT_IDENTIFYCODE = @"ebola";
static AccountInfo *accountInfo = nil;

@implementation AccountInfo

+(AccountInfo *)sharedInstance
{
    @synchronized(self) {
        if (accountInfo == nil) {
            accountInfo = [[AccountInfo alloc]init];
        }
    }
    return accountInfo;
}

-(id)init
{
    self = [super init];
    if (self) {
        _identifyCode = DEFAULT_IDENTIFYCODE;
        self.anonymousCardName = @"";
    }
    return self;
}

+(AccountInfo *)destroyInstance
{
    @synchronized(self) {
        if (accountInfo != nil) {
            accountInfo = nil;
        }
    }
    return accountInfo;
}


@end
