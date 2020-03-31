//
//  MidasAdSDKManager.h
//  MidasFramework
//
//  Created by CarlsonLee on 2019/12/24.
//  Copyright © 2019 CarlsonLee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MidasAdHeader.h"
#import "MidasAdReq.h"

NS_ASSUME_NONNULL_BEGIN

@interface MidasAdSDKManager : NSObject

/**
 * APP的唯一标识
 */
+ (NSString *)appId;

/**
 * 获取SDK版本
 */
+ (NSString *)sdkVersion;


/**
  Midas初始化方法
  @param appId  Midas应用ID
  @param productId 大数据业务线ID
  @param serverUrl 大数据埋点地址
 */
+ (void)registAppId:(NSString *)appId productId:(NSString *)productId bdServerUrl:(NSString *)serverUrl;

/**
 根据消息体展示对应的广告
 @param req 请求的消息体
 @param completion 广告结果回调
 */
+ (void)loadMidasAdWithReq:(MidasAdReq *)req completion:(MidasAdShowBlock)completion;

/**
 * 当前广告位视频是否缓存好
 */
+ (BOOL)adIsReadyWithPosition:(NSString *)position;

//日志
+ (void)logFloatEnable:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
