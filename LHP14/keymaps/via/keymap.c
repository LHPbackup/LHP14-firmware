#include QMK_KEYBOARD_H
#include "joystick.h"
#include "analog.h"


void render_logo(void) {
    oled_set_cursor(0, 0);
    oled_write_P(lhp_logo, false);
}

void render_layer(void) {
	
	oled_set_cursor(START_COL, START_ROW);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
		
		case 0:
            oled_write_P(PSTR("Profile No.0\n"), false);
//            rgblight_sethsv(0, 255, 90);
            break;
            
        case 1:
            oled_write_P(PSTR("Profile No.1\n"), false);
//            rgblight_sethsv(0, 0, 100);
            break;
            

        case 2:
            oled_write_P(PSTR("Profile No.2\n"), false);
//            rgblight_sethsv(85, 255, 90);
            break;
            

        case 3:
            oled_write_P(PSTR("Profile No.3\n"), false);
//            rgblight_sethsv(127, 170, 100);
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

   [0] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 JS_BUTTON7,\
    TO(1),		 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,				\
    																		 XXXXXXX    \
   ),

   [1] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 JS_BUTTON7,\
    TO(2),	 	XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,				\
    																		 XXXXXXX    \
   ),

   [2] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 JS_BUTTON7,\
    TO(3),	 	XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,				\
    																		 XXXXXXX    \
   ),

   [3] = LAYOUT( \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,   \
    XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 JS_BUTTON7,\
    TO(0),		 XXXXXXX,	 XXXXXXX,	 XXXXXXX,	 XXXXXXX,							\
    															 XXXXXXX,				\
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
