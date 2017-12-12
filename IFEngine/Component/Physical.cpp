//
//  Physical.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/10/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "Physical.hpp"
#include "Location.hpp"

NS_RAM_OPEN

void Physical::moveTo(Location *location) {
    Entity *owner = this->getOwner();
    if (_location) {
        _location->removeObject(owner);
    }
    _location = location;
    if (_location) {
        _location->addObject(owner);
    }
}

NS_RAM_CLOSE
