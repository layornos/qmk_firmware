// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _NEO 0
#define _NEOMOD3 1
#define _NEOMOD4 2
#define _RAISE 3

enum planck_keycodes {
    NEO = SAFE_RANGE,
    NEOMOD3,
    NEOMOD4,
    RAISE
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
};
// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_NEO] = { /* neo2 */
		{ KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
		{ KC_ESC,   KC_X,    KC_V,    KC_L,    KC_C,    KC_W,    KC_TRNS,  KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,    KC_BSPC },
		{ KC_TAB,   KC_U,    KC_I,    KC_A,    KC_E,    KC_O,    KC_TRNS,  KC_S,    KC_N,    KC_R,    KC_T,    KC_D,    KC_Z },
		{ KC_LSFT,  KC_LBRC, KC_SCLN, KC_QUOT, KC_P,    KC_Y,    KC_LSFT,  KC_B,    KC_M,    KC_COMM, KC_DOT,  KC_J,    KC_RSFT },
		{ F(0),     XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_SPC,   NEOMOD4, NEOMOD3, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT }
},

[_NEOMOD3] = {
	  { KC_TRNS,  KC_TRNS,        KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS },
		{ KC_TRNS,  XXXXXXX,        LSFT(KC_SLSH),   RALT(KC_8),    RALT(KC_9),    KC_GRV,        KC_TRNS,  KC_EXLM, KC_NUBS,    LSFT(KC_NUBS),  LSFT(KC_0),    LSFT(KC_6),    XXXXXXX },
		{ KC_TRNS,  RALT(KC_MINS),  LSFT(KC_7),      RALT(KC_7),    RALT(KC_0),    LSFT(KC_RBRC), KC_TRNS,  KC_F12,  KC_TRNS,    KC_UP,          KC_TRNS,       KC_TRNS,       KC_TRNS },
		{ KC_TRNS,  KC_NUHS,        LSFT(KC_4),      RALT(KC_NUBS), RALT(KC_RBRC), LSFT(KC_EQL),  KC_TRNS,  KC_RBRC, LSFT(KC_5), LSFT(KC_2),     LSFT(KC_NUHS), LSFT(KC_COMM), KC_TRNS },
		{ KC_TRNS,  KC_TRNS,        KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS }
},

[_NEOMOD4] = {
		{ KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO   },
		{ KC_NO,  KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, KC_NO,  XXXXXXX,  KC_7,  KC_8,  KC_9,  XXXXXXX, KC_NO },
		{ KC_NO,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_NO,  XXXXXXX,  KC_4,  KC_5,  KC_6,  XXXXXXX, KC_NO },
		{ KC_NO,  XXXXXXX, KC_END,  KC_INS,  KC_ENT,  KC_WBAK, KC_NO,  XXXXXXX,  KC_1,  KC_2,  KC_3,  XXXXXXX, KC_NO },
		{ KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }
},

[_RAISE] = {
		{ KC_MINS,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
		{ KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,  KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS },
		{ KC_TRNS,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_TRNS,  KC_F12,  KC_NUHS, KC_NUBS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, TO(_NEO), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
}


/*
[_TRNS] = {
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},
*/
};



void persistant_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) 	{
        case NEO:
            if (record->event.pressed) {
                persistant_default_layer_set(1UL<<_NEO);
                layer_on(_NEO);
            }
            return false;
            break;
        case NEOMOD3:
            if (record->event.pressed) {
                layer_on(_NEOMOD3);
            } else {
                layer_off(_NEOMOD3);
            }
            return false;
            break;
        case NEOMOD4:
            if (record->event.pressed) {
                layer_on(_NEOMOD4);
            } else {
                layer_off(_NEOMOD4);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
            break;
    }
    return true;
}
