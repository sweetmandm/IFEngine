//
//  Motivation.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Motivation_hpp
#define Motivation_hpp

#include "Emotion.hpp"

NS_RAM_OPEN

class Motivation : public Emotion {
    
public:
    Motivation(int defaultValue);
    ~Motivation();
    
    virtual std::string name();
    virtual std::string descriptionForLevel(EmotionLevel level);
    
};

NS_RAM_CLOSE

#endif /* Motivation_hpp */
