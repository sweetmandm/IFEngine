//
//  WorldMap.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/27/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef WorldMap_hpp
#define WorldMap_hpp

#include "RamBase.h"
#include "Location.hpp"

NS_RAM_OPEN

class WorldMap {
    Location* _location;
public:
    static WorldMap* generate();
    
    Location* getLocation() { return _location; };
};

NS_RAM_CLOSE

#endif /* WorldMap_hpp */
