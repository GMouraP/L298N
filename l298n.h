/*
 * L298N.h - Library for L298N Dual H-Bridge Motor Controller.
 * Created by Gustavo M. Pereira, May 04, 2017.
*/

#ifndef l298n_h
#define l298n_h

#include "Arduino.h"

//Constantes
#define  CW 1 //CW é uma abreviação americana para "Clockwise", que significa "sentido horário"
#define ACW 0 //ACW é uma abreviação americana para "Anticlockwise", que significa "sentido antihorário"

class l298n {
  public:
    l298n(byte _INA1, byte _INA2, byte _INB1, byte _INB2);
    void setSpeeds(int speedA, int speedB);
    void breakMotors(long ms);

  private:
    int _speedA,
        _speedB;
    byte _INA1,
         _INA2,
         _INB1,
         _INB2,
         _directionA,
         _directionB;
         //_ENA = ENA,
         //_ENB = ENB;
};
#endif
