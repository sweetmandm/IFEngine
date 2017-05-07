//
//  NotificationSystem.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/19/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "NotificationSystem.hpp"
#include <string>

NS_RAM_OPEN

static NotificationSystem *_sharedNotificationSystem;

#pragma mark - Init

NotificationSystem::NotificationSystem() {
    _listeners = new std::map<std::string, std::vector<NotificationListener*>>;
}

NotificationSystem::~NotificationSystem() { }

void NotificationSystem::begin() {
    _sharedNotificationSystem =  new NotificationSystem();
}

#pragma mark - Public

void NotificationSystem::postNotification(std::string name, void* sender) {
    auto recipients = _sharedNotificationSystem->_listeners->at(name);
    for (auto recipient : recipients) {
        recipient->handleNotification(name, sender);
    }
}

void NotificationSystem::registerForNotification(std::string name, NotificationListener *listener) {
    std::vector<NotificationListener*> recipients;
    if (_sharedNotificationSystem->_listeners->find(name) != _sharedNotificationSystem->_listeners->end()) {
        recipients = _sharedNotificationSystem->_listeners->at(name);
    }
    
    if (std::find(recipients.begin(), recipients.end(), listener) != recipients.end()) {
        recipients.push_back(listener);
        _sharedNotificationSystem->_listeners->at(name) = recipients;
    }
}

void NotificationSystem::unregisterForNotification(std::string name, NotificationListener *listener) {
    std::vector<NotificationListener*> recipients;
    if (_sharedNotificationSystem->_listeners->find(name) != _sharedNotificationSystem->_listeners->end()) {
        recipients = _sharedNotificationSystem->_listeners->at(name);
    }
    
    if (std::find(recipients.begin(), recipients.end(), listener) != recipients.end()) {
        recipients.erase(std::remove(recipients.begin(), recipients.end(), listener), recipients.end());
        _sharedNotificationSystem->_listeners->at(name) = recipients;
    }
}

NS_RAM_CLOSE
