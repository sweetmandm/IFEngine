//
//  Location.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "Location.hpp"
#include "Physical.hpp"

NS_RAM_OPEN

Location::Location(std::string name, std::string description)
: _name(name)
, _description(description)
{ }

void Location::addObject(Entity *entity) {
    RAM_PARAM_ASSERT(entity->getComponent<Physical>());
    _objects.push_back(entity);
}

void Location::removeObject(Entity *entity) {
    RAM_PARAM_ASSERT(entity->getComponent<Physical>());
    _objects.erase(std::remove(_objects.begin(), _objects.end(), entity));
}

NS_RAM_CLOSE
