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
  Serial.begin(9600);
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
  delay(1500);
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
  }

  void loop()
{    
    analogWrite(pwmMotorA, 0  );
    digitalWrite(dirMotorA, LOW);
    analogWrite(pwmMotorB,0);
    digitalWrite(dirMotorB, LOW);
    delay(1000);
    mostrar_matriz();
    Serial.println(" ");
    valor1 = digitalRead(sensor1);
    Serial.print(valor1);//Diminuir energia**/
    valor2 = digitalRead(sensor2);
    Serial.print(valor2); //valor invertido;
    valor3 = digitalRead(sensor3);
    Serial.print(valor3);
    matriz [0][0] = 1;
    //O = 0 N = 1 L=2 S=3
    if(valor1 == 0 and valor2 == 1 and valor3 ==0){
        frente();
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
        matriz [x][y] = 1;
    }

    else if(valor1 == 0 and valor2 == 0 and valor3 ==1){
        direita();
        //Definindo valor da ref
            if(ref == 0)
            ref == 1;
            else if(ref == 1)
            ref == 2;
            else if(ref == 2)
            ref == 3;
            else if(ref == 3)
            ref == 0;
        //Definincdo onde colocar o valor 1
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


        matriz  [x][y] = 1;
    }

    else if(valor1 == 1 and valor2 == 0 and valor3 ==0){
        esquerda();
        //Definindo valor da ref
            if(ref == 0)
            ref == 3;
            else if(ref == 3)
            ref == 2;
            else if(ref == 2)
            ref == 1;
            else if(ref == 1)
            ref == 0;
        //Definincdo onde colocar o valor 1
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
        matriz  [x][y] = 1;
    }

    else if(valor1 == 0 and valor2 == 0 and valor3 ==0){
       Serial.println("Nenhum lugar");
    }


    else if(valor1 == 0 and valor2 == 1 and valor3 ==1){
        escolher = random(1,2);
        if (escolher == 1){
            frente();
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
        matriz  [x][y] = 1;
        }
        else if (escolher == 2){
            direita();
        //Definindo valor da ref
            if(ref == 0)
            ref == 1;
            else if(ref == 1)
            ref == 2;
            else if(ref == 2)
            ref == 3;
            else if(ref == 3)
            ref == 0;
        //Definincdo onde colocar o valor 1
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

        matriz  [x][y] = 1;
    }


    }
    else if(valor1 == 1 and valor2 == 0 and valor3 ==1){
        escolher = random(1,2);
        if (escolher == 1){
            esquerda();
            //Definindo valor da ref
            if(ref == 0)
            ref == 3;
            else if(ref == 3)
            ref == 2;
            else if(ref == 2)
            ref == 1;
            else if(ref == 1)
            ref == 0;
        //Definincdo onde colocar o valor 1
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
        matriz  [x][y] = 1;
        }
        else if (escolher == 2){
            direita();
        //Definindo valor da ref
            if(ref == 0)
            ref == 1;
            else if(ref == 1)
            ref == 2;
            else if(ref == 2)
            ref == 3;
            else if(ref == 3)
            ref == 0;
        //Definincdo onde colocar o valor 1
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

        matriz  [x][y] = 1;
        }

    }
    else if(valor1 == 1 and valor2 == 1 and valor3 ==0){
        escolher = random(1,2);
        if (escolher == 1){
            esquerda();
            //Definindo valor da ref
            if(ref == 0)
            ref == 3;
            else if(ref == 3)
            ref == 2;
            else if(ref == 2)
            ref == 1;
            else if(ref == 1)
            ref == 0;
        //Definincdo onde colocar o valor 1
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
        matriz  [x][y] = 1;
        }
        else if (escolher == 2){
            frente();
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
            matriz  [x][y] = 1;
        }
    }

 
}
 
