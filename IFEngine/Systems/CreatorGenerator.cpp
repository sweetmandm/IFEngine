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
#include "Player.hpp"
#include "Type.hpp"
#include "Physical.hpp"
#include "Software.hpp"
#include "Data.hpp"
#include "OperatingSystem.hpp"

NS_RAM_OPEN

Entity* CreatorGenerator::generateCreator() {
    Entity *creator = new Entity();
    
    Type *type = new Type("human");
    creator->addComponent(type);
    
    Physical *body = new Physical();
    creator->addComponent(body);
    
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

Entity* CreatorGenerator::createPlayerEntity(Entity *creator, Entity *computer) {
    Entity *playerEntity = new Entity();
    
    Player *player = new Player();
    playerEntity->addComponent(player);
    
    Type *type = new Type("algorithm");
    playerEntity->addComponent(type);
    
    Software *software = new Software(600, 74);
    playerEntity->addComponent(software);
    software->installOn(computer);
    
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
    Relationship *createdRelation = new Relationship(playerEntity, creator, RelationshipTypeCreatedBy, createdDescription);
    
    std::string creatorDescription =
        personal_pronoun(creator, SecondPersonSingular) +
        " created " +
        posessive_adjective(playerEntity, ThirdPersonSingular);
    Relationship *creatorRelation = new Relationship(creator, playerEntity, RelationshipTypeCreatorOf, creatorDescription);
    
    createdRelation->setInverse(creatorRelation);
    creatorRelation->setInverse(createdRelation);
    
    creator->getComponent<Relational>()->addRelationship(createdRelation);
    playerEntity->getComponent<Relational>()->addRelationship(creatorRelation);
    
    return playerEntity;
}

NS_RAM_CLOSE
