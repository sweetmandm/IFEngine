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
#include <unordered_map>
#include <typeindex>
//#include "Component.hpp"

NS_RAM_OPEN

class Component;

class Entity: public BaseObject {
protected:
    std::unordered_map<std::type_index, Component*> _components;
public:
    void addComponent(Component *component);
    
    void removeComponent(Component *component);
    
    std::unordered_map<std::type_index, Component*> getAllComponents() { return _components; }
    
    template<typename T>
    T* getComponent() {
        Component* result = _components[std::type_index(typeid(T))];
        return dynamic_cast<T*>(result);
    }
};

NS_RAM_CLOSE

#endif /* Entity_hpp */
