//
//  Powerable.h
//  Ramshackle
//
//  Created by David Sweetman on 12/19/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Powerable_h
#define Powerable_h

#include "RamBase.h"
#include "PowerSupply.hpp"
#include "Component.hpp"

NS_RAM_OPEN

enum PowerStatus {
    PowerStatusRunning,
    PowerStatusNotRunning
};

class Powerable: public Component {
protected:
    PowerSupply *_powerSupply;
    PowerStatus _status;
    int _energyUsageLevel;
    
public:
    Powerable();
    ~Powerable();
    int getEnergyUsageLevel() { return _energyUsageLevel; };
    void setEnergyUsageLevel(int energyUsageLevel) { _energyUsageLevel = energyUsageLevel; };
    bool isPowerdOn();
    void setPowerSupply(PowerSupply *powerSupply);
    PowerStatus getStatus() { return _status; };
    void setStatus(PowerStatus status) { _status = status; };
};

NS_RAM_CLOSE

#endif /* Powerable_h */
