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
    KLog_U1("Updating monster ", (u32)mob);
    mob->x += mob->speed_x;
    mob->y += mob->speed_y;

    smjxxd_game_object_update_boundbox(mob->x, mob->y, mob);
    SPR_setPosition(mob->sprite, mob->box.left, mob->box.top);
  }
}

void smjxxd_world_spawn_monsters() { smjxxd_world_spawn(waves[wave]); }

// ERROR: This one is buggy:
inline void smjxxd_world_spawn(WaveMonsters *wave) {

  KLog_U1("Spawn wave: ", wave[1].amount);
  for (u8 amount = 0; amount < wave[1].amount; amount++, mob_count++){
    smjxxd_mob_init(&monster_list[amount], wave[1].type);
  }
}