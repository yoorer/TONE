/* Copyright 2019 peraneko
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

enum keycodes {
    BASE,
    FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BASE layer
 * ,---------------------------.
 * | Esc  | PGDN |  UP  | PGUP |
 * |------+------+------+------|
 * |  FN  | LEFT | DOWN | RIGHT|
 * `---------------------------'
 */
  [BASE] = LAYOUT(
    KC_ESC, KC_PGDN, KC_UP, KC_PGUP,
    FN, KC_LEFT, KC_DOWN, KC_RIGHT
  ),
/* FN layer
 * ,---------------------------.
 * |CTRL+X|CTRL+C|CTRL+V|CtAl+V|
 * |------+------+------+------|
 * |  FN  | CTRL | GUI  | ALT  |
 * `---------------------------'
 */
  [FN] = LAYOUT(
    C(KC_X), C(KC_C), C(KC_V), C(A(KC_V)),
    KC_NO, KC_LCTRL, KC_LGUI, KC_LALT
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case FN:
      if (record->event.pressed) {
        layer_on(FN);
      }else{
        layer_off(FN);
      }
      return false;
      break;
  }
  return true;
}

/* Rotary encoder settings */
void encoder_update_user(uint16_t index, bool clockwise) {
   if (clockwise) {
        tap_code(KC_WH_U);    //Rotary encoder clockcwise
    } else {
        tap_code(KC_WH_D);  //Rotary encoder Reverse clockcwise
    }
}
