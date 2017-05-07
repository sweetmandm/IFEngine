//
//  Happiness.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Happiness_hpp
#define Happiness_hpp

#include "Emotion.hpp"

NS_RAM_OPEN

class Happiness : public Emotion {
    
public:
    Happiness(int defaultValue);
    ~Happiness();
    
    virtual std::string name();
    virtual std::string descriptionForLevel(EmotionLevel level);
    
};

NS_RAM_CLOSE

#endif /* Happiness_hpp */
