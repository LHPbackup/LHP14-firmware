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


void render_layer(void) {

    oled_set_cursor(START_COL, START_ROW);
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

  /* SAM
   * ,------------------------------------------------.   
   * |ｺﾝact1|ﾀｹﾞST |  W   |ﾄｩﾙｰN l照破  |ﾀｹﾞMT |後見る|   
   * |------+------+------+------+------+------+------|   
   * |  A   |心眼  |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |閃影  |  D   |   
   * |------+------+------+------+------+------+------|   
   * |      |葉隠  |意気衝|ｱﾑﾚﾝ  |明鏡  |薬1   |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | SCH  |      |ｺﾝact2|  S   |夜天  |                 
   * `----------------------------------+------.          
   *                                    |黙想  |          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
   [SAM] = LAYOUT( \
    KC_Z,      KC_F3,     KC_W,        LALT(KC_1),LALT(KC_4),KC_F1,      KC_V,      \
    KC_A,      KC_HASH,   KC_SPC,      KC_F,      KC_T,      LALT(KC_9), KC_D,      \
    XXXXXXX,   LALT(KC_5),LALT(KC_2),  KC_AMPR,   KC_ASTR,   LALT(KC_0), JS_BUTTON7,\
    TO(SCH),   XXXXXXX,   LCA(KC_MINS),KC_S,      LALT(KC_7),                       \
                                                             LALT(KC_3),            \
                                                                         KC_F12     \
  ),

 /*[SAM] = LAYOUT( \
    KC_Q,     KC_W,     KC_E,       KC_R,     KC_T,      KC_Y,    KC_U,      \
    KC_A,     KC_S,     KC_D,       KC_F,     KC_G,      KC_H,    KC_J,      \
    KC_1,     KC_Z,     KC_X,       KC_C,     KC_V,      KC_B,    JS_BUTTON0,\
    TO(SCH),  KC_3,     KC_5,       KC_6,     KC_7,                          \
                                                         KC_8,               \
                                                                  KC_9       \
  ),*/




  /* SCH
   * ,------------------------------------------------.   
   * |ﾊﾟｸﾄ2 |ﾊﾟｸﾄ3 |   W  |秘策  |      |      |救出  |   
   * |------+------+------+------+------+------+------|   
   * |   A  |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾙｰｼｯﾄﾞ|  D   |   
   * |------+------+------+------+------+------+------|   
   * |      |ｺﾝact1|ｴｰﾃﾌﾛｰ|堅実魔|連環計|転化  |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | DRG  |      |      |   S  |応急  |                 
   * `----------------------------------+------.          
   *                                    |ｾﾗ+ｺﾝｿ|          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [SCH] = LAYOUT( \
    LCA(KC_5), LCA(KC_4), KC_W,       KC_ASTR,    XXXXXXX,    XXXXXXX,    LALT(KC_3),\
    KC_A,      XXXXXXX,   KC_SPC,     KC_F,       KC_T,       LALT(KC_4), KC_D,      \
    XXXXXXX,   KC_Z,      LALT(KC_6), LALT(KC_5), LALT(KC_1), LCA(KC_7),  JS_BUTTON7,\
    TO(DRG),   XXXXXXX,   XXXXXXX,    KC_S,       KC_7,                              \
                                                              SR_CS,                 \
                                                                          KC_F12     \
  ),

  /* DRG
   * ,------------------------------------------------.   
   * |ｺﾝact1|ﾀｹﾞST |  W   |ﾄｩﾙｰN |ｽﾊﾟｲﾝD|ﾀｹﾞMT |ﾘﾀﾆｰ  |   
   * |------+------+------+------+------+------+------|   
   * |   A  |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ｼﾞｬﾝﾌﾟ|  D   |   
   * |------+------+------+------+------+------+------|   
   * |竜牙尾|ｺﾝact1|蒼竜血|ｱﾑﾚﾝ  |Dﾀﾞｲﾌﾞ| 薬1  |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | DRK  |      |      |   S  |ｲﾙｰｼﾌﾞ|                 
   * `----------------------------------+------.          
   *                                    |ﾘﾀﾆｰ  |          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [DRG] = LAYOUT( \
    KC_Z,     KC_F3,     KC_W,       LALT(KC_1), KC_EQUAL,  KC_F1,      LALT(KC_6),\
    KC_A,     XXXXXXX,   KC_SPC,     KC_F,       KC_T,      KC_MINUS,   KC_D,      \
    RR_RD,    KC_Z,      LALT(KC_9), KC_ASTR,    KC_0,      LCA(KC_0),  JS_BUTTON7,\
    TO(DRK),  XXXXXXX,   XXXXXXX,    KC_S,       LALT(KC_7),                       \
                                                            LALT(KC_6),            \
                                                                        KC_F12     \
  ),

  /* DRK
   * ,------------------------------------------------.   
   * | ｼｬｰｸ |      |      |ﾘﾌﾟﾗｲ |ｱﾋﾞｻﾙ |      |ﾘﾋﾞﾃﾞ |   
   * |------+------+------+------+------+------+------|   
   * |ｺﾝact1|      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾌﾞﾗﾃﾞﾘ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |ﾌﾞﾗﾅｲ |ｱﾑﾚﾝ  |ﾌﾞﾗｳｪ |      |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | WAR  |      |      |      |ｽﾀﾝｽ  |                 
   * `----------------------------------+------.          
   *                                    |      |          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [DRK] = LAYOUT( \
    LCA(KC_EQL), XXXXXXX, XXXXXXX,      KC_LPRN,    LALT(KC_1), XXXXXXX,    LCA(KC_3), \
    KC_Z,        XXXXXXX, KC_SPC,       KC_F,       KC_T,       LALT(KC_2), XXXXXXX,   \
    XXXXXXX,     XXXXXXX, LALT(KC_EQL), LALT(KC_6), LALT(KC_3), XXXXXXX,    JS_BUTTON7,\
    TO(WAR),     XXXXXXX, XXXXXXX,      XXXXXXX,    LALT(KC_4),                        \
                                                                XXXXXXX,               \
                                                                            KC_F12     \
  ),

  /* WAR
   * ,------------------------------------------------.   
   * | ｼｬｰｸ |      |ｼｪｲｸｵﾌ|ﾘﾌﾟﾗｲ |      |      | ﾎﾙﾑ  |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾌｪﾙｸﾘ |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |ｳｫｰｸﾗｲ|ｱﾑﾚﾝ  |原初開|      |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | DNC  |      |      |      |ｽﾀﾝｽ  |                 
   * `----------------------------------+------.          
   *                                    |      |          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [WAR] = LAYOUT( \
    LCA(KC_EQL), XXXXXXX, KC_PLUS,      KC_LPRN,    XXXXXXX,    XXXXXXX,    LCA(KC_3), \
    XXXXXXX,     XXXXXXX, KC_SPC,       KC_F,       KC_T,       LALT(KC_3), XXXXXXX,   \
    XXXXXXX,     XXXXXXX, LALT(KC_UNDS),LALT(KC_9), LALT(KC_5), XXXXXXX,    JS_BUTTON7,\
    TO(DNC),     XXXXXXX, XXXXXXX,      XXXXXXX,    LALT(KC_1),                        \
                                                                XXXXXXX,               \
                                                                            KC_F12     \
  ),

  /* DNC
   * ,------------------------------------------------.   
   * |      |      |      |ｱﾝｱﾊﾞﾝ|      |ﾀｹﾞMT |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾌﾗﾘｯｼｭ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |ｺﾝact1|守ｻﾝﾊﾞ|ｱﾑﾚﾝ  |攻ﾀﾝｺﾞ|      |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | WHM  |      |      |      |癒ﾜﾙﾂ |                 
   * `----------------------------------+------.          
   *                                    |ｲﾝﾌﾟﾛﾋ|          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [DNC] = LAYOUT( \
    XXXXXXX,  XXXXXXX,   XXXXXXX,   KC_EQUAL,   XXXXXXX,   KC_F1,   XXXXXXX,    \
    XXXXXXX,  XXXXXXX,   KC_SPC,    KC_F,       KC_T,      KC_8,    XXXXXXX,    \
    XXXXXXX,  KC_Z,      KC_LPRN,   LALT(KC_5), KC_AMPR,   XXXXXXX, JS_BUTTON7, \
    TO(WHM),  XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_ASTR,                        \
                                                           KC_MINUS,            \
                                                                    KC_F12      \
  ),

  /* WHM
   * ,------------------------------------------------.   
   * |ｺﾝact1|      |   W  |ﾍﾞﾆｿﾝT|ﾃﾝﾊﾟ  |ﾀｹﾞMT |救出  |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾙｰｼｯﾄﾞ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |ｼﾝｴｱｰ |堅実魔|神速魔|      |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | RDM  |      |      |      |ｲﾝﾄﾞｩﾙ|                 
   * `----------------------------------+------.          
   *                                    |ｺﾝact1|          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [WHM] = LAYOUT( \
    KC_Z,      XXXXXXX,   KC_W,       LALT(KC_EQUAL),LALT(KC_5),    KC_F1,      LALT(KC_4),  \
    XXXXXXX,   XXXXXXX,   KC_SPC,     KC_F,          KC_T,          LALT(KC_8), XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   LALT(KC_0), LALT(KC_6),    LALT(KC_MINUS),XXXXXXX,    JS_BUTTON7,  \
    TO(RDM),   XXXXXXX,   XXXXXXX,    XXXXXXX,       LALT(KC_7),                             \
                                                                    KC_Z,                    \
                                                                                KC_F12       \
  ),

  /* RDM
   * ,------------------------------------------------.   
   * |ｺﾝact1|      |      |ｱｸｾﾗ  |      |ﾀｹﾞMT |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾙｰｼｯﾄﾞ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |ﾏﾅﾌｨｹ |堅実魔|ｴﾝﾎﾞﾙ |ｱﾄﾞﾙ  |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | NIN  |      |      |      |      |                 
   * `----------------------------------+------.          
   *                                    |ｺﾝact1|          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [RDM] = LAYOUT( \
    KC_Z,      XXXXXXX,   XXXXXXX,    LALT(KC_4), XXXXXXX,    KC_F1,      XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   KC_SPC,     KC_F,       KC_T,       LALT(KC_3), XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   LALT(KC_9), KC_ASTR,    LALT(KC_5), LALT(KC_2), JS_BUTTON7,  \
    TO(NIN),   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,                             \
                                                              KC_Z,                    \
                                                                          KC_F12       \
  ),

  /* NIN
   * ,------------------------------------------------.   
   * |      |      |  W   |ﾄｩﾙｰN |      |ﾀｹﾞMT |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |天地人|      |   
   * |------+------+------+------+------+------+------|   
   * |      |かくれ|だまし|ｱﾑﾚﾝ  |活殺  |      |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | RGB  |      |      |      |命水  |                 
   * `----------------------------------+------.          
   *                                    |      |          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [NIN] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   KC_W,       LALT(KC_3), XXXXXXX,    KC_F1,      XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   KC_SPC,     KC_F,       KC_T,       LALT(KC_2), XXXXXXX,     \
    XXXXXXX,   LALT(KC_0),LALT(KC_7), LALT(KC_4), LALT(KC_1), XXXXXXX,    JS_BUTTON7,  \
    TO(RGB),   XXXXXXX,   XXXXXXX,    XXXXXXX,    KC_9,                                \
                                                              XXXXXXX,                 \
                                                                          KC_F12       \
  ),

  /* RGB
   * ,------------------------------------------------.   
   * |RGBTOG|RGBHUI|RGBHUD|RGBSAI|RGBSAD|RGBVAI|RGBVAD|   
   * |------+------+------+------+------+------+------|   
   * |RGBMOD|RGBRST|Space |ﾀｹﾞ替 |ﾀｹﾞ近 |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | SAM  |      |      |      |      |                 
   * `----------------------------------+------.          
   *                                    |      |          
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
  [RGB] = LAYOUT( \
    RGB_TOG,   RGB_HUI,   RGB_HUD,    RGB_SAI,    RGB_SAD,    RGB_VAI,    RGB_VAD,     \
    RGB_MOD,   RGBRST,    KC_SPC,     KC_F,       KC_T,       XXXXXXX,    XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    JS_BUTTON7,  \
    TO(SAM),   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,                             \
                                                              XXXXXXX,                 \
                                                                          XXXXXXX      \
  ),

};


joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL
};

void matrix_scan_user(void) {

    joystick_status.axes[0] = analogReadPin(F4)/4 - 128;
    joystick_status.axes[1] = analogReadPin(D4)/4 - 128;
    joystick_status.status |= JS_UPDATED;

}


