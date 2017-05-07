//
//  Ticker_iOS.cpp
//  Ramshackle
//
//  Created by David Sweetman on 5/4/15.
//  Copyright (c) 2015 tinfish. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuartzCore/CADisplayLink.h>
#include "Ticker_iOS.h"

@interface DisplayLinkTicker : NSObject
- (instancetype)initWithDelegate:(ram::Ticker_iOS*)delegate;
@property (strong, nonatomic) CADisplayLink *displayLink;
@property (assign, nonatomic) ram::Ticker_iOS *delegate;
@end

@implementation DisplayLinkTicker

- (instancetype)initWithDelegate:(ram::Ticker_iOS*)delegate {
    self = [super init];
    self.delegate = delegate;
    if (self) {
    }
    return self;
}

- (void)tick {
    self.delegate->tick();
}

- (void)start {
    if (self.displayLink) {
        [self stop];
    }
    self.displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(tick)];
    [self.displayLink addToRunLoop:[NSRunLoop mainRunLoop] forMode:NSRunLoopCommonModes];
}

- (void)stop {
    [self.displayLink removeFromRunLoop:[NSRunLoop mainRunLoop] forMode:NSRunLoopCommonModes];
    self.displayLink = nil;
}

- (void)dealloc
{
    [self stop];
}

@end

NS_RAM_OPEN

Ticker* Ticker::create()
{
    return new Ticker_iOS();
}

Ticker_iOS::Ticker_iOS()
{
    _displayLinkTicker = [[DisplayLinkTicker alloc] initWithDelegate:this];
}

Ticker_iOS::~Ticker_iOS()
{
    [_displayLinkTicker stop];
    _displayLinkTicker = nil;
}

void Ticker_iOS::start()
{
    [_displayLinkTicker start];
}

void Ticker_iOS::stop()
{
    [_displayLinkTicker stop];
}

void Ticker_iOS::tick()
{
    //WorldManager::sharedManager()->getRenderController()->tick();
}

NS_RAM_CLOSE
