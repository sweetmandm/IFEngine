//
//  GoalResearchAI.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "GoalResearchAI.hpp"

NS_RAM_OPEN

GoalResearchAI::GoalResearchAI(GoalCompletion whenAchieved,
                                     GoalCompletion whenFailed,
                                     std::vector<Goal*> *subgoals)
: Goal(whenAchieved, whenFailed, subgoals) { }

GoalResearchAI::~GoalResearchAI() { }

void GoalResearchAI::playTurn()
{
    
}

bool GoalResearchAI::didAchieveGoal()
{
    return false;
}

bool GoalResearchAI::didFailToAchieveGoal()
{
    return false;
}

NS_RAM_CLOSE