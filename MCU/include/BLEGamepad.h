#ifndef BLE_GAMEPAD_H
#define BLE_GAMEPAD_H

#include <Arduino.h>

#include <BLEDevice.h>
#include <BLEHIDDevice.h>

#include "BLEConnection.h"

#include "sh_types.h"

const u64 BTN_1  = BIT(0);
const u64 BTN_2  = BIT(1);
const u64 BTN_3  = BIT(2);
const u64 BTN_4  = BIT(3);
const u64 BTN_5  = BIT(4);
const u64 BTN_6  = BIT(5);
const u64 BTN_7  = BIT(6);
const u64 BTN_8  = BIT(7);
const u64 BTN_9  = BIT(8);
const u64 BTN_10 = BIT(9);
const u64 BTN_11 = BIT(10);
const u64 BTN_12 = BIT(11);
const u64 BTN_13 = BIT(12);
const u64 BTN_14 = BIT(13);
const u64 BTN_15 = BIT(14);
const u64 BTN_16 = BIT(15);
const u64 BTN_17 = BIT(16);
const u64 BTN_18 = BIT(17);
const u64 BTN_19 = BIT(18);
const u64 BTN_20 = BIT(19);
const u64 BTN_21 = BIT(20);
const u64 BTN_22 = BIT(21);
const u64 BTN_23 = BIT(22);
const u64 BTN_24 = BIT(23);
const u64 BTN_25 = BIT(24);
const u64 BTN_26 = BIT(25);
const u64 BTN_27 = BIT(26);
const u64 BTN_28 = BIT(27);
const u64 BTN_29 = BIT(28);
const u64 BTN_30 = BIT(29);
const u64 BTN_31 = BIT(30);
const u64 BTN_32 = BIT(31);

const u8 DPAD_CENTER = 0;
const u8 DPAD_UP = 1;
const u8 DPAD_UP_RIGHT = 2;
const u8 DPAD_RIGHT = 3;
const u8 DPAD_DOWN_RIGHT = 4;
const u8 DPAD_DOWN = 5;
const u8 DPAD_DOWN_LEFT = 6;
const u8 DPAD_LEFT = 7;
const u8 DPAD_UP_LEFT = 8;

class BLEGamepad {
	private:
		u64 buttons = 0;
		u8 hatDirection = 0;
		u16 leftStickX = 0, leftStickY = 0;
		u16 rightStickX = 0, rightStickY = 0;
		u8 leftTrigger = 0, rightTrigger = 0;

		std::string deviceName;
		std::string deviceManufacturer;

		BLEConnectionStatus * connectStatus;
		BLEHIDDevice * hid;
		BLECharacteristic * gamepad;

		static void taskServer (void * pvParameter);
	public:
		BLEGamepad(std::string deviceName="FriendJoyPad", std::string deviceManufacturer="FriendTeamInc.");
		void begin();
		void end();
		inline void press(u64 b) { this->buttons = this->buttons | b; };
		inline void release(u64 b) { this->buttons = this->buttons & ~b; };
		inline void setHat(u8 hat) { this->hatDirection = hat; };
		void send();
		inline bool isConnected() { return this->connectStatus->connected; };
	protected:
		virtual void onStarted(BLEServer * pServer) { };
};

#undef BIT

#endif
