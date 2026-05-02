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
