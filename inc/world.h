#ifndef _SMJXXD_WORLD_H_
#define _SMJXXD_WORLD_H_

#include "game_object.h"

/**
 * The world module controls the game objects interation and states, like mobs
 * positioning, bullets and hits/clips.
 */

#define MAX_MOBS 79
#define MAX_MONSTERS 20

static u16 mob_count = 0; 
GameObject mobs_list[MAX_MOBS];

/**
 *  Updates  the world elements.
 */
void smjxxd_world_update();

#endif