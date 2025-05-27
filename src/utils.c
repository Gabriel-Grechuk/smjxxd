#include "utils.h"

#include "globals.h"

// Decrease and prevent negative numbers.
u16 smjxxd_utils_drain(u16 value, u16 decrease) {
  s16 res = value - decrease;
  if (res < 0)
    return 0;
  return res;
}

u16 smjxxd_utils_random_floor_position() {
  // Assume 4 tile for monster sizes.
  return (random() % ((SCREEN_H / 4))) + (SCREEN_H - (SCREEN_H / 4)) - 32;
}