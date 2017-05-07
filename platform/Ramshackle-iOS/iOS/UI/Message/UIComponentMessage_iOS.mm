//
//  UIComponentMessage_iOS.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/23/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "UIComponentMessage_iOS.hpp"
#import "MessageView.h"

NS_RAM_OPEN

UIComponentMessage* UIComponentMessage::makeWithMessage(ActionMessage *message)
{
    auto component = new UIComponentMessage_iOS();
    component->_message = message;
    MessageView *view = ([NSBundle.mainBundle loadNibNamed:@"MessageView" owner:nil options:nil][0]);
    [view setComponent:component];
    component->setView((__bridge void*)view);
    return component;
}

NS_RAM_CLOSE