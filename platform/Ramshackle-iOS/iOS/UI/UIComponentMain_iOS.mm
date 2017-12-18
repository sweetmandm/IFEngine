//
//  UIComponentMain_iOS.mm
//  Ramshackle-iOS
//
//  Created by sweetman on 12/8/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#import "UIComponentMain_iOS.hpp"
#import "MainScreen.h"
#import "Masonry.h"
#import "UIComponentMessageList_iOS.hpp"
#import "MessageList.h"

NS_RAM_OPEN

UIComponentMain* UIComponentMain::make() {
    auto component = new UIComponentMain_iOS();
    MainScreen *mainScreen = ([NSBundle.mainBundle loadNibNamed:@"MainScreen" owner:nil options:nil][0]);
    [mainScreen setComponent:component];
    component->setView((__bridge void*)mainScreen);
    return component;
}

MainScreen* UIComponentMain_iOS::getMainScreen() {
    return (__bridge MainScreen*)_view;
}

void UIComponentMain_iOS::setMessageList(UIComponentMessageList *messageList) {
    UIComponentMain::setMessageList(messageList);
    MessageList *messageListView = (__bridge MessageList*)_messageList->getView();
    MainScreen *main = getMainScreen();
    [main.messageListContainer addSubview:messageListView];
    [messageListView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(main.messageListContainer);
    }];
};

void UIComponentMain_iOS::showSearchMenu() {
    [getMainScreen() showSearchMenu];
}

NS_RAM_CLOSE
