//
//  PlayerSoftwareSystem.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/12/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef PlayerSoftwareSystem_hpp
#define PlayerSoftwareSystem_hpp

#include "RamBase.h"

NS_RAM_OPEN

class Entity;

struct PlayerSoftwareSystem {
    static void start(Entity *player);
};

NS_RAM_CLOSE

#endif /* PlayerSoftwareSystem_hpp */
