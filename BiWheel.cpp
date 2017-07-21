/**

 BiWheel is an Arduino library for chassis with two motors
 driven by L293 or L298 H-bridge.

 @ Filename: BiWheel.cpp
 @ Repository: https://github.com/skbrii/BiWheel

 @ Created by Ilya S. Dubkov (dubkov@skbrii.ru)
 @ Licensed under MIT X11 License

 */

#include <Arduino.h>
#include "BiWheel.h"

/**
 * BiWheel constructor with default PWM ranges
 * @param in1      IN1 pin on H-bridge
 * @param in2      IN2 pin on H-bridge
 * @param in3      IN3 pin on H-bridge
 * @param in4      IN4 pin on H-bridge
 */
BiWheel::BiWheel(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4) {

	// Set pins as output
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);

	// Private pin defenitions
	BiWheel::_IN1 = in1;
	BiWheel::_IN2 = in2;
	BiWheel::_IN3 = in3;
	BiWheel::_IN4 = in4;

	// Set default ranges
	BiWheel::_PWM_MIN = 150;
	BiWheel::_PWM_MAX = 250;

}


/**
 * BiWheel constructor with different PWM ranges
 * @param in1      IN1 pin on H-bridge
 * @param in2      IN2 pin on H-bridge
 * @param in3      IN3 pin on H-bridge
 * @param in4      IN4 pin on H-bridge
 * @param _PWM_MIN Minimum PWM value (default 150)
 * @param _PWM_MAX Maximum PWM value (default 250)
 */
BiWheel::BiWheel(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4, uint16_t _PWM_MIN = 150, uint16_t _PWM_MAX = 250) {

	// Set pins as output
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);

	// Private pin defenitions
	BiWheel::_IN1 = in1;
	BiWheel::_IN2 = in2;
	BiWheel::_IN3 = in3;
	BiWheel::_IN4 = in4;

	// Set PWM ranges
	BiWheel::_PWM_MIN = _PWM_MIN;
	BiWheel::_PWM_MAX = _PWM_MAX;

}


/**
 * Macros for converting speed to PWM duty value
 * @param  spdtpwmdt Speed
 * @return           PWM duty
 */
uint16_t BiWheel::speedToPWMDuty(int8_t speed){

	return map(speed, 0, 100, _PWM_MIN, _PWM_MAX);

}


/**
 * Stopping the left motor
 */
void BiWheel::leftMotorStop() {

	digitalWrite(_IN1, LOW);
	digitalWrite(_IN2, LOW);

}


/**
 * Stopping the right motor
 */
void BiWheel::rightMotorStop() {

	digitalWrite(_IN3, LOW);
	digitalWrite(_IN4, LOW);

}


/**
 * Set speed for left motor
 * @param speed Speed (-100 ~ 100)
 */
void BiWheel::leftMotor(int8_t speed) {

	// Stop motor
	if (speed == 0)  {

		// Stop motor
		BiWheel::leftMotorStop();

		// Stop function execution
		return;

	}

	// Save speed to private variable
	BiWheel::speedLeft = speed;

	// Make conversion
	uint16_t pwmDuty = BiWheel::speedToPWMDuty(abs(speed));

	// Forward
	if (speed > 0) {

		analogWrite(_IN3, pwmDuty);
		digitalWrite(_IN4, LOW);

	}

	// Backward
	else {

		digitalWrite(_IN3, LOW);
		analogWrite(_IN4, pwmDuty);

	}

}


/**
 * Set speed for left motor
 * @param speed Speed (-100 ~ 100)
 */
void BiWheel::rightMotor(int8_t speed) {

	// Stop motor
	if (speed == 0)  {

		// Stop motor
		BiWheel::rightMotorStop();

		// Stop function execution
		return;

	}

	// Save speed to private variable
	BiWheel::speedRight = speed;

	// Make conversion
	uint16_t pwmDuty = BiWheel::speedToPWMDuty(abs(speed));

	// Forward
	if (speed > 0) {

		analogWrite(_IN1, pwmDuty);
		digitalWrite(_IN2, LOW);

	}

	// Backward
	else {

		digitalWrite(_IN1, LOW);
		analogWrite(_IN2, pwmDuty);

	}

}


/**
 * Set speed
 * @param speedLeft  [description]
 * @param speedRight [description]
 */
void BiWheel::drive(int8_t speedLeft, int8_t speedRight) {

	// Apply speeds to motors
	BiWheel::leftMotor(speedLeft);
	BiWheel::rightMotor(speedRight);

}
