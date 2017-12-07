//
//  GenderedBeing.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/28/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef GenderedBeing_hpp
#define GenderedBeing_hpp

#include "RamBase.h"
#include "Component.hpp"
#include <string>
#include "Pronoun.h"

NS_RAM_OPEN

enum GenderedBeingState {
    Male,
    Female,
    TransMale,
    TransFemale,
    Transmasculine,
    Transfeminine
};

class GenderedBeing : public Component, Pronoun {
protected:
    GenderedBeingState _state;
public:
    GenderedBeing(GenderedBeingState state);
    
    static GenderedBeingState random_gendered_being_state();
    
    GenderedBeingState getState() { return _state; };
    void setState(GenderedBeingState state) { _state = state; }
    
    virtual std::string personalPronoun(PronounPerson person);
    virtual std::string posessivePronoun(PronounPerson person);
    virtual std::string posessiveAdjective(PronounPerson person);
};

NS_RAM_CLOSE

#endif /* GenderedBeing_hpp */
