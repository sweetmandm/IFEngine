//
//  Goal.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Goal_hpp
#define Goal_hpp

#include "TurnPiece.hpp"
#include <functional>
#include <vector>

NS_RAM_OPEN

class Character;

typedef std::function<void(void)> GoalCompletion;

class Goal : public TurnPiece {
    
    // - completions
    GoalCompletion _whenAchieved;
    GoalCompletion _whenFailed;
    std::vector<Goal*> *_subgoals;
    
public:
    Character *_owner;
    
    Goal(GoalCompletion whenAchieved,
         GoalCompletion whenFailed,
         std::vector<Goal*> *subgoals);
    
    ~Goal();
    
    // - play
    virtual void playTurn();
    virtual bool didAchieveGoal() = 0;
    virtual bool didFailToAchieveGoal() = 0;
};

NS_RAM_CLOSE

#endif /* Goal_hpp */
