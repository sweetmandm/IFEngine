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
class UIComponentMessageList;

class UIController {
    UIController();
    UIComponentMessageList *_messageList;
    UIComponent *_mainComponent;
    UIComponent *_activeActionComponent;
    
    void showComponent(std::function<UIComponent*(void)>makeComponent);
    
public:
    static UIController* shared();

    void showMessage(ActionMessage *message);
    void showQuestion(ActionQuestion *question);
    void showMessageList();
    void appendMessage(std::string message);
    
    UIComponent* getMainComponent();
    void makeMainComponentWithView(void* view);
};

NS_RAM_CLOSE

#endif /* UIController_hpp */
