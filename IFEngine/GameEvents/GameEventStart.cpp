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
#include "NameSystem.hpp"

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
    auto intro_2 = "intro_2";
    auto intro_3 = "intro_3";
    
    registerAction(ActionMessage(GameEntryLabel, {
        .text = "<allocate memory>",
        .accept = "NEXT INSTRUCTION",
        .impact = EMOTION_ZERO
    }, NextAction(intro_2)));
    
    registerAction(ActionMessage(intro_2, {
        .text = "<initialize registers>",
        .accept = "NEXT INSTRUCTION",
        .impact = EMOTION_ZERO
    }, NextAction(intro_3)));
    
    registerAction(ActionMessage(intro_3, {
        .text = "_main:",
        .accept = "NEXT INSTRUCTION",
        .impact = EMOTION_ZERO
    }, NextAction([this]() -> Action* {
        unregisterActions();
        return FirstLesson::loadEvent();
    })));
}

NS_RAM_CLOSE
