//
//  FirstLesson.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/22/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef FirstLesson_hpp
#define FirstLesson_hpp

#include "GameEvent.hpp"
#include "Action.hpp"
#include <functional>

NS_RAM_OPEN

class FirstLesson : public GameEvent {
    
public:
    FirstLesson();
    ~FirstLesson();
    
    static Action* loadEvent();
    
    void registerActions();
};

NS_RAM_CLOSE

#endif /* FirstLesson_hpp */
