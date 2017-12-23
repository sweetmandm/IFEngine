//
//  Data.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/11/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef Data_hpp
#define Data_hpp

#include "Component.hpp"
#include <string>

NS_RAM_OPEN

typedef enum {
    DataTypeSoftware,
    DataTypeImage,
    DataTypeAudio,
    DataTypeText
} DataType;

class Data : public Component {
    
    DataType _type;
    int _size;
    BaseObject *_data;
    
public:
    Data(DataType type, int size, BaseObject *data);
    
    DataType getType() { return _type; };
    int getSize() { return _size; };
    
    template<typename T>
    T getData() { return dynamic_cast<T>(_data); };
    
    BaseObject* getData() { return _data; };
    
    std::string textRepresentation();
};

NS_RAM_CLOSE

#endif /* Data_hpp */
