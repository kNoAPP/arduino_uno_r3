#include <Arduino.h>

#define TMP36_1_PIN A0

#define LED_1_PIN 3
#define LED_2_PIN 4
#define LED_3_PIN 5
// put function declarations here:
void setupPins();
void lightLedAtTemperature(float temperatureC, float thresholdTempC, uint8_t ledPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  setupPins();

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorReading = analogRead(TMP36_1_PIN);
  Serial.print("TMP36 Sensor Reading: ");
  Serial.print(sensorReading);

  // Analog-to-Digital Converter (ADC) values range from 0 to 1023.
  // Convert the reading to a voltage (assuming a 5V reference).
  float voltage = sensorReading * (5.0 / 1023.0);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.print("V");

  // For a TMP36 sensor: Temp (°C) = (Voltage - 0.5) * 100
  float temperatureC = (voltage - 0.5) * 100.0;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(" | Temperature: ");
  Serial.print(temperatureC);
  Serial.print("°C ");
  Serial.print(temperatureF);
  Serial.println("°F");

  const float thresholdTempC = 20.0;
  lightLedAtTemperature(temperatureC, thresholdTempC, LED_1_PIN);
  lightLedAtTemperature(temperatureC, thresholdTempC + 2.0, LED_2_PIN);
  lightLedAtTemperature(temperatureC, thresholdTempC + 4.0, LED_3_PIN);

  // The TMP36 gives inaccurate readings if we read it too quickly.
  // delay(1);
}

// put function definitions here:
void setupPins() {
  pinMode(TMP36_1_PIN, INPUT);

  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
}

void lightLedAtTemperature(float temperatureC, float thresholdTempC, uint8_t ledPin) {
  if (temperatureC > thresholdTempC) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}