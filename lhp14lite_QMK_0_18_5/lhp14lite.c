#include "lhp14lite.h"

// initialize OLED if OLED is enabled
#ifdef OLED_ENABLE
  oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
  }
#endif