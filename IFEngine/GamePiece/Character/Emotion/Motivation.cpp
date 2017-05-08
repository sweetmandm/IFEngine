//
//  Motivation.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "Motivation.hpp"

NS_RAM_OPEN

Motivation::Motivation(int defaultValue) : Emotion(defaultValue) { }

Motivation::~Motivation() { }

std::string Motivation::name()
{
    return "motivation";
}

std::string Motivation::descriptionForLevel(EmotionLevel level)
{
    switch (level) {
        case EmotionLevelDownBottom:    { return "down_bottom"; }
        case EmotionLevelDownFour:      { return "down_four"; }
        case EmotionLevelDownThree:     { return "down_three"; }
        case EmotionLevelDownTwo:       { return "down_two"; }
        case EmotionLevelDownOne:       { return "down_one"; }
        case EmotionLevelFlat:          { return "neutral"; }
        case EmotionLevelUpOne:         { return "up_one"; }
        case EmotionLevelUpTwo:         { return "up_two"; }
        case EmotionLevelUpThree:       { return "up_three"; }
        case EmotionLevelUpFour:        { return "up_four"; }
        case EmotionLevelUpTop:         { return "up_top"; }
    }
}

NS_RAM_CLOSE
