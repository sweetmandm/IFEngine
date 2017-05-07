//
//  ActionQuestion.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/22/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef ActionQuestion_hpp
#define ActionQuestion_hpp

#include "Action.hpp"
#include "ActionRegistry.hpp"
#include "EmotionalState.hpp"
#include "NextAction.hpp"
#include "Statement.hpp"
#include <string>
#include <functional>

NS_RAM_OPEN

/* If the user already knows the answer to this question, it can be styled appropriately: */
enum AnswerStyle {
    AnswerStyleNeutral,
    AnswerStyleCorrect,
    AnswerStyleIncorrect
};

struct Answer {
    ~Answer() {};
    
    EmotionalPredicate predicate;
    Statement text;
    EmotionalStateData impact;
    AnswerStyle style;
    NextAction next;
    bool isNone() const { return next.isNone(); };
};

struct Question {
    ~Question() {};
    EmotionalPredicate predicate;
    Statement text;
    std::vector<Answer> allAnswers;
    std::vector<Answer> answersAvailableForState(EmotionalState *state) {
        std::vector<Answer> available;
        for (auto answer : allAnswers) {
            if (state->matchesPredicate(answer.predicate)) {
                available.push_back(answer);
            }
        }
        RAM_ASSERT(available.size() > 0, "What happens if no answers match? Maybe include a default or something?");
        return available;
    };
};
#define MakeQuestion(...) ((Question){__VA_ARGS__});

class ActionQuestion : public Action {
    
    Question _question;
    Answer _selectedAnswer;
    Action* generateNextFromSelectedAnswer();
    
public:
    ActionQuestion(std::string label, Question question);
    ~ActionQuestion();
    
    Question getQuestion() { return _question; }
    
    void selectAnswer(Answer answer);
};

NS_RAM_CLOSE

#endif /* ActionQuestion_hpp */
