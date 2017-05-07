//
//  EmotionalState.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef EmotionalState_hpp
#define EmotionalState_hpp

#include "RamBase.h"
#include "Emotion.hpp"
#include "Happiness.hpp"
#include "Motivation.hpp"
#include "Fear.hpp"
#include "Anger.hpp"

NS_RAM_OPEN

struct EmotionalStateData {
    int happiness;
    int motivation;
    int fear;
    int anger;
};

bool EmotionalStateEqual(EmotionalStateData e1, EmotionalStateData e2);

/** Usage: MakeEmotionalStateData(.happiness = 0, .anger = 0, .motivation = 0, .fear = 0); */
#define MakeEmoData(...) ((struct EmotionalStateData){ __VA_ARGS__ })

#define EMOTION_BOTTOM MakeEmoData(.happiness = -100, .anger = -100, .motivation = -100, .fear = -100)
#define EMOTION_TOP MakeEmoData(.happiness = 100, .anger = 100, .motivation = 100, .fear = 100)
#define EMOTION_ZERO MakeEmoData(.happiness = 0, .anger = 0, .motivation = 0, .fear = 0)

enum Alignment {
    AlignmentNeutral,
    AlignmentGood,
    AlignmentEvil,
    AlignmentChaotic,
    AlignmentAny, // predicate-only, not assignable
};

// Whether or not a player is shown a question/answer is determined based on whether his
// emotional state passes when tested against this predicate:
struct EmotionalPredicate {
    EmotionalStateData lower;
    EmotionalStateData upper;
    Alignment alignment;
};

// A predicate that will return true for all emotional states
#define PREDICATE_MATCH_ALL EmotionalPredicate{.lower = EMOTION_BOTTOM, .upper = EMOTION_TOP, .alignment = AlignmentAny}

// Specify Lower, Upper (default any unspecified values to 'any')
/* "this is perfectly fine by C99, which explicitly provides that where a member is defined twice or more, the last initialization wins out, silencing the prior ones" https://llvm.org/bugs/show_bug.cgi?id=6934
 */
#define PREDICATE_MAKE_LU(L, U) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Winitializer-overrides\"") \
EmotionalPredicate{\
.lower = MakeEmoData(.happiness = -100, .anger = -100, .motivation = -100, .fear = -100, L),\
.upper = MakeEmoData(.happiness = 100, .anger = 100, .motivation = 100, .fear = 100, U),\
.alignment = AlignmentAny}\
_Pragma("clang diagnostic pop")

// Specify Lower, Upper, Alignment (default any unspecified values to 'any')
#define PREDICATE_MAKE_LUA(L, U, A) EmotionalPredicate{\
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Winitializer-overrides\"") \
.lower = MakeEmoData(.happiness = -100, .anger = -100, .motivation = -100, .fear = -100, L),\
.upper = MakeEmoData(.happiness = 100, .anger = 100, .motivation = 100, .fear = 100, U),\
.alignment = A}\
_Pragma("clang diagnostic pop")

// Specify Alignment
#define PREDICATE_MAKE_A(A) EmotionalPredicate{.lower = EMOTION_BOTTOM, .upper = EMOTION_TOP, .alignment = A}

/* unused...but maybe useful?
enum EmotionalStateType {
    
    EmotionalStateTypeFlat          = 0x0000,
    
    EmotionalStateTypeAfraid        = 0x0001,
    EmotionalStateTypeBold          = 0x0002,
    
    EmotionalStateTypeHappy         = 0x0004,
    EmotionalStateTypeSad           = 0x0008,
    
    EmotionalStateTypeMotivated     = 0x0010,
    EmotionalStateTypeDemotivated   = 0x0020,
    
    EmotionalStateTypeAngry         = 0x0040,
    EmotionalStateTypeCaring        = 0x0080,
    
};
*/

class EmotionalState {
    
protected:
    Happiness *_happiness;
    Motivation *_motivation;
    Fear *_fear;
    Anger *_anger;
    
    // all emotions ordered by descending dominance
    std::vector<Emotion*> allEmotions();
    
public:
    // Construct an emotional state from Data values:
    EmotionalState(EmotionalStateData data);
    
    // Construct an emotional state from emotion objects:
    EmotionalState(Happiness *happiness,
                   Fear *fear,
                   Motivation *motivation,
                   Anger *anger);
    
    ~EmotionalState();
    
    Emotion* dominantEmotion();
    
    static double distance(EmotionalState state1, EmotionalState state2);
    
    void apply(EmotionalStateData emotions);
    
    bool matchesPredicate(EmotionalPredicate predicate);
};

NS_RAM_CLOSE

#endif /* EmotionalState_hpp */
