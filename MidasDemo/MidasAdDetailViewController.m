//
//  MidasAdDetailViewController.m
//  MidasDemo
//
//  Created by CarlsonLee on 2019/12/31.
//  Copyright © 2019 CarlsonLee. All rights reserved.
//

#import "MidasAdDetailViewController.h"
#import "MidasGlobalHeader.h"
#import "XNWInterAdView.h"
#import "MBProgressHUD+JDragon.h"

@interface MidasAdDetailViewController ()<UITableViewDelegate, UITableViewDataSource>
{
    NSString *_positionId;
    UITextView *_textView;
}
@property (nonatomic, weak) UITextField *textField1;
@property (nonatomic, weak) UITableView *tableView;
@property (nonatomic, strong) NSMutableArray *datas;

@end

static NSString *MidasAdDetailTableViewCell = @"MidasAdDetailTableViewCell";
@implementation MidasAdDetailViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = self.params[@"title"];
    
    [self midas_initSubviews];
}

- (void)midas_initSubviews
{
    self.datas = @[].mutableCopy;
    
    //广告
    UIView *view1 = [self creatAdView:CGRectMake(0, kNavBarHeight, kScreen.width, kScreen.height-kNavBarHeight-80)];
    [self.view addSubview:view1];

    //功能区域View
    UIView *view3 = [self creatFuncView:CGRectMake(0, kScreen.height-80, kScreen.width, 80)];
    [self.view addSubview:view3];
}

//广告view
- (UIView *)creatAdView:(CGRect)rect
{
    CGSize size = rect.size;
    UIView *view = [[UIView alloc] initWithFrame:rect];
    UITextField *textField1 = [[UITextField alloc] initWithFrame:CGRectMake(10, 10, size.width-20, 40)];
    textField1.textColor = kColorFromRGB(0x222222);
    textField1.font = [UIFont systemFontOfSize:14];
    textField1.tintColor = kColorFromRGB(0x4D7BFF);
    textField1.keyboardType = UIKeyboardTypeDefault;
    textField1.clearButtonMode = UITextFieldViewModeWhileEditing;
    textField1.keyboardType = UIKeyboardTypeNumberPad;
    textField1.placeholder = @"广告位位ID";
    textField1.layer.cornerRadius = 5.0;
    textField1.layer.borderWidth = 1.0;
    textField1.layer.borderColor = kColorFromRGB(0xeeeeee).CGColor;
    textField1.text = self.params[@"positionId"];
    [view addSubview:textField1];
    self.textField1 = textField1;
    
    UITableView *tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(textField1.frame)+10, size.width, size.height-CGRectGetMaxY(textField1.frame)-10) style:UITableViewStylePlain];
    tableView.delegate = self;
    tableView.dataSource = self;
    [tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:MidasAdDetailTableViewCell];
    [view addSubview:tableView];
    self.tableView = tableView;
    
    return view;
}

//功能区域View
- (UIView *)creatFuncView:(CGRect)rect
{
    NSArray *funcs = @[@"预加载", @"展示广告"];
    UIView *view =  [[UIView alloc] initWithFrame:rect];
    view.backgroundColor = kColorFromRGB(0xffffff);
    CGSize size = rect.size;
    CGSize btnSize = CGSizeMake((size.width-(funcs.count-1)*2)/funcs.count, size.height-2);
    for (int i=0; i<funcs.count; i++){
        UIButton *button = [[UIButton alloc] initWithFrame:CGRectMake((btnSize.width+2)*i, 2, btnSize.width, btnSize.height)];
        button.tag = i;
        [button setBackgroundColor:kColorFromRGB(0xf0f0f0)];
        [button setTitle:funcs[i] forState:UIControlStateNormal];
        [button setTitleColor:kColorFromRGB(0x333333) forState:UIControlStateNormal];
        [button addTarget:self action:@selector(btnLoadAd:) forControlEvents:UIControlEventTouchUpInside];
        [view addSubview:button];
    }
    return view;
}


- (void)btnLoadAd:(UIButton *)btn
{
    switch (btn.tag) {
        case 0:{//缓存广告
            [self loadAd:YES];
        }
            break;
        case 1:{//展示广告
            [self loadAd:NO];
        }
            break;
        default:
            break;
    }
}


#pragma mark - 广告请求
- (void)loadAd:(BOOL)isCache
{
    //初始化一个请求体
    MidasAdReq *adReq = [MidasAdReq new];
    //当前次请求是展示还是缓存
    adReq.needCache = isCache;
    //positionId决定请求类型
    adReq.positionId = self.textField1.text;
    //原生广告和自渲染广告可设置数量
    adReq.count = 1;
    
    __weak typeof(self) wSelf = self;
    BOOL isVaild = YES;
    [MBProgressHUD hideHUD];
    if(![MidasAdSDKManager adIsReadyWithPosition:adReq.positionId]){
        isVaild = NO;
        [MBProgressHUD showTipMessageInWindow:@"视频广告未加载完"];
    }
    if(isVaild){
        [MidasAdSDKManager loadMidasAdWithReq:adReq completion:^(MidasAdRes *adRes, NSError *error) {
            if(error){
                //输出错误
            }else{
                [wSelf handleNativeAds:adRes];
            }
        }];
    }
}

