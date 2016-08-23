void setup() {
  Serial.begin(115200);
}

char a;
void loop() {
  Serial.println("HELLO WORLD");
  delay(1000);
  if (Serial.available()) {
    a = (Serial.read());
    if (a == '1') {
      Serial.println("HELLO");
    }
  }
}
