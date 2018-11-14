/* Copyright 2018 Zach White
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
  [0] = LAYOUT(\
    KC_INS,             KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_F1, \
    KC_DEL,          KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_F2, \
                  KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_F3, \
             KC_LSFT,    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_F4, \
    KC_HOME, KC_END, KC_LCTL,    KC_LGUI, KC_LALT, KC_SPC, KC_F5 \
  )
};