//
//  EmotionalState.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "EmotionalState.hpp"
#include <vector>

NS_RAM_OPEN

bool EmotionalStateEqual(EmotionalStateData e1, EmotionalStateData e2)
{
    return (e1.happiness == e2.happiness &&
            e1.motivation == e2.motivation &&
            e1.anger == e2.anger &&
            e1.fear == e2.fear);
}

extern EmotionalStateData EmotionalStateDataZero();

EmotionalState::EmotionalState(Happiness *happiness, Fear *fear, Motivation *motivation, Anger *anger)
{
    _happiness = happiness;
    _fear = fear;
    _motivation = motivation;
    _anger = anger;
}

EmotionalState::EmotionalState(EmotionalStateData data)
: EmotionalState(new Happiness(data.happiness),
                 new Fear(data.fear),
                 new Motivation(data.motivation),
                 new Anger(data.anger))
{ }

EmotionalState::~EmotionalState()
{
    if (_happiness != nullptr) { SAFE_DELETE(_happiness); }
    if (_motivation != nullptr) { SAFE_DELETE(_motivation); }
    if (_fear != nullptr) { SAFE_DELETE(_fear); }
    if (_anger != nullptr) { SAFE_DELETE(_anger); }
}

std::vector<Emotion*> EmotionalState::allEmotions()
{
    /* Ordered by dominance in case of a tie in value. */
    return {_fear, _motivation, _anger, _happiness};
}

Emotion* EmotionalState::dominantEmotion()
{
    auto emotions = allEmotions();
    Emotion *max = nullptr;
    
    for (auto emotion : emotions) {
        if (max == nullptr) {
            max = emotion;
        } else if (abs(emotion->getValue()) > abs(max->getValue())) {
            max = emotion;
        }
    }
    return max;
}

double EmotionalState::distance(EmotionalState state1, EmotionalState state2)
{
    // Euclidian Distance
    // sqrt( (x1-y1)^2 + (x2-y2)^2 + ... (xN-yN)^2 )
    
    // Each element's location in the vector is important. Since allEmotions() gives us
    // a vector ordered by dominance, use that to calculate distance.
    double innerVal = 0.0;
    auto em1 = state1.allEmotions();
    auto em2 = state2.allEmotions();
    for (int i = 0; i < em1.size(); i++) {
        innerVal += pow(em1[i]->getValue() - em2[i]->getValue(), 2);
    }
    
    double distance = sqrt(innerVal);
    return distance;
}

void EmotionalState::apply(EmotionalStateData emotions)
{
    if (EmotionalStateEqual(emotions, EMOTION_ZERO)) {
        return; /* no contribution */
    }
    _happiness->applyValue(emotions.happiness);
    _motivation->applyValue(emotions.motivation);
    _anger->applyValue(emotions.anger);
    _fear->applyValue(emotions.fear);
}

bool EmotionalState::matchesPredicate(EmotionalPredicate predicate)
{
    bool matches = (
                    _happiness->getValue() >= predicate.lower.happiness &&
                    _happiness->getValue() <= predicate.upper.happiness &&
                    
                    _anger->getValue() >= predicate.lower.anger &&
                    _anger->getValue() <= predicate.upper.anger &&
                    
                    _motivation->getValue() >= predicate.lower.motivation &&
                    _motivation->getValue() <= predicate.upper.motivation &&
                    
                    _fear->getValue() >= predicate.lower.fear &&
                    _fear->getValue() <= predicate.upper.fear
                    );
    return matches;
}

NS_RAM_CLOSE
