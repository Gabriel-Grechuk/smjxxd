#include "world.h"

#include "globals.h"
#include "guns.h"
#include "monsters.h"
#include "utils.h"

extern u8 bullet_count;
extern GameObject bullet_list[];

extern u8 monster_count;
extern GameObject monster_list[];

void smjxxd_world_spawn(WaveMonsters *wave);

/******************************************************************************
 * Module implementations.
 */
inline void smjxxd_world_update() {
  GameObject *mob = &monster_list[0];
  for (u8 i = 0; i < monster_count; i++, mob++) {
    mob->x += mob->speed_x;
    mob->y += mob->speed_y;

    DEBUG_LOG("=================================");
    DEBUG_LOG_NUM("Updating Monster: ", (u32)mob);
    DEBUG_LOG_NUM_F("X vel:", mob->speed_x);
    DEBUG_LOG_NUM_F("Y vel:", mob->speed_y);

    DEBUG_LOG_NUM_F("X pos:", mob->x);
    DEBUG_LOG_NUM_F("Y pos:", mob->y);

    smjxxd_game_object_update_boundbox(mob->x, mob->y, mob);
    SPR_setPosition(mob->sprite, mob->box.left, mob->box.top);
  }

  GameObject *bullet = &bullet_list[0];
  for (u8 j = 0; j < bullet_count; j++, bullet++) {
    bullet->x += bullet->speed_x;
    bullet->y += bullet->speed_y;

    DEBUG_LOG("=================================");
    DEBUG_LOG_NUM("Updating bullet: ", (u32)bullet);
    DEBUG_LOG_NUM_F("X vel:", bullet->speed_x);
    DEBUG_LOG_NUM_F("Y vel:", bullet->speed_y);

    DEBUG_LOG_NUM_F("X pos:", bullet->x);
    DEBUG_LOG_NUM_F("Y pos:", bullet->y);

    smjxxd_game_object_update_boundbox(bullet->x, bullet->y, bullet);
    SPR_setPosition(bullet->sprite, bullet->box.left, bullet->box.top);
  }
}

inline void smjxxd_world_start_wave() { smjxxd_world_spawn(waves[wave]); }

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