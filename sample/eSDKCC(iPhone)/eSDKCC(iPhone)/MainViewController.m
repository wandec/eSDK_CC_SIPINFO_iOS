//
//  MainViewController.m
//  eSpaceCCDemo
//
//  Created by gaoshuming on 15/11/23.
//  Copyright © 2015年 gaoshuming. All rights reserved.
//

#import "MainViewController.h"
#import "SettingViewController.h"
#import "eSpaceCCSDK.h"
#import "CallingView.h"
#import "VTMCommonDefine.h"
#import "VTMNotificationsDefine.h"
#import "SettingInfo.h"
#import "CallingUtils.h"
#import "AppDelegate.h"
#import "Reachability.h"


#define SCREEN_WIDTH self.view.frame.size.width
#define SCREEN_HEIGHT self.view.frame.size.height


@interface MainViewController ()<CallingViewDelegate>
@property (strong, nonatomic) IBOutlet UITextField *accessCodeText;
@property (strong, nonatomic) IBOutlet UITextField *messageText;
@property (strong, nonatomic) IBOutlet UIButton *anonymousBtn;
@property (strong, nonatomic) IBOutlet UIButton *messageBtn;

@property (strong, nonatomic) IBOutlet UITextView *logText;
@property (nonatomic,strong) CallingView *callView;
@property (nonatomic,strong)UIBarButtonItem *rightBarButtonItem;
@property (strong, nonatomic) IBOutlet UIButton *closeCallBtn;
@property (nonatomic,strong) NSTimer *callingTimer;
@property (nonatomic,assign)long int secondsTotal;//呼叫时长

- (IBAction)anonymousCallPress:(id)sender;

- (IBAction)sendMessagePress:(id)sender;
- (IBAction)closeCallPress:(id)sender;

@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setWithNavigation];
    
    [[eSpaceCCSDK sharedInstance] setLogSwitch:YES];
    self.callView = [[CallingView alloc]init];
    self.callView.delegate = self;
    self.callView.frame = CGRectMake(0, 0, SCREEN_HEIGHT/2 -30, SCREEN_WIDTH);
    self.callView.callStateImage.frame = CGRectMake(SCREEN_HEIGHT/4-20, SCREEN_HEIGHT/4, 100, 100);
    self.callView.closeBtn.frame = CGRectMake(SCREEN_HEIGHT/4-20, SCREEN_HEIGHT/2-20, 100, 40);
    self.accessCodeText.text = [SettingInfo sharedInstance].accessCode;
    self.messageBtn.enabled = NO;
    self.messageBtn.backgroundColor = [UIColor grayColor];
    //拒绝文本下移
    self.automaticallyAdjustsScrollViewInsets = NO;
    
    self.closeCallBtn.enabled = NO;
    self.closeCallBtn.backgroundColor = [UIColor grayColor];
    self.secondsTotal = 0;
}

-(void)setWithNavigation
{
    self.anonymousBtn.clipsToBounds = YES;
    self.anonymousBtn.layer.cornerRadius = 8;
    self.messageBtn.clipsToBounds = YES;
    self.messageBtn.layer.cornerRadius = 8;
    self.closeCallBtn.clipsToBounds = YES;
    self.closeCallBtn.layer.cornerRadius = 8;
}

- (void)startTimer{
    //实时刷新通话时间和网络信号状态
    self.callingTimer = [NSTimer scheduledTimerWithTimeInterval:1
                                                         target:self
                                                       selector:@selector(callingTimesCount)
                                                       userInfo:nil
                                                        repeats:YES];
    //保证有拖拽动作时仍在计时
    [[NSRunLoop currentRunLoop] addTimer:self.callingTimer forMode:UITrackingRunLoopMode];
}

-(void)callingTimesCount
{
    //计算时间
    self.secondsTotal ++;
    int secondsValue = (self.secondsTotal % 60);
    NSLog(@"secondsValue:%d",secondsValue);
    if (secondsValue > 30)
    {
        [self closeCall];
    }
    
    if ([self isCurrentReachableViaWiFi])
    {
        [self closeCall];
    }
}

