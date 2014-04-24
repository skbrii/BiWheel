#include "stdlib.h"
//#include "Arduino.h"
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






void biWheel::leftMotorForwardPWM(int spdl){
	_spdl = map(spdl,0,100,150,255);
  digitalWrite(_in2,LOW);
  analogWrite(_in1,_spdl);
}

void biWheel::leftMotorBackwardPWM(int spdl){
	_spdl=map(spdl,0,100,150,255);
  digitalWrite(_in1,HIGH);
  analogWrite(_in2,_spdl);
}

void biWheel::rightMotorForwardPWM(int spdr){
	_spdr=map(spdr,0,100,150,255);
digitalWrite(_in4,LOW);
  analogWrite(_in3,_spdr);
}

void biWheel::rightMotorBackwardPWM(int spdr){
	_spdr=map(spdr,0,100,150,255);
  digitalWrite(_in3,HIGH);
  analogWrite(_in4,_spdr);
}

void biWheel::leftMotor(int spdl){
	if ( spdl == 0 ){ leftMotorStop(); }
	else if ( spdl > 0 ){ leftMotorForwardPWM(abs(spdl)); }
	else { leftMotorBackwardPWM(spdl); }
}

void biWheel::rightMotor(int spdr){
	if ( spdr == 0 ){ rightMotorStop(); }
	else if ( spdr > 0 ){ rightMotorForwardPWM(abs(spdr)); }
	else { rightMotorBackwardPWM(spdr); }
}

