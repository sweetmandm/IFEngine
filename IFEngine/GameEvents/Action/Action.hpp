//
//  Action.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/22/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Action_hpp
#define Action_hpp

#include "RamBase.h"
#include "NextAction.hpp"
#include <string>

NS_RAM_OPEN

enum ActionType {
    ActionTypeQuestion,
    ActionTypeMessage,
    ActionTypeBlock
};

class Action {
protected:
    
    Action(std::string label, ActionType type);
    Action(std::string label, ActionType type, NextAction nextAction);
    ActionType _type;
    std::string _label;
    Action *_previousAction;
    NextAction _nextAction;
    
public:
    virtual ~Action();
    virtual ActionType getType() const { return _type; };
    std::string getLabel() const { return _label; };
    NextAction getNextAction() { return _nextAction; };
    void setPreviousAction(Action *action);
    void setNextAction(NextAction action);
    void removeNextAction();
    virtual void perform() = 0;
};

NS_RAM_CLOSE

#endif /* Action_hpp */
