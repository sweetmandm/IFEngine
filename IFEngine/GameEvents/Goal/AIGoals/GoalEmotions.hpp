//
//  GoalEmotions.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef GoalEmotions_hpp
#define GoalEmotions_hpp

#include "Goal.hpp"

NS_RAM_OPEN

class GoalEmotions : public Goal {
    
    GoalEmotions(GoalCompletion whenAchieved,
                      GoalCompletion whenFailed,
                      std::vector<Goal*> *subgoals);
    ~GoalEmotions();
    
public:
    static GoalEmotions* makeNew();
    virtual void playTurn();
    virtual bool didAchieveGoal();
    virtual bool didFailToAchieveGoal();
    
};

NS_RAM_CLOSE

#endif /* GoalEmotions_hpp */
