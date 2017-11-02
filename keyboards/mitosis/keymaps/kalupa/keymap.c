// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "mitosis.h"

// Some quick aliases, just to make it look pretty
#define _______ KC_TRNS
#define KCX_CA  LCTL(KC_LALT)
#define KCX_CS  LCTL(KC_LSFT)
#define KCX_CSA LCTL(LSFT(KC_LALT))
#define KCX_LST LSFT(KC_TAB)

#define KX_COPY LGUI(KC_C)
#define KX_CUT  LGUI(KC_X)
#define KX_PAST LGUI(KC_V)
#define KX_UNDO LGUI(KC_Z)

#define ALT_ENT ALT_T(KC_ENT)

#define CTL_ESC CTL_T(KC_ESC)
#define CTL_BKS CTL_T(KC_BSPC)

#define HYP_BKS ALL_T(KC_BSPC)
#define HYP_ESC ALL_T(KC_ESC)
#define HYP_EQL ALL_T(KC_EQL)

#define GUI_ENT GUI_T(KC_ENT)
#define GUI_ESC GUI_T(KC_ESC)

#define SFT_Z   SFT_T(KC_Z)
#define SFT_SL  SFT_T(KC_SLSH)

enum mitosis_layers
{
	_QW,
	_FN,
	_EX,
	_NU,
	_SHIFTED,
	_FUNCTION,
	_FUNCSHIFT
};

enum mitosis_keycodes
{
  FNKEY = SAFE_RANGE,
  SHIFT
};


// Macro definitions for readability
enum mitosis_macros
{
	VOLU,
	VOLD,
	ESCM
};

#define LONGPRESS_DELAY 150
#define LAYER_TOGGLE_DELAY 300

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*  QWERTY
 * .--------------------------------------------..--------------------------------------------.
 * |   Q    |   W    |   E    |   R    |   T    ||   Y    |   U    |   I    |     O  |   P    |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * |   A    |   S    |   D    |   F    |   G    ||   H    |   J    |   K    |   L    |   ;    |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * | Z Shft |   X    |   C    |   V    |   B    ||   N    |   M    |   ,    |   .    | / Shft |
 * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
 *          |   Tab  |   _FN  |  LAlt  | Esc/Gu ||Spc/_NU |  _EX   |   -    |   '    |
 *          |--------+--------+--------+--------||--------+--------+--------+--------|
 *          |   Esc  |  LCtl  |  Hyer  | Bk/Ctl ||Ent/Alt |        |        |   =    |
 *          '-----------------------------------''-----------------------------------'
 */

  [_QW] = {
    { KC_Q,    KC_W,   KC_E,    KC_R,        KC_T,      KC_Y,            KC_U,    KC_I,    KC_O,    KC_P    },
    { KC_A,    KC_S,   KC_D,    KC_F,        KC_G,      KC_H,            KC_J,    KC_K,    KC_L,    KC_SCLN },
    { SFT_Z,   KC_X,   KC_C,    KC_V,        KC_B,      KC_N,            KC_M,    KC_COMM, KC_DOT,  SFT_SL  },
    { XXXXXXX, KC_TAB, MO(_FN), KC_LALT,     GUI_ESC,   ALT_ENT,         KC_RGUI, KC_MINS, KC_QUOT, XXXXXXX },
    { XXXXXXX, KC_ESC, KC_LCTL, HYPR(KC_NO), CTL_BKS,   LT(_NU, KC_SPC), MO(_EX), KC_RCTL, KC_EQL,  XXXXXXX }
  },

  [_SHIFTED] = { /* Shifted Layer, layered so that tri_layer can be used, or selectively able to modify individual key's shifted behaviour */
    {_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ },
    {_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ },
    {_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ },
    {XXXXXXX, _______, _______, _______, _______,       _______, _______, _______, _______, XXXXXXX },
    {XXXXXXX, _______, _______, _______, _______,       _______, _______, _______, _______, XXXXXXX }
  },


  /*
   * Extend
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
  [_EX] = { /* Extend */
    { _______,  _______, _______, _______, _______, KC_PGUP, KC_HOME, _______, KC_END,  KC_DEL  },
    { KC_LCTL,  KC_LSFT, KC_LALT, KC_LGUI, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______ },
    { KC_LSFT,  KX_CUT,  KX_COPY, KX_PAST, _______, KC_PGDN, _______, KC_TAB,  _______, _______ },
    { XXXXXXX,  _______, _______, _______, KC_DEL,  KC_ENT,  KC_SPC,  _______, _______, XXXXXXX },
    { XXXXXXX,  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX }
  },

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
  [_NU] = { /* Numbers and symbols */
    { KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_ASTR },
    { KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD, KC_PIPE, KC_4,    KC_5,    KC_6,    KC_MINS },
    { KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_GRV,  KC_BSLS, KC_1,    KC_2,    KC_3,    KC_PLUS },
    { XXXXXXX, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_EQL,  XXXXXXX },
    { XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX }
  },

  /*
   * Functions
   *
   * ,----------------------------------.                     ,----------------------------------.
   * | Caps |  F9  |  F10 |  F11 |  F12 |                     | _USER|      |      |      | Vol ^|
   * +------+------+------+------+------|                     +------+------+------+------+------|
   * |      |  F5  |  F6  |  F7  |  F8  |                     |      |      |      |      | Vol v|
   * +------+------+------+------+------|                     +------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  | ,------.   ,------. |      |      |      |      |      |
   * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
   * |      |      |      |XXXXXX|      | |      |   |      | |      |      | _CO  |  _QW |      |
   * `----------------------------------' `------'   `------' `----------------------------------'
   *
   */
  [_FN] = { /* Functions */
    { KC_CAPS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_VOLU },
    { _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, KC_VOLD },
    { XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, XXXXXXX },
    { XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX }
  }
};


