//
//  AppDelegate.m
//  MidasDemo
//
//  Created by CarlsonLee on 2019/12/23.
//  Copyright © 2019 CarlsonLee. All rights reserved.
//

#import "AppDelegate.h"
#import "MidasMainViewController.h"
#import <MidasFramework/MidasFramework.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    /*sdk中埋点地址
     * 喝水：320002 32
     * http://testaidataprobe2.51huihuahua.com/apis/v1/dataprobe2/dhs
     */
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.rootViewController = [[UINavigationController alloc] initWithRootViewController:[MidasMainViewController new]];
    [self.window makeKeyAndVisible];
    
    NSString *serverUrl = @"http://testaidataprobe2.51huihuahua.com/apis/v1/dataprobe2/dhs";
    //初始化SDK-业务线喝水
    [MidasAdSDKManager registAppId:@"320002" productId:@"32" bdServerUrl:serverUrl];
    //日志
//    [MidasAdSDKManager logFloatEnable:YES];
    
    return YES;
}


- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options{
    
    return NO;
}


@end
