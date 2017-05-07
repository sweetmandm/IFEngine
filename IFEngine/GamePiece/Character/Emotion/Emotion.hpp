//
//  Emotion.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Emotion_hpp
#define Emotion_hpp

#include "RamBase.h"
#include <string>

NS_RAM_OPEN

#define EMOTION_MIN_VALUE -100
#define EMOTION_MAX_VALUE 100
#define limitEmotion(x) ({ \
    RAM_ASSERT(x >= EMOTION_MIN_VALUE && x <= EMOTION_MAX_VALUE, "Emotion levels range -100 to +100."); \
    x = fmin(EMOTION_MAX_VALUE, fmax(EMOTION_MIN_VALUE, x));\
    x; \
})

// Emotional range is a defined by EMOTION_MIN_VALUE - EMOTION_MAX_VALUE
enum EmotionLevel {
    EmotionLevelDownBottom  = -100,
    EmotionLevelDownFour    = /* -99 to */ -76,
    EmotionLevelDownThree   = /* -75 to */ -51,
    EmotionLevelDownTwo     = /* -50 to */ -26,
    EmotionLevelDownOne     = /* -25 to */ -1,
    EmotionLevelFlat        = 0,
    EmotionLevelUpOne       = /* 1 to */ 25,
    EmotionLevelUpTwo       = /* 26 to */ 50,
    EmotionLevelUpThree     = /* 51 to */ 75,
    EmotionLevelUpFour      = /* 76 to */ 99,
    EmotionLevelUpTop       = 100
};

class Emotion {
    
    int _value; /* -100 to +100 */
    
public:
    Emotion(int defaultValue);
    ~Emotion();
    
    int getValue() { return _value; }
    void applyValue(int value); /* limits to EMOTION_MIN_VALUE - EMOTION_MAX_VALUE */
    
    EmotionLevel emotionLevelForCurrentValue();
    std::string descriptionForCurrentLevel();
    
    virtual std::string descriptionForLevel(EmotionLevel level) = 0;
    virtual std::string name() = 0;
};

NS_RAM_CLOSE

#endif /* Emotion_hpp */
