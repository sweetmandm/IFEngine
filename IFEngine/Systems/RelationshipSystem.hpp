//
//  RelationshipSystem.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/19/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef RelationshipSystem_hpp
#define RelationshipSystem_hpp

#include "RamBase.h"
#include "Relationship.hpp"

NS_RAM_OPEN

class Entity;

extern Relationship* find_relationship(Entity* from, RelationshipType type, BaseObject* to);

NS_RAM_CLOSE

#endif /* RelationshipSystem_hpp */
