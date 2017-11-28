//
//  ConsciousBeing.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/21/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef ConsciousBeing_hpp
#define ConsciousBeing_hpp

#include "RamBase.h"
#include "Component.hpp"

NS_RAM_OPEN

enum ConsciousBeingState {
    ConsciousBeingStateAlive,
    ConsciousBeingStateAsleep,
    ConsciousBeingStateDead
};

class ConsciousBeing : public Component {
protected:
    ConsciousBeingState _state;
public:
    ConsciousBeing(ConsciousBeingState state);
    ConsciousBeingState getState() { return _state; };
    void setState(ConsciousBeingState state) { _state = state; };
};

NS_RAM_CLOSE

#endif /* ConsciousBeing_hpp */
