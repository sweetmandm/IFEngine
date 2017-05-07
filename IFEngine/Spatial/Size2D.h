//
//  Size.h
//  Ramshackle
//
//  Created by David Sweetman on 2/28/15.
//  Copyright (c) 2015 tinfish. All rights reserved.
//

#ifndef Ramshackle_Size_h
#define Ramshackle_Size_h

#include "PlatformMacros.h"

NS_RAM_OPEN

struct Size2D {
    float w;
    float h;
};

inline bool sizeEqual(const Size2D& s1, const Size2D& s2) {
    return (s1.w == s2.w && s1.h == s2.h);
};

NS_RAM_CLOSE

#endif
