#include QMK_KEYBOARD_H
#include "joystick.h"
#include "analog.h"

#define RGB 0
#define PAR 1







void render_logo(void) {
    oled_set_cursor(0, 0);
    oled_write_P(lhp_logo, false);
}

enum custom_keycodes {
  RGBRST = SAFE_RANGE,
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


void render_layer(void) {
    oled_set_cursor(0, 3);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case RGB:
            oled_write_P(PSTR("RGB&KEY TEST\n"), false);
            break;
            
        case PAR:
            oled_write_P(PSTR("LED PARAMETER\n"), false);
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


  /* RGB
   * ,------------------------------------------------.   
   * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   
   * |------+------+------+------+------+------+------|   
   * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   
   * |------+------+------+------+------+------+------|   
   * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   
   * |------+------+------+------+------+-------------'   
   * |   2  |   3  |   4  |   5  |   6  |      | PAR  |   
   * `----------------------------------+-------------.   
   *                                    |   7  |JSPush|   
   *                                    `------+------.   
   *                                           |   8  |   
   *                                           `------'   
   */

 [RGB] = LAYOUT( \
    KC_Q,     KC_W,     KC_E,       KC_R,     KC_T,      KC_Y,    KC_U,      \
    KC_A,     KC_S,     KC_D,       KC_F,     KC_G,      KC_H,    KC_J,      \
    KC_Z,     KC_X,     KC_C,       KC_V,     KC_B,      KC_N,    KC_M,      \
    KC_2,     KC_3,     KC_4,       KC_5,     KC_6,               TO(PAR),   \
                                                         KC_7,    JS_0,      \
                                                                  KC_8       \
  ),


  /* PAR
   * ,------------------------------------------------.   
   * |RGBTOG|RGBHUI|RGBHUD|RGBSAI|RGBSAD|RGBVAI|RGBVAD|   
   * |------+------+------+------+------+------+------|   
   * |RGBMOD|RGBRST|      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | RGB  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
  [PAR] = LAYOUT( \
    RGB_TOG,   RGB_HUI,   RGB_HUD,    RGB_SAI,    RGB_SAD,    RGB_VAI,    RGB_VAD,       \
    RGB_MOD,   RGBRST,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,                TO(RGB),       \
                                                              XXXXXXX,    JS_0,          \
                                                                          XXXXXXX        \
  ),

};





joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
     JOYSTICK_AXIS_VIRTUAL, // x
     JOYSTICK_AXIS_VIRTUAL  // y
};

void matrix_scan_user(void) {

    joystick_set_axis(0,analogReadPin(F4)/4 - 128);
    joystick_set_axis(1,analogReadPin(F5)/4 - 128);  // if you use LHP14F or previous version, analogReadPin(D4)

}



