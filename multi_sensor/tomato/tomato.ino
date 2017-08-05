#define TEMPERETURE_A A0
#define MOISTURE_A A1

void setup() {
  Serial.begin(9600);
}

void loop() {
  int in = Serial.read();
  if (in == '1') {
    // read tempereture
    uint16_t val;
    double dat;
    val = analogRead(TEMPERETURE_A);
    dat = (double)val * (5 / 10.24);
    Serial.println(dat);
  } else if (in == '0') {
    // read moisture
    double analogValue = (1024 - analogRead(MOISTURE_A));
    Serial.println(analogValue);
  }
}
