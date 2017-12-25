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
    [self configureUI];
}

- (void)configureUI {
    self.messageLabel.font = [StylesiOS fontWithSize:16.0];
}

- (void)setMessage:(std::string)message {
    [self.messageLabel setText:[NSString stringWithUTF8String:message.c_str()]];
}

- (void)setStyle:(MessageListCellStyle)style {
    switch (style) {
        case MessageListCellStyleLight:
            [self.messageLabel setTextColor:[StylesiOS gray]];
            break;
        case MessageListCellStyleDark:
            [self.messageLabel setTextColor:[StylesiOS dark]];
            break;
    }
}

@end
