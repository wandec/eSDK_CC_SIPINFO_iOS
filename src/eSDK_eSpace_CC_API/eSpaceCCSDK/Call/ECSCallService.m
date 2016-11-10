//
//  ECSCallService.m
//  VTMSDK
//
//  Created by gaoshuming on 15/10/20.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import "ECSCallService.h"
#import "CallServiceManger.h"
#import "CallServiceImp.h"

static ECSCallService *g_callService = nil;

@implementation ECSCallService

+ (ECSCallService*)sharedInstance
{
    @synchronized(self)
    {
        if (nil == g_callService)
        {
            g_callService = [[self alloc] init];
        }
    }
    return g_callService;
}

+ (void)destroyInstance
{
    if (g_callService)
    {
        g_callService = nil;
    }
}

#pragma mark -
#pragma mark Call
- (BOOL)isCallServiceIdle
{
    return [[CallServiceManger getCallserviceInstance] isCallFSMStateIdle];
}

-(BOOL)startCall:(NSString*)calleeNumber
{
    NSLog(@"calleeNumber:%@",calleeNumber);
    return [[CallServiceManger getCallserviceInstance] CallService_ProcCallStateMsg:MSG_CMD_START_CALL args:(__bridge void *)(calleeNumber)];
}

-(BOOL)closeCall
{
    return [[CallServiceManger getCallserviceInstance] CallService_ProcCallStateMsg:MSG_CMD_CLOSE_CALL args:nil];
}

-(void)makeInitConfigure
{
    [[CallServiceImp sharedInstance] updateSIPInfo:NO];
    [[CallServiceImp sharedInstance] configSipStack];
}



@end
