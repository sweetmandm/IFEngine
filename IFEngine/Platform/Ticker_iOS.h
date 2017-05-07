//
//  Ticker_iOS.h
//  Ramshackle
//
//  Created by David Sweetman on 5/4/15.
//  Copyright (c) 2015 tinfish. All rights reserved.
//

#ifndef __Ramshackle__Ticker_iOS__
#define __Ramshackle__Ticker_iOS__

#include "Ticker.h"
@class DisplayLinkTicker;

NS_RAM_OPEN

class Ticker_iOS : public Ticker {
public:
    void start() override;
    void stop() override;
    void tick() override;
    Ticker_iOS();
    ~Ticker_iOS();
protected:
    DisplayLinkTicker *_displayLinkTicker;
};

NS_RAM_CLOSE

#endif /* defined(__Ramshackle__Ticker_iOS__) */
