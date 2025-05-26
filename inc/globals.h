#ifndef _SMJXXD_GLOBALS_H_
#define _SMJXXD_GLOBALS_H_

#include <genesis.h>

// #define DEBUG

// GENERAL SCREEN CONFIG
#define SCREEN_W 320
#define SCREEN_H 224

#define SCREEN_W_F16 FIX16(SCREEN_W)
#define SCREEN_H_F16 FIX16(SCREEN_H)

#define SCREEN_TILES_W SCREEN_W / 8
#define SCREEN_TILES_H SCREEN_H / 8


// GENERAL VDP CONFIG ///////////////////////////////////

#define PAL_MOBS PAL0
#define PAL_BACKGROUND PAL3

#define BG_BACKGROUND BG_B

#define NUMBER_OF_JOYPADS 2

#endif