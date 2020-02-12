#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define QWER 2 // QWERTY
#define STEN 3 // STENO

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,         KC_4,    KC_5,    TG(QWER),
  KC_TAB,          KC_QUOT,     KC_COMM,       KC_DOT,       KC_P,    KC_Y,    OSL(SYMB),
  KC_ESC,          KC_A,        KC_O,          KC_E,         KC_U,    KC_I,
  KC_LSFT,         KC_SCLN,     KC_Q,          KC_J,         KC_K,    KC_X,    ALL_T(KC_NO),
  KC_LCTL,         KC_NO,       KC_NO,         ALT_T(KC_NO), KC_LWIN,
                                                                 ALT_T(KC_APP), KC_LGUI,
                                                                                KC_HOME,
                                                         KC_BSPC, OSM(MOD_LSFT), KC_DEL,
  // right hand
  TG(STEN),      KC_6,    KC_7,    KC_8,    KC_9,      KC_0,           KC_NO,
  OSL(SYMB),    KC_F,    KC_G,    KC_C,    KC_R,      KC_L,           KC_SLSH,
                KC_D,    KC_H,    KC_T,    KC_N,      KC_S,           KC_MINUS,
  MEH_T(KC_NO), KC_B,    KC_M,    KC_W,    KC_V,      KC_Z,           KC_RSFT,
                KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,   KC_RCTRL,
  KC_LEFT, KC_RIGHT,
  KC_UP,
  KC_DOWN, KC_ENT, KC_SPC
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
  EPRM,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               RGB_MOD, KC_TRNS,
                                                        KC_TRNS,
                                      RGB_VAD, RGB_VAI, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
  RGB_TOG, RGB_SLD,
  KC_TRNS,
  KC_TRNS, RGB_HUD, RGB_HUI
),
[QWER] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS, KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_TRNS,
  KC_TRNS, KC_A,      KC_S,      KC_D,      KC_F,      KC_G,
  KC_TRNS, KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_TRNS,
  EPRM,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                         KC_TRNS, KC_TRNS,
                                                                  KC_TRNS,
                                                KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
  KC_TRNS, KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,     KC_TRNS,
           KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,  KC_TRNS,
  KC_TRNS, KC_N,      KC_M,      KC_COMMA,  KC_DOT,    KC_BSLS,  KC_TRNS,
                      KC_TRNS,   KC_DOT,    KC_0,      KC_EQL,   KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
[STEN] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS, KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_TRNS,
  KC_TRNS, KC_A,      KC_S,      KC_D,      KC_F,      KC_G,
  KC_TRNS, KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_TRNS,
  EPRM,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                         KC_TRNS, KC_TRNS,
                                                                  KC_TRNS,
                                                KC_C, KC_V, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_BSPC,
  KC_TRNS, KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,     KC_LBRC,
           KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,  KC_QUOT,
  KC_TRNS, KC_N,      KC_M,      KC_COMMA,  KC_DOT,    KC_BSLS,  KC_TRNS,
                      KC_TRNS,   KC_DOT,    KC_0,      KC_EQL,   KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_N, KC_M
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
    }
  }
  return true;
}
