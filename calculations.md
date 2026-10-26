# Battery Monitoring Calculations

## 1. Battery Voltage
Vbattery = VADC × (R1 + R2) / R2

Where:
- R1 = 100 kΩ
- R2 = 33 kΩ

## 2. Current Measurement
For an ACS712 5 A sensor:

Current = (Vout - Vzero) / 0.185

Where:
- Vout = sensor output voltage
- Vzero = calibrated zero-current output voltage
- 0.185 V/A = approximate sensitivity

## 3. Temperature
For an LM35 sensor:

Temperature (°C) = Vout (V) × 100

## 4. Power
Power (W) = Battery Voltage (V) × Current (A)

## 5. Energy
Energy (Wh) = Power (W) × Time (hours)

Note: Sensor calibration and actual circuit measurements are required for accurate results.
