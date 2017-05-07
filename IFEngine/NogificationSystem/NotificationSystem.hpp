//
//  NotificationSystem.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/19/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef NotificationSystem_hpp
#define NotificationSystem_hpp

#include "RamBase.h"
#include <map>

NS_RAM_OPEN

class NotificationListener {
public:
    virtual void handleNotification(std::string name, void* sender) = 0;
};

class NotificationSystem {
    
private:
    NotificationSystem();
    ~NotificationSystem();
    std::map<std::string, std::vector<NotificationListener*>>* _listeners;
    
public:
    static void begin();
    static void postNotification(std::string name, void* sender);
    static void registerForNotification(std::string name, NotificationListener *listener);
    static void unregisterForNotification(std::string name, NotificationListener *listener);
};

NS_RAM_CLOSE

#endif /* NotificationSystem_hpp */
