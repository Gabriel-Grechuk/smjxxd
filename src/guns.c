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
  smjxxd_game_object_init(bullet, &spr_metralha_bullet, 150, 150, 0, 0,
                          PAL_GUNS, sprite_index);

  // TODO: Select the monster to shoot and apply damage.
  bullet->speed_x = smjxxd_utils_get_velocity_to_reach_point(
      bullet->x, monster_list[9].x - monster_list[9].w_offset, FIX16(2));
  bullet->speed_y = smjxxd_utils_get_velocity_to_reach_point(
      bullet->y, monster_list[9].y - monster_list[9].h_offset, FIX16(2));

  bullet->damage = 25;

  smjxxd_game_object_update_boundbox(bullet->x, bullet->y, bullet);

  ++bullet_count;

  DEBUG_LOG("===================================");
  DEBUG_LOG_NUM("Spawn bullet at address: ", (u32)bullet);
  DEBUG_LOG_NUM_F("X pos: ", bullet->x);
  DEBUG_LOG_NUM_F("Y pos: ", bullet->y);
  DEBUG_LOG_NUM_F("X speed: ", bullet->speed_x);
  DEBUG_LOG_NUM_F("Y speed: ", bullet->speed_y);
  DEBUG_LOG_NUM("Top: ", bullet->box.top);
  DEBUG_LOG_NUM("Bottom: ", bullet->box.bottom);
  DEBUG_LOG_NUM("Left: ", bullet->box.left);
  DEBUG_LOG_NUM("Right: ", bullet->box.right);
  DEBUG_LOG_NUM("Damage: ", bullet->damage);
}

void smjxxd_gun_despawn_bullet(GameObject *bullet) {
  SPR_releaseSprite(bullet->sprite);
  *bullet = (GameObject){0};
  // TODO: Here should be a array reordering to close eventual gaps in the
  // bullet list array.
  --bullet_count;
}