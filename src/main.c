#include <genesis.h>
#include <sprite_eng.h>

#include "globals.h"

#include "background.h"
#include "game_object.h"
#include "utils.h"
#include "world.h"

void game_init() {
  VDP_setScreenWidth320();
  SPR_init();

  sprite_index += smjxxd_background_init(sprite_index);
  smjxxd_world_spawn_monsters();
}

static inline void game_update() {
  // TODO: implement.
}

int main(bool resetType) {
  // Soft reset doesn't clear RAM. Can lead to bugs.
  if (!resetType) {
    SYS_hardReset();
  }
  SYS_showFrameLoad(true);
  game_init();

  SYS_doVBlankProcess();

  kprintf("Free RAM after Game Init: %d", MEM_getFree());

  while (true) {
    game_update();

    SPR_update();
    SYS_doVBlankProcess();
  }

  return 0;
}
