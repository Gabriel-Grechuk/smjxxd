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
  // TODO: Implement.
}

void smjxxd_world_spawn_monsters() { smjxxd_world_spawn(waves[wave]); }

inline void smjxxd_world_spawn(WaveMonsters *wave) {
  u8 monster_list_seek = 0;
  for (u8 i = 0; i < MONSTERS_AMOUNT; i++)
    for (u8 amount = 0; amount < wave[i].amount; amount++) {
      smjxxd_mob_init(&monster_list[monster_list_seek], wave[i].type);
    }
}