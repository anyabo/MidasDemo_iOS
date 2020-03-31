//
//  NiuDataProtocols.h
//  NiuDataSDK
//
//  Created by zhangaiwen on 2019/5/5.
//  Copyright © 2019年 zhangaiwen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XNEventDefine.h"

NS_ASSUME_NONNULL_BEGIN

@protocol NiuDataGetUserInfoProtocol <NSObject>
@optional
- (NSString *)nd_userid;
- (NSString *)nd_phoneNum;
- (NDGender)nd_gender;
- (NSString *)nd_age;
@end

NS_ASSUME_NONNULL_END
