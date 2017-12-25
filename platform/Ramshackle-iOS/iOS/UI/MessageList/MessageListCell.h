//
//  MessageListCell.h
//  Ramshackle-iOS
//
//  Created by sweetman on 12/7/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <string>

typedef NS_ENUM(NSInteger, MessageListCellStyle) {
    MessageListCellStyleLight,
    MessageListCellStyleDark
};

@interface MessageListCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *messageLabel;

+ (NSString*)reuseID;
+ (UINib*)nib;
- (void)setMessage:(std::string)message;
- (void)setStyle:(MessageListCellStyle)style;

@end
