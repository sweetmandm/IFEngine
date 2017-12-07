//
//  Pronoun.h
//  Ramshackle
//
//  Created by sweetman on 11/29/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef Pronoun_h
#define Pronoun_h

#include "RamBase.h"
#include <string>

NS_RAM_OPEN

enum PronounPerson {
    FirstPersonSingular,
    SecondPersonSingular,
    ThirdPersonSingular
};

class Pronoun {
    virtual std::string personalPronoun(PronounPerson person) = 0;
    virtual std::string posessivePronoun(PronounPerson person) = 0;
    virtual std::string posessiveAdjective(PronounPerson person) = 0;
};

NS_RAM_CLOSE

#endif /* Pronoun_h */
