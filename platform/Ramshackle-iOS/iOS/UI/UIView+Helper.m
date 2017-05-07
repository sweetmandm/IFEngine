//
//  UIViewHelper.m
//  Ramshackle
//
//  Created by David Sweetman on 12/24/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#import "UIView+Helper.h"

@implementation UIView (Helper)

- (void)fillSuperview
{
    NSParameterAssert(self.superview);
    
    self.translatesAutoresizingMaskIntoConstraints = NO;
    NSDictionary *dict = NSDictionaryOfVariableBindings(self);
    
    [self.superview addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|[self]|" options:NSLayoutFormatAlignAllCenterX metrics:nil views:dict]];
    [self.superview addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[self]|" options:NSLayoutFormatAlignAllCenterY metrics:nil views:dict]];
}

@end
