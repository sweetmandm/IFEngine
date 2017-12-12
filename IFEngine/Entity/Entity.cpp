//
//  Entity.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/15/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "Entity.hpp"
#include <typeindex>
#include "Component.hpp"

NS_RAM_OPEN

void Entity::addComponent(Component *component) {
    component->setOwner(this);
    _components.insert({std::type_index(typeid(*component)), component});
};

void Entity::removeComponent(Component *component) {
    component->setOwner(nullptr);
    _components.erase(std::type_index(typeid(*component)));
};

NS_RAM_CLOSE
