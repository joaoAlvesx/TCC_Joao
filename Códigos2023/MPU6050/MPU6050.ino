#include <Wire.h>

#define MPU6050_ADDR 0x68 // Endereço padrão do MPU6050
float giroX, giroY, giroZ, acelX, acelY, acelZ, temperatura;  
float fator_conversao_acel = 16384;
float fator_conversao_giro = 131;

void setup() {
  Serial.begin(115200);
  Wire.begin(D6, D5); // SDA em D6, SCL em D5
  // Inicialização do MPU6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B); // Registrador de energia
  Wire.write(0);    // Ligar o MPU6050 (bit zero setado para 0)
   Wire.endTransmission(true);

   Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x1B);
  Wire.write(0b00000000); // setamos o fundo de escala para +/- 250º /s
  Wire.endTransmission();

  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x1C);
  Wire.write(0b00000000); // setamos a sensibilidade para +/- 2g
  Wire.endTransmission();
}

void loop() {
  // Solicitação de dados ao MPU6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B); // Registrador inicial dos dados acelerômetro
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 14, true); 

  // Recebe os dados do acelerômetro
   acelX = ((Wire.read() << 8 | Wire.read())/fator_conversao_acel); 
  acelY = ((Wire.read() << 8 | Wire.read())/fator_conversao_acel);    
  acelZ = ((Wire.read() << 8 | Wire.read())/fator_conversao_acel); 
  temperatura = Wire.read() << 8 | Wire.read();
  giroX = ((Wire.read() << 8 | Wire.read())/fator_conversao_giro); 
  giroY = ((Wire.read() << 8 | Wire.read())/fator_conversao_giro); 
  giroZ = ((Wire.read() << 8 | Wire.read())/fator_conversao_giro); 

  // Imprime os valores no Serial Monitor
   Serial.print(String(acelX) + " " + String(acelY) + " " + String(acelZ));
  Serial.println(" ///// "+String(giroX) + " " + String(giroY) + " " + String(giroZ));
  delay(100);

  delay(1000); // Aguarda 1 segundo antes de ler novamente
}