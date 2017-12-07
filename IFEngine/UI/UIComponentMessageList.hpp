//
//  UIComponentMessageList.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/5/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef UIComponentMessageList_hpp
#define UIComponentMessageList_hpp

#include "UIComponent.hpp"
#include <string>

NS_RAM_OPEN

class UIComponentMessageList : public UIComponent {
protected:
    std::vector<std::string> *_messages;
    UIComponentMessageList();

public:
    ~UIComponentMessageList();
    static UIComponentMessageList* make();
    
    virtual void append(std::string message);
    
    // UI Data
    std::vector<std::string>* getMessages() { return _messages; };
};

NS_RAM_CLOSE

#endif /* UIComponentMessageList_hpp */
