//
//  OperatingSystem.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/11/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef OperatingSystem_hpp
#define OperatingSystem_hpp

#include "Software.hpp"

NS_RAM_OPEN

class OperatingSystem : public Software {
    std::vector<Software*> _installedPrograms;
public:
    OperatingSystem(int memoryReq, int diskReq);
    virtual InstallationResult installOn(Entity *computer);
    virtual UninstallationResult uninstallOn(Entity *computer);
    InstallationResult installSoftware(Software *software);
    UninstallationResult uninstallSoftware(Software *software);
};

NS_RAM_CLOSE

#endif /* OperatingSystem_hpp */
