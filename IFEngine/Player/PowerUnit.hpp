//
//  PowerUnit.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef PowerUnit_hpp
#define PowerUnit_hpp

#import "RamBase.h"

NS_RAM_OPEN

class PowerSource;

typedef enum {
    PowerUnitTypeGrid
} PowerUnitType;

class PowerUnit {
    PowerUnitType _type;
    int _count;
public:
    static PowerUnit* make(PowerUnitType type, int amount);
    PowerUnitType getType() { return _type; }
    void setType(PowerUnitType type) { _type = type; };
    
    int getCount() { return _count; };
    void setCount(int count) { _count = count; };
};

NS_RAM_CLOSE

#endif /* PowerUnit_hpp */
