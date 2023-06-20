// Copyright 2023 Neo Trinity
// SPDX-License-Identifier: GPL-2.0-or-later

#include "lhp14lite_rp2040d.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_180;
}
