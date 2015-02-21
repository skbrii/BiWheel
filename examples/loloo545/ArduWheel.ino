// подключение библиотеки

#include "BiWheel.h"

// создание объекта для шасси
// аргументы - цифровые пины Arduino,
// к которым подключены IN1, IN2, IN3, IN4 H-моста


/*
class BiWheel...
abstract move

class BiWheel4pin : BiWheel
move

class BiWheel6pin : BiWheel
move

BiWheel chassis = BiWheel4pin(4, 5, 6, 7);

BiWheel chassis = BiWheel6pin(4, 5, 6, 7);

chassis.move()

*/

#define MOTOR1_L 4
#define MOTOR1_R 5
#define MOTOR1_P 10

#define MOTOR2_L 6
#define MOTOR2_R 7
#define MOTOR2_P 11

BiWheel6pin biWheel6pin = BiWheel6pin(4,5,6,7,10,11);
BiWheel* biWheel = &biWheel6pin;

void setup(){
	pinMode(MOTOR1_L, OUTPUT);
	pinMode(MOTOR1_R, OUTPUT);
	pinMode(MOTOR1_P, OUTPUT);
	pinMode(MOTOR2_L, OUTPUT);
	pinMode(MOTOR2_R, OUTPUT);
	pinMode(MOTOR2_P, OUTPUT);

} // остаётся пустым

/*
	* Основной метод drive вращает заданный мотор с заданной скоростью.
	* LM - левый мотор, RM - правый мотор, LRM и RLM - оба мотора.
	* Скорость указывается от 0 до 100 по модулю:
	* 0 - стоп, 100 - максимальная скорость.
	* Отрицательная скорость - мотор вращается назад.
	* Мотор может не крутиться при указании маленькой скорости -
	* это зависит от конкретной модели мотора.
	* После использования метода drive мотор будет продолжать
	* крутиться в указанную сторону с указанной скоростью,
	* пока не будет вызван новый метод с новыми значениями.
*/

void loop(){

	biWheel->leftMotorForwardPWM(100);
	delay(2000);
	biWheel->leftMotorStop();
	delay(2000);
/*
	digitalWrite(MOTOR1_L, LOW);
	digitalWrite(MOTOR1_R, LOW);
	digitalWrite(MOTOR1_P, HIGH);

	digitalWrite(MOTOR2_L, LOW);
	digitalWrite(MOTOR2_R, LOW);
	digitalWrite(MOTOR2_P, HIGH);

	delay(2000);

	digitalWrite(MOTOR1_L, LOW);
	digitalWrite(MOTOR1_R, HIGH);
	digitalWrite(MOTOR1_P, HIGH);

	digitalWrite(MOTOR2_L, LOW);
	digitalWrite(MOTOR2_R, HIGH);
	digitalWrite(MOTOR2_P, HIGH);
	delay(2000);

	digitalWrite(MOTOR1_L, HIGH);
	digitalWrite(MOTOR1_R, LOW);
	digitalWrite(MOTOR1_P, HIGH);

	digitalWrite(MOTOR2_L, HIGH);
	digitalWrite(MOTOR2_R, LOW);
	digitalWrite(MOTOR2_P, HIGH);
	delay(2000);

	digitalWrite(MOTOR1_L, LOW);
	digitalWrite(MOTOR1_R, HIGH);
	digitalWrite(MOTOR1_P, HIGH);

	digitalWrite(MOTOR2_L, HIGH);
	digitalWrite(MOTOR2_R, LOW);
	digitalWrite(MOTOR2_P, HIGH);
	delay(2000);

	digitalWrite(MOTOR1_L, HIGH);
	digitalWrite(MOTOR1_R, LOW);
	digitalWrite(MOTOR1_P, HIGH);

	digitalWrite(MOTOR2_L, LOW);
	digitalWrite(MOTOR2_R, HIGH);
	digitalWrite(MOTOR2_P, HIGH);
	delay(2000);
	*/
}
