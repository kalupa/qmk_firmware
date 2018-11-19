/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"

#define KX_COPY LGUI(KC_C)
#define KX_CUT LGUI(KC_X)
#define KX_PAST LGUI(KC_V)
#define KX_GBKS LGUI(KC_BSPC)

#define ALT_ENT MT(MOD_LALT, KC_ENT)
#define CTL_ESC CTL_T(KC_ESC)
#define CTL_BKS CTL_T(KC_BSPC)
#define HYP_EQL ALL_T(KC_EQL)
#define GUI_BKS GUI_T(KC_BSPC)
#define GUI_ESC GUI_T(KC_ESC)
#define SFT_Z   SFT_T(KC_Z)
#define SFT_SL  SFT_T(KC_SLSH)
#define NUMSPC  LT(_NUMS, KC_SPC)

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
  _QWERTY,
  _NUMS,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  PLOVER,
  EXT_PLV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |   [  |   ]  |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |  Esc | Hypr |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  Esc | XXXX |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Tab  |  Rse | Shft |  Gui | Ctrl | Alt  |Space | Lwr  |   -  |   '  |   =  |
 * `-----------------------------------------------------------------------------------'
 */
  [_QWERTY] = {
    {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,   KC_U,   KC_I,    KC_O,    KC_P   },
    {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ESC,  KC_HYPR, KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN},
    {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    CTL_ESC, KC_ENT,  KC_N,   KC_M,   KC_COMM, KC_DOT,  SFT_SL },
    {CTL_ESC, KC_TAB,  RAISE,   KC_LSFT, CTL_BKS, GUI_ESC, ALT_ENT, NUMSPC, LOWER,  KC_MINS, KC_QUOT, HYP_EQL}
  },

  [_NUMS] = {
    {KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR, _______, _______, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_ASTR},
    {KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD, _______, _______, KC_PIPE, KC_4,    KC_5,    KC_6,    KC_MINS},
    {KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_GRV,  _______, _______, KC_BSLS, KC_1,    KC_2,    KC_3,    KC_PLUS},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_EQL,  _______}
  },


  [_LOWER] = {
    {_______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, _______, KC_END,  KC_DEL},
    {KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______},
    {KC_LSFT, KX_CUT,  KX_COPY, KX_PAST, _______, KC_DEL,  KC_ENT,  KC_PGDN, _______, KC_TAB,  _______, _______},
    {_______, _______, _______, _______, KX_GBKS, _______, _______, _______, _______, _______, _______, _______}
  },


  [_RAISE] = {
    {KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,  KC_BSPC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0},
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_DEL,  KC_BSLS, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC},
    {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
  },

  /* Plover layer (http://opensteno.org)
   * ,-----------------------------------------------------------------------------------.
   * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
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

  /* Adjust (Lower + Raise)
  * ,-----------------------------------------------------------------------------------.
  * |      | Reset|      |      |      |      |      |TermOn|TrmOff|      |      |  Del |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_ADJUST] = {
    {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL},
    {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  PLOVER,  _______, _______, _______},
    {_______, MUV_DE,  MUV_IN,  _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  }

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    break;
  case LOWER:
    if (record->event.pressed) {
      layer_on(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case RAISE:
    if (record->event.pressed) {
      layer_on(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case PLOVER:
    if (record->event.pressed) {
      layer_off(_RAISE);
      layer_off(_LOWER);
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
      layer_off(_PLOVER);
    }
    return false;
    break;
  }
  return true;
}
