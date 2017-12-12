//
//  ComputerGenerator.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/10/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef ComputerGenerator_hpp
#define ComputerGenerator_hpp

#include "RamBase.h"

NS_RAM_OPEN

class Entity;
class Router;

class ComputerGenerator {
public:
    static Entity* generateComputer();
    static Entity* generateRouter();
    static void connect(Router *router, std::vector<Entity*> computers);
};

NS_RAM_CLOSE

#endif /* ComputerGenerator_hpp */
