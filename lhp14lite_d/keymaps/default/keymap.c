// Copyright 2023 Neo Trinity
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "joystick.h"
#include "analog.h"

#define SAM 0
#define SCH 1
#define DRG 2
#define DRK 3
#define WAR 4
#define DNC 5
#define WHM 6
#define RDM 7
#define NIN 8
#define RGB 9






void render_logo(void) {
    oled_set_cursor(0, 0);
    oled_write_P(lhp_logo, false);
}

enum custom_keycodes {
  SR_CS = SAFE_RANGE,
  RR_RD,
  RGBRST
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SR_CS:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("0") "-");
      }
      break;
    case RR_RD:
      if (record->event.pressed) {
		register_code(KC_LCTL);
        SEND_STRING(SS_LALT("2"));
        unregister_code(KC_LCTL);
        SEND_STRING("5");
      }
      break;
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

    joystick_set_axis(0,170 - analogReadPin(F5)/3);
    joystick_set_axis(1,analogReadPin(F4)/3 - 170);

}



void render_layer(void) {
	
    oled_set_cursor(0, 3);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case SAM:
            oled_write_P(PSTR("SAMURAI\n"), false);
            rgblight_sethsv(0, 255, 180);
            break;
        case SCH:
            oled_write_P(PSTR("SCHOLAR\n"), false);
            rgblight_sethsv(20, 255, 210);
            break;
        case DRG:
            oled_write_P(PSTR("DRAGOON\n"), false);
            rgblight_sethsv(170, 255, 180);
            break;
        case DRK:
            oled_write_P(PSTR("DARK KNIGHT\n"), false);
            rgblight_sethsv(0, 255, 90);
            break;
        case WAR:
            oled_write_P(PSTR("WARRIOR\n"), false);
            rgblight_sethsv(85, 255, 90);
            break;            
        case DNC:
            oled_write_P(PSTR("DANCER\n"), false);
            rgblight_sethsv(213, 255, 180);
            break;            
        case WHM:
            oled_write_P(PSTR("WHITE MAGE\n"), false);
            rgblight_sethsv(11, 176, 180);
            break;
        case RDM:
            oled_write_P(PSTR("RED MAGE\n"), false);
            rgblight_sethsv(0, 255, 220);
            break;            
        case NIN:
            oled_write_P(PSTR("NINJA\n"), false);
            rgblight_sethsv(191, 255, 150);
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

  /* SAM
   * ,----------------------------------.   
   * |ｺﾝact1|  W   |ﾄｩﾙｰN l照破  |  D   |   
   * |------+------+------+------+------|   
   * |  A   |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |閃影  |   
   * |------+------+------+------+------|   
   * |葉隠  |意気衝|ｱﾑﾚﾝ  |明鏡  |薬1   |   
   * |------+------+------+------+------+------+------.   
   * |      |ｺﾝact2|  S   |夜天  |黙想  |JsPush|SCH   |   
   * `------------------------------------------------'   
   *
   */
  [SAM] = LAYOUT( \
    KC_Z,       KC_W,         LALT(KC_1), LALT(KC_4), KC_D,       \
    KC_A,       KC_SPC,       KC_F,       KC_T,       LALT(KC_9), \
    LALT(KC_5), LALT(KC_2),   KC_AMPR,    KC_ASTR,    LALT(KC_0), \
    XXXXXXX,    LCA(KC_MINS), KC_S,       LALT(KC_7), LALT(KC_3), JS_0,  TO(SCH) \
  ),






  /* SCH
   * ,----------------------------------.   
   * |ﾊﾟｸﾄ2 |   W  |秘策  |      |救出  |   
   * |------+------+------+------+------|   
   * |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾙｰｼｯﾄﾞ|   
   * |------+------+------+------+------|   
   * |ｺﾝact1|ｴｰﾃﾌﾛｰ|堅実魔|連環計|転化  |   
   * |------+------+------+------+------+------+------.   
   * |DRG   |      |   S  |応急  |ｾﾗ+ｺﾝｿ|JsPush|DRG   |   
   * `------------------------------------------------'   
   */
  [SCH] = LAYOUT( \
    LCA(KC_5), KC_W,       KC_ASTR,    XXXXXXX,    LALT(KC_3),  \
    XXXXXXX,   KC_SPC,     KC_F,       KC_T,       LALT(KC_4),  \
    KC_Z,      LALT(KC_6), LALT(KC_5), LALT(KC_1), LCA(KC_7) ,  \
    XXXXXXX,   XXXXXXX,    KC_S,       KC_7,       SR_CS,       JS_0,  TO(DRG) \
  ),

  /* DRG
   * ,----------------------------------.   
   * |ｺﾝact1|  W   |ﾄｩﾙｰN |ｽﾊﾟｲﾝD|  D   |   
   * |------+------+------+------+------|   
   * |   A  |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ｼﾞｬﾝﾌﾟ|   
   * |------+------+------+------+------|   
   * |      |蒼竜血|ｱﾑﾚﾝ  |Dﾀﾞｲﾌﾞ| 薬1  |   
   * |------+------+------+------+------+------+------.   
   * |      |      |   S  |ｲﾙｰｼﾌﾞ|ﾘﾀﾆｰ  |JsPush|DRK   |   
   * `------------------------------------------------'   
   */
  [DRG] = LAYOUT( \
    KC_Z,     KC_W,       LALT(KC_1), KC_EQUAL,   KC_D,       \
    KC_A,     KC_SPC,     KC_F,       KC_T,       KC_MINUS,   \
    XXXXXXX,  LALT(KC_9), KC_ASTR,    KC_0,       LCA(KC_0),  \
    XXXXXXX,  XXXXXXX,    KC_S,       LALT(KC_7), LALT(KC_6), JS_0,  TO(DRK) \
  ),

  /* DRK
   * ,----------------------------------.   
   * | ｼｬｰｸ |      |ﾘﾌﾟﾗｲ |ｱﾋﾞｻﾙ |ﾘﾋﾞﾃﾞ |   
   * |------+------+------+------+------|   
   * |ｺﾝact1|Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾌﾞﾗﾃﾞﾘ|   
   * |------+------+------+------+------|   
   * |      |ﾌﾞﾗﾅｲ |ｱﾑﾚﾝ  |ﾌﾞﾗｳｪ |      |   
   * |------+------+------+------+------+------+------.  
   * |      |      |      |ｽﾀﾝｽ  |      |JsPush|WAR   |  
   * `------------------------------------------------'  
   */
  [DRK] = LAYOUT( \
    LCA(KC_EQL), XXXXXXX,      KC_LPRN,    LALT(KC_1), LCA(KC_3),  \
    KC_Z,        KC_SPC,       KC_F,       KC_T,       LALT(KC_2), \
    XXXXXXX,     LALT(KC_EQL), LALT(KC_6), LALT(KC_3), XXXXXXX,    \
    XXXXXXX,     XXXXXXX,      XXXXXXX,    LALT(KC_4), XXXXXXX,    JS_0,  TO(WAR) \
  ),

  /* WAR
   * ,----------------------------------.   
   * | ｼｬｰｸ |ｼｪｲｸｵﾌ|ﾘﾌﾟﾗｲ |      | ﾎﾙﾑ  |   
   * |------+------+------+------+------|   
   * |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾌｪﾙｸﾘ |   
   * |------+------+------+------+------|   
   * |      |ｳｫｰｸﾗｲ|ｱﾑﾚﾝ  |原初開|      |   
   * |------+------+------+------+------+------+------.  
   * |      |      |      |ｽﾀﾝｽ  |      |JsPush|DNC   |  
   * `------------------------------------------------'  
   */
  [WAR] = LAYOUT( \
    LCA(KC_EQL), KC_PLUS,      KC_LPRN,    XXXXXXX,    LCA(KC_3),  \
    XXXXXXX,     KC_SPC,       KC_F,       KC_T,       LALT(KC_3), \
    XXXXXXX,     LALT(KC_UNDS),LALT(KC_9), LALT(KC_5), XXXXXXX,    \
    XXXXXXX,     XXXXXXX,      XXXXXXX,    LALT(KC_1), XXXXXXX,    JS_0,  TO(DNC) \
  ),

  /* DNC
   * ,----------------------------------.   
   * |      |      |ｱﾝｱﾊﾞﾝ|      |ﾀｹﾞMT |   
   * |------+------+------+------+------|   
   * |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾌﾗﾘｯｼｭ|   
   * |------+------+------+------+------|   
   * |ｺﾝact1|守ｻﾝﾊﾞ|ｱﾑﾚﾝ  |攻ﾀﾝｺﾞ|      |   
   * |------+------+------+------+------+------+------.  
   * |      |      |      |癒ﾜﾙﾂ |ｲﾝﾌﾟﾛﾋ|JsPush|WHM   |  
   * `------------------------------------------------'  
   */
  [DNC] = LAYOUT( \
    XXXXXXX,  XXXXXXX,   KC_EQUAL,   XXXXXXX,   KC_F1,    \
    XXXXXXX,  KC_SPC,    KC_F,       KC_T,      KC_8,     \
    KC_Z,     KC_LPRN,   LALT(KC_5), KC_AMPR,   XXXXXXX,  \
    XXXXXXX,  XXXXXXX,   XXXXXXX,    KC_ASTR,   KC_MINUS, JS_0,  TO(WHM) \
  ),

  /* WHM
   * ,----------------------------------.   
   * |ｺﾝact1|   W  |ﾍﾞﾆｿﾝT|ﾃﾝﾊﾟ  |救出  |   
   * |------+------+------+------+------|   
   * |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾙｰｼｯﾄﾞ|   
   * |------+------+------+------+------|   
   * |      |ｼﾝｴｱｰ |堅実魔|神速魔|      |   
   * |------+------+------+------+------+------+------.  
   * |      |      |      |ｲﾝﾄﾞｩﾙ|      |JsPush|RDM   |  
   * `------------------------------------------------'  
   */
  [WHM] = LAYOUT( \
    KC_Z,       KC_W,       LALT(KC_EQUAL),LALT(KC_5),    LALT(KC_4), \
    XXXXXXX,    KC_SPC,     KC_F,          KC_T,          LALT(KC_8), \
    XXXXXXX,    LALT(KC_0), LALT(KC_6),    LALT(KC_MINUS),XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,       LALT(KC_7),    XXXXXXX,    JS_0,  TO(RDM) \
  ),

  /* RDM
   * ,----------------------------------.   
   * |ｺﾝact1|      |ｱｸｾﾗ  |      |ﾀｹﾞMT |   
   * |------+------+------+------+------|   
   * |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾙｰｼｯﾄﾞ|   
   * |------+------+------+------+------|   
   * |      |ﾏﾅﾌｨｹ |堅実魔|ｴﾝﾎﾞﾙ |ｱﾄﾞﾙ  |   
   * |------+------+------+------+------+------+------.  
   * |      |      |      |      |ｺﾝact1|JsPush|NIN   |  
   * `------------------------------------------------'  
   */
  [RDM] = LAYOUT( \
    KC_Z,        XXXXXXX,    LALT(KC_4), XXXXXXX,    KC_F1,      \
    XXXXXXX,     KC_SPC,     KC_F,       KC_T,       LALT(KC_3), \
    XXXXXXX,     LALT(KC_9), KC_ASTR,    LALT(KC_5), LALT(KC_2), \
    XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_Z,       JS_0,  TO(NIN) \
  ),

  /* NIN
   * ,----------------------------------.   
   * |      |  W   |ﾄｩﾙｰN |      |ﾀｹﾞMT |   
   * |------+------+------+------+------|   
   * |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |天地人|   
   * |------+------+------+------+------|   
   * |かくれ|だまし|ｱﾑﾚﾝ  |活殺  |      |   
   * |------+------+------+------+------+------+------.  
   * |      |      |      |命水  |      |JsPush|RGB   |  
   * `------------------------------------------------'  
   */
  [NIN] = LAYOUT( \
    XXXXXXX,   KC_W,       LALT(KC_3), XXXXXXX,    KC_F1,      \
    XXXXXXX,   KC_SPC,     KC_F,       KC_T,       LALT(KC_2), \
    LALT(KC_0),LALT(KC_7), LALT(KC_4), LALT(KC_1), XXXXXXX,    \
    XXXXXXX,   XXXXXXX,    XXXXXXX,    KC_9,       XXXXXXX,    JS_0,  TO(RGB) \
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
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX, JS_0,  TO(SAM) \
  ),

};



