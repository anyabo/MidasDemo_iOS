//
//  XNEventDefine.h
//  NiuDataStatistics
//
//  Created by zhangaiwen on 2019/1/18.
//  Copyright © 2019年 zhangaiwen. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int, XNEventPriority) {
    // for Extendibility
    XNEventPriority_ImmediatelyUpload = 1006,
    XNEventPriority_InBatchesUpload = 1007,
};

typedef NS_ENUM(int, NDRunModel) {
    NDRunModel_Release = 1,
    NDRunModel_Debug = 2,
};

typedef NS_ENUM(NSInteger, NDGender) {
    NDGender_Unknow = 0,
    NDGender_Male = 1,
    NDGender_Female = 2,
};

typedef NS_OPTIONS(int, NDHeatBeatType) {
    NDHeatBeatType_None = 0,
    NDHeatBeatType_Foreground = 1, // 仅在前台心跳
    NDHeatBeatType_ForegroundAndBackground = 2, // 前后台都心跳
};

NS_ASSUME_NONNULL_END
