//
//  Statement.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/22/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "Statement.hpp"
#include <random>
#include <iterator>

NS_RAM_OPEN

// random container selection is from http://stackoverflow.com/a/16421677
template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, (int)std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

std::string selectOption(std::string str)
{
    std::vector<std::string> options;
    std::string activeOption = "";
    
    for (int i = 0; i < str.length(); i++) {
        
        if (str[i] == '[') {
            
            // resolve embedded options
            activeOption.append(selectOption(str.substr(i, str.length()-i)));
            // advance index to closing brace
            while (str[i] != ']' && i < str.length()) { i++; }
            
        } else if (str[i] == ']') {
            
            // end the option sequence & return the result
            options.push_back(activeOption);
            int randomIndex = rand() % options.size();
            auto final = options[randomIndex];
            return *select_randomly(options.begin(), options.end());
            
        } else if (str[i] == '|') {
            
            // Spit options on pipes
            if (activeOption.length() > 0) {
                options.push_back(activeOption);
                activeOption = "";
            }
            
        } else {
            
            activeOption += str[i];
            
        }
    }
    RAM_ASSERT(false, "Option block not closed with ].");
    return "";
}

std::string flatten(std::string str)
{
    std::string final = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '[') {
            // resolve embedded options
            final.append(selectOption(str.substr(i+1, str.length()-i)));
            // advance index to closing brace
            while (str[i] != ']' && i < str.length()) { i++; }
        } else {
            final += str[i];
        }
    }
    return final;
}

Statement::Statement()
: _sourceText("")
, _evaluatedText(nullptr)
{ }

Statement::Statement(std::string sourceText)
: _sourceText(sourceText)
, _evaluatedText(nullptr)
{ }

Statement::~Statement()
{
    if (_evaluatedText != nullptr) {
        SAFE_DELETE(_evaluatedText);
    }
}

std::string* Statement::evaluateStatement()
{
    return new std::string(flatten(_sourceText));
}

std::string* Statement::getText()
{
    if (_evaluatedText == nullptr) {
        _evaluatedText = evaluateStatement();
    }
    return _evaluatedText;
}

NS_RAM_CLOSE
