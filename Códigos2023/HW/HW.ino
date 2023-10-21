 int sensor = 5; //Definindo porta do sensor 
 int valor = 0;// variavel que recebera valor do sensor

 void setup()  
 {  
  Serial.begin(115200);// Iniando a comunicacao serial na frequencia 115200
  pinMode(sensor, INPUT); //Setando o Pino 5 como entrada
 }  
 void loop()   
 {  
  val = digitalRead(sensor);//Lendo o valor de entrada do sensor e armazenando
  Serial.println(valor);//Mostrando n monitor serial o valor do sensor   
  delay(100);        

}  
