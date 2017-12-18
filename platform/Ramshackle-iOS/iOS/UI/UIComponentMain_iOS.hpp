//
//  UIComponentMain_iOS.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/8/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef UIComponentMain_iOS_hpp
#define UIComponentMain_iOS_hpp

#include "UIComponentMain.hpp"

@class MainScreen;

NS_RAM_OPEN

class UIComponentMain_iOS : public UIComponentMain {
    MainScreen* getMainScreen();
    virtual void setMessageList(UIComponentMessageList *messageList);
    virtual void showSearchMenu();
};

NS_RAM_CLOSE

#endif /* UIComponentMain_iOS_hpp */
