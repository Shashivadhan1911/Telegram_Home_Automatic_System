#include "sensors.h"
#include "config.h"
#include <Arduino.h>

SensorManager::SensorManager() {
  // Initialize sensor values
  temperature = 0.0;
  humidity = 0.0;
  motionDetected = false;
  
  #ifdef DHT_SENSOR_ENABLED
  dht = DHT(DHT_PIN, DHT_TYPE);
  #endif
}

void SensorManager::init() {
  #ifdef DHT_SENSOR_ENABLED
    dht.begin();
    Serial.println("DHT sensor initialized");
  #endif
  
  #ifdef PIR_SENSOR_ENABLED
    pinMode(PIR_PIN, INPUT);
    Serial.println("PIR sensor initialized on pin " + String(PIR_PIN));
  #endif
  
  Serial.println("Sensor manager initialized");
}

void SensorManager::readSensors() {
  #ifdef DHT_SENSOR_ENABLED
    float newTemp = dht.readTemperature();
    float newHumidity = dht.readHumidity();
    
    // Only update if readings are valid
    if (!isnan(newTemp)) {
      temperature = newTemp;
    }
    if (!isnan(newHumidity)) {
      humidity = newHumidity;
    }
  #endif
  
  #ifdef PIR_SENSOR_ENABLED
    motionDetected = digitalRead(PIR_PIN) == HIGH;
  #endif
  
  Serial.println("Sensors read: Temp=" + String(temperature) + 
                 "°C, Humidity=" + String(humidity) + 
                 "%, Motion=" + String(motionDetected ? "Yes" : "No"));
}

float SensorManager::getTemperature() {
  return temperature;
}

float SensorManager::getHumidity() {
  return humidity;
}

bool SensorManager::getMotion() {
  return motionDetected;
}

String SensorManager::getStatusMessage() {
  String status = "📊 Sensor Readings:\n";
  status += "• Temperature: " + String(temperature) + "°C\n";
  status += "• Humidity: " + String(humidity) + "%\n";
  #ifdef PIR_SENSOR_ENABLED
  status += "• Motion: " + String(motionDetected ? "Detected" : "No motion");
  #endif
  return status;
}