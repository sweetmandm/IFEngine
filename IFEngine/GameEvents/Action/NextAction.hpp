//
//  NextAction.hpp
//  Ramshackle
//
//  Created by David Sweetman on 2/25/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef NextAction_hpp
#define NextAction_hpp

#include "RamBase.h"
#include "ActionRegistry.hpp"
#include <string>
#include <functional>

NS_RAM_OPEN

class Action;

enum NextActionType {
    NextActionTypeNone,
    NextActionTypeLabel,
    NextActionTypeLambda
};

class NextAction {
    std::string _nextActionLabel;
    std::function<Action*(void)> _nextActionGenerator;
    NextActionType _type;
    
public:
    ~NextAction();
    
    /// Create a 'NextActionTypeNone':
    NextAction();
    
    /// Create a 'NextActionTypeLabel':
    NextAction(std::string label);
    
    // Create a 'NextActionTypeLambda':
    NextAction(std::function<Action*(void)> next);
    
    Action* getNext() const;
    NextActionType getType() const { return _type; };
    bool isNone() const { return _type == NextActionTypeNone; };
    bool isLabel() const { return _type == NextActionTypeLabel; };
    bool isLambda() const { return _type == NextActionTypeLambda; };
};

NS_RAM_CLOSE

#endif /* NextAction_hpp */
