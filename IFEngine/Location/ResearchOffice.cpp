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

ResearchOffice::ResearchOffice()
: Location({
    "Research Office",
    "There is a chill."
})
{
    /* IDEA:
     The Location gets a bunch of randomly-generated Components.
     
     It's also given a randomly-generated name, based on a randomly-selected Type.
     (For example, "University Computer Science Hall", would markov from a bunch of names
     like "Stewmann Building", "Partner Building I", etc.
     
     Its description is generated off of its components. The description is the
     player's INTERPRETATION of those components. For example, if you have a
     'Sensory' component, you might get "The room feels chilly."
     */
}

NS_RAM_CLOSE
