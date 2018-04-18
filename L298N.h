/*
 * L298N.h - Library for L298N Dual H-Bridge Motor Controller.
 * Created by Gustavo M. Pereira, May 04, 2017.
 * Updated by Gustavo M. Pereira, Apr 15, 2018.
*/

#ifndef L298N_H
#define L298N_H

#include "Arduino.h"

//Constantes
#define  CW 1 // Sentido Horário
#define ACW 0 // Sentido Anti-horário

class L298N {
  public:
    L298N(byte _INA1, byte _INA2, byte _INB1, byte _INB2, byte _ENA, byte _ENB);
    void setSpeeds(int speedA, int speedB);
    void brakeMotors(long ms);

  private:
    int _speedA,
        _speedB;
    byte _INA1,
         _INA2,
         _INB1,
         _INB2,
         _directionA,
         _directionB,
         _ENA,
         _ENB;
};
#endif
