#include QMK_KEYBOARD_H
#include "joystick.h"
#include "analog.h"


// Layer(=job) MAX 32jobs available
#define DRK 0
#define GNB 1
#define WAR 2
#define PLD 3
#define DRG 4
#define SAM 5
#define MNK 6
#define NIN 7
#define BRD 8
#define MCH 9
#define DNC 10
#define RDM 11
#define SMN 12
#define BLM 13
#define BLU 14
#define WHM 15
#define SCH 16
#define AST 17
#define GAT 18
#define CRA 19

#define RGB 20





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
		
		case DRK:
            oled_write_P(PSTR("DARK KNIGHT\n"), false);
            rgblight_sethsv(0, 255, 90);
            break;
            
        case GNB:
            oled_write_P(PSTR("GUNBREAKER\n"), false);
            rgblight_sethsv(0, 0, 100);
            break;
            
        case WAR:
            oled_write_P(PSTR("WARRIOR\n"), false);
            rgblight_sethsv(85, 255, 90);
            break;
            
        case PLD:
            oled_write_P(PSTR("PALADIN\n"), false);
            rgblight_sethsv(127, 170, 100);
            break;
            
        case DRG:
            oled_write_P(PSTR("DRAGOON\n"), false);
            rgblight_sethsv(170, 255, 180);
            break;
            
        case SAM:
            oled_write_P(PSTR("SAMURAI\n"), false);
            rgblight_sethsv(0, 255, 180);
            break;
            
        case MNK:
            oled_write_P(PSTR("MONK\n"), false);
            rgblight_sethsv(85, 255, 50);
            break;
            
        case NIN:
            oled_write_P(PSTR("NINJA\n"), false);
            rgblight_sethsv(191, 255, 150);
            break;
            
        case BRD:
            oled_write_P(PSTR("BARD\n"), false);
            rgblight_sethsv(91, 199, 140);
            break;
            
        case MCH:
            oled_write_P(PSTR("MACHINIST\n"), false);
            rgblight_sethsv(68, 15, 150);
            break;
            
        case DNC:
            oled_write_P(PSTR("DANCER\n"), false);
            rgblight_sethsv(213, 255, 180);
            break;
            
        case RDM:
            oled_write_P(PSTR("RED MAGE\n"), false);
            rgblight_sethsv(0, 255, 220);
            break;
            
        case SMN:
            oled_write_P(PSTR("SUMMONER\n"), false);
            rgblight_sethsv(20, 255, 100);
            break;
            
        case BLM:
            oled_write_P(PSTR("BLACK MAGE\n"), false);
            rgblight_sethsv(68, 15, 50);
            break;
            
        case BLU:
            oled_write_P(PSTR("BLUE MAGE\n"), false);
            rgblight_sethsv(170, 255, 200);
            break;
            
        case WHM:
            oled_write_P(PSTR("WHITE MAGE\n"), false);
            rgblight_sethsv(11, 176, 180);
            break;
            
        case SCH:
            oled_write_P(PSTR("SCHOLAR\n"), false);
            rgblight_sethsv(20, 255, 210);
            break;
            
        case AST:
            oled_write_P(PSTR("ASTROLOGIAN\n"), false);
            rgblight_sethsv(127, 255, 180);
            break;

        case GAT:
            oled_write_P(PSTR("GATHERER\n"), false);
            rgblight_sethsv(68, 130, 190);
            break;
            
        case CRA:
            oled_write_P(PSTR("CRAFTER\n"), false);
            rgblight_sethsv(198, 130, 190);
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

  /* DRK
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | GNB  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [DRK] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(GNB),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* GNB
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | WAR  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [GNB] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(WAR),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* WAR
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | PLD  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   [WAR] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(PLD),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* PLD
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | DRG  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [PLD] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(DRG),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* DRG
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
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

   [DRG] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(SAM),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* SAM
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | MNK  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [SAM] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(MNK),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* MNK
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | NIN  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   [MNK] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(NIN),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* NIN
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | BRD  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [NIN] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(BRD),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* BRD
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | MCH  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

  [BRD] = LAYOUT( \
   XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
   XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
   XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(MCH),   \
   XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    														 XXXXXXX,	 JS_BUTTON0,\
    																	 XXXXXXX    \
   ),


  /* MCH
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | DNC  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [MCH] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(DNC),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* DNC
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | RDM  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   [DNC] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(RDM),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* RDM
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | SMK  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [RDM] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(SMN),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* SMN
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | BLM  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [SMN] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(BLM),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* BLM
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | BLU  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [BLM] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(BLU),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),


  /* BLU
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | WHM  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [BLU] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(WHM),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),


  /* WHM
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | SCH  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [WHM] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(SCH),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* SCH
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | AST  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [SCH] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(AST),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* AST
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | GAT  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [AST] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(GAT),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),

  /* GAT
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | CRA  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [GAT] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(CRA),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),


  /* CRA
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | RGB  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   

   [CRA] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 TO(RGB),   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
   ),


  /* RGB
   * ,------------------------------------------------.   
   * |RGBTOG|RGBHUI|RGBHUD|RGBSAI|RGBSAD|RGBVAI|RGBVAD|   
   * |------+------+------+------+------+------+------|   
   * |RGBMOD|RGBRST|      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      | DRK  |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |                 
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

  [RGB] = LAYOUT( \
    RGB_TOG,	 RGB_HUI,   RGB_HUD,    RGB_SAI,    RGB_SAD,     RGB_VAI,    RGB_VAD,   \
    RGB_MOD,	 RGBRST,    XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,    XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,    TO(DRK),   \
    XXXXXXX,	 XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,                            \
    															 XXXXXXX,	 JS_BUTTON0,\
    																		 XXXXXXX    \
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



