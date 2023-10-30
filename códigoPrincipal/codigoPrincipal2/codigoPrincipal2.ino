#define D0    16
#define D1    5
#define D2    4
#define D3    0
#define D4    2
#define D5    14
#define D6    12
#define D7    13
#define D8    15
#define D9    3
#define D10   1



//sensores
int sensor1 = D0;//Esquerda azul/
int sensor2 = D5;//Frente/
int sensor3 = D7;//Direita branco

int valor1;
int valor2;
int valor3;

//MOTORES
const int pwmMotorA = D1;
const int pwmMotorB = D2;
const int dirMotorA = D3;
const int dirMotorB = D4;

int motorSpeed = 100;
int motorSpeedNegativo = -100;

//Matriz
int x = 0;
int y = 0;
#define tam 12
//variaveis auxiliares
bool saida = false;
int escolher = 0;

//O = 0 N = 1 L=2 S=3
int ref = 2;

int matriz [tam][tam] =
{

{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0}

};


void setup()
{
  Serial.begin(115200);
 // system_update_cpu_freq(160);
 

  pinMode(pwmMotorA , OUTPUT);
  pinMode(pwmMotorB, OUTPUT);
  pinMode(dirMotorA, OUTPUT);
  pinMode(dirMotorB, OUTPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);

  }
void mostrar_matriz(){
  for (int y = 0; y<8;y++){
    for (int x = 0; x<8;x++){
      Serial.print(matriz[x][y]);
    }
    Serial.println(" ");
  }

}
void frente(){
  
  analogWrite(pwmMotorA, motorSpeed+27  );
  digitalWrite(dirMotorA, LOW);
  analogWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, LOW);
  delay(1800);
     Serial.println(" Frente");
}
void esquerda(){

  while (valor2 == 0 and valor3 == 0){
      valor2 = digitalRead(sensor2);
      valor3 = digitalRead(sensor3);
      analogWrite(pwmMotorA, 100);
      digitalWrite(dirMotorA, LOW);
      analogWrite(pwmMotorB, 100);
      digitalWrite(dirMotorB, HIGH);
  }

  analogWrite(pwmMotorA, motorSpeed +27 );
  digitalWrite(dirMotorA, LOW);
  analogWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, LOW);
  delay(1000);
     Serial.println("Esquerda ");
}
void direita(){

 while (valor2 == 0 and valor1 == 0){
    valor2 = digitalRead(sensor2);
    valor1 = digitalRead(sensor1);
    analogWrite(pwmMotorA, motorSpeed);
    digitalWrite(dirMotorA, HIGH);
    analogWrite(pwmMotorB, motorSpeed);
    digitalWrite(dirMotorB, LOW);
 }

  analogWrite(pwmMotorA, motorSpeed  );
  digitalWrite(dirMotorA, LOW);
  analogWrite(pwmMotorB, motorSpeed+27);
  digitalWrite(dirMotorB, LOW);
  delay(1000);
     Serial.println("Direita ");
  }
  void retorno(){
  while (valor2 == 0 ){
      valor2 = digitalRead(sensor2);
     
     
      analogWrite(pwmMotorA, 100);
      digitalWrite(dirMotorA, LOW);
      analogWrite(pwmMotorB, 100);
      digitalWrite(dirMotorB, HIGH);
  }

    analogWrite(pwmMotorA, motorSpeed);
    digitalWrite(dirMotorA, LOW);
    analogWrite(pwmMotorB, motorSpeed);
    digitalWrite(dirMotorB, HIGH);
    delay(500);

    analogWrite(pwmMotorA, 0);
    digitalWrite(dirMotorA, LOW);
    analogWrite(pwmMotorB, 0);
    digitalWrite(dirMotorB, LOW);
    delay(1500);
  }
  void loop()
{    
   analogWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, LOW);
  analogWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, LOW);
  delay(3300);
  analogWrite(pwmMotorA, 0);
  digitalWrite(dirMotorA, LOW);
  analogWrite(pwmMotorB, 0);
  digitalWrite(dirMotorB, LOW);
  delay(3000);
 
}
