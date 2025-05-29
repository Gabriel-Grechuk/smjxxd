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

f16 smjxxd_utils_random_speed() {
  // NOTE:
  // The FIX16() macro keeps rounding my small numbers, so I just generate a
  // random int number between 0 and 0x0F (or any other mask) and cast it
  // directly as a f16, so it only populates its decimal bits.
  //
  // Also makes some OR operation with the last bits to prevent zeros.
  u16 num = -((random() % 0x0F) | 0x05);
  return (f16)num;
}