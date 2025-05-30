#ifndef _SMJXXD_WORLD_H_
#define _SMJXXD_WORLD_H_

#include "game_object.h"

/**
 * The world module controls the game objects interation and states, like mobs
 * positioning, bullets and hits/clips.
 */

#define MONSTER_TYPE_COUNT 6

typedef struct {
  MobType type;
  u8 amount;
} WaveMonsters;

// 7 waves 0 - 6;
static u8 wave = 0;

/**
 * Monsters per level.
 *
 * Hard codded for now. Should be a probabilistic function.
 *
 * NOTE: keep all zombies until the other mobs have sprites.
 */

static WaveMonsters waves[7][MONSTER_TYPE_COUNT] = {
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

/**
 * Updates the world elements.
 */
void smjxxd_world_update();

/**
 * Start the monsters wave.
 */
void smjxxd_world_start_wave();

/**
 * Check the collisions between bullets and monsters;
 */
void smjxxd_world_check_collisions();

#endif