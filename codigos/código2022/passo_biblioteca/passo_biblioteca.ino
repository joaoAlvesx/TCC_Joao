'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''#include <Stepper.h>

const int PassoPorVolta = 500;
Stepper MotorP(PassoPorVolta, 4, 5, 6, 7);

void setup() {
  MotorP.setSpeed(100);

}

void loop() {
  // Gira 360 graus no sentido horario
  // Em 3 degraus de 120 graus
  for (int i=0; i<3; i++) {
  MotorP.step(682);
  delay(1000);
  }
  // Gira 360 graus no sentido anti-horario
  // Em 3 degraus de 120 graus
  for (int i=0; i<3; i++) {
  MotorP.step(-682);
  delay(1000);
  }
  
}
