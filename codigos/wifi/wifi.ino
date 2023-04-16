
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

#define ENA    D1 //BRANCO AMARELO
#define IN1    D5 //CINZA VERDE
#define IN2    D6 //BRANCO AZUL

#define ENA2    D2 //BRANCO
#define IN12    D3 //VERDE
#define IN22    D4 //AZUL


void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); 
  pinMode(ENA2, OUTPUT);
  pinMode(IN12, OUTPUT);
  pinMode(IN22, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN12, LOW);
  digitalWrite(IN22, LOW);

}

void loop() {
  analogWrite(ENA, 100);
  analogWrite(ENA2, 100);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN12, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN22, LOW);
  delay(5000);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN12, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN22, HIGH);
  delay(5000);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN12, LOW);
  digitalWrite(IN22, LOW);
}
