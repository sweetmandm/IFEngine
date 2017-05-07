//
//  IFEngine.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/17/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef IFEngine_hpp
#define IFEngine_hpp

#include <stdio.h>
#include "RamBase.h"
#include "EmotionalState.hpp"

NS_RAM_OPEN

class GameState;
class ActionQuestion;
class ActionPrompt;
class ActionMessage;
class GameEvent;
class Action;
struct Answer;

class IFEngine {
    
    GameState *_gameState;
    
public:
    
    static IFEngine* shared();
    
    GameState* getGameState() { return _gameState; };
    void begin(GameState* state);
    
    void playTurn();
    void performQuestion(ActionQuestion *question);
    void performPrompt(ActionPrompt *prompt);
    void performMessage(ActionMessage *message);
    
    void acceptMessage(ActionMessage *message);
    void answerQuestion(ActionQuestion *question, Answer answer);
    
    Action* loadGameEvent(GameEvent *event);
};

NS_RAM_CLOSE

#endif /* IFEngine_hpp */
