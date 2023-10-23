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
/*
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Configração do WiFi
const char* ssid = "IFMaker Adm";  // SSID Wifi
const char* password = "@IFM4k3r";  // Senha Wifi
ESP8266WebServer server(80);
bool LEDstatus = LOW;
*/int test = 0;

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
/*
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Rede WiFi: ");
  Serial.println(ssid);
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
  delay(100);

  server.on("/", handle_OnConnect);
  server.on("/ledon", handle_ledon);
  server.on("/ledoff", handle_ledoff);
  server.onNotFound(handle_NotFound);
  server.begin();
  Serial.println("Servidor HTTP iniciado!");
*/
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
  
  analogWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, LOW);
  analogWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, LOW);
  delay(2500);

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
 Serial.println("frente" );
   Serial.print("ref =");
  Serial.print(ref);

}

void direita(){
//O = 0 N = 1 L=2 S=3
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

  if(ref == 0)
    ref = 1;
  else if(ref == 1)
    ref = 2;
  else if(ref == 2)
    ref = 3;
  else if(ref == 3)
    ref = 0;

  pos();
 
  Serial.println("Direita");
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

  if(ref == 0)
    ref = 3;
  else if(ref == 3)
    ref = 2;
  else if(ref == 2)
    ref = 1;
  else if(ref == 1)
    ref = 0;

  pos();

   Serial.println("Esquerda");
}

void retorno(){
    while (valor2 == 0 and valor3 == 0){
      valor2 = digitalRead(sensor2);
      valor3 = digitalRead(sensor3);
      analogWrite(pwmMotorA, 100);
      digitalWrite(dirMotorA, LOW);
      analogWrite(pwmMotorB, 100);
      digitalWrite(dirMotorB, HIGH);
  }

    analogWrite(pwmMotorA, motorSpeed);
    digitalWrite(dirMotorA, HIGH);
    analogWrite(pwmMotorB, motorSpeed);
    digitalWrite(dirMotorB, LOW);
    delay(500);
  
}





  void loop()
{
  //server.handleClient();    // Faz o Handle
  //O = 0 N = 1 L=2 S=3

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
 // Serial.print(valor1);//Diminuir energia**/
  valor2 = digitalRead(sensor2);
  //Serial.print(valor2); //valor invertido;
  valor3 = digitalRead(sensor3);
 // Serial.print(valor3);
  
    
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
    Serial.println("Nenhum canto");
    }


  else if(valor1 == 0 and valor2 == 1 and valor3 ==1){
    escolher = random(1,2);
    if (escolher == 1){
   //   paredes(false,true,true);
      frente();
      matriz  [x][y] = 1;
    }
    else if (escolher == 2){
     // paredes(false,true,true);
      direita();
      matriz  [x][y] = 1;
    }
  
   
    }
  else if(valor1 == 1 and valor2 == 0 and valor3 ==1){
   escolher = random(1,2);
    if (escolher == 1){
     // paredes(true,false,true);
      esquerda();
      matriz  [x][y] = 1;
    }
    else if (escolher == 2){
     // paredes(true,false,true);
      direita();
      matriz  [x][y] = 1;
    }
  
    }
  else if(valor1 == 1 and valor2 == 1 and valor3 ==0){
    escolher = random(1,2);
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
  if (x == 12 and y ==12)
  {
    Serial.println("Acabou");
  }
  /*else if(valor1 == 1 and valor2 == 1 and valor3 ==1)
    Serial.print(sai);

  };*/
 



}/*
 void handle_OnConnect() {
  LEDstatus = LOW;
  server.send(200, "text/html", SendHTML(false));
}

void handle_ledon() {
  LEDstatus = HIGH;
  server.send(200, "text/html", SendHTML(true));
}

void handle_ledoff() {
  LEDstatus = LOW;
  server.send(200, "text/html", SendHTML(false));
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}


 String SendHTML(uint8_t led) {
  String ptr = "<!DOCTYPE html>\n";
  ptr += "<html>\n";
  ptr += "<head>\n";
  ptr += "<title>Codigo TCC</title>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += test;
  /*ptr += "<form method=\"get\">\n";
  if (led)
    ptr += "<input type=\"button\" value=\"LED OFF\" onclick=\"window.location.href='/ledoff'\">\n";
  else
    ptr += "<input type=\"button\" value=\"LED ON\" onclick=\"window.location.href='/ledon'\">\n";
  ptr += "</form>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;*/
  
