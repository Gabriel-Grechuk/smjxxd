#ifndef _SMJXXD_MOBS_H_
#define _SMJXXD_MOBS_H_

#include "game_object.h"

typedef enum {
  // Guns.
  SNIPE,
  MORTAR,
  METRALHA,
  HOLY_GRENADE,
  VAP,

  // Bullets.
  SNIPE_BULLET,
  METRALHA_BULLET,
  MORTAR_BULLET,
  EXPLOSION,
  HOLY_EXPLOSION,
  SPLASH,

  // Monsters.
  ZOMBIE,
  SKELETON,
  MUTANT,
  GHOST,
  IMP,

  // The boss.
  BOSS
} MobType;

/**
 * Apply damage.
 */
inline void smjxxd_mob_apply_damage(GameObject mob, GameObject bullet,
                                    u8 distance);

#endif