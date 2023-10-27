
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

//definir 160mhz


//Wifi 

#include <ESP8266WiFi.h>


// Configração do WiFi
const char* ssid = "IFMaker Adm"; //VARIÁVEL QUE ARMAZENA O NOME DA REDE SEM FIO EM QUE VAI CONECTAR
const char* password = "@IFM4k3r"; //VARIÁVEL QUE ARMAZENA A SENHA DA REDE SEM FIO EM QUE VAI CONECTAR
 
WiFiServer server(80);

bool LEDstatus = LOW;
int test = 0;

//sensores
int sensor1 = D0;//Esquerda azul/
int sensor2 = D5;//Frente/
int sensor3 = D7;//Direita branco

int valor1;
int valor2;
int valor3;
int htsensor1;
int htsensor2;
int htsensor3;


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
#define tam 13
//variaveis auxiliares
bool saida = false;
int escolher = 0;

//O = 0 N = 1 L=2 S=3
int ref = 3;

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
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0}

};

void mostrar_matriz(){
  for (int y = 0; y<12;y++){
    for (int x = 0; x<12;x++){
      Serial.print(matriz[x][y]);
    }
    Serial.println(" ");
  }



}


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

  Serial.println(""); //PULA UMA LINHA NA JANELA SERIAL
  Serial.println(""); //PULA UMA LINHA NA JANELA SERIAL
  Serial.print("Conectando a "); //ESCREVE O TEXTO NA SERIAL
  Serial.print(ssid); //ESCREVE O NOME DA REDE NA SERIAL
  
  WiFi.begin(ssid, password); //PASSA OS PARÂMETROS PARA A FUNÇÃO QUE VAI FAZER A CONEXÃO COM A REDE SEM FIO
  
  while (WiFi.status() != WL_CONNECTED) { //ENQUANTO STATUS FOR DIFERENTE DE CONECTADO
  delay(500); //INTERVALO DE 500 MILISEGUNDOS
  Serial.print("."); //ESCREVE O CARACTER NA SERIAL
  }
  Serial.println(""); //PULA UMA LINHA NA JANELA SERIAL
  Serial.print("Conectado a rede sem fio "); //ESCREVE O TEXTO NA SERIAL
  Serial.println(ssid); //ESCREVE O NOME DA REDE NA SERIAL
  server.begin(); //INICIA O SERVIDOR PARA RECEBER DADOS NA PORTA DEFINIDA EM "WiFiServer server(porta);"
  Serial.println("Servidor iniciado"); //ESCREVE O TEXTO NA SERIAL
  
  Serial.print("IP para se conectar ao NodeMCU: "); //ESCREVE O TEXTO NA SERIAL
  Serial.print("http://"); //ESCREVE O TEXTO NA SERIAL
  Serial.println(WiFi.localIP()); //ESCREVE NA SERIAL O IP RECEBIDO DENTRO DA REDE SEM FIO (O IP NESSA PRÁTICA É RECEBIDO DE FORMA AUTOMÁTICA)
  
}

void pos(){
  //O = 0 N = 1 L=2 S=3
 if(ref == 0){
    x--;
    matriz [x][y] = 1;
    x--;
}
  else if(ref == 1){
    y--;
    matriz [x][y] = 1;
    y--;
}
  else if(ref == 2){
    x++;
    matriz [x][y] = 1;
    x++;
  }
  else if(ref == 3){
    y++;
    matriz [x][y] = 1;
    y++;
  }
  Serial.print("ref =");
  Serial.print(ref);
}
void frente(){
   Serial.println("Frente");
  analogWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, LOW);
  analogWrite(pwmMotorB, motorSpeed+27);
  digitalWrite(dirMotorB, HIGH);
  delay(2100);

  if(ref == 0){
    x--;
    matriz [x][y] = 1;
    x--;
  }
  else if(ref == 1){
    y--;
    matriz [x][y] = 1;
    y--;
  }
  else if(ref == 2){
    x++;
    matriz [x][y] = 1;
    x++;
  }
  else if(ref == 3){
    y++;
    matriz [x][y] = 1;
    y++;
  }
 
   Serial.print("ref =");
  Serial.print(ref);
    test = 1;

}

