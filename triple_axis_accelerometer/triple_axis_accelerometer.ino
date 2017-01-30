// https://www.dfrobot.com/wiki/index.php/Triple_Axis_Accelerometer_MMA7361_(SKU:_DFR0143)

// zero force voltage
float zfx, zfy, zfz;

float input_voltage(int pin) {
  int a = analogRead(pin);
  return a * 5.0 / 1024; // analog --> voltage
}

void calibration() {
  Serial.print("calibration start");
  float min_x = 5, min_y = 5, min_z = 5;
  float max_x = 0, max_y = 0, max_z = 0;
  unsigned long start = millis();
  while (millis() < start + 20000) {
    float vx = input_voltage(0);
    float vy = input_voltage(1);
    float vz = input_voltage(2);
    if (vx > max_x) max_x = vx;
    if (vy > max_y) max_y = vy;
    if (vz > max_z) max_z = vz;
    if (vx < min_x) min_x = vx;
    if (vy < min_y) min_y = vy;
    if (vz < min_z) min_z = vz;
  }
  Serial.println("calibration finish");
  zfx = (min_x + max_x) / 2;
  zfy = (min_y + max_y) / 2;
  zfz = (min_z + max_z) / 2;
  Serial.print(zfx);
  Serial.print(",");
  Serial.print(zfy);
  Serial.print(",");
  Serial.println(zfz);
}

void setup() {
  Serial.begin(57600);
  calibration();
}


void loop() {
  float vx = input_voltage(0);
  float vy = input_voltage(1);
  float vz = input_voltage(2);

  // calculate the gram value
  float g_x = (vx - zfx) / 0.8;
  float g_y = (vy - zfy) / 0.8;
  float g_z = (vz - zfz) / 0.8;

  float degree_x, degree_y, degree_z;
  if(g_x <= 1 && g_x >= -1) {
    //We use this condition to prevent the overflow of asin(x).( If x>1 or x<-1, asin(x)=0)
    degree_x = asin(g_x) * 180.0 / PI;//calculate the degree value
    degree_y = asin(g_y) * 180.0 / PI;
    degree_z = asin(g_z) * 180.0 / PI;
  }
  //fix the overflow condition
  if (g_x > 1) degree_x = 90;
  if (g_x < -1) degree_x = -90;
  if (g_y > 1) degree_y = 90;
  if (g_y < -1) degree_y = -90;
  if (g_z > 1) degree_z = 90;
  if (g_z < -1) degree_z = -90;

  Serial.print("x:");
  Serial.print(degree_x);
  Serial.print(" y:");
  Serial.print(degree_y);
  Serial.print(" z:");
  Serial.println(degree_z);
  delay(200);

}
