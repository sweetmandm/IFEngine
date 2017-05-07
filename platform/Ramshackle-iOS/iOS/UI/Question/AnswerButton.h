//
//  AnswerButton.h
//  Ramshackle
//
//  Created by David Sweetman on 12/24/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RamBase.h"

NS_RAM_OPEN
struct Answer;
NS_RAM_CLOSE
@class QuestionView;

@interface AnswerButton : UIView

- (instancetype)initWithFrame:(CGRect)frame answer:(ram::Answer)answer owner:(QuestionView*)owner;
- (void)setTitleColor:(UIColor*)color;

@end
