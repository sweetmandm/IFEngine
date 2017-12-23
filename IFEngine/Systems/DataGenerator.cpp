//
//  DataGenerator.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/18/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "DataGenerator.hpp"
#include "Data.hpp"
#include "RelationshipSystem.hpp"
#include "DataContentText.hpp"
#include "ComputerDiskInterface.hpp"
#include "ComputerSSD.hpp"

NS_RAM_OPEN

Data random_research_notes(Entity *owner) {
    std::string text = "Research Notes";
    DataContentText *content = new DataContentText(text);
    return Data(DataTypeText, content->getSize(), content);
}

void DataGenerator::generateData(Entity *computer, std::vector<Entity*> users) {
    ComputerDiskInterface *dif = computer->getComponent<ComputerDiskInterface>();
    if (dif == nullptr) { return; }
    
    auto owner = std::find_if(users.begin(), users.end(), [computer](Entity *u) {
        return find_relationship(u, RelationshipTypeOwnerOf, computer) != nullptr;
    });
    
    std::vector<Data> data;
    
    if (owner != users.end()) {
        data.push_back(random_research_notes(*owner));
    }
    
    for (auto item : data) {
        ComputerSSD *disk = dif->diskWithFree(item.getSize());
        disk->addData(item);
    }
}

NS_RAM_CLOSE
