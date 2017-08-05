#define ANALOG_SENSOR_PIN A0
#define DIGITAL_SENSOR_PIN 3

int analogValue;
void setup() {
  Serial.begin(9600);
}

void loop() {
  analogValue = analogRead(ANALOG_SENSOR_PIN);
  Serial.println(analogValue);
  delay(500);
}
