#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x11(
    KC_F14,  KC_F17,  MO(1),   KC_BSPC, KC_PEQL, KC_PPLS, KC_P9,   KC_P6,   KC_P3,   KC_PDOT, KC_PENT,
    KC_F13,  KC_F16,  KC_F19,  KC_TAB,  KC_PAST, MO(1),   KC_P8,   KC_P5,   KC_P2,   KC_P0,   KC_RALT,
    KC_NLCK, KC_F15,  KC_F18,  KC_ESC,  KC_PSLS, KC_PMNS, KC_P7,   KC_P4,   KC_P1,   KC_P0,   KC_RCTL
  ),

  [1] = LAYOUT_ortho_3x11(
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, KC_NO,   RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ) //,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_NUM_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_COMPOSE)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_KANA)) {

  } else {

  }

}
