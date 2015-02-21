/*

@ Filename: BiWheel.h

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

#ifndef BiWheel_h
#define BiWheel_h

#define PWM_MIN 150
#define PWM_MAX 255

#define LM 0
#define RM 1
#define LRM 2
#define RLM 2

class BiWheel
{
	public:
		virtual inline int spdToPWMduty(int);
		virtual void leftMotorStop();
		virtual void rightMotorStop();
		virtual void leftMotorForwardPWM(int);
		virtual void leftMotorBackwardPWM(int);
		virtual void rightMotorForwardPWM(int);
		virtual void rightMotorBackwardPWM(int);
		virtual void leftMotor(int);
		virtual void rightMotor(int);
		virtual void drive(int, int);
};

class BiWheel4pin : public BiWheel
{
	public:
		BiWheel4pin(int, int, int, int);
		inline int spdToPWMduty(int);
		void leftMotorStop();
		void rightMotorStop();
		void leftMotorForwardPWM(int);
		void leftMotorBackwardPWM(int);
		void rightMotorForwardPWM(int);
		void rightMotorBackwardPWM(int);
		void leftMotor(int);
		void rightMotor(int);
		void drive(int, int);

	private:
		int _in1;
		int _in2;
		int _in3;
		int _in4;
		int _inpl;
		int _inpr;


		int _spdl;
		int _spdr;
		int _spd;
		int _mtr;
};


class BiWheel6pin : public BiWheel
{
	public:
		BiWheel6pin(int, int, int, int, int, int);
		inline int spdToPWMduty(int);
		void leftMotorStop();
		void rightMotorStop();
		void leftMotorForwardPWM(int);
		void leftMotorBackwardPWM(int);
		void rightMotorForwardPWM(int);
		void rightMotorBackwardPWM(int);
		void leftMotor(int);
		void rightMotor(int);
		void drive(int, int);

	private:
		int _in1;
		int _in2;
		int _in3;
		int _in4;
		int _inpl;
		int _inpr;


		int _spdl;
		int _spdr;
		int _spd;
		int _mtr;
};

#endif
