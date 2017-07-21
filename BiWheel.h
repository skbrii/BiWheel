/**

 BiWheel is an Arduino library for chassis with two motors
 driven by L293 or L298 H-bridge.

 @ Filename: BiWheel.h
 @ Repository: https://github.com/skbrii/BiWheel

 @ Created by Ilya S. Dubkov (dubkov@skbrii.ru)
 @ Licensed under MIT X11 License

 */

#include <stdint.h>

#ifndef BiWheel_h
#define BiWheel_h

class BiWheel {

	public:

		// Speed on left motor
		int8_t speedLeft;

		// Speed on right motor
		int8_t speedRight;

		// Constructor with default PWM limits
		BiWheel(uint8_t, uint8_t, uint8_t, uint8_t);

		// Constructor with custom PWM limits
		BiWheel(uint8_t, uint8_t, uint8_t, uint8_t, uint16_t, uint16_t);

		// Speed to duty conversion
		uint16_t speedToPWMDuty(int8_t);

		// Left motor stop
		void leftMotorStop();

		// Right motor stop
		void rightMotorStop();

		// Set speed on left motor
		void leftMotor(int8_t);

		// Set speed on right motor
		void rightMotor(int8_t);

		// Set speeds for each motors
		void drive(int8_t, int8_t);

	private:

		// Minimal PWM duty (speed = 0)
		uint16_t _PWM_MIN;

		// Maximum PWM duty (speed = 100)
		uint16_t _PWM_MAX;

		// Pins on H-bridge
		uint8_t _IN1;
		uint8_t _IN2;
		uint8_t _IN3;
		uint8_t _IN4;

};

#endif
