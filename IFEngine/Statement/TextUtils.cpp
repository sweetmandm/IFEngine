//
//  TextUtils.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/5/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "TextUtils.hpp"
#include "UIController.hpp"
#include "TTS.hpp"

NS_RAM_OPEN

std::string capitalize(std::string text) {
    auto copy = text;
    if (copy.length() > 0 && isalpha(copy[0])) {
        copy[0] = toupper(copy[0]);
    }
    return copy;
}

std::string titleize(std::string text) {
    auto copy = text;
    int last = ' ';
    for (size_t i = 0; i < copy.length(); i++) {
        auto c = copy[i];
        if (last == ' ' && c != ' ' && ::isalpha(c)) {
            copy[i] = toupper(c);
        }
        last = c;
    }
    return copy;
}

extern void message(std::string text) {
    TTS::speak(text);
    UIController::shared()->appendMessage(text);
}

NS_RAM_CLOSE
