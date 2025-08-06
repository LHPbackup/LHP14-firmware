// Copyright 2025 Neo Trinity
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "joystick.h"
#include "analog.h"

// ADC Measured value
#define min_x 139
#define med_x 329
#define max_x 521

#define min_y 139
#define med_y 339
#define max_y 543


#define TST 0
#define RGB 1






enum custom_keycodes {
  RGBRST = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
};


joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(GP28, max_x, med_x, min_x),
    [1] = JOYSTICK_AXIS_IN(GP29, min_y, med_y, max_y),
};



void render_layer(void) {

    oled_set_cursor(0,0);
    oled_write_P(PSTR("X:"), false);
    uint16_t val = analogReadPin(GP28);
    char val_str[4];
    itoa(val, val_str, 10);
    oled_write(val_str, false);
    oled_set_cursor(0,1);
    oled_write_P(PSTR("Y:"), false);
    val = analogReadPin(GP29);
    itoa(val, val_str, 10);
    oled_write(val_str, false);
    
    // special thanks marusii and HellSingCoder


    oled_set_cursor(0, 3);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case TST:
            oled_write_P(PSTR("KEY TEST\n"), false);
            rgblight_sethsv(0, 255, 180);
            break;
        case RGB:
            oled_write_P(PSTR("RGB LED TEST\n"), false);
            //rgblight_sethsv(128, 255, 180);
            break;     
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
};

bool oled_task_user(void) {
    render_layer();
    return false;
};





void suspend_power_down_kb(void) {
    oled_off();
};

void suspend_wakeup_init_kb(void) {
    oled_on();
};





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* TST
   * ,----------------------------------.   
   * |  Q   |  W   |  E   |  R   |  T   |   
   * |------+------+------+------+------|   
   * |  A   |  S   |  D   |  F   |  G   |   
   * |------+------+------+------+------|   
   * |  Z   |  X   |  C   |  V   |  B   |   
   * |------+------+------+------+------+------+------.  
   * |  1   |  2   |  3   |  4   |  5   |JsPush|RGB   |  
   * `------------------------------------------------'  
   */
  [TST] = LAYOUT( \
    KC_Q,   KC_W,   KC_E,   KC_R,    KC_T,  \
    KC_A,   KC_S,   KC_D,   KC_F,    KC_G,  \
    KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,  \
    KC_1,   KC_2,   KC_3,   KC_4,    KC_5,  JS_0,  TO(RGB) \
  ),

  /* RGB
   * ,----------------------------------.   
   * |RGBTOG|RGBHUI|RGBHUD|RGBSAI|RGBSAD|   
   * |------+------+------+------+------|   
   * |RGBMOD|RGBRST|RGBVAI|RGBVAD|      |   
   * |------+------+------+------+------|   
   * |      |      |      |      |      |   
   * |------+------+------+------+------+------+------.  
   * |      |      |      |      |      |JsPush|SAM   |  
   * `------------------------------------------------'  
   */
  [RGB] = LAYOUT( \
    RGB_TOG,   RGB_HUI,   RGB_HUD,    RGB_SAI,    RGB_SAD, \
    RGB_MOD,   RGBRST,    RGB_VAI,    RGB_VAD,    XXXXXXX, \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX, JS_0,  TO(TST) \
  ),

};


