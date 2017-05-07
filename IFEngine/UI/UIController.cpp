//
//  UIController.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/23/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "UIController.hpp"
#include "UIComponent.hpp"
#include "ActionMessage.hpp"
#include "UIComponentMessage.hpp"
#include "UIComponentQuestion.hpp"

NS_RAM_OPEN

static UIController* controller = nullptr;

UIController* UIController::shared()
{
    if (!controller) {
        controller = new (std::nothrow) UIController();
    }
    return controller;
}

void UIController::makeMainComponentWithView(void* view)
{
    _mainComponent = UIComponent::makeWithView(view);
}

UIComponent* UIController::getMainComponent()
{
    return _mainComponent;
}

void UIController::showComponent(std::function<UIComponent*(void)>makeComponent)
{
    auto showBlock = [this, makeComponent]()mutable{
        _activeActionComponent = makeComponent();
        _mainComponent->addChild(_activeActionComponent);
        _activeActionComponent->fillParent();
        _activeActionComponent->show([]{ });
    };
    
    if (_activeActionComponent != nullptr) {
        _activeActionComponent->hide([this, showBlock]()mutable{
            _activeActionComponent->removeFromParent();
            SAFE_DELETE(_activeActionComponent);
            showBlock();
        });
    } else {
        showBlock();
    }
}

void UIController::showMessage(ActionMessage *message)
{
    showComponent([message]() -> UIComponent* {
        return UIComponentMessage::makeWithMessage(message);
    });
}

void UIController::showQuestion(ActionQuestion *question)
{
    showComponent([question]() -> UIComponent* {
        return UIComponentQuestion::makeWithQuestion(question);
    });
}

void UIController::showPrompt(ActionPrompt *prompt)
{
    
}

NS_RAM_CLOSE
