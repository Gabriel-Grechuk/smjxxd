#ifndef _SMJXXD_GAME_OBJECT_H_
#define _SMJXXD_GAME_OBJECT_H_

#include <genesis.h>

typedef struct
{
  s16 left;
  s16 right;
  s16 top;
  s16 bottom;
} BoundBox;

typedef struct
{
  Sprite *sprite;
  f16 x;
  f16 y;
  f16 next_x;
  f16 next_y;
  f16 speed_x;
  f16 speed_y;
  u8 w;
  u8 h;
  BoundBox box;
  s8 w_offset;
  s8 h_offset;
  u8 anim;
  u8 health;
} GameObject;

/**
 * Create and initialize the structure.
 */
u16 smjxxd_game_object_init(GameObject *const obj, const SpriteDefinition *const sprite, s16 x, s16 y, s8 w_offset, s8 h_offset, u8 pal, u16 ind);

/**
 * Updates GameObject's bound box (integer values) from positions and size (fix16).
 */
void smjxxd_game_object_update_boundbox(f16 x, f16 y, GameObject *obj);

/**
 *	Prevents object from going outside screen by repositioning it at screen bounds.
 */
void smjxxd_game_object_clamp_screen(GameObject *obj);

#endif