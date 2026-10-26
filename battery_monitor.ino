
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define CURRENT_PIN A0
#define BATTERY_PIN A1
#define TEMP_PIN A2

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const float ADC_REF = 5.0;
const float ADC_MAX = 1023.0;

const float R1 = 100000.0;
const float R2 = 33000.0;

const float ACS_SENSITIVITY = 0.185;
const float ACS_ZERO_VOLTAGE = 2.5;

float voltage, current, temperature, power;

void setup()
{
    Serial.begin(9600);
    Wire.begin();

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println("OLED not detected");
        while (1);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.display();

    Serial.println("Battery Monitoring System Started");
}

void loop()
{
    // Battery voltage
    int batteryRaw = analogRead(BATTERY_PIN);

    float adcVoltage = batteryRaw * ADC_REF / ADC_MAX;

    voltage = adcVoltage * (R1 + R2) / R2;

    // LM35 temperature
    int tempRaw = analogRead(TEMP_PIN);

    float tempVoltage = tempRaw * ADC_REF / ADC_MAX;

    temperature = tempVoltage * 100.0;

    // ACS712 current
    int currentRaw = analogRead(CURRENT_PIN);

    float sensorVoltage = currentRaw * ADC_REF / ADC_MAX;

    current = (sensorVoltage - ACS_ZERO_VOLTAGE)
              / ACS_SENSITIVITY;

    // Remove small zero-current noise
    if (current > -0.05 && current < 0.05)
    {
        current = 0.0;
    }

    // Power
    power = voltage * current;

    // Virtual Terminal output
    Serial.print("Battery ADC: ");
    Serial.print(batteryRaw);
    Serial.print(" | Battery Voltage: ");
    Serial.print(voltage, 2);
    Serial.println(" V");

    Serial.print("Current ADC: ");
    Serial.print(currentRaw);
    Serial.print(" | Current: ");
    Serial.print(current, 2);
    Serial.println(" A");

    Serial.print("Temperature ADC: ");
    Serial.print(tempRaw);
    Serial.print(" | Temperature: ");
    Serial.print(temperature, 1);
    Serial.println(" C");

    Serial.print("Power: ");
    Serial.print(power, 2);
    Serial.println(" W");

    Serial.println("--------------------");

    // OLED output
    display.clearDisplay();
    display.setCursor(0, 0);

    display.print("Battery: ");
    display.print(voltage, 1);
    display.println(" V");

    display.print("Current: ");
    display.print(current, 2);
    display.println(" A");

    display.print("Temp: ");
    display.print(temperature, 1);
    display.println(" C");

    display.print("Power: ");
    display.print(power, 1);
    display.println(" W");

    display.display();

    delay(1000);
}
