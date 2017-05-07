//
//  NextActionFromLambda.hpp
//  Ramshackle
//
//  Created by David Sweetman on 2/26/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef NextActionFromLambda_hpp
#define NextActionFromLambda_hpp

#include "RamBase.h"
#include "ActionRegistry.hpp"
#include <string>
#include <functional>

NS_RAM_OPEN

class Action;

class NextAction {
    std::string _nextActionLabel;
    std::function<Action*(void)> _nextActionGenerator;
    
public:
    NextAction(std::string label);
    NextAction(std::function<Action*(void)> next);
    ~NextAction();
    
    virtual Action* getNext() = 0;
};

NS_RAM_CLOSE

#endif /* NextActionFromLambda_hpp */