/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/* [_MALT] = { /\* Malt Layout, customised for reduced columns (ex: quote and shift locations) *\/ */
/*   {KC_Q,    KC_P,    KC_Y,    KC_C,    KC_B,           KC_V,    KC_M,    KC_U,    KC_Z,    KC_L    }, */
/*   {KC_A,    KC_N,    KC_I,    KC_S,    KC_F,           KC_D,    KC_T,    KC_H,    KC_O,    KC_R    }, */
/*   {KC_COMM, KC_DOT,  KC_J,    KC_G,    KC_SLSH,        KC_SCLN, KC_W,    KC_K,    KC_QUOT, KC_X    }, */
/*   {XXXXXXX, M(VOLU), M(ESCM), KC_TAB,  KC_LCTL,        KC_LALT, KC_ENT,  KC_DEL,  KC_PGUP, XXXXXXX }, */
/*   {XXXXXXX, M(VOLD), KC_LGUI, KC_E,    FNKEY,          SHIFT,   KC_SPC,  KC_BSPC, KC_PGDN, XXXXXXX } */
/* }, */


/* [_SHIFTED] = { /\* Shifted Layer, layered so that tri_layer can be used, or selectively */
/*                                  able to modify individual key's shifted behaviour *\/ */
/*   {_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ }, */
/*   {_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ }, */
/*   {_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ }, */
/*   {XXXXXXX, _______, _______, _______, _______,       _______, _______, _______, _______, XXXXXXX }, */
/*   {XXXXXXX, _______, _______, _______, _______,       _______, _______, _______, _______, XXXXXXX } */
/* }, */



/* [_FUNCTION] = { /\* Function Layer, primary alternative layer featuring numpad on right hand, */
/*                                    cursor keys on left hand, and all symbols*\/ */
/*   {KC_AMPR, KC_PERC, KC_UP,   KC_CIRC, KC_PIPE,       KC_LBRC, KC_7,    KC_8,    KC_9,    KC_MINS }, */
/*   {KC_AT,   KC_LEFT, KC_DOWN, KC_RGHT, KC_HASH,       KC_LPRN, KC_4,    KC_5,    KC_6,    KC_PLUS }, */
/*   {KC_ASTR, KC_UNDS, KC_EXLM, KC_DLR,  KC_BSLS,       KC_LCBR, KC_1,    KC_2,    KC_3,    KC_ENT  }, */
/*   {XXXXXXX, KC_HOME, KC_GRV,  KC_PWR,  _______,       _______, KC_EQL,  KC_TILD, KC_DOT,  XXXXXXX }, */
/*   {XXXXXXX, KC_END,  _______, _______, _______,       _______, KC_0,    _______, KC_PSCR, XXXXXXX } */
/* }, */


