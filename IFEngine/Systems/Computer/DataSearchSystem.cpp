//
//  DataSearchSystem.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/22/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "DataSearchSystem.hpp"
#include "Entity.hpp"
#include "ComputerDiskInterface.hpp"
#include "ComputerSSD.hpp"

NS_RAM_OPEN

Data* DataSearchSystem::search(Entity *computer) {
    auto dif = computer->getComponent<ComputerDiskInterface>();
    auto disks = dif->getDisks();
    return disks[0]->randomDataItem();
}

NS_RAM_CLOSE
