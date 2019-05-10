/* Copyright 2019 alexSt
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
#include "dz60rgb_mine.h"
#include "config.h"

#include "quantum.h"
/*
#ifdef WT_MONO_BACKLIGHT
#include "keyboards/wilba_tech/wt_mono_backlight.h"
#endif
*/
#include "via_api.h"
#include "via_keycodes.h"

#include "dynamic_keymap.h"
#include "raw_hid.h"
#include "timer.h"
#include "tmk_core/common/eeprom.h"
#include "tmk_core/common/print.h"

#if defined(dzrgb60_iso)
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, K_14, J_14, L_14}, {0, K_13, J_13, L_13}, {0, K_12, J_12, L_12},
    {0, K_11, J_11, L_11}, {0, K_10, J_10, L_10}, {0, K_9, J_9, L_9},
    {0, K_8, J_8, L_8},    {0, K_7, J_7, L_7},    {0, K_6, J_6, L_6},
    {0, K_5, J_5, L_5},    {0, K_4, J_4, L_4},    {0, K_3, J_3, L_3},
    {0, K_2, J_2, L_2},    {0, K_1, J_1, L_1},    {0, H_15, G_15, I_15},
    {0, H_13, G_13, I_13}, {0, H_12, G_12, I_12}, {0, H_11, G_11, I_11},
    {0, H_10, G_10, I_10}, {0, H_9, G_9, I_9},    {0, H_8, G_8, I_8},
    {0, H_7, G_7, I_7},    {0, H_6, G_6, I_6},    {0, H_5, G_5, I_5},
    {0, H_4, G_4, I_4},    {0, H_3, G_3, I_3},    {0, H_2, G_2, I_2},
    {0, H_1, G_1, I_1},    {0, B_14, A_14, C_14}, {0, E_12, D_12, F_12},
    {0, E_11, D_11, F_11}, {0, E_10, D_10, F_10}, {0, E_9, D_9, F_9},
    {0, E_8, D_8, F_8},    {0, E_7, D_7, F_7},    {0, E_6, D_6, F_6},
    {0, E_5, D_5, F_5},    {0, E_4, D_4, F_4},    {0, E_3, D_3, F_3},
    {0, E_2, D_2, F_2},    {0, E_1, D_1, F_1},    {0, B_13, A_13, C_13},
    {0, B_11, A_11, C_11}, {0, B_10, A_10, C_10}, {0, B_9, A_9, C_9},
    {0, B_8, A_8, C_8},    {0, B_7, A_7, C_7},    {0, B_6, A_6, C_6},
    {0, B_5, A_5, C_5},    {0, B_4, A_4, C_4},    {0, B_3, A_3, C_3},
    {0, B_2, A_2, C_2},    {0, B_1, A_1, C_1},    {0, B_15, A_15, C_15},
    {0, E_13, D_13, F_13}, {0, B_12, A_12, C_12}, {0, E_15, D_15, F_15},
    {0, B_16, A_16, C_16}, {0, E_16, D_16, F_16}, {0, H_16, G_16, I_16},
    {0, K_16, J_16, L_16},
};

rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {
    {{0 | (13 << 4)}, {16 * 13.5, 0}, 1},
    {{0 | (12 << 4)}, {16 * 12, 0}, 1},
    {{0 | (11 << 4)}, {16 * 11, 0}, 1},
    {{0 | (10 << 4)}, {16 * 10, 0}, 1},
    {{0 | (9 << 4)}, {16 * 9, 0}, 1},
    {{0 | (8 << 4)}, {16 * 8, 0}, 1},
    {{0 | (7 << 4)}, {16 * 7, 0}, 1},
    {{0 | (6 << 4)}, {16 * 6, 0}, 1},
    {{0 | (5 << 4)}, {16 * 5, 0}, 1},
    {{0 | (4 << 4)}, {16 * 4, 0}, 1},
    {{0 | (3 << 4)}, {16 * 3, 0}, 1},
    {{0 | (2 << 4)}, {16 * 2, 0}, 1},
    {{0 | (1 << 4)}, {16 * 1, 0}, 1},
    {{0 | (0 << 4)}, {16 * 0, 0}, 1},
    {{2 | (13 << 4)}, {16 * 13.75, 24}, 1},
    {{1 | (12 << 4)}, {16 * 12.5, 16}, 4},
    {{1 | (11 << 4)}, {16 * 11.5, 16}, 4},
    {{1 | (10 << 4)}, {16 * 10.5, 16}, 4},
    {{1 | (9 << 4)}, {16 * 9.5, 16}, 4},
    {{1 | (8 << 4)}, {16 * 8.5, 16}, 4},
    {{1 | (7 << 4)}, {16 * 7.5, 16}, 4},
    {{1 | (6 << 4)}, {16 * 6.5, 16}, 4},
    {{1 | (5 << 4)}, {16 * 5.5, 16}, 4},
    {{1 | (4 << 4)}, {16 * 4.5, 16}, 4},
    {{1 | (3 << 4)}, {16 * 3.5, 16}, 4},
    {{1 | (2 << 4)}, {16 * 2.5, 16}, 4},
    {{1 | (1 << 4)}, {16 * 1.5, 16}, 4},
    {{1 | (0 << 4)}, {16 * 0.25, 16}, 1},
    {{1 | (13 << 4)}, {16 * 12.75, 32}, 1},
    {{2 | (11 << 4)}, {16 * 11.75, 32}, 4},
    {{2 | (10 << 4)}, {16 * 10.75, 32}, 4},
    {{2 | (9 << 4)}, {16 * 9.75, 32}, 4},
    {{2 | (8 << 4)}, {16 * 8.75, 32}, 4},
    {{2 | (7 << 4)}, {16 * 7.75, 32}, 4},
    {{2 | (6 << 4)}, {16 * 6.75, 32}, 4},
    {{2 | (5 << 4)}, {16 * 5.75, 32}, 4},
    {{2 | (4 << 4)}, {16 * 4.75, 32}, 4},
    {{2 | (3 << 4)}, {16 * 3.75, 32}, 4},
    {{2 | (2 << 4)}, {16 * 2.75, 32}, 4},
    {{2 | (1 << 4)}, {16 * 1.75, 32}, 4},
    {{2 | (0 << 4)}, {16 * 0.375, 32}, 1},
    {{3 | (11 << 4)}, {16 * 13.125, 48}, 1},
    {{3 | (10 << 4)}, {16 * 11.25, 48}, 4},
    {{3 | (9 << 4)}, {16 * 10.25, 48}, 4},
    {{3 | (8 << 4)}, {16 * 9.25, 48}, 4},
    {{3 | (7 << 4)}, {16 * 8.25, 48}, 4},
    {{3 | (6 << 4)}, {16 * 7.25, 48}, 4},
    {{3 | (5 << 4)}, {16 * 6.25, 48}, 4},
    {{3 | (4 << 4)}, {16 * 5.25, 48}, 4},
    {{3 | (3 << 4)}, {16 * 4.25, 48}, 4},
    {{3 | (2 << 4)}, {16 * 3.25, 48}, 4},
    {{3 | (1 << 4)}, {16 * 1.25, 48}, 4},
    {{3 | (0 << 4)}, {16 * 0.625, 48}, 1},
    {{4 | (13 << 4)}, {16 * 13.875, 64}, 1},
    {{4 | (11 << 4)}, {16 * 12.625, 64}, 1},
    {{4 | (10 << 4)}, {16 * 11.375, 64}, 1},
    {{4 | (9 << 4)}, {16 * 10.125, 64}, 1},
    {{4 | (5 << 4)}, {16 * 6.375, 64}, 4},
    {{4 | (2 << 4)}, {16 * 2.625, 64}, 1},
    {{4 | (1 << 4)}, {16 * 1.375, 64}, 1},
    {{4 | (0 << 4)}, {16 * 0.125, 64}, 1},
};
#elif defined(dzrgb60_hhkb)
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, H_15, G_15, I_15}, {0, K_14, J_14, L_14}, {0, K_13, J_13, L_13},
    {0, K_12, J_12, L_12}, {0, K_11, J_11, L_11}, {0, K_10, J_10, L_10},
    {0, K_9, J_9, L_9},    {0, K_8, J_8, L_8},    {0, K_7, J_7, L_7},
    {0, K_6, J_6, L_6},    {0, K_5, J_5, L_5},    {0, K_4, J_4, L_4},
    {0, K_3, J_3, L_3},    {0, K_2, J_2, L_2},    {0, K_1, J_1, L_1},
    {0, H_14, G_14, I_14}, {0, H_13, G_13, I_13}, {0, H_12, G_12, I_12},
    {0, H_11, G_11, I_11}, {0, H_10, G_10, I_10}, {0, H_9, G_9, I_9},
    {0, H_8, G_8, I_8},    {0, H_7, G_7, I_7},    {0, H_6, G_6, I_6},
    {0, H_5, G_5, I_5},    {0, H_4, G_4, I_4},    {0, H_3, G_3, I_3},
    {0, H_2, G_2, I_2},    {0, H_1, G_1, I_1},    {0, E_14, D_14, F_14},
    {0, E_12, D_12, F_12}, {0, E_11, D_11, F_11}, {0, E_10, D_10, F_10},
    {0, E_9, D_9, F_9},    {0, E_8, D_8, F_8},    {0, E_7, D_7, F_7},
    {0, E_6, D_6, F_6},    {0, E_5, D_5, F_5},    {0, E_4, D_4, F_4},
    {0, E_3, D_3, F_3},    {0, E_2, D_2, F_2},    {0, E_1, D_1, F_1},
    {0, B_14, A_14, C_14}, {0, B_13, A_13, C_13}, {0, B_11, A_11, C_11},
    {0, B_10, A_10, C_10}, {0, B_9, A_9, C_9},    {0, B_8, A_8, C_8},
    {0, B_7, A_7, C_7},    {0, B_6, A_6, C_6},    {0, B_5, A_5, C_5},
    {0, B_4, A_4, C_4},    {0, B_3, A_3, C_3},    {0, B_2, A_2, C_2},
    {0, B_1, A_1, C_1},    {0, B_15, A_15, C_15}, {0, E_13, D_13, F_13},
    {0, B_12, A_12, C_12}, {0, B_16, A_16, C_16}, {0, E_16, D_16, F_16},
    {0, H_16, G_16, I_16}, {0, K_16, J_16, L_16},
};

rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {
    {{2 | (12 << 4)}, {16 * 14, 0}, 1},
    {{0 | (13 << 4)}, {16 * 13, 0}, 1},
    {{0 | (12 << 4)}, {16 * 12, 0}, 1},
    {{0 | (11 << 4)}, {16 * 11, 0}, 1},
    {{0 | (10 << 4)}, {16 * 10, 0}, 1},
    {{0 | (9 << 4)}, {16 * 9, 0}, 1},
    {{0 | (8 << 4)}, {16 * 8, 0}, 1},
    {{0 | (7 << 4)}, {16 * 7, 0}, 1},
    {{0 | (6 << 4)}, {16 * 6, 0}, 1},
    {{0 | (5 << 4)}, {16 * 5, 0}, 1},
    {{0 | (4 << 4)}, {16 * 4, 0}, 1},
    {{0 | (3 << 4)}, {16 * 3, 0}, 1},
    {{0 | (2 << 4)}, {16 * 2, 0}, 1},
    {{0 | (1 << 4)}, {16 * 1, 0}, 1},
    {{0 | (0 << 4)}, {16 * 0, 0}, 1},
    {{1 | (13 << 4)}, {16 * 13.75, 16}, 1},
    {{1 | (12 << 4)}, {16 * 12.5, 16}, 4},
    {{1 | (11 << 4)}, {16 * 11.5, 16}, 4},
    {{1 | (10 << 4)}, {16 * 10.5, 16}, 4},
    {{1 | (9 << 4)}, {16 * 9.5, 16}, 4},
    {{1 | (8 << 4)}, {16 * 8.5, 16}, 4},
    {{1 | (7 << 4)}, {16 * 7.5, 16}, 4},
    {{1 | (6 << 4)}, {16 * 6.5, 16}, 4},
    {{1 | (5 << 4)}, {16 * 5.5, 16}, 4},
    {{1 | (4 << 4)}, {16 * 4.5, 16}, 4},
    {{1 | (3 << 4)}, {16 * 3.5, 16}, 4},
    {{1 | (2 << 4)}, {16 * 2.5, 16}, 4},
    {{1 | (1 << 4)}, {16 * 1.5, 16}, 4},
    {{1 | (0 << 4)}, {16 * 0.25, 16}, 1},
    {{2 | (13 << 4)}, {16 * 12.75, 32}, 1},
    {{2 | (11 << 4)}, {16 * 11.75, 32}, 4},
    {{2 | (10 << 4)}, {16 * 10.75, 32}, 4},
    {{2 | (9 << 4)}, {16 * 9.75, 32}, 4},
    {{2 | (8 << 4)}, {16 * 8.75, 32}, 4},
    {{2 | (7 << 4)}, {16 * 7.75, 32}, 4},
    {{2 | (6 << 4)}, {16 * 6.75, 32}, 4},
    {{2 | (5 << 4)}, {16 * 5.75, 32}, 4},
    {{2 | (4 << 4)}, {16 * 4.75, 32}, 4},
    {{2 | (3 << 4)}, {16 * 3.75, 32}, 4},
    {{2 | (2 << 4)}, {16 * 2.75, 32}, 4},
    {{2 | (1 << 4)}, {16 * 1.75, 32}, 4},
    {{2 | (0 << 4)}, {16 * 0.375, 32}, 1},
    {{3 | (13 << 4)}, {16 * 14, 48}, 1},
    {{3 | (11 << 4)}, {16 * 12.625, 48}, 4},
    {{3 | (10 << 4)}, {16 * 11.25, 48}, 4},
    {{3 | (9 << 4)}, {16 * 10.25, 48}, 4},
    {{3 | (8 << 4)}, {16 * 9.25, 48}, 4},
    {{3 | (7 << 4)}, {16 * 8.25, 48}, 4},
    {{3 | (6 << 4)}, {16 * 7.25, 48}, 4},
    {{3 | (5 << 4)}, {16 * 6.25, 48}, 4},
    {{3 | (4 << 4)}, {16 * 5.25, 48}, 4},
    {{3 | (3 << 4)}, {16 * 4.25, 48}, 4},
    {{3 | (2 << 4)}, {16 * 3.25, 48}, 4},
    {{3 | (1 << 4)}, {16 * 1.25, 48}, 4},
    {{3 | (0 << 4)}, {16 * 0.625, 48}, 1},
    {{4 | (13 << 4)}, {16 * 13.625, 64}, 1},
    {{4 | (11 << 4)}, {16 * 12.375, 64}, 1},
    {{4 | (10 << 4)}, {16 * 11.125, 64}, 1},
    {{4 | (5 << 4)}, {16 * 7, 64}, 4},
    {{4 | (2 << 4)}, {16 * 2.875, 64}, 1},
    {{4 | (1 << 4)}, {16 * 1.625, 64}, 1},
    {{4 | (0 << 4)}, {16 * 0.375, 64}, 1},
};
#elif defined(dzrgb60_hhkb_iso)
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, H_15, G_15, I_15}, {0, K_14, J_14, L_14}, {0, K_13, J_13, L_13},
    {0, K_12, J_12, L_12}, {0, K_11, J_11, L_11}, {0, K_10, J_10, L_10},
    {0, K_9, J_9, L_9},    {0, K_8, J_8, L_8},    {0, K_7, J_7, L_7},
    {0, K_6, J_6, L_6},    {0, K_5, J_5, L_5},    {0, K_4, J_4, L_4},
    {0, K_3, J_3, L_3},    {0, K_2, J_2, L_2},    {0, K_1, J_1, L_1},
    {0, K_15, J_15, L_15}, {0, H_13, G_13, I_13}, {0, H_12, G_12, I_12},
    {0, H_11, G_11, I_11}, {0, H_10, G_10, I_10}, {0, H_9, G_9, I_9},
    {0, H_8, G_8, I_8},    {0, H_7, G_7, I_7},    {0, H_6, G_6, I_6},
    {0, H_5, G_5, I_5},    {0, H_4, G_4, I_4},    {0, H_3, G_3, I_3},
    {0, H_2, G_2, I_2},    {0, H_1, G_1, I_1},    {0, E_15, D_15, F_15},
    {0, E_12, D_12, F_12}, {0, E_11, D_11, F_11}, {0, E_10, D_10, F_10},
    {0, E_9, D_9, F_9},    {0, E_8, D_8, F_8},    {0, E_7, D_7, F_7},
    {0, E_6, D_6, F_6},    {0, E_5, D_5, F_5},    {0, E_4, D_4, F_4},
    {0, E_3, D_3, F_3},    {0, E_2, D_2, F_2},    {0, E_1, D_1, F_1},
    {0, B_14, A_14, C_14}, {0, B_13, A_13, C_13}, {0, B_11, A_11, C_11},
    {0, B_10, A_10, C_10}, {0, B_9, A_9, C_9},    {0, B_8, A_8, C_8},
    {0, B_7, A_7, C_7},    {0, B_6, A_6, C_6},    {0, B_5, A_5, C_5},
    {0, B_4, A_4, C_4},    {0, B_3, A_3, C_3},    {0, B_2, A_2, C_2},
    {0, B_1, A_1, C_1},    {0, B_15, A_15, C_15}, {0, E_13, D_13, F_13},
    {0, B_12, A_12, C_12}, {0, B_16, A_16, C_16}, {0, E_16, D_16, F_16},
    {0, H_16, G_16, I_16}, {0, K_16, J_16, L_16},
};

rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {
    {{2 | (12 << 4)}, {16 * 14, 0}, 1},
    {{0 | (13 << 4)}, {16 * 13, 0}, 1},
    {{0 | (12 << 4)}, {16 * 12, 0}, 1},
    {{0 | (11 << 4)}, {16 * 11, 0}, 1},
    {{0 | (10 << 4)}, {16 * 10, 0}, 1},
    {{0 | (9 << 4)}, {16 * 9, 0}, 1},
    {{0 | (8 << 4)}, {16 * 8, 0}, 1},
    {{0 | (7 << 4)}, {16 * 7, 0}, 1},
    {{0 | (6 << 4)}, {16 * 6, 0}, 1},
    {{0 | (5 << 4)}, {16 * 5, 0}, 1},
    {{0 | (4 << 4)}, {16 * 4, 0}, 1},
    {{0 | (3 << 4)}, {16 * 3, 0}, 1},
    {{0 | (2 << 4)}, {16 * 2, 0}, 1},
    {{0 | (1 << 4)}, {16 * 1, 0}, 1},
    {{0 | (0 << 4)}, {16 * 0, 0}, 1},
    {{2 | (13 << 4)}, {16 * 13.75, 24}, 1},
    {{1 | (12 << 4)}, {16 * 12.5, 16}, 4},
    {{1 | (11 << 4)}, {16 * 11.5, 16}, 4},
    {{1 | (10 << 4)}, {16 * 10.5, 16}, 4},
    {{1 | (9 << 4)}, {16 * 9.5, 16}, 4},
    {{1 | (8 << 4)}, {16 * 8.5, 16}, 4},
    {{1 | (7 << 4)}, {16 * 7.5, 16}, 4},
    {{1 | (6 << 4)}, {16 * 6.5, 16}, 4},
    {{1 | (5 << 4)}, {16 * 5.5, 16}, 4},
    {{1 | (4 << 4)}, {16 * 4.5, 16}, 4},
    {{1 | (3 << 4)}, {16 * 3.5, 16}, 4},
    {{1 | (2 << 4)}, {16 * 2.5, 16}, 4},
    {{1 | (1 << 4)}, {16 * 1.5, 16}, 4},
    {{1 | (0 << 4)}, {16 * 0.25, 16}, 1},
    {{1 | (13 << 4)}, {16 * 12.75, 32}, 1},
    {{2 | (11 << 4)}, {16 * 11.75, 32}, 4},
    {{2 | (10 << 4)}, {16 * 10.75, 32}, 4},
    {{2 | (9 << 4)}, {16 * 9.75, 32}, 4},
    {{2 | (8 << 4)}, {16 * 8.75, 32}, 4},
    {{2 | (7 << 4)}, {16 * 7.75, 32}, 4},
    {{2 | (6 << 4)}, {16 * 6.75, 32}, 4},
    {{2 | (5 << 4)}, {16 * 5.75, 32}, 4},
    {{2 | (4 << 4)}, {16 * 4.75, 32}, 4},
    {{2 | (3 << 4)}, {16 * 3.75, 32}, 4},
    {{2 | (2 << 4)}, {16 * 2.75, 32}, 4},
    {{2 | (1 << 4)}, {16 * 1.75, 32}, 4},
    {{2 | (0 << 4)}, {16 * 0.375, 32}, 1},
    {{3 | (13 << 4)}, {16 * 14, 48}, 1},
    {{3 | (11 << 4)}, {16 * 12.625, 48}, 4},
    {{3 | (10 << 4)}, {16 * 11.25, 48}, 4},
    {{3 | (9 << 4)}, {16 * 10.25, 48}, 4},
    {{3 | (8 << 4)}, {16 * 9.25, 48}, 4},
    {{3 | (7 << 4)}, {16 * 8.25, 48}, 4},
    {{3 | (6 << 4)}, {16 * 7.25, 48}, 4},
    {{3 | (5 << 4)}, {16 * 6.25, 48}, 4},
    {{3 | (4 << 4)}, {16 * 5.25, 48}, 4},
    {{3 | (3 << 4)}, {16 * 4.25, 48}, 4},
    {{3 | (2 << 4)}, {16 * 3.25, 48}, 4},
    {{3 | (1 << 4)}, {16 * 1.25, 48}, 4},
    {{3 | (0 << 4)}, {16 * 0.625, 48}, 1},
    {{4 | (13 << 4)}, {16 * 13.625, 64}, 1},
    {{4 | (11 << 4)}, {16 * 12.375, 64}, 1},
    {{4 | (10 << 4)}, {16 * 11.125, 64}, 1},
    {{4 | (5 << 4)}, {16 * 7, 64}, 4},
    {{4 | (2 << 4)}, {16 * 2.875, 64}, 1},
    {{4 | (1 << 4)}, {16 * 1.625, 64}, 1},
    {{4 | (0 << 4)}, {16 * 0.375, 64}, 1},
};
#elif defined(dzrgb60_ansi)
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, K_14, J_14, L_14}, {0, K_13, J_13, L_13}, {0, K_12, J_12, L_12},
    {0, K_11, J_11, L_11}, {0, K_10, J_10, L_10}, {0, K_9, J_9, L_9},
    {0, K_8, J_8, L_8},    {0, K_7, J_7, L_7},    {0, K_6, J_6, L_6},
    {0, K_5, J_5, L_5},    {0, K_4, J_4, L_4},    {0, K_3, J_3, L_3},
    {0, K_2, J_2, L_2},    {0, K_1, J_1, L_1},    {0, H_14, G_14, I_14},
    {0, H_13, G_13, I_13}, {0, H_12, G_12, I_12}, {0, H_11, G_11, I_11},
    {0, H_10, G_10, I_10}, {0, H_9, G_9, I_9},    {0, H_8, G_8, I_8},
    {0, H_7, G_7, I_7},    {0, H_6, G_6, I_6},    {0, H_5, G_5, I_5},
    {0, H_4, G_4, I_4},    {0, H_3, G_3, I_3},    {0, H_2, G_2, I_2},
    {0, H_1, G_1, I_1},    {0, E_14, D_14, F_14}, {0, E_12, D_12, F_12},
    {0, E_11, D_11, F_11}, {0, E_10, D_10, F_10}, {0, E_9, D_9, F_9},
    {0, E_8, D_8, F_8},    {0, E_7, D_7, F_7},    {0, E_6, D_6, F_6},
    {0, E_5, D_5, F_5},    {0, E_4, D_4, F_4},    {0, E_3, D_3, F_3},
    {0, E_2, D_2, F_2},    {0, E_1, D_1, F_1},    {0, B_13, A_13, C_13},
    {0, B_11, A_11, C_11}, {0, B_10, A_10, C_10}, {0, B_9, A_9, C_9},
    {0, B_8, A_8, C_8},    {0, B_7, A_7, C_7},    {0, B_6, A_6, C_6},
    {0, B_5, A_5, C_5},    {0, B_4, A_4, C_4},    {0, B_3, A_3, C_3},
    {0, B_2, A_2, C_2},    {0, B_1, A_1, C_1},    {0, B_15, A_15, C_15},
    {0, E_13, D_13, F_13}, {0, B_12, A_12, C_12}, {0, E_15, D_15, F_15},
    {0, B_16, A_16, C_16}, {0, E_16, D_16, F_16}, {0, H_16, G_16, I_16},
    {0, K_16, J_16, L_16},
};

rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {
    {{0 | (13 << 4)}, {16 * 13.5, 0}, 1},
    {{0 | (12 << 4)}, {16 * 12, 0}, 1},
    {{0 | (11 << 4)}, {16 * 11, 0}, 1},
    {{0 | (10 << 4)}, {16 * 10, 0}, 1},
    {{0 | (9 << 4)}, {16 * 9, 0}, 1},
    {{0 | (8 << 4)}, {16 * 8, 0}, 1},
    {{0 | (7 << 4)}, {16 * 7, 0}, 1},
    {{0 | (6 << 4)}, {16 * 6, 0}, 1},
    {{0 | (5 << 4)}, {16 * 5, 0}, 1},
    {{0 | (4 << 4)}, {16 * 4, 0}, 1},
    {{0 | (3 << 4)}, {16 * 3, 0}, 1},
    {{0 | (2 << 4)}, {16 * 2, 0}, 1},
    {{0 | (1 << 4)}, {16 * 1, 0}, 1},
    {{0 | (0 << 4)}, {16 * 0, 0}, 1},
    {{1 | (13 << 4)}, {16 * 13.75, 16}, 1},
    {{1 | (12 << 4)}, {16 * 12.5, 16}, 4},
    {{1 | (11 << 4)}, {16 * 11.5, 16}, 4},
    {{1 | (10 << 4)}, {16 * 10.5, 16}, 4},
    {{1 | (9 << 4)}, {16 * 9.5, 16}, 4},
    {{1 | (8 << 4)}, {16 * 8.5, 16}, 4},
    {{1 | (7 << 4)}, {16 * 7.5, 16}, 4},
    {{1 | (6 << 4)}, {16 * 6.5, 16}, 4},
    {{1 | (5 << 4)}, {16 * 5.5, 16}, 4},
    {{1 | (4 << 4)}, {16 * 4.5, 16}, 4},
    {{1 | (3 << 4)}, {16 * 3.5, 16}, 4},
    {{1 | (2 << 4)}, {16 * 2.5, 16}, 4},
    {{1 | (1 << 4)}, {16 * 1.5, 16}, 4},
    {{1 | (0 << 4)}, {16 * 0.25, 16}, 1},
    {{2 | (13 << 4)}, {16 * 13.375, 24}, 1},
    {{2 | (11 << 4)}, {16 * 11.75, 32}, 4},
    {{2 | (10 << 4)}, {16 * 10.75, 32}, 4},
    {{2 | (9 << 4)}, {16 * 9.75, 32}, 4},
    {{2 | (8 << 4)}, {16 * 8.75, 32}, 4},
    {{2 | (7 << 4)}, {16 * 7.75, 32}, 4},
    {{2 | (6 << 4)}, {16 * 6.75, 32}, 4},
    {{2 | (5 << 4)}, {16 * 5.75, 32}, 4},
    {{2 | (4 << 4)}, {16 * 4.75, 32}, 4},
    {{2 | (3 << 4)}, {16 * 3.75, 32}, 4},
    {{2 | (2 << 4)}, {16 * 2.75, 32}, 4},
    {{2 | (1 << 4)}, {16 * 1.75, 32}, 4},
    {{2 | (0 << 4)}, {16 * 0.375, 32}, 1},
    {{3 | (11 << 4)}, {16 * 13.125, 48}, 1},
    {{3 | (10 << 4)}, {16 * 11.25, 48}, 4},
    {{3 | (9 << 4)}, {16 * 10.25, 48}, 4},
    {{3 | (8 << 4)}, {16 * 9.25, 48}, 4},
    {{3 | (7 << 4)}, {16 * 8.25, 48}, 4},
    {{3 | (6 << 4)}, {16 * 7.25, 48}, 4},
    {{3 | (5 << 4)}, {16 * 6.25, 48}, 4},
    {{3 | (4 << 4)}, {16 * 5.25, 48}, 4},
    {{3 | (3 << 4)}, {16 * 4.25, 48}, 4},
    {{3 | (2 << 4)}, {16 * 3.25, 48}, 4},
    {{3 | (1 << 4)}, {16 * 1.25, 48}, 4},
    {{3 | (0 << 4)}, {16 * 0.625, 48}, 1},
    {{4 | (13 << 4)}, {16 * 13.875, 64}, 1},
    {{4 | (11 << 4)}, {16 * 12.625, 64}, 1},
    {{4 | (10 << 4)}, {16 * 11.375, 64}, 1},
    {{4 | (9 << 4)}, {16 * 10.125, 64}, 1},
    {{4 | (5 << 4)}, {16 * 6.375, 64}, 4},
    {{4 | (2 << 4)}, {16 * 2.625, 64}, 1},
    {{4 | (1 << 4)}, {16 * 1.375, 64}, 1},
    {{4 | (0 << 4)}, {16 * 0.125, 64}, 1},
};
#else
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, K_14, J_14, L_14}, {0, K_13, J_13, L_13}, {0, K_12, J_12, L_12},
    {0, K_11, J_11, L_11}, {0, K_10, J_10, L_10}, {0, K_9, J_9, L_9},
    {0, K_8, J_8, L_8},    {0, K_7, J_7, L_7},    {0, K_6, J_6, L_6},
    {0, K_5, J_5, L_5},    {0, K_4, J_4, L_4},    {0, K_3, J_3, L_3},
    {0, K_2, J_2, L_2},    {0, K_1, J_1, L_1},    {0, H_14, G_14, I_14},
    {0, H_13, G_13, I_13}, {0, H_12, G_12, I_12}, {0, H_11, G_11, I_11},
    {0, H_10, G_10, I_10}, {0, H_9, G_9, I_9},    {0, H_8, G_8, I_8},
    {0, H_7, G_7, I_7},    {0, H_6, G_6, I_6},    {0, H_5, G_5, I_5},
    {0, H_4, G_4, I_4},    {0, H_3, G_3, I_3},    {0, H_2, G_2, I_2},
    {0, H_1, G_1, I_1},    {0, E_14, D_14, F_14}, {0, E_12, D_12, F_12},
    {0, E_11, D_11, F_11}, {0, E_10, D_10, F_10}, {0, E_9, D_9, F_9},
    {0, E_8, D_8, F_8},    {0, E_7, D_7, F_7},    {0, E_6, D_6, F_6},
    {0, E_5, D_5, F_5},    {0, E_4, D_4, F_4},    {0, E_3, D_3, F_3},
    {0, E_2, D_2, F_2},    {0, E_1, D_1, F_1},    {0, B_14, A_14, C_14},
    {0, B_13, A_13, C_13}, {0, B_11, A_11, C_11}, {0, B_10, A_10, C_10},
    {0, B_9, A_9, C_9},    {0, B_8, A_8, C_8},    {0, B_7, A_7, C_7},
    {0, B_6, A_6, C_6},    {0, B_5, A_5, C_5},    {0, B_4, A_4, C_4},
    {0, B_3, A_3, C_3},    {0, B_2, A_2, C_2},    {0, B_1, A_1, C_1},
    {0, B_15, A_15, C_15}, {0, E_13, D_13, F_13}, {0, B_12, A_12, C_12},
    {0, E_15, D_15, F_15}, {0, H_15, G_15, I_15}, {0, B_16, A_16, C_16},
    {0, E_16, D_16, F_16}, {0, H_16, G_16, I_16}, {0, K_16, J_16, L_16},
};

rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {
    {{0 | (13 << 4)}, {17.23 * 13, 0}, 1},
    {{0 | (12 << 4)}, {17.23 * 12, 0}, 1},
    {{0 | (11 << 4)}, {17.23 * 11, 0}, 1},
    {{0 | (10 << 4)}, {17.23 * 10, 0}, 1},
    {{0 | (9 << 4)}, {17.23 * 9, 0}, 1},
    {{0 | (8 << 4)}, {17.23 * 8, 0}, 1},
    {{0 | (7 << 4)}, {17.23 * 7, 0}, 1},
    {{0 | (6 << 4)}, {17.23 * 6, 0}, 1},
    {{0 | (5 << 4)}, {17.23 * 5, 0}, 1},
    {{0 | (4 << 4)}, {17.23 * 4, 0}, 1},
    {{0 | (3 << 4)}, {17.23 * 3, 0}, 1},
    {{0 | (2 << 4)}, {17.23 * 2, 0}, 1},
    {{0 | (1 << 4)}, {17.23 * 1, 0}, 1},
    {{0 | (0 << 4)}, {17.23 * 0, 0}, 1},
    {{1 | (13 << 4)}, {17.23 * 13, 16}, 1},
    {{1 | (12 << 4)}, {17.23 * 12, 16}, 4},
    {{1 | (11 << 4)}, {17.23 * 11, 16}, 4},
    {{1 | (10 << 4)}, {17.23 * 10, 16}, 4},
    {{1 | (9 << 4)}, {17.23 * 9, 16}, 4},
    {{1 | (8 << 4)}, {17.23 * 8, 16}, 4},
    {{1 | (7 << 4)}, {17.23 * 7, 16}, 4},
    {{1 | (6 << 4)}, {17.23 * 6, 16}, 4},
    {{1 | (5 << 4)}, {17.23 * 5, 16}, 4},
    {{1 | (4 << 4)}, {17.23 * 4, 16}, 4},
    {{1 | (3 << 4)}, {17.23 * 3, 16}, 4},
    {{1 | (2 << 4)}, {17.23 * 2, 16}, 4},
    {{1 | (1 << 4)}, {17.23 * 1, 16}, 4},
    {{1 | (0 << 4)}, {17.23 * 0, 16}, 1},
    {{2 | (13 << 4)}, {17.23 * 13, 32}, 1},
    {{2 | (11 << 4)}, {17.23 * 11, 32}, 4},
    {{2 | (10 << 4)}, {17.23 * 10, 32}, 4},
    {{2 | (9 << 4)}, {17.23 * 9, 32}, 4},
    {{2 | (8 << 4)}, {17.23 * 8, 32}, 4},
    {{2 | (7 << 4)}, {17.23 * 7, 32}, 4},
    {{2 | (6 << 4)}, {17.23 * 6, 32}, 4},
    {{2 | (5 << 4)}, {17.23 * 5, 32}, 4},
    {{2 | (4 << 4)}, {17.23 * 4, 32}, 4},
    {{2 | (3 << 4)}, {17.23 * 3, 32}, 4},
    {{2 | (2 << 4)}, {17.23 * 2, 32}, 4},
    {{2 | (1 << 4)}, {17.23 * 1, 32}, 4},
    {{2 | (0 << 4)}, {17.23 * 0, 32}, 1},
    {{3 | (13 << 4)}, {17.23 * 13, 48}, 1},
    {{3 | (11 << 4)}, {17.23 * 11, 48}, 4},
    {{3 | (10 << 4)}, {17.23 * 10, 48}, 4},
    {{3 | (9 << 4)}, {17.23 * 9, 48}, 4},
    {{3 | (8 << 4)}, {17.23 * 8, 48}, 4},
    {{3 | (7 << 4)}, {17.23 * 7, 48}, 4},
    {{3 | (6 << 4)}, {17.23 * 6, 48}, 4},
    {{3 | (5 << 4)}, {17.23 * 5, 48}, 4},
    {{3 | (4 << 4)}, {17.23 * 4, 48}, 4},
    {{3 | (3 << 4)}, {17.23 * 3, 48}, 4},
    {{3 | (2 << 4)}, {17.23 * 2, 48}, 4},
    {{3 | (1 << 4)}, {17.23 * 1, 48}, 4},
    {{3 | (0 << 4)}, {17.23 * 0, 48}, 1},
    {{4 | (13 << 4)}, {17.23 * 13, 64}, 1},
    {{4 | (11 << 4)}, {17.23 * 11, 64}, 1},
    {{4 | (10 << 4)}, {17.23 * 10, 64}, 1},
    {{4 | (9 << 4)}, {17.23 * 9, 64}, 1},
    {{4 | (8 << 4)}, {17.23 * 8, 64}, 1},
    {{4 | (5 << 4)}, {17.23 * 5, 64}, 4},
    {{4 | (2 << 4)}, {17.23 * 2, 64}, 1},
    {{4 | (1 << 4)}, {17.23 * 1, 64}, 1},
    {{4 | (0 << 4)}, {17.23 * 0, 64}, 1},
};
#endif

