//
//  GameEvent.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "GameEvent.hpp"
#include "NextAction.hpp"
#include "Action.hpp"
#include "ActionRegistry.hpp"

NS_RAM_OPEN

GameEvent::GameEvent(std::string name)
: _priorEvent(nullptr)
, _name(name)
{ }

GameEvent::~GameEvent()
{
    unregisterActions();
}

void GameEvent::unregisterActions()
{
    for (auto name : _associatedActions) {
        ActionRegistry::shared()->remove(name);
    }
}

NS_RAM_CLOSE
