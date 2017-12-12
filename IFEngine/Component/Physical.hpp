//
//  Physical.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/10/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef Physical_hpp
#define Physical_hpp

#include "Component.hpp"

NS_RAM_OPEN

class Location;
class Entity;

class Physical : public Component {
protected:
    Location *_location;
public:
    Location* getLocation() { return _location; };
    void moveTo(Location *location);
};

NS_RAM_CLOSE

#endif /* Physical_hpp */
