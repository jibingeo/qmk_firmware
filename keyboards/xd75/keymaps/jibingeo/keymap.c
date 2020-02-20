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
#define M_QWRT  0 // Mac Qwerty layer
#define L_QWRT  1 // Linux Qwerty layer
#define LNX     2 // Function
#define MAC     3 // Function
#define FN      4 // Function
#define META    5 // Function

#define SFT_SPC     SFT_T(KC_SPC)
#define GUI_UP      GUI_T(KC_UP)
#define CTL_ESC     LCTL_T(KC_ESC)
#define CTL_ENT     LCTL_T(KC_ENT)
#define FN_DOWN     LT(FN, KC_DOWN)
#define SFT_UP      SFT_T(KC_UP)
#define SFT_MINS    SFT_T(KC_MINS)
#define SFT_QUOT    SFT_T(KC_QUOT)
#define ALT_BSLS    ALT_T(KC_BSLS)
#define ALT_TAB     ALT_T(KC_TAB)

#define DF_MAC      DF(M_QWRT)
#define DF_LNX      DF(L_QWRT)

// Linux shortcut
#define CTL_COPY  LCTL(KC_INS)
#define CTL_PST   LSFT(KC_INS)
#define CTL_F     LCTL(KC_F)

// MultiKey

#define SPR_A     LGUI(KC_A)
#define SPR_B     LGUI(KC_B)
#define SPR_C     LGUI(KC_C)
#define SPR_D     LGUI(KC_D)
#define SPR_E     LGUI(KC_E)
#define SPR_F     LGUI(KC_F)
#define SPR_G     LGUI(KC_G)
#define SPR_H     LGUI(KC_H)
#define SPR_I     LGUI(KC_I)
#define SPR_J     LGUI(KC_J)
#define SPR_K     LGUI(KC_K)
#define SPR_L     LGUI(KC_L)
#define SPR_M     LGUI(KC_M)
#define SPR_N     LGUI(KC_N)
#define SPR_O     LGUI(KC_O)
#define SPR_P     LGUI(KC_P)
#define SPR_Q     LGUI(KC_Q)
#define SPR_R     LGUI(KC_R)
#define SPR_S     LGUI(KC_S)
#define SPR_T     LGUI(KC_T)
#define SPR_U     LGUI(KC_U)
#define SPR_V     LGUI(KC_V)
#define SPR_W     LGUI(KC_W)
#define SPR_X     LGUI(KC_X)
#define SPR_Y     LGUI(KC_Y)
#define SPR_Z     LGUI(KC_Z)


#define SPR_1     LGUI(KC_1)
#define SPR_2     LGUI(KC_2)
#define SPR_3     LGUI(KC_3)
#define SPR_4     LGUI(KC_4)
#define SPR_5     LGUI(KC_5)
#define SPR_6     LGUI(KC_6)
#define SPR_7     LGUI(KC_7)
#define SPR_8     LGUI(KC_8)
#define SPR_9     LGUI(KC_9)
#define SPR_0     LGUI(KC_0)

#define SPR_GRV   LGUI(KC_GRV)
#define SPR_ENT   LGUI(KC_ENT)
#define SPR_BSPC  LGUI(KC_BSPC)
#define SPR_BSLS  LGUI(KC_BSLS)
#define SPR_MINS  LGUI(KC_MINS)
#define SPR_EQL   LGUI(KC_EQL)
#define SPR_COMM  LGUI(KC_COMM)
#define SPR_DOT   LGUI(KC_DOT)
#define SPR_SLSH  LGUI(KC_SLSH)
#define SPR_SCLN  LGUI(KC_SCLN)
#define SPR_SPC  LGUI(KC_SPC)

// Macro keycode
enum custom_keycodes {
  GUI_CTL = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [M_QWRT] = LAYOUT_ortho_5x15( /* qwerty */
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_MINS,  KC_BSLS,  KC_EQL,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
    ALT_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,  KC_QUOT,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     ALT_BSLS,
    CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_HOME,  KC_DEL,   KC_PGUP,  KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  CTL_ENT,
    SFT_QUOT, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_END,   KC_UP,    KC_PGDN,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SFT_MINS,
    KC_LCTL,  KC_LGUI,  KC_LALT,  MO(META), KC_LGUI,  SFT_SPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_SPC,   FN_DOWN,  MO(META), KC_RALT,  KC_RGUI,  KC_RCTL
  ),

  [L_QWRT] = LAYOUT_ortho_5x15( /* qwerty */
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  MO(LNX),  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [LNX] = LAYOUT_ortho_5x15( /* qwerty */
    SPR_GRV,  SPR_1,    SPR_2,    SPR_3,    SPR_4,    SPR_5,    _______,  _______,  _______,  SPR_6,    SPR_7,    SPR_8,    SPR_9,    SPR_0,    SPR_BSPC,
    KC_LALT,  SPR_Q,    SPR_W,    SPR_E,    SPR_R,    SPR_T,    _______,  _______,  _______,  SPR_Y,    SPR_U,    SPR_I,    SPR_O,    SPR_P,    SPR_BSLS,
    KC_LCTL,  SPR_A,    SPR_S,    SPR_D,    CTL_F,    SPR_G,    _______,  _______,  _______,  SPR_H,    SPR_J,    SPR_K,    SPR_L,    SPR_SCLN, SPR_ENT,
    KC_LSFT,  SPR_Z,    SPR_X,    CTL_COPY, CTL_PST,  SPR_B,    _______,  _______,  _______,  SPR_N,    SPR_M,    SPR_COMM, SPR_DOT,  SPR_SLSH, SPR_MINS,
    _______,  _______,  _______,  _______,  _______,  SPR_SPC,  _______,  _______,  _______,  SPR_SPC,  _______,  _______,  _______,  _______,  _______
  ),

  [FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F11,   _______,  KC_F12,  KC_F6,     KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,
    _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  _______,  _______,  _______,  _______,  _______,  KC_QUOT,  KC_UNDS,  _______,  _______,  _______,
    _______,  _______,  _______,  KC_LCBR,  KC_RCBR,  _______,  _______,  _______,  _______,  _______,  KC_DQUO,  KC_MINS,  _______,  _______,  _______,
    _______,  _______,  _______,  KC_LABK,  KC_RABK,  _______,  _______,  _______,  _______,  _______,  KC_EQL,   KC_PLUS,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [META] = LAYOUT_ortho_5x15( /* FUNCTION */
    _______,  DF_MAC,   DF_LNX,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPLY,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MNXT,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MPRV,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MSTP,
    RGB_RMOD, RGB_MOD,  RGB_TOG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GUI_CTL:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LCTL);
        rgblight_enable();
        rgblight_setrgb(255, 0, 0);
      } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_LGUI);
        rgblight_disable();
      }
      return false;
  }
  return true;
};
