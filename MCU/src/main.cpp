#include <Arduino.h>

#include "PinButton.h"
#include "BLEGamepad.h"

#include "config.h"

PinButton pins[] = {
	button_a, button_b, button_x, button_y,
	button_up, button_down, button_left, button_right,
	stick_left_x, stick_left_y, stick_left_b,
	stick_right_x, stick_right_y, stick_right_b,
	shoulder_left_1, shoulder_left_2, shoulder_left_b,
	shoulder_right_1, shoulder_right_2, shoulder_right_b,
	trigger_left_a, trigger_left_b,
	trigger_right_a, trigger_right_b
};

BLEGamepad joypad;

void setup () {
	// Init pins
	for (byte i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++) {
		pins[i].init();
	}

	// Init serial
	Serial.begin(115200);

	// Init gamepad
	joypad.begin();
}

void loop () {
	if (button_a.read()) {
		joypad.press(BTN_1);
	} else {
		joypad.release(BTN_1);
	}

	if (button_b.read()) {
		joypad.press(BTN_2);
	} else {
		joypad.release(BTN_2);
	}

	if (button_x.read()) {
		joypad.press(BTN_3);
	} else {
		joypad.release(BTN_3);
	}

	if (button_y.read()) {
		joypad.press(BTN_4);
	} else {
		joypad.release(BTN_4);
	}

	// TODO: find a better way to read hat values.
	u8 dpad = 0;
	bool up    = button_up.read();
	bool right = button_right.read();
	bool down  = button_down.read();
	bool left  = button_left.read();

	if ((up || down) && (right || left)) {
		if (up && right) dpad = DPAD_UP_RIGHT;
		if (down && right) dpad = DPAD_DOWN_RIGHT;
		if (down && left) dpad = DPAD_DOWN_LEFT;
		if (up && left) dpad = DPAD_UP_LEFT;
	} else {
		if (up) dpad = DPAD_UP;
		if (right) dpad = DPAD_RIGHT;
		if (down) dpad = DPAD_DOWN;
		if (left) dpad = DPAD_LEFT;
	}

	joypad.setLeftStick(stick_left_x.readAnalog(), stick_left_y.readAnalog());

	joypad.setHat(dpad);

	if (joypad.isConnected()) {
		joypad.send();
	}

	delay(5);
}
