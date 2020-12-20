#include <BLEDevice.h>
#include <BLEHIDDevice.h>

#include "BLEGamepad.h"
#include "BLEConnection.h"

const u8 _hidReportDescriptor[] = {
	USAGE_PAGE(1),      0x01, // USAGE_PAGE (Generic Desktop)
	USAGE(1),           0x05, // USAGE (Gamepad)
	COLLECTION(1),      0x01, // COLLECTION (Application)
	USAGE(1),           0x01, // USAGE (Pointer)
	COLLECTION(1),      0x00, // COLLECTION (Physical)
	// ------------------------------------------------- Buttons (1 to 32)
	USAGE_PAGE(1),      0x09, // USAGE_PAGE (Button)
	USAGE_MINIMUM(1),   0x01, // USAGE_MINIMUM (Button 1)
	USAGE_MAXIMUM(1),   0x20, // USAGE_MAXIMUM (Button 32)
	LOGICAL_MINIMUM(1), 0x00, // LOGICAL_MINIMUM (0)
	LOGICAL_MAXIMUM(1), 0x01, // LOGICAL_MAXIMUM (1)
	REPORT_SIZE(1),     0x01, // REPORT_SIZE (1)
	REPORT_COUNT(1),    0x20, // REPORT_COUNT (32)
	HIDINPUT(1),        0x02, // INPUT (Data, Variable, Absolute) ;32 button bits
	// ------------------------------------------------- X/Y position, Z/rZ position
	USAGE_PAGE(1),      0x01, //      USAGE_PAGE (Generic Desktop)
	COLLECTION(1),      0x00, //      COLLECTION (Physical)
	USAGE(1),           0x30, //      USAGE (X)
	USAGE(1),           0x31, //      USAGE (Y)
	USAGE(1),           0x32, //      USAGE (Z)
	USAGE(1),           0x35, //      USAGE (rZ)
	LOGICAL_MINIMUM(2), 0x00,0x00, // LOGICAL_MINIMUM (0)
	LOGICAL_MAXIMUM(2), 0x00,0x10, // LOGICAL_MAXIMUM (4096)
	REPORT_SIZE(1),     0x10, //      REPORT_SIZE (16)
	REPORT_COUNT(1),    0x04, //      REPORT_COUNT (4)
	HIDINPUT(1),        0x02, //      INPUT (Data,Var,Abs)
	// ------------------------------------------------- Triggers
	USAGE(1),           0x33, // USAGE (rX) Left Trigger
	USAGE(1),           0x34, // USAGE (rY) Right Trigger
	LOGICAL_MINIMUM(1), 0x81, // LOGICAL_MINIMUM (-127)
	LOGICAL_MAXIMUM(1), 0x7f, // LOGICAL_MAXIMUM (127)
	REPORT_SIZE(1),     0x08, // REPORT_SIZE (8)
	REPORT_COUNT(1),    0x02, // REPORT_COUNT (2)
	HIDINPUT(1),        0x02, // INPUT (Data, Variable, Absolute) ;4 bytes (X,Y,Z,rZ)
	END_COLLECTION(0),        // END_COLLECTION
	
	USAGE_PAGE(1),      0x01, // USAGE_PAGE (Generic Desktop)
	USAGE(1),           0x39, // USAGE (Hat switch)
	USAGE(1),           0x39, // USAGE (Hat switch)
	LOGICAL_MINIMUM(1), 0x01, // LOGICAL_MINIMUM (1)
	LOGICAL_MAXIMUM(1), 0x08, // LOGICAL_MAXIMUM (8)
	REPORT_SIZE(1),     0x04, // REPORT_SIZE (4)
	REPORT_COUNT(1),    0x02, // REPORT_COUNT (2)
	HIDINPUT(1),        0x02, // INPUT (Data, Variable, Absolute) ;1 byte Hat1, Hat2

	END_COLLECTION(0), // END_COLLECTION
	END_COLLECTION(0)  // END_COLLECTION
};

BLEGamepad::BLEGamepad (std::string deviceName, std::string deviceManufacturer) {
	this->deviceName = deviceName;
	this->deviceManufacturer = deviceName;
	this->connectStatus = new BLEConnectionStatus();
}

void BLEGamepad::begin () {
	xTaskCreate(this->taskServer, "server", 20000, (void*)this, 5, NULL);
}

void BLEGamepad::send () {
	if (this->connectStatus->connected) {
		// Pack the data into an array to send over
		u8 m[15];

		m[0] = this->buttons;
		m[1] = this->buttons >> 8;
		m[2] = this->buttons >> 16;
		m[3] = this->buttons >> 24;

		m[4] = this->leftStickX;
		m[5] = this->leftStickX >> 8;
		m[6] = this->leftStickY;
		m[7] = this->leftStickY >> 8;
		
		m[8] = this->rightStickX;
		m[9] = this->rightStickX >> 8;
		m[10] = this->rightStickY;
		m[11] = this->rightStickY >> 8;

		m[12] = this->leftTrigger;
		m[13] = this->leftTrigger;

		m[14] = this->hatDirection;

		this->gamepad->setValue(m, sizeof(m));
		this->gamepad->notify();
	}
}

void BLEGamepad::taskServer (void * pvParameter) {
	BLEGamepad * self = (BLEGamepad *) pvParameter;
	BLEDevice::init(self->deviceName);
	BLEServer * pServer = BLEDevice::createServer();
	pServer->setCallbacks(self->connectStatus);

	self->hid = new BLEHIDDevice(pServer);
	self->gamepad = self->hid->inputReport(0);
	self->connectStatus->inputGamepad = self->gamepad;

	self->hid->manufacturer()->setValue(self->deviceManufacturer);
	self->hid->pnp(0x1, 0x2e5, 0xabcc, 0x110);
	self->hid->hidInfo(0x0, 0x1);
	self->hid->reportMap((uint8_t*)_hidReportDescriptor, sizeof(_hidReportDescriptor));
	self->hid->startServices();

	self->onStarted(pServer);

	BLEAdvertising * pAdvert = pServer->getAdvertising();
	pAdvert->setAppearance(HID_GAMEPAD);
	pAdvert->addServiceUUID(self->hid->hidService()->getUUID());
	pAdvert->start();
	self->hid->setBatteryLevel(-1);

	vTaskDelay(portMAX_DELAY);
}