#pragma mark - 处理广告
- (void)handleNativeAds:(MidasAdRes *)adRes
{
    if(adRes.adType == MidasADReqTypeFeed){
        //原生广告
        if (adRes.adState == MidasADReqStateRenderSuccess){//渲染成功
            [self.datas removeAllObjects];
            [self.datas addObjectsFromArray:adRes.adViews];
            [self.tableView reloadData];
        }else if (adRes.adState == MidasADReqStateClose){//点击不喜欢广告
            [self.datas removeAllObjects];
            [self.tableView reloadData];
        }
    }else if (adRes.adType == MidasADReqTypeNativeAds){
        //自渲染广告
        if(adRes.adState==MidasADReqStateData){
            [self.datas removeAllObjects];
            for(int i=0; i<adRes.adDatas.count; i++){
                MidasAdDataObject *adObject = adRes.adDatas[i];
                CGFloat h = (kScreen.width-20)/adObject.mediaRatio+70;
                XNWInterAdView *adView = [[XNWInterAdView alloc] initWithFrame:CGRectMake(10, 0, kScreen.width-20, h)];
                [adView loadNativeAdObj:adObject];
                [self.datas addObject:adView];
            }
            [self.tableView reloadData];
        }
    }else if (adRes.adType == MidasADReqTypeBanner){
        //banner广告
        if(adRes.adState==MidasADReqStateData){//加载到数据
            [self.datas removeAllObjects];
            [self.datas addObject:adRes.adViews[0]];
            [self.tableView reloadData];
        }else if (adRes.adState==MidasADReqStateClose){
            [self.datas removeAllObjects];
            [self.tableView reloadData];
        }
    }else if (adRes.adType == MidasADReqTypeFloat){
        //互动广告悬浮
        UIView *adView = adRes.adViews[0];
        CGRect rect = CGRectMake(kScreen.width-100, 0, 50, 50);
        adView.frame = rect;
        [self.datas removeAllObjects];
        [self.datas addObject:adView];
        [self.tableView reloadData];
    }
}

#pragma mark - TableViewDelegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.datas.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UIView *view = self.datas[indexPath.row];
    return view.bounds.size.height;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:MidasAdDetailTableViewCell];
    UIView *subView = (UIView *)[cell.contentView viewWithTag:1000];
    if ([subView superview]) {
        [subView removeFromSuperview];
    }
    UIView *view = self.datas[indexPath.row];
    view.tag = 1000;
    [cell.contentView addSubview:view];
    return cell;
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    [self.view endEditing:YES];
}

- (NSString *)adStateWithType:(MidasADReqState)type
{
    NSString *stateStr = @"未知状态";
    switch (type) {
        case MidasADReqStateData:{
            stateStr = @"获取到广告数据";
        }
            break;
        case MidasADReqStateRenderSuccess:{
            stateStr = @"广告渲染成功";
        }
            break;
        case MidasADReqStateDataFail:{
            stateStr = @"广告加载失败";
        }
            break;
        case MidasADReqStateShow:{
            stateStr = @"广告曝光";
        }
            break;
        case MidasADReqStateClick:{
            stateStr = @"广告点击";
        }
            break;
        case MidasADReqStateReward:{
            stateStr = @"激励视频达到激励条件";
        }
            break;
        case MidasADReqStateSkip:{
            stateStr = @"全屏视频跳过";
        }
            break;
        case MidasADReqStateClose:{
            stateStr = @"广告关闭";
        }
            break;
        default:
            break;
    }
    return stateStr;
}

- (NSString *)adStrWithType:(MidasADReqType)type
{
    NSString *adStr = @"广告";
    switch (type) {
        case MidasADReqTypeNone:{
            adStr = @"获取到广告数据";
        }
            break;
        case MidasADReqTypeSplash:{
            adStr = @"开屏广告";
        }
            break;
        case MidasADReqTypeNativeAds:{
            adStr = @"自渲染广告";
        }
            break;
        case MidasADReqTypeBanner:{
            adStr = @"banner广告";
        }
            break;
        case MidasADReqTypeFullScreenVideo:{
            adStr = @"全屏视频广告";
        }
            break;
        case MidasADReqTypeRewardedVideo:{
            adStr = @"激励视频广告";
        }
            break;
        case MidasADReqTypeInterstitial:{
            adStr = @"插屏广告";
        }
            break;
        case MidasADReqTypeFeed:{
            adStr = @"原生广告";
        }
            break;
        default:
            break;
    }
    return adStr;
}

@end
