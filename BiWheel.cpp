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

BiWheel4pin::BiWheel4pin(int in1, int in2, int in3, int in4):BiWheel()
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

inline int BiWheel4pin::spdToPWMduty(int spdtpwmdt){
	return map(spdtpwmdt, 0, 100, PWM_MIN, PWM_MAX);
}

void BiWheel4pin::leftMotorStop(){
	digitalWrite(_in1, LOW);
	digitalWrite(_in2, LOW);
}

void BiWheel4pin::rightMotorStop(){
	digitalWrite(_in3, LOW);
	digitalWrite(_in4, LOW);
}

void BiWheel4pin::leftMotorForwardPWM(int spdl){

	_spdl = spdToPWMduty(spdl);

	digitalWrite(_in2, LOW);
	analogWrite(_in1, _spdl);
}

void BiWheel4pin::leftMotorBackwardPWM(int spdl){

	_spdl = spdToPWMduty(spdl);

	digitalWrite(_in1, LOW);
	analogWrite(_in2, _spdl);
}

void BiWheel4pin::rightMotorForwardPWM(int spdr){

	_spdr = spdToPWMduty(spdr);

	digitalWrite(_in4, LOW);
	analogWrite(_in3, _spdr);
}

void BiWheel4pin::rightMotorBackwardPWM(int spdr){

	_spdr = spdToPWMduty(spdr);

	digitalWrite(_in3, LOW);
	analogWrite(_in4, _spdr);
}

void BiWheel4pin::leftMotor(int spdl){
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

void BiWheel4pin::rightMotor(int spdr){
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

void BiWheel4pin::drive(int mtr, int spd){

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

//BiWheel6pin

BiWheel6pin::BiWheel6pin(int in1, int in2, int in3, int in4, int inpl, int inpr):BiWheel()
{
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
//	pinMode(inpl, OUTPUT);
//	pinMode(inpr, OUTPUT);


	_in1 = in1;
	_in2 = in2;
	_in3 = in3;
	_in4 = in4;
	_inpl = inpl;
	_inpr = inpr;
}

inline int BiWheel6pin::spdToPWMduty(int spdtpwmdt){
	return map(spdtpwmdt, 0, 100, PWM_MIN, PWM_MAX);
}

void BiWheel6pin::leftMotorStop(){
	digitalWrite(_in1, LOW);
	digitalWrite(_in2, LOW);
	digitalWrite(_spdl, LOW);
}

void BiWheel6pin::rightMotorStop(){
	digitalWrite(_in3, LOW);
	digitalWrite(_in4, LOW);
	digitalWrite(_spdr, LOW);
}

void BiWheel6pin::leftMotorForwardPWM(int spdl){

	_spdl = spdToPWMduty(spdl);

	digitalWrite(_in1, HIGH);
	digitalWrite(_in2, LOW);
	analogWrite(_inpl, _spdl);
}


void BiWheel6pin::leftMotorBackwardPWM(int spdl){

	_spdl = spdToPWMduty(spdl);

	digitalWrite(_in1, LOW);
	digitalWrite(_in2, HIGH);
	analogWrite(_inpl, _spdl);
}


void BiWheel6pin::rightMotorForwardPWM(int spdr){

	_spdr = spdToPWMduty(spdr);

	digitalWrite(_in4, LOW);
	digitalWrite(_in3, LOW);
	analogWrite(_inpr, _spdr);
}


void BiWheel6pin::rightMotorBackwardPWM(int spdr){

	_spdr = spdToPWMduty(spdr);

	digitalWrite(_in3, LOW);
	digitalWrite(_in4, LOW);
	analogWrite(_inpr, _spdr);
}


void BiWheel6pin::leftMotor(int spdl){
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


void BiWheel6pin::rightMotor(int spdr){
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

void BiWheel6pin::drive(int mtr, int spd){

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
