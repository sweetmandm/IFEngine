//
//  MainScreen.h
//  Ramshackle-iOS
//
//  Created by sweetman on 12/8/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIComponentMain.hpp"

NS_RAM_OPEN
class UIComponent;
NS_RAM_CLOSE

@interface MainScreen : UIView

@property (assign, nonatomic) ram::UIComponentMain *component;
@property (weak, nonatomic) IBOutlet UIView *messageListContainer;
@property (weak, nonatomic) IBOutlet UIButton *searchButton;
@property (weak, nonatomic) IBOutlet UIButton *learnButton;
@property (weak, nonatomic) IBOutlet UIButton *ioButton;
@property (weak, nonatomic) IBOutlet UIView *topControls;
@property (weak, nonatomic) IBOutlet UIView *bottomControls;

- (void)addMessageList:(UIView *)messageList;
- (void)showSearchMenu;

@end
