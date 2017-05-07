//
//  AppDelegate.m
//  Ramshackle
//
//  Created by David Sweetman on 10/18/14.
//  Copyright (c) 2014 tinfish. All rights reserved.
//

#import "AppDelegate.h"
#import "BaseViewController.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    BaseViewController *vc = [[BaseViewController alloc] initWithNibName:nil bundle:nil];
    [self.window setRootViewController:vc];
    [self.window makeKeyAndVisible];
    return YES;
}

@end
