//
//  QuestionView.m
//  Ramshackle
//
//  Created by David Sweetman on 12/24/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#import "QuestionView.h"
#import "UIComponentQuestion.hpp"
#import "ActionQuestion.hpp"
#import "StylesiOS.h"
#import "AnswerButton.h"
#import "Masonry.h"
#import "FullTextView.h"

@interface QuestionView()
@property (strong, nonatomic) UITextView *textView;
@property (strong, nonatomic) NSMutableArray *views;
@end

@implementation QuestionView

- (void)setComponent:(ram::UIComponentQuestion *)component
{
    _component = component;
    [self setupUI];
}

- (void)setupUI
{
    self.backgroundColor = [UIColor clearColor];
    
    self.scrollView = [[UIScrollView alloc] initWithFrame:self.frame];
    [self addSubview:self.scrollView];
    
    [self.scrollView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.mas_left);
        make.right.equalTo(self.mas_right);
        make.top.equalTo(self.mas_top);
        make.width.equalTo(self.mas_width);
        make.height.equalTo(self.mas_height);
    }];
    self.views = [[NSMutableArray alloc] init];
    
    [self makeTextView];
    
    for (auto answer : self.component->getAvailableAnswers()) {
        [self addAnswer:answer];
    }
    [self installBottomConstraint];
    [self updateTextViewText];
}

- (void)installBottomConstraint
{
    [self.views.lastObject mas_makeConstraints:^(MASConstraintMaker *make) {
        make.bottom.equalTo(self.scrollView.mas_bottom).with.offset(-40.0);
    }];
}

- (void)updateTextViewText
{
    NSString *question = [NSString stringWithCString:self.component->getQuestionText().c_str()
                                            encoding:NSUTF8StringEncoding];
    self.textView.text = question;
    [self.textView layoutSubviews];
}

- (void)makeTextView
{
    self.textView = [[FullTextView alloc] initWithFrame:CGRectZero];
    self.textView.backgroundColor = [UIColor clearColor];
    self.textView.editable = NO;
    self.textView.selectable = NO;
    self.textView.scrollEnabled = NO;
    
    UIFont *font = [StylesiOS fontWithSize:16.0];
    self.textView.font = font;
    self.textView.translatesAutoresizingMaskIntoConstraints = NO;
    [self.textView setTextColor:[UIColor whiteColor]];
    [self.scrollView addSubview:self.textView];
    [self.views addObject:self.textView];
    
    CGFloat padding = 16.0;
    [self.textView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.scrollView.mas_left).with.offset(padding);
        make.right.equalTo(self.scrollView.mas_right).with.offset(-padding);
        make.width.equalTo(self.scrollView.mas_width).with.offset(-padding*2);
        make.top.equalTo(self.scrollView.mas_top).with.offset(60.0);
    }];
}

- (void)addAnswer:(ram::Answer)answer
{
    UIView *last = [self.views lastObject];
    AnswerButton *button = [[AnswerButton alloc] initWithFrame:CGRectZero answer:answer owner:self];
    ApplyNeutralButtonStyle(button);
    
    button.translatesAutoresizingMaskIntoConstraints = NO;
    [self.scrollView addSubview:button];
    [button mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(last.mas_left);
        make.right.equalTo(last.mas_right);
        make.top.equalTo(last.mas_bottom).with.offset(10.0);
        make.width.equalTo(last.mas_width);
    }];
    [self.views addObject:button];
}

- (void)didSelectAnswer:(ram::Answer)answer
{
    self.component->answer(answer);
}

- (void)dealloc
{
    RAM_LOG("QuestionView dealloc");
}

@end
