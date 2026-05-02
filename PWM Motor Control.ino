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
