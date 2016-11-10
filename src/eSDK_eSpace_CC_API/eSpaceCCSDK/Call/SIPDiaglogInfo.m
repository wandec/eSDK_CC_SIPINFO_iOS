//
//  SIPDiaglogInfo.m
//  eSpaceCCSDK
//
//  Created by gaoshuming on 15/11/25.
//  Copyright © 2015年 gaoshuming. All rights reserved.
//

#import "SIPDiaglogInfo.h"

@implementation SIPDiaglogInfo

@synthesize mediaType;
@synthesize subMediaType;
@synthesize body;
@synthesize contentStr;

-(instancetype)init
{
    self = [super init];
    if (self)
    {
        self.mediaType = @"";
        self.subMediaType = @"";
        self.body = @"";
        self.contentStr = @"";
    }
    return self;
}


@end
