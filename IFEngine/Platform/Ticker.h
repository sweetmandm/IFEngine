//
//  Ticker.h
//  Ramshackle
//
//  Created by David Sweetman on 5/4/15.
//  Copyright (c) 2015 tinfish. All rights reserved.
//

// This is an abstract base class; ticking stuff is platform-dependent.

#ifndef __Ramshackle__Ticker__
#define __Ramshackle__Ticker__

#include "RamBase.h"

NS_RAM_OPEN

class Ticker {
public:
    static Ticker* create();
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void tick() = 0;
    Ticker();
    ~Ticker();
};

NS_RAM_CLOSE

#endif /* defined(__Ramshackle__Ticker__) */
