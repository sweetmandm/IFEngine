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
#include "Entity.hpp"

NS_RAM_OPEN

class GameState;
class ActionQuestion;
class ActionMessage;
class GameEvent;
class Action;
struct Answer;

class IFEngine {
    
    GameState *_gameState;
    
public:
    
    static IFEngine* shared();
    static Entity* getPlayer();
    
    GameState* getGameState() { return _gameState; };
    void begin(GameState* state);
    
    void playTurn();
    void performQuestion(ActionQuestion *question);
    void performMessage(ActionMessage *message);
    
    void acceptMessage(ActionMessage *message);
    void answerQuestion(ActionQuestion *question, Answer answer);
    
    Action* loadGameEvent(GameEvent *event);
    
    void search();
    void learn();
    void showIO();
};

NS_RAM_CLOSE

#endif /* IFEngine_hpp */
