//
//  StylesiOS.m
//  Ramshackle
//
//  Created by David Sweetman on 12/24/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#import "StylesiOS.h"
#import "AnswerButton.h"

void ApplyNeutralButtonStyle(id buttonThing)
{
    if ([buttonThing isKindOfClass:[UIButton class]]) {
        
        UIButton *button = buttonThing;
        [button setTitleColor:STYLES_BLUE forState:UIControlStateNormal];
        
    } else if ([buttonThing isKindOfClass:[AnswerButton class]]) {
        
        AnswerButton *button = buttonThing;
        [button setTitleColor:STYLES_BLUE];
        
    } else {
        
        RAM_ASSERT(false, "You've got to style a recognized object");
        
    }
}

@implementation StylesiOS

+ (UIFont*)fontWithSize:(CGFloat)size
{
    UIFont *font = [UIFont fontWithName:@"LiberationMono" size:size];
    NSParameterAssert(font);
    return font;
}

@end
