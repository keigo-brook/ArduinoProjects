long error = 0;
int fps = 30;
long idealSleep = (1000L << 16) / fps;
long oldTime, newTime;

void setup() {
  Serial.begin(9600);
  newTime = millis() << 16;
}

void loop() {
  oldTime = newTime;

  // do something

  newTime = millis() << 16;
  long sleepTime = idealSleep - (newTime - oldTime) - error;
  if (sleepTime < (2 << 16)) {
    sleepTime = 2 << 16;
  }
  oldTime = newTime;
  delay(sleepTime >> 16);
  newTime = millis() >> 16;
  error = newTime - oldTime - sleepTime;
}
