//
//  NextActionNone.hpp
//  Ramshackle
//
//  Created by David Sweetman on 2/26/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef NextActionNone_hpp
#define NextActionNone_hpp

#include "NextAction.hpp"

NS_RAM_OPEN

class Action;

class NextActionNone : public NextAction {
public:
    virtual Action* getNext() { return nullptr; };
};

NS_RAM_CLOSE

#endif /* NextActionNone_hpp */
