//
//  ResearchOffice.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef ResearchOffice_hpp
#define ResearchOffice_hpp

#include "Location.hpp"

NS_RAM_OPEN

class Researcher;

class ResearchOffice : public Location {

protected:
    ResearchOffice();
    ~ResearchOffice();
    Researcher* _researcher;
    
public:
    static ResearchOffice* makeNew();
    
    Researcher* getResearcher() { return _researcher; }
    
    virtual void playTurn();
};

NS_RAM_CLOSE

#endif /* ResearchOffice_hpp */
