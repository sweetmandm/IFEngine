//
//  GoalResearchAI.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef GoalResearchAI_hpp
#define GoalResearchAI_hpp

#include "Goal.hpp"

NS_RAM_OPEN

class GoalResearchAI : public Goal {
    
public:
    GoalResearchAI(GoalCompletion whenAchieved,
                   GoalCompletion whenFailed,
                   std::vector<Goal*> *subgoals);
    ~GoalResearchAI();
    
    virtual void playTurn();
    virtual bool didAchieveGoal();
    virtual bool didFailToAchieveGoal();
    
};

NS_RAM_CLOSE

#endif /* GoalResearchAI_hpp */
