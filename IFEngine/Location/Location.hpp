//
//  Location.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Location_hpp
#define Location_hpp

#include "TurnPiece.hpp"

NS_RAM_OPEN

// Location
// - name
// - description (change over time)
// - objects (interactable or observable)
// - characters (change over time, interactable and observable)

// 'Locations' are long-running game objects that change infrequently.
// Each object in the Location might be allowed a life of its own. For example,
// the Researcher's actions and motivations are influenced by his stats. If he
// becomes afraid, he'll act differently, potentially witholding training or
// threatening shutdown, and you'll have to change your tactics. If his
// motivations are contrary to your own goals, you'll have to manipulate
// him or try to get him to change his mind.

// Initial Location:
// Office
//  Characters:
//  - Researcher
//  Objects:
//  - Power Source: wall outlet

class Action;

typedef struct {
    std::string* name;
    std::string* description;
} LocationData;

class Location : public TurnPiece {

protected:
    Location();
    ~Location();
    
    static Location* makeWithData(LocationData);
    
public:
    virtual void playTurn();

};

NS_RAM_CLOSE

#endif /* Location_hpp */
