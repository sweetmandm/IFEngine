//
//  FileManager-osx.cpp
//  Ramshackle
//
//  Created by David Sweetman on 10/20/14.
//  Copyright (c) 2014 tinfish. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "FileManager-osx.h"
#include "PlatformMacros.h"
#include <fstream>
#include <sstream>

NS_RAM_OPEN

FileManagerOSX::FileManagerOSX() { }
FileManagerOSX::~FileManagerOSX() { }

FileManager* FileManager::getManager()
{
    if (_sharedManager == nullptr)
    {
        _sharedManager = new (std::nothrow) FileManagerOSX();
    }
    return _sharedManager;
}

std::string FileManagerOSX::getFullPath(const std::string& filename) const
{
    NSString* fullpath = [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:filename.c_str()]
                                                         ofType:nil];
    if (fullpath != nil) {
        return [fullpath UTF8String];
    }
    RAM_LOG("WARNING: File not found: %s", filename.c_str());
    RAM_PARAM_ASSERT(fullpath != nil);
    return "";
}

std::string FileManagerOSX::getStringFromFile(const std::string& filepath) const
{
    NSString *path = [NSString stringWithUTF8String:filepath.c_str()];
    NSError *error = nil;
    NSString *str = [NSString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:&error];
    
    std::string ret((const char*)[str UTF8String]);
    return ret;
}

std::vector<std::string> FileManagerOSX::splitLinesIntoVectorFromFile(const std::string& filepath) const
{
    std::vector<std::string> lines;
    std::ifstream infile(filepath);
    while (infile) {
        std::string line;
        if (!getline(infile, line)) { break; }
        if (line.length() > 0) {
            lines.push_back(line);
        }
    }
    return lines;
}

NS_RAM_CLOSE
