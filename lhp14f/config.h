/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
//#define VENDOR_ID      0xFF14
//#define PRODUCT_ID     0x0009
//#define DEVICE_VER     0x0001
//#define MANUFACTURER   NeoTrinity
//#define PRODUCT        LHP14f


#define MATRIX_ROWS 4
#define MATRIX_COLS 9


#define MATRIX_ROW_PINS { D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6, C6, D2 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

//#define LOCKING_SUPPORT_ENABLE
//#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN D3
#define RGBLED_NUM 28 // Number of LEDs. Tape LED >>> RGBLED_NUM 6   no LED >>> RGBLED_NUM 0

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

 #ifdef RGB_DI_PIN
   #define RGBLIGHT_HUE_STEP 8
   #define RGBLIGHT_SAT_STEP 8
   #define RGBLIGHT_VAL_STEP 8
   #define RGBLIGHT_LIMIT_VAL 120 /* The maximum brightness level */
   #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
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

#define OLED_TIMEOUT 0

#define OLED_FONT_H "keyboards/lhp14f/glcdfont_lhp14.c"

#define LAYER_STATE_32BIT
