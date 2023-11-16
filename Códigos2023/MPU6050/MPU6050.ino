#include <Wire.h>

#define MPU6050_ADDR 0x68 // Endereço padrão do MPU6050
long temp_prev;
float fator_conversao_acel = 16384;
float fator_conversao_giro = 131;
#define RAD_GRAUS 57.2957795131;
float giroX, giroY, giroZ, acelX, acelY, acelZ, temperatura, aceleracao_eixo, giro_eixo, angulo_eixo, dt;
float ang_x_prev, ang_y_prev, ang_z_prev;
float ang_x, ang_y, ang_z;
long tempo_prev;

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
  
  dt = (millis() - tempo_prev) / 1000.0;
  tempo_prev = millis();

  float accel_ang_x = atan(acelY / sqrt(pow(acelX, 2) + pow(acelZ, 2))) * (180.0 / 3.14);
  float accel_ang_y = atan(-acelX / sqrt(pow(acelY, 2) + pow(acelZ, 2))) * (180.0 / 3.14);
  float accel_ang_z = atan((sqrt(pow(acelX, 2) + pow(acelY, 2))) / acelZ) * (180.0 / 3.14);
  
  ang_x = 0.98 * (ang_x_prev + (giroX / 131) * dt) + 0.02 * accel_ang_x;
  ang_y = 0.98 * (ang_y_prev + (giroY / 131) * dt) + 0.02 * accel_ang_y;
  ang_z = 0.98 * (ang_z_prev + (giroZ / 131) * dt) + 0.02 * accel_ang_z;

  ang_x_prev = ang_x;
  ang_y_prev = ang_y;
  ang_z_prev = ang_z;
  Serial.println(ang_z);
  delay(100);
 
  
  
  delay(100); // Aguarda 1 segundo antes de ler novamente
}
