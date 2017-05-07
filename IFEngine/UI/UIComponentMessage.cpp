//
//  UIComponentMessage.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/23/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "UIComponentMessage.hpp"
#include "IFEngine.hpp"
#include "ActionMessage.hpp"

NS_RAM_OPEN

UIComponentMessage::~UIComponentMessage()
{
    _message = nullptr;
}

void UIComponentMessage::acceptMessage()
{
    IFEngine::shared()->acceptMessage(_message);
}

std::string UIComponentMessage::getMessageText()
{
    return _message->getMessage().text;
}

std::string UIComponentMessage::getAcceptText()
{
    return _message->getMessage().accept;
}

NS_RAM_CLOSE