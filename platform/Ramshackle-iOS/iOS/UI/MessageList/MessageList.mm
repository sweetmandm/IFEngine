//
//  MessageList.m
//  Ramshackle-iOS
//
//  Created by sweetman on 12/5/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#import "MessageList.h"
#import "UIComponentMessageList.hpp"
#import "MessageListCell.h"

@interface MessageList() <UITableViewDelegate, UITableViewDataSource>
@end

@implementation MessageList

- (void)awakeFromNib {
    [super awakeFromNib];
    [self registerCells];
    [self reload];
}

- (void) setupUI {
    [self.tableView setTableFooterView:[[UIView alloc] initWithFrame:CGRectZero]];
}

- (void)setComponent:(ram::UIComponentMessageList *)component
{
    _component = component;
    [self setupUI];
    [self reload];
}

- (void)registerCells {
    [self.tableView registerNib:[MessageListCell nib]
         forCellReuseIdentifier:[MessageListCell reuseID]];
}

- (void)reload {
    if (!self.component) { return; }
    [self.tableView reloadData];
}

- (void)didAppendMessage {
    BOOL topIsVisible = ((NSIndexPath*)[[self.tableView indexPathsForVisibleRows] firstObject]).row == 0;
    if (topIsVisible) {
        [self.tableView insertRowsAtIndexPaths:@[[NSIndexPath indexPathForRow:0 inSection:0]]
                              withRowAnimation:UITableViewRowAnimationAutomatic];
    } else {
        [self.tableView reloadData];
    }
    [self.tableView scrollToRowAtIndexPath:[NSIndexPath indexPathForRow:0 inSection:0]
                          atScrollPosition:UITableViewScrollPositionTop
                                  animated:YES];
}

- (std::vector<std::string>*)messages {
    RAM_PARAM_ASSERT(self.component);
    return self.component->getMessages();
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return (NSInteger)[self messages]->size();
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    MessageListCell *cell = [tableView dequeueReusableCellWithIdentifier:[MessageListCell reuseID]
                                                            forIndexPath:indexPath];
    std::string message = (*[self messages])[indexPath.row];
    [cell setMessage:message];
    return cell;
}

@end

