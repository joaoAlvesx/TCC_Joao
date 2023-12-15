#define D80    16
#define D1    5
#define D2    4
#define D3    80
#define D4    2
#define D5    14
#define D6    12
#define D7    13
#define D8    15
#define D9    3
#define D180   1


#include <ESP8266WiFi.h>


// Configração do WiFi
const char* ssid = "IFMaker Adm"; //VARIÁVEL QUE ARMAZENA O NOME DA REDE SEM FIO EM QUE VAI CONECTAR
const char* password = "@IFM4k3r"; //VARIÁVEL QUE ARMAZENA A SENHA DA REDE SEM FIO EM QUE VAI CONECTAR
 
WiFiServer server(880);

//Matriz
int x = 0;
int y = 0;
int a, b, indice=0,cont=0;
int origem[2],destino[2];
#define tamanho 14
//variaveis auxiliares

int escolher = 0;

//O = 80 N = 1 L=2 S=3
int ref = 2;

int caminho [tamanho][tamanho];
int aux [tamanho][tamanho];
int matriz [tamanho][tamanho];

int cenario [tamanho][tamanho] =
{
{80,80,80,80,80,80,80,80,80,80,80,80,80,80},
{80,-99,80,1,1,1,80,80,80,80,80,80,80,80},
{80,1,80,80,80,1,80,80,80,80,80,80,80,80},
{80,1,1,1,1,1,1,1,1,1,1,1,80,80},
{80,1,80,1,80,80,80,80,80,80,1,80,80,80},
{80,1,1,1,1,1,80,80,80,80,1,80,80,80},
{80,1,80,80,80,1,80,80,80,80,1,1,1,80},
{80,1,80,1,80,1,80,80,80,80,1,80,1,80},
{80,1,80,1,80,1,1,1,1,1,1,80,1,80},
{80,1,80,1,80,80,80,80,80,1,1,80,1,80},
{80,1,1,1,1,1,80,80,80,1,1,1,1,80},
{80,80,80,80,80,1,80,80,80,80,1,1,80,80},
{80,1,1,1,1,1,1,1,1,1,1,1,999,80},
{80,80,80,80,80,80,80,80,80,80,80,80,80,80}

};

void busca()
{

  for(x=0;x<tamanho;x++)
  {
    for(y=0;y<tamanho;y++)
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
      
      }
  }
  
  
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
            
            if (matriz[a][b+1]==-60)  { matriz[a][b+1]=indice+1;  aux[a][b+1]=indice+1;   }
            if (matriz[a+1][b]==-60)	{	matriz[a+1][b]=indice+1;	aux[a+1][b]=indice+1; 		}
            if (matriz[a-1][b]==-60)	{	matriz[a-1][b]=indice+1;	aux[a-1][b]=indice+1; 		}
            if (matriz[a][b-1]==-60)	{	matriz[a][b-1]=indice+1;	aux[a][b-1]=indice+1;		}
            
            if(matriz[a+1][b]==999 || matriz[a][b+1]==999 ||matriz[a-1][b]==999 ||matriz[a][b-1]==999 )	{ Serial.println("achou = 1 ");achou=1;}
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

     for (int x = 0; x<tamanho;x++){
      for (int y = 0; y<tamanho;y++){
        Serial.print("|");
        Serial.print(cenario[x][y]);
        Serial.print("|");
      }
      Serial.println(" ");
    }
    Serial.println(" ");
    delay(500);
 
    
  
    
    caminho[origem[0]][origem[1]]=-10;
    caminho[destino[0]][destino[1]]=indice;

    a=origem[0];
    b=origem[1];

   
    int busca = 0;
    while(busca<indice)
    {	busca++;
        
        if (matriz[a+1][b]==busca)  { caminho[a+1][b]=busca+1;    a=a+1;  b=b;  } //2
        else   if (matriz[a][b+1]==busca)  { caminho[a][b+1]=busca+1;    a=a;  b=b+1;  } //3
        else if (matriz[a-1][b]==busca)	{	caminho[a-1][b]=busca+1;		a=a-1;	b=b;	}		//1
        else	if (matriz[a][b-1]==busca)	{	caminho[a][b-1]=busca+1;		a=a;	b=b-1;	}	//4
        //muldar 3 e 4 pra 2 e 3 altera a busca de baixo para lateral
      
    }
    caminho[origem[0]][origem[1]]=01;
 for (int x = 0; x<tamanho;x++){
      for (int y = 0; y<tamanho;y++){
        Serial.print(" |");
        Serial.print(caminho[x][y]);
        Serial.print("| ");
      }
      Serial.println(" ");
    }
    Serial.println(" ");
    delay(500);
 
    
  }
