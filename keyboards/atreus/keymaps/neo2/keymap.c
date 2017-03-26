// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _NEO 0
#define _NEOMOD3 1
#define _NEOMOD4 2
#define _MOUSE 3
#define _RAISE 4
#define _PLOVER 5
#define _NEOMOD3_QWERTY_US 6
#define _ADJUST 16

enum planck_keycodes {
    NEO = SAFE_RANGE,
    NEOMOD3,
    NEOMOD4,
    PLOVER,
    MOUSE,
    RAISE,
    BACKLIT,
    EXT_PLV,
    AUDIO
};
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_NEO] = {
  {KC_X,    KC_V,    KC_L,    KC_C,    KC_W,   KC_TRNS,  KC_TRNS, KC_K,    KC_H,    KC_G,    KC_F,    KC_Q  },
  {KC_U,    KC_I,    KC_A,    KC_E,    KC_O,   KC_TRNS,  KC_TRNS, KC_S,    KC_N,    KC_R,    KC_T,    KC_D  },
  {KC_LBRC, KC_SCLN, KC_QUOT, KC_P,    KC_Y,   KC_TRNS,  KC_TRNS, KC_B,    KC_M,    KC_COMM, KC_DOT,  KC_J  },
  {F(0),    KC_TAB,  KC_LGUI, KC_LALT, KC_LSFT,KC_BSPC,  KC_ENT,  KC_SPC,  NEOMOD4, NEOMOD3, KC_Z,    RAISE }
},
[_NEOMOD3] = {
  {KC_TRNS, LSFT(KC_SLSH),  RALT(KC_8),  RALT(KC_9),    KC_GRV,        KC_EXLM,       KC_TRNS, KC_TRNS, KC_NUBS,       LSFT(KC_NUBS), LSFT(KC_0),  LSFT(KC_6) },
  {RALT(KC_MINS),  LSFT(KC_7),  RALT(KC_7),    RALT(KC_0),    LSFT(KC_RBRC), KC_TRNS, KC_TRNS, LSFT(KC_MINS), LSFT(KC_8),    LSFT(KC_9),  KC_SLSH,       LSFT(KC_DOT) },
  {KC_NUHS,        LSFT(KC_4),  RALT(KC_NUBS), RALT(KC_RBRC), LSFT(KC_EQL),  KC_TRNS, KC_TRNS, KC_RBRC,       LSFT(KC_5),    LSFT(KC_2), LSFT(KC_NUHS),  LSFT(KC_COMM) },
  {RALT(KC_Q),_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______}
},
[_NEOMOD4] = {
  {KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, _______, _______,  KC_7,   KC_8,    KC_9,    XXXXXXX, XXXXXXX},
  {KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, _______,  KC_4,   KC_5,    KC_6,    XXXXXXX, XXXXXXX},
  {XXXXXXX, KC_END,  KC_INS,  KC_ENT,  KC_WBAK, _______, _______,  KC_1,   KC_2,    KC_3,    XXXXXXX, XXXXXXX},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},
[_RAISE] = {
  {KC_1,    KC_2,   KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0  },
  {KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10},
  {KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,  _______, _______, KC_F12,  _______, _______, _______, _______},
  {_______, RESET,  LSFT(KC_Q), _______, _______, _______, _______, _______, _______, _______, _______, _______}
}};

void persistant_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NEO:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
                #endif
                persistant_default_layer_set(1UL<<_NEO);
                layer_on(_NEO);
            }
            return false;
            break;
        case MOUSE:
            if (record->event.pressed) {
                layer_on(_MOUSE);
            } else {
                layer_off(_MOUSE);
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
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
                #ifdef BACKLIGHT_ENABLE
                    backlight_step();
                #endif
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
        case PLOVER:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    stop_all_notes();
                    PLAY_NOTE_ARRAY(tone_plover, false, 0);
                #endif
                layer_off(_RAISE);
                layer_off(_MOUSE);
                layer_off(_ADJUST);
                layer_on(_PLOVER);
                if (!eeconfig_is_enabled()) {
                    eeconfig_init();
                }
                keymap_config.raw = eeconfig_read_keymap();
                keymap_config.nkro = 1;
                eeconfig_update_keymap(keymap_config.raw);
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
                #endif
                layer_off(_PLOVER);
            }
            return false;
            break;

        case AUDIO:
            #ifdef AUDIO_ENABLE
            music_rock_user();
            #endif
            return false;
            break;
    }
    return true;
}

void matrix_init_user(void) {
#ifdef AUDIO_ENABLE
    startup_user();
#endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

void music_rock_user(void)
{
    PLAY_NOTE_ARRAY(music_rock, false, 0);
}

#endif
