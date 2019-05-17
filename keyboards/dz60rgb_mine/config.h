/*
Copyright 2019 alexSt

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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x445A //DZ
#define PRODUCT_ID 0x3630 //60
#define DEVICE_VER 0x0001
#define MANUFACTURER KBDFANS
#define PRODUCT DZ60RGB
#define DESCRIPTION DZ60 board with STM32 controller and per key rgb

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on
 * diode) ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS        \
	{                          \
		B1, B10, B11, B14, B12 \
	}
#define MATRIX_COL_PINS                                             \
	{                                                               \
		A6, A7, B0, B13, B15, A8, A15, B3, B4, B5, B8, B9, C13, C14 \
	}

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is
 * not needed */
#define DEBOUNCING_DELAY 5

/* VIA Configurator support(experimental) */
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// EEPROM usage
#define EEPROM_SIZE 1024
// TODO: refactor with new user EEPROM code (coming soon)
#define EEPROM_MAGIC 0x451F
#define EEPROM_MAGIC_ADDR 32
// Bump this every time we change what we store
// This will automatically reset the EEPROM with defaults
// and avoid loading invalid data from the EEPROM
#define EEPROM_VERSION 0x01
#define EEPROM_VERSION_ADDR 34

// Backlight config starts after EEPROM version
#define RGB_BACKLIGHT_CONFIG_EEPROM_ADDR 35

// Dynamic keymap starts after EEPROM version
#define DYNAMIC_KEYMAP_EEPROM_ADDR RGB_BACKLIGHT_CONFIG_EEPROM_ADDR + 32

// Dynamic macro starts after dynamic keymaps
#define DYNAMIC_KEYMAP_MACRO_EEPROM_ADDR \
	(DYNAMIC_KEYMAP_EEPROM_ADDR +        \
	 (DYNAMIC_KEYMAP_LAYER_COUNT * MATRIX_ROWS * MATRIX_COLS * 2))

#define DYNAMIC_KEYMAP_MACRO_EEPROM_SIZE \
	(EEPROM_SIZE - DYNAMIC_KEYMAP_MACRO_EEPROM_ADDR)

#define DYNAMIC_KEYMAP_MACRO_COUNT 16

// RGB_Matrix related
#define RGB_BACKLIGHT_ENABLED 1
#define DRIVER_COUNT 2
#define DRIVER_LED_TOTAL 63

// they aren't really used if RGB_BACKLIGHT_HS60 defined
#define RGB_BACKLIGHT_USE_SPLIT_BACKSPACE 0
#define RGB_BACKLIGHT_USE_SPLIT_LEFT_SHIFT 0
#define RGB_BACKLIGHT_USE_SPLIT_RIGHT_SHIFT 0
#define RGB_BACKLIGHT_USE_7U_SPACEBAR 0
#define RGB_BACKLIGHT_USE_ISO_ENTER 0
#define RGB_BACKLIGHT_DISABLE_HHKB_BLOCKER_LEDS 0

// disable backlight when USB suspended (PC sleep/hibernate/shutdown)
#define RGB_BACKLIGHT_DISABLE_WHEN_USB_SUSPENDED true

// disable backlight after timeout in minutes, 0 = no timeout
#define RGB_BACKLIGHT_DISABLE_AFTER_TIMEOUT 0

// the default brightness
#define RGB_BACKLIGHT_BRIGHTNESS 255

// the default effect (RGB test)
#define RGB_BACKLIGHT_EFFECT 255

// the default effect speed (0-3)
#define RGB_BACKLIGHT_EFFECT_SPEED 0

// the default color1 and color2
#define RGB_BACKLIGHT_COLOR_1 { .h = 0, .s = 255 }
#define RGB_BACKLIGHT_COLOR_2 { .h = 127, .s = 255 }

// These define which keys in the matrix are alphas/mods
// Used for backlight effects so colors are different for
// alphas vs. mods
// Each value is for a row, bit 0 is column 0
// Alpha=0 Mod=1
#define RGB_BACKLIGHT_ALPHAS_MODS_ROW_0 0b0010000000000001
#define RGB_BACKLIGHT_ALPHAS_MODS_ROW_1 0b0000000000000001
#define RGB_BACKLIGHT_ALPHAS_MODS_ROW_2 0b0010000000000001
#define RGB_BACKLIGHT_ALPHAS_MODS_ROW_3 0b0010000000000001
#define RGB_BACKLIGHT_ALPHAS_MODS_ROW_4 0b0011110000000111

#define RGB_BACKLIGHT_CAPS_LOCK_INDICATOR       \
	{                                           \
		.color = {.h = 0, .s = 0}, .index = 255 \
	}
#define RGB_BACKLIGHT_LAYER_1_INDICATOR         \
	{                                           \
		.color = {.h = 0, .s = 0}, .index = 255 \
	}
#define RGB_BACKLIGHT_LAYER_2_INDICATOR         \
	{                                           \
		.color = {.h = 0, .s = 0}, .index = 255 \
	}
#define RGB_BACKLIGHT_LAYER_3_INDICATOR         \
	{                                           \
		.color = {.h = 0, .s = 0}, .index = 255 \
	}
