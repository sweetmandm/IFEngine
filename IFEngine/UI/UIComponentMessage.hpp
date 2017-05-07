//
//  UIComponentMessage.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/23/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef UIComponentMessage_hpp
#define UIComponentMessage_hpp

#include "UIComponent.hpp"
#include <string>

NS_RAM_OPEN

class ActionMessage;

class UIComponentMessage : public UIComponent {
    
    ActionMessage *_message;
    
public:
    ~UIComponentMessage();
    static UIComponentMessage* makeWithMessage(ActionMessage *message);
    
    // Interaction
    void acceptMessage();
    
    // UI Data
    std::string getMessageText();
    std::string getAcceptText();
};

NS_RAM_CLOSE

#endif /* UIComponentMessage_hpp */
