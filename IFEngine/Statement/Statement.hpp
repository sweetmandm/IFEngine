//
//  Statement.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/22/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Statement_hpp
#define Statement_hpp

#include "RamBase.h"
#include <string>

NS_RAM_OPEN

class Statement {
    
    std::string _sourceText;
    std::string* _evaluatedText;
    std::string* evaluateStatement();
    
public:
    
    /**
     *  SourceText may have options to select, like "This string [has|contains] some alternate text."
     *  Options can be nested, like "Select [something [with|containing] | a thing [including|having]] nested options"
     */
    Statement();
    Statement(std::string sourceText);
    ~Statement();
    
    std::string* getText();
    
    bool isEmpty() const { return _sourceText.size() == 0; };
};

NS_RAM_CLOSE

#endif /* Statement_hpp */
