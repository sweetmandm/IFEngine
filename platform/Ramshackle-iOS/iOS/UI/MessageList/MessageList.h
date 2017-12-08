//
//  MessageList.h
//  Ramshackle-iOS
//
//  Created by sweetman on 12/5/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RamBase.h"

NS_RAM_OPEN
class UIComponentMessageList;
NS_RAM_CLOSE

@interface MessageList : UIView

@property (assign, nonatomic) ram::UIComponentMessageList *component;
@property (weak, nonatomic) IBOutlet UITableView *tableView;
- (void)setComponent:(ram::UIComponentMessageList *)component;
- (void)reload;
- (void)didAppendMessage;

@end
