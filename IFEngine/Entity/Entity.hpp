//
//  Entity.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/15/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include "RamBase.h"
#include <vector>
#include "Component.hpp"

NS_RAM_OPEN


class Entity: public BaseObject {
protected:
    std::vector<Component*> _components;
public:
    std::vector<Component*> getComponents() { return _components; };
    
    void addComponent(Component *component) { _components.push_back(component); };
    
    template<typename T>
    T getComponent() {
        auto result = std::find_if(_components.begin(),
                                   _components.end(),
                                   [](Component *s) { return typeid(*s) == typeid(T); });
        if (result == _components.end()) {
            return nullptr;
        } else {
            return dynamic_cast<T>(*result);
        }
    }
};

NS_RAM_CLOSE

#endif /* Entity_hpp */
