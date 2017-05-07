//
//  Point2D.h
//  Ramshackle
//
//  Created by David Sweetman on 2/28/15.
//  Copyright (c) 2015 tinfish. All rights reserved.
//

#ifndef Ramshackle_Point_h
#define Ramshackle_Point_h

#include "PlatformMacros.h"

NS_RAM_OPEN

struct Point2D {
    float x;
    float y;
};

inline bool point2DEqual(const Point2D& p1, const Point2D& p2) {
    return (p1.x == p2.x && p1.y == p2.y);
};

NS_RAM_CLOSE

#endif
