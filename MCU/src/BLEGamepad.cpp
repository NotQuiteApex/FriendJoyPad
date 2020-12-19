#include <BLEDevice.h>
#include <BLEHIDDevice.h>

#include "BLEGamepad.h"
#include "BLEConnection.h"

const u8 _hidReportDescriptor[] = {
  USAGE_PAGE(1),       0x01, // USAGE_PAGE (Generic Desktop)
  USAGE(1),            0x05, // USAGE (Gamepad)
  COLLECTION(1),       0x01, // COLLECTION (Application)
  USAGE(1),            0x01, //   USAGE (Pointer)
  COLLECTION(1),       0x00, //   COLLECTION (Physical)

  // ------------------------------------------------- Buttons (1 to 32)
  USAGE_PAGE(1),       0x09, //     USAGE_PAGE (Button)
  USAGE_MINIMUM(1),    0x01, //     USAGE_MINIMUM (Button 1)
  USAGE_MAXIMUM(1),    0x20, //     USAGE_MAXIMUM (Button 32)
  LOGICAL_MINIMUM(1),  0x00, //     LOGICAL_MINIMUM (0)
  LOGICAL_MAXIMUM(1),  0x01, //     LOGICAL_MAXIMUM (1)
  REPORT_SIZE(1),      0x01, //     REPORT_SIZE (1)
  REPORT_COUNT(1),     0x20, //     REPORT_COUNT (32)
  HIDINPUT(1),         0x02, //     INPUT (Data, Variable, Absolute) ;32 button bits
  // ------------------------------------------------- X/Y position, Z/rZ position
  USAGE_PAGE(1), 	   0x01, //		USAGE_PAGE (Generic Desktop)
  COLLECTION(1), 	   0x00, //		COLLECTION (Physical)
  USAGE(1), 		   0x30, //     USAGE (X)
  USAGE(1), 		   0x31, //     USAGE (Y)
  USAGE(1), 		   0x32, //     USAGE (Z)
  USAGE(1), 		   0x35, //     USAGE (rZ)
  0x16, 			   0x01, 0x80,//LOGICAL_MINIMUM (-32767)
  0x26, 			   0xFF, 0x7F,//LOGICAL_MAXIMUM (32767)
  REPORT_SIZE(1), 	   0x10, //		REPORT_SIZE (16)
  REPORT_COUNT(1), 	   0x04, //		REPORT_COUNT (4)
  HIDINPUT(1), 		   0x02, //     INPUT (Data,Var,Abs)
  // ------------------------------------------------- Triggers
  USAGE(1),            0x33, //     USAGE (rX) Left Trigger
  USAGE(1),            0x34, //     USAGE (rY) Right Trigger
  LOGICAL_MINIMUM(1),  0x81, //     LOGICAL_MINIMUM (-127)
  LOGICAL_MAXIMUM(1),  0x7f, //     LOGICAL_MAXIMUM (127)
  REPORT_SIZE(1),      0x08, //     REPORT_SIZE (8)
  REPORT_COUNT(1),     0x02, //     REPORT_COUNT (2)
  HIDINPUT(1),         0x02, //     INPUT (Data, Variable, Absolute) ;4 bytes (X,Y,Z,rZ)
  END_COLLECTION(0),		 //     END_COLLECTION
  
  USAGE_PAGE(1),       0x01, //     USAGE_PAGE (Generic Desktop)
  USAGE(1),            0x39, //     USAGE (Hat switch)
  USAGE(1),            0x39, //     USAGE (Hat switch)
  LOGICAL_MINIMUM(1),  0x01, //     LOGICAL_MINIMUM (1)
  LOGICAL_MAXIMUM(1),  0x08, //     LOGICAL_MAXIMUM (8)
  REPORT_SIZE(1),      0x04, //     REPORT_SIZE (4)
  REPORT_COUNT(1),     0x02, //     REPORT_COUNT (2)
  HIDINPUT(1),         0x02, //     INPUT (Data, Variable, Absolute) ;1 byte Hat1, Hat2

  END_COLLECTION(0),         //     END_COLLECTION
  END_COLLECTION(0)          //     END_COLLECTION
};

BLEGamepad::BLEGamepad (String deviceName, String deviceManufacturer) {
	this->deviceName = deviceName;
	this->deviceManufacturer = deviceName;
	this->connectStatus = new BLEConnectionStatus();
}
