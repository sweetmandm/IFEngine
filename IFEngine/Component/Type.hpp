//
//  Type.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/7/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef Type_hpp
#define Type_hpp

#include "RamBase.h"
#include "Component.hpp"
#include <string>

NS_RAM_OPEN

class Type : public Component {
    std::string _type;
public:
    Type(std::string type);
    std::string getType() { return _type; };
};

NS_RAM_CLOSE

#endif /* Type_hpp */
