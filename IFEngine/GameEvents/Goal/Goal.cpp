//
//  Goal.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "Goal.hpp"
#include "Character.hpp"

NS_RAM_OPEN

Goal::Goal(GoalCompletion whenAchieved,
           GoalCompletion whenFailed,
           std::vector<Goal*> *subgoals=nullptr)
{
    _whenAchieved = whenAchieved;
    _whenFailed = whenFailed;
    _subgoals = subgoals;
}

Goal::~Goal() { }

void Goal::playTurn()
{
    for (auto goal : *_subgoals) {
        goal->playTurn();
    }
    
    if (didAchieveGoal()) {
        _whenAchieved();
    } else if (didFailToAchieveGoal()) {
        _whenFailed();
    }
}

NS_RAM_CLOSE