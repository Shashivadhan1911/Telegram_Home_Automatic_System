# Telegram_Home_Automatic_System

A diploma major project enabling IoT-based home automation via Telegram bot. Control lights, fans, and other appliances using Telegram commands.

##  Features

- 🏠 Remote home appliance control (lights, fans, etc.) via Telegram.
- 🤖 Telegram bot integration for command-based control.
-  Support for turning devices on/off and querying device status.
-  Potential for future enhancements like scheduled automation or sensor notifications.

##  Tech Stack

| Component            | Description                          |
|----------------------|--------------------------------------|
| **Language**         | C++ (Arduino / ESP32 / ESP8266)      |
| **Bot**              | Telegram Bot API                     |
| **Controller**       | ESP32 or ESP8266 (NodeMCU)           |
| **Connectivity**     | Wi-Fi (via embedded board)           |
| **IDE**              | Arduino IDE / PlatformIO             |
| **Extras (Optional)**| Sensors, relay modules, safety checks|

##  Prerequisites

- A working Telegram account and the Telegram app.
- Create a Telegram bot using [BotFather](https://telegram.me/BotFather) and obtain the **bot token**.
- Your Telegram user/chat ID (to restrict access to yourself).
- Hardware such as:
  - ESP32 or ESP8266 (NodeMCU)
  - Relay module(s) for controlling appliances
  - Optional: Wires, breadboard, power supply, sensors (for future extension)
- Arduino IDE or PlatformIO installed on your computer.

##  Setup & Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/Shashivadhan1911/Telegram_Home_Automatic_System.git
   cd Telegram_Home_Automatic_System
   ```
2. **Open in IDE**

- Use Arduino IDE or PlatformIO to open the project.

3. **Configure the code**

- Insert your Wi-Fi credentials (SSID and password).

- Input your Telegram Bot Token.

- Set your Telegram user/chat ID to restrict command access.

4. **Deploy to ESP board**

- Compile and upload the code to your ESP32 or ESP8266 controller.

5. **Start controlling!**

- Open Telegram, initiate a chat with your bot, and send commands.
### Basic Commands (Example)
   ```pgsql
    /start      – Display welcome instructions
    /turnon X   – Turn on device X (e.g., light, fan)
    /turnoff X  – Turn off device X
    /status X   – Get the current status of device X
   ```
## Circuit & Wiring 

- Connect GPIO pins of your ESP board to a relay module to control appliances.

- Supply appropriate power (typically 5 V for the relay module, provided by the board or an external supply).

- Ensure proper grounding and isolation for safety.

## Future Enhancements

- Sensor integration: e.g., temperature, motion, light.

- Scheduling or conditional automation (e.g., timer-based or sensor-triggered actions).

- Push notifications or status updates via Telegram.

- Secure access using user authentication or feedback messages.

- Expand to support voice commands or dashboard interfaces.

## Troubleshooting

- **No response from bot**: Double-check bot token and user/chat ID configurations.

- **Unauthorized access error**: Ensure your user ID is correctly entered and Telegram user matches.

- **Wi-Fi connection fails**: Verify SSID/password, check hardware stability.

- **Relay/board not responding**: Confirm wiring, power supply, and GPIO mappings.
- 
## License

This project is open-source under the MIT License.

---

## ✨ End Note

This project was developed as a **Diploma Major Project** with the goal of making home automation simple, affordable, and accessible through a familiar platform like **Telegram**.  

By blending IoT and messaging technology, it demonstrates how everyday devices can be controlled securely and remotely.  

🔧 Feel free to fork, improve, and expand this project — whether it’s adding sensors, creating smarter automation, or building a complete IoT ecosystem.  
⭐ If you find this project useful, don’t forget to **star the repo** and share it with others who love IoT & automation!
