// https://www.dfrobot.com/wiki/index.php/Joystick_Module_For_Arduino_SKU:DFR0061
int X = 0;
int Y = 1;
int Z = 0;

void setup() {
  pinMode(Z, INPUT);
  Serial.begin(9600);
}

void loop() {
  int x, y, z;
  x = analogRead(X);
  y = analogRead(Y);
  z = digitalRead(Z);
  Serial.print(x, DEC);
  Serial.print(",");
  Serial.print(y, DEC);
  Serial.print(",");
  Serial.println(z, DEC);
}