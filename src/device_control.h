#ifndef DEVICE_CONTROL_H
#define DEVICE_CONTROL_H

#include <Arduino.h>

class DeviceController {
public:
  DeviceController();
  void init();
  bool controlDevice(String deviceName, bool state);
  bool getDeviceState(int index);
  String getDeviceName(int index);
  int getDeviceCount();
  void handleScheduledTasks();
  
private:
  bool deviceStates[DEVICE_COUNT];
  int deviceCount;
};

#endif