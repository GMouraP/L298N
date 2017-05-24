/*
 * Movimento.ino - Example Program - Library for L298N Dual H-Bridge Motor Controller.
 * Created by Gustavo M. Pereira, May 04, 2017.
*/

#include <L298N.h>

L298N motoresAB(11,10,6,5);

void setup() {
}

void loop() {
  motoresAB.setSpeeds(255,   255);
  delay(2000);
  motoresAB.setSpeeds(-255, -255);
  delay(2000);
  motoresAB.setSpeeds(255, -255);
  delay(2000);
  motoresAB.setSpeeds(-255, 255);
  delay(2000);
}
