//
//  ResearchOffice.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/20/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "ResearchOffice.hpp"
#include "Researcher.hpp"
#include "Action.hpp"

NS_RAM_OPEN

ResearchOffice::ResearchOffice() { }

ResearchOffice::~ResearchOffice() { }

ResearchOffice* ResearchOffice::makeNew()
{
    auto office = new ResearchOffice();
    return office;
}

void ResearchOffice::playTurn()
{
    
}

NS_RAM_CLOSE
