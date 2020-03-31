//
//  NiuDataStatistics.h
//  NiuDataStatistics
//
//  Created by zhangaiwen on 2019/1/4.
//  Copyright © 2019年 zhangaiwen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIApplication.h>
#import "XNEventDefine.h"

@protocol NiuDataGetUserInfoProtocol;

@interface NiuDataStatistics : NSObject

/*
 * @param serverURL 事件数据上传的服务器地址
 * @param appID     指定采集的是那个APP数据
 * @param runModel  设置牛数的运行环境/模式
 * @discusstion     设置采集SDK，需要在App did Finish Launching是去设置事件采集的SDK
 */
+ (instancetype _Nonnull )constructSDKWithServerURL:(nonnull NSString *)serverURL appID:(nonnull NSString *)appID runModel:(NDRunModel)runModel;

+ (NiuDataStatistics *_Nullable)sharedInstance;

/**
 * @abstract
 * 获取设置的上传事件数据的severURL
 *
 * @return 事件数据上传的severURL
 */
+ (nonnull NSString *)serverURL;

/**
 * @abstract
 * 获取SDK绑定的APPID
 *
 * @return SDK绑定的APPID
 */
+ (nonnull NSString *)APPID;

/**
 * @abstract
 * 获取SDK版本号
 *
 * @return SDK版本号
 */
+ (nonnull NSString *)SDKVersion;

/**
 * @abstract
 * 设置事件发生的相关的用户的相关信息
 *
 * @param userinfo 遵循<NiuDataGetUserInfoProtocol>协议的Model
 *                 SDK会根据协议的行为获取用户数据
 *
 */
+ (void)setUserInfo:(nullable id<NiuDataGetUserInfoProtocol>)userinfo;

/**
 * @abstract
 * 获取事件发生的相关的用户的相关信息
 *
 * @return 包含用户设置的相关数据
 *
 */
+ (nonnull NSDictionary *)eventUserInfo;

/**
 * @abstract
 * 清除数据一般是在APP用户退登录的时候
 */
+ (void)clearUserInfo;

/**
 * @abstract
 * 获取牛数当情的运行环境/模式
 *
 * @return SDK当前绑定的userid
 */
+ (NDRunModel)runModel;

/**
 * @abstract
 * 用来设置事件的动态自定义公共属性
 *
 * @discussion
 * 当追踪事件时通过`extendParameter`传入数据 、customCommonParameters得到的数据，还有 SDK 自动生成的事件参数有相同的 key 时，遵循如下的优先级：
 *    SDKDefaultProperty > extendParameter > customCommonParameters
 *
 * 例如，SDKDefaultProperty 是 @{@"p1":1, @"p2": "aaa"}，返回的 customCommonParameters 是 @{@"p2": 123, @"p3": @"asd"}，
 * extendParameter 是  @{@"p1":3, @"p2": "ccc", @"c":@"ccc"}
 * 则 merge 后的结果是 @{"p1":1, @"p2": "bbb", @"c": @"asd", @"d":@"ddd"}
 * 返回的 NSDictionary 需满足以下要求
 * 注意： event扩展自定义数据。但对扩展数据做了一定的限制
 *       是字典类型，以键值(key-value)对的形式组织数据
 *       key(键) - 必须是`NSString`类型，如果与牛数的默认字段
 *       冲突，牛数会覆盖extendParameter中相应的value；
 *       value(值) - 只支持 NSString、NSNumber、NSSet、NSArray、NSDictionary、NSDate 这些类型。
 *       其中牛数会过滤掉NSSet、NSArray中非NSString和NSNumber元素。
 *
 * @param customCommonParameters block 用来返回事件的自定义公共属性
 */
+ (void)registerCustomCommonParameters:(NSDictionary<NSString *,id> *_Nonnull(^ _Nullable)(void))customCommonParameters;

/**
 * @abstract
 * 牛数SDK激活事件对外的回调
 *
 * @discussion
 * 当 牛数SDK激活事件上传时开始调用激活时间
*/
+ (void)registerCustomActiveCallBack:(void(^ _Nullable)(void))customActiveCallBack;

/**
 * @abstract
 * 上传点击事件数据
 *
 * @param eventCode 事件唯一代码
 * @param eventName 事件描述名称
 * @param priority  事件优先级
 * @param extendParameter event扩展自定义数据。但对扩展数据做了一定的限制
 *                        是字典类型，以键值(key-value)对的形式组织数据
 *                        key(键) - 必须是`NSString`类型，如果与牛数的默认字段
 *                        冲突，牛数会覆盖extendParameter中相应的value；
 *                        value(值) - 只支持 NSString、NSNumber、NSSet、NSArray、NSDictionary、NSDate 这些类型。
 *                        其中牛数会过滤掉NSSet、NSArray中非NSString和NSNumber元素。
 *
 */
+ (void)clickWtihCode:(nonnull NSString *)eventCode
            eventName:(nonnull NSString *)eventName
             priority:(XNEventPriority)priority
      extendParameter:(nullable NSDictionary *)extendParameter;


