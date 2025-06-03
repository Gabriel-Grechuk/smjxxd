#include "world.h"

#include "globals.h"
#include "guns.h"
#include "monsters.h"
#include "utils.h"

u8 wave = 0;
WaveMonsters waves[7][MONSTER_TYPE_COUNT] = {
    {
        {.type = ZOMBIE, .amount = 10},
        {.type = SKELETON, .amount = 0},
        {.type = MUTANT, .amount = 0},
        {.type = GHOST, .amount = 0},
        {.type = IMP, .amount = 0},
        {.type = BOSS, .amount = 0},
    },
    {
        {.type = ZOMBIE, .amount = 10},
        {.type = SKELETON, .amount = 0},
        {.type = MUTANT, .amount = 0},
        {.type = GHOST, .amount = 0},
        {.type = IMP, .amount = 0},
        {.type = BOSS, .amount = 0},
    },
    {
        {.type = ZOMBIE, .amount = 10},
        {.type = SKELETON, .amount = 0},
        {.type = MUTANT, .amount = 0},
        {.type = GHOST, .amount = 0},
        {.type = IMP, .amount = 0},
        {.type = BOSS, .amount = 0},
    },
    {
        {.type = ZOMBIE, .amount = 10},
        {.type = SKELETON, .amount = 0},
        {.type = MUTANT, .amount = 0},
        {.type = GHOST, .amount = 0},
        {.type = IMP, .amount = 0},
        {.type = BOSS, .amount = 0},
    },
    {
        {.type = ZOMBIE, .amount = 10},
        {.type = SKELETON, .amount = 0},
        {.type = MUTANT, .amount = 0},
        {.type = GHOST, .amount = 0},
        {.type = IMP, .amount = 0},
        {.type = BOSS, .amount = 0},
    },
    {
        {.type = ZOMBIE, .amount = 10},
        {.type = SKELETON, .amount = 0},
        {.type = MUTANT, .amount = 0},
        {.type = GHOST, .amount = 0},
        {.type = IMP, .amount = 0},
        {.type = BOSS, .amount = 0},
    },
    {
        {.type = ZOMBIE, .amount = 10},
        {.type = SKELETON, .amount = 0},
        {.type = MUTANT, .amount = 0},
        {.type = GHOST, .amount = 0},
        {.type = IMP, .amount = 0},
        {.type = BOSS, .amount = 0},
    },
};

extern u8 bullet_count;
extern GameObject bullet_list[];

extern u8 monster_count;
extern GameObject monster_list[];

void smjxxd_world_spawn(WaveMonsters *wave);

/******************************************************************************
 * Module implementations.
 */
inline void smjxxd_world_update() {
  if (!bullet_count && monster_count) {
    smjxxd_gun_spawn_metralha_bullet();
  }

  GameObject *mob = &monster_list[0];
  for (u8 i = 0; i < monster_count; i++, mob++) {
    mob->x += mob->speed_x;
    mob->y += mob->speed_y;

    smjxxd_game_object_update_boundbox(mob->x, mob->y, mob);
    SPR_setPosition(mob->sprite, mob->box.left, mob->box.top);
  }

  GameObject *bullet = &bullet_list[0];
  for (u8 j = 0; j < bullet_count; j++, bullet++) {
    bullet->x += bullet->speed_x;
    bullet->y += bullet->speed_y;

    smjxxd_game_object_update_boundbox(bullet->x, bullet->y, bullet);
    SPR_setPosition(bullet->sprite, bullet->box.left, bullet->box.top);
  }

  smjxxd_world_check_collisions();
}

inline void smjxxd_world_start_wave() { smjxxd_world_spawn(waves[wave]); }

inline void smjxxd_world_check_collisions() {
  GameObject *mob = &monster_list[0];
  for (u8 i = 0; i < monster_count; i++, mob++) {
    // Resets the bullet pointer.
    GameObject *bullet = &bullet_list[0];
    for (u8 j = 0; j < bullet_count; j++, bullet++) {
      if (smjxxd_game_object_out_of_bounds(bullet))
        smjxxd_gun_despawn_bullet(bullet);

      if (smjxxd_utils_check_overlap(bullet, mob)) {
        smjxxd_monster_apply_damage(mob, bullet, 0);
        smjxxd_gun_despawn_bullet(bullet);

        if (mob->health <= 0)
          smjxxd_monster_despawn(mob);
      }
    }
  }
}

/******************************************************************************
 * Local implementations.
 */
inline void smjxxd_world_spawn(WaveMonsters *wave) {
  for (u8 i = 0; i < MONSTER_TYPE_COUNT; i++)
    for (u8 j = 0; j < wave[i].amount; j++, monster_count++) {
      smjxxd_monster_init(&monster_list[monster_count], wave[i].type);
      DEBUG_LOG_NUM("Created monster in address: ",
                    (u32)&monster_list[monster_count]);
      DEBUG_LOG_NUM_F("X pos: ", monster_list[monster_count].x);
      DEBUG_LOG_NUM_F("Y pos: ", monster_list[monster_count].y);
      DEBUG_LOG_NUM_F("X speed: ", monster_list[monster_count].speed_x);
      DEBUG_LOG_NUM_F("Y speed: ", monster_list[monster_count].speed_y);
      DEBUG_LOG_NUM("Top: ", monster_list[monster_count].box.top);
      DEBUG_LOG_NUM("Bottom: ", monster_list[monster_count].box.top);
      DEBUG_LOG_NUM("Left: ", monster_list[monster_count].box.left);
      DEBUG_LOG_NUM("Right: ", monster_list[monster_count].box.right);
    }
}