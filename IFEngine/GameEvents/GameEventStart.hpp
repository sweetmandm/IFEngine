//
//  GameEventStart.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef GameEventStart_hpp
#define GameEventStart_hpp

#include "GameEvent.hpp"
#include <vector>
#include <string>

NS_RAM_OPEN

class GameEventStart : public GameEvent {
    
    std::vector<std::string> _associatedActions;
    
public:
    GameEventStart();
    ~GameEventStart();
    static Action* loadEvent();
    virtual void registerActions();
};

NS_RAM_CLOSE

#endif /* GameEventStart_hpp */