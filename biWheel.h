/* biWheel.h
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

#ifndef biWheel_h
#define biWheel_h

#include "Arduino.h"

#define LM 0
#define RM 1


class biWheel
{
	public:
		biWheel(int in1, int in2, int in3, int in4);
		void leftMotorForward();
		void leftMotorBackward();
		void leftMotorStop();
		void rightMotorForward();
		void rightMotorBackward();
		void rightMotorStop();
		void leftMotorForwardPWM(int spdl);
		void leftMotorBackwardPWM(int spdl);
		void rightMotorForwardPWM(int spdr);
		void rightMotorBackwardPWM(int spdr);
		void drive(boolean mtr, int spd);
		void leftMotor(int spdl);
		void rightMotor(int spdr);
    
	private:
    		int _in1;
    		int _in2;
    		int _in3;
    		int _in4;
		int _spdl;
		int _spdr;
		int _spd;
		boolean _mtr;

};

#endif
