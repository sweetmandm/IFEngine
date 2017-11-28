//
//  TurnPiece.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef TurnPiece_hpp
#define TurnPiece_hpp

#include "RamBase.h"
#include "Component.hpp"

NS_RAM_OPEN

class TurnPiece: public Component {
public:
    virtual ~TurnPiece() { };
    virtual void playTurn() = 0;
};

NS_RAM_CLOSE

#endif /* TurnPiece_hpp */
