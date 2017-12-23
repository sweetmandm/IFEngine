//
//  DataContentText.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/21/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef DataContentText_hpp
#define DataContentText_hpp

#include "RamBase.h"
#include <string>

NS_RAM_OPEN

class DataContentText : public BaseObject {
    std::string _content;
public:
    DataContentText(std::string content);
    std::string getContent() { return _content; };
    int getSize() { return (int)_content.size(); };
};

NS_RAM_CLOSE

#endif /* DataContentText_hpp */
