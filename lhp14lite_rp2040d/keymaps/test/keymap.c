#include QMK_KEYBOARD_H
#include "joystick.h"
#include "analog.h"

#define TST 0
#define RGB 1







void render_logo(void) {
    oled_set_cursor(0, 0);
    oled_write_P(lhp_logo, false);
}

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
}


joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
     JOYSTICK_AXIS_VIRTUAL, // x
     JOYSTICK_AXIS_VIRTUAL  // y
};

void matrix_scan_user(void) {

    // joystick_set_axis(0,170 - analogReadPin(GP28)/3);  // for N-Switch Joycon Repair Kit
    // joystick_set_axis(1,analogReadPin(GP29)/3 - 170);
    joystick_set_axis(0,128 - analogReadPin(GP28)/4);  // for Gulikit Hall Sensing Joystick
    joystick_set_axis(1,analogReadPin(GP29)/4 - 128);

}



void render_layer(void) {
	
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
}

bool oled_task_user(void) {
    render_logo();
    render_layer();
    return false;
}

void suspend_power_down_kb(void) {
    oled_off();
}

void suspend_wakeup_init_kb(void) {
    oled_on();
}





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


