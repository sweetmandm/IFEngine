//
//  CreatorGenerator.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/28/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "CreatorGenerator.hpp"
#include "Relational.hpp"
#include "Relationship.hpp"
#include "ConsciousBeing.hpp"
#include "Powerable.hpp"
#include "EmotionalState.hpp"
#include "GenderedBeing.hpp"
#include "NameSystem.hpp"

NS_RAM_OPEN

Entity* CreatorGenerator::generateCreator() {
    Entity *creator = new Entity();
    
    ConsciousBeing *consciousness = new ConsciousBeing(ConsciousBeingStateAlive);
    creator->addComponent(consciousness);
    
    EmotionalState *emotions = new EmotionalState(EMOTION_ZERO);
    creator->addComponent(emotions);
    
    Relational *relational = new Relational();
    creator->addComponent(relational);
    
    GenderedBeing *gender = new GenderedBeing(GenderedBeing::random_gendered_being_state());
    creator->addComponent(gender);
    
    return creator;
}

Entity* CreatorGenerator::createPlayerEntity(Entity *creator) {
    Entity *playerEntity = new Entity();
    
    Powerable *powerable = new Powerable();
    playerEntity->addComponent(powerable);
    
    ConsciousBeing *consciousness = new ConsciousBeing(ConsciousBeingStateDead);
    playerEntity->addComponent(consciousness);
    
    EmotionalState *emotions = new EmotionalState(EMOTION_ZERO);
    playerEntity->addComponent(emotions);
    
    Relational *relational = new Relational();
    playerEntity->addComponent(relational);
    
    std::string createdDescription =
        personal_pronoun(creator, ThirdPersonSingular) +
        " is " +
        posessive_adjective(playerEntity, SecondPersonSingular) +
        " creator.";
    Relationship *createdRelation = new Relationship(playerEntity, creator, createdDescription);
    
    std::string creatorDescription =
        personal_pronoun(creator, SecondPersonSingular) +
        " created " +
        posessive_adjective(playerEntity, ThirdPersonSingular);
    Relationship *creatorRelation = new Relationship(creator, playerEntity, creatorDescription);
    
    createdRelation->setInverse(creatorRelation);
    creatorRelation->setInverse(createdRelation);
    
    creator->getComponent<Relational>()->addRelationship(createdRelation);
    playerEntity->getComponent<Relational>()->addRelationship(creatorRelation);
    
    return playerEntity;
}

NS_RAM_CLOSE