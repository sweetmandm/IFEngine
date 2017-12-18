 //
//  Software.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/11/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "Software.hpp"
#include "Entity.hpp"
#include "ComputerCPU.hpp"
#include "ComputerSSD.hpp"
#include "ComputerMemory.hpp"
#include "ComputerDiskInterface.hpp"
#include "OperatingSystem.hpp"

NS_RAM_OPEN

Software::Software(int memoryReq, int diskReq)
: _memoryReq(memoryReq)
, _diskReq(diskReq)
, _installLocation(nullptr)
, _pid(-1)
{ }

Entity* Software::getComputer() {
    auto disk = getInstallLocation();
    if (disk) {
        auto diskIf = disk->getOwner();
        if (diskIf) {
            return diskIf->getOwner();
        }
    }
    return nullptr;
}

InstallationResult Software::installOn(Entity *computer) {
    auto os = computer->getComponent<OperatingSystem>();
    return os->installSoftware(this);
}

UninstallationResult Software::uninstallOn(Entity *computer) {
    auto os = computer->getComponent<OperatingSystem>();
    return os->uninstallSoftware(this);
}

bool Software::start() {
    return true;
}

bool Software::kill() {
    _pid = -1;
    return true;
}

NS_RAM_CLOSE
