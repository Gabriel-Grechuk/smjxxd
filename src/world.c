#include "world.h"
#include "monsters.h"
#include "utils.h"

void smjxxd_world_spawn(WaveMonsters *wave);

/******************************************************************************
 * Module implementations.
 */
inline void smjxxd_world_update() {
  GameObject *mob = &monster_list[0];
  for (u8 i = 0; i < monster_count; ++i, ++mob) {
    mob->x += mob->speed_x;
    mob->y += mob->speed_y;

    smjxxd_game_object_update_boundbox(mob->x, mob->y, mob);
    SPR_setPosition(mob->sprite, mob->box.left, mob->box.top);
  }
}

inline void smjxxd_world_start_wave() {
  smjxxd_world_spawn(waves[wave]);
  DEBUG_LOG_NUM("Mob count: ", monster_count);
}

inline void smjxxd_world_check_collisions() {
  // TODO: Implement.
}

/******************************************************************************
 * Local implementations.
 */
inline void smjxxd_world_spawn(WaveMonsters *wave) {
  for (u8 i = 0; i < MONSTER_TYPE_COUNT; i++)
    for (u8 j = 0; j < wave[i].amount; j++, monster_count++) {
      smjxxd_monster_init(&monster_list[monster_count], wave[i].type);
      DEBUG_LOG_NUM("Created monster in address: ",
                    (u32)&monster_list[monster_count]);
    }
}