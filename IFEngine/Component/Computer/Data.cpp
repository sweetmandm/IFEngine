//
//  Data.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/11/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "Data.hpp"
#include "DataContentText.hpp"

NS_RAM_OPEN

Data::Data(DataType type, int size, BaseObject *data)
: _type(type)
, _size(size)
, _data(data)
{ }

std::string Data::textRepresentation() {
    switch (getType()) {
        case DataTypeSoftware:
            break;
        case DataTypeImage:
            break;
        case DataTypeAudio:
            break;
        case DataTypeText:
            auto data = dynamic_cast<DataContentText*>(_data);
            if (data) {
                return data->getContent();
            }
    }
    return "";
}

NS_RAM_CLOSE
