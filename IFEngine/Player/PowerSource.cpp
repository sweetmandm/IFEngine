//
//  PowerSource.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "PowerSource.hpp"

NS_RAM_OPEN

PowerSource::PowerSource() { }
PowerSource::~PowerSource() { }

PowerUnit PowerSource::transmitPower() {
    PowerUnit powerUnit;
    powerUnit.setType(_type);
    
    // Limit output to the available power:
    int powerToDistribute = fmin(_quantity, _replenishRate);
    
    if (_quantity > 0) {
        RAM_ASSERT(!isInfiniteSource(), "We shouldn't be in here if power is infinite");
        // Decrease the power store:
        _quantity = fmax(0, _quantity - powerToDistribute);
    }
    powerUnit.setCount(powerToDistribute);
    
    return powerUnit;
}

NS_RAM_CLOSE
