//
//  MainScreen.m
//  Ramshackle-iOS
//
//  Created by sweetman on 12/8/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#import "MainScreen.h"
#import "Masonry.h"

@interface MainScreen()
@property (weak, nonatomic) UIView *messageList;
@end

@implementation MainScreen

- (void)setComponent:(ram::UIComponentMain *)component
{
    _component = component;
    [self setupUI];
}

- (void)setupUI {
    
}

- (void)addMessageList:(UIView *)messageList {
    self.messageList = messageList;
    [self.messageListContainer addSubview:messageList];
    [messageList mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(self.messageListContainer);
    }];
}

- (IBAction)didPressSearch:(id)sender {
    _component->didSelectSearch();
}

- (IBAction)didPressLearn:(id)sender {
    _component->didSelectLearn();
}

- (IBAction)didPressIO:(id)sender {
    _component->didSelectIO();
}

- (void)showSearchMenu {
    
}

@end
