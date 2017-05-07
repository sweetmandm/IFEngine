//
//  FullTextView.m
//  Ramshackle
//
//  Created by David Sweetman on 12/26/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#import "FullTextView.h"

@interface FullTextView ()
@property (nonatomic, strong) NSLayoutConstraint *heightConstraint;
@end

@implementation FullTextView

- (void)layoutSubviews
{
    [super layoutSubviews];
    
    CGSize size = [self sizeThatFits:CGSizeMake(self.bounds.size.width, FLT_MAX)];
    
    if (!self.heightConstraint) {
        self.heightConstraint = [NSLayoutConstraint
                                 constraintWithItem:self
                                 attribute:NSLayoutAttributeHeight
                                 relatedBy:NSLayoutRelationEqual
                                 toItem:nil
                                 attribute:0
                                 multiplier:1.0f
                                 constant:size.height];
        [self addConstraint:self.heightConstraint];
    }
    
    self.heightConstraint.constant = size.height;
    
    [super layoutSubviews];
}

@end