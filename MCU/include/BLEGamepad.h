#ifndef BLE_GAMEPAD_H
#define BLE_GAMEPAD_H

#include <Arduino.h>

#include <BLEDevice.h>
#include <BLEHIDDevice.h>

#include "BLEConnection.h"

#include "sh_types.h"

const u64 BTN_1  = BIT64(1);
const u64 BTN_2  = BIT64(2);
const u64 BTN_3  = BIT64(3);
const u64 BTN_4  = BIT64(4);
const u64 BTN_5  = BIT64(5);
const u64 BTN_6  = BIT64(6);
const u64 BTN_7  = BIT64(7);
const u64 BTN_8  = BIT64(8);
const u64 BTN_9  = BIT64(9);
const u64 BTN_10 = BIT64(10);
const u64 BTN_11 = BIT64(11);
const u64 BTN_12 = BIT64(12);
const u64 BTN_13 = BIT64(13);
const u64 BTN_14 = BIT64(14);
const u64 BTN_15 = BIT64(15);
const u64 BTN_16 = BIT64(16);
const u64 BTN_17 = BIT64(17);
const u64 BTN_18 = BIT64(18);
const u64 BTN_19 = BIT64(19);
const u64 BTN_20 = BIT64(20);
const u64 BTN_21 = BIT64(21);
const u64 BTN_22 = BIT64(22);
const u64 BTN_23 = BIT64(23);
const u64 BTN_24 = BIT64(24);
const u64 BTN_25 = BIT64(25);
const u64 BTN_26 = BIT64(26);
const u64 BTN_27 = BIT64(27);
const u64 BTN_28 = BIT64(28);
const u64 BTN_29 = BIT64(29);
const u64 BTN_30 = BIT64(30);
const u64 BTN_31 = BIT64(31);
const u64 BTN_32 = BIT64(32);

const u8 DPAD_CENTER = 0;
const u8 DPAP_UP = 1;
const u8 DPAP_UP_RIGHT = 2;
const u8 DPAP_RIGHT = 3;
const u8 DPAP_DOWN_RIGHT = 4;
const u8 DPAP_DOWN = 5;
const u8 DPAP_DOWN_LEFT = 6;
const u8 DPAP_LEFT = 7;
const u8 DPAP_UP_LEFT = 8;

class BLEGamepad {
	private:
		u64 buttons = 0;
		String deviceName;
		String deviceManufacturer;
		BLEConnectionStatus * connectStatus;
		BLEHIDDevice * hid;
		BLECharacteristic * gamepad;
	public:
		BLEGamepad(String deviceName="FriendJoyPad", String deviceManufacturer="FriendTeamInc.");
		void begin();
		void end();
	protected:
		virtual void onStarted(BLEServer * pServer) { };
};

#undef BIT

#endif
