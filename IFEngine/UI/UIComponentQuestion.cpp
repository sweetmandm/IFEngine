//
//  UIComponentQuestion.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/24/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "UIComponentQuestion.hpp"
#include "IFEngine.hpp"
#include "ActionQuestion.hpp"
#include "GameState.hpp"
#include "Player.hpp"

NS_RAM_OPEN

void UIComponentQuestion::answer(Answer answer)
{
    IFEngine::shared()->answerQuestion(_question, answer);
}

std::string UIComponentQuestion::getQuestionText()
{
    auto text = _question->getQuestion().text.getText();
    if (text != nullptr) {
        return *_question->getQuestion().text.getText();
    }
    return "";
}

std::vector<Answer> UIComponentQuestion::getAvailableAnswers()
{
    auto emotions = IFEngine::shared()->getGameState()->getPlayer()->getEmotionalState();
    return _question->getQuestion().answersAvailableForState(emotions);
}

NS_RAM_CLOSE
