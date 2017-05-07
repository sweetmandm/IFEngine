//
//  Action.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/22/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "Action.hpp"
#include "NextAction.hpp"
#include "NextActionNone.hpp"

NS_RAM_OPEN

Action::Action(std::string label, ActionType type)
: _type(type)
, _label(label)
, _nextAction(NextActionNone())
{ }

Action::Action(std::string label, ActionType type, NextAction nextAction)
: _type(type)
, _label(label)
, _nextAction(nextAction)
{ }

Action::~Action() { }

void Action::setPreviousAction(Action *action)
{
    _previousAction = action;
}

void Action::setNextAction(NextAction action)
{
    _nextAction = action;
}

void Action::removeNextAction()
{
    _nextAction = NextActionNone();
}

NS_RAM_CLOSE
