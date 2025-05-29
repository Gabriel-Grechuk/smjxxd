#ifndef _SMJXXD_MOBS_H_
#define _SMJXXD_MOBS_H_

#include "game_object.h"

/**
 * Initialize a mob.
 */
void smjxxd_mob_init(GameObject *mob, MobType type);

/**
 * Apply damage to a mob.
 */
void smjxxd_mob_apply_damage(GameObject *mob, GameObject *bullet, u8 distance);

#endif