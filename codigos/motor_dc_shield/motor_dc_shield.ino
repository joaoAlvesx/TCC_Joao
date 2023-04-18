int in1 = 5;
int in2 = 0 ;
int i;
void setup()
{
  Serial.begin(9600);
  
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT); 
}
  void loop()
{
  for (i = 0; i<1023; i++ ){
    analogWrite(in1, i);
    analogWrite(in2, 0);
    delay(100);
  }


}