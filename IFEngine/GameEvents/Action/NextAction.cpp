//
//  NextAction.cpp
//  Ramshackle
//
//  Created by David Sweetman on 2/25/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "NextAction.hpp"
#include "Action.hpp"

NS_RAM_OPEN

NextAction::NextAction()
: _type(NextActionTypeNone)
{ }

NextAction::NextAction(std::string label)
: _type(NextActionTypeLabel)
, _nextActionLabel(label)
{ }

NextAction::NextAction(std::function<Action*(void)> next)
: _type(NextActionTypeLambda)
, _nextActionGenerator(next)
{ }

NextAction::~NextAction() { }

Action* NextAction::getNext() const {
    switch (_type) {
        case NextActionTypeNone:
            return nullptr;
            break;
        case NextActionTypeLabel:
            return ActionRegistry::shared()->get(_nextActionLabel);
            break;
        case NextActionTypeLambda:
            return _nextActionGenerator();
            break;
    }
}

NS_RAM_CLOSE
