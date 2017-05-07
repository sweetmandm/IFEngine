//
//  PowerUnit.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "PowerUnit.hpp"
#include "PowerSource.hpp"

NS_RAM_OPEN

PowerUnit* PowerUnit::make(PowerUnitType type, int amount) {
    PowerUnit *powerUnit = new PowerUnit();
    powerUnit->setType(type);
    powerUnit->setCount(amount);
    return powerUnit;
}

NS_RAM_CLOSE