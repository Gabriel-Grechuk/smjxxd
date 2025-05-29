#include "world.h"
#include "mob.h"
#include "utils.h"

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
  smjxxd_world_spawn(waves[wave]);
  DEBUG_LOG_NUM("Mob count: ", mob_count);
}

// ERROR: This one is buggy:
inline void smjxxd_world_spawn(WaveMonsters *wave) {
  for (u8 i = 0; i < MONSTER_TYPE_COUNT; i++)
    for (u8 j = 0; j < wave[i].amount; j++, mob_count++) {
      smjxxd_mob_init(&monster_list[mob_count], wave[i].type);
      DEBUG_LOG_NUM("Created monster in address: ",
                    (u32)&monster_list[mob_count]);
    }
}