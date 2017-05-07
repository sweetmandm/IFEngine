//
//  UIComponentQuestion.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/24/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef UIComponentQuestion_hpp
#define UIComponentQuestion_hpp

#include "UIComponent.hpp"
#include <string>

NS_RAM_OPEN

class ActionQuestion;
struct Answer;

class UIComponentQuestion : public UIComponent {
protected:
    ActionQuestion *_question;
public:
    static UIComponentQuestion* makeWithQuestion(ActionQuestion *question);
    
    // Interaction
    void answer(Answer answer);
    
    // UI Data
    std::string getQuestionText();
    std::vector<Answer> getAvailableAnswers();
};

NS_RAM_CLOSE

#endif /* UIComponentQuestion_hpp */
