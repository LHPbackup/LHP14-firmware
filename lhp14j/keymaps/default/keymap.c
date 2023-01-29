#include QMK_KEYBOARD_H
#include "joystick.h"
#include "analog.h"

#define SAM 0
#define SCH 1
#define SGE 2
#define MNK 3
#define RPR 4
#define DRG 5
#define DRK 6
#define WAR 7
#define DNC 8
#define MCH 9
#define WHM 10
#define RDM 11
#define NIN 12



#define RGB 13




bool repeat_sd = false;		//Global repeat variable
static uint16_t timer_sd;	//Global timer variable
bool repeat_jp = false;
static uint16_t timer_jp;
bool repeat_dd = false;
static uint16_t timer_dd;
bool repeat_pot = false;
static uint16_t timer_pot;




void render_logo(void) {
    oled_set_cursor(0, 0);
    oled_write_P(lhp_logo, false);
}

enum custom_keycodes {
  AC_PH = SAFE_RANGE,
  HC_HB,
  SE_SH,
  RGBRST,
  TK_GG,
  RPT_SD,
  RPT_JP,
  RPT_DD,
  RPT_POT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    
    case AC_PH:
      if (record->event.pressed) {
         register_code(KC_LALT);
           SEND_STRING(SS_DELAY(10) "2" SS_DELAY(10));
         unregister_code(KC_LALT);
           SEND_STRING(SS_DELAY(10) ")" SS_DELAY(10));
      }
      break;
    
    case HC_HB:
      if (record->event.pressed) {
         register_code(KC_LALT);
           SEND_STRING(SS_DELAY(10) "7" SS_DELAY(10));
           SEND_STRING(SS_DELAY(10) "8" SS_DELAY(10));
         unregister_code(KC_LALT);
      }
      break;
    
    case SE_SH:
      if (record->event.pressed) {
         register_code(KC_LALT);
           tap_code_delay(KC_4,10);
           tap_code_delay(KC_9,10);
         unregister_code(KC_LALT);
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
    
    case TK_GG:
      if (record->event.pressed) {
         register_code(KC_LALT);
           SEND_STRING(SS_DELAY(10) "8" SS_DELAY(10));
           SEND_STRING(SS_DELAY(10) "9" SS_DELAY(10));
         unregister_code(KC_LALT);
      }
      break;
    
    case RPT_SD:
      if (record->event.pressed) {				//When key is pressed
            tap_code(KC_EQL);					//Type key you want to repeat (in this case =)
            repeat_sd = true;					//Set "repeat_sd" to true
            timer_sd = timer_read();				//Start timer
         } else {						//Else key is released
            repeat_sd = false;					//Set "repeat_sd" to false
         }
        return false;
      break;
      
      case RPT_JP:
      if (record->event.pressed) {
            tap_code(KC_MINS);
            repeat_jp = true;
            timer_jp = timer_read();
         } else {
            repeat_jp = false;
         }
        return false;
      break;
      
      case RPT_DD:
      if (record->event.pressed) {
            tap_code(KC_0);
            repeat_dd = true;
            timer_dd = timer_read();
         } else {
            repeat_dd = false;
         }
        return false;
      break;
      
      case RPT_POT:
      if (record->event.pressed) {
            repeat_pot = true;
            timer_pot = timer_read();
         } else {
            repeat_pot = false;
         }
        return false;
      break;
  }
  return true;
}




joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
     JOYSTICK_AXIS_VIRTUAL, // x
     JOYSTICK_AXIS_VIRTUAL  // y
};

