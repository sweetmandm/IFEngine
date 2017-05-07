//
//  MockAction.hpp
//  Ramshackle
//
//  Created by David Sweetman on 2/25/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef MockAction_hpp
#define MockAction_hpp

#include "Action.hpp"
#include "NextAction.hpp"
#include <string>

using namespace ram;

class MockAction : public Action {
public:
    MockAction(std::string label);
    MockAction(std::string label, ActionType type);
    MockAction(std::string label, ActionType type, NextAction nextAction);
    ~MockAction();
};

#endif /* MockAction_hpp */
