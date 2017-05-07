//
//  ActionPrompt.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/22/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "ActionPrompt.hpp"

NS_RAM_OPEN

ActionPrompt::ActionPrompt(std::string label, Prompt prompt)
: Action(label, ActionTypePrompt)
, _prompt(prompt)
{ }

ActionPrompt::~ActionPrompt() { }

NS_RAM_CLOSE