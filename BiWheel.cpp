/* BiWheel.cpp
BiWheel is Arduino library for chassis with two motors driven by l293d or l298d H-bridge.  

Created by Ilya S. Dubkov, April 24, 2014

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.
*/

#include "stdlib.h"
#include "BiWheel.h"

#define LM 0
#define RM 1
#define LRM 2
#define RLM 2

#define PWM_MIN 150
#define PWM_MAX 255

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
	_spdl = map(spdl,0,100,PWM_MIN,PWM_MAX);
	digitalWrite(_in2,LOW);
	analogWrite(_in1,_spdl);
}

void biWheel::leftMotorBackwardPWM(int spdl){
	_spdl=map(spdl,0,100,PWM_MIN,PWM_MAX);
	digitalWrite(_in1,LOW);
	analogWrite(_in2,_spdl);
}

void biWheel::rightMotorForwardPWM(int spdr){
	_spdr=map(spdr,0,100,PWM_MIN,PWM_MAX);
	digitalWrite(_in4,LOW);
	analogWrite(_in3,_spdr);
}

void biWheel::rightMotorBackwardPWM(int spdr){
	_spdr=map(spdr,0,100,PWM_MIN,PWM_MAX);
	digitalWrite(_in3,LOW);
	analogWrite(_in4,_spdr);
}

void biWheel::leftMotor(int spdl){
	if ( spdl == 0 ){ leftMotorStop(); }
	else if ( spdl > 0 ){ leftMotorForwardPWM(spdl); }
	else if ( spdl < 0 ) { leftMotorBackwardPWM(abs(spdl)); }
}

void biWheel::rightMotor(int spdr){
	if ( spdr == 0 ){ rightMotorStop(); }
	else if ( spdr > 0 ){ rightMotorForwardPWM(spdr); }
	else if ( spdr < 0 ) { rightMotorBackwardPWM(abs(spdr)); }
}

void biWheel::drive(boolean mtr, int spd){
	_mtr = mtr;
	_spd = spd;	
	if ( _mtr == 0 ){ rightMotor(_spd); }
	else if ( _mtr == 1 ){ leftMotor(_spd);}
	else if ( _mtr == 2 ){ leftMotor(_spd); rightMotor(_spd); }
}
