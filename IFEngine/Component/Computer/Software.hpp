//
//  Software.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/11/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef Software_hpp
#define Software_hpp

#include "Component.hpp"

NS_RAM_OPEN

class ComputerSSD;

enum InstallationResult {
    InstallationSuccess,
    InstallationFailureProcessor,
    InstallationFailureMemory,
    InstallationFailureDisk
};

enum UninstallationResult {
    UninstallationSuccess,
    UninstallationFailure
};

class Software : public Component {
    int _memoryReq;
    int _diskReq;
    int _pid;
    ComputerSSD *_installLocation;
public:

    Software(int memoryReq, int diskReq);
    
    ComputerSSD* getInstallLocation() { return _installLocation; };
    void setInstallLocation(ComputerSSD *disk) { _installLocation = disk; };
    int getMemoryReq() { return _memoryReq; };
    int getDiskReq() { return _diskReq; };
    
    Entity* getComputer();
    virtual InstallationResult installOn(Entity *computer);
    virtual UninstallationResult uninstallOn(Entity *computer);
    
    void setPid(int pid) { _pid = pid; };
    bool isRunning() { return _pid > -1; };
    virtual bool start();
    virtual bool kill();
};

NS_RAM_CLOSE

#endif /* Software_hpp */
