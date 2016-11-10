//
//  AppDelegate.m
//  eSDKCC(iPhone)
//
//  Created by gaoshuming on 15/11/25.
//  Copyright © 2015年 gaoshuming. All rights reserved.
//

#import "AppDelegate.h"
#import "eSpaceCCSDK.h"
#import "CallingView.h"
#import "MainViewController.h"
#import "SettingInfo.h"


static NSString * const ACCESSCODE = @"2001";
static NSString * const DEFAULT_SERVER = @"172.22.8.69";
static NSInteger const DEFAULT_PORT = 5060;

@interface AppDelegate ()

@property (strong, nonatomic) MainViewController *viewController;

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc]initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];
    self.window.hidden = NO;
    
    [[eSpaceCCSDK sharedInstance] loadeSpaceCCSDK];
    [[eSpaceCCSDK sharedInstance] setLogSwitch:YES];
    
    [[SettingInfo sharedInstance] loadConfigInfo];
    if ([[SettingInfo sharedInstance].accessCode length] == 0)
    {
        [SettingInfo sharedInstance].accessCode = ACCESSCODE;
    }
    
    if ([[SettingInfo sharedInstance].serverIP length] >0 && [[SettingInfo sharedInstance].port length]> 0)
    {
        NSUInteger portValue = [[SettingInfo sharedInstance].port integerValue];
        [[eSpaceCCSDK sharedInstance] setHostAddr:[SettingInfo sharedInstance].serverIP withPort:portValue withCard:@"" localPort:@"5070"];
    }
    else
    {
        [SettingInfo sharedInstance].serverIP = DEFAULT_SERVER;
        [SettingInfo sharedInstance].port = [NSString stringWithFormat:@"%ld",(long)DEFAULT_PORT];
        [[eSpaceCCSDK sharedInstance] setHostAddr:DEFAULT_SERVER withPort:DEFAULT_PORT withCard:@"" localPort:@"5070"];
    }
    
    
    MainViewController *mainVC = [[MainViewController alloc]init];
    self.viewController = mainVC;
    
    UINavigationController *nav = [[UINavigationController alloc]initWithRootViewController:self.viewController];
    self.navigationVC = nav;
    self.window.rootViewController = nav;
    
    [self.window makeKeyAndVisible];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

+(AppDelegate *)appDelegate
{
    return (AppDelegate *)[UIApplication sharedApplication].delegate;
}

@end
