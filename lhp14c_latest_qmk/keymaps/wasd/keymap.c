#include QMK_KEYBOARD_H
#include "joystick.h"
#include "analog.h"

#define SAM 0
#define SCH 1
#define RPR 2
#define DRG 3
#define DRK 4
#define WAR 5
#define DNC 6
#define WHM 7
#define RDM 8
#define NIN 9



#define RGB 10


static int actuation = 256; // actuation point for arrows (0-511)
bool arrows[4];

void render_logo(void) {
    oled_set_cursor(0, 0);
    oled_write_P(lhp_logo, false);
}

enum custom_keycodes {
  AC_PH = SAFE_RANGE,
  RR_RD,
  SE_SH,
  RGBRST
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case AC_PH:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("2") ")");
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
    case SE_SH:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("4") SS_LALT("9"));
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
            
        case RPR:
            oled_write_P(PSTR("REAPER\n"), false);
            rgblight_sethsv(0, 255, 20);
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

bool oled_task_user(void) {
    render_logo();
    render_layer();
    return false;
}





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* SAM
   * ,------------------------------------------------.   #
   * |ｺﾝact1|ﾀｹﾞST |  W   |ﾄｩﾙｰN l照破  |無明照|後見る|   
   * |------+------+------+------+------+------+------|   
   * |  A   |心眼  |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |閃影照|  D   |   
   * |------+------+------+------+------+------+------|   
   * |心眼  |葉隠  |意気衝|ｱﾑﾚﾝ  |明鏡  |薬1   | SCH  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |ｺﾝact2|  S   |夜天  |                 
   * `----------------------------------+-------------.          
   *                                    |黙想  |心眼  |   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
   [SAM] = LAYOUT( \
    KC_Z,      KC_F3,     KC_W,        LALT(KC_1),LALT(KC_4),KC_PLUS,    KC_V,      \
    KC_A,      KC_HASH,   KC_SPC,      KC_F,      KC_T,      SE_SH,      KC_D,      \
    KC_HASH,   LALT(KC_5),LALT(KC_2),  KC_AMPR,   KC_ASTR,   LALT(KC_0), TO(SCH),   \
    XXXXXXX,   XXXXXXX,   LCA(KC_MINS),KC_S,   LALT(KC_MINS),                       \
                                                             LALT(KC_3), KC_HASH,   \
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
   * |ﾊﾟｸﾄ2 |ﾊﾟｸﾄ3 |   W  |秘策  |疾風怒|      |救出  |   
   * |------+------+------+------+------+------+------|   
   * |   A  |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾙｰｼｯﾄﾞ|  D   |   
   * |------+------+------+------+------+------+------|   
   * |      |ｺﾝact1|ｴｰﾃﾌﾛｰ|堅実魔|連環計|転化  | RPR  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |   S  |応急  |                 
   * `----------------------------------+-------------.          
   *                                    |ｾﾗ+ｺﾝｿ|JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [SCH] = LAYOUT( \
    LCA(KC_5), LCA(KC_4), KC_W,       KC_ASTR,    LCA(KC_EQL),XXXXXXX,    LALT(KC_3),\
    KC_A,      XXXXXXX,   KC_SPC,     KC_F,       KC_T,       LALT(KC_4), KC_D,      \
    XXXXXXX,   KC_Z,      LALT(KC_6), LALT(KC_5), LALT(KC_1), LCA(KC_7),  TO(RPR),   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_S,       KC_7,                              \
                                                              LALT(KC_0), JS_BUTTON0,\
                                                                          KC_F12     \
  ),

  /* RPR
   * ,------------------------------------------------.   
   * |ｺﾝact1|ﾀｹﾞST |  W   |ﾄｩﾙｰN lｲﾝｸﾞﾚ |ﾀｹﾞMT |後見る|   
   * |------+------+------+------+------+------+------|   
   * |  A   |心眼  |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ALT0  |  D   |   
   * |------+------+------+------+------+------+------|   
   * |心眼  |ｸﾚｽﾄ  |ｱﾙｹﾌﾚﾊ|ｱﾑﾚﾝ  |ｼｬﾄﾞｳ |ALT-  | DRG  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |ｺﾝact2|  S   |ｲｰｸﾞﾚ |                 
   * `----------------------------------+-------------.          
   *                                    |黙想  |ｸﾚｽﾄ  |   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
   [RPR] = LAYOUT( \
    KC_Z,      KC_F3,     KC_W,        LALT(KC_1),LALT(KC_9),KC_F1,      KC_V,      \
    KC_A,      KC_HASH,   KC_SPC,      KC_F,      KC_T,      LALT(KC_0), KC_D,      \
    KC_HASH,   LALT(KC_MINS),AC_PH,    KC_AMPR,   KC_ASTR,   LALT(KC_MINS), TO(DRG),   \
    XXXXXXX,   XXXXXXX,   LCA(KC_MINS),KC_S,      LALT(KC_7),                       \
                                                             LALT(KC_3), LALT(KC_MINS),\
                                                                         KC_F12     \
  ),


  /* DRG
   * ,------------------------------------------------.   
   * |ｺﾝact1|ﾀｹﾞST |  W   |ﾄｩﾙｰN |ｽﾊﾟｲﾝD|ﾀｹﾞMT |ﾘﾀﾆｰ  |   
   * |------+------+------+------+------+------+------|   
   * |   A  |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ｼﾞｬﾝﾌﾟ|  D   |   
   * |------+------+------+------+------+------+------|   
   * |      |ｺﾝact1|蒼竜血|ｱﾑﾚﾝ  |Dﾀﾞｲﾌﾞ| 薬1  | DRK  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |   S  |ｲﾙｰｼﾌﾞ|                 
   * `----------------------------------+-------------.   
   *                                    |ﾘﾀﾆｰ  |JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [DRG] = LAYOUT( \
    KC_Z,     KC_F3,     KC_W,       LALT(KC_1), KC_EQUAL,  KC_F1,      LALT(KC_6),\
    KC_A,     XXXXXXX,   KC_SPC,     KC_F,       KC_T,      KC_MINUS,   KC_D,      \
    XXXXXXX,  KC_Z,      LALT(KC_9), KC_ASTR,    KC_0,      LCA(KC_0),  TO(DRK),   \
    XXXXXXX,  XXXXXXX,   XXXXXXX,    KC_S,       LALT(KC_7),                       \
                                                            LALT(KC_6), JS_BUTTON0,\
                                                                        KC_F12     \
  ),

  /* DRK
   * ,------------------------------------------------.   
   * | ｼｬｰｸ |      |      |ﾘﾌﾟﾗｲ |ｱﾋﾞｻﾙ |      |ﾘﾋﾞﾃﾞ |   
   * |------+------+------+------+------+------+------|   
   * |ｺﾝact1|      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾌﾞﾗﾃﾞﾘ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |ﾌﾞﾗﾅｲ |ｱﾑﾚﾝ  |ﾌﾞﾗｳｪ |      | WAR  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |ｽﾀﾝｽ  |                 
   * `----------------------------------+-------------.   
   *                                    |      |ｼﾞｪｸﾄ |   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [DRK] = LAYOUT( \
    LCA(KC_EQL), XXXXXXX, XXXXXXX,      KC_LPRN,    LALT(KC_1), XXXXXXX,    LCA(KC_3), \
    KC_Z,        XXXXXXX, KC_SPC,       KC_F,       KC_T,       LALT(KC_2), XXXXXXX,   \
    XXXXXXX,     XXXXXXX, LALT(KC_EQL), LALT(KC_6), LALT(KC_3), XXXXXXX,    TO(WAR),   \
    XXXXXXX,     XXXXXXX, XXXXXXX,      XXXXXXX,    LALT(KC_7),                        \
                                                                XXXXXXX,    LALT(KC_8),\
                                                                            KC_F12     \
  ),

  /* WAR
   * ,------------------------------------------------.   
   * | ｼｬｰｸ |      |ｼｪｲｸｵﾌ|ﾘﾌﾟﾗｲ |      |      | ﾎﾙﾑ  |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾌｪﾙｸﾘ |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |ｳｫｰｸﾗｲ|ｱﾑﾚﾝ  |原初開|      | DNC  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |ｽﾀﾝｽ  |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [WAR] = LAYOUT( \
    LCA(KC_EQL), XXXXXXX, KC_PLUS,      KC_LPRN,    XXXXXXX,    XXXXXXX,    LCA(KC_3), \
    XXXXXXX,     XXXXXXX, KC_SPC,       KC_F,       KC_T,       LALT(KC_3), XXXXXXX,   \
    XXXXXXX,     XXXXXXX, LALT(KC_UNDS),LALT(KC_9), LALT(KC_5), XXXXXXX,    TO(DNC),   \
    XXXXXXX,     XXXXXXX, XXXXXXX,      XXXXXXX,    LALT(KC_1),                        \
                                                                XXXXXXX,    JS_BUTTON0,\
                                                                            KC_F12     \
  ),

  /* DNC
   * ,------------------------------------------------.   
   * |      |      |      |      |ｱﾝｱﾊﾞﾝ|ﾀｹﾞMT |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾌﾗﾘｯｼｭ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |ｺﾝact1|癒ﾜﾙﾂ |ｱﾑﾚﾝ  |攻ﾀﾝｺﾞ|      | WHM  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |守ｻﾝﾊﾞ|                 
   * `----------------------------------+-------------.   
   *                                    |ｲﾝﾌﾟﾛﾋ|JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [DNC] = LAYOUT( \
    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,LALT(KC_EQUAL), KC_F1,   XXXXXXX,    \
    XXXXXXX,  XXXXXXX,   KC_SPC,    KC_F,       KC_T,      KC_8,    XXXXXXX,    \
    XXXXXXX,  KC_Z,      KC_LPRN,   LALT(KC_5), KC_AMPR,   XXXXXXX, TO(WHM),    \
    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_ASTR,                        \
                                                           KC_MINUS,JS_BUTTON0, \
                                                                    KC_F12      \
  ),

  /* WHM
   * ,------------------------------------------------.   
   * |ｺﾝact1|      |   W  |ﾍﾞﾆｿﾝT|ﾃﾝﾊﾟ  |ﾀｹﾞMT |救出  |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾙｰｼｯﾄﾞ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |ｼﾝｴｱｰ |堅実魔|神速魔|      | RDM  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |ｲﾝﾄﾞｩﾙ|                 
   * `----------------------------------+-------------.   
   *                                    |ｺﾝact1|JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [WHM] = LAYOUT( \
    KC_Z,      XXXXXXX,   KC_W,       LALT(KC_EQUAL),LALT(KC_5),    KC_F1,      LALT(KC_4),  \
    XXXXXXX,   XXXXXXX,   KC_SPC,     KC_F,          KC_T,          LALT(KC_8), XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   LALT(KC_0), LALT(KC_6),    LALT(KC_MINUS),XXXXXXX,    TO(RDM),     \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,       LALT(KC_7),                             \
                                                                    KC_Z,       JS_BUTTON0,  \
                                                                                KC_F12       \
  ),

  /* RDM
   * ,------------------------------------------------.   
   * |ｺﾝact1|      |      |ｱｸｾﾗ  |      |ﾀｹﾞMT |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾙｰｼｯﾄﾞ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |ﾏﾅﾌｨｹ |堅実魔|ｴﾝﾎﾞﾙ |ｱﾄﾞﾙ  | NIN  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |ﾊﾞﾏｼｸ |                 
   * `----------------------------------+-------------.   
   *                                    |ｺﾝact1|JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [RDM] = LAYOUT( \
    KC_Z,      XXXXXXX,   XXXXXXX,    LALT(KC_4), XXXXXXX,    KC_F1,      XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   KC_SPC,     KC_F,       KC_T,       LALT(KC_3), XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   LALT(KC_9), KC_ASTR,    LALT(KC_5), LALT(KC_2), TO(NIN),     \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    LALT(KC_1),                          \
                                                              KC_Z,       JS_BUTTON0,  \
                                                                          KC_F12       \
  ),

  /* NIN
   * ,------------------------------------------------.   
   * |      |      |  W   |ﾄｩﾙｰN |      |ﾀｹﾞMT |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |天地人|      |   
   * |------+------+------+------+------+------+------|   
   * |      |かくれ|だまし|ｱﾑﾚﾝ  |活殺  |      | RGB  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |命水  |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [NIN] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   KC_W,       LALT(KC_3), XXXXXXX,    KC_F1,      XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   KC_SPC,     KC_F,       KC_T,       LALT(KC_2), XXXXXXX,     \
    XXXXXXX,   LALT(KC_0),LALT(KC_7), LALT(KC_4), LALT(KC_1), XXXXXXX,    TO(RGB),     \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    KC_9,                                \
                                                              XXXXXXX,    JS_BUTTON0,  \
                                                                          KC_F12       \
  ),

  /* RGB
   * ,------------------------------------------------.   
   * |RGBTOG|RGBHUI|RGBHUD|RGBSAI|RGBSAD|RGBVAI|RGBVAD|   
   * |------+------+------+------+------+------+------|   
   * |RGBMOD|RGBRST|Space |ﾀｹﾞ替 |ﾀｹﾞ近 |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | SAM  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
  [RGB] = LAYOUT( \
    RGB_TOG,   RGB_HUI,   RGB_HUD,    RGB_SAI,    RGB_SAD,    RGB_VAI,    RGB_VAD,     \
    RGB_MOD,   RGBRST,    KC_SPC,     KC_F,       KC_T,       XXXXXXX,    XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    TO(SAM),     \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,                             \
                                                              XXXXXXX,    JS_BUTTON0,  \
                                                                          XXXXXXX      \
  ),

};







void matrix_scan_user(void) {


        if (!arrows[0] && analogReadPin(F4) - 512 > actuation){
            arrows[0] = true;
            register_code16(KC_D);
        }
        else if (arrows[0] &&  analogReadPin(F4) - 512 < actuation){
            arrows[0] = false;
            unregister_code16(KC_D);
        }
        if (!arrows[1] && analogReadPin(F4) - 512 < -actuation){
            arrows[1] = true;
            register_code16(KC_A);
        }
        else if (arrows[1] && analogReadPin(F4) - 512 > -actuation){
            arrows[1] = false;
            unregister_code16(KC_A);
        }
        if (!arrows[2] && analogReadPin(D4) - 512 > actuation){
            arrows[2] = true;
            register_code16(KC_S);
        }
        else if (arrows[2] &&  analogReadPin(D4) - 512 < actuation){
            arrows[2] = false;
            unregister_code16(KC_S);
        }
        if (!arrows[3] && analogReadPin(D4) - 512 < -actuation){
            arrows[3] = true;
            register_code16(KC_W);
        }
        else if (arrows[3] && analogReadPin(D4) - 512 > -actuation){
            arrows[3] = false;
            unregister_code16(KC_W); 
        }
        joystick_status.status |= JS_UPDATED;
    
}



