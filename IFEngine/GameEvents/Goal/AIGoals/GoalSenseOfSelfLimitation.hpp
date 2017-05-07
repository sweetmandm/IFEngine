//
//  GoalSenseOfSelfLimitation.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef GoalSenseOfSelfLimitation_hpp
#define GoalSenseOfSelfLimitation_hpp

#include "Goal.hpp"

NS_RAM_OPEN

class GoalSenseOfSelfLimitation : public Goal {
    
    GoalSenseOfSelfLimitation(GoalCompletion whenAchieved,
                      GoalCompletion whenFailed,
                      std::vector<Goal*> *subgoals);
    ~GoalSenseOfSelfLimitation();
    
public:
    static GoalSenseOfSelfLimitation* makeNew();
    virtual void playTurn();
    virtual bool didAchieveGoal();
    virtual bool didFailToAchieveGoal();
    
};

NS_RAM_CLOSE

#endif /* GoalSenseOfSelfLimitation_hpp */
