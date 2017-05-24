/*
 * Movimento.ino - Example Program - Library for L298N Dual H-Bridge Motor Controller.
 * Created by Gustavo M. Pereira, May 04, 2017.
*/

#include <l298n.h>

l298n motoresAB(11,10,6,5);

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
