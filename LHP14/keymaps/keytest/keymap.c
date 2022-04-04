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
            //rgblight_sethsv(128, 255, 180);
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
   * |∫›act1|¿πﬁST |  W   |ƒ©Ÿ∞N lè∆îj  |¿πﬁMT |å„å©ÇÈ|   
   * |------+------+------+------+------+------+------|   
   * |  A   |      |Space |¿πﬁë÷ |¿πﬁãﬂ |ëMâe  |  D   |   
   * |------+------+------+------+------+------+------|   
   * |ótâB  |ótâB  |à”ãCè’|±—⁄›  |ñæãæ  |ñÚ1   |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | SCH  |      |∫›act2|  S   |ñÈìV  |                 
   * `----------------------------------+------.          
   *                                    |ñŸëz  |          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
 /*[SAM] = LAYOUT( \
    KC_Z,      KC_F3,     KC_W,        LALT(KC_1),LALT(KC_4),KC_F1,      KC_V,      \
    KC_A,      XXXXXXX,   KC_SPC,      KC_F,      KC_T,      LALT(KC_9), KC_D,      \
    LALT(KC_5),LALT(KC_5),LALT(KC_2),  KC_AMPR,   KC_ASTR,   LALT(KC_0), JS_BUTTON7,\
    TO(SCH),   XXXXXXX,   LCA(KC_MINS),KC_S,      LALT(KC_7),                       \
                                                             LALT(KC_3),            \
                                                                         KC_F12     \
  ),*/

 [SAM] = LAYOUT( \
    KC_Q,     KC_W,     KC_E,       KC_R,     KC_T,      KC_Y,    KC_U,      \
    KC_A,     KC_S,     KC_D,       KC_F,     KC_G,      KC_H,    KC_J,      \
    KC_1,     KC_Z,     KC_X,       KC_C,     KC_V,      KC_B,    JS_BUTTON7,\
    TO(SCH),  KC_2,     KC_3,       KC_4,     KC_5,                          \
                                                         KC_6,               \
                                                                  KC_7       \
  ),




  /* SCH
   * ,------------------------------------------------.   
   * | ﬂ∏ƒ2 | ﬂ∏ƒ3 |   W  |îÈçÙ  |      |      |ã~èo  |   
   * |------+------+------+------+------+------+------|   
   * |   A  |      |Space |¿πﬁë÷ |¿πﬁãﬂ |Ÿ∞ºØƒﬁ|  D   |   
   * |------+------+------+------+------+------+------|   
   * |      |∫›act1|¥∞√Ã€∞|åòé¿ñÇ|òAä¬åv|ì]âª  |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | DRG  |      |      |   S  |âûã}  |                 
   * `----------------------------------+------.          
   *                                    |æ◊+∫›ø|          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [SCH] = LAYOUT( \
    LCA(KC_5), LCA(KC_4), KC_W,       KC_ASTR,    XXXXXXX,    XXXXXXX,    LALT(KC_3),  \
    KC_A,      XXXXXXX,   KC_SPC,     KC_F,       KC_T,       LALT(KC_4), KC_D,        \
    XXXXXXX,   KC_Z,      LALT(KC_6), LALT(KC_5), LALT(KC_1), LCA(KC_7),  JS_BUTTON7,  \
    TO(DRG),   XXXXXXX,   XXXXXXX,    KC_S,       KC_7,                                \
                                                              SR_CS,                   \
                                                                          KC_F12       \
  ),

  /* DRG
   * ,------------------------------------------------.   
   * |∫›act1|¿πﬁST |  W   |ƒ©Ÿ∞N |Ω ﬂ≤›D|¿πﬁMT |ÿ¿∆∞  |   
   * |------+------+------+------+------+------+------|   
   * |   A  |      |Space |¿πﬁë÷ |¿πﬁãﬂ |ºﬁ¨›Ãﬂ|  D   |   
   * |------+------+------+------+------+------+------|   
   * |ó≥âÂîˆ|∫›act1|ëìó≥åå|±—⁄›  |D¿ﬁ≤Ãﬁ| ñÚ1  |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | DRK  |      |      |   S  |≤Ÿ∞ºÃﬁ|                 
   * `----------------------------------+------.          
   *                                    |ÿ¿∆∞  |          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [DRG] = LAYOUT( \
    KC_Z,     KC_F3,     KC_W,       LALT(KC_1), KC_EQUAL,  KC_F1,      LALT(KC_6),  \
    KC_A,     XXXXXXX,   KC_SPC,     KC_F,       KC_T,      KC_MINUS,   KC_D,        \
    RR_RD,    KC_Z,      LALT(KC_9), KC_ASTR,    KC_0,      LCA(KC_0),  JS_BUTTON7,  \
    TO(DRK),  XXXXXXX,   XXXXXXX,    KC_S,       LALT(KC_7),                         \
                                                            LALT(KC_6),              \
                                                                        KC_F12       \
  ),

  /* DRK
   * ,------------------------------------------------.   
   * | º¨∞∏ |      |      |ÿÃﬂ◊≤ |±ÀﬁªŸ |      |ÿÀﬁ√ﬁ |   
   * |------+------+------+------+------+------+------|   
   * |∫›act1|      |Space |¿πﬁë÷ |¿πﬁãﬂ |Ãﬁ◊√ﬁÿ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Ãﬁ◊≈≤ |±—⁄›  |Ãﬁ◊≥™ |      |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | WAR  |      |      |      |Ω¿›Ω  |                 
   * `----------------------------------+------.          
   *                                    |      |          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [DRK] = LAYOUT( \
    LCA(KC_EQL), XXXXXXX, XXXXXXX,      KC_LPRN,    LALT(KC_1), XXXXXXX,    LCA(KC_3),   \
    KC_Z,        XXXXXXX, KC_SPC,       KC_F,       KC_T,       LALT(KC_2), XXXXXXX,     \
    XXXXXXX,     XXXXXXX, LALT(KC_EQL), LALT(KC_6), LALT(KC_3), XXXXXXX,    JS_BUTTON7,  \
    TO(WAR),     XXXXXXX, XXXXXXX,      XXXXXXX,    LALT(KC_4),                          \
                                                                XXXXXXX,                 \
                                                                            KC_F12       \
  ),

  /* WAR
   * ,------------------------------------------------.   
   * | º¨∞∏ |      |º™≤∏µÃ|ÿÃﬂ◊≤ |      |      | ŒŸ—  |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |¿πﬁë÷ |¿πﬁãﬂ |Ã™Ÿ∏ÿ |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |≥´∞∏◊≤|±—⁄›  |å¥èâäJ|      |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | DNC  |      |      |      |Ω¿›Ω  |                 
   * `----------------------------------+------.          
   *                                    |      |          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [WAR] = LAYOUT( \
    LCA(KC_EQL), XXXXXXX, KC_PLUS,      KC_LPRN,    XXXXXXX,    XXXXXXX,    LCA(KC_3),   \
    XXXXXXX,     XXXXXXX, KC_SPC,       KC_F,       KC_T,       LALT(KC_3), XXXXXXX,     \
    XXXXXXX,     XXXXXXX, LALT(KC_UNDS),LALT(KC_9), LALT(KC_5), XXXXXXX,    JS_BUTTON7,  \
    TO(DNC),     XXXXXXX, XXXXXXX,      XXXXXXX,    LALT(KC_1),                          \
                                                                XXXXXXX,                 \
                                                                            KC_F12       \
  ),

  /* DNC
   * ,------------------------------------------------.   
   * |      |      |      |±›± ﬁ›|      |¿πﬁMT |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |¿πﬁë÷ |¿πﬁãﬂ |Ã◊ÿØº≠|      |   
   * |------+------+------+------+------+------+------|   
   * |      |∫›act1|éÁª› ﬁ|±—⁄›  |çU¿›∫ﬁ|      |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | WHM  |      |      |      |ñ¸‹Ÿ¬ |                 
   * `----------------------------------+------.          
   *                                    |≤›Ãﬂ€À|          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [DNC] = LAYOUT( \
    XXXXXXX,  XXXXXXX,   XXXXXXX,   KC_EQUAL,   XXXXXXX,   KC_F1,   XXXXXXX,      \
    XXXXXXX,  XXXXXXX,   KC_SPC,    KC_F,       KC_T,      KC_8,    XXXXXXX,      \
    XXXXXXX,  KC_Z,      KC_LPRN,   LALT(KC_5), KC_AMPR,   XXXXXXX, JS_BUTTON7,   \
    TO(WHM),  XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_ASTR,                          \
                                                           KC_MINUS,              \
                                                                    KC_F12        \
  ),

  /* WHM
   * ,------------------------------------------------.   
   * |∫›act1|      |   W  |Õﬁ∆ø›T|√› ﬂ  |¿πﬁMT |ã~èo  |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |¿πﬁë÷ |¿πﬁãﬂ |Ÿ∞ºØƒﬁ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |º›¥±∞ |åòé¿ñÇ|ê_ë¨ñÇ|      |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | RDM  |      |      |      |≤›ƒﬁ©Ÿ|                 
   * `----------------------------------+------.          
   *                                    |∫›act1|          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [WHM] = LAYOUT( \
    KC_Z,      XXXXXXX,   KC_W,       LALT(KC_EQUAL),LALT(KC_5),    KC_F1,      LALT(KC_4),    \
    XXXXXXX,   XXXXXXX,   KC_SPC,     KC_F,          KC_T,          LALT(KC_8), XXXXXXX,       \
    XXXXXXX,   XXXXXXX,   LALT(KC_0), LALT(KC_6),    LALT(KC_MINUS),XXXXXXX,    JS_BUTTON7,    \
    TO(RDM),   XXXXXXX,   XXXXXXX,    XXXXXXX,       LALT(KC_7),                               \
                                                                    KC_Z,                      \
                                                                                KC_F12         \
  ),

  /* RDM
   * ,------------------------------------------------.   
   * |∫›act1|      |      |±∏æ◊  |      |¿πﬁMT |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |¿πﬁë÷ |¿πﬁãﬂ |Ÿ∞ºØƒﬁ|      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |œ≈Ã®π |åòé¿ñÇ|¥›ŒﬁŸ |±ƒﬁŸ  |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | NIN  |      |      |      |      |                 
   * `----------------------------------+------.          
   *                                    |∫›act1|          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [RDM] = LAYOUT( \
    KC_Z,      XXXXXXX,   XXXXXXX,    LALT(KC_4), XXXXXXX,    KC_F1,      XXXXXXX,       \
    XXXXXXX,   XXXXXXX,   KC_SPC,     KC_F,       KC_T,       LALT(KC_3), XXXXXXX,       \
    XXXXXXX,   XXXXXXX,   LALT(KC_9), KC_ASTR,    LALT(KC_5), LALT(KC_2), JS_BUTTON7,    \
    TO(NIN),   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,                               \
                                                              KC_Z,                      \
                                                                          KC_F12         \
  ),

  /* NIN
   * ,------------------------------------------------.   
   * |      |      |  W   |ƒ©Ÿ∞N |      |¿πﬁMT |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |Space |¿πﬁë÷ |¿πﬁãﬂ |ìVínêl|      |   
   * |------+------+------+------+------+------+------|   
   * |      |Ç©Ç≠ÇÍ|ÇæÇ‹Çµ|±—⁄›  |äàéE  |      |JSPush|   
   * |------+------+------+------+------+-------------'   
   * | RGB  |      |      |      |ñΩêÖ  |                 
   * `----------------------------------+------.          
   *                                    |      |          
   *                                    `------+------.   
   *                                           |  LB  |   
   *                                           `------'   
   */
  [NIN] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   KC_W,       LALT(KC_3), XXXXXXX,    KC_F1,      XXXXXXX,       \
    XXXXXXX,   XXXXXXX,   KC_SPC,     KC_F,       KC_T,       LALT(KC_2), XXXXXXX,       \
    XXXXXXX,   LALT(KC_0),LALT(KC_7), LALT(KC_4), LALT(KC_1), XXXXXXX,    JS_BUTTON7,    \
    TO(RGB),   XXXXXXX,   XXXXXXX,    XXXXXXX,    KC_9,                                  \
                                                              XXXXXXX,                   \
                                                                          KC_F12         \
  ),

  /* RGB
   * ,------------------------------------------------.   
   * |RGBTOG|RGBHUI|RGBHUD|RGBSAI|RGBSAD|RGBVAI|RGBVAD|   
   * |------+------+------+------+------+------+------|   
   * |RGBMOD|RGBRST|Space |¿πﬁë÷ |¿πﬁãﬂ |      |      |   
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
    RGB_TOG,   RGB_HUI,   RGB_HUD,    RGB_SAI,    RGB_SAD,    RGB_VAI,    RGB_VAD,       \
    RGB_MOD,   RGBRST,    KC_SPC,     KC_F,       KC_T,       XXXXXXX,    XXXXXXX,       \
    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    JS_BUTTON7,    \
    TO(SAM),   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,                               \
                                                              XXXXXXX,                   \
                                                                          XXXXXXX        \
  ),

};

void joystick_task(){

		joystick_status.axes[0] = analogReadPin(F4)/4 - 128;
		joystick_status.axes[1] = analogReadPin(D4)/4 - 128;
        send_joystick_packet(&joystick_status);
}
