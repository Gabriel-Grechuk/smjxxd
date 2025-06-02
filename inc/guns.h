#ifndef _SMJXXD_GUNS_H_
#define _SMJXXD_GUNS_H_

#include "game_object.h"

#define BULLET_AMOUNT 5

extern u8 bullet_count;
extern GameObject bullet_list[];

void smjxxd_gun_spawn_metralha_bullet();

#endif