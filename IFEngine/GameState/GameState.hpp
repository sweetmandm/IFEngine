//
//  GameState.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/19/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp

#include "RamBase.h"

NS_RAM_OPEN

struct EmotionalStateData;

class Player;
class Location;
class Action;
class GameEvent;

class GameState {

protected:
    GameState();
    ~GameState();
    
    Player *_player;
    Location *_location;
    Action *_currentAction;
    GameEvent *_currentGameEvent;
    
public:
    static GameState* makeNew();
    
    Action* getNextAction();
    void setNextAction(Action *action);
    Player* getPlayer() { return _player; };
    
    Action* loadGameEvent(GameEvent *event);
    
    void applyEmotion(EmotionalStateData emotions);
    
};

NS_RAM_CLOSE

#endif /* GameState_hpp */
