//
//  Fear.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Fear_hpp
#define Fear_hpp

#include "Emotion.hpp"

NS_RAM_OPEN

class Fear : public Emotion {
    
public:
    Fear(int defaultValue);
    ~Fear();
    
    virtual std::string name();
    virtual std::string descriptionForLevel(EmotionLevel level);
    
};

NS_RAM_CLOSE

#endif /* Fear_hpp */
