#include "world.h"

#include "mob.h"

/**
 * Local implementations.
 */
void smjxxd_world_spawn(WaveMonsters *wave);

/**
 * Module implementations.
 */
void smjxxd_world_update() {
  GameObject *mob = &monster_list[0];
  for (u8 i = 0; i < mob_count; ++i, ++mob) {
    mob->x += mob->speed_x;
    mob->y += mob->speed_y;

    smjxxd_game_object_update_boundbox(mob->x, mob->y, mob);
    SPR_setPosition(mob->sprite, mob->box.left, mob->box.top);
  }
}

void smjxxd_world_spawn_monsters() {
  KLog_U1("Monster amount: ", 1010);
  smjxxd_world_spawn(waves[wave]);
}

// ERROR: This one is buggy:
inline void smjxxd_world_spawn(WaveMonsters *wave) {
  for (u8 i = 0; i < MONSTER_TYPE_COUNT; ++i, ++mob_count) {
    KLog_U1("Monster amount: ", wave[i].amount);
    KLog_U1("Monster type: ", wave[i].type);
    smjxxd_mob_init(&monster_list[mob_count], wave[i].type);
  }
}