# Workshop-1.0





BUTTON ACTION:
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









LED BLINK:
void setup() {
  pinMode(A0, OUTPUT);   
  digitalWrite(A0, HIGH); 
}

void loop() {
  
}

void setup() {
  pinMode(A0, OUTPUT);  // A0 output 
}

void loop() {
  digitalWrite(A0, HIGH);  // A0 pin ON
  delay(1000);              // 1 second wait

  digitalWrite(A0, LOW);   // A0 pin OFF
  delay(1000);              // 1 second wait
}















Push Button Timer LED:
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



















Servo Motor:
#include <Servo.h>
Servo x;
int servoPin = 3;

void setup() {
  x.attach(servoPin);
  Serial.begin(9600);
  
  // Test positions
  x.write(150);
  delay(1000);
 
}

void loop() {
  
}














PWM Motor Control:
int a = 2;
int b = 4;
int pwm = 3;

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(pwm, OUTPUT);

  // Start motor clockwise
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  analogWrite(pwm, 200); // Speed 0-255
}

void loop() {
  
}

int a = 2;    // IN1
int b = 4;    // IN2
int pwm = 3;  // Enable / PWM pin

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(pwm, OUTPUT);
}





void loop() {
  // Motor clockwise
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  analogWrite(pwm, 200);  // Speed 0-255
  delay(1000);             // 1 second

  // Motor anti-clockwise
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  analogWrite(pwm, 220);  // Speed 0-255
  delay(1000);             // 1 second
}















Sensor:
int sensorPin = A0;
int sensorValue = 0;

void setup() {
  Serial.begin(9600); 
}



void loop() {
  sensorValue = analogRead(sensorPin);
  

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
  delay(500);}

  int sensorPin = 2;  
int sensorState = 0;



void setup() {
  pinMode(sensorPin, INPUT); 
  Serial.begin(9600);
}

void loop() {
  sensorState = digitalRead(sensorPin);
  
  if(sensorState == HIGH) {
    Serial.println("Detected!");
  } else {
    Serial.println("Not Detected");
  }
  
  delay(100);
}














Photoresistor:
void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(A5);
  float voltage = analogValue * (5.0 / 1023.0);
  
  Serial.println(voltage);
  delay(100);
}




void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A5));
  delay(100);
}


   
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
    Serial.println("Light Ditect.");
  } else {
    digitalWrite(5, LOW);
  }
  
  delay(100);
}













Gas Sensor:
int GAS_SENSOR = A0;  

void setup() {
  Serial.begin(9600);
  delay(3000);
}

void loop() {
  int gasValue = analogRead(GAS_SENSOR);
  float voltage = gasValue * (5.0 / 1023.0);
  
  Serial.print("Analog Value = ");
  Serial.print(gasValue);
  Serial.print(" & Voltage = ");
  Serial.print(voltage);
  Serial.println("V");
  
  delay(1000);
}
















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
  
  Serial.print("V: ");
  Serial.print(volt, 2);
  
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
  else if(volt > 3.0) {
    digitalWrite(ALARM, LOW);
    Serial.println("SAFE");
  }
  else {
    digitalWrite(ALARM, LOW);
    Serial.println("SAFE");
  }
  
  delay(1000);
}


















Obstacle Detection:

int LED=13;
int PIRPin=11; 
int isObstacle=LOW;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(PIRPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  isObstacle=digitalRead(PIRPin);
  if (isObstacle==HIGH){
    Serial.println("OBSTACLE!!,OBSTACLE!!");
    digitalWrite(LED, HIGH);
  }
  else{
  	Serial.println("Clear");
    digitalWrite(LED, LOW);
  }
  delay(1000);
}









 




Ultrasonic Distance Sensor:

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
 //Send pulse to sensor
pinMode(11, OUTPUT);      // Set pin 11 as OUTPUT mode
digitalWrite(11, LOW);    // First set to LOW (0V)
delayMicroseconds(2);     // Wait 2 microseconds
digitalWrite(11, HIGH);   // Then set to HIGH (5V)
delayMicroseconds(10);    // Keep HIGH for 10 microseconds
digitalWrite(11, LOW);    // Set back to LOW
  
  //Read Pulse
  pinMode(11, INPUT);
  long t = pulseIn(11, HIGH);
  
  //Distance 
  int d = t * 0.034 / 2;
  
  //Show Distance In Serial Monitor.
  if(d > 0) {
    Serial.print("Distance: ");
    Serial.println(d);
  }
  
  //LED
  digitalWrite(13, (d < 100) ? HIGH : LOW);
  
  delay(500);
}
