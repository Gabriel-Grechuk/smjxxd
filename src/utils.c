#include "utils.h"

#include "globals.h"

// Decrease and prevent negative numbers.
inline u16 smjxxd_utils_drain(u16 value, u16 decrease) {
  s16 res = value - decrease;
  if (res < 0)
    return 0;
  return res;
}

inline u16 smjxxd_utils_random_floor_position() {
  // Assume 4 tile for monster sizes.
  return (random() % ((SCREEN_H / 4))) + (SCREEN_H - (SCREEN_H / 4)) - 32;
}

inline f16 smjxxd_utils_random_speed() {
  // NOTE:
  // The FIX16() macro keeps rounding my small numbers, so I just generate a
  // random int number between 0 and 0x0F (or any other mask) and cast it
  // directly as a f16, so it only populates its decimal bits.
  //
  // Also makes some OR operation with the last bits to prevent zeros.
  u16 num = -((random() % 0x0F) | 0x05);
  return (f16)num;
}

inline f16 smjxxd_utils_get_velocity_to_reach_point(f16 pi, f16 pf, f16 t) {
  return (pf - pi) / t;
}

inline bool smjxxd_utils_check_overlap(GameObject *obj1, GameObject *obj2) {
  if (obj1->box.left > obj2->box.right) {
    return true;
  } else
    return false;
}

inline void smjxxd_utils_close_array_gaps(GameObject *arr, u8 n) {
  for (u8 i = 0; i < n; i++)
    if (arr[i].type == NONE) {
      // Fetch next and replace.
      for (u8 j = i; j < n; j++) {
        if (arr[j].type != NONE) {
          arr[i] = arr[j];
          arr[j] = (GameObject){.type = NONE};
          break;
        }
      }
    }
}