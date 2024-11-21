// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _RS 1
#define _LW 2
#define _MO 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,           KC_W,    KC_E,       KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,           KC_S,    KC_D,       KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,           KC_X,    KC_C,       KC_V,    KC_B,    KC_TAB,  MO(_LW), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    LCTL_T(KC_ESC), KC_LALT, HYPR(KC_A), KC_BSPC, KC_LGUI, KC_LSFT, MO(_RS), KC_ENT,  KC_SPC,  KC_BSLS, KC_LBRC, KC_RBRC
  ),

  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_DLRR, KC_PERC,                   KC_PGUP, KC_7,    KC_8,   KC_9, KC_BSPC ,
    KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN,                   KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_HASH, KC_LCBR, KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_1,    KC_2,   KC_3, _______ ,
    _______, ______,  _______, _______, _______, MO(_MO), _______, _______, _______, KC_DOT, KC_0, KC_EQL  ),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   QK_BOOT, _______, _______, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_NO,   KC_VOLD, _______, _______, _______, MO(_MO), _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS ),

  [_MO] = LAYOUT( /* [> MOD <] */
    HYPR(KC_A), _______, LCA(KC_E),    _______,      LCA(KC_T),                       _______, RAG(KC_7),    RAG(KC_8),  RAG(KC_9), _______  ,
    _______,    _______, LCA(KC_D),    LCA(KC_F),    LCA(KC_G),                       _______, RAG(KC_4),    RAG(KC_5),  RAG(KC_6), _______  ,
    _______,    _______, _______,      _______,      _______,   _______, ________,    _______, RAG(KC_1),    RAG(KC_2),  RAG(KC_3), _______  ,
    _______,    _______, LCA(KC_LEFT), LCA(KC_RGHT), _______,   _______, LCA(KC_ENT), _______, LCA(KC_DOWN), LCA(KC_UP), _______,   _______ )
};
