

#define D0    16 //
#define D1    5 //
#define D2    4 //
#define D3    0 //
#define D4    2 //
#define D5    14 //
#define D6    12 //
#define D7    13 //
#define D8    15
#define D9    3 
#define D10   1
#define D12   10
#define D13   9



int sensor1 = D7;//Esquerda azul/
int sensor2 = D12;//Frente/
int sensor3 = D0;//Direita branco

int valor1;
int valor2;
int valor3;
 void setup()  
 {  
  Serial.begin(115200);// Iniando a comunicacao serial na frequencia 115200
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
 }  
 void loop()   
 {  
      valor1 = digitalRead(sensor1);
      Serial.print("sensor esquerda:");
      Serial.print(valor1);//Diminuir energia**/
      valor2 = digitalRead(sensor2);
      Serial.print("sensor frente:");
      Serial.print(valor2); //valor invertido;
      valor3 = digitalRead(sensor3);
      Serial.print("sensor direita:");
      Serial.print(valor3);
      Serial.println(" ");
}  
