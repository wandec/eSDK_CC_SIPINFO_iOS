//
//  SDKMdm.h
//  anyofficesdk
//
//  Created by kf1 on 15/11/12.
//  Copyright (c) 2015年 pangqi. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SDKMdmDelegate <NSObject>

@optional
// callback
- (void)onReceivedViolation:(NSArray *)resultInfo;

@end

@interface SDKMdm : NSObject

// delegate object
@property (nonatomic, assign) id<SDKMdmDelegate> delegate;

+ (SDKMdm*)getInstance;

// Set delegate Method
- (void)setMdmCheckCallback:(id<SDKMdmDelegate>)SDKMdmDelegate;

// C
void addCheckResult(int rID, int rPolicy);
void onReceivedViolationToUI();

@end
