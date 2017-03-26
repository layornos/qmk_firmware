// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif

#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _NEO 0
#define _NEOMOD3 1
#define _NEOMOD4 2
#define _QWERTY 3
#define _MOUSE 4
#define _RAISE 5
#define _PLOVER 6
#define _NEOMOD3_QWERTY_US 7
#define _ADJUST 16

enum planck_keycodes {
    NEO = SAFE_RANGE,
    NEOMOD3,
    NEOMOD4,
    QWERTY,
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
// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Mouse |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
{KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
{KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
{KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
{KC_LCTL, XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_SPC,  KC_SPC,  KC_RALT, KC_CAPS, TO(_MOUSE), XXXXXXX,   RAISE}
},

/* NEO2 Layout
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   X  |   V  |   L  |   C  |   W  |   K  |   H  |   G  |   F  |   Q  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TAB  |   U  |   I  |   A  |   E  |   O  |   S  |   N  |   R  |   T  |   D  |  Y   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Ü  |   Ö  |   Ä  |   P  |   Z  |   B  |   M  |   ,  |   .  |   J  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | NO   | GUI  | LALT | Shift|    Space    |  L4  |  L3  | LED  | AUDIO|Raise |
 * `-----------------------------------------------------------------------------------'
 */
[_NEO] = {
{KC_ESC,  KC_X,    KC_V,    KC_L,    KC_C,    KC_W,    KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,   KC_BSPC},
{KC_TAB,  KC_U,    KC_I,    KC_A,    KC_E,    KC_O,    KC_S,    KC_N,    KC_R,    KC_T,    KC_D,   KC_Z},
{KC_LSFT, KC_LBRC, KC_SCLN, KC_QUOT, KC_P,    KC_Y,    KC_B,    KC_M,    KC_COMM, KC_DOT,  KC_J,   KC_ENT },
{F(0), XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_SPC,  KC_SPC,  NEOMOD4, NEOMOD3, BACKLIT, AUDIO,  RAISE}
},

/* NEO2 Layer 3
 * ,-----------------------------------------------------------------------------------.
 * | ESC  | NO   |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TAB  |   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |     |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | NO   | GUI  | LALT | Shift|    Space    |  L4  |  L3  | LED  | AUDIO|Raise |
 * `-----------------------------------------------------------------------------------'
 */
[_NEOMOD3] = {
{_______,  XXXXXXX,    LSFT(KC_SLSH),   RALT(KC_8),    RALT(KC_9),    KC_GRV,    KC_EXLM,   KC_NUBS,    LSFT(KC_NUBS),    LSFT(KC_0),    LSFT(KC_6),    _______},
{_______,  RALT(KC_MINS),    LSFT(KC_7),    RALT(KC_7),    RALT(KC_0),    LSFT(KC_RBRC),    LSFT(KC_MINS),    LSFT(KC_8),    LSFT(KC_9),    KC_SLSH,   LSFT(KC_DOT),  RALT(KC_Q)},
{_______, KC_NUHS, LSFT(KC_4), RALT(KC_NUBS), RALT(KC_RBRC),   LSFT(KC_EQL),    KC_RBRC,    LSFT(KC_5),    LSFT(KC_2), LSFT(KC_NUHS),  LSFT(KC_COMM),    _______},
{_______, _______, _______, _______, _______, _______,  _______,  _______,    _______,    _______, _______,   _______}
},

/* NEO2 Layer 4 */
[_NEOMOD4] = {
{_______,  KC_PGUP,    KC_BSPC,    KC_UP,    KC_DEL,    KC_PGDN,    XXXXXXX,   KC_7,    KC_8,    KC_9,    XXXXXXX,    _______},

{_______,  KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_END,    XXXXXXX,    KC_4,    KC_5,    KC_6,    XXXXXXX,    XXXXXXX},

{_______, XXXXXXX, KC_END, KC_INS, KC_ENT,   KC_WBAK,   XXXXXXX,    KC_1,    KC_2, KC_3,  XXXXXXX,    _______},

{_______, _______, _______, _______, _______, _______,  _______,  _______,    _______,    _______, _______,   _______}
},
/* NEO2 Layer 3 if it runs on QWERTY */
[_NEOMOD3_QWERTY_US] = {
{_______,  XXXXXXX,    KC_UNDS,    KC_LBRC,    KC_RBRC,    KC_CIRC,    KC_EXLM,   LSFT(KC_COMM) ,    LSFT(KC_DOT),    KC_EQL,    KC_AMPR,    _______},
{_______,  KC_BSLS,    KC_SLSH,    KC_LCBR,    KC_RCBR,    KC_ASTR,    LSFT(KC_SLSH),    KC_LPRN,    KC_RPRN,    KC_MINS,    LSFT(KC_SCLN),    KC_AT},
{_______, KC_HASH, KC_DLR, KC_PIPE, KC_TILD,    KC_GRV,    KC_PLUS,    KC_PERC,    KC_QUOT, LSFT(KC_QUOT),  KC_SCLN,    _______},
{_______, _______, _______, _______, _______, _______,  _______,  _______,    _______,    _______, _______,   _______}
},

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |  UP  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  LEFT| DOWN | RIGHT|      | WH UP| BTN1 | BTN2 |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |WH DWN| BTN3 | BTN4 |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = {
{XXXXXXX, XXXXXXX, XXXXXXX,    KC_MS_UP,   XXXXXXX,     XXXXXXX, XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX},
{XXXXXXX, XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, XXXXXXX, KC_MS_WH_UP,   KC_MS_BTN1, KC_MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX},
{XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX, KC_MS_WH_DOWN, KC_MS_BTN3, KC_MS_BTN4, XXXXXXX, XXXXXXX, XXXXXXX},
{XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX, XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
{KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
{KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
{_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______},
{_______, TO(_QWERTY), TO(_NEO), _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |TogOut|   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
{KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
{XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
{XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
{EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Adjust (Mouse + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
{_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
{_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  PLOVER,  _______},
{_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
float music_rock[][2]      = SONG(ROCK_A_BYE_BABY);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
                #endif
                persistant_default_layer_set(1UL<<_QWERTY);
                layer_on(_QWERTY);
            }
            return false;
            break;
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
