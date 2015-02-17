BiWheel
=======

Библиотека для двухколесного шасси, управляемого H-мостом L298 или L293. Предназначена для Arduino IDE 1.0.x, 1.5.x, 1.6.0.

+ Авторство: Илья Дубков (dubkov &lt;at&gt; skbrii.ru)
+ Дата создания: 24 апреля 2014.
+ Дата обновления: 17 февраля 2015.  
+ Сведения о лицензии: Библиотека опубликована под лицензией GNU Lesser General Public License v2.1.

Установка библиотеки
-------
Скачайте архив с библиотекой, кликнув по кнопке Download ZIP справа от этой записи.

Распакуйте содержимое и переименуйте папку BiWheel-master в BiWheel. Папку поместите в Arduino/libraries. Перезапустите Arduino IDE, если она была запущена.

После запуска Arduino IDE в примерах (Файл->примеры) появится строчка BiWheel с примерами использования библиотеки.

Подключение двигателей
-------

Для того, чтобы библиотека заработала с ходу для вашего шасси, следует подключать провода от моторов следующим образом:

- нижний провод правого мотора к OUT1,
- верхний провод правого мотора к OUT2,
- нижний провод левого мотора к OUT3,
- верхний провод левого мотора к OUT4.

Подключение H-моста
-------

Библиотека предусматривает подключение Arduino по 4-м проводам к входам H-моста IN1, IN2, IN3, IN4;

На Arduino будет занято 4 пина, причём все 4 должны уметь генерировать ШИМ-сигнал. ШИМ-сигналы можно получить на пинах 3, 5, 6, 9, 10, 11 Arduino UNO.

Для IN1, IN2, IN3 и IN4 рекомендуется использовать пины 11, 3, 9 и 10 поскольку на них одна и та же частота ШИМ.

Описание API
-----

Для подключения библиотеки к проекту включите следующую строку в самое начало скетча

    #include "BiWheel.h"

Для работы с шасси необходимо создать объект класса `biWheel`. Он может быть назван любым образом. В примере ниже объект называется `chassis`

    biWheel chassis = biWheel(11, 3, 9, 10);

Инициализация пинов производится при создании объекта, поэтому дополнительно ничего не нужно инициализировать внутри `setup()`

    void setup(){} // остаётся пустым

Основной метод, предназначенный для управления моторами - `drive()`. У него два аргумента - мотор и скорость. Можно выбрать или левый, или правый мотор, или оба сразу. Скорость указывается от -100 до 100, где 0 - это стоп мотора, 100 - максимальная скорость при вращении вперед, а -100 - максимальная скорость при вращении назад. Пример использования метода:

    chassis.drive(LM, 100);
    chassis.drive(RM, -50);

В данном примере левый мотор вращается с максимальной скоростью вперед, а правый - с половинной скоростью назад.

Использование констант `LRM` и `RLM` в качестве первого аргумента метода `drive()` позволяют запустить оба мотора в одну и ту же сторону с одинаковой скоростью. Например:

    chassis.drive(LRM, 80);

Моторы будут продолжать крутиться в указанную сторону с указанной скоростью, пока не будет вызван новый метод `drive()` с новыми значениями. Например, чтобы заставить шасси крутиться на месте в течение пяти секунд, а затем остановиться, можно написать так:

    chassis.drive(LM, 100);
    chassis.drive(RM, -100);
    delay(5000);
    chassis.drive(LRM, 0);

Hacking
-----

**Внимание:** При указании маленькой скорости мотор может крутиться недостаточно медленно или не крутиться вовсе - это зависит от конкретной модели мотора.

В этом случае можно *"подкрутить"* параметры ШИМ. В файле `BiWheel.h` указаны константы `PWM_MIN` и `PWM_MAX`, равные 150 и 255, соответственно, которые означают минимальную и максимальную длину импульсов ШИМ.

Можно попытаться подстроить минимальную длину импульсов под свои моторы экспериментальным путем. Делать максимальную длину больше 255 не имеет смысла - это аппаратное ограничение.

Для экспериментов следует менять значения в строках

    #define PWM_MIN 150
    #define PWM_MAX 255

Свяжитесь с нами
-------
[Официальный сайт](http://www.skbrii.ru)

[Группа Вконтакте](https://www.vk.com/skbrii)
