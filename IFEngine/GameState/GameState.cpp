//
//  GameState.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/19/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "GameState.hpp"
#include "Player.hpp"
#include "ResearchOffice.hpp"
#include "Action.hpp"
#include "GameEventStart.hpp"
#include "EmotionalState.hpp"
#include "Entity.hpp"
#include "WorldMap.hpp"
#include "CreatorGenerator.hpp"

NS_RAM_OPEN

GameState::GameState()
: _currentAction(nullptr)
, _currentGameEvent(nullptr)
, _player(nullptr)
, _worldMap(nullptr)
, _location(nullptr)
{ }

GameState::~GameState() { }

GameState* GameState::makeNew() {
    auto gameState = new GameState();
    auto creator = CreatorGenerator::generateCreator();
    gameState->_player = CreatorGenerator::createPlayerEntity(creator);
    WorldMap *worldMap = WorldMap::generate();
    gameState->_worldMap = worldMap;
    gameState->_location = worldMap->getLocation();
    return gameState;
}

Action* GameState::loadGameEvent(GameEvent *event)
{
    _currentGameEvent = event;
    auto action = event->getAction();
    RAM_ASSERT(action, "A GameEvent must return an action");
    return action;
}

void GameState::setNextAction(Action *action)
{
    RAM_ASSERT(action, "Attempted to set a nullptr as the next action");
    if (_currentAction != nullptr) {
        action->setPreviousAction(_currentAction);
    }
    _currentAction = action;
}

Action* GameState::getNextAction()
{
    return _currentAction;
}

void GameState::applyEmotion(EmotionalStateData emotions)
{
    EmotionalState *playerEmotions = _player->getComponent<EmotionalState>();
    if (playerEmotions) {
        playerEmotions->apply(emotions);
    }
}

NS_RAM_CLOSE
