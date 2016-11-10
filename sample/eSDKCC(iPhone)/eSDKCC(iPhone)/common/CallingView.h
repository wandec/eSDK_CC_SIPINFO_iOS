//
//  CallingView.h
//  VTMCallDemo
//
//  Created by gaoshuming on 15/10/12.
//  Copyright © 2015年 wangchan. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CallingViewDelegate <NSObject>

- (void)closeCall;

@end

@interface CallingView : UIView

@property (nonatomic,strong) UIImageView *callStateImage;
@property (nonatomic,strong) UIButton *closeBtn;
@property (nonatomic,assign) id<CallingViewDelegate>delegate;

+(CallingView *)sharedInstance;

-(void)startAnimation;
-(void)stopAnimation;

@end
