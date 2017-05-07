//
//  AnswerButton.m
//  Ramshackle
//
//  Created by David Sweetman on 12/24/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#import "AnswerButton.h"
#import "ActionQuestion.hpp"
#import "UIView+Helper.h"
#import "QuestionView.h"
#import "StylesiOS.h"
#import "Masonry.h"

@interface AnswerButton()
@property (strong, nonatomic) UIButton *button;
@property (strong, nonatomic) UILabel *answerLabel;
@property (weak, nonatomic) QuestionView *owner;
@property (assign, nonatomic) ram::Answer answer;
@end

@implementation AnswerButton

- (instancetype)initWithFrame:(CGRect)frame answer:(ram::Answer)answer owner:(QuestionView*)owner
{
    self = [super initWithFrame:frame];
    if (self) {
        self.owner = owner;
        self.answer = answer;
        self.autoresizingMask = UIViewAutoresizingFlexibleWidth;
        self.translatesAutoresizingMaskIntoConstraints = YES;
        [self configureUI];
    }
    return self;
}

- (void)configureUI
{
    self.answerLabel = [[UILabel alloc] initWithFrame:self.frame];
    self.answerLabel.numberOfLines = 0;
    [self addSubview:self.answerLabel];
    [self.answerLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.mas_left);
        make.right.equalTo(self.mas_right);
        make.top.equalTo(self.mas_top);
        make.height.greaterThanOrEqualTo(@40);
    }];
    [self mas_makeConstraints:^(MASConstraintMaker *make) {
        make.height.equalTo(self.answerLabel.mas_height);
    }];
    self.answerLabel.textAlignment = NSTextAlignmentLeft;
    
    self.answerLabel.userInteractionEnabled = NO;
    self.answerLabel.text = [NSString stringWithCString:self.answer.text.getText()->c_str()
                                               encoding:NSUTF8StringEncoding];
    self.answerLabel.font = [StylesiOS fontWithSize:20.0];
    self.button = [UIButton buttonWithType:UIButtonTypeCustom];
    self.button.frame = self.frame;
    [self addSubview:self.button];
    [self.button fillSuperview];
    [self.button addTarget:self action:@selector(didSelectAnswer:) forControlEvents:UIControlEventTouchUpInside];
}

- (void)didSelectAnswer:(id)sender
{
    [self.owner didSelectAnswer:self.answer];
}

- (void)setTitleColor:(UIColor*)color
{
    [self.answerLabel setTextColor:color];
}

@end
