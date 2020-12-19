#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include "PinButton.h"

// PinButtons for each of the buttons, sticks, etc.
PinButton button_a = {23, INPUT_PULLUP}; // A
PinButton button_b = {3, INPUT_PULLUP};  // B
PinButton button_x = {21, INPUT_PULLUP}; // X
PinButton button_y = {22, INPUT_PULLUP}; // Y

PinButton button_up    = {22, INPUT_PULLUP}; // DPAD up
PinButton button_down  = {23, INPUT_PULLUP}; // DPAD down
PinButton button_left  = {21, INPUT_PULLUP}; // DPAD left
PinButton button_right = {3, INPUT_PULLUP};  // DPAD right

PinButton stick_left_x = {36, INPUT_PULLDOWN}; // left stick left and right
PinButton stick_left_y = {39, INPUT_PULLDOWN}; // left stick up and down
PinButton stick_left_b = {32, INPUT_PULLUP};   // left stick button

PinButton stick_right_x = {0, INPUT_PULLDOWN}; // right stick left and right
PinButton stick_right_y = {0, INPUT_PULLDOWN}; // right stick up and down
PinButton stick_right_b = {0, INPUT_PULLUP};   // right stick button

PinButton shoulder_left_1 = {19, INPUT_PULLUP}; // left shoulder encoder PinButton 1
PinButton shoulder_left_2 = {18, INPUT_PULLUP}; // left shoulder encoder PinButton 2
PinButton shoulder_left_b = {40, INPUT_PULLUP}; // left shoulder button

PinButton shoulder_right_1 = {0, INPUT_PULLUP}; // right shoulder encoder PinButton 1
PinButton shoulder_right_2 = {0, INPUT_PULLUP}; // right shoulder encoder PinButton 2
PinButton shoulder_right_b = {0, INPUT_PULLUP}; // right shoulder button

PinButton trigger_left_a = {0, INPUT_PULLDOWN}; // left trigger analog input
PinButton trigger_left_b = {0, INPUT_PULLUP};   // left trigger digital input

PinButton trigger_right_a = {0, INPUT_PULLDOWN}; // right trigger analog input
PinButton trigger_right_b = {0, INPUT_PULLUP};   // right trigger digital input

#endif // CONFIG_H
