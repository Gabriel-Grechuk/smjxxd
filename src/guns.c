#include "guns.h"

#include "game_object.h"
#include "globals.h"
#include "monsters.h"
#include "resources.h"
#include "utils.h"

u8 bullet_count = 0;
GameObject bullet_list[BULLET_AMOUNT];

inline void smjxxd_gun_spawn_metralha_bullet() {
  GameObject *bullet = &bullet_list[0];
  smjxxd_game_object_init(bullet, &spr_metralha_bullet, 150, 150, -2, -2,
                          PAL_GUNS, sprite_index);

  // TODO: Select the monster to shoot and apply damage.
  bullet->speed_x = smjxxd_utils_get_velocity_to_reach_point(
      bullet->x, monster_list[9].x - monster_list[9].w_offset, FIX16(0.5));
  bullet->speed_y = smjxxd_utils_get_velocity_to_reach_point(
      bullet->y, monster_list[9].y - monster_list[9].h_offset, FIX16(0.5));
  ++bullet_count;

  DEBUG_LOG_NUM("Spawn bullet at address: ", (u32)bullet);
  DEBUG_LOG_NUM("Ref monster: ", (u32)&monster_list[0]);
  DEBUG_LOG_NUM_F("X pos: ", monster_list[0].x);
  DEBUG_LOG_NUM_F("X speed: ", bullet->x);
  DEBUG_LOG_NUM_F("Y speed: ", bullet->y);
}