/*
 * Freio.ino - Example Program - Library for L298N Dual H-Bridge Motor Controller.
 * Created by Gustavo M. Pereira, May 04, 2017.
*/

#include <L298N.h>

L298N MotoresAB(11,10,6,5);

void setup() {  
}

void loop() {
  //Faz os motores girarem com velocidade total no sentido horário
  MotoresAB.setSpeeds(255,255);
  delay(1000);
  //Faz os motores frearem totalmente em 500ms
  MotoresAB.breakMotors(500);
  delay(2000);
  //Faz os motores girarem com velocidade total no sentido horário
  MotoresAB.setSpeeds(255,255);
  delay(1000);
  //Freia os motores instantaneamente
  MotoresAB.breakMotors(0);
}
