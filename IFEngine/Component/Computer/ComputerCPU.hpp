//
//  ComputerCPU.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/10/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef ComputerCPU_hpp
#define ComputerCPU_hpp

#include "Component.hpp"

NS_RAM_OPEN

class ComputerCPU: public Component {
    int _cores;
    float _clockSpeed;
public:
    ComputerCPU(int cores, float clockSpeed);
    int getCores() { return _cores; };
    float getClockSpeed() { return _clockSpeed; };
};

NS_RAM_CLOSE

#endif /* ComputerCPU_hpp */
