//
//  MockAction.cpp
//  Ramshackle
//
//  Created by David Sweetman on 2/25/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "MockAction.hpp"

using namespace ram;

MockAction::MockAction(std::string label)
: Action(label, ActionTypeMessage)
{ }

MockAction::MockAction(std::string label, ActionType type)
: Action(label, type)
{ }

MockAction::MockAction(std::string label, ActionType type, NextAction nextAction)
: Action(label, type, nextAction)
{ }

MockAction::~MockAction()
{ }
