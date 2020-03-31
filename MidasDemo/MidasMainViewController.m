//
//  MidasBaseViewController.m
//  MidasDemo
//
//  Created by CarlsonLee on 2019/12/23.
//  Copyright © 2019 CarlsonLee. All rights reserved.
//

#import "MidasMainViewController.h"
#import <MidasFramework/MidasFramework.h>
#import "MidasAdDetailViewController.h"

@interface MidasMainViewController ()<UITableViewDelegate, UITableViewDataSource>
{
    NSArray *_demoArray;
}
@end

static NSString * const kMidasMainTableViewCellIndentify = @"kMidasMainTableViewCellIndentify";
@implementation MidasMainViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = [NSString stringWithFormat:@"Midas广告 v%@", [MidasAdSDKManager sdkVersion]];
    
       
   _demoArray = @[@{@"title":@"开屏广告", @"positionId":@"4406095701"},
                  @{@"title":@"激励视频广告", @"positionId":@"6378460641"},
                  @{@"title":@"原生广告", @"positionId":@"adpos_1750558351"},
                  @{@"title":@"插屏广告", @"positionId":@"9956956621"},
                  @{@"title":@"全屏视频广告", @"positionId":@"1770259631"},
                  @{@"title":@"自渲染广告", @"positionId":@"adpos_7902746561"},
                  @{@"title":@"banner广告", @"positionId":@"adpos_5338639311"},
                  @{@"title":@"推啊互动悬浮广告", @"positionId":@"adpos_4200862971"}];
                    
    [self midas_initSubviews];
}

- (void)midas_initSubviews
{
    UITableView *table = [[UITableView alloc] initWithFrame:[UIScreen mainScreen].bounds];
    table.delegate = self;
    table.dataSource = self;
    [table registerClass:[UITableViewCell class] forCellReuseIdentifier:kMidasMainTableViewCellIndentify];
    table.tableFooterView = [UIView new];
    [self.view addSubview:table];
}

#pragma mark - TableViewDelegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return _demoArray.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 50;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:kMidasMainTableViewCellIndentify];
    cell.textLabel.text = _demoArray[indexPath.row][@"title"];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    MidasADReqType reqType = MidasADReqTypeNone;
    switch (indexPath.row) {
        case 0:{
            reqType = MidasADReqTypeSplash;
        }
            break;
        case 1:{
            reqType = MidasADReqTypeRewardedVideo;
        }
            break;
        case 2:{
            reqType = MidasADReqTypeFeed;
        }
            break;
        case 3:{
            reqType = MidasADReqTypeInterstitial;
        }
            break;
        case 4:{
            reqType = MidasADReqTypeFullScreenVideo;
        }
            break;
        case 5:{
            reqType = MidasADReqTypeNativeAds;
        }
            break;
        case 6:{
            reqType = MidasADReqTypeBanner;
        }
            break;
        case 7:{
            reqType = MidasADReqTypeFloat;
        }
        default:
            break;
    }
    MidasAdDetailViewController *detail = [MidasAdDetailViewController new];
    detail.type = reqType;
    detail.params = _demoArray[indexPath.row];
    [self.navigationController pushViewController:detail animated:YES];
}

@end