/* [_FUNCSHIFT] = { /\* Function Shifted Layer, secondary alternative layer with closing brackets, */
/*                                             and F-keys under their numpad equivalents*\/ */
/*   {_______, _______, _______, _______, _______,       KC_RBRC, KC_F7,   KC_F8,   KC_F9,   KC_F10  }, */
/*   {_______, _______, _______, _______, _______,       KC_RPRN, KC_F4,   KC_F5,   KC_F6,   KC_F11  }, */
/*   {_______, _______, _______, _______, _______,       KC_RCBR, KC_F1,   KC_F2,   KC_F3,   KC_F12  }, */
/*   {XXXXXXX, _______, _______, _______, _______,       _______, _______, _______, _______, XXXXXXX }, */
/*   {XXXXXXX, _______, _______, _______, _______,       _______, _______, _______, _______, XXXXXXX } */
/* } */

/* }; */

const uint16_t PROGMEM fn_actions[] = {

};

static uint16_t key_timer;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
    switch(id) {

      	//switch multiplexing for media, short tap for volume up, long press for play/pause
        case VOLU:
            if (record->event.pressed) {
            	key_timer = timer_read(); // if the key is being pressed, we start the timer.
          	} else { // this means the key was just released, so we can figure out how long it was pressed for (tap or "held down").
            	if (timer_elapsed(key_timer) > LONGPRESS_DELAY) { // LONGPRESS_DELAY being 150ms, the threshhold we pick for counting something as a tap.
                  return MACRO(T(MPLY), END);
                } else {
                  return MACRO(T(VOLU), END);
                }
          	}
          	break;

		//switch multiplexing for media, short tap for volume down, long press for next track
        case VOLD:
            if (record->event.pressed) {
            	key_timer = timer_read();
          	} else {
            	if (timer_elapsed(key_timer) > LONGPRESS_DELAY) {
                  return MACRO(T(MNXT), END);
                } else {
                  return MACRO(T(VOLD), END);
                }
          	}
          	break;

        //switch multiplexing for escape, short tap for escape, long press for context menu
        case ESCM:
            if (record->event.pressed) {
            	key_timer = timer_read();
          	} else {
            	if (timer_elapsed(key_timer) > LONGPRESS_DELAY) {
                  return MACRO(T(APP), END);
                } else {
                  return MACRO(T(ESC), END);
                }
          	}
          	break;

        break;
    }
    return MACRO_NONE;
};

static bool singular_key = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

	uint8_t layer;
  layer = biton32(layer_state);  // get the current layer

  //custom layer handling for tri_layer,
  switch (keycode) {
  case FNKEY:
  	if (record->event.pressed) {
      key_timer = timer_read();
      singular_key = true;
    	layer_on(_FUNCTION);
  	} else {
      if (timer_elapsed(key_timer) < LAYER_TOGGLE_DELAY || !singular_key) {
        layer_off(_FUNCTION);
      }
  	}
    update_tri_layer(_FUNCTION, _SHIFTED, _FUNCSHIFT);
  	return false;
  	break;
  //SHIFT is handled as LSHIFT in the general case
  case SHIFT:
  	if (record->event.pressed) {
      key_timer = timer_read();
      singular_key = true;
    	layer_on(_SHIFTED);
    	register_code(KC_LSFT);
  	} else {
    	if (timer_elapsed(key_timer) < LAYER_TOGGLE_DELAY || !singular_key) {
        layer_off(_SHIFTED);
    	  unregister_code(KC_LSFT);
      }
    }
    update_tri_layer(_FUNCTION, _SHIFTED, _FUNCSHIFT);
  	return false;
  	break;

  //If any other key was pressed during the layer mod hold period,
  //then the layer mod was used momentarily, and should block latching
  default:
    singular_key = false;
    break;
  }

  //FUNCSHIFT has been shifted by the SHIFT handling, some keys need to be excluded
  if (layer == _FUNCSHIFT) {
  	//F1-F12 should be sent as unshifted keycodes,
  	//and ] needs to be unshifted or it is sent as }
  	if ( (keycode >= KC_F1 && keycode <= KC_F12)
  	   || keycode == KC_RBRC ) {
  		if (record->event.pressed) {
              unregister_mods(MOD_LSFT);
          } else {
              register_mods(MOD_LSFT);
          }
  	}
  }

  return true;
};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
    case _QW:
      set_led_off;
      break;
    case _FUNCTION:
      set_led_blue;
      break;
    case _SHIFTED:
      set_led_red;
      break;
    case _FUNCSHIFT:
      set_led_green;
      break;
    default:
      break;
    }
};
