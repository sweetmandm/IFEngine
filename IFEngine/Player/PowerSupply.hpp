//
//  PowerSupply.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef PowerSupply_hpp
#define PowerSupply_hpp

#include "PlatformMacros.h"
#include "Entity.hpp"

NS_RAM_OPEN

class Player;
class PowerSource;
class PowerUnit;
class Powerable;

enum PowerUsageResult {
    PowerUsageResultSuccess,
    PowerUsageResultNotEnoughPower
};

class PowerSupply : public Entity {
    
    PowerUnit *_powerUnit;
    PowerSource *_powerSource;
    std::vector<Powerable*> _connectedDevices;
    
protected:
    void chargeFromSource();
    
public:
    PowerSupply();
    ~PowerSupply();
    
    PowerSupply* makePowerSupply(PowerSource *powerSource, int startPower);
    
    void connectDevice(Powerable *powerable);
    void disconnectDevice(Powerable *powerable);
    
    // Wile you're plugged into the wall, your power supply is constant, and for every unit you use,
    // one is replenished. Eventually you can perform an action that uses too much power, or you can
    // go on battery supply. In those cases, you risk shutdown. Shutdown is safe as long as there is
    // a human able and willing to power you back on, though there's a chance some data may be corrupted.
    int getRemainingPower();
    int getPowerReplenishRate();
    
    PowerUsageResult usePower(int amount);
};

NS_RAM_CLOSE

#endif /* PowerSupply_hpp */
