//
//  ActionMessage.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/22/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "ActionMessage.hpp"
#include "ActionRegistry.hpp"

NS_RAM_OPEN

ActionMessage::ActionMessage(std::string label, Message message, NextAction next)
: Action(label, ActionTypeMessage, next)
, _message(message)
{ }

ActionMessage::ActionMessage(std::string label, Message message)
: Action(label, ActionTypeMessage)
, _message(message)
{ }

ActionMessage::~ActionMessage() { }

NS_RAM_CLOSE