/**
 * @abstract
 * 上传点eventType为“ad_process”事件件数据
 *
 * @param eventCode 事件唯一代码
 * @param eventName 事件描述名称
 * @param priority  事件优先级
 * @param extendParameter event扩展自定义数据。但对扩展数据做了一定的限制
 *                        是字典类型，以键值(key-value)对的形式组织数据
 *                        key(键) - 必须是`NSString`类型，如果与牛数的默认字段
 *                        冲突，牛数会覆盖extendParameter中相应的value；
 *                        value(值) - 只支持 NSString、NSNumber、NSSet、NSArray、NSDictionary、NSDate 这些类型。
 *                        其中牛数会过滤掉NSSet、NSArray中非NSString和NSNumber元素。
 *
 */
+ (void)adProcessWtihCode:(nonnull NSString *)eventCode
                eventName:(nonnull NSString *)eventName
                 priority:(XNEventPriority)priority
          extendParameter:(nullable NSDictionary *)extendParameter;

/**
 * @abstract
 * 上传浏览时事件数据
 *
 * @param eventCode 事件唯一代码
 * @param eventName 事件描述名称
 * @param startViewDate  开始浏览页面时间
 * @param priority 事件优先级 立即上传/批次上传
 * @param extendParameter event扩展自定义数据。但对扩展数据做了一定的限制
 *                        是字典类型，以键值(key-value)对的形式组织数据
 *                        key(键) - 必须是`NSString`类型，如果与牛数的默认字段
 *                        冲突，牛数会覆盖extendParameter中相应的value；
 *                        value(值) - 只支持 NSString、NSNumber、NSSet、NSArray、NSDictionary、NSDate 这些类型。
 *                        其中牛数会过滤掉NSSet、NSArray中非NSString和NSNumber元素。
 *
 */
+ (void)endViewPageWtihCode:(nonnull NSString *)eventCode
                  eventName:(nonnull NSString *)eventName
              startViewDate:(nullable NSDate *)startViewDate
                   priority:(XNEventPriority)priority
            extendParameter:(nullable NSDictionary *)extendParameter;


/**
 * @abstract
 * 上传自定义事件
 *
 * @param eventCode 事件唯一代码
 * @param eventName 事件描述名称
 * @param priority 事件优先级 立即上传/批次上传
 * @param extendParameter event扩展自定义数据。但对扩展数据做了一定的限制
 *                        是字典类型，以键值(key-value)对的形式组织数据
 *                        key(键) - 必须是`NSString`类型，如果与牛数的默认字段
 *                        冲突，牛数会覆盖extendParameter中相应的value；
 *                        value(值) - 只支持 NSString、NSNumber、NSSet、NSArray、NSDate 这些类型。
 *                        其中牛数会过滤掉NSSet、NSArray中非NSString和NSNumber元素。
 *
 */
+ (void)customWtihCode:(nonnull NSString *)eventCode
             eventName:(nonnull NSString *)eventName
              priority:(XNEventPriority)priority
       extendParameter:(nullable NSDictionary *)extendParameter;

/**
 * @abstract
 * 上传H5中的点击事件数据
 *
 * @param eventCode 事件唯一代码
 * @param eventName 事件描述名称
 * @param priority  事件优先级
 * @param extendParameter event扩展自定义数据。但对扩展数据做了一定的限制
 *                        是字典类型，以键值(key-value)对的形式组织数据
 *                        key(键) - 必须是`NSString`类型，如果与牛数的默认字段
 *                        冲突，牛数会覆盖extendParameter中相应的value；
 *                        value(值) - 只支持 NSString、NSNumber、NSSet、NSArray、NSDate 这些类型。
 *                        其中牛数会过滤掉NSSet、NSArray中非NSString和NSNumber元素。
 *
 * @discusstion 这个API与 `+ clickWtihCode:eventName:priority:extendParameter:`区别就是：
 *                       会在"page_type"字段中传"h5"
 *
 */
+ (void)clickInH5WtihCode:(nonnull NSString *)eventCode
                eventName:(nonnull NSString *)eventName
                 priority:(XNEventPriority)priority
          extendParameter:(nullable NSDictionary *)extendParameter;

/**
 * @abstract
 * 上传H5y页面浏览时事件数据
 *
 * @param eventCode 事件唯一代码
 * @param eventName 事件描述名称
 * @param startViewDate  开始浏览页面时间
 * @param priority 事件优先级 立即上传/批次上传
 * @param extendParameter event扩展自定义数据。但对扩展数据做了一定的限制
 *                        是字典类型，以键值(key-value)对的形式组织数据
 *                        key(键) - 必须是`NSString`类型，如果与牛数的默认字段
 *                        冲突，牛数会覆盖extendParameter中相应的value；
 *                        value(值) - 只支持 NSString、NSNumber、NSSet、NSArray、NSDate 这些类型。
 *                        其中牛数会过滤掉NSSet、NSArray中非NSString和NSNumber元素。
 *
 * @discusstion 这个API与 `+ endViewPageWtihCode:eventName:startViewDate:priority:extendParameter:`区别就是：
 *                       会在"page_type"字段中传"h5"
 */
