
#include <MPU6050_tockn.h>
#include <Wire.h>
const uint8_t scl = D5;
const uint8_t sda = D6;
MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin(sda, scl);
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());
}
