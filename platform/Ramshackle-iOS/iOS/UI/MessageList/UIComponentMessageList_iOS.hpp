//
//  UIComponentMessageList_iOS.h
//  Ramshackle-iOS
//
//  Created by sweetman on 12/5/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#import "UIComponentMessageList.hpp"

NS_RAM_OPEN

class UIComponentMessageList_iOS : public UIComponentMessageList {
public:
    UIComponentMessageList_iOS();
    virtual void append(std::string message);
};


NS_RAM_CLOSE
