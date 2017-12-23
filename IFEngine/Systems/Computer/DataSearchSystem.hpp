//
//  DataSearchSystem.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/22/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef DataSearchSystem_hpp
#define DataSearchSystem_hpp

#include "RamBase.h"
#include "Data.hpp"

NS_RAM_OPEN

class Entity;

class DataSearchSystem {
public:
    static Data* search(Entity *computer);
};

NS_RAM_CLOSE

#endif /* DataSearchSystem_hpp */