void matrix_scan_user(void) {

    joystick_set_axis(0,analogReadPin(F4)/4 - 128);
    joystick_set_axis(1,analogReadPin(F5)/4 - 128);

    if ((repeat_sd) && (timer_elapsed(timer_sd) > 50)) {		//If "repeat_sd" is true and 50 ms has elapsed
         tap_code(KC_EQL);						//Type key you want to repeat
       timer_sd = timer_read();						//Reset timer (also could do with modulus % and not resetting timer, unsure which is faster)
    }
    
    if ((repeat_jp) && (timer_elapsed(timer_jp) > 100)) {
         tap_code(KC_MINS);
       timer_jp = timer_read();
    }
    
    if ((repeat_dd) && (timer_elapsed(timer_dd) > 150)) {
         tap_code(KC_0);
       timer_dd = timer_read();
    }
    
    if ((repeat_pot) && (timer_elapsed(timer_pot) > 100)) {
         register_code(KC_LALT);
           tap_code_delay(KC_0,10);
         unregister_code(KC_LALT);
       timer_dd = timer_read();
    }
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
            
        case SGE:
            oled_write_P(PSTR("SAGE\n"), false);
            rgblight_sethsv(100, 100, 90);
            break;
            
        case MNK:
            oled_write_P(PSTR("MONK\n"), false);
            rgblight_sethsv(85, 255, 30);
            break;
            
        case RPR:
            oled_write_P(PSTR("REAPER\n"), false);
            rgblight_sethsv(0, 255, 20);
            break;
            
            
        case DRG:
            oled_write_P(PSTR("DRAGOON\n"), false);
            rgblight_sethsv(170, 255, 10);
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
            
        case MCH:
            oled_write_P(PSTR("MACHINIST\n"), false);
            rgblight_sethsv(11, 176, 20);
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



void suspend_power_down_kb(void) {
    oled_off();
}

void suspend_wakeup_init_kb(void) {
    oled_on();
}





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

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
    KC_HASH,     LALT(KC_5),LALT(KC_2),  KC_AMPR,   KC_ASTR,      RPT_POT,    XXXXXXX,   \
    LCA(KC_MINS),XXXXXXX,   LCA(KC_MINS),KC_S,      LALT(KC_MINS),            TO(SCH),   \
                                                                  LALT(KC_3), KC_HASH,   \
                                                                              KC_F12     \
  ),

  /* SCH
   * ,------------------------------------------------.   
   * |ﾊﾟｸﾄ2 |ﾊﾟｸﾄ3 |   W  |秘策  |疾風怒|      |救出  |   
   * |------+------+------+------+------+------+------|   
   * |   A  |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾙｰｼｯﾄﾞ|  D   |   
   * |------+------+------+------+------+------+------|   
   * |      |ｺﾝact1|ｴｰﾃﾌﾛｰ|堅実魔|連環計|転化  |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |   S  |応急  |      | SGE  |   
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
    XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_S,       KC_7,                   TO(SGE),   \
                                                              LALT(KC_0), JS_0,      \
                                                                          KC_F12     \
  ),

  /* SGE
   * ,------------------------------------------------.   
   * | ﾊｲﾏ2 | ﾊｲﾏ3 |   W  |ｿﾞｰｴ  |ｲｯｸｿｺﾚ|      |救出  |   
   * |------+------+------+------+------+------+------|   
   * |ｸﾗｰｼｽ2|ｸﾗｰｼｽ3|Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾙｰｼｯﾄﾞ|  D   |   
   * |------+------+------+------+------+------+------|   
   * |   A  |ｺﾝact1|ｴｳｸﾗｼｱ|堅実魔|ﾘｿﾞｰﾏﾀ|      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |   S  |ﾎｰﾘｽﾞﾑ|      | MNK  |   
   * `----------------------------------+-------------.   
   *                                    |ﾊﾟﾝﾊｲﾏ|JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [SGE] = LAYOUT( \
    LCA(KC_5), LCA(KC_4), KC_W,       KC_ASTR,    KC_MINS,    XXXXXXX,    LALT(KC_3),\
    LCA(KC_8), LCA(KC_7), KC_SPC,     KC_F,       KC_T,       LALT(KC_4), KC_D,      \
    KC_A,      KC_Z,      LALT(KC_6), LALT(KC_5), LALT(KC_1), XXXXXXX,    XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_S,       KC_UNDS,                TO(MNK),   \
                                                              LALT(KC_0), JS_0,      \
                                                                          KC_F12     \
  ),




  /* MNK
   * ,------------------------------------------------.   #
   * |ｺﾝact1|ﾀｹﾞST |  W   |ﾄｩﾙｰN l桃園  |      |後見る|   
   * |------+------+------+------+------+------+------|   
   * |  A   |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |闘気  |  D   |   
   * |------+------+------+------+------+------+------|   
   * |      |演武  |踏鳴  |ｱﾑﾚﾝ  |紅蓮  |薬1   |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |ｺﾝact2|  S   |必殺技|      | RPR  |   
   * `----------------------------------+-------------.   
   *                                    |無我  |金剛  |   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
   [MNK] = LAYOUT( \
    KC_Z,      KC_F2,     KC_W,        LALT(KC_6),LALT(KC_9),XXXXXXX,    KC_V,      \
    KC_A,      XXXXXXX,   KC_SPC,      KC_F,      KC_T,     LALT(KC_5),  KC_D,      \
    XXXXXXX,   LCA(KC_1), LCA(KC_9),   KC_AMPR,   TK_GG,    LALT(KC_0),  XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   LCA(KC_MINS),KC_S,      KC_0,                  TO(RPR),   \
                                                             LCA(KC_2),  KC_HASH,   \
                                                                         KC_F12     \
  ),

  /* RPR
   * ,------------------------------------------------.   
   * |ｺﾝact1|ﾀｹﾞST |  W   |ﾄｩﾙｰN lｲﾝｸﾞﾚ |ﾀｹﾞMT |後見る|   
   * |------+------+------+------+------+------+------|   
   * |  A   |  #   |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ALT0  |  D   |   
   * |------+------+------+------+------+------+------|   
   * |      |ｸﾚｽﾄ  |ｱﾙｹﾌﾚﾊ|ｱﾑﾚﾝ  |ｼｬﾄﾞｳ |ALT-  |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |ｺﾝact2|  S   |ｲｰｸﾞﾚ |      | DRG  |   
   * `----------------------------------+-------------.   
   *                                    |黙想  |ｸﾚｽﾄ  |   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
   [RPR] = LAYOUT( \
    KC_Z,      KC_F2,     KC_W,        LALT(KC_1),LALT(KC_9),KC_F1,        KC_V,         \
    KC_A,      KC_HASH,   KC_SPC,      KC_F,      KC_T,      LALT(KC_0),   KC_D,         \
    KC_HASH,   LALT(KC_MINS),AC_PH,    KC_AMPR,   KC_ASTR,   LALT(KC_MINS),XXXXXXX,      \
    XXXXXXX,   XXXXXXX,   LCA(KC_MINS),KC_S,      LALT(KC_7),              TO(DRG),      \
                                                             LALT(KC_3),   LALT(KC_MINS),\
                                                                           KC_F12        \
  ),


  /* DRG
   * ,------------------------------------------------.   
   * |ｺﾝact1|ﾀｹﾞST |  W   |ﾄｩﾙｰN |ｽﾊﾟｲﾝD|ﾀｹﾞMT |ﾘﾀﾆｰ  |   
   * |------+------+------+------+------+------+------|   
   * |  A   |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ｼﾞｬﾝﾌﾟ|  D   |   
   * |------+------+------+------+------+------+------|   
   * |      |ｺﾝact1|蒼竜血|ｱﾑﾚﾝ  |Dﾀﾞｲﾌﾞ| 薬1  |      |   
   * |------+------+------+------+------+-------------'   
   * |RPT_SD|RPT_JP|RPT_DD|  S   |ｲﾙｰｼﾌﾞ|      | DRK  |   
   * `----------------------------------+-------------.   
   *                                    |ﾘﾀﾆｰ  |JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [DRG] = LAYOUT( \
    KC_Z,     KC_F2,     KC_W,       LALT(KC_1), KC_EQUAL,  KC_F1,      LALT(KC_6),\
    KC_A,     XXXXXXX,   KC_SPC,     KC_F,       KC_T,      KC_MINUS,   KC_D,      \
    XXXXXXX,  KC_Z,      LALT(KC_9), KC_ASTR,    KC_0,      LCA(KC_0),  XXXXXXX,   \
    RPT_SD,   RPT_JP,    RPT_DD,     KC_S,       LALT(KC_7),            TO(DRK),   \
                                                            LALT(KC_6), JS_0,      \
                                                                        KC_F12     \
  ),

  /* DRK
   * ,------------------------------------------------.   
   * | ｼｬｰｸ |      |      |ﾘﾌﾟﾗｲ |ｱﾋﾞｻﾙ |      |ﾘﾋﾞﾃﾞ |   
   * |------+------+------+------+------+------+------|   
   * |ｺﾝact1|      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾌﾞﾗﾃﾞﾘ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |ﾌﾞﾗﾅｲ |ｱﾑﾚﾝ  |ﾌﾞﾗｳｪ |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |ｽﾀﾝｽ  |      | WAR  |   
   * `----------------------------------+-------------.   
   *                                    |      |ｼﾞｪｸﾄ |   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [DRK] = LAYOUT( \
    LCA(KC_EQL), XXXXXXX, XXXXXXX,      KC_LPRN,    LALT(KC_1), XXXXXXX,    LCA(KC_3), \
    KC_Z,        XXXXXXX, KC_SPC,       KC_F,       KC_T,       LALT(KC_2), XXXXXXX,   \
    XXXXXXX,     XXXXXXX, LALT(KC_EQL), LALT(KC_6), LALT(KC_3), XXXXXXX,    XXXXXXX,   \
    XXXXXXX,     XXXXXXX, XXXXXXX,      XXXXXXX,    LALT(KC_7),             TO(WAR),   \
                                                                XXXXXXX,    LALT(KC_8),\
                                                                            KC_F12     \
  ),

  /* WAR
   * ,------------------------------------------------.   
   * | ｼｬｰｸ |      |ｼｪｲｸｵﾌ|ﾘﾌﾟﾗｲ |      |      | ﾎﾙﾑ  |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾌｪﾙｸﾘ |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |ｳｫｰｸﾗｲ|ｱﾑﾚﾝ  |原初開|      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |ｽﾀﾝｽ  |      | DNC  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [WAR] = LAYOUT( \
    LCA(KC_EQL), XXXXXXX, KC_PLUS,      KC_LPRN,    XXXXXXX,    XXXXXXX,    LCA(KC_3), \
    XXXXXXX,     XXXXXXX, KC_SPC,       KC_F,       KC_T,       LALT(KC_3), XXXXXXX,   \
    XXXXXXX,     XXXXXXX, LALT(KC_UNDS),LALT(KC_9), LALT(KC_5), XXXXXXX,    XXXXXXX,   \
    XXXXXXX,     XXXXXXX, XXXXXXX,      XXXXXXX,    LALT(KC_1),             TO(DNC),   \
                                                                XXXXXXX,    JS_0,      \
                                                                            KC_F12     \
  ),

  /* DNC
   * ,------------------------------------------------.   
   * |      |      |      |      |ｱﾝｱﾊﾞﾝ|ﾀｹﾞMT |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾌﾗﾘｯｼｭ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |ｺﾝact1|癒ﾜﾙﾂ |ｱﾑﾚﾝ  |攻ﾀﾝｺﾞ|      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |守ｻﾝﾊﾞ|      | MCH  |   
   * `----------------------------------+-------------.   
   *                                    |ｲﾝﾌﾟﾛﾋ|JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [DNC] = LAYOUT( \
    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,LALT(KC_EQUAL),KC_F1,   XXXXXXX,    \
    XXXXXXX,  XXXXXXX,   KC_SPC,    KC_F,       KC_T,      KC_8,    XXXXXXX,    \
    XXXXXXX,  KC_Z,      KC_LPRN,   LALT(KC_5), KC_AMPR,   XXXXXXX, XXXXXXX,    \
    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_ASTR,            TO(MCH),    \
                                                           KC_MINUS,JS_0,       \
                                                                    KC_F12      \
  ),

  /* MCH
   * ,------------------------------------------------.   
   * |      |      |      |      |      |ﾀｹﾞMT |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾊﾟｲﾙB |      |   
   * |------+------+------+------+------+------+------|   
   * |      |ｺﾝact1|Bﾋｰﾀｰ |ｱﾑﾚﾝ  |HC_HB |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | WHM  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [MCH] = LAYOUT( \
    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,   KC_F1,   XXXXXXX,    \
    XXXXXXX,  XXXXXXX,   KC_SPC,    KC_F,       KC_T,      KC_ASTR, XXXXXXX,    \
    XXXXXXX,  KC_Z,      LALT(KC_4),LALT(KC_5), HC_HB,     XXXXXXX, XXXXXXX,    \
    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,            TO(WHM),    \
                                                           XXXXXXX, JS_0,       \
                                                                    KC_F12      \
  ),

  /* WHM
   * ,------------------------------------------------.   
   * |      |   W  |ﾍﾞﾆｿT2|ﾃﾝﾊﾟ  |ﾍﾞﾆｿT1|      | 救出 |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾙｰｼｯﾄﾞ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |ｺﾝact1|ｼﾝｴｱｰ |堅実魔|神速魔|      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |ｲﾝﾄﾞｩﾙ|      | RDM  |   
   * `----------------------------------+-------------.   
   *                                    |ﾗﾌﾟﾁｬｰ|JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [WHM] = LAYOUT( \
    XXXXXXX,   KC_W,      LALT(KC_EQUAL),LALT(KC_5), LALT(KC_9),    XXXXXXX,    LALT(KC_4),  \
    XXXXXXX,   XXXXXXX,   KC_SPC,     KC_F,          KC_T,          LALT(KC_7), XXXXXXX,     \
    XXXXXXX,   KC_Z,      LALT(KC_0), LALT(KC_6),    LALT(KC_MINUS),XXXXXXX,    XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,       KC_UNDS,                   TO(RDM),     \
                                                                    KC_MINUS,   JS_0,        \
                                                                                KC_F12       \
  ),

  /* RDM
   * ,------------------------------------------------.   
   * |ｺﾝact1|      |      |ｱｸｾﾗ  |      |ﾀｹﾞMT |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |ﾙｰｼｯﾄﾞ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |ﾏﾅﾌｨｹ |堅実魔|ｴﾝﾎﾞﾙ |ｱﾄﾞﾙ  |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |ﾊﾞﾏｼｸ |      | NIN  |   
   * `----------------------------------+-------------.   
   *                                    |ｺﾝact1|JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [RDM] = LAYOUT( \
    KC_Z,      XXXXXXX,   XXXXXXX,    LALT(KC_4), XXXXXXX,    KC_F1,      XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   KC_SPC,     KC_F,       KC_T,       LALT(KC_3), XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   LALT(KC_9), KC_ASTR,    LALT(KC_5), LALT(KC_2), XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    LALT(KC_1),             TO(NIN),     \
                                                              KC_Z,       JS_0,        \
                                                                          KC_F12       \
  ),

  /* NIN
   * ,------------------------------------------------.   
   * |      |      |  W   |ﾄｩﾙｰN |無限三|ﾀｹﾞMT |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |ﾀｹﾞ替 |ﾀｹﾞ近 |天地人|      |   
   * |------+------+------+------+------+------+------|   
   * |      |かくれ|だまし|ｱﾑﾚﾝ  |活殺  |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |命水  |      | RGB  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [NIN] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   KC_W,       LALT(KC_3), KC_EQUAL,   KC_F1,      XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   KC_SPC,     KC_F,       KC_T,       LALT(KC_2), XXXXXXX,     \
    XXXXXXX,   LALT(KC_0),LALT(KC_7), LALT(KC_4), LALT(KC_1), XXXXXXX,    XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    KC_9,                   TO(RGB),     \
                                                              XXXXXXX,    JS_0,        \
                                                                          KC_F12       \
  ),

  /* RGB
   * ,------------------------------------------------.   
   * |RGBTOG|RGBHUI|RGBHUD|RGBSAI|RGBSAD|RGBVAI|RGBVAD|   
   * |------+------+------+------+------+------+------|   
   * |RGBMOD|RGBRST|Space |ﾀｹﾞ替 |ﾀｹﾞ近 |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | SAM  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
  [RGB] = LAYOUT( \
    RGB_TOG,   RGB_HUI,   RGB_HUD,    RGB_SAI,    RGB_SAD,    RGB_VAI,    RGB_VAD,     \
    RGB_MOD,   RGBRST,    KC_SPC,     KC_F,       KC_T,       XXXXXXX,    XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,                TO(SAM),     \
                                                              XXXXXXX,    JS_0,        \
                                                                          XXXXXXX      \
  ),

};





