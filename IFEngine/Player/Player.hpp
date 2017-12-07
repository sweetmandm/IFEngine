//
//  Player.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "Component.hpp"
#include "Entity.hpp"

NS_RAM_OPEN

Entity* makePlayer();

class Player : public Component {
};

NS_RAM_CLOSE

#endif /* Player_hpp */
