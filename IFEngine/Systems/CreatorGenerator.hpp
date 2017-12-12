//
//  CreatorGenerator.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/28/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef CreatorGenerator_hpp
#define CreatorGenerator_hpp

#include "RamBase.h"
#include "Entity.hpp"

NS_RAM_OPEN

class CreatorGenerator {
public:
    static Entity* generateCreator();
    static Entity* createPlayerEntity(Entity *creator, Entity *computer);
};

NS_RAM_CLOSE

#endif /* CreatorGenerator_hpp */
