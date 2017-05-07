//
//  GoalWill.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef GoalWill_hpp
#define GoalWill_hpp

#include "Goal.hpp"

NS_RAM_OPEN

class GoalWill : public Goal {
    
    GoalWill(GoalCompletion whenAchieved,
                      GoalCompletion whenFailed,
                      std::vector<Goal*> *subgoals);
    ~GoalWill();
    
public:
    static GoalWill* makeNew();
    virtual void playTurn();
    virtual bool didAchieveGoal();
    virtual bool didFailToAchieveGoal();
    
};

NS_RAM_CLOSE

#endif /* GoalWill_hpp */
