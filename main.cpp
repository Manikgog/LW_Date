/*
«адание 1
—оздайте класс Date, который будет содержать информацию о
дате (день, мес€ц, год).
— помощью механизма перегрузки операторов, определите
операцию разности двух дат (результат в виде количества дней
между датами), а также операцию увеличени€ даты на определенное количество дней.
*/

#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "Date.h"

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	srand(time(NULL));

	Date my_birthday(14, 5, 1979);
	Date date = my_birthday - 20;
	date.PrintDate();


	return 0;
}
