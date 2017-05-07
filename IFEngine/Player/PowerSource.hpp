//
//  PowerSource.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef PowerSource_hpp
#define PowerSource_hpp

#include "RamBase.h"
#include "PowerUnit.hpp"

NS_RAM_OPEN

class PowerSource {
    
    PowerUnitType _type;
    int _replenishRate;
    int _quantity; /* -1 if effectively infinite */
    bool _mobile = false;
    
public:
    PowerSource();
    ~PowerSource();
    
    int getReplenishRate() { return _replenishRate; }
    PowerUnitType getType() { return _type; }
    
    /**
     * Will reduce quantity by the 'count' of PowerUnit. Might be empty.
     */
    PowerUnit transmitPower();
    bool isInfiniteSource() { return _quantity == -1; };
};

NS_RAM_CLOSE

#endif /* PowerSource_hpp */
