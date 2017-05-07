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
#include "ActionPrompt.hpp"
#include "UIController.hpp"
#include "ActionRegistry.hpp"
#include "GameEvent.hpp"
#include "GameEventStart.hpp"

NS_RAM_OPEN

static IFEngine *instance = nullptr;

IFEngine* IFEngine::shared()
{
    if (instance == nullptr) {
        instance = new (std::nothrow) IFEngine();
    }
    return instance;
}

void IFEngine::begin(GameState* state)
{
    if (state == nullptr) {
        _gameState = GameState::makeNew();
        auto action = GameEventStart::loadEvent();
        _gameState->setNextAction(action);
    } else {
        _gameState = state;
    }
    playTurn();
}

void IFEngine::playTurn()
{
    auto action = _gameState->getNextAction();
    
    switch (action->getType()) {
        case ActionTypeQuestion: {
            
            ActionQuestion* question = dynamic_cast<ActionQuestion*>(action);
            RAM_ASSERT(question != nullptr, "Failed to cast action as ActionQuestion");
            performQuestion(question);
            break;
            
        }
        case ActionTypeMessage: {
            
            ActionMessage* message = dynamic_cast<ActionMessage*>(action);
            RAM_ASSERT(message != nullptr, "Failed to cast action as ActionMessage");
            performMessage(message);
            break;
            
        }
        case ActionTypePrompt: {
            
            ActionPrompt* prompt = dynamic_cast<ActionPrompt*>(action);
            RAM_ASSERT(prompt != nullptr, "Failed to cast action as ActionPrompt");
            performPrompt(prompt);
            
        }
    }
}

void IFEngine::performQuestion(ActionQuestion *question) {
    UIController::shared()->showQuestion(question);
}

void IFEngine::performPrompt(ActionPrompt *prompt)
{
    UIController::shared()->showPrompt(prompt);
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
