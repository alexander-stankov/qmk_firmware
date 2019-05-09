#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x1219
#define DEVICE_VER      0x0001
#define MANUFACTURER    DZTECH

#define PRODUCT         DZ60RGB
#define DESCRIPTION     DZ60 ARM RGB keyboard
#define MATRIX_ROWS 5
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS { B1, B10, B11, B14, B12 }
#define MATRIX_COL_PINS {A6, A7, B0, B13, B15, A8, A15, B3, B4, B5, B8, B9, C13, C14 }

/* #define UNUSED_PINS {A0,A1,A2, A3,A4,A9,A10,C15,A13,A14,B2}*/

#define DIODE_DIRECTION COL2ROW

//#define DEBOUNCE 3
#define DEBOUNCING_DELAY 5
#define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_LED_PROCESS_LIMIT 4
#define RGB_MATRIX_LED_FLUSH_LIMIT 26
#define DISABLE_RGB_MATRIX_SPLASH
#define DISABLE_RGB_MATRIX_MULTISPLASH
#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#define DRIVER_ADDR_1 0b1010000
#define DRIVER_ADDR_2 0b1010000 // this is here for compliancy reasons.
#define DRIVER_COUNT 2
#define DRIVER_1_LED_TOTAL 63
#define DRIVER_LED_TOTAL DRIVER_1_LED_TOTAL


#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// EEPROM usage

// TODO: refactor with new user EEPROM code (coming soon)
#define EEPROM_MAGIC 0x451F
#define EEPROM_MAGIC_ADDR 32
// Bump this every time we change what we store
// This will automatically reset the EEPROM with defaults
// and avoid loading invalid data from the EEPROM
#define EEPROM_VERSION 0x08
#define EEPROM_VERSION_ADDR 34

// Dynamic keymap starts after EEPROM version
#define DYNAMIC_KEYMAP_EEPROM_ADDR 35
// Dynamic macro starts after dynamic keymaps (35+(4*10*6*2)) = (35+480)
#define DYNAMIC_KEYMAP_MACRO_EEPROM_ADDR 595    // **** CHANGE THIS BASED ON MATRIX_ROWS & MATRIX_COLS ****
#define DYNAMIC_KEYMAP_MACRO_EEPROM_SIZE 429    // **** CHANGE THIS BASED ON 1024-DYNAMIC_KEYMAP_MACRO_EEPROM_ADDR ****
#define DYNAMIC_KEYMAP_MACRO_COUNT 16
