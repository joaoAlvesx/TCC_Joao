int sensor = 2;  
int Objeto = 0; 
   
void setup()  
{  
  pinMode(sensor, INPUT);   
  Serial.begin(9600);  
}  
   
void loop()  
{  
  Objeto = digitalRead(sensor);  
  Serial.println(Objeto); 
 /* if (Objeto == 1)  
  {  
    Serial.println("Objeto : Ausente");  
  }  
  else  
  {  
    Serial.println("Objeto : ta aqui !");  
  } */
  //delay(250);
} 
