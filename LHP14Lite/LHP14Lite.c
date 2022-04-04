#include "LHP14Lite.h"

// initialize OLED if OLED is enabled
#ifdef OLED_DRIVER_ENABLE
  oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
  }
#endif