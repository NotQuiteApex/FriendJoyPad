#ifndef BLE_GAMEPAD_H
#define BLE_GAMEPAD_H

#include "sh_types.h"

#define BIT(x) (1 << (x))

const u32 BTN_1  = BIT(1);
const u32 BTN_2  = BIT(2);
const u32 BTN_3  = BIT(3);
const u32 BTN_4  = BIT(4);
const u32 BTN_5  = BIT(5);
const u32 BTN_6  = BIT(6);
const u32 BTN_7  = BIT(7);
const u32 BTN_8  = BIT(8);
const u32 BTN_9  = BIT(9);
const u32 BTN_10 = BIT(10);
const u32 BTN_11 = BIT(11);
const u32 BTN_12 = BIT(12);
const u32 BTN_13 = BIT(13);
const u32 BTN_14 = BIT(14);
const u32 BTN_15 = BIT(15);
const u32 BTN_16 = BIT(16);
const u32 BTN_17 = BIT(17);
const u32 BTN_18 = BIT(18);
const u32 BTN_19 = BIT(19);
const u32 BTN_20 = BIT(20);
const u32 BTN_21 = BIT(21);
const u32 BTN_22 = BIT(22);
const u32 BTN_23 = BIT(23);
const u32 BTN_24 = BIT(24);
const u32 BTN_25 = BIT(25);
const u32 BTN_26 = BIT(26);
const u32 BTN_27 = BIT(27);
const u32 BTN_28 = BIT(28);
const u32 BTN_29 = BIT(29);
const u32 BTN_30 = BIT(30);
const u32 BTN_31 = BIT(31);
const u32 BTN_32 = BIT(32);

const u32 DPAD_CENTER = 0;
const u32 DPAP_UP = 1;
const u32 DPAP_UP_RIGHT = 2;
const u32 DPAP_RIGHT = 3;
const u32 DPAP_DOWN_RIGHT = 4;
const u32 DPAP_DOWN = 5;
const u32 DPAP_DOWN_LEFT = 6;
const u32 DPAP_LEFT = 7;
const u32 DPAP_UP_LEFT = 8;

#undef BIT

#endif