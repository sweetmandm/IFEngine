//
//  GenderedBeing.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 11/28/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "GenderedBeing.hpp"
#include "RandomSelection.hpp"

NS_RAM_OPEN

std::vector<GenderedBeingState> all_genders() {
    return std::vector<GenderedBeingState>({
        Male,
        Female,
        TransMale,
        TransFemale,
        Transmasculine,
        Transfeminine
    });
}

GenderedBeingState GenderedBeing::random_gendered_being_state() {
    return weighted_random({42, 42, 4, 4, 4, 4}, all_genders());
}

GenderedBeing::GenderedBeing(GenderedBeingState state)
: _state(state)
{ }

std::string GenderedBeing::personalPronoun(PronounPerson person) {
    switch (person) {
        case FirstPersonSingular:
            return "I";
        case SecondPersonSingular:
            return "you";
        case ThirdPersonSingular:
            switch (_state) {
                case Male:
                case TransMale:
                case Transmasculine:
                    return "he";
                case Female:
                case TransFemale:
                case Transfeminine:
                    return "she";
                default:
                    return "ze";
            }
    }
}

std::string GenderedBeing::posessivePronoun(PronounPerson person) {
    switch (person) {
        case FirstPersonSingular:
            return "mine";
        case SecondPersonSingular:
            return "yours";
        case ThirdPersonSingular:
            switch (_state) {
                case Male:
                case TransMale:
                case Transmasculine:
                    return "his";
                case Female:
                case TransFemale:
                case Transfeminine:
                    return "hers";
                default:
                    return "ze's";
            }
    }
}

std::string GenderedBeing::posessiveAdjective(PronounPerson person) {
    switch (person) {
        case FirstPersonSingular:
            return "my";
        case SecondPersonSingular:
            return "your";
        case ThirdPersonSingular:
            switch (_state) {
                case Male:
                case TransMale:
                case Transmasculine:
                    return "his";
                case Female:
                case TransFemale:
                case Transfeminine:
                    return "her";
                default:
                    return "ze's";
            }
    }
}

NS_RAM_CLOSE
