/*
������� 1
�������� ����� Date, ������� ����� ��������� ���������� �
���� (����, �����, ���).
� ������� ��������� ���������� ����������, ����������
�������� �������� ���� ��� (��������� � ���� ���������� ����
����� ������), � ����� �������� ���������� ���� �� ������������ ���������� ����.
*/

#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "Date.h"

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // ��������� ������� �������� �� ���� ������
	srand(time(NULL));

	Date my_birthday(14, 5, 1979);
	Date date = my_birthday - 20;
	date.PrintDate();


	return 0;
}
