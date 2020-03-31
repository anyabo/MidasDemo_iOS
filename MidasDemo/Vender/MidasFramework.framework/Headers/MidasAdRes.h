//
//  MidasAd.h
//  MidasFramework
//
//  Created by CarlsonLee on 2019/12/24.
//  Copyright © 2019 CarlsonLee. All rights reserved.
//  

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MidasAdHeader.h"
#import "MidasAdDataObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface MidasAdRes : NSObject

/**
 * 广告类型
 */
@property (nonatomic, assign) MidasADReqType adType;

/**
 * 广告请求状态
 */
@property (nonatomic, assign) MidasADReqState adState;

/**
 * 视图广告数据对象
 */
@property (nonatomic, strong) NSArray *adViews;

/**
 * 自渲染广告数据对象
 */
@property (nonatomic, strong) NSArray<MidasAdDataObject *> *adDatas;

@end

NS_ASSUME_NONNULL_END
