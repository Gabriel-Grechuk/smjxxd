#include "game_object.h"
#include "globals.h"

u16 smjxxd_game_object_init(GameObject *const obj,
                            const SpriteDefinition *const sprite, s16 x, s16 y,
                            s8 w_offset, s8 h_offset, u8 pal, u16 ind) {
  obj->x = FIX16(x);
  obj->y = FIX16(y);
  obj->next_x = obj->x;
  obj->next_y = obj->y;
  obj->speed_x = 0;
  obj->speed_y = 0;
  obj->anim = 0;
  PAL_setPalette(pal, sprite->palette->data, DMA);

  obj->sprite =
      SPR_addSprite(sprite, x, y, TILE_ATTR_FULL(pal, FALSE, FALSE, 0, ind));

  obj->w = obj->sprite->definition->w + w_offset;
  obj->h = obj->sprite->definition->h + h_offset;
  obj->w_offset = w_offset / 2; // half offset for each side
  obj->h_offset = h_offset / 2;

  return obj->sprite->definition->maxNumTile;
}

void smjxxd_game_object_update_boundbox(f16 x, f16 y, GameObject *obj) {
  obj->box.left = fix16ToInt(x);
  obj->box.top = fix16ToInt(y);
  obj->box.right = fix16ToInt(x) + obj->w;  // - 1;
  obj->box.bottom = fix16ToInt(y) + obj->h; // - 1;
}

void smjxxd_game_object_clamp_screen(GameObject *obj) {
  obj->x = clamp(obj->x, 0, FIX16(SCREEN_W - obj->w));
  obj->y = clamp(obj->y, 0, FIX16(SCREEN_H - obj->h));
}

inline bool smjxxd_game_object_out_of_bounds(GameObject *obj) {
  if (obj->box.left > SCREEN_W || obj->box.top > SCREEN_H ||
      obj->box.bottom < 0 || obj->box.right < 0)
    return true;

  else
    return false;
}