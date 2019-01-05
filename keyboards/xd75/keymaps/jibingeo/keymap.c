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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .---------------------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC      | 1      | 2      | 3      | 4      | 5          | -      | `      | =      | 6          | 7      | 8      | 9      | 0      | BACKSP    |
 * |----------+--------+--------+--------+--------+------------+--------+--------+--------+------------+--------+--------+--------+--------------------|
 * | TAB      | Q      | W      | E      | R      | T          | [      | \      | ]      | Y          | U      | I      | O      | P      | SHT+TAB   |
 * |----------+--------+--------+--------+--------+------------+--------+--------+--------+------------+--------+--------+-----------------+-----------|
 * | CTL/ESC  | A      | S      | D      | F      | G          | HOME   | DEL    | END    | H          | J      | K      | L      | ;      | CTL/ENTER |
 * |----------+--------+--------+--------+--------+------------+--------+--------+--------+------------+--------+--------------------------+-----------|
 * | LSHIFT   | Z      | X      | C      | V      | B          | '      | UP     | '      | N          | M      | ,      | .      | /      | RSHIFT    |
 * |----------+--------+--------+--------+--------+------------+--------+--------+--------+------------+--------+--------+--------+--------|-----------|
 * | LCTRL    | LALT   | LGUI   | FN     | FN     | SFT/SPACE  | LEFT   | DOWN   | RIGHT  | SFT/SPACE  | FN     | FN     | RGUI   | RALT   | RCTRL     |
 * '---------------------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_ESC,        KC_1,    KC_2,    KC_3,    KC_4,     KC_5,           KC_MINS, KC_GRV,  KC_EQL,  KC_6,           KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC       },
  { KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,           KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,           KC_U,     KC_I,    KC_O,    KC_P,    S(KC_TAB)     },
  { CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,     KC_G,           KC_HOME, KC_DEL,  KC_END,  KC_H,           KC_J,     KC_K,    KC_L,    KC_SCLN, CTL_T(KC_ENT) },
  { KC_LSFT      , KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,           KC_QUOT, KC_UP,   KC_QUOT, KC_N,           KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT       },
  { KC_LCTL      , KC_LALT, KC_LGUI, MO(_FN), MO(_FN),  SFT_T(KC_SPC),  KC_LEFT, KC_DOWN, KC_RGHT, SFT_T(KC_SPC),  MO(_FN),  MO(_FN), KC_RGUI, KC_RALT, KC_RCTL       },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_FN] = { /* FUNCTION */
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12   },
  { KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS  },
  { KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______  },
  { KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______  },
  { _______, _______, RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, _______  },
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

bool MOD_DOWN = false;
void matrix_scan_user(void) {
    if(MOD_DOWN) {
        rgblight_setrgb(255, 0, 0);
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LGUI:
    case KC_RGUI:
    case KC_ESC:
    case KC_BSPC:
    case CTL_T(KC_ESC):
    case CTL_T(KC_ENT):
    case KC_LSFT:
    case KC_RSFT:
    case KC_LCTL:
    case KC_RCTL:
    case KC_RALT:
    case KC_LALT:
    case SFT_T(KC_SPC):
      if (record->event.pressed) {
        MOD_DOWN = true;
      } else {
        MOD_DOWN = false;
      }
  }
  return true;
};
