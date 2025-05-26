#include "mob.h"

#include "utils.h"

// Some local rules to keep track of mobs specific damage rules.
u16 smjxxd_zombie_damage_rules(GameObject *bullet);
u16 smjxxd_skeleton_damage_rules(GameObject *bullet);
u16 smjxxd_mutant_damage_rules(GameObject *bullet);
u16 smjxxd_ghost_damage_rules(GameObject *bullet);
u16 smjxxd_imp_damage_rules(GameObject *bullet);

void smjxxd_mob_apply_damage(GameObject *mob, GameObject *bullet)
{
  u16 damage = 0;

  switch (mob->type)
  {
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
  default:
    damage = 0;
  }

  // Shield first breaks, and then, the mob start to take damage.
  if (mob->shield >= 0)
    mob->shield = smjxxd_utils_drain(mob->shield, damage);
  else if (mob->health >= 0)
    mob->health = smjxxd_utils_drain(mob->health, damage);
}

u16 smjxxd_skeleton_damage_rules(GameObject *bullet)
{
  // TODO: Implement
}

u16 smjxxd_skeleton_damage_rules(GameObject *bullet)
{
  // TODO: Implement
}

u16 smjxxd_mutant_damage_rules(GameObject *bullet)
{
  // TODO: Implement
}

u16 smjxxd_ghost_damage_rules(GameObject *bullet)
{
  // TODO: Implement
}

u16 smjxxd_imp_damage_rules(GameObject *bullet)
{
  // TODO: Implement
}