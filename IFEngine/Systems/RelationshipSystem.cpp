//
//  RelationshipSystem.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/19/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "RelationshipSystem.hpp"
#include "Relational.hpp"
#include "Entity.hpp"

NS_RAM_OPEN

Relationship* find_relationship(Entity* from, RelationshipType type, BaseObject* to) {
    Relational *userRelation = from->getComponent<Relational>();
    if (userRelation) {
        auto o = userRelation->getRelationshipTo(to);
        return o && o->isType(type) ? o : nullptr;
    } else {
        return nullptr;
    }
}

NS_RAM_CLOSE
