/*

@ Filename: BiWheel.cpp

@ BiWheel is an Arduino library for chassis with two motors
@ driven by L293 or L298 H-bridge.

@ Created by Ilya S. Dubkov
@ e-mail: dubkov@skbrii.ru
@ April 24, 2014

@ Last update: Feb 17, 2015
@ by Ilya S. Dubkov

@ License information:

@ This library is free software; you can redistribute it and/or
@ modify it under the terms of the GNU Lesser General Public
@ License as published by the Free Software Foundation; either
@ version 2.1 of the License, or (at your option) any later version.

@ This library is distributed in the hope that it will be useful,
@ but WITHOUT ANY WARRANTY; without even the implied warranty of
@ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
@ Lesser General Public License for more details.

*/

#include <stdlib.h>
#include <Arduino.h>
#include "BiWheel.h"

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

inline int biWheel::spdToPWMduty(int spdtpwmdt){
	return map(spdtpwmdt, 0, 100, PWM_MIN, PWM_MAX);
}

void biWheel::leftMotorStop(){
	digitalWrite(_in1, LOW);
	digitalWrite(_in2, LOW);
}

void biWheel::rightMotorStop(){
	digitalWrite(_in3, LOW);
	digitalWrite(_in4, LOW);
}

void biWheel::leftMotorForwardPWM(int spdl){

	_spdl = spdToPWMduty(spdl);

	digitalWrite(_in2, LOW);
	analogWrite(_in1, _spdl);
}

void biWheel::leftMotorBackwardPWM(int spdl){

	_spdl = spdToPWMduty(spdl);

	digitalWrite(_in1,LOW);
	digitalWrite(_in2, HIGH);
	analogWrite(_in1, 255-_spdl);
}

void biWheel::rightMotorForwardPWM(int spdr){

	_spdr = spdToPWMduty(spdr);

	digitalWrite(_in4, LOW);
	analogWrite(_in3, _spdr);
}

void biWheel::rightMotorBackwardPWM(int spdr){

	_spdr = spdToPWMduty(spdr);

	digitalWrite(_in3, LOW);
	digitalWrite(_in4, HIGH);
	analogWrite(_in3, 255-_spdr);
}

void biWheel::leftMotor(int spdl){
	if ( spdl == 0 ){
		leftMotorStop();
	}
	else if ( spdl > 0 ){
		leftMotorForwardPWM(spdl);
	}
	else {
		leftMotorBackwardPWM(abs(spdl));
	}
}

void biWheel::rightMotor(int spdr){
	if ( spdr == 0 ){
		rightMotorStop();
	}
	else if ( spdr > 0 ){
		rightMotorForwardPWM(spdr);
	}
	else {
		rightMotorBackwardPWM(abs(spdr));
	}
}

void biWheel::drive(int mtr, int spd){

	_mtr = mtr;
	_spd = spd;

	if ( _mtr == 0 ){
		rightMotor(_spd);
	}
	else if ( _mtr == 1 ){
		leftMotor(_spd);
	}
	else if ( _mtr == 2 ){
		leftMotor(_spd);
		rightMotor(_spd);
	}
	else return;
}
