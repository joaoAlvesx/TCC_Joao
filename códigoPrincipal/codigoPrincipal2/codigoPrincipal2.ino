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
int a, b, indice=0,cont=0;
int origem[2],destino[2];
#define tamanho 14
//variaveis auxiliares

int escolher = 0;

//O = 0 N = 1 L=2 S=3
int ref = 2;

int caminho [tamanho][tamanho];
int aux [tamanho][tamanho];
int matriz [tamanho][tamanho];

int cenario [tamanho][tamanho] =
{
{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,-99,0,1,1,1,0,0,0,0,0,0,0,0},
{0,1,0,0,0,1,0,0,0,0,0,0,0,0},
{0,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,0,1,0,0,0,0,0,0,1,0,0,0},
{0,1,1,1,1,1,0,0,0,0,1,0,0,0},
{0,1,0,0,0,1,0,0,0,0,1,1,1,0},
{0,1,0,1,0,1,0,0,0,0,0,0,1,0},
{0,1,0,1,0,1,1,1,1,1,1,0,1,0},
{0,1,0,1,0,0,0,0,0,1,0,0,1,0},
{0,1,0,1,1,1,0,0,0,1,1,1,1,0},
{0,1,0,1,0,0,0,0,0,1,0,0,0,0},
{0,1,1,1,1,1,1,1,1,1,1,1,999,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0}

};

void setup()
{
  Serial.begin(115200);
 // system_update_cpu_freq(160);


  pinMode(pwmMotorA , OUTPUT);
  pinMode(pwmMotorB, OUTPUT);
  pinMode(dirMotorA, OUTPUT);
  pinMode(dirMotorB, OUTPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  Serial.println("funfou");
  for (int y = 0; y<tamanho;y++){
      for (int x = 0; x<tamanho;x++){
      aux[x][y] = -20;
      }
    }
  }


void busca()
{

  for(y=0;y<tamanho;y++)
  {
    for(x=0;x<tamanho;x++)
    {
      if(cenario[x][y] == -99)	
      {
        origem[0] = x; 
        origem[1] = y;
        matriz[x][y]=0;
        aux[x][y]=0;
        
      }
      if(cenario[x][y] == 999)	
      {
        destino[0] = x; 
        destino[1] = y;
        matriz[x][y]=999;
        aux[x][y]=999;

      }
      if(cenario[x][y] == 1)
      {
        matriz[x][y]=-60;
        aux[x][y]=-60;
      }
      if(cenario[x][y] == 0)	
      {
        matriz[x][y]=-30;
        aux[x][y]=-30;
        
      }
      Serial.print(cenario[x][y]);
      Serial.print(" ");
      Serial.print(aux[x][y]);
      Serial.println("");
      delay(100);
      }
  }
   for (int y = 0; y<tamanho;y++){
      for (int x = 0; x<tamanho;x++){
        Serial.print(aux[x][y]);
      }
      Serial.println(" ");
    }
    Serial.println(" ");
    delay(500);
  Serial.println("teste ");
  
  int achou=0;
  while (achou==0)
  {
    for (y=0;y<tamanho;y++)
    {
      for(x=0;x<tamanho;x++)
      {
        if(aux[x][y]==indice)
        {
          cont++;
        }
      }
    }
    
    if (cont>=1)
    {
      for (y=0;y<tamanho;y++)
      {
        for(x=0;x<tamanho;x++)
        {
          if(aux[x][y]==indice)
          {
            a=x;
            b=y;
            aux[x][y]=-99; //-2 na tabela auxiliar significa que foi lido o campo
            
            if (matriz[a+1][b]==-60)	{	matriz[a+1][b]=indice+1;	aux[a+1][b]=indice+1; 		}
            if (matriz[a][b+1]==-60)	{	matriz[a][b+1]=indice+1;	aux[a][b+1]=indice+1;		}
            if (matriz[a-1][b]==-60)	{	matriz[a-1][b]=indice+1;	aux[a-1][b]=indice+1; 		}
            if (matriz[a][b-1]==-60)	{	matriz[a][b-1]=indice+1;	aux[a][b-1]=indice+1;		}
            
            if(matriz[a+1][b]==999 || matriz[a][b+1]==999 ||matriz[a-1][b]==999 ||matriz[a][b-1]==999 )	{achou=1;}
            cont--;

          }
        }

      }
      
        }
    if (cont==0)
      {
        indice++;
      }
  }		
    caminho[origem[0]][origem[1]]=indice;
    caminho[destino[0]][destino[1]]=-10;

    a=origem[0];
    b=origem[1];

    caminho[a][b]=indice;

    while(indice>1)
    {	indice--;
          if (matriz[a-1][b]==indice)	{	caminho[a-1][b]=indice;		a=a-1;	b=b;	}		//1
        else	if (matriz[a+1][b]==indice)	{	caminho[a+1][b]=indice;		a=a+1;	b=b;	}	//2
        else 	if (matriz[a][b+1]==indice)	{	caminho[a][b+1]=indice;		a=a;	b=b+1;	}	//3
        else	if (matriz[a][b-1]==indice)	{	caminho[a][b-1]=indice;		a=a;	b=b-1;	}	//4
        //muldar 3 e 4 pra 2 e 3 altera a busca de baixo para lateral
      
    }

    
  }



void loop()
{
  busca();
  delay(5000);

}