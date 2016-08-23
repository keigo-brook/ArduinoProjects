#include <Wire.h>
#include <math.h>

int BH1750address = 0x23;

byte buff[2];

void setup() {
    Wire.begin();
    BH1750_Init(BH1750address);
    delay(200);
    Serial.begin(9600);
    Serial.println("Setup Done");
}

void loop() {
    int i;
    uint16_t val = 0;
    delay(200);
    if (BH1750_Read(BH1750address) == 2) {
        val = ((buff[0] << 8) | buff[1]);
        Serial.print(val, DEC);
        Serial.println("[lx]");
    }
    delay(1000);
}

int BH1750_Read(int address) {
    byte i = 0;
    Wire.beginTransmission(address);

    Wire.requestFrom(address, 2);
    while (Wire.available()) {
        buff[i] = Wire.read();
        i++;
    }

    Wire.endTransmission();
    return i;
}

void BH1750_Init(int address) {
    Wire.beginTransmission(address);
    Wire.write(0x10);
    Wire.endTransmission();
}