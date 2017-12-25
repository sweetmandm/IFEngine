//
//  UIComponentMessageList.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/5/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "UIComponentMessageList.hpp"

NS_RAM_OPEN

void UIComponentMessageList::append(std::string message) {
    _messages->push_back(message);
}

UIComponentMessageList::UIComponentMessageList()
: _messages(new std::vector<std::string>)
{ }

UIComponentMessageList::~UIComponentMessageList(){ };

NS_RAM_CLOSE
