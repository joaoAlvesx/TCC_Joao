

int IN3 = 14 ;
int IN4 = 12 ;
float velocidade = 255; 

void setup() {
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);

}

void loop() {
  analogWrite(IN3, LOW);
  analogWrite(IN4, velocidade);;

}
