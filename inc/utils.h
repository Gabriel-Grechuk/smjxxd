#ifndef _SMJXXD_UTILS_H_
#define _SMJXXD_UTILS_H_

#include "globals.h"
#include "game_object.h"
#include <genesis.h>

// DEBUG util
#ifdef DEBUG

#define DEBUG_LOG(X) (KLog(X))
#define DEBUG_LOG_NUM(X, Y) (KLog_U1(X, Y))
#define DEBUG_LOG_NUM_F(X, Y) (KLog_F1(X, Y))

#else

#define DEBUG_LOG(X)
#define DEBUG_LOG_NUM(X, Y)
#define DEBUG_LOG_NUM_F(X, Y)

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

/**
 * Return the amount of velocity a object need to intersect a point in N secs.
 *
 * @Args:
 *   f16 pi: The initial point.
 *   f16 pf: The final point.
 *   f16 t:  The desired time.
 *
 * @Returns:
 *   f16: The velocity.
 *
 * Consider this:
 *
 *    Pi(x, y) + --> Vx
 *          Vy |\
 *             v \
 *                \
 *                 + Pf(x, y)
 *
 * You can decompose the amount of vertical and horizontal velocity the object
 * in Pi needs to move to intersect the Pf point in 1 second, like:
 *  f15 Vx = smjxxd_utils_get_velocity_to_reach_point(Pi.x, Pf.x, 1)
 *  f15 Vy = smjxxd_utils_get_velocity_to_reach_point(Pi.y, Pf.y, 1)
 */
f16 smjxxd_utils_get_velocity_to_reach_point(f16 pi, f16 pf, f16 t);

/**
 * Check overlap.
 */
bool smjxxd_utils_check_overlap(GameObject *obj1, GameObject *obj2);

#endif