//
//  RamBase.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/28/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "RamBase.h"
#include "ObjectMap.hpp"

NS_RAM_OPEN

BaseObject::BaseObject() {
    _objectId = ObjectMap::shared()->insert(this);
}

BaseObject::~BaseObject() {
    ObjectMap::shared()->remove(_objectId);
}

NS_RAM_CLOSE
