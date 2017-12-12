//
//  ComputerMemory.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/10/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "ComputerMemory.hpp"

NS_RAM_OPEN

ComputerMemory::ComputerMemory(int sizeInMB)
: _size(sizeInMB)
, _free(sizeInMB)
, _used(0)
{ }

NS_RAM_CLOSE
