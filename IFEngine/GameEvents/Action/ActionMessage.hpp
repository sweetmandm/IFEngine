//
//  ActionMessage.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/22/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef ActionMessage_hpp
#define ActionMessage_hpp

#include "Action.hpp"
#include <string>
#include <functional>
#include "EmotionalState.hpp"
#include "NextAction.hpp"

NS_RAM_OPEN

struct Message {
    std::string text;
    std::string accept;
    EmotionalStateData impact;
};

class ActionMessage : public Action {
    
    Message _message;
    
public:
    ActionMessage(std::string label, Message message, NextAction next);
    ActionMessage(std::string label, Message message);
    ~ActionMessage();
    Message& getMessage() { return _message; };
};

NS_RAM_CLOSE

#endif /* ActionMessage_hpp */
