/*
 * Keyboard: Atreus
 * Keymap:   kalupa
 * Version:  0.1
 *
 * keymap heavily based on replicaJunction. Please see that one for the basics.
 *
 * Changes default layout to QWERTY and makes tweaks to the power usage and timeouts.
 *
 * Makes some of the keys more vim-friendly.
 */

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Note that whatever is set as layer 0 will be the default layer of the keyboard.

enum atreus_layers
  {
   _QWERTY,
   _COLEMAK,
   _CURSOR,
   _NUMBER,
   _FUNCS,
  };

enum atreus_keycodes
  {
   QWERTY = SAFE_RANGE,
   COLEMAK,
   CURSOR,
   NUMBER,
   FUNCS
  };

// Some quick aliases, just to make it look pretty
#define KX_COPY LGUI(KC_C)
#define KX_CUT  LGUI(KC_X)
#define KX_PAST LGUI(KC_V)
#define KX_UNDO LGUI(KC_Z)

#define ALT_ENT ALT_T(KC_ENT)

#define CTL_ESC CTL_T(KC_ESC)
#define CTL_BKS CTL_T(KC_BSPC)

#define HYP_BKS ALL_T(KC_BSPC)
#define HYP_EQL ALL_T(KC_EQL)
#define GUI_ENT GUI_T(KC_ENT)
#define GUI_ESC GUI_T(KC_ESC)
#define SFT_Z   SFT_T(KC_Z)
#define SFT_SL  SFT_T(KC_SLSH)
#define NUMSPC  LT(_NUMBER, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /*
    * qwerty
    *
    * ,----------------------------------.                     ,----------------------------------.
    * |   Q  |   W  |   E  |   R  |   T  |                     |   Y  |   U  |   I  |   O  |   P  |
    * +------+------+------+------+------|                     +------+------+------+------+------|
    * |   A  |   S  |   D  |   F  |   G  |                     |   H  |   J  |   K  |   L  |   ;  |
    * +------+------+------+------+------|                     +------+------+------+------+------|
    * |Z Shft|   X  |   C  |   V  |   B  | ,------.   ,------. |   N  |   M  |   ,  |   .  |/ Shft|
    * +------+------+------+------+------| | Esc  |   | Enter| +------+------+------+------+------|
    * | Esc  |  Tab |  _FN | Shft | Bksp | | Gui  |   | Alt  | |  Sp  |  _EX |   -  |   '  |   =  |
    * | Ctrl |      |      |      | Ctrl | |      |   |      | |  _NU |      |      |      | Hypr |
    * `----------------------------------' `------'   `------' `----------------------------------'
    *
    */
   [_QWERTY] = LAYOUT(KC_Q,    KC_W,   KC_E,  KC_R,    KC_T,                      KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,
                      KC_A,    KC_S,   KC_D,  KC_F,    KC_G,                      KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN,
                      SFT_Z,   KC_X,   KC_C,  KC_V,    KC_B,                      KC_N,   KC_M,  KC_COMM, KC_DOT,  SFT_SL,
                      CTL_ESC, KC_TAB, FUNCS, KC_LSFT, CTL_BKS, GUI_ESC, ALT_ENT, NUMSPC, CURSOR, KC_MINS, KC_QUOT, HYP_EQL),

   /*
    * Colemak-ModDH
    *
    * ,----------------------------------.                     ,----------------------------------.
    * |   Q  |   W  |   F  |   P  |   B  |                     |   J  |   L  |   U  |   Y  |   ;  |
    * +------+------+------+------+------|                     +------+------+------+------+------|
    * |   A  |   R  |   S  |   T  |   G  |                     |   M  |   N  |   E  |   I  |   O  |
    * +------+------+------+------+------|                     +------+------+------+------+------|
    * |Z Shft|   X  |   C  |   D  |   V  | ,------.   ,------. |   K  |   H  |   ,  |   .  |/ Shft|
    * +------+------+------+------+------| | Esc  |   | Enter| +------+------+------+------+------|
    * | Esc  |  Tab |  _FN | Hypr | Bksp | | Gui  |   | Alt  | |  Sp  |  _EX |   -  |   '  |   =  |
    * | Ctrl |      |      |      | Ctrl | |      |   |      | |  _NU |      |      |      | Hypr |
    * `----------------------------------' `------'   `------' `----------------------------------'
    *
    */
   [_COLEMAK] = LAYOUT(KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
                       KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
                       SFT_Z,   KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H,    KC_COMM, KC_DOT,  SFT_SL,
                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ),

   /*
    * Cursor
    *
    * Also note that some dual-role keys are overridden here with their modifiers
    *
    * ,----------------------------------.                     ,----------------------------------.
    * |      |      |      |      |      |                     | PgUp | Home |      |  End |  Del |
    * +------+------+------+------+------|                     +------+------+------+------+------|
    * | Ctrl | Shift|  Alt |  Gui |      |                     | Left | Down |   Up | Right|      |
    * +------+------+------+------+------|                     +------+------+------+------+------|
    * | Shift|  Cut | Copy | Paste|      | ,------.   ,------. | PgDn |      |  Tab |      |      |
    * +------+------+------+------+------| |  Del |   | Enter| +------+------+------+------+------|
    * |      |      |      |      |      | |      |   |      | | Space|XXXXXX|      |      |      |
    * `----------------------------------' `------'   `------' `----------------------------------'
    *
    */
   [_CURSOR] = LAYOUT(_______, _______, _______, _______, _______,                   KC_PGUP, KC_HOME, _______, KC_END,  KC_DEL,
                      KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
                      KC_LSFT, KX_CUT,  KX_COPY, KX_PAST, _______,                   KC_PGDN, _______, KC_TAB,  _______, _______,
                      _______, _______, _______, _______, _______, KC_DEL,  KC_ENT,  KC_SPC,  _______, _______, _______, _______ ),

   /*
    * Numbers and symbols
    *
    * ,----------------------------------.                     ,----------------------------------.
    * |   !  |   @  |   {  |   }  |   &  |                     |   /  |   7  |   8  |   9  |   *  |
    * +------+------+------+------+------|                     +------+------+------+------+------|
    * |   #  |   $  |   (  |   )  |   ~  |                     |   |  |   4  |   5  |   6  |   -  |
    * +------+------+------+------+------|                     +------+------+------+------+------|
    * |   %  |   ^  |   [  |   ]  |   `  | ,------.   ,------. |   \  |   1  |   2  |   3  |   +  |
    * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
    * |      |  _GA |      |      |      | |      |   |      | |XXXXXX|   0  |   .  |   =  |      |
    * `----------------------------------' `------'   `------' `----------------------------------'
    *
    */
   [_NUMBER] = LAYOUT(KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR,                    KC_SLSH, KC_7,    KC_8,   KC_9,   KC_ASTR,
                      KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD,                    KC_PIPE, KC_4,    KC_5,   KC_6,   KC_MINS,
                      KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_GRV,                     KC_BSLS, KC_1,    KC_2,   KC_3,   KC_PLUS,
                      _______, _______, _______, _______, _______, _______,  _______, _______, KC_0,    KC_DOT, KC_EQL, _______ ),

   /*
    * Functions
    *
    * ,----------------------------------.                     ,----------------------------------.
    * | Caps |  F9  |  F10 |  F11 |  F12 |                     | _USER|      |      |      |      |
    * +------+------+------+------+------|                     +------+------+------+------+------|
    * |      |  F5  |  F6  |  F7  |  F8  |                     |      |      |      |      | Vol ^|
    * +------+------+------+------+------|                     +------+------+------+------+------|
    * |      |  F1  |  F2  |  F3  |  F4  | ,------.   ,------. |      |      |      |      | Vol v|
    * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
    * |      |      |XXXXXX|      |      | |      |   |      | |      |      | _CO  |  _QW | RESET|
    * `----------------------------------' `------'   `------' `----------------------------------'
    *
    */
   [_FUNCS]   = LAYOUT(KC_CAPS, KC_F9,   KC_F10,  KC_F11,  KC_F12,                    _______, _______, _______, _______, _______,
                       _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,                     _______, _______, _______, _______, KC_VOLU,
                       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,                     _______, _______, _______, _______, KC_VOLD,
                       _______, _______, _______, _______, _______, _______, _______, _______, _______, COLEMAK, QWERTY,  RESET ),

  };

