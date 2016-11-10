//
//  CallingView.m
//  VTMCallDemo
//
//  Created by gaoshuming on 15/10/12.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import "CallingView.h"
#define SCREEN_WIDTH  [[UIScreen mainScreen] applicationFrame].size.width
#define SCREEN_HEIGHT [[UIScreen mainScreen] applicationFrame].size.height

static CallingView *callView = nil;

@implementation CallingView

+(CallingView *)sharedInstance
{
    @synchronized(self) {
        if (callView == nil) {
            callView = [[self alloc]init];
        }
    }
    return callView;
}

-(instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        [self initWithCallView];
        [self addSubview:_callStateImage];
        [self initCloseBtn];
        [self addSubview:_closeBtn];
        self.backgroundColor = [UIColor darkGrayColor];
    }
    return self;
}

-(void)initWithCallView
{
    //呼叫
    _callStateImage = [[UIImageView alloc]initWithImage:[UIImage imageNamed:@"voice_status_call_03"]];
    NSArray *imgArray = nil;
    imgArray = [NSArray arrayWithObjects:[UIImage imageNamed:@"voice_status_call_00"],[UIImage imageNamed:@"voice_status_call_01"],[UIImage imageNamed:@"voice_status_call_02"],[UIImage imageNamed:@"voice_status_call_03"], nil];
    [_callStateImage setAnimationImages:imgArray];
    
}

- (void)initCloseBtn
{
    _closeBtn = [[UIButton alloc] initWithFrame:CGRectMake(SCREEN_WIDTH/2 - 50, 240, 100, 44)];
    [_closeBtn setTitle:@"挂断" forState:UIControlStateNormal];
    [_closeBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [_closeBtn setBackgroundImage:[UIImage imageNamed:@"btn_normal.png"] forState:UIControlStateNormal];
    [_closeBtn setBackgroundImage:[UIImage imageNamed:@"btn_pressed.png"] forState:UIControlStateHighlighted];
    [_closeBtn addTarget:self action:@selector(onClosedBtnPressed:) forControlEvents:UIControlEventTouchUpInside];
    
}

- (void)onClosedBtnPressed:(id)sender
{
    NSLog(@"close btn pressed");
    if (self.delegate)
    {
        [self.delegate closeCall];
    }
    else
    {
        NSLog(@"no delegate to handle close call");
    }
}

-(void)startAnimation
{
    [_callStateImage setAnimationDuration:0.5f];
    [_callStateImage startAnimating];
}

-(void)stopAnimation
{
    [_callStateImage stopAnimating];
}

@end
