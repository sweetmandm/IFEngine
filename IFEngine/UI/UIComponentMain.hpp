//
//  UIComponentMainMenu.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/26/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef UIComponentMainMenu_hpp
#define UIComponentMainMenu_hpp

#include "UIComponent.hpp"

NS_RAM_OPEN

class UIComponentMessageList;

class UIComponentMain : public UIComponent {
protected:
    UIComponentMessageList *_messageList;
    
public:
    static UIComponentMain* makeWithView(void* view);
    virtual void setMessageList(UIComponentMessageList *messageList) { _messageList = messageList; };
};

NS_RAM_CLOSE

#endif /* UIComponentMainMenu_hpp */
