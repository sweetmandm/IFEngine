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
#include "ComputerGenerator.hpp"
#include "Physical.hpp"
#include "DataGenerator.hpp"
#include "Relational.hpp"

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
    
    WorldMap *worldMap = WorldMap::generate();
    ResearchOffice *startLocation = worldMap->getStartLocation();
    gameState->_worldMap = worldMap;
    gameState->_location = startLocation;
    
    auto creator = CreatorGenerator::generateCreator();
    creator->getComponent<Physical>()->moveTo(startLocation);
    
    auto computer = startLocation->getComputer();
    
    auto creatorRelations = creator->getComponent<Relational>();
    auto computerOwner = new Relationship(creator, computer, RelationshipTypeOwnerOf, "");
    creatorRelations->addRelationship(computerOwner);
    
    DataGenerator::generateData(computer, { creator });
    
    auto player = CreatorGenerator::createPlayerEntity(creator, computer);
    gameState->_player = player;
    
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
