# DS1302 STM32F3
Небольшая библиотека почти полностью скопирована отсюда https://github.com/julgonmej/stm32f7-ds1302-lib.git .  
В изначальной библиотеке DS1302 **не выводится из режима HALT**. В результате запись и чтение регистров получается, а вот отсчета времени нет (микросхема спит).

Я добавил несколько изменений:  
1. Добавил 3 новых функции:  
//Запуск часов.  
void DS1302_ClockStart(void);  
//Остановка часов.  
void DS1302_ClockStop(void);  
//Сброс часов. Затирает все значения регистров времени и даты нулями.  
void DS1302_ClockClear(void);  

2. В функции DS1302_Init() добавил вызов функции DS1302_ClockStart() чтоб часы начали (продолжили) отсчет времени.
3. Вынел функцию delayUS_DWT в отдельный файл.
4. В файле DS1302.h разместил небольшую инструкцию по использованию.
5. Перенёс объявления Порта и Выводов из DS1302.c в DS1302.h.
