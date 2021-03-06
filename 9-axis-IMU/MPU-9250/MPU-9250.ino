// http://www.lucidarme.me/?p=5057

#include <Wire.h>

#define MPU9250_ADDRESS 0x68
#define MAG_ADDRESS 0x0C

#define GYRO_FULL_SCALE_250_DPS 0x00
#define GYRO_FULL_SCALE_500_DPS 0x08
#define GYRO_FULL_SCALE_1000_DPS 0x10
#define GYRO_FULL_SCALE_2000_DPS 0x18

#define ACC_FULL_SCALE_2_G 0x00
#define ACC_FULL_SCALE_4_G 0x08
#define ACC_FULL_SCALE_8_G 0x10
#define ACC_FULL_SCALE_16_G 0x18

#define MAG_16BIT 0x10
#define MAG_8HZ 0x02
#define MAG_100HZ 0x06

// This function read Nbytes bytes form I2C device at address Address.
// Put read bytes starting at register Register in the Data array.
void I2Cread(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data) {
  // Set register address
  Wire.beginTransmission(Address);
  Wire.write(Register);
  Wire.endTransmission();

  // Read Nbytes
  Wire.requestFrom(Address, Nbytes);
  uint8_t index=0;
  while (Wire.available()) {
    Data[index++] = Wire.read();
  }
}


// Write a byte (Data) in device (Address) at register (Register)
void I2CwriteByte(uint8_t Address, uint8_t Register, uint8_t Data) {
  // Set register address
  Wire.beginTransmission(Address);
  Wire.write(Register);
  Wire.write(Data);
  Wire.endTransmission();
}

void setup() {
  // Arduino initializations
  Wire.begin();
  Serial.begin(115200);

  // Set accelerometers low pass filter at 5Hz
  I2CwriteByte(MPU9250_ADDRESS, 29, 0x06);
  // Set gyroscope low pass filter at 5Hz
  I2CwriteByte(MPU9250_ADDRESS, 26, 0x06);


  // Configure gyroscope range
  I2CwriteByte(MPU9250_ADDRESS, 27, GYRO_FULL_SCALE_2000_DPS);
  // Configure accelerometers range
  I2CwriteByte(MPU9250_ADDRESS, 28, ACC_FULL_SCALE_16_G);
  // Set by pass mode for the magnetometers
  I2CwriteByte(MPU9250_ADDRESS, 0x37, 0x02);

  // Request continuous magnetometer measurements in 16bits, 100Hz
  I2CwriteByte(MAG_ADDRESS, 0x0A, (MAG_16BIT | MAG_100HZ));
}

long int cpt = 0;
void loop() {
  // Counter
  // Display data counter
  Serial.print(cpt++, DEC);
  Serial.print("\t");

  // Accelerometer and gyroscope

  // Read
  uint8_t Buf[14];
  // 0x3Bから14byteに加速度，ジャイロのデータが入っている
  I2Cread(MPU9250_ADDRESS, 0x3B, 14, Buf);

  // Create 16bits values from 8bits data

  // Accelerometer
  int16_t ax = -(Buf[0] << 8 | Buf[1]);
  int16_t ay = -(Buf[2] << 8 | Buf[3]);
  int16_t az = Buf[4] << 8 | Buf[5];

  // Gyroscope
  int16_t gx = -(Buf[8] << 8 | Buf[9]);
  int16_t gy = -(Buf[10] << 8 | Buf[11]);
  int16_t gz = Buf[12] << 8 | Buf[13];

  // Display

  // Accelerometer
  Serial.print(ax, DEC);
  Serial.print("\t");
  Serial.print(ay, DEC);
  Serial.print("\t");
  Serial.print(az, DEC);
  Serial.print("\t");

  // Gyroscope
  Serial.print(gx, DEC);
  Serial.print("\t");
  Serial.print(gy, DEC);
  Serial.print("\t");
  Serial.print(gz, DEC);
  Serial.print("\t");


  // Magnetometer

  // Read register status 1 and wait for the DRDY: Data Ready

  uint8_t ST1 = 0;
  do {
    I2Cread(MAG_ADDRESS, 0x02, 1, &ST1);
  } while (!(ST1 & 0x01));

  // Read magnetometer data
  uint8_t Mag[7];
  I2Cread(MAG_ADDRESS, 0x03, 7, Mag);

  // Create 16bits values from 8 bits dta
  int16_t mx = -(Mag[3] << 8 | Mag[2]);
  int16_t my = -(Mag[1] << 8 | Mag[0]);
  int16_t mz = -(Mag[5] << 8 | Mag[4]);

  // Display
  Serial.print(mx + 200, DEC);
  Serial.print("\t");
  Serial.print(my - 70, DEC);
  Serial.print("\t");
  Serial.print(mz - 700, DEC);

  Serial.println("");
  /* delay(100); */
}
