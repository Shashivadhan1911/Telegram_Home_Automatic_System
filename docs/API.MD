# API Reference

## Telegram Bot Commands

### Basic Commands
- `/start` or `/help` - Show help message with all commands
- `/status` - Show system status (WiFi, IP, uptime, device states)
- `/allstatus` - Complete status including sensor readings

### Device Control
- `/on [device]` - Turn on a specific device
- `/off [device]` - Turn off a specific device

### Sensor Readings
- `/temp` or `/temperature` - Get current temperature
- `/humidity` - Get current humidity

### System Management
- `/restart` - Restart the ESP32 system

## Device Names

The system supports the following default device names (configurable in `config.h`):
- `light1` - Connected to GPIO12
- `light2` - Connected to GPIO13
- `fan` - Connected to GPIO14
- `outlet` - Connected to GPIO27

## Adding New Devices

1. Edit `config.h`:
   ```cpp
        #define DEVICE_COUNT 5
        const DevicePin DEVICE_PINS[DEVICE_COUNT] = {
            {"light1", 12},
            {"light2", 13},
            {"fan", 14},
            {"outlet", 27},
            {"newdevice", 26}  // Add your new device
        };
    ```
2. The system will automatically recognize the new device after restart.
## Adding New Sensors
1. **For DHT-type sensors**:
    ```cpp
        #define NEW_SENSOR_ENABLED
        #define NEW_SENSOR_PIN 33
        #define NEW_SENSOR_TYPE DHT22
    ```
2. **For digital sensors**:
    ```cpp
        #define NEW_SENSOR_ENABLED
        #define NEW_SENSOR_PIN 32
    ```
3. Update the SensorManager class to read the new sensor.

## Customizing Messages
### Edit the response formats in telegram_bot.cpp:

- showHelp() - Change the help message

- sendStatus() - Modify status format

- handleNewMessage() - Add new commands

## Security Features
- Chat ID authentication - Only authorized users can control devices

- No external API dependencies beyond Telegram

- All communication encrypted through Telegram's protocol