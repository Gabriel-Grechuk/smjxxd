#ifndef _SMJXXD_GUNS_H_
#define _SMJXXD_GUNS_H_

#include "game_object.h"

#define BULLET_AMOUNT 5
#define GUNS_AMOUNT 4

extern u8 bullet_count;
extern GameObject bullet_list[];

extern u8 guns_count;
extern GameObject gun_list[];

void smjxxd_gun_spawn_metralha_bullet();

void smjxxd_gun_spawn_metralha();

void smjxxd_gun_despawn_bullet(GameObject *bullet);

#endif