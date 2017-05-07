//
//  Researcher.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "Researcher.hpp"
#include "EmotionalState.hpp"
#include "GoalResearchAI.hpp"

NS_RAM_OPEN

Researcher::Researcher()
{
    _goal = new GoalResearchAI([]() {
        RAM_LOG("Succeded Research AI");
    }, []() {
        RAM_LOG("Failed Research AI");
    }, nullptr);
}

Researcher::~Researcher() { }

Researcher* Researcher::makeNew()
{
    auto researcher = new Researcher();
    researcher->_emotionalState = Researcher::defaultEmotionalState();
    return researcher;
}

EmotionalState* Researcher::defaultEmotionalState()
{
    return new EmotionalState(new Happiness(0), new Fear(0), new Motivation(0), new Anger(0));
}

void Researcher::playTurn()
{
    RAM_LOG("TODO: Give the researcher something to do on his turn.");
}

NS_RAM_CLOSE