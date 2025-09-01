#include "device_control.h"
#include "config.h"
#include <Arduino.h>

DeviceController::DeviceController() {
  deviceCount = sizeof(DEVICE_PINS) / sizeof(DevicePin);
}

void DeviceController::init() {
  for (int i = 0; i < deviceCount; i++) {
    pinMode(DEVICE_PINS[i].pin, OUTPUT);
    digitalWrite(DEVICE_PINS[i].pin, LOW);
    deviceStates[i] = false;
    Serial.println("Initialized device: " + String(DEVICE_PINS[i].name) + " on pin " + String(DEVICE_PINS[i].pin));
  }
  Serial.println("Total devices initialized: " + String(deviceCount));
}

bool DeviceController::controlDevice(String deviceName, bool state) {
  for (int i = 0; i < deviceCount; i++) {
    if (deviceName.equalsIgnoreCase(DEVICE_PINS[i].name)) {
      digitalWrite(DEVICE_PINS[i].pin, state ? HIGH : LOW);
      deviceStates[i] = state;
      
      // Log the action
      Serial.println("Device " + String(DEVICE_PINS[i].name) + " turned " + (state ? "ON" : "OFF"));
      return true;
    }
  }
  return false;
}

bool DeviceController::getDeviceState(int index) {
  if (index >= 0 && index < deviceCount) {
    return deviceStates[index];
  }
  return false;
}

String DeviceController::getDeviceName(int index) {
  if (index >= 0 && index < deviceCount) {
    return DEVICE_PINS[index].name;
  }
  return "";
}

int DeviceController::getDeviceCount() {
  return deviceCount;
}

void DeviceController::handleScheduledTasks() {
  // Implement scheduled tasks based on time
  // For example: turn on lights at sunset, etc.
  
  // This would typically check the current time and
  // perform actions based on a schedule defined in config.h
  
  // Example:
  // if (isNightTime() && !deviceStates[0]) {
  //   controlDevice("light1", true);
  // }
}