void setup() {
  Serial.begin(9600);
}

void loop() {
  int in = Serial.read();
  if (in == '1') {
    Serial.write(1);
  } else {
  }
}
