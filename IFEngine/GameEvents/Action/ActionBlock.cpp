//
//  ActionBlock.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/7/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "ActionBlock.hpp"
#include <string>

NS_RAM_OPEN

ActionBlock::ActionBlock(std::string label, std::function<void(void)> block)
: Action(label, ActionTypeBlock)
, _block(block)
{ }

void ActionBlock::perform() {
    _block();
}

NS_RAM_CLOSE
