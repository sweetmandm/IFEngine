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

- (void)setComponent:(ram::UIComponentMessageList *)component
{
    _component = component;
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

