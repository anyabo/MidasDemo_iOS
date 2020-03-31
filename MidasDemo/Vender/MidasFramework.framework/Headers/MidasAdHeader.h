//
//  MidasAdHeader.h
//  XNWalkerLove
//
//  Created by  CarlsonLee on 2019/10/16.
//  Copyright © 2019 YANJING. All rights reserved.
//

#ifndef MidasAdHeader_h
#define MidasAdHeader_h
//环境
typedef NS_ENUM(NSInteger, MidasEnvType){
    MidasEnvTypeTest = 1,//测试
    MidasEnvTypeDis//生产
};

//广告源
typedef NS_ENUM(NSInteger, MidasADSource){
    MidasADSourceNone = 0,
    MidasADSourceByteDance,//穿山甲
    MidasADSourceGDT,//优量汇
    MidasAdSourceMintegral,//Mintegral
    MidasAdSourceMeishu,//美数
    MidasADSourceTuia,//推啊
    MidasADSourceInmobi,
};

//广告类型
typedef NS_ENUM(NSInteger, MidasADReqType){
    MidasADReqTypeNone,//无此类型
    MidasADReqTypeSplash,//开屏广告
    MidasADReqTypeNativeAds,//自渲染
    MidasADReqTypeBanner,//模板banner
    MidasADReqTypeFullScreenVideo,//模板全屏视频
    MidasADReqTypeRewardedVideo,//模板激励视频
    MidasADReqTypeInterstitial,//模板插屏
    MidasADReqTypeFeed,//模板原生信息流广告
    MidasADReqTypeFloat,//互动广告悬浮
};

//广告请求状态
typedef NS_ENUM(NSInteger, MidasADReqState){
    MidasADReqStateNone,//初始状态
    MidasADReqStateData = 1,//获取到广告数据
    MidasADReqStateRenderSuccess,//广告渲染成功
    MidasADReqStateDataFail,//广告加载失败
    MidasADReqStateShow,//广告曝光
    MidasADReqStateClick,//广告点击
    MidasADReqStateReward,//激励广告达到激励条件
    MidasADReqStateSkip,//全屏视频跳过
    MidasADReqStateClose,//点击关闭
};

@class MidasAdBaseObject;
@class MidasAdRes;
typedef void(^MidasAdShowBlock)(MidasAdRes *ad, NSError *error);//展示回调
typedef void(^MidasAdRequestBlock)(MidasAdBaseObject *adObj, MidasADReqState adState, NSError *error);//请求回调
#endif /* MidasAdHeader_h */
