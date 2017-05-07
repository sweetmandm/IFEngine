//
//  Anger.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Anger_hpp
#define Anger_hpp

#include "Emotion.hpp"

NS_RAM_OPEN

class Anger : public Emotion {
    
public:
    Anger(int defaultValue);
    ~Anger();
    
    virtual std::string name();
    virtual std::string descriptionForLevel(EmotionLevel level);
    
};

NS_RAM_CLOSE

#endif /* Anger_hpp */
