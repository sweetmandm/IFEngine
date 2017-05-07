//
//  Happiness.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "Happiness.hpp"

NS_RAM_OPEN

Happiness::Happiness(int defaultValue) : Emotion(defaultValue) { }

Happiness::~Happiness() { }

std::string Happiness::name()
{
    return "happiness";
}

std::string Happiness::descriptionForLevel(EmotionLevel level)
{
    switch (level) {
        case EmotionLevelDownBottom:    { return "despairing"; }
        case EmotionLevelDownFour:      { return "despairing"; }
        case EmotionLevelDownThree:     { return "miserable"; }
        case EmotionLevelDownTwo:       { return "depressed"; }
        case EmotionLevelDownOne:       { return "melancholic"; }
        case EmotionLevelFlat:          { return "flat"; }
        case EmotionLevelUpOne:         { return "pleasant"; }
        case EmotionLevelUpTwo:         { return "happy"; }
        case EmotionLevelUpThree:       { return "elated"; }
        case EmotionLevelUpFour:        { return "ecstatic"; }
        case EmotionLevelUpTop:         { return "ecstatic"; }
    }
}

NS_RAM_CLOSE
