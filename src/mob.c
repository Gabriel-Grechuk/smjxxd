#include "mob.h"
#include <tools.h>

#include "utils.h"

/**
 * TODO:
 * Make the mortar and explosives damage a function of the distance of the mob
 * from the explosion
 */

// Some local rules to keep track of mobs specific damage rules.
u16 smjxxd_zombie_damage_rules(GameObject *bullet);
u16 smjxxd_skeleton_damage_rules(GameObject *bullet);
u16 smjxxd_mutant_damage_rules(GameObject *bullet);
u16 smjxxd_ghost_damage_rules(GameObject *bullet);
u16 smjxxd_imp_damage_rules(GameObject *bullet);
u16 smjxxd_boss_damage_rules(GameObject *bullet);

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
  default:
    damage = 0;
  }

  // Shield first breaks, and then, the mob start to take damage.
  if (mob->shield >= 0)
    mob->shield = smjxxd_utils_drain(mob->shield, damage);
  else if (mob->health >= 0)
    mob->health = smjxxd_utils_drain(mob->health, damage);
}

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
    u16 hit = random() % 4;
    if (hit == 0)
      return 0;
    return bullet->damage;

  // 50% miss chance for gun bullets.
  case METRALHA_BULLET:
    u16 hit = random() % 2;
    if (hit == 0)
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