#include <Arduino.h>
#include "wifi_manager.h"
#include "telegram_bot.h"
#include "device_control.h"
#include "sensors.h"

// Global objects
WiFiManager wifiManager;
TelegramBot telegramBot;
DeviceController deviceController;
SensorManager sensorManager;

unsigned long lastSensorReadTime = 0;
const unsigned long SENSOR_READ_INTERVAL = 30000; // 30 seconds

void setup() {
  Serial.begin(115200);
  
  // Initialize components
  wifiManager.connect();
  telegramBot.init();
  deviceController.init();
  sensorManager.init();
  
  Serial.println("Home Automation System Started");
  telegramBot.sendMessage("System started successfully!");
}

void loop() {
  telegramBot.handleMessages();
  
  // Read sensors at regular intervals
  if (millis() - lastSensorReadTime > SENSOR_READ_INTERVAL) {
    sensorManager.readSensors();
    String status = sensorManager.getStatusMessage();
    telegramBot.sendMessageToAdmin(status);
    lastSensorReadTime = millis();
  }
  
  // Handle any scheduled tasks
  deviceController.handleScheduledTasks();
  
  delay(100);
}