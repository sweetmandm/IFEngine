//
//  Description.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/7/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "Description.hpp"
#include "IFEngine.hpp"
#include "UIController.hpp"
#include "NameSystem.hpp"
#include "Player.hpp"
#include "GenderedBeing.hpp"
#include "ConsciousBeing.hpp"
#include "TextUtils.hpp"
#include "Player.hpp"

NS_RAM_OPEN

void describe_consciousness(Entity *e) {
    Player *p = e->getComponent<Player>();
    ConsciousBeing *c = e->getComponent<ConsciousBeing>();
    if (c) {
        switch (c->getState()) {
            case ConsciousBeingStateAlive:
                message(p ?
                        you("are conscious.") :
                        the(e, "is conscious."));
                break;
            case ConsciousBeingStateAsleep:
                message(p ?
                        you("are unconscious.") :
                        the(e, "is unconscious."));
                break;
            case ConsciousBeingStateDead:
                message(p ?
                        you("are dead.") :
                        the(e, "is dead."));
                break;
            default:
                break;
        }
    } else {
        message(p ?
                you("are not conscious.") :
                the(e, "is not conscious."));
    }
}

NS_RAM_CLOSE
