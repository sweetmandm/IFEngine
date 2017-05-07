//
//  Researcher.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Researcher_hpp
#define Researcher_hpp

#include "Character.hpp"
#include "OrganicBeing.hpp"

NS_RAM_OPEN

class EmotionalState;
class Goal;

class Researcher : public Character {

protected:
    Researcher();
    ~Researcher();
    
    EmotionalState *_emotionalState;
    OrganicBeingState _organicBeingState;
    Goal *_goal;
    
public:
    static Researcher* makeNew();
    static EmotionalState* defaultEmotionalState();
    virtual void playTurn();
    
    EmotionalState* getEmotionalState() { return _emotionalState; }
    OrganicBeingState getOrganicBeingState() { return _organicBeingState; }
    
};

NS_RAM_CLOSE

#endif /* Researcher_hpp */
