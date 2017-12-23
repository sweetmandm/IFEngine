//
//  DataGenerator.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/18/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef DataGenerator_hpp
#define DataGenerator_hpp

#include "RamBase.h"
#include "Data.hpp"
#include <vector>

NS_RAM_OPEN

class Data;
class Entity;

class DataGenerator {
public:
    static void generateData(Entity *computer, std::vector<Entity*> users);
};

NS_RAM_CLOSE

#endif /* DataGenerator_hpp */
