//
//  ActionBlock.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/7/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef ActionBlock_hpp
#define ActionBlock_hpp

#include "RamBase.h"
#include "Action.hpp"
#include <functional>

NS_RAM_OPEN

class ActionBlock : public Action {
    std::function<void(void)> _block;
public:
    ActionBlock(std::string label, std::function<void(void)> block);
    virtual void perform();
};

NS_RAM_CLOSE

#endif /* ActionBlock_hpp */
