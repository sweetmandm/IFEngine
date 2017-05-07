//
//  ActionPrompt.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/22/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef ActionPrompt_hpp
#define ActionPrompt_hpp

#include "Action.hpp"
#include <string>

NS_RAM_OPEN

struct Prompt {
    std::string text;
};

class ActionPrompt : public Action {
    Prompt _prompt;
    
public:
    ActionPrompt(std::string label, Prompt prompt);
    ~ActionPrompt();
    Prompt getPrompt() { return _prompt; };
};

NS_RAM_CLOSE

#endif /* ActionPrompt_hpp */
