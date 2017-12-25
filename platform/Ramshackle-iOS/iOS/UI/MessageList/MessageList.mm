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

- (int)lastRow {
    return ((int)[self messages]->size()) - 1;
}

- (void)didAppendMessage {
    int lastRow = [self lastRow] - 1;
    BOOL bottomIsVisible = ((NSIndexPath*)[[self.tableView indexPathsForVisibleRows] lastObject]).row == lastRow;
    NSIndexPath *newIndexPath = [NSIndexPath indexPathForRow:lastRow + 1 inSection:0];
    if (bottomIsVisible) {
        [self.tableView insertRowsAtIndexPaths:@[newIndexPath]
                              withRowAnimation:UITableViewRowAnimationAutomatic];
    } else {
        [self.tableView reloadData];
    }
    [self.tableView scrollToRowAtIndexPath:newIndexPath
                          atScrollPosition:UITableViewScrollPositionTop
                                  animated:YES];
    [self updateCellAppearances];
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
    [self updateCellAppearance:cell atIndexPath:indexPath];
    return cell;
}

- (void)updateCellAppearance:(MessageListCell*)cell atIndexPath:(NSIndexPath*)ip {
    MessageListCellStyle style = (ip.row == [self lastRow] ?
                                  MessageListCellStyleDark :
                                  MessageListCellStyleLight);
    [cell setStyle:style];
}

- (void)updateCellAppearances {
    for (NSIndexPath *ip in [self.tableView indexPathsForVisibleRows]) {
        MessageListCell *cell = (MessageListCell*)[self.tableView cellForRowAtIndexPath:ip];
        [self updateCellAppearance:cell atIndexPath:ip];
    }
}

@end

