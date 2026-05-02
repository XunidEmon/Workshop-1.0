# Embedded Programming Workshop 1.0

This repository contains Arduino programs learned during **Embedded Programming Workshop 1.0**.
It covers fundamental concepts of embedded systems including sensors, actuators, and control logic.

---

## topics Covered

* Button & LED Control
* LED Blinking
* Timer LED
* Servo Motor
* PWM Motor Control
* Analog & Digital Sensors
* LDR (Photoresistor)
* Gas Sensor
* Obstacle Detection
* Ultrasonic Sensor

---

# 💡 1. Button Action

```cpp
#define LED 5
#define BTN 8

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(BTN) == LOW) {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
  }
}
```

---

# 💡 2. LED Blink

```cpp
void setup() {
  pinMode(A0, OUTPUT);
}

void loop() {
  digitalWrite(A0, HIGH);
  delay(1000);
  digitalWrite(A0, LOW);
  delay(1000);
}
```

---

# 💡 3. Push Button Timer LED

```cpp
#define LED 5
#define BTN 8

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(BTN) == LOW) {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
  }
}
```

---

# 🤖 4. Servo Motor

```cpp
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
```

---

# ⚙️ 5. PWM Motor Control

```cpp
int a = 2;
int b = 4;
int pwm = 3;

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(pwm, OUTPUT);
}

void loop() {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  analogWrite(pwm, 200);
  delay(1000);

  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  analogWrite(pwm, 220);
  delay(1000);
}
```

---

# 📡 6. Analog Sensor

```cpp
int sensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  delay(500);
}
```

---

# 📡 7. Digital Sensor

```cpp
int sensorPin = 2;

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorState = digitalRead(sensorPin);

  if(sensorState == HIGH) {
    Serial.println("Detected!");
  } else {
    Serial.println("Not Detected");
  }

  delay(100);
}
```

---

# 🌞 8. Photoresistor (LDR)

```cpp
void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
}

void loop() {
  int analogValue = analogRead(A5);
  float voltage = analogValue * (5.0 / 1023.0);

  Serial.print(voltage);
  Serial.println(" V");

  if(voltage > 3.0) {
    digitalWrite(5, HIGH);
    Serial.println("Light Detected");
  } else {
    digitalWrite(5, LOW);
  }

  delay(100);
}
```

---

# 🔥 9. Gas Sensor

```cpp
int GAS_SENSOR = A0;
int ALARM = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ALARM, OUTPUT);
  delay(3000);
}

void loop() {
  int val = analogRead(GAS_SENSOR);
  float volt = val * (5.0 / 1023.0);

  Serial.print("Voltage: ");
  Serial.println(volt);

  if(volt > 4.5) {
    digitalWrite(ALARM, HIGH);
    Serial.println("RED ALERT!");
  }
  else if(volt > 4.0) {
    digitalWrite(ALARM, HIGH);
    delay(100);
    digitalWrite(ALARM, LOW);
    Serial.println("ALERT");
  }
  else {
    digitalWrite(ALARM, LOW);
    Serial.println("SAFE");
  }

  delay(1000);
}
```

---

# 🚧 10. Obstacle Detection (PIR)

```cpp
int LED = 13;
int PIRPin = 11;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PIRPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int state = digitalRead(PIRPin);

  if(state == HIGH){
    Serial.println("OBSTACLE DETECTED!");
    digitalWrite(LED, HIGH);
  } else {
    Serial.println("Clear");
    digitalWrite(LED, LOW);
  }

  delay(1000);
}
```

---

# 📏 11. Ultrasonic Distance Sensor

```cpp
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  delayMicroseconds(2);
  digitalWrite(11, HIGH);
  delayMicroseconds(10);
  digitalWrite(11, LOW);

  pinMode(11, INPUT);
  long t = pulseIn(11, HIGH);

  int d = t * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(d);

  digitalWrite(13, (d < 100) ? HIGH : LOW);

  delay(500);
}
```

---


---

