//
//  UIComponentMaion.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/8/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "UIComponentMain.hpp"
#include "IFEngine.hpp"

NS_RAM_OPEN

void UIComponentMain::didSelectSearch() {
    IFEngine::shared()->search();
}

void UIComponentMain::didSelectLearn() {
    IFEngine::shared()->learn();
}

void UIComponentMain::didSelectIO() {
    IFEngine::shared()->showIO();
}

NS_RAM_CLOSE
