//
//  MessageView.m
//  Ramshackle
//
//  Created by David Sweetman on 12/23/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#import "MessageView.h"
#import "UIComponentMessage.hpp"
#import "StylesiOS.h"
#import "ActionMessage.hpp"

@implementation MessageView

- (void)setComponent:(ram::UIComponentMessage *)component
{
    _component = component;
    [self configureUI];
}

- (void)configureUI
{
    if (_component == nullptr) { return; }
    NSString *messageText = [NSString stringWithCString:self.component->getMessageText().c_str()
                                               encoding:NSUTF8StringEncoding];
    self.messageLabel.text = messageText;
    self.messageLabel.font = [StylesiOS fontWithSize:20.0];
    self.messageLabel.backgroundColor = [UIColor clearColor];
    
    NSString *acceptText = [NSString stringWithCString:self.component->getAcceptText().c_str()
                                              encoding:NSUTF8StringEncoding];
    [self.acceptButton setTitle:acceptText forState:UIControlStateNormal];
    self.acceptButton.titleLabel.font = [StylesiOS fontWithSize:20.0];
    ApplyNeutralButtonStyle(self.acceptButton);
}

- (IBAction)acceptButtonPressed:(id)sender
{
    self.component->acceptMessage();
}

- (void)dealloc
{
    RAM_LOG("MessageView dealloc");
}

@end
