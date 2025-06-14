#include <genesis.h>
#include <sprite_eng.h>

#include "guns.h"
#include "monsters.h"

#include "background.h"
#include "game_object.h"
#include "globals.h"
#include "utils.h"
#include "world.h"

u16 sprite_index = TILE_USER_INDEX;

void game_init() {
  VDP_setScreenWidth320();
  SPR_init();

  sprite_index += smjxxd_background_init(sprite_index);
  smjxxd_gun_spawn_metralha();
  smjxxd_world_start_wave();
}

int main(bool resetType) {
  // Soft reset doesn't clear RAM. Can lead to bugs.
  if (!resetType) {
    SYS_hardReset();
  }
  SYS_showFrameLoad(true);
  game_init();

  SYS_doVBlankProcess();

  while (true) {
    smjxxd_world_update();
    SPR_update();
    SYS_doVBlankProcess();
  }

  return 0;
}
