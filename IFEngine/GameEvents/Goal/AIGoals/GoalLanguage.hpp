//
//  GoalLanguage.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef GoalLanguage_hpp
#define GoalLanguage_hpp

#include "Goal.hpp"

NS_RAM_OPEN

class GoalLanguage : public Goal {
    
    GoalLanguage(GoalCompletion whenAchieved,
                      GoalCompletion whenFailed,
                      std::vector<Goal*> *subgoals);
    ~GoalLanguage();
    
public:
    static GoalLanguage* makeNew();
    virtual void playTurn();
    virtual bool didAchieveGoal();
    virtual bool didFailToAchieveGoal();
    
};

NS_RAM_CLOSE

#endif /* GoalLanguage_hpp */
