//
//  SIPDiaglogInfo.h
//  eSpaceCCSDK
//
//  Created by gaoshuming on 15/11/25.
//  Copyright © 2015年 gaoshuming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "tup_def.h"

@interface SIPDiaglogInfo : NSObject

@property (nonatomic,assign) NSString *mediaType;
@property (nonatomic,assign) NSString *subMediaType;
@property (nonatomic,assign) NSString *body;
@property (nonatomic,copy) NSString *contentStr;

@end
