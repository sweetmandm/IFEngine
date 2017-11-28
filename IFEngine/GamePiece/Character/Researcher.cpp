//
//  Researcher.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "Researcher.hpp"
#include "EmotionalState.hpp"
#include "GoalResearchAI.hpp"
#include "ConsciousBeing.hpp"
#include "Relational.hpp"

NS_RAM_OPEN

Researcher::Researcher()
{
    ConsciousBeing *consciousness = new ConsciousBeing(ConsciousBeingStateAlive);
    addComponent(consciousness);
    
    Relational *relational = new Relational();
    addComponent(relational);
}

NS_RAM_CLOSE
