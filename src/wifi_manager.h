#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFi.h>

class WiFiManager {
public:
  void connect();
  void disconnect();
  bool isConnected();
  void checkConnection();
  
private:
  unsigned long lastConnectionCheck = 0;
  const unsigned long CONNECTION_CHECK_INTERVAL = 10000; // 10 seconds
};

#endif