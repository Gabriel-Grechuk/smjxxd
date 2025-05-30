#include "guns.h"

#include "game_object.h"
#include "globals.h"
#include "monsters.h"
#include "resources.h"
#include "utils.h"

void smjxxd_gun_spawn_metralha_bullet() {
  GameObject *bullet = &bullet_list[bullet_count];
  smjxxd_game_object_init(bullet, &spr_metralha_bullet, 150, 150, -2, -2,
                          PAL_GUNS, sprite_index);
  bullet_count++;
  bullet->speed_x =
      smjxxd_utils_get_velocity_to_reach_point(bullet->x, monster_list[0].x, 2);
  bullet->speed_y =
      smjxxd_utils_get_velocity_to_reach_point(bullet->y, monster_list[0].y, 2);
}