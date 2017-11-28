//
//  Powerable.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/24/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "Powerable.hpp"

NS_RAM_OPEN

Powerable::Powerable()
: _status(PowerStatusRunning)
, _powerSupply(nullptr)
, _energyUsageLevel(0)
{ }

bool Powerable::isPowerdOn() {
    return _status == PowerStatusRunning;
}

Powerable::~Powerable() {
    _powerSupply->disconnectDevice(this);
}

NS_RAM_CLOSE
