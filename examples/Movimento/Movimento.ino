/*
 * Movimento.ino - Example Program - Library for L298N Dual H-Bridge Motor Controller.
 * Created by Gustavo M. Pereira, May 04, 2017.
 * Updated by Gustavo M. Pereira, Apr 15, 2018.
*/

#include <L298N.h>

L298N motoresAB(13, 12, 11, 8, 7, 6);

void setup() {
}

void loop() {
  motoresAB.setSpeeds(255, 255);   // Movimento para frente
  delay(2000);
  motoresAB.setSpeeds(-255, -255); // Movimento para trás
  delay(2000);
  motoresAB.setSpeeds(255, -255);  // Vira para a direita
  delay(2000);
  motoresAB.setSpeeds(-255, 255);  // Vira para a esquerda
  delay(2000);
}
