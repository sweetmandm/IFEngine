//
//  RamBase.h
//  Ramshackle
//
//  Created by sweetman on 5/7/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef RamBase_h
#define RamBase_h

#include "PlatformMacros.h"

NS_RAM_OPEN

typedef uint32_t object_id;

class BaseObject {
    object_id _objectId;
public:
    object_id getObjectId() { return _objectId; };
    BaseObject();
    virtual ~BaseObject();
};

NS_RAM_CLOSE

#endif /* RamBase_h */