void setup()
{
  Serial.begin(115200);
 // system_update_cpu_freq(1680);


  busca();
  Serial.println("funfou");
  
    
  WiFi.begin(ssid, password); //PASSA OS PAR METROS PARA A FUNÇÃO QUE VAI FAZER A CONEXÃO COM A REDE SEM FIO
 
  while (WiFi.status() != WL_CONNECTED) { //ENQUANTO STATUS FOR DIFERENTE DE CONECTADO
  delay(500); //INTERVALO DE 500 MILISEGUNDOS
  Serial.print("."); //ESCREVE O CARACTER NA SERIAL
 
  }
  Serial.println(""); //PULA UMA LINHA NA JANELA SERIAL
  Serial.print("Conectado a rede sem fio "); //ESCREVE O TEXTO NA SERIAL
  Serial.println(ssid); //ESCREVE O NOME DA REDE NA SERIAL
  server.begin(); //INICIA O SERVIDOR PARA RECEBER DADOS NA PORTA DEFINIDA EM "WiFiServer server(porta);"
    yield();
  Serial.println("Servidor iniciado"); //ESCREVE O TEXTO NA SERIAL
 
  Serial.print("IP para se conectar ao NodeMCU: "); //ESCREVE O TEXTO NA SERIAL
  Serial.print("http://"); //ESCREVE O TEXTO NA SERIAL
  Serial.println(WiFi.localIP()); //ESCREVE NA SERIAL O IP RECEBIDO DENTRO DA REDE SEM FIO (O IP NESSA PRÁTICA É RECEBIDO DE FORMA AUTOMÁTICA)



  




    
  }






void loop()
{
 
  delay(500);
  yield();
  WiFiClient client = server.available(); //VERIFICA SE ALGUM CLIENTE ESTÁ CONECTADO NO SERVIDOR


  String request = client.readStringUntil('\r'); //FAZ A LEITURA DA PRIMEIRA LINHA DA REQUISIÇÃO
  client.flush(); //AGUARDA ATÉ QUE TODOS OS DADOS DE SAÍDA SEJAM ENVIADOS AO CLIENTE
  
  client.println("HTTP/1.1 200 OK"); //ESCREVE PARA O CLIENTE A VERSÃO DO HTTP
  client.println("Content-Type: text/html"); //ESCREVE PARA O CLIENTE O TIPO DE CONTEÚDO(texto/html)
  client.println("");
  client.println("<!DOCTYPE HTML>"); //INFORMA AO NAVEGADOR A ESPECIFICAÇÃO DO HTML
  client.println("<html>"); //ABRE A TAG "html"

  
  client.println("<br>"); 
    client.println("Cenario");
   client.println("<br>"); 
  
 

  client.println("</center></h1>"); //ESCREVE "Ola cliente!" NA PÁGINA
  client.println("<center><font size='5'></center>"); //ESCREVE "Seja bem vindo!" NA PÁGINA
  client.println("</html>"); //FECHA A TAG "html"
  delay(1); //INTERVALO DE 1 MILISEGUNDO
 
  Serial.println(""); //PULA UMA LINHA NA JANELA SERIAL
  yield();

}
