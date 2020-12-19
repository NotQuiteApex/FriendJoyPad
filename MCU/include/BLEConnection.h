#ifndef BLE_CONNECTION_H
#define BLE_CONNECTION_H

#include <BLEServer.h>
#include "BLE2902.h"
#include "BLECharacteristic.h"

class BLEConnectionStatus : public BLEServerCallbacks
{
public:
  BLEConnectionStatus();
  bool connected = false;
  void onConnect(BLEServer* pServer);
  void onDisconnect(BLEServer* pServer);
  BLECharacteristic* inputGamepad;
};

#endif // ESP32_BLE_CONNECTION_STATUS_H