//
//  ComputerSSD.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/10/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "ComputerSSD.hpp"
#include "Software.hpp"
#include "Data.hpp"

NS_RAM_OPEN

ComputerSSD::ComputerSSD(int sizeInMB)
: _size(sizeInMB)
, _used(0)
{ }

void ComputerSSD::removeDataObject(BaseObject *dataObject) {
    auto found = std::find_if(_data.begin(), _data.end(), [dataObject](Data *data) {
        return data->getData() == dataObject;
    });
    if (found == _data.end()) { return; }
    auto data = *found;
    _used = std::max(0, _used - data->getSize());
    _data.erase(found);
}

bool ComputerSSD::addData(Data *data) {
    if (_used + data->getSize() > _size) {
        return false;
    }
    _used += data->getSize();
    _data.push_back(data);
    return true;
};

NS_RAM_CLOSE
