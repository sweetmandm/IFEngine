//
//  QuestionView.h
//  Ramshackle
//
//  Created by David Sweetman on 12/24/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RamBase.h"

NS_RAM_OPEN
class UIComponentQuestion;
struct Answer;
NS_RAM_CLOSE

@interface QuestionView : UIView

@property (assign, nonatomic) ram::UIComponentQuestion *component;
@property (strong, nonatomic) UIScrollView *scrollView;

- (void)didSelectAnswer:(ram::Answer)answer;

@end
