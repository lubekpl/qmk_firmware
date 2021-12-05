/* Copyright 2020 Paul James
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

#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _COLEMAKDH,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_5x12(
    KC_GRV,         KC_1,    KC_2,          KC_3,    KC_4,           KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,         KC_Q,    KC_W,          KC_E,    KC_R,           KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LCTL_T(KC_ESC), KC_A,    LGUI_T(KC_S),  KC_D,    LCTL_T(KC_F),   LALT_T(KC_G),           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,        KC_Z,    KC_X,          KC_C,    KC_V,           KC_B,                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL,        LOWER,   KC_LALT,       KC_LGUI, LOWER,          KC_ENT,                 KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_COLEMAKDH] = LAYOUT_ortho_5x12(
    KC_GRV,         KC_1,    KC_2,     KC_3,    KC_4,    KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,  KC_W,    KC_F,     KC_P,    KC_B,    KC_J,              KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    LCTL_T(KC_ESC), KC_A,    KC_R,     KC_S,    KC_T,    KC_G,              KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_TRNS,
    KC_LSFT,  KC_Z, KC_X,    KC_C,     KC_D,    KC_V,    KC_K,              KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
    KC_LCTL,        LOWER,   KC_LALT,  KC_LGUI, LOWER,   KC_ENT,            KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER] = LAYOUT_ortho_5x12(
    KC_GRV,  KC_1,    KC_2,     KC_3,    KC_4,    KC_5,                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_GRV,  KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC,              KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_NO, KC_NO,  KC_NO, KC_LCBR, KC_LBRC,              KC_RBRC, KC_RCBR, KC_LBRC, KC_RBRC, KC_BSLS, KC_PIPE,
    KC_LSFT, KC_NO, KC_NO,  KC_NO,   KC_EQL,  KC_MINUS,             KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
    KC_LCTL, LOWER,   KC_LALT,  KC_LGUI, KC_TRNS,   KC_ENT,               KC_SPC,  ADJUST,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_RAISE] = LAYOUT_ortho_5x12(
    KC_GRV,  KC_1,   KC_2,     KC_3,    KC_4,    KC_5,                 KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_BSPC,
    KC_TILD, KC_1,   KC_2,     KC_3,    KC_4,    KC_5,                 KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_BSPC,
    KC_DEL,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,                KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_NO, KC_NO,
    KC_LSFT, KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,                KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,
    KC_LCTL, LOWER,  KC_LALT,  KC_LGUI, ADJUST,   KC_ENT,               KC_SPC,  KC_TRNS,   KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT
),

[_ADJUST] = LAYOUT_ortho_5x12(
    KC_NO,   KC_NO, KC_NO,         KC_NO,   KC_NO,         KC_NO,                      KC_NO,   KC_NO,       KC_NO,           KC_NO,   KC_NO,   KC_NO,
    RGB_SAI, KC_NO, LCTL(KC_PGUP), KC_NO,   LCTL(KC_PGDN), KC_NO,                      RGB_TOG, RGB_MOD,     KC_NO,         KC_NO, KC_NO, RGB_HUI,
    RGB_SAD, KC_NO, LCTL(KC_LEFT), KC_NO,   LCTL(KC_RGHT), KC_NO,                      KC_NO,   TO(_QWERTY), TO(_COLEMAKDH),  KC_NO,   KC_NO,   RGB_HUD,
    RESET  , KC_NO, KC_NO,         KC_NO,   KC_NO,         KC_NO,                      KC_MRWD, KC_MFFD,     KC_VOLD,         KC_VOLU, KC_MPLY, BL_TOGG,
    KC_LCTL, LOWER, KC_LALT,       KC_LGUI, KC_TRNS,         KC_ENT,                     KC_SPC,  KC_TRNS,       KC_LEFT,         KC_DOWN, KC_UP,   KC_RGHT
)
};
