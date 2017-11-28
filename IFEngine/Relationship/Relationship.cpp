//
//  Relationship.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/26/17.
//  Copyright © 2017 tinfish. All rights reserved.
//


#include "Relationship.hpp"
#include "ObjectMap.hpp"

NS_RAM_OPEN

Relationship::Relationship(Entity *from, Entity *to)
: _fromEntityID(from->getObjectId())
, _toEntityID(to->getObjectId())
{ }

Entity* Relationship::getFrom() {
    return ObjectMap::shared()->castObject<Entity*>(_fromEntityID);
}

Entity* Relationship::getTo() {
    return ObjectMap::shared()->castObject<Entity*>(_toEntityID);
}

NS_RAM_CLOSE
