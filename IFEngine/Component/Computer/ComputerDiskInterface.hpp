//
//  ComputerDiskInterface.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/10/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef ComputerDiskInterface_hpp
#define ComputerDiskInterface_hpp

#include "Component.hpp"
#include "ComputerSSD.hpp"

NS_RAM_OPEN

class ComputerDiskInterface : public Component {
    std::vector<ComputerSSD*> _disks;
public:
    ComputerDiskInterface(std::vector<ComputerSSD*> disks);
    std::vector<ComputerSSD*> getDisks() { return _disks; };
    
    ComputerSSD* diskWithFree(int blockSize) {
        auto found = std::find_if(_disks.begin(), _disks.end(), [blockSize](ComputerSSD *disk) {
            return disk->getFree() >= blockSize;
        });
        if (found == _disks.end()) {
            return nullptr;
        } else {
            return *found;
        }
    }
};

NS_RAM_CLOSE

#endif /* ComputerDiskInterface_hpp */
