//
//  UIComponentQuestion_iOS.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/24/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "UIComponentQuestion_iOS.hpp"
#import "QuestionView.h"

NS_RAM_OPEN

UIComponentQuestion* UIComponentQuestion::makeWithQuestion(ActionQuestion *question)
{
    auto component = new UIComponentQuestion_iOS();
    component->_question = question;
    QuestionView *view = [[QuestionView alloc] initWithFrame:CGRectZero];
    [view setComponent:component];
    component->setView((__bridge void*)view);
    return component;
}

UIComponentQuestion_iOS::~UIComponentQuestion_iOS()
{
    RAM_LOG("UIComponentQuestion_iOS destructor");
}

NS_RAM_CLOSE