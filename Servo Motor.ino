#include <Servo.h>

Servo x;
int servoPin = 3;

void setup() {
  x.attach(servoPin);
  Serial.begin(9600);

  x.write(150);
  delay(1000);
}

void loop() {}