-(void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    if (self.navigationController)
    {
        _rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"设置" style:UIBarButtonItemStylePlain target:self action:@selector(onSettingBtnPressed:)];
        self.navigationItem.rightBarButtonItem = _rightBarButtonItem;
    }
    [self addNotifications];
    
}

-(void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    
    [self.callingTimer invalidate];
    self.callingTimer = nil;
}

-(void)viewDidUnload
{
    self.callView = nil;
    self.callView.callStateImage = nil;
    self.callView.closeBtn = nil;
    self.logText = nil;
    self.messageText = nil;
    self.secondsTotal = 0;
    [[UIApplication sharedApplication] endReceivingRemoteControlEvents];
    [super viewDidUnload];
}

-(void)addNotifications
{
    //发起呼叫请求
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(startCalling:) name:STARTCALL_RESULT object:nil];
    
    //收到语音消息
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(showMessageText:) name:RECEIVE_CALL_MESSAGE object:nil];
    
    //通话结束
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(callingClosing:) name:CALL_ENDED object:nil];
    
    //语音建立
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(callRingBack:) name:CALL_RINGBACK object:nil];
    
    //接收发送SIP消息后回调消息
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(receiveSipInfoCallBack:) name:SIP_INFO_RECEIVE_NOTIFY object:nil];
    
    //隐藏键盘
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleKeyBoardHide:) name:UIKeyboardWillHideNotification object:nil];
    
    //显示键盘
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleKeyBoardShow:) name:UIKeyboardWillShowNotification object:nil];
}

#pragma mark - 通知方法

-(void)callRingBack:(NSNotification *)notify
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showLogText:@"call ring back"];
        [self closeCallingView];
        _rightBarButtonItem.enabled = NO;
        
        self.closeCallBtn.enabled = YES;
        self.closeCallBtn.backgroundColor = [UIColor whiteColor];
    });
}

-(void)startCalling:(NSNotification *)notify
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showLogText:@"start call event"];
        _rightBarButtonItem.enabled = NO;
    });
}
-(void)showMessageText:(NSNotification *)notify
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showLogText:@"receive audio message"];
        [self closeCallingView];
        self.messageBtn.enabled = YES;
        self.messageBtn.backgroundColor = [UIColor whiteColor];
        _rightBarButtonItem.enabled = NO;
        
        self.closeCallBtn.enabled = YES;
        self.closeCallBtn.backgroundColor = [UIColor whiteColor];
    });
}

-(void)callingClosing:(NSNotification *)notify
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showLogText:@"call close"];
        [self closeCallingView];
        self.messageBtn.enabled = NO;
        self.messageBtn.backgroundColor = [UIColor grayColor];
        _rightBarButtonItem.enabled = YES;
        
        self.closeCallBtn.enabled = NO;
        self.closeCallBtn.backgroundColor = [UIColor grayColor];
        
        [self.callingTimer invalidate];
        self.callingTimer = nil;
        
        self.secondsTotal = 0;
    });
}

-(void)receiveSipInfoCallBack:(NSNotification *)notify
{
    NSDictionary *userDic = [notify userInfo];
    NSString *messageContent = [userDic objectForKey:SIP_INFO_CONTENT];
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showLogText:[NSString stringWithFormat:@"receive message:%@ successfully",messageContent]];
    });
}

-(void)releaseCallingNotify:(NSNotification *)notify
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showLogText:@"release calling "];
        [self closeCall];
        self.messageBtn.enabled = NO;
        self.messageBtn.backgroundColor = [UIColor grayColor];
        _rightBarButtonItem.enabled = YES;
        
        self.closeCallBtn.enabled = NO;
        self.messageBtn.backgroundColor = [UIColor grayColor];
    });
}

