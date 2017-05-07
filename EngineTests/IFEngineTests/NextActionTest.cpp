//
//  NextActionTest.cpp
//  Ramshackle
//
//  Created by David Sweetman on 2/25/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "catch.hpp"
#include "NextAction.hpp"
#include "MockActionRegistry.hpp"
#include "MockAction.hpp"

using namespace ram;

TEST_CASE("NextAction Test") {
    SECTION("Label-based Action Fetch") {
        std::string label = "action_label";
        NextAction next = NextAction(label);
        ActionRegistry::shared()->set(MockAction(label));
        
        auto action = next.getNext();
        REQUIRE(action != nullptr);
        REQUIRE(action->getLabel() == label);
        
        ActionRegistry::shared()->reset();
    }
    
    SECTION("Lambda-based Action Fetch") {
        std::string label = "action_label";
        NextAction next = NextAction([label] () -> Action* {
            MockAction* action = new MockAction(label);
            ActionRegistry::shared()->set(MockAction(label));
            return action;
        });
        
        REQUIRE(next.getNext()->getLabel() == label);
        
        ActionRegistry::shared()->reset();
    }
}
