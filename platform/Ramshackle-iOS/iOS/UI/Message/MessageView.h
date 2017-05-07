//
//  MessageView.h
//  Ramshackle
//
//  Created by David Sweetman on 12/23/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RamBase.h"

NS_RAM_OPEN
class UIComponentMessage;
NS_RAM_CLOSE

@interface MessageView : UIView

@property (assign, nonatomic) ram::UIComponentMessage *component;
@property (weak, nonatomic) IBOutlet UILabel *messageLabel;
@property (weak, nonatomic) IBOutlet UIButton *acceptButton;

@end
