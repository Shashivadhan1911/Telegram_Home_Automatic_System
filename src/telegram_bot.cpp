#include "telegram_bot.h"
#include "device_control.h"
#include "sensors.h"
#include "config.h"
#include "secrets.h"

extern DeviceController deviceController;
extern SensorManager sensorManager;

TelegramBot::TelegramBot() : bot(BOT_TOKEN, client) {}

void TelegramBot::init() {
  // Configure WiFiClientSecure for Telegram
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  
  // Test Telegram connection
  Serial.print("Testing Telegram connection... ");
  if (bot.getMe()) {
    Serial.println("OK");
  } else {
    Serial.println("FAILED");
  }
}

void TelegramBot::handleMessages() {
  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

  while (numNewMessages) {
    Serial.println("Got response");
    handleNewMessage(bot.messages[0].chat_id, bot.messages[0].text);
    numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  }
}

void TelegramBot::handleNewMessage(String chat_id, String text) {
  Serial.println("Message from " + chat_id + ": " + text);
  
  // Check if user is authorized
  if (!isAuthorized(chat_id)) {
    bot.sendMessage(chat_id, "Unauthorized access. Contact administrator.");
    return;
  }

  text.toLowerCase();
  
  if (text == "/start" || text == "/help") {
    showHelp(chat_id);
  } else if (text == "/status") {
    sendStatus(chat_id);
  } else if (text.startsWith("/on")) {
    handleDeviceControl(chat_id, text, true);
  } else if (text.startsWith("/off")) {
    handleDeviceControl(chat_id, text, false);
  } else if (text == "/temp" || text == "/temperature") {
    sendTemperature(chat_id);
  } else if (text == "/humidity") {
    sendHumidity(chat_id);
  } else if (text == "/allstatus") {
    sendAllStatus(chat_id);
  } else if (text == "/restart") {
    bot.sendMessage(chat_id, "Restarting system...");
    ESP.restart();
  } else {
    bot.sendMessage(chat_id, "Unknown command. Type /help for available commands.");
  }
}

void TelegramBot::showHelp(String chat_id) {
  String helpMessage = "🏠 *Home Automation Bot* 🏠\n\n";
  helpMessage += "*/help* - Show this help message\n";
  helpMessage += "*/status* - Show system status\n";
  helpMessage += "*/on [device]* - Turn on device (e.g., /on light1)\n";
  helpMessage += "*/off [device]* - Turn off device\n";
  helpMessage += "*/temp* - Current temperature\n";
  helpMessage += "*/humidity* - Current humidity\n";
  helpMessage += "*/allstatus* - Full status report\n";
  helpMessage += "*/restart* - Restart the system\n\n";
  helpMessage += "*Available devices:* ";
  
  for (int i = 0; i < deviceController.getDeviceCount(); i++) {
    helpMessage += deviceController.getDeviceName(i) + " ";
  }
  
  bot.sendMessage(chat_id, helpMessage, "Markdown");
}

void TelegramBot::handleDeviceControl(String chat_id, String text, bool turnOn) {
  String deviceName = text.substring(turnOn ? 3 : 4);
  deviceName.trim();
  
  if (deviceName.length() == 0) {
    bot.sendMessage(chat_id, "Please specify a device. Example: /on light1");
    return;
  }
  
  if (deviceController.controlDevice(deviceName, turnOn)) {
    String message = "✅ Turned " + String(turnOn ? "on " : "off ") + deviceName;
    bot.sendMessage(chat_id, message);
    
    // Log the action
    String logMessage = "User " + chat_id + " turned " + 
                       String(turnOn ? "on " : "off ") + deviceName;
    Serial.println(logMessage);
  } else {
    bot.sendMessage(chat_id, "❌ Device not found: " + deviceName);
  }
}

void TelegramBot::sendStatus(String chat_id) {
  String status = "📊 *System Status:*\n";
  status += "• WiFi: " + String(WiFi.status() == WL_CONNECTED ? "Connected" : "Disconnected") + "\n";
  status += "• IP: " + WiFi.localIP().toString() + "\n";
  status += "• Uptime: " + formatUptime() + "\n";
  status += "• Free memory: " + String(ESP.getFreeHeap()) + " bytes\n";
  status += "\n*Devices:*\n";
  
  for (int i = 0; i < deviceController.getDeviceCount(); i++) {
    status += "• " + deviceController.getDeviceName(i) + ": " + 
              (deviceController.getDeviceState(i) ? "🟢 ON" : "🔴 OFF") + "\n";
  }
  
  bot.sendMessage(chat_id, status, "Markdown");
}

void TelegramBot::sendAllStatus(String chat_id) {
  sendStatus(chat_id);
  sendTemperature(chat_id);
  sendHumidity(chat_id);
  
  #ifdef PIR_SENSOR_ENABLED
  String motionStatus = "• Motion: " + String(sensorManager.getMotion() ? "Detected" : "No motion");
  bot.sendMessage(chat_id, motionStatus);
  #endif
}

void TelegramBot::sendTemperature(String chat_id) {
  float temp = sensorManager.getTemperature();
  String emoji = (temp > 30) ? "🔥" : (temp < 18) ? "❄️" : "🌡";
  bot.sendMessage(chat_id, emoji + " Temperature: " + String(temp) + "°C");
}

void TelegramBot::sendHumidity(String chat_id) {
  float humidity = sensorManager.getHumidity();
  String emoji = (humidity > 70) ? "💧" : (humidity < 30) ? "🏜" : "💦";
  bot.sendMessage(chat_id, emoji + " Humidity: " + String(humidity) + "%");
}

String TelegramBot::formatUptime() {
  long seconds = millis() / 1000;
  int days = seconds / 86400;
  seconds = seconds % 86400;
  int hours = seconds / 3600;
  seconds = seconds % 3600;
  int minutes = seconds / 60;
  seconds = seconds % 60;
  
  return String(days) + "d " + String(hours) + "h " + String(minutes) + "m " + String(seconds) + "s";
}

bool TelegramBot::isAuthorized(String chat_id) {
  // Check if the chat ID is in the authorized list
  for (int i = 0; i < AUTHORIZED_USERS_COUNT; i++) {
    if (chat_id == AUTHORIZED_USERS[i]) {
      return true;
    }
  }
  return false;
}

void TelegramBot::sendMessage(String message) {
  bot.sendMessage(ADMIN_CHAT_ID, message);
}

void TelegramBot::sendMessageToAdmin(String message) {
  sendMessage(message);
}