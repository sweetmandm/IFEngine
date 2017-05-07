//
//  Emotion.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "Emotion.hpp"

NS_RAM_OPEN

Emotion::Emotion(int defaultValue)
{
    limitEmotion(defaultValue);
    _value = defaultValue;
};

Emotion::~Emotion() { };

int value; /* -100 to +100 */

EmotionLevel Emotion::emotionLevelForCurrentValue() {
    EmotionLevel level = EmotionLevelFlat;
    /**
     *  This search should be exhaustive of all possible values, from -100 to +100.
     */
    switch (value) {
        case EmotionLevelDownBottom:                            { level = EmotionLevelDownBottom; }
        case EmotionLevelDownBottom+1 ... EmotionLevelDownFour: { level = EmotionLevelDownFour; }
        case EmotionLevelDownFour+1 ... EmotionLevelDownThree:  { level = EmotionLevelDownThree; }
        case EmotionLevelDownThree+1 ... EmotionLevelDownTwo:   { level = EmotionLevelDownTwo; }
        case EmotionLevelDownTwo+1 ... EmotionLevelDownOne:     { level = EmotionLevelDownOne; }
        case EmotionLevelFlat:                                  { level = EmotionLevelFlat; }
        case EmotionLevelFlat+1 ... EmotionLevelUpOne:          { level = EmotionLevelUpOne; }
        case EmotionLevelUpOne+1 ... EmotionLevelUpTwo:         { level = EmotionLevelUpTwo; }
        case EmotionLevelUpTwo+1 ... EmotionLevelUpThree:       { level = EmotionLevelUpThree; }
        case EmotionLevelUpThree+1 ... EmotionLevelUpFour:      { level = EmotionLevelUpFour; }
        case EmotionLevelUpTop:                                 { level = EmotionLevelUpTop; }
    }
    return level;
}

std::string Emotion::descriptionForCurrentLevel() {
    auto level = emotionLevelForCurrentValue();
    return descriptionForLevel(level);
}

void Emotion::applyValue(int value)
{
    int intermediate = _value + value;
    // limit to the emotional range:
    _value = fmax(EMOTION_MIN_VALUE, fmin(EMOTION_MAX_VALUE, intermediate));
}

NS_RAM_CLOSE
