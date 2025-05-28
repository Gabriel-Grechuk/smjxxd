#include "mob.h"

#include <tools.h>

#include "globals.h"
#include "resources.h"
#include "utils.h"

/**
 * TODO:
 * Make the mortar and explosives damage a function of the distance of the mob
 * from the explosion
 */

u16 smjxxd_zombie_damage_rules(GameObject *bullet);
u16 smjxxd_skeleton_damage_rules(GameObject *bullet);
u16 smjxxd_mutant_damage_rules(GameObject *bullet);
u16 smjxxd_ghost_damage_rules(GameObject *bullet);
u16 smjxxd_imp_damage_rules(GameObject *bullet);
u16 smjxxd_boss_damage_rules(GameObject *bullet);

/******************************************************************************
 * Module implementations.
 */
inline void smjxxd_mob_init(GameObject *mob, MobType type) {
  switch (type) {
  case ZOMBIE:
    smjxxd_game_object_init(mob, &spr_zombie, SCREEN_W - 8,
                            smjxxd_utils_random_floor_position(), 0, 0,
                            PAL_MOBS, sprite_index);
    mob->speed_x = FIX16(-1);
    mob->speed_y = FIX16(0);
    break;

  case SKELETON:
    break;

  case MUTANT:
    break;

  case GHOST:
    break;

  case IMP:
    break;

  case BOSS:
    break;
  }
}

inline void smjxxd_mob_apply_damage(GameObject *mob, GameObject *bullet,
                                    u8 distance) {
  u16 damage = 0;

  switch (mob->type) {
  case ZOMBIE:
    damage = smjxxd_zombie_damage_rules(bullet);
    break;

  case SKELETON:
    damage = smjxxd_skeleton_damage_rules(bullet);
    break;

  case MUTANT:
    damage = smjxxd_mutant_damage_rules(bullet);
    break;

  case GHOST:
    damage = smjxxd_ghost_damage_rules(bullet);
    break;

  case IMP:
    damage = smjxxd_imp_damage_rules(bullet);
    break;

  case BOSS:
    damage = smjxxd_boss_damage_rules(bullet);
    break;

  default:
    damage = 0;
  }

  // Shield first breaks, and then, the mob start to take damage.
  if (mob->shield > 0)
    mob->shield = smjxxd_utils_drain(mob->shield, damage);
  else if (mob->health > 0)
    mob->health = smjxxd_utils_drain(mob->health, damage);
}

/******************************************************************************
 * Local implementations.
 */
inline u16 smjxxd_zombie_damage_rules(GameObject *bullet) {
  switch (bullet->type) {
  case SPLASH:
    return 0;

  default:
    return bullet->damage;
  }
}

inline u16 smjxxd_skeleton_damage_rules(GameObject *bullet) {
  switch (bullet->type) {
  case SPLASH:
    return 0;

  // 25% miss chance for gun bullets.
  case SNIPE_BULLET:
    if ((random() % 4) == 0)
      return 0;
    return bullet->damage;

  // 50% miss chance for gun bullets.
  case METRALHA_BULLET:
    if ((random() % 2) == 0)
      return 0;
    return bullet->damage;

  default:
    return bullet->damage;
  }
}

inline u16 smjxxd_mutant_damage_rules(GameObject *bullet) {
  switch (bullet->type) {
  case SPLASH:
    return 0;

  default:
    return bullet->damage;
  }
}

inline u16 smjxxd_ghost_damage_rules(GameObject *bullet) {
  switch (bullet->type) {
  // No damage from area attacks.
  case EXPLOSION:
  case HOLY_EXPLOSION:
  case MORTAR_BULLET:
  case SPLASH:
    return 0;

  default:
    return bullet->damage;
  }
}

inline u16 smjxxd_imp_damage_rules(GameObject *bullet) {
  switch (bullet->type) {
  // +25% Damage for holy grenades.
  case HOLY_EXPLOSION:
    return (u16)(bullet->damage + bullet->damage * 0.25);

  default:
    return bullet->damage;
  }
}

inline u16 smjxxd_boss_damage_rules(GameObject *bullet) {
  // Will take all damages.
  return bullet->damage;
}