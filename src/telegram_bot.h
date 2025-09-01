#ifndef TELEGRAM_BOT_H
#define TELEGRAM_BOT_H

#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>

class TelegramBot {
public:
  TelegramBot();
  void init();
  void handleMessages();
  void sendMessage(String message);
  void sendMessageToAdmin(String message);
  
private:
  WiFiClientSecure client;
  UniversalTelegramBot bot;
  
  void handleNewMessage(String chat_id, String text);
  void showHelp(String chat_id);
  void handleDeviceControl(String chat_id, String text, bool turnOn);
  void sendStatus(String chat_id);
  void sendAllStatus(String chat_id);
  void sendTemperature(String chat_id);
  void sendHumidity(String chat_id);
  String formatUptime();
  bool isAuthorized(String chat_id);
};

#endif