const int pwmMotorA = D1;
const int pwmMotorB = D2;
const int dirMotorA = D3;
const int dirMotorB = D4;

int motorVelocidade = 500;

void setup()
{
  pinMode(pwmMotorA , OUTPUT);
  pinMode(pwmMotorB, OUTPUT);
  pinMode(dirMotorA, OUTPUT);
  pinMode(dirMotorB, OUTPUT);
}
  void loop()
{
  analogWrite(pwmMotorA, motorVelocidade);
  digitalWrite(dirMotorA, LOW);
  analogWrite(pwmMotorB, motorVelocidade);
  digitalWrite(dirMotorB, LOW);
  delay(2500);

  analogWrite(pwmMotorA, motorVelocidade);
  digitalWrite(dirMotorA, HIGH);
  analogWrite(pwmMotorB, motorVelocidade);
  digitalWrite(dirMotorB, HIGH);
  delay(2500);
}




