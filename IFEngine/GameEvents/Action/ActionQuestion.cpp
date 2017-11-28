//
//  ActionQuestion.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/22/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "ActionQuestion.hpp"
#include "IFEngine.hpp"

NS_RAM_OPEN

ActionQuestion::ActionQuestion(std::string label, Question question)
: Action(label, ActionTypeQuestion)
, _question(question)
{ };

ActionQuestion::~ActionQuestion() { }

Action* ActionQuestion::generateNextFromSelectedAnswer()
{
    if (_selectedAnswer.isNone()) {
        return this;
    }
    return _selectedAnswer.next.getNext();
}

void ActionQuestion::selectAnswer(Answer answer)
{
    _selectedAnswer = answer;
    _nextAction = _selectedAnswer.next;
}

void ActionQuestion::perform() {
    IFEngine::shared()->performQuestion(this);
}

NS_RAM_CLOSE
