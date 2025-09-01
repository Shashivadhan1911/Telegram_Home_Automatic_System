# Troubleshooting Guide

## Common Issues

### WiFi Connection Problems
- **Symptoms**: System doesn't connect to WiFi, constant reboots
- **Solutions**:
  - Verify SSID and password in `secrets.h`
  - Check WiFi signal strength
  - Ensure ESP32 supports your WiFi frequency (2.4GHz only)

### Telegram Bot Not Responding
- **Symptoms**: Commands not working, no response from bot
- **Solutions**:
  - Verify bot token in `secrets.h`
  - Check that your chat ID is in the authorized list
  - Ensure your ESP32 has internet connectivity

### Sensors Not Reading Correctly
- **Symptoms**: Wrong temperature/humidity values, motion sensor always on/off
- **Solutions**:
  - Check wiring connections
  - Verify sensor pins in `config.h`
  - For DHT sensors, add a pull-up resistor if needed

### Devices Not Turning On/Off
- **Symptoms**: Relays not clicking, devices not responding
- **Solutions**:
  - Check relay module power (5V)
  - Verify GPIO pins in `config.h`
  - Test relays directly with simple blink sketch

## Debugging

### Serial Monitor
The system outputs detailed information to serial monitor at 115200 baud:
- WiFi connection status
- Telegram bot interactions
- Sensor readings
- Device control actions

### LED Indicators
Add an LED to GPIO2 for visual status:
- Slow blink: Connecting to WiFi
- Fast blink: Processing Telegram message
- Solid: Connected and idle

## Performance Optimization

### Memory Issues
- Symptoms: System crashes, random reboots
- Solutions:
  - Reduce number of devices/sensors
  - Use `String` objects sparingly
  - Enable PSRAM if available

### Telegram Rate Limiting
- Symptoms: Missed messages, delayed responses
- Solutions:
  - Increase delay in main loop
  - Use webhooks instead of polling (advanced)

## Factory Reset

To reset the system to defaults:
1. Hold BOOT button while powering on
2. Upload blank sketch
3. Reupload the home automation firmware

## Getting Help

1. Check serial monitor for error messages
2. Verify all configuration settings
3. Ensure hardware connections are correct
4. Search issues on GitHub repository
5. Create a new issue with:
   - Serial monitor output
   - Your config.h (without secrets)
   - Hardware setup photos