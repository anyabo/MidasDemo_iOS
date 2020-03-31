//
//  UIViewController+NDStatistics.h
//  NiuDataSDK
//
//  Created by zhangaiwen on 2019/2/28.
//  Copyright © 2019年 zhangaiwen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XNEventDefine.h"

NS_ASSUME_NONNULL_BEGIN

@protocol NDGetViewPageEventDataDelegate <NSObject>
//页面的唯一id
- (nonnull NSString *)ndpageview_eventCode;
@optional
- (nonnull NSString *)ndpageview_eventName;
- (XNEventPriority)ndpageview_eventPriority;
- (nonnull NSDictionary *)ndpageview_eventExtendParameter;

@end

@interface UIViewController (NDStatistics)

/**
 * @abstract
 * 标记开始浏览页面
 */
- (void)nd_StartViewPage;

/**
 * @abstract
 * 获取标记开始浏览页面时间点
 */
-(NSDate *)nd_viewPageStartTime;

/**
 * @abstract
 * 标记开始浏览页面
 *
 * @param getEventDataObj 符合id<NDGetViewPageEventDataDelegate>的对象，通过这个对象获得相应的事件数据
 */
- (void)nd_EndViewPage:(id<NDGetViewPageEventDataDelegate>)getEventDataObj;

/*
 * @abstract
 * 自定义viewContoller需要重写 override 这个方法！！！
 * App进入后台时，牛数SDK会从这个方法返回值获取遵循<NDGetViewPageDataDelegate>协议的对象
 * 并通过这个对象在APP enter background时获取end view page的事件数据
 *
 * @return 遵循<NDGetViewPageDataDelegate>协议的对象
 *
 */
- (id<NDGetViewPageEventDataDelegate>)getRecordEndViewPageWhenAppEnterBackground;
@end

NS_ASSUME_NONNULL_END
