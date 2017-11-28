//
//  Relational.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/26/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "Relational.hpp"

NS_RAM_OPEN

void Relational::addRelationship(Relationship *relationship) {
    _relationships.insert({relationship->getToId(), relationship});
}

void Relational::removeRelationship(Relationship *relationship) {
    _relationships.erase(relationship->getToId());
}

Relationship* Relational::getRelationshipTo(object_id objectId) {
    return _relationships[objectId];
}

NS_RAM_CLOSE
