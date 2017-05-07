//
//  FileManager-osx.h
//  Ramshackle
//
//  Created by David Sweetman on 10/20/14.
//  Copyright (c) 2014 tinfish. All rights reserved.
//

#ifndef __Ramshackle__FileManager_osx__
#define __Ramshackle__FileManager_osx__

#import "FileManager.h"

NS_RAM_OPEN

class FileManagerOSX : public FileManager
{
public:
    FileManagerOSX();
    ~FileManagerOSX();
    virtual std::string getFullPath(const std::string& filename) const override;
    virtual std::string getStringFromFile(const std::string& filepath) const override;
    virtual std::vector<std::string> splitLinesIntoVectorFromFile(const std::string& filepath) const override;
};

NS_RAM_CLOSE

#endif /* defined(__Ramshackle__FileManager_osx__) */
