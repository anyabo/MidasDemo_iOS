//
//  MidasAdDetailViewController.h
//  MidasDemo
//
//  Created by CarlsonLee on 2019/12/31.
//  Copyright © 2019 CarlsonLee. All rights reserved.
//

#import "MidasBaseViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface MidasAdDetailViewController : MidasBaseViewController

@property (nonatomic, assign) NSInteger type;

@property (nonatomic, strong) NSDictionary *params;

@end

NS_ASSUME_NONNULL_END
