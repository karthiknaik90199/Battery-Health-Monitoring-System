# Battery-Health-Monitoring-System
Battery Health Monitoring System using Arduino UNO, ACS712 current sensor, LM35 temperature sensor, and a voltage divider. Monitors battery voltage, current, temperature, power, and energy consumption, with real-time readings displayed on an I2C OLED. Developed using Embedded C/C++, Arduino IDE, and Proteus simulation.
# BMS & Mobile Charger Monitoring System

## Project Overview
An embedded systems prototype for monitoring battery and mobile charger parameters using Arduino UNO and Proteus simulation.

## Main Features
- Battery voltage monitoring using a voltage divider
- Current measurement using the ACS712 sensor
- Temperature measurement using the LM35 sensor
- Power calculation using voltage and current
- Energy consumption calculation
- Real-time parameter display on an I2C OLED

## Hardware Components
- Arduino UNO
- ACS712 current sensor
- LM35 temperature sensor
- 100 kΩ and 33 kΩ resistors
- OLED I2C display
- 12 V battery

## Software and Tools
- Embedded C/C++ (Arduino)
- Arduino IDE
- Proteus Design Suite

## Calculations
- Battery voltage: Vbattery = VADC × (R1 + R2) / R2
- Power: P = V × I
- Energy: E = P × time

## Project Status
Prototype under development. Sensor calibration, validation, and battery protection testing are required before real-world use.

## Future Improvements
- Overvoltage and undervoltage protection
- Overcurrent and overtemperature shutdown
- Battery state-of-charge estimation
- Fault indication and data logging
- ESP32-based wireless monitoring
