//
//  MidasAdDataObject.h
//  MidasFramework
//
//  Created by CarlsonLee on 2019/12/24.
//  Copyright © 2019 CarlsonLee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MidasCreativeType){
    MidasCreativeTypeVideo = 9, // 视频
    MidasCreativeTypeSmallImage = 10, // 小图
    MidasCreativeTypeLargeImage = 11, // 大图
    MidasCreativeTypeThreeImage = 12, // 三图
};

@interface MidasAdDataObject : NSObject

/**
 * 广告标题
 */
@property (nonatomic, copy) NSString *title;

/**
 * 广告描述
 */
@property (nonatomic, copy) NSString *desc;

/**
 * 广告图片Url
 */
@property (nonatomic, copy) NSString *imageUrl;

/**
 * 广告icon 图标
 */
@property (nonatomic, copy) NSString *iconUrl;

/**
 * icon大小
 */
@property (nonatomic, assign) CGSize iconSize;

/**
 * 广告icon
 */
@property (nonatomic, strong) UIImage *iconImage;

/**
 * 媒体资源宽高比
 */
@property (nonatomic, assign) CGFloat mediaRatio;

/**
 * 媒体创意类型
 */
@property (nonatomic, assign) MidasCreativeType creativeType;

/**
 * 是否是下载类型
 */
@property (nonatomic, assign) BOOL isAppDownload;

/**
 * 注册需要点击回调的视图
*/
- (void)registContainer:(UIView *)containerView mediaView:(UIView *)view;


@end

NS_ASSUME_NONNULL_END
