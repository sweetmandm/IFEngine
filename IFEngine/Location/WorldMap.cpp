//
//  WorldMap.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/27/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "WorldMap.hpp"
#include "ResearchOffice.hpp"

NS_RAM_OPEN

WorldMap* WorldMap::generate() {
    WorldMap *map = new WorldMap();
    map->_location = new ResearchOffice();
    return map;
}



NS_RAM_CLOSE
