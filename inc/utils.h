#ifndef _SMJXXD_UTILS_H_
#define _SMJXXD_UTILS_H_

#include <genesis.h>

// DEBUG util
#ifdef DEBUG

#define DEBUG_LOG(X) (KLog(X))
#define DEBUG_LOG_NUM(X, Y) (KLog_F1(X, Y))

#else

#define DEBUG_LOG(X)
#define DEBUG_LOG_NUM(X, Y)

#endif

// Decrease and prevent negative numbers.
u16 smjxxd_utils_drain(u16 value, u16 decrease);

/**
 * Random positioning in the floor.
 */
u16 smjxxd_utils_random_floor_position();

/**
 * Random positioning in the floor.
 */
f16 smjxxd_utils_random_speed();

#endif