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
#include "ResearchOffice.hpp"

NS_RAM_OPEN

class WorldMap {
    ResearchOffice* _startLocation;
public:
    static WorldMap* generate();
    
    ResearchOffice* getStartLocation() { return _startLocation; };
};

NS_RAM_CLOSE

#endif /* WorldMap_hpp */
