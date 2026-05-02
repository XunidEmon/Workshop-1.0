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
