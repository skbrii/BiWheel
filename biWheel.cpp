#include "Arduino.h"
#include "biWheel.h"

biWheel::biWheel(int in1, int in2, int in3, int in4)
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  _in1 = in1;
  _in2 = in2;
  _in3 = in3;
  _in4 = in4;
}

void biWheel::leftMotorForward(){
  digitalWrite(_in2,LOW);
  digitalWrite(_in1,HIGH);
}

void biWheel::leftMotorBackward(){
  digitalWrite(_in1,LOW);
  digitalWrite(_in2,HIGH);
}

void biWheel::leftMotorStop(){
  digitalWrite(_in1,LOW);
  digitalWrite(_in2,LOW);
}

void biWheel::rightMotorForward(){
  digitalWrite(_in4,LOW);
  digitalWrite(_in3,HIGH);
}

void biWheel::rightMotorBackward(){
  digitalWrite(_in3,LOW);
  digitalWrite(_in4,HIGH);
}

void biWheel::rightMotorStop(){
  digitalWrite(_in3,LOW);
  digitalWrite(_in4,LOW);
}
