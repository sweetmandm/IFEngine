//
//  PowerSupply.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "PowerSupply.hpp"
#include "PowerUnit.hpp"
#include "PowerSource.hpp"
#include "Player.hpp"

NS_RAM_OPEN

PowerSupply::PowerSupply() { }
PowerSupply::~PowerSupply() {
    SAFE_DELETE(_powerUnit);
}

PowerSupply* PowerSupply::makePowerSupply(PowerSource *powerSource, int startPower) {
    PowerSupply *supply = new PowerSupply();
    supply->_powerSource = powerSource;
    
    auto powerUnit = PowerUnit::make(_powerSource->getType(), startPower);
    supply->_powerUnit = powerUnit;
    
    return supply;
}

void PowerSupply::connectDevice(Powerable *powerable) {
    _connectedDevices.push_back(powerable);
}

void PowerSupply::disconnectDevice(Powerable *powerable) {
    _connectedDevices.erase(std::remove(_connectedDevices.begin(), _connectedDevices.end(), powerable));
}

int PowerSupply::getRemainingPower() { return _powerUnit->getCount(); };
int PowerSupply::getPowerReplenishRate() { return _powerSource->getReplenishRate(); };

void PowerSupply::chargeFromSource() {
    if (_powerSource != nullptr) {
        PowerUnit replenishUnit = _powerSource->transmitPower();
        RAM_ASSERT(replenishUnit.getType() == _powerUnit->getType(), "Incompatible power types");
        int quantity = _powerUnit->getCount() + replenishUnit.getCount();
        _powerUnit->setCount(quantity);
    }
}

PowerUsageResult PowerSupply::usePower(int amount) {
    
    if (_powerUnit->getCount() <= amount) {
        int remaining = _powerUnit->getCount() - amount;
        _powerUnit->setCount(remaining);
        return PowerUsageResultSuccess;
    } else {
        return PowerUsageResultNotEnoughPower;
    }
}

NS_RAM_CLOSE
