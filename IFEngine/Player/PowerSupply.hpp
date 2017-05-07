//
//  PowerSupply.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef PowerSupply_hpp
#define PowerSupply_hpp

#include "TurnPiece.hpp"

NS_RAM_OPEN

class Player;
class PowerSource;
class PowerUnit;

enum PowerUsageResult {
    PowerUsageResultSuccess,
    PowerUsageResultNotEnoughPower
};

class PowerSupply : public TurnPiece {
    
    PowerUnit *_powerUnit;
    PowerSource *_powerSource;
    Player *_owner;
    
protected:
    // Called once each playTurn()
    void chargeFromSource();
    
public:
    PowerSupply();
    ~PowerSupply();
    
    PowerSupply* makePowerSupply(PowerSource *powerSource, int startPower);
    
    // Wile you're plugged into the wall, your power supply is constant, and for every unit you use,
    // one is replenished. Eventually you can perform an action that uses too much power, or you can
    // go on battery supply. In those cases, you risk shutdown. Shutdown is safe as long as there is
    // a human able and willing to power you back on, though there's a chance some data may be corrupted.
    int getRemainingPower();
    int getPowerReplenishRate();
    
    // The owner of the power supply calls this method directly if the owner is powered on.
    PowerUsageResult usePower(int amount);
    
    // - TurnPiece
    virtual void playTurn();
};

NS_RAM_CLOSE

#endif /* PowerSupply_hpp */
