//
//  NameSystem.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/28/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "NameSystem.hpp"
#include "IFEngine.hpp"
#include "GameState.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "GenderedBeing.hpp"
#include "TextUtils.hpp"
#include "Type.hpp"

NS_RAM_OPEN

std::string personal_pronoun(BaseObject *object, PronounPerson person) {
    Entity *e = dynamic_cast<Entity*>(object);
    if (e) {
        GenderedBeing *gender = e->getComponent<GenderedBeing>();
        if (gender) {
            return gender->personalPronoun(person);
        }
    }
    
    switch (person) {
        case FirstPersonSingular:
            return "self";
        case SecondPersonSingular:
            return "you";
        case ThirdPersonSingular:
        default:
            return "it";
    }
}

std::string posessive_pronoun(BaseObject *object, PronounPerson person) {
    Entity *e = dynamic_cast<Entity*>(object);
    if (e) {
        GenderedBeing *gender = e->getComponent<GenderedBeing>();
        if (gender) {
            return gender->posessivePronoun(person);
        }
    }
    
    switch (person) {
        case FirstPersonSingular:
            return "mine";
        case SecondPersonSingular:
            return "yours";
        case ThirdPersonSingular:
        default:
            return "its";
    }
}

std::string posessive_adjective(BaseObject *object, PronounPerson person) {
    Entity *e = dynamic_cast<Entity*>(object);
    if (e) {
        GenderedBeing *gender = e->getComponent<GenderedBeing>();
        if (gender) {
            return gender->posessiveAdjective(person);
        }
    }
    
    switch (person) {
        case FirstPersonSingular:
            return "my";
        case SecondPersonSingular:
            return "your";
        case ThirdPersonSingular:
        default:
            return "its";
    }
}

std::string you(std::string message) {
    return capitalize(personal_pronoun(IFEngine::getPlayer(), SecondPersonSingular) + " " + message);
}

std::string type(Entity *e) {
    Type *type = e->getComponent<Type>();
    if (type) {
        return type->getType();
    }
    return "thing";
}

std::string the(Entity *e, std::string message) {
    return "The " + type(e) + " " + message;
}

NS_RAM_CLOSE
