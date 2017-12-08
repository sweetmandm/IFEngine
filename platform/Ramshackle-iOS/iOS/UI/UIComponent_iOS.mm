//
//  UIComponent_iOS.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/23/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "UIComponent_iOS.hpp"
#import <UIKit/UIKit.h>
#import "UIView+Helper.h"

NS_RAM_OPEN

UIComponent* UIComponent::makeWithFrame(Rect frame)
{
    UIComponent_iOS *component = new UIComponent_iOS();
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(frame.origin.x,
                                                            frame.origin.y,
                                                            frame.size.w,
                                                            frame.size.h)];
    component->setView((__bridge void*)view);
    return component;
}

UIComponent* UIComponent::makeWithView(void* view)
{
    UIComponent_iOS *component = new UIComponent_iOS();
    component->setView(view);
    return component;
}

UIComponent::~UIComponent()
{
    // give the view back to ARC
    auto release = (__bridge_transfer UIView *)_view;
    release = nullptr; // just to avoid the 'unused variable' warning
}

void UIComponent::setView(void* view) {
    _view = (__bridge_retained void *)(__bridge UIView *)view;
};

void UIComponent::fillParent()
{
    UIView *view = ((__bridge UIView*)getView());
    [view fillSuperview];
}

void UIComponent::show(bool animated, std::function<void(void)> didShow)
{
    UIView *view = ((__bridge UIView*)getView());
    
    if (!animated) {
        view.hidden = NO;
        view.alpha = 1.0;
        didShow();
        return;
    }
    
    view.alpha = 0.0;
    view.hidden = false;
    
    [UIView animateWithDuration:0.2 animations:^{
        view.alpha = 1.0;
    } completion:^(BOOL finished) {
        didShow();
    }];
}

void UIComponent::hide(bool animated, std::function<void(void)> didHide)
{
    UIView *view = ((__bridge UIView*)getView());
    
    if (!animated) {
        view.hidden = YES;
        view.alpha = 0.0;
        didHide();
        return;
    }
    
    view.alpha = 1.0;
    
    [UIView animateWithDuration:0.2 animations:^{
        view.alpha = 0.0;
    } completion:^(BOOL finished) {
        didHide();
        view.hidden = YES;
    }];
}

void UIComponent::addChild(UIComponent *component)
{
    UIView *view = (__bridge UIView*)getView();
    UIView *child = (__bridge UIView*)(component->getView());
    RAM_PARAM_ASSERT(view != child);
    [view addSubview:child];
}

void UIComponent::removeFromParent()
{
    UIView *view = ((__bridge UIView*)getView());
    [view removeFromSuperview];
}

Rect UIComponent::frame()
{
    UIView *view = ((__bridge UIView*)getView());
    return (Rect){
        (float)view.frame.origin.x,
        (float)view.frame.origin.y,
        (float)view.frame.size.width,
        (float)view.frame.size.height
    };
}

NS_RAM_CLOSE
