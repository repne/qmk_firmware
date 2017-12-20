// This is the Dvorak-friendly layout for the Mitosis by CarVac (/u/CarVac)
// It features space on the left thumb, shift on the right thumb, a
//  number layer with all the numbers on the home row, and a function layer
//  that provides mouse keys among other things.

#include "mitosis.h"

enum mitosis_layers
{
	_STD,
    _EXT,
    _FN,
    _GW2,
    _GW2_B
	// _NUM,
	// _FN,
    // _FOO,
};


//Mousekeys
#define MOUSEKEY_DELAY 300
#define MOUSEKEY_INTERNAL 50
#define MOUSEKEY_MAX_SPEED 20
#define MOUSEKEY_TIME_TO_MAX 30
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_STD] = {
    {   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P }, 
    {   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT },
    {   KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH },
    {   XXXXXXX, KC_ESC, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, XXXXXXX },
    {   XXXXXXX, TG(_GW2), KC_NO, MO(_EXT), KC_SPC, KC_SPC, MO(_EXT), KC_NO, KC_NO, XXXXXXX}
},

[_EXT] = {
		{   KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN}, 
		{   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SCLN, KC_QUOT, KC_NO, KC_MINS, KC_TRNS}, 
		{   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_NO, KC_EQL, KC_BSLS}, 
		{   XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX}, 
		{   XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX}
},

[_FN] = {
		{   KC_NO, KC_P9, KC_P8, KC_P7, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_NO}, 
		{   KC_NO, KC_P6, KC_P5, KC_P4, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_NO}, 
		{   KC_NO, KC_P3, KC_P2, KC_P1, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_NO}, 
		{   XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_TRNS, KC_TRNS, XXXXXXX}, 
		{   XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX}
},

[_GW2] = {
    {   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P              }, 
    {   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_TRNS           }, 
    {   KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH      }, 
    {   XXXXXXX, KC_ESC, KC_BSPC, KC_SPC, KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX    }, 
    {   XXXXXXX, KC_TRNS, KC_TRNS, MO(_GW2_B), KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX    }
},

[_GW2_B] = {
		{ KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}, 
		{ KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}, 
		{ KC_TAB, KC_I, KC_O, KC_J, KC_K, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}, 
		{ XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX}, 
		{ XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX}
}

/* blank key layout template
 * .--------------------------------------------..--------------------------------------------.
 * |        |        |        |        |        ||        |        |        |        |        |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * |        |        |        |        |        ||        |        |        |        |        |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * |        |        |        |        |        ||        |        |        |        |        |
 * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
 *          |        |        |        |        ||        |        |        |        |
 *          |--------+--------+--------+--------||--------+--------+--------+--------|
 *          |        |        |        |        ||        |        |        |        |
 *          '-----------------------------------''-----------------------------------'
 */

};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    
    switch (layer) {
    	case _STD:
    		set_led_off;
    		break;
        case _EXT:
            set_led_blue;
            break;
        case _GW2:
            set_led_red;
            break;
        default:
            break;
    }
};

