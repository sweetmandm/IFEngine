//
//  UIComponent.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/23/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef UIComponent_hpp
#define UIComponent_hpp

#include "RamBase.h"
#include "Rect.h"
#include <functional>

NS_RAM_OPEN

class UIComponent {
protected:
    void* _view;
public:
    virtual ~UIComponent();
    
    void setView(void* view);
    void* getView() { return _view; };
    
    static UIComponent* makeWithFrame(Rect frame);
    static UIComponent* makeWithView(void* view);
    
    Rect frame();
    void fillParent();
    void show(std::function<void(void)> didShow);
    void hide(std::function<void(void)> didHide);
    void addChild(UIComponent *component);
    void removeFromParent();
};

NS_RAM_CLOSE

#endif /* UIComponent_hpp */
