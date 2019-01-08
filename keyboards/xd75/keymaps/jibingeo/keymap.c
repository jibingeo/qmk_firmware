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
#define _QW 0
#define _FN 1
#define _FN2 2
#define _TMUX 3


#define TX_PRFX SS_LCTRL("b")

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

/* QWERTY
 * .---------------------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC      | 1      | 2      | 3      | 4      | 5          | -      | `      | =      | 6          | 7      | 8      | 9      | 0      | BACKSP    |
 * |----------+--------+--------+--------+--------+------------+--------+--------+--------+------------+--------+--------+--------+--------------------|
 * | TAB      | Q      | W      | E      | R      | T          | [      | \      | ]      | Y          | U      | I      | O      | P      | SHT+TAB   |
 * |----------+--------+--------+--------+--------+------------+--------+--------+--------+------------+--------+--------+-----------------+-----------|
 * | CTL/ESC  | A      | S      | D      | F      | G          | (      | '      | )      | H          | J      | K      | L      | ;      | CTL/ENTER |
 * |----------+--------+--------+--------+--------+------------+--------+--------+--------+------------+--------+--------------------------+-----------|
 * | LSHIFT   | Z      | X      | C      | V      | B          | <      | UP     | >      | N          | M      | ,      | .      | /      | RSHIFT    |
 * |----------+--------+--------+--------+--------+------------+--------+--------+--------+------------+--------+--------+--------+--------|-----------|
 * | LCTRL    | LALT   | LGUI   | FN     | FN     | SFT/SPACE  | LEFT   | DOWN   | RIGHT  | SFT/SPACE  | FN     | FN     | RGUI   | RALT   | RCTRL     |
 * '---------------------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_ESC,            KC_1,    KC_2,    KC_3,    KC_4,     KC_5,           KC_MINS, KC_GRV,   KC_EQL,   KC_6,           KC_7,     KC_8,     KC_9,    KC_0,    KC_BSPC       },
  { LT(_TMUX, KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,           KC_LBRC, KC_BSLS,  KC_RBRC,  KC_Y,           KC_U,     KC_I,     KC_O,    KC_P,    S(KC_TAB)     },
  { CTL_T(KC_ESC),     KC_A,    KC_S,    KC_D,    KC_F,     KC_G,           KC_LPRN, KC_QUOT,  KC_RPRN,  KC_H,           KC_J,     KC_K,     KC_L,    KC_SCLN, CTL_T(KC_ENT) },
  { KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,           KC_LABK, KC_UP,    KC_RABK,  KC_N,           KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT       },
  { KC_LCTL,           KC_LALT, KC_LGUI, MO(_FN2), MO(_FN), SFT_T(KC_SPC),  KC_LEFT, KC_DOWN,  KC_RGHT,  SFT_T(KC_SPC),  MO(_FN),  MO(_FN2), KC_RGUI, KC_RALT, KC_RCTL       },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     |        |        |        | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | 1      | 2      | 3      | 4      | 5      |        |        |        | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_FN] = { /* FUNCTION */
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12   },
  { _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______  },
  { _______, _______, KC_GRV,  KC_PIPE, KC_LCBR, KC_RCBR, KC_UNDS, _______, KC_PLUS, KC_LPRN, KC_RPRN, KC_DQUO, KC_TILD, _______, _______  },
  { _______, _______, _______, KC_BSLS, KC_LBRC, KC_RBRC, KC_MINS, _______, KC_EQL,  KC_LABK, KC_RABK, KC_QUOT, _______, _______, _______  },
  { _______, _______, RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, _______, _______, _______, _______, _______, MO(_FN), _______, _______, RESET    },
 },


 [_FN2] = { /* FUNCTION 2 */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },


 [_TMUX] = { /* FUNCTION 2 */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TX_PREV, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, TX_LEFT, TX_DOWN, TX_UP,   TX_RGHT, _______, _______  },
  { _______, _______, _______, TX_NEW, _______, _______, _______, _______, _______, TX_NEXT, _______, _______, _______, _______, _______  },
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