void direita(){
//O = 0 N = 1 L=2 S=3
 Serial.println("Direita");
 
   
    analogWrite(pwmMotorA, motorSpeed);
    digitalWrite(dirMotorA, LOW);
    analogWrite(pwmMotorB, motorSpeed);
    digitalWrite(dirMotorB, LOW);

    delay(1850);

  analogWrite(pwmMotorA, motorSpeed  );
  digitalWrite(dirMotorA, LOW);
  analogWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, HIGH);
  delay(2100);

  if(ref == 0)
    ref = 1;
  else if(ref == 1)
    ref = 2;
  else if(ref == 2)
    ref = 3;
  else if(ref == 3)
    ref = 0;

  pos();
  test = 2;
 

}

  

void esquerda(){
   Serial.println("Esquerda");

 
    analogWrite(pwmMotorA, motorSpeed);
    digitalWrite(dirMotorA, HIGH);
    analogWrite(pwmMotorB, motorSpeed);
    digitalWrite(dirMotorB, HIGH);
    delay(1600);

  analogWrite(pwmMotorA, motorSpeed );
  digitalWrite(dirMotorA, LOW);
  analogWrite(pwmMotorB, motorSpeed +27);
  digitalWrite(dirMotorB, HIGH);
  delay(2100);

  if(ref == 0)
    ref = 3;
  else if(ref == 3)
    ref = 2;
  else if(ref == 2)
    ref = 1;
  else if(ref == 1)
    ref = 0;

  pos();
  test = 3;
  
}

void retorno(){
    
   analogWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, LOW);
  analogWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, LOW);
  delay(3300);

  analogWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, HIGH);
  analogWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, LOW);
  delay(2100);
