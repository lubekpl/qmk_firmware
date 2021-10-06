/* 
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_split_3x6_3(
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
    LCTL_T(KC_ESC),    KC_A,    LGUI_T(KC_S),    LALT_T(KC_D),    LCTL_T(KC_F),    KC_G,         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                                          KC_LGUI,   MO(2),  KC_ENT,     KC_SPC,   MO(3), KC_RALT
  ),

  [1] = LAYOUT_split_3x6_3(
     KC_TAB,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
     LCTL_T(KC_ESC),  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,   KC_E,    KC_I,    KC_O,    KC_TRNS,
     KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,      KC_K,    KC_H,   KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
                                          KC_LGUI,   MO(2),  KC_ENT,     KC_SPC,   MO(3), KC_RALT
  ),

  [2] = LAYOUT_split_3x6_3(
    KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_LBRC,                         KC_RBRC,  KC_RCBR, KC_LBRC, KC_RBRC, KC_BSLS,  KC_PIPE,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL, KC_MINUS,                        KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                                          KC_LGUI,   KC_TRNS,  KC_ENT,     KC_SPC,   MO(4), KC_RALT
  ),

  [3] = LAYOUT_split_3x6_3(
    KC_TILD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
    KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, KC_NO,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,
                                          KC_LGUI,   MO(4),  KC_ENT,     KC_SPC,   KC_TRNS, KC_RALT
  ),

  [4] = LAYOUT_split_3x6_3(
    RGB_SAI, KC_NO, LCTL(KC_PGUP), KC_NO, LCTL(KC_PGDN), KC_NO,                      RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI,
    RGB_SAD, KC_NO, LCTL(KC_LEFT), KC_NO, LCTL(KC_RGHT), KC_NO,                      KC_NO, TO(0), TO(1), KC_NO, KC_NO, RGB_HUD,
    RESET  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                      KC_MRWD, KC_MFFD, KC_VOLD, KC_VOLU, KC_MPLY, KC_NO,
                                          KC_LGUI,   KC_TRNS,  KC_ENT,     KC_SPC,   KC_TRNS, KC_RALT
  )
};
