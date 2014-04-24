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
