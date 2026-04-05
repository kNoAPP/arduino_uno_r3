#include <Arduino.h>
#include <Servo.h>

#define POTENTIOMETER_PIN A0

#define SERVO_PIN 9
Servo servo;

// put function declarations here:
void setupPins();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  setupPins();
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(POTENTIOMETER_PIN);
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);

  int angle = map(potValue, 0, 1023, 0, 179);
  servo.write(angle);

  // Allow some time for the servo to reach the position
  delay(15);
}

// put function definitions here:
void setupPins() {
  pinMode(POTENTIOMETER_PIN, INPUT);

  pinMode(SERVO_PIN, OUTPUT);
  servo.attach(SERVO_PIN);
}