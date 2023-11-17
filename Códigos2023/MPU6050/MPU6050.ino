

#include <MPU6050_tockn.h>
#include <Wire.h>
const uint8_t scl = D5;
const uint8_t sda = D6;

MPU6050 mpu6050(Wire);
int angulo;

const int pwmMotorA = D1;
const int pwmMotorB = D2;
const int dirMotorA = D3;
const int dirMotorB = D4;

int motorSpeed = 100;
int motorSpeedNegativo = -100;
int parar = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin(sda, scl);
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  pinMode(pwmMotorA , OUTPUT);
  pinMode(pwmMotorB, OUTPUT);
  pinMode(dirMotorA, OUTPUT);
  pinMode(dirMotorB, OUTPUT);
}
void direita(){
  
  mpu6050.calcGyroOffsets(true);
  mpu6050.update();
  
  while (mpu6050.getAngleZ()<= 90){
    
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());
  
  analogWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, HIGH);
  analogWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, HIGH);
    }
   Serial.print("sair");
  analogWrite(pwmMotorA, parar);
  digitalWrite(dirMotorA, LOW);
  analogWrite(pwmMotorB, parar);
  digitalWrite(dirMotorB, LOW);
  }
void loop() {
   mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());
 
   direita();
}
