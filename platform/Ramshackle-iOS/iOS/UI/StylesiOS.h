//
//  StylesiOS.h
//  Ramshackle
//
//  Created by David Sweetman on 12/24/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#import <UIKit/UIKit.h>

#define STYLES_BLUE ([UIColor colorWithRed:130.0/255.0 green:180.0/255.0 blue: 240.0/255.0 alpha:1.0])
#define STYLES_RED ([UIColor colorWithRed:200.0/255.0 green:40.0/255.0 blue: 30.0/255.0 alpha:1.0])
#define STYLES_GREEN ([UIColor colorWithRed:40.0/255.0 green:200.0/255.0 blue: 30.0/255.0 alpha:1.0])

void ApplyNeutralButtonStyle(id buttonThing);

@interface StylesiOS : UIView

+ (UIFont*)fontWithSize:(CGFloat)size;

@end
