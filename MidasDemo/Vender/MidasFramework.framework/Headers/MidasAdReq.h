//
//  MidasAdReq.h
//  MidasFramework
//
//  Created by CarlsonLee on 2019/12/27.
//  Copyright © 2019 CarlsonLee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 广告请求体，抽象层，请求广告需要实例化对应类型的子类对象
 */
@interface MidasAdReq : NSObject

/**
 * 广告位置ID
 */
@property (nonatomic, copy) NSString *positionId;

/**
 * 当前请求是否缓存，YES缓存，NO展示，默认NO
 */
@property (nonatomic, assign) BOOL needCache;

/**
 * 开屏拉取广告超时时间，默认为3秒
 */
@property (nonatomic, assign) NSInteger fetchDelay;

/**
 * banner、插屏可设置大小，模板广告要设置宽
 */
@property (nonatomic, assign) CGSize adSize;

/**
 * 原生信息流、自渲染可设置广告数量，默认1
 */
@property (nonatomic, assign) NSInteger count;

/**
 * 弹出广告详情的控制器，默认keyWindow的rootvc
 */
@property (nonatomic, strong) UIViewController *rootVc;

@end


NS_ASSUME_NONNULL_END
