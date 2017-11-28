//
//  Player.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "Player.hpp"
#include "NotificationSystem.hpp"

// Default Components
#include "ConsciousBeing.hpp"
#include "Powerable.hpp"
#include "EmotionalState.hpp"

NS_RAM_OPEN

#pragma mark - Init

Entity* makePlayer() {
    Entity *entity = new Entity();
    
    Player *player = new Player();
    entity->addComponent(player);
    
    Powerable *powerable = new Powerable();
    entity->addComponent(powerable);
    
    ConsciousBeing *consciousness = new ConsciousBeing(ConsciousBeingStateDead);
    entity->addComponent(consciousness);
    
    EmotionalState *emotions = new EmotionalState(EMOTION_ZERO);
    entity->addComponent(emotions);
    
    return entity;
}

NS_RAM_CLOSE
