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
	
	oled_set_cursor(START_COL, START_ROW);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case TST:
            oled_write_P(PSTR("KEY TEST\n"), false);
            break;
        case RGB:
            oled_write_P(PSTR("RGB LED TEST\n"), false);
            break;     
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void oled_task_user(void) {
    render_logo();
    render_layer();
}

void suspend_power_down_user(void) {
    oled_off();
}





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  /* TST
   * ,------------------------------------------------.   
   * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   
   * |------+------+------+------+------+------+------|   
   * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   
   * |------+------+------+------+------+------+------|   
   * |   1  |   Z  |   X  |  C   |   V  |   B  |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | RGB  |   2  |   3  |  4   |   5  |                 
   * `----------------------------------+------.          
   *                                    |   6  |          
   *                                    `------+------.   
   *                                           |   7  |   
   *                                           `------'   
   */

 [TST] = LAYOUT( \
    KC_Q,     KC_W,     KC_E,       KC_R,     KC_T,      KC_Y,    KC_U,      \
    KC_A,     KC_S,     KC_D,       KC_F,     KC_G,      KC_H,    KC_J,      \
    KC_1,     KC_Z,     KC_X,       KC_C,     KC_V,      KC_B,    JS_BUTTON7,\
    TO(RGB),  KC_2,     KC_3,       KC_4,     KC_5,                          \
                                                         KC_6,               \
                                                                  KC_7       \
  ),






  /* RGB
   * ,------------------------------------------------.   
   * |RGBTOG|RGBHUI|RGBHUD|RGBSAI|RGBSAD|RGBVAI|RGBVAD|   
   * |------+------+------+------+------+------+------|   
   * |RGBMOD|RGBRST|      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | TST  |      |      |      |      |                 
   * `----------------------------------+------.          
   *                                    |      |          
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
  [RGB] = LAYOUT( \
    RGB_TOG,   RGB_HUI,   RGB_HUD,    RGB_SAI,    RGB_SAD,    RGB_VAI,    RGB_VAD,       \
    RGB_MOD,   RGBRST,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    JS_BUTTON7,    \
    TO(TST),   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,                               \
                                                              XXXXXXX,                   \
                                                                          XXXXXXX        \
  ),

};

void joystick_task(){

    joystick_status.axes[0] = analogReadPin(F4)/4 - 128;
    joystick_status.axes[1] = analogReadPin(D4)/4 - 128;
    send_joystick_packet(&joystick_status);
}
