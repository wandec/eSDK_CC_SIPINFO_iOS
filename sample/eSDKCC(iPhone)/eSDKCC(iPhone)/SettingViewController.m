//
//  SettingViewController.m
//  eSpaceCCDemo
//
//  Created by gaoshuming on 15/11/23.
//  Copyright © 2015年 gaoshuming. All rights reserved.
//

#define SCREEN_WIDTH self.view.frame.size.width
#define SCREEN_HEIGHT self.view.frame.size.height

#import "SettingViewController.h"
#import "SettingInfo.h"
#import "CallingUtils.h"
#import "eSpaceCCSDK.h"

@interface SettingViewController ()

@property (strong, nonatomic) IBOutlet UITextField *serverText;
@property (strong, nonatomic) IBOutlet UITextField *portText;
@property (strong, nonatomic) IBOutlet UITextField *localPortTextField;
@property (strong, nonatomic) IBOutlet UITextField *anonymousCardTextField;


@end

@implementation SettingViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.serverText.text = [SettingInfo sharedInstance].serverIP;
    self.portText.text = [SettingInfo sharedInstance].port;
    self.localPortTextField.text = [SettingInfo sharedInstance].localPort;
    
    [self setWithNavigation];
}


-(void)setWithNavigation
{
    if (self.navigationController)
    {
        [self.navigationItem setTitle:NSLocalizedString(@"settings", @"Settings")];
        UIBarButtonItem *leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"返回" style:UIBarButtonItemStylePlain target:self action:@selector(onBackBtnPressed:)];
        self.navigationItem.leftBarButtonItem = leftBarButtonItem;
        
        UIBarButtonItem *rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"保存" style:UIBarButtonItemStylePlain target:self action:@selector(onSaveBtnPressed:)];
        self.navigationItem.rightBarButtonItem = rightBarButtonItem;
    }
}

-(void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    //隐藏键盘
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleKeyBoardHide:) name:UIKeyboardWillHideNotification object:nil];
    
    //显示键盘
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleKeyBoardShow:) name:UIKeyboardWillShowNotification object:nil];
}

#pragma mark - 键盘通知
-(void)handleKeyBoardShow:(NSNotification *)notify
{
    NSDictionary *userInfo = [notify userInfo];
    NSNumber *duration = userInfo[UIKeyboardAnimationDurationUserInfoKey];
    [UIView animateWithDuration:[duration doubleValue] animations:^{
        self.view.frame = CGRectMake(0,-60, SCREEN_WIDTH, SCREEN_HEIGHT);
        NSLog(@"self.view.frame:%f,%f,%f",self.view.frame.origin.x,self.view.frame.size.width,self.view.frame.size.height);
    }];
}

-(void)handleKeyBoardHide:(NSNotification *)notify
{
    NSDictionary *userInfo = [notify userInfo];
    NSNumber *duration = userInfo[UIKeyboardAnimationDurationUserInfoKey];
    [UIView animateWithDuration:[duration doubleValue] animations:^{
        self.view.frame = CGRectMake(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    }];
}

-(void)goBackAction
{
    if (self.navigationController) {
        [self.navigationController popViewControllerAnimated:YES];
    }
}

-(void)onBackBtnPressed:(id)sender
{
    [self.view endEditing:YES];
    NSString *ip = self.serverText.text;
    NSString *port = self.portText.text;
    NSString *localPort = self.localPortTextField.text;
    
    NSString *oldIp = [SettingInfo sharedInstance].serverIP;
    NSString *oldPort = [SettingInfo sharedInstance].port;
    NSString *oldLocalPort = [SettingInfo sharedInstance].localPort;
    
    if (![ip isEqualToString:oldIp] || ![port isEqualToString:oldPort] || ![localPort isEqualToString:oldLocalPort])
    {
        [CallingUtils showAlertWithTitle:@"提示" content:@"保存已修改的内容吗?" andDelegate:self];
    }
    else
    {
        [self goBackAction];
    }
}

-(void)onSaveBtnPressed:(id)sender
{
    [self.view endEditing:YES];
    NSString *ipStr = self.serverText.text;
    NSString *portStr = self.portText.text;
    NSString *localPort = self.localPortTextField.text;
    BOOL isIPOK = [CallingUtils isIPValid:ipStr];
    if (!isIPOK) {
        [CallingUtils showAlertWithTitle:@"配置错误" content:@"IP地址无效"];
        return;
    }
    
    BOOL isPortNumber = [CallingUtils isNumber:portStr];
    if (!isPortNumber) {
        [CallingUtils showAlertWithTitle:@"配置错误" content:@"端口号无效"];
        return;
    }
    NSInteger portValue = [portStr integerValue];
    if (![CallingUtils isValidPort:portValue]) {
        [CallingUtils showAlertWithTitle:@"配置错误" content:@"端口号超出范围"];
        return;
    }
    [SettingInfo sharedInstance].serverIP = ipStr;
    [SettingInfo sharedInstance].port = portStr;
    [SettingInfo sharedInstance].localPort = localPort;
    [[SettingInfo sharedInstance] saveConfigInfo];
    [[eSpaceCCSDK sharedInstance] setHostAddr:ipStr withPort:portValue withCard:@"" localPort:localPort];
    [self goBackAction];
}

-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self.view endEditing:YES];
}

#pragma mark -
#pragma mark TSAlertView delegate
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (buttonIndex == 0) {
        [self onSaveBtnPressed:nil];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



@end
