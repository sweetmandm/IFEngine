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
        [button setTitleColor:[StylesiOS blue] forState:UIControlStateNormal];
        
    } else if ([buttonThing isKindOfClass:[AnswerButton class]]) {
        
        AnswerButton *button = buttonThing;
        [button setTitleColor:[StylesiOS blue]];
        
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

+ (UIColor*)green {
    return [UIColor colorWithRed:40.0/255.0
                           green:200.0/255.0
                            blue: 30.0/255.0
                           alpha:1.0];
}

+ (UIColor*)blue {
    return [UIColor colorWithRed:130.0/255.0
                           green:180.0/255.0
                            blue: 240.0/255.0
                           alpha:1.0];
}

+ (UIColor*)red {
    return [UIColor colorWithRed:200.0/255.0
                           green:40.0/255.0
                            blue: 30.0/255.0
                           alpha:1.0];
}

+ (UIColor*)dark {
    return [UIColor colorWithRed:2.0/255.0
                           green:2.0/255.0
                            blue: 8.0/255.0
                           alpha:1.0];
}

+ (UIColor*)gray {
    return [UIColor colorWithRed:101.0/255.0
                           green:101.0/255.0
                            blue: 115.0/255.0
                           alpha:1.0];
}

@end
