biWheel
=======
Библиотека для двухколесного шасси, управляемого H-мостом L298 или L293. 

Библиотека предназначена для Arduino IDE 1.0 и старше.

Установка библиотеки
-------
Скачайте архив с библиотекой, кликнув на кнопку Download ZIP справа от этой записи. 

Распакуйте содержимое и переименуйте папку biWheel-master в biWheel. Папку поместите в Arduino/libraries. 

После запуска Arduino IDE в примерах (Файл->примеры) появится строчка biWheel с примерами использования библиотеки. 

Подключение двигателей
-------

Для того, чтобы библиотека заработала с ходу для вашего шасси, следует подключать провода от моторов следующим образом:

- нижний провод правого мотора к OUT1,

- верхний провод правого мотора к OUT2,

- нижний провод левого мотора к OUT3,

- верхний провод левого мотора к OUT4.

Подключение H-моста
-------

Библиотека предусматривает два способа подключения H-моста к Arduino:

1. подключение 4-х проводов к входам H-моста IN1, IN2, IN3, IN4;

2. подключение 6-и проводов к входам H-моста IN1, IN2, IN3, IN4, ENA, ENB.

Поведение шасси будет идентичным, разница лишь в количестве используемых пинов Arduino и используемых каналов ШИМ. При 1-м способе подключения занято 4 пина, причём все 4 должны уметь генерировать ШИМ-сигнал, таким образом подключение второго H-моста к плате Arduino представляется затруднительным. При втором способе подключения занято 6 пинов, из которых всего 2 должны уметь генерировать ШИМ-сигнал, и при желании можно подключить до 3-х мостов на одну плату.

ШИМ-сигналы можно получить на пинах 3, 5, 6, 9, 10, 11 Arduino. 

При 1-м способе подключения для IN1, IN2, IN3 и IN4 рекомендуется использовать пины 3, 9, 10 и 11, поскольку на них одна и та же частота ШИМ. 

При 2-м способе подключения для IN1, IN2, IN3 и IN4 можно использовать любые пины, но нежелательно использовать пины 0 и 1, поскольку они используются для прошивки контроллера через USB, а также пин 13, поскольку к нему подключен светодиод с резистором. Для ENA и ENB можно использовать пару 5,6 или 9,10 или 11,3.



Свяжитесь с нами
-------
[Официальный сайт](http://www.skbrii.ru)

[Группа Вконтакте](https://www.vk.com/skbrii)






