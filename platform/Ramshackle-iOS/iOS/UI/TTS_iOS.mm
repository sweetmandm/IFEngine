//
//  TTS_iOS.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/12/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#import "TTS_iOS.hpp"
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <AVFoundation/AVSpeechSynthesis.h>

@interface TTSState: NSObject <AVSpeechSynthesizerDelegate>
@property (strong, nonatomic) NSMutableArray<NSString*>* utteranceQueue;
@property (strong, nonatomic) AVSpeechSynthesizer *synth;
@property (strong, nonatomic) NSString *current;
@end

@implementation TTSState

+ (instancetype)shared {
    static TTSState *instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[TTSState alloc] init];
    });
    return instance;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.utteranceQueue = [[NSMutableArray alloc] init];
        self.synth = [[AVSpeechSynthesizer alloc] init];
        self.synth.delegate = self;
    }
    return self;
}

- (void)add:(NSString*)text {
    [self.utteranceQueue addObject:text];
    [self speakNext];
}

- (void)speakNext {
    if (self.current != nil) {
        return;
    }
    NSString *next = [self.utteranceQueue firstObject];
    self.current = next;
    if (next) {
        [self.utteranceQueue removeObjectAtIndex:0];
        AVSpeechUtterance *u = [[AVSpeechUtterance alloc] initWithString:next];
        [self.synth speakUtterance:u];
    }
}

- (void)speechSynthesizer:(AVSpeechSynthesizer *)synthesizer didFinishSpeechUtterance:(AVSpeechUtterance *)utterance {
    self.current = nil;
    [self speakNext];
}

- (void)speechSynthesizer:(AVSpeechSynthesizer *)synthesizer didCancelSpeechUtterance:(AVSpeechUtterance *)utterance {
    self.current = nil;
    [self speakNext];
}

@end

void ram::TTS::speak(std::string text) {
    [[TTSState shared] add:[NSString stringWithUTF8String:text.c_str()]];
}
