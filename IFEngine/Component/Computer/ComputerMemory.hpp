//
//  ComputerMemory.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/10/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef ComputerMemory_hpp
#define ComputerMemory_hpp

#include "Component.hpp"

NS_RAM_OPEN

class ComputerMemory : public Component {
    int _size;
    int _free;
    int _used;
public:
    ComputerMemory(int sizeInMB);
    int getSize() { return _size; };
    int getFree() { return _free; };
    int getUsed() { return _used; };

};

NS_RAM_CLOSE

#endif /* ComputerMemory_hpp */
