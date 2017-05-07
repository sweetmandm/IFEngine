//
//  Character.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/19/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include "TurnPiece.hpp"

NS_RAM_OPEN

class Character : public TurnPiece {
    virtual void playTurn() = 0;
};

NS_RAM_CLOSE

#endif /* Character_hpp */
