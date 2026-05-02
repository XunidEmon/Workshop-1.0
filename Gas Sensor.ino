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
