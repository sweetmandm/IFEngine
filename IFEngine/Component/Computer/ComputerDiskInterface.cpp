//
//  ComputerDiskInterface.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/10/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "ComputerDiskInterface.hpp"

NS_RAM_OPEN

ComputerDiskInterface::ComputerDiskInterface(std::vector<ComputerSSD*> disks)
: _disks(disks)
{
    for (auto disk : disks) {
        disk->setOwner(this);
    }
}

NS_RAM_CLOSE
