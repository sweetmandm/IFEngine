//
//  Relationship.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/26/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef Relationship_hpp
#define Relationship_hpp

#include "RamBase.h"
#include "Component.hpp"
#include "Entity.hpp"
#include <string>

NS_RAM_OPEN

class Relationship {
protected:
    Relationship *_inverse;
    object_id _fromEntityID;
    object_id _toEntityID;
    std::string _description;
public:
    Relationship(Entity *from, Entity *to, std::string description);
    object_id getFromId() { return _fromEntityID; };
    object_id getToId() { return _toEntityID; };
    Entity* getFrom();
    Entity* getTo();
    Relationship* getInverse() { return _inverse; };
    void setInverse(Relationship *relationship) { _inverse = relationship; };
    void setDescription(std::string description) { _description = description; };
};

NS_RAM_CLOSE

#endif /* Relationship_hpp */
