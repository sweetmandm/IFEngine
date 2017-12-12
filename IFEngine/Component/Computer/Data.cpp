//
//  Data.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/11/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "Data.hpp"

NS_RAM_OPEN

Data::Data(DataType type, int size, BaseObject *data)
: _type(type)
, _size(size)
, _data(data)
{ }

NS_RAM_CLOSE
