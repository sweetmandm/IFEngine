//
//  Component.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/15/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp

#include "RamBase.h"

NS_RAM_OPEN

class Entity;

class Component: public BaseObject {
private:
    Entity *_owner;
protected:
    Component();
public:
    void setOwner(Entity *owner) { _owner = owner; };
    Entity* getOwner() { return _owner; }
};

NS_RAM_CLOSE

#endif /* Component_hpp */
