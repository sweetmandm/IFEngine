//
//  Rect.h
//  Ramshackle
//
//  Created by David Sweetman on 2/28/15.
//  Copyright (c) 2015 tinfish. All rights reserved.
//

#ifndef Ramshackle_Rect_h
#define Ramshackle_Rect_h

#include "PlatformMacros.h"
#include "Point2D.h"
#include "Size2D.h"

NS_RAM_OPEN

struct Rect {
    Point2D origin;
    Size2D size;
};

inline bool rectEqual(const Rect& r1, const Rect& r2) {
    return (point2DEqual(r1.origin, r2.origin) && sizeEqual(r1.size, r2.size));
};

NS_RAM_CLOSE

#endif
