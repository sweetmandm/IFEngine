//
//  MessageListCell.m
//  Ramshackle-iOS
//
//  Created by sweetman on 12/7/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#import "MessageListCell.h"
#import "StylesiOS.h"

@implementation MessageListCell

+ (NSString*)reuseID {
    return @"MessageListCell";
}

+ (UINib*)nib {
    return [UINib nibWithNibName:@"MessageListCell" bundle:nil];
}

- (void)awakeFromNib {
    [super awakeFromNib];
}

- (void)configureUI {
    self.messageLabel.font = [StylesiOS fontWithSize:16.0];
}

- (void)setMessage:(std::string)message {
    [self.messageLabel setText:[NSString stringWithUTF8String:message.c_str()]];
}

@end
