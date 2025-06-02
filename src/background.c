#include "background.h"
#include "globals.h"

u16 smjxxd_background_init(u16 ind) {
  VDP_setPlaneSize(64, 64, TRUE);
  // No scrolling, just a pain background.
  VDP_drawImageEx(BG_BACKGROUND, &img_background,
                  TILE_ATTR_FULL(PAL_BACKGROUND, 0, 0, 0, ind), 0, 0, TRUE,
                  DMA);
  return img_background.tileset->numTile;
}