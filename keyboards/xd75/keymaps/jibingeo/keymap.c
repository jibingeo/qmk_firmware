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
#define QWRT    0 // Mac Qwerty layer
#define FN      1 // Function
#define META    2 // Function

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

// Linux shortcut
#define CUT         LCTL(KC_DEL)
#define COPY        LCTL(KC_INS)
#define PSTE        LSFT(KC_INS)
#define FIND        LCTL(KC_F)
#define UNDO        LCTL(KC_Z)
#define REDO        LCTL(KC_Y)
#define SLT_ALL    LCTL(KC_A)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWRT] = LAYOUT_ortho_5x15( /* qwerty */
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_MINS,  KC_BSLS,  KC_EQL,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
    ALT_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,  KC_QUOT,  KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     ALT_BSLS,
    CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_HOME,  KC_DEL,   KC_PGUP,  KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  CTL_ENT,
    SFT_QUOT, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_END,   KC_UP,    KC_PGDN,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SFT_MINS,
    KC_LCTL,  KC_LGUI,  KC_LALT,  MO(FN),   KC_LGUI,  SFT_SPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_SPC,   FN_DOWN,  MO(META), KC_RALT,  KC_RGUI,  KC_RCTL
  ),

  [FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F11,   _______,  KC_F12,  KC_F6,     KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  REDO,     _______,  _______,  _______,  _______,  _______,
    _______,  SLT_ALL,  _______,  _______,  FIND,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  UNDO,     CUT,      COPY,     PSTE,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [META] = LAYOUT_ortho_5x15( /* FUNCTION */
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPLY,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MNXT,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MPRV,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MSTP,
    RGB_RMOD, RGB_MOD,  RGB_TOG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
};
