//
//  GameEventStart.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "GameEventStart.hpp"
#include "ActionMessage.hpp"
#include "FirstLesson.hpp"
#include "ActionRegistry.hpp"
#include "IFEngine.hpp"
#include "Description.hpp"
#include "ActionBlock.hpp"
#include "PlayerSoftwareSystem.hpp"

NS_RAM_OPEN

static auto GameEntryLabel = "intro_1";

Action* GameEventStart::loadEvent()
{
    auto action = IFEngine::shared()->loadGameEvent(new GameEventStart());
    return action;
}

GameEventStart::GameEventStart()
: GameEvent("Start")
{
    registerActions();
    _firstAction = ActionRegistry::shared()->get(GameEntryLabel);
}

GameEventStart::~GameEventStart() { }

void GameEventStart::registerActions()
{
    registerAction(ActionBlock(GameEntryLabel, []() -> void {
        Entity *player = IFEngine::shared()->getPlayer();
        describe_consciousness(player);
        PlayerSoftwareSystem::start(player);
    }));
}

NS_RAM_CLOSE
