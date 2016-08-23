const int THERMISTOR = 1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float t = 0.0;
  t = tempMeasure();
  Serial.print("Temp = ");
  Serial.print(t);
  Serial.println("C");
  delay(1000);
}

float tempMeasure() {
  // from MF11-503K spec sheet
  const float B = 4350.0, Ta = 25.0, Rt0 = 50000.0;
  const float K = 273.15;
  // v0: Arduino + 5V
  const float v0 = 5.0, r0 = 1000.0;
  const int resolution = 1024;
  int srcVal = 0;
  float vt = 0.0, rt = 0.0;

  srcVal = analogRead(THERMISTOR);
  vt = srcVal * (v0 / (resolution - 1));
  rt = (v0 * r0 - vt * r0) / vt;
  return (1.0 / (log(rt / Rt0) / B + 1.0 / (Ta + K)) - K);
}

