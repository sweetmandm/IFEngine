//
//  ActionRegistry.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/22/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "ActionRegistry.hpp"
#include "Action.hpp"
#include "ActionMessage.hpp"
#include "ActionQuestion.hpp"

NS_RAM_OPEN

static ActionRegistry* registry = nullptr;

ActionRegistry* ActionRegistry::shared()
{
    if (!registry) {
        registry = new (std::nothrow) ActionRegistry();
    }
    return registry;
}

ActionRegistry::ActionRegistry() { }

ActionRegistry::~ActionRegistry()
{
    for (auto itr : map) { SAFE_DELETE(itr.second); }
}

Action* ActionRegistry::get(std::string name)
{
    return map[name];
}

void ActionRegistry::remove(std::string name)
{
    Action* action = ActionRegistry::shared()->get(name);
    map.erase(name);
    SAFE_DELETE(action);
}

void ActionRegistry::reset()
{
    for (auto itr : map) { SAFE_DELETE(itr.second); }
    registry = new (std::nothrow) ActionRegistry();
}

NS_RAM_CLOSE
