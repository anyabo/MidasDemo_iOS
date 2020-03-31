//
//  main.m
//  MidasDemo
//
//  Created by CarlsonLee on 2019/12/23.
//  Copyright © 2019 CarlsonLee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MSAdSDK/MSAdSDK.h>
#import "AppDelegate.h"

int main(int argc, char * argv[]) {
    NSString * appDelegateClassName;
    @autoreleasepool {
        // Setup code that might create autoreleased objects goes here.
        appDelegateClassName = NSStringFromClass([AppDelegate class]);
    }
    return UIApplicationMain(argc, argv, NSStringFromClass([MRApplication class]), appDelegateClassName);
}
