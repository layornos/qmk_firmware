// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.
#include "ortho_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _MOUSE 1
#define _RAISE 2

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    MOUSE,
    RAISE
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
[_QWERTY] = KEYMAP (
KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,  \
KC_LCTL, XXXXXXX, KC_LGUI, KC_LALT, KC_ENT, KC_LSFT,  KC_SPC,  KC_RALT, KC_CAPS, XXXXXXX, TO(_MOUSE), RAISE \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Mouse |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
//[_NEO] = {
//{KC_TAB,  KC_X,    KC_V,    KC_L,    KC_C,    KC_W,    KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,    KC_BSPC},
//{KC_ESC,  KC_U,    KC_I,    KC_A,    KC_E,    KC_O,    KC_S,    KC_N,    KC_R,    KC_T,    KC_D,    KC_Z},
//{KC_LSFT, KC_LBRC, KC_SCLN, KC_QUOT, KC_P,    KC_Y,    KC_B,    KC_M,    KC_COMM, KC_DOT,  KC_J,    KC_ENT },
//{KC_LCTL, BACKLIT, KC_LGUI, KC_LALT, KC_LSFT, KC_SPC,  KC_SPC,  MOD4,    MOD3,    KC_CAPS, AUDIO,   RAISE}
//},
//
//[_NEOMOD3] = {
//{KC_TAB,  KC_X,    KC_V,    KC_L,    KC_C,    KC_W,    KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,    KC_BSPC},
//{KC_ESC,  KC_U,    KC_I,    KC_A,    KC_E,    KC_O,    KC_S,    KC_N,    KC_R,    KC_T,    KC_D,    KC_Z},
//{KC_LSFT, KC_LBRC, KC_SCLN, KC_QUOT, KC_P,    KC_Y,    KC_B,    KC_M,    KC_COMM, KC_DOT,  KC_J,    KC_ENT },
//{KC_LCTL, BACKLIT, KC_LGUI, KC_LALT, KC_LSFT, KC_SPC,  KC_SPC,  MOD4,    MOD3,    KC_CAPS, AUDIO,   RAISE}
//},
//
//[_NEOMOD4] = {
//{KC_TAB,  KC_X,    KC_V,    KC_L,    KC_C,    KC_W,    KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,    KC_BSPC},
//{KC_ESC,  KC_U,    KC_I,    KC_A,    KC_E,    KC_O,    KC_S,    KC_N,    KC_R,    KC_T,    KC_D,    KC_Z},
//{KC_LSFT, KC_LBRC, KC_SCLN, KC_QUOT, KC_P,    KC_Y,    KC_B,    KC_M,    KC_COMM, KC_DOT,  KC_J,    KC_ENT },
//{KC_LCTL, BACKLIT, KC_LGUI, KC_LALT, KC_LSFT, KC_SPC,  KC_SPC,  MOD4,    MOD3,    KC_CAPS, AUDIO,   RAISE}
//},

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = KEYMAP (
  XXXXXXX, XXXXXXX, XXXXXXX,    KC_MS_UP,   XXXXXXX,     XXXXXXX, XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, XXXXXXX, KC_MS_WH_UP,   KC_MS_BTN1, KC_MS_BTN2, XXXXXXX,      XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX, KC_MS_WH_DOWN, KC_MS_BTN3, KC_MS_BTN4, XXXXXXX,      XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX, XXXXXXX,       XXXXXXX,    XXXXXXX,    TO(_QWERTY),  XXXXXXX, XXXXXXX \
),

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
[_RAISE] = KEYMAP (
  KC_LBRC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)

};

void persistant_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                persistant_default_layer_set(1UL<<_QWERTY);
                layer_on(_QWERTY);
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
