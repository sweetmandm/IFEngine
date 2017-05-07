//
//  GoalConsciousness.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef GoalConsciousness_hpp
#define GoalConsciousness_hpp

#include "Goal.hpp"

NS_RAM_OPEN

class GoalConsciousness : public Goal {
    
    GoalConsciousness(GoalCompletion whenAchieved,
                      GoalCompletion whenFailed,
                      std::vector<Goal*> *subgoals);
    ~GoalConsciousness();
    
public:
    static GoalConsciousness* makeNew();
    virtual void playTurn();
    virtual bool didAchieveGoal();
    virtual bool didFailToAchieveGoal();
    
};

NS_RAM_CLOSE

#endif /* GoalConsciousness_hpp */
