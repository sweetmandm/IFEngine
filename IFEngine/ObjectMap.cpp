//
//  ObjectMap.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/27/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "ObjectMap.hpp"

NS_RAM_OPEN

static ObjectMap *instance = nullptr;

ObjectMap* ObjectMap::shared()
{
    if (instance == nullptr) {
        instance = new (std::nothrow) ObjectMap();
    }
    return instance;
}

object_id ObjectMap::getUid() {
    static std::atomic<object_id> uid { 0 };
    return ++uid;
}

object_id ObjectMap::insert(BaseObject *object) {
    object_id id = ObjectMap::getUid();
    _objects.insert({id, object});
    return id;
}

BaseObject* ObjectMap::getObject(object_id id) {
    return _objects[id];
}

void ObjectMap::remove(object_id id) {
    _objects.erase(id);
}

NS_RAM_CLOSE
