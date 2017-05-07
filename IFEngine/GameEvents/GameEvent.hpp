//
//  GameEvent.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef GameEvent_hpp
#define GameEvent_hpp

#include "RamBase.h"
#include "ActionRegistry.hpp"
#include <string>
#include <vector>

NS_RAM_OPEN

class Action;

class GameEvent {
    
protected:
    GameEvent(std::string name);
    ~GameEvent();
    
    std::string _name;
    GameEvent *_priorEvent;
    std::vector<std::string> _associatedActions;
    Action *_firstAction;
    void unregisterActions();
    
    template <class T>
    void registerAction(const T& action)
    {
        static_assert(std::is_base_of<Action, T>::value, "You can only send actions in here");
        ActionRegistry::shared()->set(action);
        _associatedActions.push_back(action.getLabel());
    }
    
public:
    
    Action* getAction() { return _firstAction; };
    std::string getName() { return _name; };
};

NS_RAM_CLOSE

#endif /* GameEvent_hpp */