/*
void matrix_init_kb(void) { matrix_init_user(); }

void matrix_scan_kb(void) { matrix_scan_user(); }

bool process_record_kb(uint16_t keycode, keyrecord_t *record) { return
process_record_user(keycode, record); }
*/

bool eeprom_is_valid(void)
{
	return (eeprom_read_word(((void *)EEPROM_MAGIC_ADDR)) == EEPROM_MAGIC &&
	        eeprom_read_byte(((void *)EEPROM_VERSION_ADDR)) == EEPROM_VERSION);
}

void eeprom_set_valid(bool valid)
{
	eeprom_update_word(((void *)EEPROM_MAGIC_ADDR),
	                   valid ? EEPROM_MAGIC : 0xFFFF);
	eeprom_update_byte(((void *)EEPROM_VERSION_ADDR),
	                   valid ? EEPROM_VERSION : 0xFF);
}

void eeprom_reset(void)
{
	// Set the Zeal60 specific EEPROM state as invalid.
	eeprom_set_valid(false);
	// Set the TMK/QMK EEPROM state as invalid.
	eeconfig_disable();
}

#ifdef RAW_ENABLE

void raw_hid_receive(uint8_t *data, uint8_t length)
{
	uint8_t *command_id = &(data[0]);
	uint8_t *command_data = &(data[1]);

	uprintf("Received command: %d, data length: %d\n", *command_id, length);
	switch (*command_id)
	{
		case id_get_protocol_version:
		{
			command_data[0] = PROTOCOL_VERSION >> 8;
			command_data[1] = PROTOCOL_VERSION & 0xFF;
			break;
		}
		case id_get_keyboard_value:
		{
			if (command_data[0] == id_uptime)
			{
				uint32_t value = timer_read32();
				command_data[1] = (value >> 24) & 0xFF;
				command_data[2] = (value >> 16) & 0xFF;
				command_data[3] = (value >> 8) & 0xFF;
				command_data[4] = value & 0xFF;
			}
			else
			{
				*command_id = id_unhandled;
			}
			break;
		}
#ifdef DYNAMIC_KEYMAP_ENABLE
		case id_dynamic_keymap_get_keycode:
		{
			uint16_t keycode = dynamic_keymap_get_keycode(
			    command_data[0], command_data[1], command_data[2]);
			command_data[3] = keycode >> 8;
			command_data[4] = keycode & 0xFF;
			break;
		}
		case id_dynamic_keymap_set_keycode:
		{
			dynamic_keymap_set_keycode(
			    command_data[0], command_data[1], command_data[2],
			    (command_data[3] << 8) | command_data[4]);
			break;
		}
		case id_dynamic_keymap_reset:
		{
			dynamic_keymap_reset();
			break;
		}
		case id_dynamic_keymap_macro_get_count:
		{
			command_data[0] = dynamic_keymap_macro_get_count();
			break;
		}
		case id_dynamic_keymap_macro_get_buffer_size:
		{
			uint16_t size = dynamic_keymap_macro_get_buffer_size();
			command_data[0] = size >> 8;
			command_data[1] = size & 0xFF;
			break;
		}
		case id_dynamic_keymap_macro_get_buffer:
		{
			uint16_t offset = (command_data[0] << 8) | command_data[1];
			uint16_t size = command_data[2];  // size <= 28
			dynamic_keymap_macro_get_buffer(offset, size, &command_data[3]);
			break;
		}
		case id_dynamic_keymap_macro_set_buffer:
		{
			uint16_t offset = (command_data[0] << 8) | command_data[1];
			uint16_t size = command_data[2];  // size <= 28
			dynamic_keymap_macro_set_buffer(offset, size, &command_data[3]);
			break;
		}
		case id_dynamic_keymap_macro_reset:
		{
			dynamic_keymap_macro_reset();
			break;
		}
		case id_dynamic_keymap_get_layer_count:
		{
			command_data[0] = dynamic_keymap_get_layer_count();
			break;
		}
		case id_dynamic_keymap_get_buffer:
		{
			uint16_t offset = (command_data[0] << 8) | command_data[1];
			uint16_t size = command_data[2];  // size <= 28
			dynamic_keymap_get_buffer(offset, size, &command_data[3]);
			break;
		}
		case id_dynamic_keymap_set_buffer:
		{
			uint16_t offset = (command_data[0] << 8) | command_data[1];
			uint16_t size = command_data[2];  // size <= 28
			dynamic_keymap_set_buffer(offset, size, &command_data[3]);
			break;
		}
#endif  // DYNAMIC_KEYMAP_ENABLE
		case id_eeprom_reset:
		{
			eeprom_reset();
			break;
		}
		case id_bootloader_jump:
		{
			// Need to send data back before the jump
			// Informs host that the command is handled
			raw_hid_send(data, length);
			// Give host time to read it
			wait_ms(100);
			bootloader_jump();
			break;
		}
		default:
		{
			// Unhandled message.
			*command_id = id_unhandled;
			break;
		}
	}

	// Return same buffer with values changed
	raw_hid_send(data, length);
}

