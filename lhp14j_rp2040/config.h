// Copyright 2022 Neo Trinity
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RGBLED_NUM 28 // Number of LEDs. Tape LED >>> RGBLED_NUM 6   onboard LED >>> RGBLED_NUM 1

#if  RGBLED_NUM == 28
  #define LED_LAYOUT( \
    L00, L01, L02, L03, L04, L05, L06, \
    L07, L08, L09, L10, L11, L12, L13, \
    L14, L15, L16, L17, L18, L19, L20, \
    L21, L22, L23, L24, L25, L26, L27) \
   { \
    L00, L01, L02, L03, L04, L05, L06, \
    L07, L08, L09, L10, L11, L12, L13, \
    L14, L15, L16, L17, L18, L19, L20, \
    L21, L22, L23, L24, L25, L26, L27  \
   }

  #define RGBLIGHT_LED_MAP LED_LAYOUT( \
    6,  5,  4,   3,  2,  1,  0,   \
    7,  8,  9,  10, 11, 12, 13,   \
    20, 19, 18, 17, 16, 15, 14,   \
    21, 22, 23, 24, 25, 26, 27)    
#endif

#define JOYSTICK_BUTTON_COUNT 1
#define JOYSTICK_AXIS_COUNT 2
#define JOYSTICK_AXIS_RESOLUTION 8

#define OLED_TIMEOUT 0

#define OLED_FONT_H "keyboards/lhp14j_rp2040/glcdfont_lhp14.c"

#define LAYER_STATE_32BIT


#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET 
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U 
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U 

#define OLED_DISPLAY_128X32
#define I2C1_SCL_PIN GP3
#define I2C1_SDA_PIN GP2
#define I2C_DRIVER I2CD1
#define OLED_BRIGHTNESS 128

