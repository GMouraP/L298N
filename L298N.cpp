/*
 * L298N.cpp - Library for L298N Dual H-Bridge Motor Controller.
 * Created by Gustavo M. Pereira, May 04, 2017.
*/

#include "Arduino.h"
#include "L298N.h"

L298N::L298N(byte INA1, byte INA2, byte INB1, byte INB2) {
  pinMode(INA1,OUTPUT);
  pinMode(INA2,OUTPUT);
  pinMode(INB1,OUTPUT);
  pinMode(INB2,OUTPUT);
  
  _INA1 = INA1;
  _INA2 = INA2;
  _INB1 = INB1;
  _INB2 = INB2;
  //_ENA = ENA;
  //_ENB = ENB;
}

void L298N::setSpeeds(int speedA, int speedB) {
  speedA < 0 ? _speedA = -speedA : _speedA = speedA;
  speedB < 0 ? _speedB = -speedB : _speedB = speedB;
  speedA = constrain(speedA, -250,250);
  speedB = constrain(speedB, -250,250);
  
  //Motor A
  if (speedA < 0) {
    analogWrite(_INA1, 125+(_speedA/2));
    analogWrite(_INA2, 125-(_speedA/2));
    _directionA = ACW;
  }
  else if (speedA > 0) {
    analogWrite(_INA1, 125-(_speedA/2));
    analogWrite(_INA2, 125+(_speedA/2));
    _directionA = CW;
  }
  //Motor B
  if (speedB < 0) {
    analogWrite(_INB1, 125+(_speedB/2));
    analogWrite(_INB2, 125-(_speedB/2));
    _directionB = ACW;
  }
  else if (speedB > 0) {
    analogWrite(_INB1, 125+(_speedB/2));
    analogWrite(_INB2, 125-(_speedB/2));
    _directionB = CW;
  }
}

void L298N::breakMotors(long ms) {
  if (ms > 1) {
    unsigned long timein = millis(); //Guarda o tempo atual da chamada da função em "timein"
    for(int x = ms; (millis()-timein) < ms; x--){ //x = tempo em ms dado como argumento
                                                  //"(millis()-timein)" - Verifica o tempo decorrido
                                                  //ainda é menor que o tempo desejado.
                                                  //"x--" -> x será decrescido até que o tempo restante chegue a zero.
      int speedA = map(_speedA,0,255,0,x); //"mapeia" a velocidade A para uma nova faixa de valores, determinada entre 0 e x
      int speedB = map(_speedB,0,255,0,x); //"mapeia" a velocidade B para uma nova faixa de valores, determinada entre 0 e x
      
      _directionA == CW ? analogWrite(_INA1, speedA) : analogWrite(_INA2, speedA); //Verifica qual o sentido de rotação do motor
                                                                                    //para identificar onde deve se alterar a velocidade
      _directionB == CW ? analogWrite(_INB1, speedB) : analogWrite(_INB2, speedB);//Verifica qual o sentido de rotação do motor
                                                                                    //para identificar onde deve se alterar a velocidade
    }
    
  }
  else { //Instant break
      _directionA == CW ? analogWrite(_INA1, 0) : analogWrite(_INA2, 0);
      _directionB == CW ? analogWrite(_INB1, 0) : analogWrite(_INB2, 0);
  }
}
