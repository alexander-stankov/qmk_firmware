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
#include "via_api.h"
#include "via_keycodes.h"

// Check that no backlight functions are called
#if RGB_BACKLIGHT_ENABLED
#include "rgb_backlight.h"
#endif // BACKLIGHT_ENABLED

#include "dynamic_keymap.h"
#include "raw_hid.h"
#include "timer.h"
#include "tmk_core/common/eeprom.h"
//TODO: remove this in production
#include "tmk_core/common/print.h"

/*
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
#ifdef RGB_BACKLIGHT_ENABLED
		case id_backlight_config_set_value:
		{
			backlight_config_set_value(command_data);
			break;
		}
		case id_backlight_config_get_value:
		{
			backlight_config_get_value(command_data);
			break;
		}
		case id_backlight_config_save:
		{
			backlight_config_save();
			break;
		}
#endif
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
	if (eeprom_is_valid()) {
#if RGB_BACKLIGHT_ENABLED
		backlight_config_load();
#endif // RGB_BACKLIGHT_ENABLED
	} else	{
#if RGB_BACKLIGHT_ENABLED
		// If the EEPROM has not been saved before, or is out of date,
		// save the default values to the EEPROM. Default values
		// come from construction of the zeal_backlight_config instance.
		backlight_config_save();
#endif // RGB_BACKLIGHT_ENABLED
#ifdef DYNAMIC_KEYMAP_ENABLE
		// This resets the keymaps in EEPROM to what is in flash.
		dynamic_keymap_reset();
		// This resets the macros in EEPROM to nothing.
		dynamic_keymap_macro_reset();
#endif
		// Save the magic number last, in case saving was interrupted
		eeprom_set_valid(true);
	}

#if RGB_BACKLIGHT_ENABLED
	// Initialize LED drivers for backlight.
	backlight_init_drivers();

	backlight_timer_init();
	backlight_timer_enable();
#endif // RGB_BACKLIGHT_ENABLED
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
#if RGB_BACKLIGHT_ENABLED
	process_record_backlight(keycode, record);
#endif // BACKLIGHT_ENABLED

	switch(keycode) {
		case FN_MO13:
			if (record->event.pressed) {
				layer_on(1);
				update_tri_layer(1, 2, 3);
			} else {
				layer_off(1);
				update_tri_layer(1, 2, 3);
			}
			return false;
			break;
		case FN_MO23:
			if (record->event.pressed) {
				layer_on(2);
				update_tri_layer(1, 2, 3);
			} else {
				layer_off(2);
				update_tri_layer(1, 2, 3);
			}
			return false;
			break;
	}

#ifdef DYNAMIC_KEYMAP_ENABLE
	// Handle macros
	if (record->event.pressed) {
		if ( keycode >= MACRO00 && keycode <= MACRO15 )
		{
			uint8_t id = keycode - MACRO00;
			dynamic_keymap_macro_send(id);
			return false;
		}
	}
#endif //DYNAMIC_KEYMAP_ENABLE

	return process_record_user(keycode, record);
}

// This overrides the one in quantum/keymap_common.c
uint16_t keymap_function_id_to_action( uint16_t function_id )
{
	// Zeal60 specific "action functions" are 0xF00 to 0xFFF
	// i.e. F(0xF00) to F(0xFFF) are mapped to
	// enum zeal60_action_functions by masking last 8 bits.
	if ( function_id >= 0x0F00 && function_id <= 0x0FFF )
	{
		uint8_t id = function_id & 0xFF;
		switch ( id ) {
			case TRIPLE_TAP_1_3:
			case TRIPLE_TAP_2_3:
			{
				return ACTION_FUNCTION_TAP(id);
				break;
			}
			default:
				break;
		}
	}

	return pgm_read_word(&fn_actions[function_id]);
}

// Zeal60 specific "action functions"
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	switch (id)
	{
	case TRIPLE_TAP_1_3:
	case TRIPLE_TAP_2_3:
		if (record->event.pressed) {
			layer_on( id == TRIPLE_TAP_1_3 ? 1 : 2 );
			if (record->tap.count && !record->tap.interrupted) {
				if (record->tap.count >= 3) {
					layer_invert(3);
				}
			} else {
				record->tap.count = 0;
			}
		} else {
			layer_off( id == TRIPLE_TAP_1_3 ? 1 : 2 );
		}
		break;
	}
}

void led_set_kb(uint8_t usb_led)
{
#if RGB_BACKLIGHT_ENABLED
	backlight_set_indicator_state(usb_led);
#endif // RGB_BACKLIGHT_ENABLED
}

void suspend_power_down_kb(void)
{
#if RGB_BACKLIGHT_ENABLED
	backlight_set_suspend_state(true);
#endif // RGB_BACKLIGHT_ENABLED
}

void suspend_wakeup_init_kb(void)
{
#if RGB_BACKLIGHT_ENABLED
	backlight_set_suspend_state(false);
#endif // RGB_BACKLIGHT_ENABLED
}
