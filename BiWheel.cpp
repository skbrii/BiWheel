/* biWheel.cpp
biWheel is Arduino library for chassis with two motors driven by l293d or l298d H-bridge.  

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

biWheel4::biWheel4(int in1, int in2, int in3, int in4)
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

void biWheel4::leftMotorForward(){
	digitalWrite(_in2,LOW);
	digitalWrite(_in1,HIGH);
}

void biWheel4::leftMotorBackward(){
	digitalWrite(_in1,LOW);
	digitalWrite(_in2,HIGH);
}

void biWheel4::leftMotorStop(){
	digitalWrite(_in1,LOW);
	digitalWrite(_in2,LOW);
}

void biWheel4::rightMotorForward(){
	digitalWrite(_in4,LOW);
	digitalWrite(_in3,HIGH);
}

void biWheel4::rightMotorBackward(){
	digitalWrite(_in3,LOW);
	digitalWrite(_in4,HIGH);
}

void biWheel4::rightMotorStop(){
	digitalWrite(_in3,LOW);
	digitalWrite(_in4,LOW);
}






void biWheel4::leftMotorForwardPWM(int spdl){
	_spdl = map(spdl,0,100,150,255);
	digitalWrite(_in2,LOW);
	analogWrite(_in1,_spdl);
}

void biWheel4::leftMotorBackwardPWM(int spdl){
	_spdl=map(spdl,0,100,150,255);
	digitalWrite(_in1,LOW);
	analogWrite(_in2,_spdl);
}

void biWheel4::rightMotorForwardPWM(int spdr){
	_spdr=map(spdr,0,100,150,255);
	digitalWrite(_in4,LOW);
	analogWrite(_in3,_spdr);
}

void biWheel4::rightMotorBackwardPWM(int spdr){
	_spdr=map(spdr,0,100,150,255);
	digitalWrite(_in3,LOW);
	analogWrite(_in4,_spdr);
}

void biWheel4::leftMotor(int spdl){
	if ( spdl == 0 ){ leftMotorStop(); }
	else if ( spdl > 0 ){ leftMotorForwardPWM(spdl); }
	else if ( spdl < 0 ) { leftMotorBackwardPWM(abs(spdl)); }
}

void biWheel4::rightMotor(int spdr){
	if ( spdr == 0 ){ rightMotorStop(); }
	else if ( spdr > 0 ){ rightMotorForwardPWM(spdr); }
	else if ( spdr < 0 ) { rightMotorBackwardPWM(abs(spdr)); }
}

void biWheel4::drive(boolean mtr, int spd){
	_mtr = mtr;
	_spd = spd;	
	if ( _mtr == 0 ){ rightMotor(_spd);}
	else if ( _mtr == 1 ){ leftMotor(_spd);}
}

biWheel6::biWheel6(int in1, int in2, int in3, int in4, int ena, int enb)
{
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	_in1 = in1;
	_in2 = in2;
	_in3 = in3;
	_in4 = in4;
	_ena = ena;
	_enb = enb;
}

void biWheel6::leftMotorForward(){
	digitalWrite(_in2,LOW);
	digitalWrite(_in1,HIGH);
}

void biWheel6::leftMotorBackward(){
	digitalWrite(_in1,LOW);
	digitalWrite(_in2,HIGH);
}

void biWheel6::leftMotorStop(){
	digitalWrite(_in1,LOW);
	digitalWrite(_in2,LOW);
}

void biWheel6::rightMotorForward(){
	digitalWrite(_in4,LOW);
	digitalWrite(_in3,HIGH);
}

void biWheel6::rightMotorBackward(){
	digitalWrite(_in3,LOW);
	digitalWrite(_in4,HIGH);
}

void biWheel6::rightMotorStop(){
	digitalWrite(_in3,LOW);
	digitalWrite(_in4,LOW);
}






void biWheel6::leftMotorForwardPWM(int spdl){
	_spdl = map(spdl,0,100,150,255);
	digitalWrite(_in2,LOW);
	digitalWrite(_in1,HIGH);
	analogWrite(_ena, spdl);
}

void biWheel6::leftMotorBackwardPWM(int spdl){
	_spdl=map(spdl,0,100,150,255);
	digitalWrite(_in1,LOW);
	digitalWrite(_in2,HIGH);
	analogWrite(_ena,_spdl);
}

void biWheel6::rightMotorForwardPWM(int spdr){
	_spdr=map(spdr,0,100,150,255);
	digitalWrite(_in4,LOW);
	digitalWrite(_in3,HIGH);
	analogWrite(_enb,_spdr);
}

void biWheel6::rightMotorBackwardPWM(int spdr){
	_spdr=map(spdr,0,100,150,255);
	digitalWrite(_in3,LOW);
	digitalWrite(_in4,HIGH);
	analogWrite(_enb,_spdr);
}

void biWheel6::leftMotor(int spdl){
	if ( spdl == 0 ){ leftMotorStop(); }
	else if ( spdl > 0 ){ leftMotorForwardPWM(spdl); }
	else if ( spdl < 0 ) { leftMotorBackwardPWM(abs(spdl)); }
}

void biWheel6::rightMotor(int spdr){
	if ( spdr == 0 ){ rightMotorStop(); }
	else if ( spdr > 0 ){ rightMotorForwardPWM(spdr); }
	else if ( spdr < 0 ) { rightMotorBackwardPWM(abs(spdr)); }
}

void biWheel6::drive(boolean mtr, int spd){
	_mtr = mtr;
	_spd = spd;	
	if ( _mtr == 0 ){ rightMotor(_spd);}
	else if ( _mtr == 1 ){ leftMotor(_spd);}
}
	
