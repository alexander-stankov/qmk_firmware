#pragma once

// Can't use SAFE_RANGE here, it might change if someone adds
// new values to enum quantum_keycodes.
// Need to keep checking 0x5F10 is still in the safe range.
// TODO: merge this into quantum_keycodes
// Backlight keycodes are in range 0x5F00-0x5F0F
enum via_keycodes
{
	FN_MO13 = 0x5F10,
	FN_MO23,
	MACRO00,
	MACRO01,
	MACRO02,
	MACRO03,
	MACRO04,
	MACRO05,
	MACRO06,
	MACRO07,
	MACRO08,
	MACRO09,
	MACRO10,
	MACRO11,
	MACRO12,
	MACRO13,
	MACRO14,
	MACRO15,
};

enum user_keycodes
{
	USER00 = 0x5F80,
	USER01,
	USER02,
	USER03,
	USER04,
	USER05,
	USER06,
	USER07,
	USER08,
	USER09,
	USER10,
	USER11,
	USER12,
	USER13,
	USER14,
	USER15,
};

// Zeal60 specific "action functions"
// These are only valid IDs in action_function()
// Use FN_TT13, FN_TT23, etc. in keymaps
enum via_action_functions
{
	TRIPLE_TAP_1_3 = 0x31,
	TRIPLE_TAP_2_3 = 0x32
};

// Bitwise OR the above with 0x0F00 to use in F(x) macro
// This reserves the top 256 of the 4096 range of F(x) keycodes,
// leaving the rest for use in fn_actions[] or actions in EEPROM.
#define FN_TT13 F((0x0F00 | TRIPLE_TAP_1_3))
#define FN_TT23 F((0x0F00 | TRIPLE_TAP_2_3))

#define TG_NKRO MAGIC_TOGGLE_NKRO
