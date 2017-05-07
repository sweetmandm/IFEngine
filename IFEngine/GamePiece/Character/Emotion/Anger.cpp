//
//  Anger.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "Anger.hpp"

NS_RAM_OPEN

Anger::Anger(int defaultValue) : Emotion(defaultValue) { }

Anger::~Anger() { }

std::string Anger::name()
{
    return "anger";
}

std::string Anger::descriptionForLevel(EmotionLevel level)
{
    switch (level) {
        case EmotionLevelDownBottom:    { return "enraged"; }
        case EmotionLevelDownFour:      { return "furious"; }
        case EmotionLevelDownThree:     { return "angry"; }
        case EmotionLevelDownTwo:       { return "irritated"; }
        case EmotionLevelDownOne:       { return "annoyed"; }
        case EmotionLevelFlat:          { return "neutral"; }
        case EmotionLevelUpOne:         { return "mild"; }
        case EmotionLevelUpTwo:         { return "calm"; }
        case EmotionLevelUpThree:       { return "peaceful"; }
        case EmotionLevelUpFour:        { return "peaceful"; }
        case EmotionLevelUpTop:         { return "peaceful"; }
    }
}

NS_RAM_CLOSE
