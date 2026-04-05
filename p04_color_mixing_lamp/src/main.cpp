#include <Arduino.h>

#define R_SENSOR_PIN A0
#define G_SENSOR_PIN A1
#define B_SENSOR_PIN A2

#define R_LED_PIN 11
#define G_LED_PIN 10
#define B_LED_PIN 9

// put function declarations here:
void setupPins();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  setupPins();
}

void loop() {
  // put your main code here, to run repeatedly:
  int rAdc = analogRead(R_SENSOR_PIN);
  delay(50);
  int gAdc = analogRead(G_SENSOR_PIN);
  delay(50);
  int bAdc = analogRead(B_SENSOR_PIN);
  delay(50);

  Serial.print("RGB Map: (");
  Serial.print(rAdc);
  Serial.print(", ");
  Serial.print(gAdc);
  Serial.print(", ");
  Serial.print(bAdc);
  Serial.print(") -> (");

  // Map to LED brightness (0-255)
  int rLed = map(rAdc, 0, 1023, 0, 255);
  int gLed = map(gAdc, 0, 1023, 0, 255);
  int bLed = map(bAdc, 0, 1023, 0, 255);

  Serial.print(rLed);
  Serial.print(", ");
  Serial.print(gLed);
  Serial.print(", ");
  Serial.print(bLed);
  Serial.println(")");

  analogWrite(R_LED_PIN, rLed);
  analogWrite(G_LED_PIN, gLed);
  analogWrite(B_LED_PIN, bLed);
}

// put function definitions here:
void setupPins() {
  pinMode(R_SENSOR_PIN, INPUT);
  pinMode(G_SENSOR_PIN, INPUT);
  pinMode(B_SENSOR_PIN, INPUT);

  pinMode(R_LED_PIN, OUTPUT);
  pinMode(G_LED_PIN, OUTPUT);
  pinMode(B_LED_PIN, OUTPUT);
}