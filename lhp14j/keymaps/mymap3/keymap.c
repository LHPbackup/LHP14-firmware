#include QMK_KEYBOARD_H
#include "joystick.h"
#include "analog.h"


// Layer(=job) MAX 32jobs available
#define SCH 0
#define SAM 1






void render_logo(void) {
    oled_set_cursor(0, 0);
    oled_write_P(lhp_logo, false);
}

enum custom_keycodes {
  SE_SH = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
     case SE_SH:
      if (record->event.pressed) {
         register_code(KC_LALT);
           SEND_STRING(SS_DELAY(10) "4" SS_DELAY(10));
           SEND_STRING(SS_DELAY(10) "9" SS_DELAY(10));
         unregister_code(KC_LALT);
      }
      break;
  }
  return true;
}


void render_layer(void) {	
    oled_set_cursor(0, 3);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {

        case SCH:
            oled_write_P(PSTR("SCHOLAR\n"), false);
            rgblight_sethsv(20, 255, 210);
            break;

        case SAM:
            oled_write_P(PSTR("SAMURAI\n"), false);
            rgblight_sethsv(0, 255, 180);
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

  /* SCH
   * ,------------------------------------------------.   
   * |ﾊﾟｸﾄ2 |ﾊﾟｸﾄ3 |   W  |秘策  |疾風怒|      |救出  |   
   * |------+------+------+------+------+------+------|   
   * |   A  |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾙｰｼｯﾄﾞ|  D   |   
   * |------+------+------+------+------+------+------|   
   * |      |ｺﾝact1|ｴｰﾃﾌﾛｰ|堅実魔|連環計|転化  |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |   S  |応急  |      | SAM  |   
   * `----------------------------------+-------------.   
   *                                    |ｾﾗ+ｺﾝｿ|JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [SCH] = LAYOUT( \
    LCA(KC_5), LCA(KC_4), KC_W,       KC_ASTR,    LCA(KC_EQL),XXXXXXX,    LALT(KC_3),\
    KC_A,      XXXXXXX,   KC_SPC,     KC_F,       KC_T,       LALT(KC_4), KC_D,      \
    XXXXXXX,   KC_Z,      LALT(KC_6), LALT(KC_5), LALT(KC_1), LCA(KC_7),  XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_S,       KC_7,                   TO(SAM),   \
                                                              LALT(KC_0), JS_0,      \
                                                                          KC_F12     \
   ),

  /* SAM
   * ,------------------------------------------------.   #
   * |ｺﾝact1|ﾀｹﾞST |  W   |ﾄｩﾙｰN l照破  |無明照|後見る|   
   * |------+------+------+------+------+------+------|   
   * |  A   |心眼  |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |閃影照|  D   |   
   * |------+------+------+------+------+------+------|   
   * |心眼  |葉隠  |意気衝|ｱﾑﾚﾝ  |明鏡  |薬1   |      |   
   * |------+------+------+------+------+-------------'   
   * | GG   |      |ｺﾝact2|  S   |夜天  |      | SCH  |   
   * `----------------------------------+-------------.   
   *                                    |黙想  |心眼  |   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
   [SAM] = LAYOUT( \
    KC_Z,        KC_F2,     KC_W,        LALT(KC_1),LALT(KC_4),   KC_PLUS,    KC_V,      \
    KC_A,        KC_HASH,   KC_SPC,      KC_F,      KC_T,         SE_SH,      KC_D,      \
    KC_HASH,     LALT(KC_5),LALT(KC_2),  KC_AMPR,   KC_ASTR,      LALT(KC_0), XXXXXXX,   \
    LCA(KC_MINS),XXXXXXX,   LCA(KC_EQL), KC_S,      LALT(KC_MINS),            TO(SCH),   \
                                                                  LALT(KC_3), KC_HASH,   \
                                                                              KC_F12  
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



