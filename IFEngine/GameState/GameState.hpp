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

class Entity;
class Location;
class Action;
class GameEvent;
class WorldMap;

class GameState {

protected:
    GameState();
    ~GameState();
    
    Entity *_player;
    Location *_location;
    Action *_currentAction;
    GameEvent *_currentGameEvent;
    WorldMap *_worldMap;
    
public:
    static GameState* makeNew();
    
    Action* getNextAction();
    void setNextAction(Action *action);
    Entity* getPlayer() { return _player; };
    
    Action* loadGameEvent(GameEvent *event);
    
    void applyEmotion(EmotionalStateData emotions);
    
};

NS_RAM_CLOSE

#endif /* GameState_hpp */
