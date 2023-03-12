#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _COLEMAKDH,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOUSE,
  _NUMBERS
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define MOUSE MO(_MOUSE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    KC_Q,             KC_W,         KC_E,    KC_R,         KC_T,                   KC_Y,     LT(_NUMBERS, KC_U),               KC_I,    KC_O,   KC_P,
    LSFT_T(KC_A),     LGUI_T(KC_S), KC_D,    LCTL_T(KC_F), LALT_T(KC_G),           KC_H,     KC_J, KC_K,    KC_L, RSFT_T(KC_SCLN),
    LT(_MOUSE, KC_Z), LCTL_T(KC_X), KC_C,    KC_V,         KC_B,                   KC_N,     KC_M,  KC_COMM,  LCTL_T(KC_DOT), KC_SLSH,
                                             MO(2),        KC_ENT,                 LT(_NUMBERS, KC_SPC),   MO(3)
  ),

  [_COLEMAKDH] = LAYOUT(
     KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                        KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN,
     KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                        KC_M,    KC_N,   KC_E,    KC_I,    KC_O,
     KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,                        KC_K,    KC_H,   KC_COMM, KC_DOT,  KC_SLSH,
                               MO(2),   KC_ENT,                      KC_SPC,  MO(3)
  ),

  [_LOWER] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,    KC_PERC,                  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    XXXXXXX, KC_GRV,  KC_QUOTE, KC_LCBR,   KC_LBRC,                  KC_RBRC, KC_RCBR, KC_DQUO, KC_TILD, KC_BSLS,
    XXXXXXX, KC_TILD, XXXXXXX,  KC_EQL,    KC_MINUS,                 KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                                KC_TRNS,   KC_ENT,                   KC_BSPC, MO(4)
  ),

  [_RAISE] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,                      KC_NO,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                MO(4), KC_LGUI,                      KC_SPC,  KC_TRNS
  ),

  [_ADJUST] = LAYOUT(
    KC_NO, LCTL(KC_PGUP), KC_NO, LCTL(KC_PGDN),  KC_NO,                      RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, QK_BOOT,
    KC_NO, LCTL(KC_LEFT), KC_NO, LCTL(KC_RGHT),  KC_NO,                      KC_NO, TO(0), TO(1), KC_NO, KC_NO,
    KC_NO, KC_NO,         KC_NO, KC_NO,          KC_NO,                      KC_MRWD, KC_MFFD, KC_VOLD, KC_VOLU, KC_MPLY,
                          MO(5), KC_ENT,     KC_SPC,   KC_TRNS
  ),

  [_MOUSE] = LAYOUT(
    KC_NO, KC_NO, KC_MS_U, KC_NO, KC_NO,                              KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,
    KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,                          KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,
    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                      KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                          KC_TRNS,  KC_ENT,     KC_SPC,   KC_TRNS
  ),
  [_NUMBERS] = LAYOUT(
    KC_NO, KC_7, KC_8,  KC_9,  KC_NO,                              KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,
    KC_NO, KC_4, KC_5,  KC_6,  KC_ENT,                          KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,
    KC_NO, KC_1, KC_2,  KC_3,  KC_NO,                      KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_NO, KC_NO,     KC_SPC,   KC_TRNS
  )
};
