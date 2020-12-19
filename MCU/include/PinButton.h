#ifndef PIN_BUTTON_H
#define PIN_BUTTON_H

#include <Arduino.h>
#include "sh_types.h"

struct PinButton {
	u8 pin;
	u8 mode;
	bool invert = false;

	PinButton (u8 pin, u8 mode = INPUT) : pin(pin), mode(mode) {
		if (mode == INPUT_PULLUP) this->invert = true;
	}

	PinButton (u8 pin, u8 mode, bool invert) : pin(pin), mode(mode), invert(invert) {}

	void init () {
		pinMode(this->pin, this->mode);
	}

	bool read () {
		bool val = digitalRead(this->pin);
		if (this->invert)
			return !val;
		else
			return val;
	}

	u16 readAnalog() {
		return analogRead(this->pin);
	}
};


#endif