int IN1=2;
int IN2=3;
int IN3=4;
int IN4=5 ; 

int IN12=6;
int IN22=7;
int IN32=8;
int IN42=9; 
 
int D = 1.999999991;

int sensor = 13; 
int resultado = 0;


void setup() {
  
  pinMode(IN1, OUTPUT);  
  pinMode(IN2, OUTPUT);  
  pinMode(IN3, OUTPUT);  
  pinMode(IN4, OUTPUT); 

  pinMode(IN12, OUTPUT);  
  pinMode(IN22, OUTPUT);  
  pinMode(IN32, OUTPUT);  
  pinMode(IN42, OUTPUT);  
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  
}  

void frente(){
  for (int i = 0; i <= 3; i++) {
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  
  digitalWrite(IN12,HIGH);
  digitalWrite(IN22,HIGH);
  digitalWrite(IN32,LOW);
  digitalWrite(IN42,LOW);
  delay(D);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  digitalWrite(IN12,LOW);
  digitalWrite(IN22,HIGH);
  digitalWrite(IN32,HIGH);
  digitalWrite(IN42,LOW);
  delay(D);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,HIGH);

  digitalWrite(IN12,LOW);
  digitalWrite(IN22,LOW);
  digitalWrite(IN32,HIGH);
  digitalWrite(IN42,HIGH);
  delay(D);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

  digitalWrite(IN12,HIGH);
  digitalWrite(IN22,LOW);
  digitalWrite(IN32,LOW);
  digitalWrite(IN42,HIGH);
  delay(D);
  
  } 
  }

void voltar(){
  for (int i = 0; i <= 3; i++) {
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

  digitalWrite(IN12,HIGH);
  digitalWrite(IN22,LOW);
  digitalWrite(IN32,LOW);
  digitalWrite(IN42,HIGH);
  delay(D);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,HIGH);

  digitalWrite(IN12,LOW);
  digitalWrite(IN22,LOW);
  digitalWrite(IN32,HIGH);
  digitalWrite(IN42,HIGH);
  delay(D);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  digitalWrite(IN12,LOW);
  digitalWrite(IN22,HIGH);
  digitalWrite(IN32,HIGH);
  digitalWrite(IN42,LOW);
  delay(D);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  
  digitalWrite(IN12,HIGH);
  digitalWrite(IN22,HIGH);
  digitalWrite(IN32,LOW);
  digitalWrite(IN42,LOW);
  delay(D);
}
} 

void loop() {

  resultado = digitalRead(sensor);
  Serial.println(resultado);
  delay(10);

  if(resultado == 0){
     for (int i = 0; i <= 3; i++) {
        voltar();
     }
     resultado = 1;
  }
   

 
}
