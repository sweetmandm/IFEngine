//
//  UIController.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/23/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "UIController.hpp"
#include "UIComponent.hpp"
#include "UIComponentMain.hpp"
#include "ActionMessage.hpp"
#include "UIComponentMessage.hpp"
#include "UIComponentQuestion.hpp"
#include "UIComponentMessageList.hpp"

NS_RAM_OPEN

static UIController* controller = nullptr;

UIController::UIController()
: _messageList(UIComponentMessageList::make())
, _activeActionComponent(nullptr)
{ }

UIController* UIController::shared()
{
    if (!controller) {
        controller = new (std::nothrow) UIController();
    }
    return controller;
}

void UIController::makeBaseComponentWithView(void* view)
{
    _base = UIComponent::makeWithView(view);
}

UIComponent* UIController::getBaseComponent()
{
    return _base;
}

void UIController::showComponent(bool animated, std::function<UIComponent*(void)>makeComponent, std::function<void(void)>completion)
{
    auto component = makeComponent();
    if (_activeActionComponent == component) {
        return;
    }
    
    auto showBlock = [this, animated, completion, component]()mutable{
        _activeActionComponent = component;
        _base->addChild(_activeActionComponent);
        _activeActionComponent->fillParent();
        _activeActionComponent->show(animated, completion);
    };
    
    if (_activeActionComponent != nullptr) {
        _activeActionComponent->hide(animated, [this, showBlock]()mutable{
            _activeActionComponent->removeFromParent();
            showBlock();
        });
    } else {
        showBlock();
    }
}

void UIController::showMessage(ActionMessage *message)
{
    showComponent(true, [message]() -> UIComponent* {
        return UIComponentMessage::makeWithMessage(message);
    }, []{});
}

void UIController::showMessageList()
{
    showComponent(true, [this]() -> UIComponent* {
        if (_mainComponent == nullptr) {
            _mainComponent = UIComponentMain::make();
            _mainComponent->setMessageList(_messageList);
        }
        return _mainComponent;
    }, []{});
}

void UIController::showQuestion(ActionQuestion *question)
{
    showComponent(true, [question]() -> UIComponent* {
        return UIComponentQuestion::makeWithQuestion(question);
    }, []{});
}

void UIController::appendMessage(std::string message) {
    showMessageList();
    _messageList->append(message);
}

NS_RAM_CLOSE
