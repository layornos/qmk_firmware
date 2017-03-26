// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _NEO 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_NEO] = {
  {KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X},
  {KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X},
  {KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X},
  {KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X, KC_X}
}};
