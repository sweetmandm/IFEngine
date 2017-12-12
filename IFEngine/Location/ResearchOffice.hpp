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
    Entity *_computer;
    Entity *_router;
public:
    ResearchOffice();
    Entity* getComputer() { return _computer; };
};

NS_RAM_CLOSE

#endif /* ResearchOffice_hpp */
