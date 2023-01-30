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
#define RPR 8
#define BRD 9
#define MCH 10
#define DNC 11
#define RDM 12
#define SMN 13
#define BLM 14
#define BLU 15
#define WHM 16
#define SCH 17
#define AST 18
#define SGE 19
#define GAT 20
#define CRA 21
#define GLA 22
#define MRD 23
#define LNC 24
#define PUG 25
#define ROG 26
#define ARC 27
#define THM 28
#define ACN 29
#define CNJ 30
#define RGB 31




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
    oled_set_cursor(0, 3);
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
            
        case RPR:
            oled_write_P(PSTR("REAPER\n"), false);
            rgblight_sethsv(0, 255, 20);
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

        case SGE:
            oled_write_P(PSTR("SAGE\n"), false);
            rgblight_sethsv(100, 100, 90);
            break;
            
        case GAT:
            oled_write_P(PSTR("GATHERER\n"), false);
            rgblight_sethsv(68, 130, 190);
            break;
            
        case CRA:
            oled_write_P(PSTR("CRAFTER\n"), false);
            rgblight_sethsv(198, 130, 190);
            break;
            
        case GLA:
            oled_write_P(PSTR("GLADIATOR\n"), false);
            rgblight_sethsv(127, 170, 80);
            break;
            
        case MRD:
            oled_write_P(PSTR("MARAUDER\n"), false);
            rgblight_sethsv(85, 255, 70);
            break;
        case LNC:
            oled_write_P(PSTR("LANCER\n"), false);
            rgblight_sethsv(170, 255, 160);
            break;
            
        case PUG:
            oled_write_P(PSTR("PUGILIST\n"), false);
            rgblight_sethsv(85, 255, 30);
            break;
        case ROG:
            oled_write_P(PSTR("ROGUE\n"), false);
            rgblight_sethsv(190, 255, 130);
            break;
            
        case ARC:
            oled_write_P(PSTR("ARCHER\n"), false);
            rgblight_sethsv(90, 200, 120);
            break;
        case THM:
            oled_write_P(PSTR("THAUMATURGE\n"), false);
            rgblight_sethsv(68, 15, 30);
            break;
            
        case ACN:
            oled_write_P(PSTR("ARCANIST\n"), false);
            rgblight_sethsv(20, 255, 80);
            break;
        case CNJ:
            oled_write_P(PSTR("CONJURER\n"), false);
            rgblight_sethsv(10, 176, 160);
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
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | GNB  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [DRK] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(GNB),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* GNB
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | WAR  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [GNB] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(WAR),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* WAR
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | PLD  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   [WAR] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(PLD),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* PLD
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | DRG  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [PLD] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(DRG),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* DRG
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
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

   [DRG] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(SAM),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* SAM
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | MNK  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [SAM] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(MNK),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* MNK
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | NIN  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   [MNK] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(NIN),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* NIN
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | RPR  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [NIN] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(RPR),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* RPR
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | BRD  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [RPR] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(BRD),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* BRD
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | MCH  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
  [BRD] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(MCH),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* MCH
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | DNC  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [MCH] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(DNC),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* DNC
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | RDM  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   [DNC] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(RDM),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* RDM
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | SMN  |           
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [RDM] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(SMN),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* SMN
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | BLM  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [SMN] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(BLM),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* BLM
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | BLU  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [BLM] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(BLU),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* BLU
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | WHM  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [BLU] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(WHM),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* WHM
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | SCH  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [WHM] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(SCH),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* SCH
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | AST  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [SCH] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(AST),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* AST
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | SGE  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [AST] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(SGE),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* SGE
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | GAT  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [SGE] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(GAT),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* GAT
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | CRA  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

   [GAT] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(CRA),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* CRA
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | GLA  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [CRA] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(GLA),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* GLA
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | MRD  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [GLA] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(MRD),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* MRD
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | LNC  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [MRD] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(LNC),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* LNC
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | PUG  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [LNC] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(PUG),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* PUG
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | ROG  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [PUG] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(ROG),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* ROG
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | ARC  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [ROG] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(ARC),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* ARC
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | THM  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [ARC] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(THM),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* THM
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | ACN  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   [THM] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(ACN),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* ACN
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | CNJ  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */
   
   [ACN] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(CNJ),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* CNJ
   * ,------------------------------------------------.   
   * |      |      |      |      l      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
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
   
   [CNJ] = LAYOUT( \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   \
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              TO(RGB),   \
                                                           XXXXXXX,   JS_0,      \
                                                                      XXXXXXX    \
   ),


  /* RGB
   * ,------------------------------------------------.   
   * |RGBTOG|RGBHUI|RGBHUD|RGBSAI|RGBSAD|RGBVAI|RGBVAD|   
   * |------+------+------+------+------+------+------|   
   * |RGBMOD|RGBRST|      |      |      |      |      |   
   * |------+------+------+------+------+------+------|   
   * |      |      |      |      |      |      |      |   
   * |------+------+------+------+------+-------------'   
   * |      |      |      |      |      |      | DRK  |   
   * `----------------------------------+-------------.   
   *                                    |      |JSPush|   
   *                                    `------+------.   
   *                                           |      |   
   *                                           `------'   
   */

  [RGB] = LAYOUT( \
    RGB_TOG,    RGB_HUI,   RGB_HUD,    RGB_SAI,    RGB_SAD,     RGB_VAI,    RGB_VAD,   \
    RGB_MOD,    RGBRST,    XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,    XXXXXXX,   \
    XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,    XXXXXXX,   \
    XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,                 TO(DRK),   \
                                                                XXXXXXX,    JS_0,      \
                                                                            XXXXXXX    \
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



