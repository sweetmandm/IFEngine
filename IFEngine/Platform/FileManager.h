//
//  FileManager.h
//  Ramshackle
//
//  Created by David Sweetman on 10/20/14.
//  Copyright (c) 2014 tinfish. All rights reserved.
//

#ifndef __Ramshackle__FileManager__
#define __Ramshackle__FileManager__

#include "PlatformMacros.h"
#include <string>

NS_RAM_OPEN

class FileManager
{
public:
    static FileManager* getManager();
    static void deleteSharedManager();
    virtual ~FileManager();
    virtual std::string getFullPath(const std::string& filename) const = 0;
    virtual std::string getStringFromFile(const std::string& filename) const = 0;
    virtual std::vector<std::string> splitLinesIntoVectorFromFile(const std::string& filepath) const = 0;
protected:
    FileManager();
    static FileManager* _sharedManager;
};

NS_RAM_CLOSE

#endif /* defined(__Ramshackle__FileManager__) */
