#ifndef _SMJXXD_GUNS_H_
#define _SMJXXD_GUNS_H_

#include <genesis.h>

#include "game_object.h"

#define BULLET_AMOUNT 5

static u8 bullet_count = 0;
static GameObject bullet_list[BULLET_AMOUNT];

void smjxxd_gun_spawn_metralha_bullet();

#endif