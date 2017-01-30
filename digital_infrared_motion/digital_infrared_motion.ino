/*
  https://www.dfrobot.com/wiki/index.php/Digital_Infrared_motion_sensor_(SKU:SEN0018)
  This is a simple to use motion sensor.
  Power it up and wait 1-2 seconds for the sensor to get a snapshot of the still room.
  If anything moves after that period, the 'alarm' pin will go low.
 */

const int buttonPin = 2;
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}