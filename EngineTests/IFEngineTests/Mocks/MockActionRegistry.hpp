//
//  MockActionRegistry.hpp
//  Ramshackle
//
//  Created by David Sweetman on 2/25/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef MockActionRegistry_hpp
#define MockActionRegistry_hpp

#include "ActionRegistry.hpp"

using namespace ram;

class MockActionRegistry : public ActionRegistry {
public:
    MockActionRegistry();
    ~MockActionRegistry();
};

#endif /* MockActionRegistry_hpp */
