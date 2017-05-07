//
//  Fear.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "Fear.hpp"

NS_RAM_OPEN

Fear::Fear(int defaultValue) : Emotion(defaultValue) { }

Fear::~Fear() { }

std::string Fear::name()
{
    return "fear";
}

std::string Fear::descriptionForLevel(EmotionLevel level)
{
    switch (level) {
        case EmotionLevelDownBottom:    { return "down_bottom"; }
        case EmotionLevelDownFour:      { return "down_four"; }
        case EmotionLevelDownThree:     { return "down_three"; }
        case EmotionLevelDownTwo:       { return "down_two"; }
        case EmotionLevelDownOne:       { return "down_one"; }
        case EmotionLevelFlat:          { return "neutral"; }
        case EmotionLevelUpOne:         { return "up_on"; }
        case EmotionLevelUpTwo:         { return "up_two"; }
        case EmotionLevelUpThree:       { return "up_three"; }
        case EmotionLevelUpFour:        { return "up_four"; }
        case EmotionLevelUpTop:         { return "up_top"; }
    }
}

NS_RAM_CLOSE
