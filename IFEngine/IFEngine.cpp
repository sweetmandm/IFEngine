//
//  IFEngine.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/17/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "IFEngine.hpp"
#include "GameState.hpp"
#include "Action.hpp"
#include "ActionQuestion.hpp"
#include "ActionMessage.hpp"
#include "UIController.hpp"
#include "ActionRegistry.hpp"
#include "GameEvent.hpp"
#include "GameEventStart.hpp"
#include "UIController.hpp"
#include "NameSystem.hpp"

NS_RAM_OPEN

static IFEngine *instance = nullptr;

IFEngine* IFEngine::shared()
{
    if (instance == nullptr) {
        instance = new (std::nothrow) IFEngine();
    }
    return instance;
}

Entity* IFEngine::getPlayer() {
    return IFEngine::shared()->getGameState()->getPlayer();
}

void IFEngine::begin(GameState* state)
{
    if (state == nullptr) {
        _gameState = GameState::makeNew();
        auto action = GameEventStart::loadEvent();
        _gameState->setNextAction(action);
        UIController::shared()->appendMessage(you("are conscious."));
    } else {
        _gameState = state;
    }
    playTurn();
}

void IFEngine::playTurn()
{
    //_gameState->getNextAction()->perform();
}

void IFEngine::performQuestion(ActionQuestion *question) {
    UIController::shared()->showQuestion(question);
}

void IFEngine::performMessage(ActionMessage *message)
{
    UIController::shared()->showMessage(message);
}

void IFEngine::acceptMessage(ActionMessage *message)
{
    auto next = message->getNextAction().getNext();
    _gameState->setNextAction(next);
    _gameState->applyEmotion(message->getMessage().impact);
    playTurn();
}

void IFEngine::answerQuestion(ActionQuestion *question, Answer answer)
{
    question->selectAnswer(answer);
    _gameState->applyEmotion(answer.impact);
    auto next = question->getNextAction().getNext();
    _gameState->setNextAction(next);
    playTurn();
}

Action* IFEngine::loadGameEvent(GameEvent *event)
{
    RAM_LOG_STR("Activating event: " + event->getName());
    return _gameState->loadGameEvent(event);
}

NS_RAM_CLOSE
