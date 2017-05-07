//
//  Powerable.h
//  Ramshackle
//
//  Created by David Sweetman on 12/19/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Powerable_h
#define Powerable_h

#include "RamBase.h"

NS_RAM_OPEN

enum PowerOnResult {
    PowerOnResultRunning,
    PowerOnResultNoPower,
    PowerOnResultNotEnoughPower,
    PowerOnResultOvercharge
};

class Powerable {
    virtual PowerOnResult powerOn() = 0;
};

NS_RAM_CLOSE

#endif /* Powerable_h */
