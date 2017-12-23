//
//  ComputerSSD.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/10/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef ComputerSSD_hpp
#define ComputerSSD_hpp

#include "RamBase.h"

NS_RAM_OPEN

class Data;
class ComputerDiskInterface;

class ComputerSSD {
    ComputerDiskInterface *_owner;
    int _size;
    int _used;
    std::vector<Data> _data;
public:
    ComputerSSD(int sizeInMB);
    ComputerDiskInterface* getOwner() { return _owner; };
    void setOwner(ComputerDiskInterface* owner) { _owner = owner; };
    int getSize() { return _size; };
    int getFree() { return _size - _used; };
    int getUsed() { return _used; };
    bool addData(Data data);
    void removeDataObject(BaseObject *dataObject);
    Data* randomDataItem();
};

NS_RAM_CLOSE

#endif /* ComputerSSD_hpp */
