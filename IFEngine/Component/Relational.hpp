//
//  Relational.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/26/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef Relational_hpp
#define Relational_hpp

#include "RamBase.h"
#include "Component.hpp"
#include "Relationship.hpp"
#include <unordered_map>

NS_RAM_OPEN

class Relational : public Component {
protected:
    std::unordered_map<object_id, Relationship*> _relationships;
    
public:
    void addRelationship(Relationship *relationship);
    void removeRelationship(Relationship *relationship);
    Relationship* getRelationshipTo(object_id objectId);
};

NS_RAM_CLOSE

#endif /* Relational_hpp */