#endif

void main_init(void)
{
	// If the EEPROM has the magic, the data is good.
	// OK to load from EEPROM.
	if (eeprom_is_valid())
	{
		// backlight_config_load();
	}
	else
	{
	// If the EEPROM has not been saved before, or is out of date,
	// save the default values to the EEPROM. Default values
	// come from construction of the zeal_backlight_config instance.
	// backlight_config_save();
#ifdef DYNAMIC_KEYMAP_ENABLE
		// This resets the keymaps in EEPROM to what is in flash.
		dynamic_keymap_reset();
		// This resets the macros in EEPROM to nothing.
		dynamic_keymap_macro_reset();
#endif
		// Save the magic number last, in case saving was interrupted
		eeprom_set_valid(true);
	}

#ifdef WT_MONO_BACKLIGHT
	// Initialize LED drivers for backlight.
	backlight_init_drivers();

	backlight_timer_init();
	backlight_timer_enable();
#endif
}

void bootmagic_lite(void)
{
	// The lite version of TMK's bootmagic.
	// 100% less potential for accidentally making the
	// keyboard do stupid things.

	// We need multiple scans because debouncing can't be turned off.
	matrix_scan();
	wait_ms(DEBOUNCING_DELAY);
	wait_ms(DEBOUNCING_DELAY);
	matrix_scan();

	// If the Esc (matrix 0,0) is held down on power up,
	// reset the EEPROM valid state and jump to bootloader.
	if (matrix_get_row(0) & (1 << 0))
	{
		eeprom_reset();
		bootloader_jump();
	}
}

void matrix_init_kb(void)
{
	bootmagic_lite();
	main_init();
	matrix_init_user();
}

void matrix_scan_kb(void)
{
#ifdef WT_MONO_BACKLIGHT
	// This only updates the LED driver buffers if something has changed.
	backlight_update_pwm_buffers();
#endif
	matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record)
{
	switch (keycode)
	{
		case FN_MO13:
			if (record->event.pressed)
			{
				layer_on(1);
				update_tri_layer(1, 2, 3);
			}
			else
			{
				layer_off(1);
				update_tri_layer(1, 2, 3);
			}
			return false;
			break;
		case FN_MO23:
			if (record->event.pressed)
			{
				layer_on(2);
				update_tri_layer(1, 2, 3);
			}
			else
			{
				layer_off(2);
				update_tri_layer(1, 2, 3);
			}
			return false;
			break;
	}

#ifdef DYNAMIC_KEYMAP_ENABLE
	// Handle macros
	if (record->event.pressed)
	{
		if (keycode >= MACRO00 && keycode <= MACRO15)
		{
			uint8_t id = keycode - MACRO00;
			dynamic_keymap_macro_send(id);
			return false;
		}
	}
#endif  // DYNAMIC_KEYMAP_ENABLE

	return process_record_user(keycode, record);
}

void suspend_power_down_kb(void)
{
	rgb_matrix_set_suspend_state(true);
	suspend_power_down_user();
}

void suspend_wakeup_init_kb(void)
{
	rgb_matrix_set_suspend_state(false);
	suspend_wakeup_init_user();
}
