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
