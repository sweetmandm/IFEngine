//
//  ObjectMap.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/27/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef ObjectMap_hpp
#define ObjectMap_hpp

#include "RamBase.h"
#include <unordered_map>

NS_RAM_OPEN

class ObjectMap {
private:
    static object_id getUid();
    std::unordered_map<object_id, BaseObject*> _objects;
public:
    static ObjectMap* shared();
    object_id insert(BaseObject *object);
    void remove(object_id id);
    BaseObject* getObject(object_id id);
    
    template<typename T>
    T castObject(object_id id) {
        return dynamic_cast<T>(getObject(id));
    };
};

NS_RAM_CLOSE

#endif /* ObjectMap_hpp */
