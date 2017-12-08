//
//  BaseViewcontroller.m
//  Ramshackle
//
//  Created by David Sweetman on 12/23/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#import "BaseViewController.h"
//UI
#import "UIController.hpp"

// IFEngine
#import "IFEngine.hpp"

//// 3DEngine
//#import "EAGLView.h"
//#import "RenderController.h"
//#import "PlatformMacros.h"
//#import "WorldManager.h"
//#import "RenderView_iOSGL.h"
//#import "Size2D.h"

@implementation BaseViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    ram::UIController::shared()->makeBaseComponentWithView((__bridge void*)self.view);
    ram::IFEngine::shared()->begin(nullptr);
}

@end
