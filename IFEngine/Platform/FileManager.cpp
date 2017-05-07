//
//  FileManager.cpp
//  Ramshackle
//
//  Created by David Sweetman on 10/20/14.
//  Copyright (c) 2014 tinfish. All rights reserved.
//

#include "FileManager.h"

NS_RAM_OPEN

FileManager::FileManager() { }
FileManager::~FileManager() { }

FileManager* FileManager::_sharedManager = nullptr;

void FileManager::deleteSharedManager()
{
    SAFE_DELETE(_sharedManager);
}

NS_RAM_CLOSE
