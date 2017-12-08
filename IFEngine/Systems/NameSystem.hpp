//
//  NameSystem.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/28/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef NameSystem_hpp
#define NameSystem_hpp

#include "RamBase.h"
#include "Pronoun.h"
#include <string>

NS_RAM_OPEN

class Entity;

std::string personal_pronoun(BaseObject* object, PronounPerson person);
std::string posessive_pronoun(BaseObject* object, PronounPerson person);
std::string posessive_adjective(BaseObject* object, PronounPerson person);

std::string you(std::string message);
std::string the(Entity *e, std::string message);

NS_RAM_CLOSE

#endif /* NameSystem_hpp */
