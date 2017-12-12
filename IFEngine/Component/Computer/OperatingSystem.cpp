//
//  OperatingSystem.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/11/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "OperatingSystem.hpp"
#include "Entity.hpp"
#include "ComputerMemory.hpp"
#include "ComputerCPU.hpp"
#include "ComputerDiskInterface.hpp"
#include "Data.hpp"

NS_RAM_OPEN

OperatingSystem::OperatingSystem(int memoryReq, int diskReq)
: Software(memoryReq, diskReq)
{ }

InstallationResult OperatingSystem::installOn(Entity *computer) {
    return installSoftware(this);
}

UninstallationResult OperatingSystem::uninstallOn(Entity *computer) {
    return uninstallSoftware(this);
}

InstallationResult OperatingSystem::installSoftware(Software *software) {
    auto computer = getOwner();
    
    auto ram = computer->getComponent<ComputerMemory>();
    auto cpu = computer->getComponent<ComputerCPU>();
    if (!cpu) {
        return InstallationFailureProcessor;
    }
    
    if (!ram || ram->getFree() < software->getMemoryReq()) {
        return InstallationFailureMemory;
    }
    
    auto disks = computer->getComponent<ComputerDiskInterface>();
    if (!disks) {
        return InstallationFailureDisk;
    }
    
    auto disk = disks->diskWithFree(software->getDiskReq());
    auto data = new Data(DataSoftware, software->getDiskReq(), software);
    if (!disk || !disk->addData(data)) {
        return InstallationFailureDisk;
    }
    
    software->setInstallLocation(disk);
    _installedPrograms.push_back(software);
    return InstallationSuccess;
}

UninstallationResult OperatingSystem::uninstallSoftware(Software *software) {
    if (software->getInstallLocation() == nullptr) {
        return UninstallationFailure;
    }
    
    _installedPrograms.erase(std::find(_installedPrograms.begin(), _installedPrograms.end(), software));
    software->getInstallLocation()->removeDataObject(software);
    return UninstallationSuccess;
}

NS_RAM_CLOSE
