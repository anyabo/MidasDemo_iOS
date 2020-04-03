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
 APP的唯一标识
 */
+ (NSString *)appId;

/**
 获取SDK版本
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
 根据adReq去判断有没有可用广告，如果有直接回调，如果没有，发起新的请求
 @param req 请求体
 @param block 结果回调
*/
+ (void)checkAdStateWithReq:(MidasAdReq *)req block:(void(^)(BOOL isReady, NSString *errStr))block;

/**
 是否支持日志, 若设置YES,则在window层会添加一个悬浮的日志view
 @param enable 默认NO
*/
+ (void)logFloatEnable:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
