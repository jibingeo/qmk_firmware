/* Copyright 2017 Wunder
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

#include "xd75.h"

// Layer shorthand
#define L0 0 // Qwerty
#define L1 1 // Function
#define L2 2 // Tmux

#define GUI_DOWN GUI_T(KC_DOWN)
#define SFT_SPC SFT_T(KC_SPC)
#define GUI_UP GUI_T(KC_UP)

#define RSFT_UP RSFT_T(KC_UP)
#define RCTL_DOWN RCTL_T(KC_DOWN)
#define LSFT_RIGHT LSFT_T(KC_RIGHT)
#define LCTL_LEFT LCTL_T(KC_LEFT)
#define CTL_ESC LCTL_T(KC_ESC)

#define L1_SPC LT(L1, KC_SPC)
#define L2_LEFT LT(L2, KC_LEFT)
#define L2_RIGHT LT(L2, KC_RIGHT)


#define TX_PRFX SS_LCTRL("b")
#define WN_NEXT LGUI(KC_RIGHT)
#define WN_PREV LGUI(KC_LEFT)

// Macro keycode
enum custom_keycodes {
  TX_NEXT = SAFE_RANGE,
  TX_PREV,
  TX_LEFT,
  TX_RGHT,
  TX_UP,
  TX_DOWN,
  TX_NEW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [L0] = { /* QWERTY */
  { KC_GRV,     KC_1,    KC_2,    KC_3,      KC_4,   KC_5,    KC_MUTE, KC_VOLD, KC_VOLU, KC_6,   KC_7,     KC_8,     KC_9,    KC_0,    KC_BSPC   },
  { KC_TAB,     KC_Q,    KC_W,    KC_E,      KC_R,   KC_T,    KC_GRV,  KC_MPLY, KC_BSLS, KC_Y,   KC_U,     KC_I,     KC_O,    KC_P,    KC_BSLS   },
  { CTL_ESC,    KC_A,    KC_S,    KC_D,      KC_F,   KC_G,    KC_LBRC, KC_MINS, KC_RBRC, KC_H,   KC_J,     KC_K,     KC_L,    KC_SCLN, KC_ENT    },
  { LSFT_RIGHT, KC_Z,    KC_X,    KC_C,      KC_V,   KC_B,    KC_QUOT, KC_UP,   KC_EQL,  KC_N,   KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, RSFT_UP   },
  { L2_LEFT,    KC_LALT, KC_LGUI, LCTL_LEFT, GUI_UP, SFT_SPC, KC_LEFT, KC_DOWN, KC_RGHT, L1_SPC, GUI_DOWN, L2_RIGHT, KC_RGUI, KC_RALT, RCTL_DOWN },
 },

 [L1] = { /* FUNCTION */
  { KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  },
  { WN_NEXT,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______ },
  { WN_PREV,  KC_TILD, KC_EQL,  KC_QUOT, KC_DQUO, KC_MINS, _______, _______, _______, KC_PLUS, KC_UNDS, KC_BSLS, KC_PIPE, KC_COLN, _______ },
  { _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { RGB_RMOD, RGB_MOD, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET   },
 },

 [L2] = { /* FUNCTION 2 */
  { _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TX_PREV, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, TX_LEFT, TX_DOWN, TX_UP,   TX_RGHT, _______, _______  },
  { _______, _______, _______, TX_NEW,  _______, _______, _______, _______, _______, TX_NEXT, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 }
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TX_NEXT:
      if (record->event.pressed) {
        SEND_STRING(TX_PRFX"n");
      }
      break;
    case TX_PREV:
      if (record->event.pressed) {
        SEND_STRING(TX_PRFX"p");
      }
      break;
    case TX_NEW:
      if (record->event.pressed) {
        SEND_STRING(TX_PRFX"c");
      }
      break;
    case TX_LEFT:
      if (record->event.pressed) {
        SEND_STRING(TX_PRFX);
        SEND_STRING(SS_TAP(X_LEFT));
      }
      break;
    case TX_RGHT:
      if (record->event.pressed) {
        SEND_STRING(TX_PRFX);
        SEND_STRING(SS_TAP(X_RIGHT));
      }
      break;
    case TX_UP:
      if (record->event.pressed) {
        SEND_STRING(TX_PRFX);
        SEND_STRING(SS_TAP(X_UP));
      }
      break;
    case TX_DOWN:
      if (record->event.pressed) {
        SEND_STRING(TX_PRFX);
        SEND_STRING(SS_TAP(X_DOWN));
      }
      break;
  }
  return true;
};
