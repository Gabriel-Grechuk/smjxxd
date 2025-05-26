#ifndef _SMJXXD_MOBS_H_
#define _SMJXXD_MOBS_H_

#include "game_object.h"

typedef enum
{
  // Guns.
  SNIPE,
  MORTAR,
  METRALHA,
  HOLY_GRENADE,
  VAP,

  // Bullets.
  GUN_BULLET,
  MORTAR_BULLET,
  EXPLOSION,
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
void smjxxd_mob_apply_damage(GameObject mob, GameObject bullet);

#endif