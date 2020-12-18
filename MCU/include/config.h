#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include "Pair.h"

typedef Pair<byte, byte> PIN;

// Pins for each of the buttons, sticks, etc.
PIN button_a = {22, INPUT_PULLUP}; // A
PIN button_b = {23, INPUT_PULLUP}; // B
PIN button_x = {3, INPUT_PULLUP};  // X
PIN button_y = {21, INPUT_PULLUP}; // Y

PIN button_up    = {22, INPUT_PULLUP}; // DPAD up
PIN button_down  = {23, INPUT_PULLUP}; // DPAD down
PIN button_left  = {3, INPUT_PULLUP};  // DPAD left
PIN button_right = {21, INPUT_PULLUP}; // DPAD right

PIN stick_left_x = {39, INPUT_PULLUP}; // left stick left and right
PIN stick_left_y = {36, INPUT_PULLUP}; // left stick up and down
PIN stick_left_b = {32, INPUT_PULLUP}; // left stick button

PIN stick_right_x = {0, INPUT_PULLUP}; // right stick left and right
PIN stick_right_y = {0, INPUT_PULLUP}; // right stick up and down
PIN stick_right_b = {0, INPUT_PULLUP}; // right stick button

PIN shoulder_left_1 = {19, INPUT_PULLUP}; // left shoulder encoder pin 1
PIN shoulder_left_2 = {18, INPUT_PULLUP}; // left shoulder encoder pin 2
PIN shoulder_left_b = {40, INPUT_PULLUP}; // left shoulder button

PIN shoulder_right_1 = {0, INPUT_PULLUP}; // right shoulder encoder pin 1
PIN shoulder_right_2 = {0, INPUT_PULLUP}; // right shoulder encoder pin 2
PIN shoulder_right_b = {0, INPUT_PULLUP}; // right shoulder button

PIN trigger_left_a = {0, INPUT_PULLUP}; // left trigger analog input
PIN trigger_left_b = {0, INPUT_PULLUP}; // left trigger digital input

PIN trigger_right_a = {0, INPUT_PULLUP}; // right trigger analog input
PIN trigger_right_b = {0, INPUT_PULLUP}; // right trigger digital input

#endif // CONFIG_H
