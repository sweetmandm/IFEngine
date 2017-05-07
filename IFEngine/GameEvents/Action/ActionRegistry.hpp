//
//  ActionRegistry.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/22/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef ActionRegistry_hpp
#define ActionRegistry_hpp

#include "RamBase.h"
#include <string>
#include <map>

NS_RAM_OPEN

class Action;

class ActionRegistry {

protected:
    ActionRegistry();
    ~ActionRegistry();
    std::map<std::string, Action*> map;
    
public:
    static ActionRegistry* shared();
    Action* get(std::string name);
    void remove(std::string name);
    void reset();

    template <class T>
    void set(const T& action)
    {
        static_assert(std::is_base_of<Action, T>::value, "You can only send actions in here");
        auto actionPtr = new T(action);
        auto result = map.insert({actionPtr->getLabel(), actionPtr});
        if (!result.second) {
            RAM_ASSERT(result.second, "Failed to insert this Action into the map");
            SAFE_DELETE(actionPtr);
        }
    };
};

NS_RAM_CLOSE

#endif /* ActionRegistry_hpp */
