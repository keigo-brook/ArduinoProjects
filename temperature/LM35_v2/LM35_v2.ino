void setup() {
  Serial.begin(9600);
}

void loop() {
  uint16_t val;
  double dat;
  val = analogRead(A0);
  dat = (double)val * (5 / 10.24);
  Serial.println(dat);
  delay(10000);
}
