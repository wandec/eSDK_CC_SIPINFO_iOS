//
//  SecurityMacros.h
//  eSpaceIOSSDK
//
//  Created by h00195524 on 15/1/19.
//  Copyright (c) 2015年 Huawei Technologies Co., Ltd. All rights reserved.
//

#ifndef eSpaceIOSSDK_SecurityMacros_h
#define eSpaceIOSSDK_SecurityMacros_h

#define USING_HW_SECURITY_LIBRARY 1

#if USING_HW_SECURITY_LIBRARY

#include "securec.h"

#define HW_MEMSET(dest, destmax, src, count) memset_s(dest, destmax, src, count)
#define HW_MEMCPY(dest, destmax, src, count) memcpy_s(dest, destmax, src, count)
#define HW_MEMMOVE(dest, destmax, src, count) memmove_s(dest, destmax, src, count)
#define HW_STRNCPY(dest, destmax, src, count) strncpy_s(dest, destmax, src, count)

#else

#define HW_MEMSET(dest, destmax, src, count) memset(dest, src, count)
#define HW_MEMCPY(dest, destmax, src, count) memcpy(dest, src, count)
#define HW_MEMMOVE(dest, destmax, src, count) memmove(dest, src, count)
#define HW_STRNCPY(dest, destmax, src, count) strncpy(dest, src, count)

#endif // USING_HW_SECURITY_LIBRARY

#define HW_RANDOM_INT(max) arc4random_uniform(max)

#endif