//O = 0 N = 1 L=2 S=3
  if(ref == 0)
    ref = 2;
  else if(ref == 2)
    ref = 0;
  else if(ref == 1)
    ref = 3;
  else if(ref == 3)
    ref = 1;


  test = 4;
}





  void loop()
{


  if (y > 12){
    while(true){
      analogWrite(pwmMotorA, 0  );
      digitalWrite(dirMotorA, LOW);
      analogWrite(pwmMotorB,0);
      digitalWrite(dirMotorB, LOW);
    }
  }
  if (x > 12){
    while(true){
      analogWrite(pwmMotorA, 0  );
      digitalWrite(dirMotorA, LOW);
      analogWrite(pwmMotorB,0);
      digitalWrite(dirMotorB, LOW);
    }
  }

  if (y < 0){
    while(true){
      analogWrite(pwmMotorA, 0  );
      digitalWrite(dirMotorA, LOW);
      analogWrite(pwmMotorB,0);
      digitalWrite(dirMotorB, LOW);
    }
  }
  if (x < 0){
    while(true){
      analogWrite(pwmMotorA, 0  );
      digitalWrite(dirMotorA, LOW);
      analogWrite(pwmMotorB,0);
      digitalWrite(dirMotorB, LOW);
    }
  }
  //O = 0 N = 1 L=2 S=3
  delay(500);
  matriz [0][0] = 1;
  Serial.println("");
  mostrar_matriz();
    Serial.println("");
  analogWrite(pwmMotorA, 0  );
  digitalWrite(dirMotorA, LOW);
  analogWrite(pwmMotorB,0);
  digitalWrite(dirMotorB, LOW);
  delay(1000);
  //O = 0 N = 1 L=2 S=3
    


  valor1 = digitalRead(sensor1);
  htsensor1 = digitalRead(sensor1);
 Serial.println(valor1);//Diminuir energia**/
  valor2 = digitalRead(sensor2);
    htsensor2 = digitalRead(sensor2);
  Serial.print(valor2); //valor invertido;
  valor3 = digitalRead(sensor3);
    htsensor3 = digitalRead(sensor3);
 Serial.print(valor3);
  
    
  if(valor1 == 0 and valor2 == 1 and valor3 ==0){
   // paredes(false,true,false);
    frente();
    matriz  [x][y] = 1;
}

  else if(valor1 == 0 and valor2 == 0 and valor3 ==1){
  //  paredes(false,false,true);
    direita();
    matriz  [x][y] = 1;
    }
   
  else if(valor1 == 1 and valor2 == 0 and valor3 ==0){
   // paredes(true,false,false);
    esquerda();
    matriz  [x][y] = 1;
    }

  else if(valor1 == 0 and valor2 == 0 and valor3 ==0){
    retorno();
    }


  else if(valor1 == 0 and valor2 == 1 and valor3 ==1){
  
      direita();
      matriz  [x][y] = 1;
    
  
   
    }
  else if(valor1 == 1 and valor2 == 0 and valor3 ==1){
    
   
      direita();
      matriz  [x][y] = 1;
    
  
    }
  else if(valor1 == 1 and valor2 == 1 and valor3 ==0){
    escolher = random(0,2);
    if (escolher == 1){
     // paredes(true,true,false);
      esquerda();
      matriz  [x][y] = 1;
    }
    else if (escolher == 2){
     // paredes(true,true,false);
      frente();
      matriz  [x][y] = 1;
    }
  } 
   else if(valor1 == 1 and valor2 == 1 and valor3 ==1){
      delay(1000);
    }

    Serial.println("");
    Serial.print("X:");
    Serial.println(x);
    Serial.print("Y:");
    Serial.print(y);
    Serial.println("");
  
  /*else if(valor1 == 1 and valor2 == 1 and valor3 ==1)
    Serial.print(sai);

  };*/
 

WiFiClient client = server.available(); //VERIFICA SE ALGUM CLIENTE ESTÁ CONECTADO NO SERVIDOR
if (!client) { //SE NÃO EXISTIR CLIENTE CONECTADO, FAZ
return; //REEXECUTA O PROCESSO ATÉ QUE ALGUM CLIENTE SE CONECTE AO SERVIDOR
}
Serial.println("Novo cliente se conectou!"); //ESCREVE O TEXTO NA SERIAL

String request = client.readStringUntil('\r'); //FAZ A LEITURA DA PRIMEIRA LINHA DA REQUISIÇÃO
Serial.println(request); //ESCREVE A REQUISIÇÃO NA SERIAL
client.flush(); //AGUARDA ATÉ QUE TODOS OS DADOS DE SAÍDA SEJAM ENVIADOS AO CLIENTE
 
client.println("HTTP/1.1 200 OK"); //ESCREVE PARA O CLIENTE A VERSÃO DO HTTP
client.println("Content-Type: text/html"); //ESCREVE PARA O CLIENTE O TIPO DE CONTEÚDO(texto/html)
client.println("");
client.println("<!DOCTYPE HTML>"); //INFORMA AO NAVEGADOR A ESPECIFICAÇÃO DO HTML
client.println("<html>"); //ABRE A TAG "html"

client.println("Funcao:"); 
client.print(test); 
client.println("<br>"); 
client.println("sensor1:"); 
client.print(valor1); 
client.println("<br>"); 
client.println("sensor2:"); 
client.print(valor2); 
client.println("<br>"); 
client.println("sensor3:"); 
client.print(valor3); 
client.println("<br>"); 
client.println("referencia:"); 
//O = 0 N = 1 L=2 S=3
if(ref == 0 ){
  client.print("Oeste"); 
}
else if(ref == 1 ){
  client.print("Norte"); 
}
else if(ref == 2 ){
  client.print("Leste"); 
}
else if(ref == 3 ){
  client.print("Sul"); 
}
client.println("<br>"); 
client.println("<br>"); 
 client.print("Matriz"); 
client.println("<br>"); 

  for (int y = 0; y<12;y++){
    for (int x = 0; x<12;x++){
     client.print(matriz[x][y]);
    }
    client.println("<br>"); 
  }


  client.println("<br>");
    client.println("X:");
    client.print(x);
    client.println("Y:");
    client.println(y);
    client.println("<br>");
    if (x == 12 and y ==12)
  {
    client.println("Acabou");
  }


client.println("</center></h1>"); //ESCREVE "Ola cliente!" NA PÁGINA
client.println("<center><font size='5'></center>"); //ESCREVE "Seja bem vindo!" NA PÁGINA
client.println("</html>"); //FECHA A TAG "html"
delay(1); //INTERVALO DE 1 MILISEGUNDO
Serial.println("Cliente desconectado"); //ESCREVE O TEXTO NA SERIAL
Serial.println(""); //PULA UMA LINHA NA JANELA SERIAL

}
