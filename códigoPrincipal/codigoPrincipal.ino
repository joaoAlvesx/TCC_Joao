#define D0    16
#define D5    14
#define D6    12
#define D7    13
#define D8    15
#define D9    3
#define D10   1


int in1 = 5;//d1
int in2 = 0 ;//d3
int in12 = 4;
int in22 = 2 ;

int sensor1 = D0;
int sensor2 = D5;
int sensor3 = D6;

// " "

int valor1;
int valor2;
int valor3;
void setup()
{
  Serial.begin(9600);
  
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT); 
  pinMode(in12, OUTPUT); 
  pinMode(in22, OUTPUT); 
  pinMode(sensor1, INPUT); 
  pinMode(sensor2, INPUT); 
  pinMode(sensor3, INPUT); 

}

  void frente()
{
   analogWrite(in1, 255);
   analogWrite(in2, 0);
   delay(1000)
   Serial.print("motor parou ");
    
}

  void loop()
{
  valor1 = digitalRead(sensor1); 
  valor2 = digitalRead(sensor2); 
  valor3 = digitalRead(sensor3); 

  if (valor1 == 0)
  {
    Serial.println( "deu certo");
    frente();
    
  }


}
