#ifndef SENSORS_H
#define SENSORS_H

#include <DHT.h>

class SensorManager {
public:
  SensorManager();
  void init();
  void readSensors();
  float getTemperature();
  float getHumidity();
  bool getMotion();
  String getStatusMessage();
  
private:
  float temperature;
  float humidity;
  bool motionDetected;
  #ifdef DHT_SENSOR_ENABLED
  DHT dht;
  #endif
};

#endif