#pragma mark - 键盘通知
-(void)handleKeyBoardShow:(NSNotification *)notify
{
    NSDictionary *userInfo = [notify userInfo];
    NSNumber *duration = userInfo[UIKeyboardAnimationDurationUserInfoKey];
    [UIView animateWithDuration:[duration doubleValue] animations:^{
        self.view.frame = CGRectMake(0,-60, SCREEN_WIDTH, SCREEN_HEIGHT);
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


-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self closeCallingView];
    [self.view endEditing:YES];
}

-(void)onSettingBtnPressed:(id)sender
{
    [self.view endEditing:YES];
    SettingViewController *settingVC = [[SettingViewController alloc]initWithNibName:@"SettingViewController" bundle:nil];
    if (self.navigationController)
    {
        [[AppDelegate appDelegate].navigationVC pushViewController:settingVC animated:YES];
    }
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)anonymousCallPress:(id)sender
{
    [self checkIfInWifiOrNot];
}

- (IBAction)sendMessagePress:(id)sender
{
    [self.view endEditing:YES];
    short ret = [[eSpaceCCSDK sharedInstance] sendMessageWithMediaType:@"text" subType:@"xml" body:self.messageText.text];
    NSLog(@"ret-------:%d",ret);
    if ([self.messageText.text length] == 0) {
        [CallingUtils showAlertWithTitle:@"失败" content:@"发送消息不能为空！"];
    }
    if (RET_OK == ret && [self.messageText.text length]>0)
    {
        [self showLogText:[NSString stringWithFormat:@"send message :%@",self.messageText.text]];
    }
    else
    {
        [self showLogText:@"发送消息失败"];
    }
}

- (IBAction)closeCallPress:(id)sender
{
    [self closeCall];
    self.closeCallBtn.enabled = NO;
    self.messageBtn.backgroundColor = [UIColor grayColor];
}

-(void)showCallingMode
{
    [self.view addSubview:self.callView];
    [self.callView startAnimation];
}

#pragma mark - delegate
- (void)closeCall
{
    [[eSpaceCCSDK sharedInstance] releaseCall];
    [self closeCallingView];
}

-(void)closeCallingView
{
    [self.callView stopAnimation];
    [self.callView removeFromSuperview];
}

-(void)showLogText:(NSString *)logText
{
    NSString *logStr = [NSString stringWithString:self.logText.text];
    
    if ([logStr length] > 400 )
    {
        logStr = @"";
    }
    
    NSDate *nowDate = [NSDate date];
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    dateFormatter.dateFormat = @"yyyy-MM-dd HH:mm:ss";
    NSString *nowDateStr = [dateFormatter stringFromDate:nowDate];
    NSString *newLogStr =  [NSString stringWithFormat:@"%@[%@] %@\r\n",logStr,nowDateStr,logText];
    
    self.logText.text = newLogStr;
}

#pragma mark - 监测网络环境
- (BOOL)isCurrentReachableViaWiFi
{
    NetworkStatus netStatus = [[Reachability reachabilityForInternetConnection] currentReachabilityStatus];
    return netStatus == NotReachable;
}
-(void)checkIfInWifiOrNot
{
    if ([self isCurrentReachableViaWiFi])
    {
        [CallingUtils showAlertWithTitle:@"提示" content:@"当前网络没有连接！"];
        return;
    }
    else
    {
        [self.accessCodeText resignFirstResponder];
        NSString *called = [[self.accessCodeText text] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
        
        if ([called length] == 0) {
            [CallingUtils showAlertWithTitle:@"配置错误" content:@"呼叫码不能为空"];
            return;
        }
        else
        {
            short callRet = RET_COMMON_EEROR;
            callRet = [[eSpaceCCSDK sharedInstance] anonymousCallWithAccessCode:self.accessCodeText.text];
            if (RET_OK == callRet)
            {
                [self startTimer];
                if (![called isEqualToString:[SettingInfo sharedInstance].accessCode])
                {
                    [SettingInfo sharedInstance].accessCode = called;
                    [[SettingInfo sharedInstance] saveConfigInfo];
                }
                [self showLogText:@"send request successfully ,please wait response"];
                [self showCallingMode];
            }
            else if (callRet == RET_STATUS_ERROR)
            {
                [self showLogText:@"send call request failed, check login status or voip status"];
                UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"提示" message:@"呼叫失败" delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil, nil];
                [alert show];
            }
            else
            {
                [self showLogText:@"send call request failed, check network config please"];
                UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"提示" message:@"呼叫失败" delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil, nil];
                [alert show];
            }
        }
    }
}

@end
