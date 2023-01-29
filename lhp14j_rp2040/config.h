// Copyright 2022 Neo Trinity
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#define MATRIX_ROWS 4
#define MATRIX_COLS 9


#define MATRIX_ROW_PINS { GP6, GP7, GP8, GP9 }
#define MATRIX_COL_PINS { GP4, GP27, GP26, GP22, GP20, GP23, GP21, GP5, GP1 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

//#define LOCKING_SUPPORT_ENABLE
//#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN GP0 // GP25>>>ProMicroRP2040 onboard LED (RGBLED_NUM 1)
#define RGBLED_NUM 28 // Number of LEDs. Tape LED >>> RGBLED_NUM 6   no LED >>> RGBLED_NUM 0

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

 #ifdef RGB_DI_PIN
   #define RGBLIGHT_HUE_STEP 8
   #define RGBLIGHT_SAT_STEP 8
   #define RGBLIGHT_VAL_STEP 8
   #define RGBLIGHT_LIMIT_VAL 120 
   #define RGBLIGHT_SLEEP  
 /*== all animations enable ==*/
//   #define RGBLIGHT_ANIMATIONS
 /*== or choose animations ==*/
   //#define RGBLIGHT_EFFECT_BREATHING
   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
   #define RGBLIGHT_EFFECT_SNAKE
   #define RGBLIGHT_EFFECT_KNIGHT
   //#define RGBLIGHT_EFFECT_CHRISTMAS
   //#define RGBLIGHT_EFFECT_STATIC_GRADIENT
   #define RGBLIGHT_EFFECT_RGB_TEST
   //#define RGBLIGHT_EFFECT_ALTERNATING
   //#define RGBLIGHT_EFFECT_TWINKLE
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
#define I2C_DRIVER I2CD2
#define OLED_BRIGHTNESS 128

