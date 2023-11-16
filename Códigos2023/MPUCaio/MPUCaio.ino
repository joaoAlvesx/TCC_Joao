#include <Wire.h>
#define RAD_GRAUS 57.2957795131;
float giroX, giroY, giroZ, acelX, acelY, acelZ, temperatura, aceleracao_eixo, giro_eixo, angulo_eixo, dt;  
float fator_conversao_acel = 16384;
float fator_conversao_giro = 131;
const int mpu = 0x68; 
long temp_prev;

void setup() {
  Serial.begin(115200);
  Wire.begin(D6, D5);
  Wire.beginTransmission(mpu);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  Wire.beginTransmission(mpu);
  Wire.write(0x1B);
  Wire.write(0b00000000); // setamos o fundo de escala para +/- 250º /s
  Wire.endTransmission();

  Wire.beginTransmission(mpu);
  Wire.write(0x1C);
  Wire.write(0b00000000); // setamos a sensibilidade para +/- 2g
  Wire.endTransmission();
}

void loop() {
  Wire.beginTransmission(mpu);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(mpu, 14, true);

  // obtendo os valores do sensor e armazenando nas variaveis
  acelX = ((Wire.read() << 8 | Wire.read())/fator_conversao_acel); 
  acelY = ((Wire.read() << 8 | Wire.read())/fator_conversao_acel);    
  acelZ = ((Wire.read() << 8 | Wire.read())/fator_conversao_acel); 
  temperatura = Wire.read() << 8 | Wire.read();
  giroX = ((Wire.read() << 8 | Wire.read())/fator_conversao_giro); 
  giroY = ((Wire.read() << 8 | Wire.read())/fator_conversao_giro); 
  giroZ = ((Wire.read() << 8 | Wire.read())/fator_conversao_giro); 

 aceleracao_eixo = atan((acelY)/sqrt(pow((acelX),2) + pow((acelZ),2)))*RAD_GRAUS;
  //calculando o intevalo entre leituras
  dt = (millis() - temp_prev);
  temp_prev = millis();
  //calculando o angulo
  angulo_eixo = 0.98 *(angulo_eixo+giroY*(dt)/ 1000.0) + 0.02*aceleracao_eixo;
  Serial.println(angulo_eixo);
  
  delay(100);
}
