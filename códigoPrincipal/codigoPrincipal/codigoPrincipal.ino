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




int in1 = D1;
int in2 = D3;
int in12 = D2;
int in22 = D4;


int sensor1 = D0;//Esquerda azul/
int sensor2 = D5;//Frente/
int sensor3 = D6;//Direita branco


int valor1;
int valor2;
int valor3;


int x = 6;
int y = 6;


bool saida == false;
int ref = L;

int matriz[x][y]=
{
  
  
  {0,0,0,0},
  {0,0,0,0},
  {0,0,0,0},
  {0,0,0,0},
  {0,0,0,0}
};




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


   analogWrite(in1, 0);
   analogWrite(in2, 0);


}

void frente(){
 
  //mover motores

  if (ref == L){
    x++;
  }
  else if (ref == O){
    x--;
  }
  else if (ref == N){
    y++;
  }
  else if (ref == S){
    y--;
  }

}

void direita(){
  
  if(ref == L){
    ref = S;
  }

  else if(ref == S){
    ref = O;
  }
  else if(ref == O){
    ref = N;
  }
  else if(ref == N){
    ref = L;
  }

  //mover motores

  if (ref == L){
    x++;
  }
  else if (ref == O){
    x--;
  }
  else if (ref == N){
    y++;
  }
  else if (ref == S){
    y--;
  }

}

void esquerda(){
  
  if(ref == L){
    ref = N;
  }

  else if(ref == N){
    ref = O;
  }
  else if(ref == O){
    ref = S;
  }
  else if(ref == S){
    ref = L;
  }

  //mover motores

  if (ref == L){
    x++;
  }
  else if (ref == O){
    x--;
  }
  else if (ref == N){
    y++;
  }
  else if (ref == S){
    y--;
  }

}

void retorno(){
  if(ref == L){
    ref = O;
  }

  else if(ref == O){
    ref = L;
  }
  else if(ref == N){
    ref = S;
  }
  else if(ref == S){
    ref = N;
  }

  if (ref == L){
    x++;
  }
  else if (ref == O){
    x--;
  }
  else if (ref == N){
    y++;
  }
  else if (ref == S){
    y--;
  }
}

  void loop()
{
  valor1 = digitalRead(sensor1);
  //Serial.print(valor1);//Diminuir energia**/
  valor2 = digitalRead(sensor2);
 //Serial.print(valor2); //valor invertido;
  valor3 = digitalRead(sensor3);
  //Serial.print(valor3);
  //Serial.println(" ");


 /* if(valor1 == 1 and valor2 == 1 and valor3 ==1)
    Serial.println("tudo 1");
  else if(valor1 == 1 and valor2 == 1 and valor3 ==0)
    Serial.println("1 1 0");
  else if(valor1 == 1 and valor2 == 0 and valor3 ==1)
    Serial.println("1 e 0 1");
  else if(valor1 == 0 and valor2 == 1 and valor3 ==1)
    Serial.println("0 e 1 1");
    else if(valor1 == 0 and valor2 == 1 and valor3 ==0)
    Serial.println("10");
    else if(valor1 == 0 and valor2 == 0 and valor3 ==0)
    Serial.println("0");
    else if(valor1 == 0 and valor2 == 0 and valor3 ==1)
    Serial.println("1");
    else if(valor1 == 1 and valor2 == 0 and valor3 ==0)
    Serial.println("100");*/


  matriz = [0][0] = "O"


  while(saida == false){
    //Somente frente disponivel
    if(valor1 == 0 and valor2 == 1 and valor3 ==0){
    
  
    frente()
    matriz = [x][y] = "L";
    
  
    }

    if(valor1 == 0 and valor2 == 0 and valor3 ==1){
    direita()
    matriz = [x][y] = "L";
   
    
    }
   
    if(valor1 == 1 and valor2 == 0 and valor3 ==0){
    esquerda()
    matriz = [x][y] = "L";
    
    
    }
   
   if(valor1 == 0 and valor2 == 0 and valor3 ==0){
    matriz = [x][y] = "B";
    retorno()
    
    
    
    
    
    }
   


  };






}