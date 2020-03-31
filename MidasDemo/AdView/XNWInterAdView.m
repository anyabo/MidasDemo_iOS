//
//  XNWInterAdView.m
//  XNWalkerLove
//
//  Created by CarlsonLee on 2019/11/5.
//  Copyright © 2019 YANJING. All rights reserved.

#import "XNWInterAdView.h"

@interface XNWInterAdView ()
{
    UIImageView *_iconImgView;
    UILabel *_titleLab;
    UIImageView *_adImgView;
    UILabel *_desLab;
}

@end

@implementation XNWInterAdView

- (instancetype)initWithFrame:(CGRect)frame
{
    if(self = [super initWithFrame:frame]){
        [self initSubviews];
    }
    return self;
}

- (void)initSubviews
{
    UIImageView *iconImgView = [UIImageView new];
    iconImgView.frame = CGRectMake(0, 0, 30, 30);
    UILabel *titleLab = [UILabel new];
    titleLab.backgroundColor = [UIColor clearColor];
    titleLab.textColor = [UIColor grayColor];
    titleLab.textAlignment = NSTextAlignmentLeft;
    titleLab.font = [UIFont systemFontOfSize:14];
    titleLab.frame = CGRectMake(CGRectGetMaxX(iconImgView.frame)+10, 0, 200, 30);
    
    UILabel *desLab = [UILabel new];
    desLab.backgroundColor = [UIColor clearColor];
    desLab.textColor = [UIColor grayColor];
    desLab.textAlignment = NSTextAlignmentLeft;
    desLab.frame = CGRectMake(0, self.bounds.size.height-30, self.bounds.size.width, 30);
    
    [self addSubview:iconImgView];
    [self addSubview:titleLab];
    [self addSubview:desLab];
    _iconImgView = iconImgView;
    _titleLab = titleLab;
    _desLab = desLab;
}

- (void)loadNativeAdObj:(MidasAdDataObject *)adObj
{
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        NSData *data = [NSData dataWithContentsOfURL:[NSURL URLWithString:adObj.iconUrl]];
        dispatch_async(dispatch_get_main_queue(), ^{
            UIImage *icon = [UIImage imageWithData:data];
            self->_iconImgView.image = icon;
        });
    });
    _titleLab.text = adObj.title;
    _desLab.text = adObj.desc;
    
    MidasAdMediaView *view = [[MidasAdMediaView alloc] initWithFrame:CGRectMake(0, 40, self.bounds.size.width, (self.bounds.size.width)/adObj.mediaRatio)];
    [view setMeidaAdData:adObj];
    [self addSubview:view];
    
    //注册点击
    [adObj registContainer:self mediaView:view];
}

@end
