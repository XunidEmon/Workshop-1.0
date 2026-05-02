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
