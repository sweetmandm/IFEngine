//
//  UIComponentMessageList_iOS.m
//  Ramshackle-iOS
//
//  Created by sweetman on 12/5/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#import "UIComponentMessageList_iOS.hpp"
#import "MessageList.h"

NS_RAM_OPEN

UIComponentMessageList_iOS::UIComponentMessageList_iOS()
: UIComponentMessageList()
{ }

UIComponentMessageList* UIComponentMessageList::make()
{
    auto component = new UIComponentMessageList_iOS();
    MessageList *view = ([NSBundle.mainBundle loadNibNamed:@"MessageList" owner:nil options:nil][0]);
    [view setComponent:component];
    component->setView((__bridge void*)view);
    return component;
}

void UIComponentMessageList_iOS::append(std::string message)
{
    UIComponentMessageList::append(message);
    [(__bridge MessageList*)_view reload];
}

NS_RAM_CLOSE

