int analogPin0 = 0;
int analogPin1 = 1;
int val0 = 0;
int val1 = 0;
char trans[20];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9800);
}

void loop() {
  // put your main code here, to run repeatedly:
  memset(trans, 0,20);
  char *json = &trans[0];
  val0 = analogRead(analogPin0);
  val1 = analogRead(analogPin1);
  Serial.println(val0);
  Serial.println(val1);
//  sprintf(json, "{\"val0\":%d, \"val1\":%d}", val0, val1);
//  Serial.println(json);
  delay(100);
}
