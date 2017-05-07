//
//  GoalIndependentThought.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef GoalIndependentThought_hpp
#define GoalIndependentThought_hpp

#include "Goal.hpp"

NS_RAM_OPEN

class GoalIndependentThought : public Goal {
    
    GoalIndependentThought(GoalCompletion whenAchieved,
                      GoalCompletion whenFailed,
                      std::vector<Goal*> *subgoals);
    ~GoalIndependentThought();
    
public:
    static GoalIndependentThought* makeNew();
    virtual void playTurn();
    virtual bool didAchieveGoal();
    virtual bool didFailToAchieveGoal();
    
};

NS_RAM_CLOSE

#endif /* GoalIndependentThought_hpp */