/*
 * Template
 *
 * ,----------------------------------.                     ,----------------------------------.
 * |      |      |      |      |      |                     |      |      |      |      |      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |      |      |      |      |                     |      |      |      |      |      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |      |      |      |      | ,------.   ,------. |      |      |      |      |      |
 * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
 * |      |      |      |      |      | |      |   |      | |      |      |      |      |      |
 * `----------------------------------' `------'   `------' `----------------------------------'
 *
 */


bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case CURSOR:
      if (record->event.pressed) {
        layer_on(_CURSOR);
        update_tri_layer(_CURSOR, _FUNCS, _NUMBER);
      } else {
        layer_off(_CURSOR);
        update_tri_layer(_CURSOR, _FUNCS, _NUMBER);
      }
      return false;
      break;
    case NUMBER:
      if (record->event.pressed) {
        layer_on(_NUMBER);
        update_tri_layer(_CURSOR, _FUNCS, _NUMBER);
      } else {
        layer_off(_NUMBER);
        update_tri_layer(_CURSOR, _FUNCS, _NUMBER);
      }
      return false;
      break;
    case FUNCS:
      if (record->event.pressed) {
        layer_on(_FUNCS);
        update_tri_layer(_CURSOR, _FUNCS, _NUMBER);
      } else {
        layer_off(_FUNCS);
        update_tri_layer(_CURSOR, _FUNCS, _NUMBER);
      }
      return false;
      break;
  }
  return true;
}
