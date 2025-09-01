// Configuration file - rename to config.h and update values

#ifndef CONFIG_H
#define CONFIG_H

// WiFi Settings
#define WIFI_SSID "Your_WiFi_SSID"
#define WIFI_PASSWORD "Your_WiFi_Password"

// Telegram Bot Settings
#define BOT_TOKEN "Your_Telegram_Bot_Token"
#define ADMIN_CHAT_ID "Your_Chat_ID"

// Telegram SSL Certificate (don't change this unless you know what you're doing)
#define TELEGRAM_CERTIFICATE_ROOT "-----BEGIN CERTIFICATE-----\n" \
"MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF\n" \
"ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UECgwGQW1hem9uMRkwFwYDVQQDDBBBbWF6\n" \
"b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL\n" \
"MAkGA1UEBhMCVVMxDzANBgNVBAoMBkFtYXpvbjEZMBcGA1UEAwwQQW1hem9uIFJv\n" \
"b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj\n" \
"ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM\n" \
"9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw\n" \
"IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6\n" \
"VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L\n" \
"93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm\n" \
"jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC\n" \
"AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA\n" \
"A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI\n" \
"U5PMCCjjmCXPI6T53iHTfIuJruydjsw2hUwsOBYk2o2/nWF09e7/3GXK+F8CLFM9\n" \
"wYfNqkPPQnGhh4M2+U4XiQ1FJrJgbN8TdwX1EEjSU5cFy5y4oF3Z+JckD/Cs6EzL\n" \
"aBhrdzs4L4kbokiPxS+Ici+MYqJ3hTl4ozFxfea4Bwn4hLkGeJZX+WK7+J4ck3g8\n" \
"kpexr6j/6pZ3MlBk0F+B1Cq8j+QSRGFV5sNfqoVk0eP0nw1WnTcdm+ux6RgNrcG+\n" \
"3e6K9twEdR+JuPZX2FldEtJp7MmR2BfNg3+Q1W\n" \
"-----END CERTIFICATE-----\n"

// Authorized users (add up to 10 chat IDs)
#define AUTHORIZED_USERS_COUNT 1
const String AUTHORIZED_USERS[AUTHORIZED_USERS_COUNT] = {
  "Your_Chat_ID"
};

// Device Configuration
struct DevicePin {
  const char* name;
  int pin;
};

#define DEVICE_COUNT 4
const DevicePin DEVICE_PINS[DEVICE_COUNT] = {
  {"light1", 12},
  {"light2", 13},
  {"fan", 14},
  {"outlet", 27}
};

// Sensor Configuration
#define DHT_SENSOR_ENABLED
#define DHT_PIN 4
#define DHT_TYPE DHT22

#define PIR_SENSOR_ENABLED
#define PIR_PIN 35

// Other Settings
#define SERIAL_BAUD_RATE 115200

#endif