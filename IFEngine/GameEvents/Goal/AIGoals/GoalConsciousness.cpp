//
//  GoalConsciousness.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "GoalConsciousness.hpp"

NS_RAM_OPEN

GoalConsciousness* GoalConsciousness::makeNew()
{
    auto consciousness = new GoalConsciousness([]() { }, []() { }, nullptr);
    return consciousness;
}

GoalConsciousness::GoalConsciousness(GoalCompletion whenAchieved,
                                     GoalCompletion whenFailed,
                                     std::vector<Goal*> *subgoals)
: Goal(whenAchieved, whenFailed, subgoals) { }

GoalConsciousness::~GoalConsciousness() { }

void GoalConsciousness::playTurn()
{
    
}

bool GoalConsciousness::didAchieveGoal()
{
    return false;
}

bool GoalConsciousness::didFailToAchieveGoal()
{
    return false;
}

NS_RAM_CLOSE
