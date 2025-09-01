# Setup Guide

## Hardware Setup

### Components Required
- ESP32 development board
- Relay module (4-channel recommended)
- DHT22 temperature/humidity sensor
- PIR motion sensor
- Breadboard and jumper wires
- Power supply for ESP32 and relays

### Circuit Connections

1. **Relay Connections**:
   - Connect IN1 to GPIO12 (Light 1)
   - Connect IN2 to GPIO13 (Light 2)
   - Connect IN3 to GPIO14 (Fan)
   - Connect IN4 to GPIO27 (Outlet)
   - Connect VCC to 5V
   - Connect GND to GND

2. **DHT22 Sensor**:
   - Connect VCC to 3.3V
   - Connect DATA to GPIO4
   - Connect GND to GND
   - Add a 10K resistor between VCC and DATA

3. **PIR Motion Sensor**:
   - Connect VCC to 5V
   - Connect OUT to GPIO35
   - Connect GND to GND

## Software Setup

### Prerequisites
- Arduino IDE or PlatformIO
- ESP32 board support package
- Required libraries (automatically installed with PlatformIO):
  - UniversalTelegramBot
  - WiFi
  - DHT sensor library

### Installation Steps

1. **Clone the Repository**:
   ```bash
        git clone https://github.com/yourusername/telegram-home-automation.git
        cd telegram-home-automation
   ```
2. **Configure Settings**:

- Copy firmware/src/config.h.example to firmware/src/config.h

- Copy firmware/src/secrets.h.example to firmware/src/secrets.h

- Edit both files with your specific settings

3. **PlatformIO Setup**:
   ```bash
        # Install PlatformIO if you haven't already
        pip install platformio

        # Build and upload
        pio run -t upload

        # Monitor serial output
        pio device monitor
   ```
4. **Arduino IDE Alternative**:

- Open firmware/src/main.cpp in Arduino IDE

- Install required libraries through Library Manager

- Select ESP32 board

- Upload the sketch

## Telegram Bot Setup
1. **Create a Bot**:

- Message @BotFather on Telegram

- Send /newbot and follow instructions

- Save the bot token for your secrets.h file

2. **Get Your Chat ID**:

- Send a message to @userinfobot on Telegram

- It will reply with your chat ID

- Add this to the AUTHORIZED_USERS array in config.h

3. **Start Using Your Bot**:

- Find your bot by its username

- Send /start to begin

- Use /help to see all commands

### Usage Examples
- Turn on light: /on light1

- Check temperature: /temp

- System status: /status

- Full report: /allstatus

### Troubleshooting
- If WiFi doesn't connect, check your credentials

- If Telegram doesn't work, verify your bot token

- Check serial monitor for detailed error messages
