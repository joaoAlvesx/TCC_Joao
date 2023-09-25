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


int x = 4;
int y = 0;
#define tam 4

bool saida = false;
int escolher = 0;

//O = 0 N = 1 L=2 S=3


int ref = 1;

int matriz [tam][tam] =
{
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


  


}
void pos(){
 if(ref == 0){
    x--;
    matriz [x][y] = 1;
    x--;
}
  else if(ref == 1){
    y++;
    matriz [x][y] = 1;
    y++;
}
  else if(ref == 2){
    x++;
    matriz [x][y] = 1;
    x++;
  }
  else if(ref == 3){
    y--;
    matriz [x][y] = 1;
    y--;
  }
}
void frente(){
 
  //mover motores

  if(ref == 0){
    x--;
    matriz [x][y] = 1;
    x--;
  }
  else if(ref == 1){
    y++;
    matriz [x][y] = 1;
    y++;
  }
  else if(ref == 2){
    x++;
    matriz [x][y] = 1;
    x++;
  }
  else if(ref == 3){
    y--;
    matriz [x][y] = 1;
    y--;
  }

}

void direita(){

  //mover motores

  if(ref == 0)
    ref == 1;
  else if(ref == 1)
    ref == 2;
  else if(ref == 2)
    ref == 3;
  else if(ref == 3)
    ref == 0;

  pos();

}

  

void esquerda(){
  

  //mover motores

  if(ref == 0)
    ref == 3;
  else if(ref == 3)
    ref == 2;
  else if(ref == 2)
    ref == 1;
  else if(ref == 1)
    ref == 0;

  pos();


}

void retorno(){
}

void paredes(bool E, bool F, bool D){
  //O = 0 N = 1 L=2 S=3
  //false = parede
if(ref == 0 ){
  if (false,true,false){
      y--;
      matriz  [x][y] = 0;
      y+2;
      matriz  [x][y] = 0;
      y--;
    }
    else if(false,false,true){
      y--;
      matriz  [x][y] = 0;
      y++;
      x--;
      matriz  [x][y] = 0;
      x++;
    }
    else if (true,false,false){
      x--;
      matriz  [x][y] = 0;
      x++;
      y++;
      matriz  [x][y] = 0;
      y--;
    }
    else if (false,true,true){
      y--;
      matriz  [x][y] = 0;
      y++;
    }
    else if (true,false,true){
      x--;
      matriz  [x][y] = 0;
      x++
    }
    else if (true,true,false){
      y++;
      matriz  [x][y] = 0;
      y--;
    }
    
} 

  else if (ref == 2){
    if (false,true,false){
      y++;
      matriz  [x][y] = 0;
      y-2;
      matriz  [x][y] = 0;
      y++;
    }
    else if(false,false,true){
      y++;
      matriz  [x][y] = 0;
      y--;
      x++;
      matriz  [x][y] = 0;
      x--;
    }
    else if (true,false,false){
      x++;
      matriz  [x][y] = 0;
      x--;
      y--;
      matriz  [x][y] = 0;
      y++;
    }

    else if (false,true,true){
      y++;
      matriz  [x][y] = 0;
      y--;
    }
    else if (true,false,true){
      x++;
      matriz  [x][y] = 0;
      x--;
    }
    else if (true,true,false){
      y--;
      matriz  [x][y] = 0;
      y++;
  }

}
  else if(ref == 1){

    if (false,true,false){

    }
    else if(false,false,true){
      
    }
    else if (true,false,false){
      
    }
    else if (false,true,true){
      
    }
    else if (true,false,true){
      
    }
    else if (true,true,false){
      
    }
    }
    if ( ref == 3){
      if (false,true,false){

    }
    else if(false,false,true){
      
    }
    else if (true,false,false){
      
    }
    else if (false,true,true){
      
    }
    else if (true,false,true){
      
    }
    else if (true,true,false){
      
    }

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
  


  matriz [0][0] = 1;

  //O = 0 N = 1 L=2 S=3

  while(saida == false){
    //Somente frente disponivel
  if(valor1 == 0 and valor2 == 1 and valor3 ==0){
    paredes(false,true,false);
    frente();
    matriz  [x][y] = 1;
}

  else if(valor1 == 0 and valor2 == 0 and valor3 ==1){
    paredes(false,false,true);
    direita();
    matriz  [x][y] = 1;
    }
   
  else if(valor1 == 1 and valor2 == 0 and valor3 ==0){
    paredes(true,false,false);
    esquerda();
    matriz  [x][y] = 1;
    }

  else if(valor1 == 0 and valor2 == 0 and valor3 ==0){
    paredes(false,false,false);
    matriz  [x][y] = 1;
    retorno();
    }


  else if(valor1 == 0 and valor2 == 1 and valor3 ==1){
    escolher = random(1,2);
    if (escolher == 1){
      paredes(false,true,true);
      frente();
      matriz  [x][y] = 1;
    }
    else if (escolher == 2){
      paredes(false,true,true);
      direita();
      matriz  [x][y] = 1;
    }
  
   
    }
  else if(valor1 == 1 and valor2 == 0 and valor3 ==1){
   escolher = random(1,2);
    if (escolher == 1){
      paredes(true,false,true);
      esquerda();
      matriz  [x][y] = 1;
    }
    else if (escolher == 2){
      paredes(true,false,true);
      direita();
      matriz  [x][y] = 1;
    }
  
    }
  else if(valor1 == 1 and valor2 == 1 and valor3 ==0){
    escolher = random(1,2);
    if (escolher == 1){
      paredes(true,true,false);
      esquerda();
      matriz  [x][y] = 1;
    }
    else if (escolher == 2){
      paredes(true,true,false);
      frente();
      matriz  [x][y] = 1;
    }
  }
  
  else if(valor1 == 1 and valor2 == 1 and valor3 ==1)
    saida == true;

  };




}