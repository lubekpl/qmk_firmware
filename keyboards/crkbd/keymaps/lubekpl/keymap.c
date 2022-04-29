/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
    LCTL_T(KC_ESC),    KC_A,    LGUI_T(KC_S),    KC_D,    LCTL_T(KC_F),    LALT_T(KC_G),         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
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
    KC_DEL, XXXXXXX, KC_GRV, KC_QUOTE, KC_LCBR, KC_LBRC,                         KC_RBRC,  KC_RCBR, KC_DQUO, KC_TILD, KC_BSLS,  KC_PIPE,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL, KC_MINUS,                        KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                                          KC_LGUI,   KC_TRNS,  KC_ENT,     KC_BSPC,   MO(4), KC_RALT
  ),

  [3] = LAYOUT_split_3x6_3(
    KC_TILD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
    KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, KC_NO,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,                      KC_LEAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,
                                          KC_DEL,   MO(4),  KC_LGUI,     KC_SPC,   KC_TRNS, KC_RALT
  ),

  [4] = LAYOUT_split_3x6_3(
    RGB_SAI, KC_NO, LCTL(KC_PGUP), KC_NO, LCTL(KC_PGDN), KC_NO,                      RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI,
    RGB_SAD, KC_NO, LCTL(KC_LEFT), KC_NO, LCTL(KC_RGHT), KC_NO,                      KC_NO, TO(0), TO(1), KC_NO, KC_NO, RGB_HUD,
    RESET  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                      KC_MRWD, KC_MFFD, KC_VOLD, KC_VOLU, KC_MPLY, KC_NO,
                                          MO(5),   KC_TRNS,  KC_ENT,     KC_SPC,   KC_TRNS, KC_RALT
  ),

  [5] = LAYOUT_split_3x6_3(
    KC_NO, KC_NO, KC_NO, KC_MS_U, KC_NO, KC_NO,                      KC_NO,KC_NO, KC_NO, KC_NO,KC_NO, KC_ACL0,
    KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,                      KC_NO, KC_BTN1, KC_BTN2, KC_NO, KC_NO, KC_ACL1,
    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ACL2,
                                          KC_TRNS,   KC_TRNS,  KC_ENT,     KC_SPC,   KC_TRNS, KC_RALT
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE

/* LEADER_EXTERNS(); */
/* void matrix_scan_user(void) { */
/*   LEADER_DICTIONARY() { */
/*     leading = false; */
/*     leader_end(); */
/*     // Replace the sequences below with your own sequences. */
/*     SEQ_ONE_KEY(KC_T) { */
/*       // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T */
/*       SEND_STRING(SS_LCTRL(SS_LSFT("t"))); */
/*     } */
/*   } */
/* } */
