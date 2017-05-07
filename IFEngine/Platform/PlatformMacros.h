//
//  PlatformMacros.h
//  Ramshackle
//
//  Created by David Sweetman on 10/19/14.
//  Copyright (c) 2014 tinfish. All rights reserved.
//

#include "PlatformIncludes.h"

#ifndef Ramshackle_PlatformMacros_h
#define Ramshackle_PlatformMacros_h

/* namespace */

#define NS_RAM_OPEN     namespace ram {
#define NS_RAM_CLOSE    }

/* logging */

#ifndef RAM_LOG
#if DEBUG
#   define RAM_PRINT_FNAME() fprintf(stderr, "\n%s (%s, line %d)\n", __func__, __FILE__, __LINE__)
#   define RAM_LOG(...) do{\
        fprintf(stderr, "%s (%s, line %d): ", __func__, __FILE__, __LINE__); \
        fprintf(stderr, __VA_ARGS__);           \
        fprintf(stderr, "\n");} while(0)
#   define RAM_LOG_STR(str) RAM_LOG("%s", (str).c_str())
#else
#   define RAM_PRINT_FNAME(...)
#   define RAM_LOG(...)
#   define RAM_LOG_STR(str)
#endif /* DEBUG */
#endif /* RAM_LOG */

/* assert */

#ifndef RAM_ASSERT
#define RAM_ASSERT(predicate, message) \
if (!(predicate)) { RAM_LOG(message); } assert(predicate)
#endif /* RAM_ASSERT */

#ifndef RAM_PARAM_ASSERT
#define RAM_PARAM_ASSERT(predicate) RAM_ASSERT(predicate, "")
#endif

#define SAFE_DELETE(p) do { delete (p); (p) = nullptr; } while(0)

#endif /* Ramshackle_PlatformMacros_h */
