#ifndef _SMJXXD_MOBS_H_
#define _SMJXXD_MOBS_H_

#include "game_object.h"

#define MONSTERS_AMOUNT 10
#define MONSTERS_ON_SCREEN 6

extern u8 monster_count;
extern GameObject monster_list[];

/**
 * Initialize a mob.
 */
void smjxxd_monster_init(GameObject *mob, MobType type);

/**
 * Apply damage to a mob.
 */
void smjxxd_monster_apply_damage(GameObject *mob, GameObject *bullet,
                                 u8 distance);

#endif