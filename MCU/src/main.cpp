#include <Arduino.h>

#include "BLEGamepad.h"

#include "config.h"

PIN pins[] = {
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
		pinMode(pins[i].first(), pins[i].second());
	}

	// Init serial
	Serial.begin(115200);

	// Init gamepad
	joypad.begin();
}

void loop () {
	if (joypad.isConnected()) {
		Serial.println("start1");
		joypad.press(BTN_1);
		joypad.press(BTN_32);
		joypad.setHat(DPAD_RIGHT);
		joypad.send();
		delay(500);
		
		Serial.println("srtat3");
		joypad.release(BTN_1 | BTN_32);
		joypad.setHat(DPAD_CENTER);
		joypad.send();
		delay(500);
	}
}
