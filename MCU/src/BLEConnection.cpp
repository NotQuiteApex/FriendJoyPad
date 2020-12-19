#include "BLEConnection.h"

BLEConnectionStatus::BLEConnectionStatus(void) {
}

void BLEConnectionStatus::onConnect(BLEServer* pServer)
{
  this->connected = true;
  BLE2902* desc = (BLE2902*)this->inputGamepad->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
  desc->setNotifications(true);
}

void BLEConnectionStatus::onDisconnect(BLEServer* pServer)
{
  this->connected = false;
  BLE2902* desc = (BLE2902*)this->inputGamepad->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
  desc->setNotifications(false);
}