+ (void)endH5ViewPageWtihCode:(nonnull NSString *)eventCode
                    eventName:(nonnull NSString *)eventName
                startViewDate:(nullable NSDate *)startViewDate
                     priority:(XNEventPriority)priority
              extendParameter:(nullable NSDictionary *)extendParameter;

/**
 * @abstract
 * 上传自定义事件
 *
 * @param eventCode 事件唯一代码
 * @param eventName 事件描述名称
 * @param priority 事件优先级 立即上传/批次上传
 * @param extendParameter event扩展自定义数据。但对扩展数据做了一定的限制
 *                        是字典类型，以键值(key-value)对的形式组织数据
 *                        key(键) - 必须是`NSString`类型，如果与牛数的默认字段
 *                        冲突，牛数会覆盖extendParameter中相应的value；
 *                        value(值) - 只支持 NSString、NSNumber、NSSet、NSArray、NSDate 这些类型。
 *                        其中牛数会过滤掉NSSet、NSArray中非NSString和NSNumber元素。
 *
 * @discusstion 这个API与 `+ customWtihCode:eventName:priority:extendParameter:`区别就是：
 *                       会在"page_type"字段中传"h5"
 */
+ (void)customInH5WtihCode:(nonnull NSString *)eventCode
                 eventName:(nonnull NSString *)eventName
                  priority:(XNEventPriority)priority
           extendParameter:(nullable NSDictionary *)extendParameter;

/**
* @abstract
* 上传风控事件数据
*
* @param eventCode 事件唯一代码
* @param eventName 事件描述名称
* @param priority  事件优先级
* @param extendParameter event扩展自定义数据。但对扩展数据做了一定的限制
*                        是字典类型，以键值(key-value)对的形式组织数据
*                        key(键) - 必须是`NSString`类型，如果与牛数的默认字段
*                        冲突，牛数会覆盖extendParameter中相应的value；
*                        value(值) - 只支持 NSString、NSNumber、NSSet、NSArray、NSDictionary、NSDate 这些类型。
*                        其中牛数会过滤掉NSSet、NSArray中非NSString和NSNumber元素。
*
*/
+ (void)riskWtihCode:(nonnull NSString *)eventCode
      eventName:(nonnull NSString *)eventName
       priority:(XNEventPriority)priority
     extendParameter:(nullable NSDictionary *)extendParameter;

/**
 * @abstract
 * 开始追踪事件的时间间隔
 *
 * @param eventCode 事件唯一代码，会开始追踪改事件的时间间隔
 */
+ (void)beginTrackDurationForEventCode:(nonnull NSString *)eventCode;

/**
 * @abstract
 * 结束追踪事件的时间间隔
 *
 * @param eventCode 结束事件时间间隔追踪的事件码
 * @param durationCallBack 事件时间间回调，异步调用，非主线程
 */
+ (void)endTrackDurationForClickEvent:(nonnull NSString *)eventCode callBack:(void (^ __nonnull)(NSTimeInterval duration))durationCallBack;

/**
 * @abstract
 * 开启心跳，指定心跳的时间间隔(单位：秒)，心跳类型（仅在前台，还是前后台都心跳），上传地址，心跳数据包的扩展参数
 * @param intervalSecs 心跳时间间隔，单位:秒
 * @param beatType 心跳模式，默认仅在前台心跳
 * @param heartBeatServerURL 上报心跳的服务地址（不能为空）
 * @param extendDic 心跳携带的扩展信息
 */
+ (void)startHeartBeatWithIntervalSecs:(NSInteger)intervalSecs
                         heartBeatType:(NDHeatBeatType)beatType
                    heartBeatServerURL:(nonnull NSString *)heartBeatServerURL
                       extendParameter:(nullable NSDictionary *)extendDic;

/**
 * @abstract
 * 结束心跳
 */
+ (void)stopHeartBeat;

/**
 * @abstract
 * 牛数如果获取公网IP失败，这当前是返回的内网IP
*/
+ (nonnull NSString *)nd_IPAddress;

/**
 *  @abstract 当前牛数为没有iPhone设备定义的设备唯一id (IDFA or DeviceID)
*/
+ (nonnull NSString *)ND_UDID;

/**
 * @abstract
 * 牛数获取的当前所在省的数据
 *
 * @return 返回SDK成功获取到当前的省的名称字符串，否则返回 `@""`
 */
+ (nonnull NSString *)nd_CurruntProvinceName;

/**
 * @abstract
 * 牛数获取的当前所在市的数据
 *
 * @return 返回SDK成功获取到当前的市的名称字符串，否则返回 `@""`
 */
+ (nonnull NSString *)nd_CurruntCityName;

/**
 * @abstract
 * 返回当前设备的机型编码Identifier
 *
 * @return 返回当前当前设备的型号的编码，非传统意义上的iPhone 6 plus这种，而是 "iPhone8,1"
 * @discussion 可以在这里找映射关系 https://www.theiphonewiki.com/wiki/models
 *  在 `Identifier` colum
 */
+ (nonnull NSString *)nd_CurruntDevicesModelCode;
@end
