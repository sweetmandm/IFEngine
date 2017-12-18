//
//  UIController.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/23/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef UIController_hpp
#define UIController_hpp

#include "RamBase.h"
#include <functional>

NS_RAM_OPEN

class Action;
class ActionMessage;
class ActionQuestion;
class UIComponent;
class UIComponentMain;
class UIComponentMessageList;

class UIController {
    UIController();
    UIComponentMessageList *_messageList;
    UIComponentMain *_mainComponent;
    UIComponent *_base;
    UIComponent *_activeActionComponent;
    
    void showComponent(bool animated, std::function<UIComponent*(void)>makeComponent, std::function<void(void)>completion);

public:
    static UIController* shared();

    void showMessage(ActionMessage *message);
    void showQuestion(ActionQuestion *question);
    void showMainComponent();
    void appendMessage(std::string message);
    
    UIComponent* getBaseComponent();
    void makeBaseComponentWithView(void* view);
    
    void showSearchMenu();
};

NS_RAM_CLOSE

#endif /* UIController_hpp */
