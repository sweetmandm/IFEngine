//
//  TTS.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/12/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef TTS_hpp
#define TTS_hpp

#include "RamBase.h"
#include <string>

NS_RAM_OPEN

class TTS {
public:
    static void speak(std::string text);
};

NS_RAM_CLOSE

#endif /* TTS_hpp */
