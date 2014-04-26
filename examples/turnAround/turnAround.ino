#include "biWheel.h"

biWheel chassis = biWheel(5,6,9,10);

void setup(){}

void loop(){
	chassis.drive(LM,100);
	chassis.drive(RM,-100);
	delay(2000);
	chassis.drive(LM,-80);
	chassis.drive(RM,80);
	delay(3000);
}