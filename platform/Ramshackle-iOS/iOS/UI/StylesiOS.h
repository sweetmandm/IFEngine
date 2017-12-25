//
//  StylesiOS.h
//  Ramshackle
//
//  Created by David Sweetman on 12/24/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#import <UIKit/UIKit.h>

void ApplyNeutralButtonStyle(id buttonThing);

@interface StylesiOS : UIView

+ (UIFont*)fontWithSize:(CGFloat)size;
+ (UIColor*)blue;
+ (UIColor*)green;
+ (UIColor*)red;
+ (UIColor*)dark;
+ (UIColor*)gray;

@end
