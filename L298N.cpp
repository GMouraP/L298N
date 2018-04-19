/*
 * L298N.cpp - Library for L298N Dual H-Bridge Motor Controller.
 * Created by Gustavo M. Pereira, May 04, 2017.
 * Updated by Gustavo M. Pereira, Apr 15, 2018.
*/

#include "Arduino.h"
#include "L298N.h"

L298N::L298N(byte INA1, byte INA2, byte ENA, byte INB1, byte INB2, byte ENB) {
  pinMode(INA1,OUTPUT);
  pinMode(INA2,OUTPUT);
  pinMode(INB1,OUTPUT);
  pinMode(INB2,OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  _INA1 = INA1;
  _INA2 = INA2;
  _INB1 = INB1;
  _INB2 = INB2;
  _ENA = ENA;
  _ENB = ENB;
}

void L298N::setSpeeds(int speedA, int speedB) {
  speedA < 0 ? _speedA = -speedA : _speedA = speedA;
  speedB < 0 ? _speedB = -speedB : _speedB = speedB;
  speedA = constrain(speedA, -255,255);
  speedB = constrain(speedB, -255,255);
  
  //Motor A
  if (speedA < 0) {
    digitalWrite (_INA1, HIGH);
    digitalWrite (_INA2,  LOW);
    analogWrite  (_ENA, _speedA);
    _directionA = ACW;
  }
  else if (speedA > 0) {
    digitalWrite (_INA1,  LOW);
    digitalWrite (_INA2, HIGH);
    analogWrite  (_ENA, _speedA);
    _directionA = CW;
  }
  //Motor B
  if (speedB < 0) {
    digitalWrite (_INB1, HIGH);
    digitalWrite (_INB2,  LOW);
    analogWrite  (_ENB, _speedB);
    _directionB = ACW;
  }
  else if (speedB > 0) {
    digitalWrite (_INB1, HIGH);
    digitalWrite (_INB2,  LOW);
    analogWrite  (_ENB, _speedB);
    _directionB = CW;
  }
}

void L298N::brakeMotors(long ms) {
  if (ms > 1) {
    unsigned long T0 = millis(), 
                  deltaT = 0,
                  x = ms;
    do {
      // Devido aos limites do PWM do Arduino, os valores de saída são ajustados para os valores das velocidades atuais
      // para que os motores freem sem perder sua direção ou pular para velocidades altas apenas para frear.
      _speedA = map(x, 0, ms, 0, 255);
      _speedB = map(x, 0, ms, 0, 255);
      analogWrite(_ENA, _speedA);
      analogWrite(_ENB, _speedB);

      deltaT = millis() - T0;
      x = ms - millis();
    } while(deltaT < ms);
  }
  else{ 
    analogWrite(_ENA, LOW);
    analogWrite(_ENB, LOW);
  }
}
