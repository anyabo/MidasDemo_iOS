//
//  XNESGlobalHeader.h
//  EarnSDKFrameworkProject
//
//  Created by user on 2019/11/15.
//  Copyright © 2019 TDF. All rights reserved.
//

#ifndef XNESGlobalHeader_h
#define XNESGlobalHeader_h

//屏幕尺寸问题
#define kScreen         [UIScreen mainScreen].bounds.size
#define kScaleX         kScreen.width/375
#define kStatusHeight   [UIApplication sharedApplication].statusBarFrame.size.height

//判断刘海屏
#define IS_IPHONEX \
({BOOL isPhoneX = NO;\
if (@available(iOS 11.0, *)) {\
isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
}\
(isPhoneX);})

#define kTargetIphoneX              IS_IPHONEX
#define kTargetIphonePlus           ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242,2208), [[UIScreen mainScreen] currentMode].size) : NO)

#define kNavBarHeight               (kTargetIphoneX ? 88 : 64)
#define kStatusBarHeight            (kTargetIphoneX ? 44 : 20)
#define kStatusBarTopMargin         (kTargetIphoneX ? 24 : 0)
#define kTopEstimatedMargin         (kTargetIphoneX ? 30 : 0)

#define kTabBarHeight               (kTargetIphoneX ? 83 : 49)
#define kTabBarBottomMargin         (kTargetIphoneX ? 34 : 0)


//屏幕 宽高
#define kScreenSize         [UIScreen mainScreen].bounds.size
#define kScreenHeight       [UIScreen mainScreen].bounds.size.height
#define kScreenWidth        [UIScreen mainScreen].bounds.size.width
#define kSttOnePointHeight  (1/[UIScreen mainScreen].scale)
#define kScreenSizeMin      MIN(SCREEN_HEIGHT,SCREEN_WIDTH)
#define kScreenSizeMax      MAX(SCREEN_HEIGHT,SCREEN_WIDTH)

//定义颜色的宏
#define kColorFromRGB(rgbValue) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define kAlphaColorWithRGBA(_rgbValue_, _alpha_) [UIColor \
colorWithRed:((float)((_rgbValue_ & 0xFF0000) >> 16))/255.0 \
green:((float)((_rgbValue_ & 0xFF00) >> 8))/255.0 \
blue:((float)(_rgbValue_ & 0xFF))/255.0 alpha:_alpha_]

#define TDFColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
//随机色
#define kRandomColor TDFColor(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))

//弱引用
#define XNBlockSelf __weak typeof(self) weakSelf = self;
//强引用
#define XNBlockStrongSelf __strong typeof(self) strongSelf = weakSelf;

#endif /* XNESGlobalHeader_h */
