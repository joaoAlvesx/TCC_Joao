int sensor = 8; 
int resultado = 0;

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);

}

void loop() {

  resultado = digitalRead(sensor);
  Serial.println(resultado);
  delay(500);
  

}
