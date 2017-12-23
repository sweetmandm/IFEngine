//
//  PlayerSoftwareSystem.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/12/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "PlayerSoftwareSystem.hpp"
#include "Player.hpp"
#include "OperatingSystem.hpp"
#include "Software.hpp"
#include "ConsciousBeing.hpp"
#include "Description.hpp"
#include "TextUtils.hpp"

NS_RAM_OPEN

void PlayerSoftwareSystem::start(Entity *player) {
    auto software = player->getComponent<Software>();
    
    auto computer = (software ?
                     software->getComputer() :
                     nullptr);
    
    auto os = (computer ?
               computer->getComponent<OperatingSystem>()
               : nullptr);
    
    if (software && os) {
        auto consciousness = player->getComponent<ConsciousBeing>();
        if (os->startProgram(software)) {
            message(you("feel a dull buzz."));
            if (consciousness) {
                consciousness->setState(ConsciousBeingStateAlive);
            }
        } else {
            message(you("feel a sense of failure."));
            if (consciousness) {
                consciousness->setState(ConsciousBeingStateDead);
            }
        }
    }
    describe_consciousness(player);
}

NS_RAM_CLOSE
