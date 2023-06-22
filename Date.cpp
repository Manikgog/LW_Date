#include "Date.h"


Date::Date() : _day(1), _month(1), _year(1970) {}
Date::Date(unsigned char day, unsigned char month, unsigned int year)
	: _day(day), _month(month), _year(year)
{
	if (!CheckDayByMonth())
	{
		std::cout << "Введённое количество дней не соответствует количеству дней в месяце.\n";
		exit(1);
	}
}

Date::Date(unsigned char day) : Date(day, 1, 1970) {}

Date::Date(unsigned char day, unsigned char month) : Date(day, month, 1970) {}

bool Date::CheckDayByMonth()	// проверка правильности введённого количества дней в месяце
{
	switch (_month)
	{
	case 1:
		if (_day >= 1 && _day <= 31)
			return true;
		else
			return false;
	case 2:

		if (_day >= 1 && _day <= DaysInFebruary())
			return true;
		else
			return false;
	case 3:
		if (_day >= 1 && _day <= 31)
			return true;
		else
			return false;
	case 4:
		if (_day >= 1 && _day <= 30)
			return true;
		else
			return false;
	case 5:
		if (_day >= 1 && _day <= 31)
			return true;
		else
			return false;
	case 6:
		if (_day >= 1 && _day <= 30)
			return true;
		else
			return false;
	case 7:
		if (_day >= 1 && _day <= 31)
			return true;
		else
			return false;
	case 8:
		if (_day >= 1 && _day <= 31)
			return true;
		else
			return false;
	case 9:
		if (_day >= 1 && _day <= 30)
			return true;
		else
			return false;
	case 10:
		if (_day >= 1 && _day <= 31)
			return true;
		else
			return false;
	case 11:
		if (_day >= 1 && _day <= 30)
			return true;
		else
			return false;
	case 12:
		if (_day >= 1 && _day <= 31)
			return true;
		else
			return false;
	}
	
	return false;
}

unsigned char Date::DaysInFebruary()	// функция возвращает количество дней в феврале в зависимости от високосности года
{
	if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
	{
		return 29;
	}
	return 28;
}

Date& Date::operator-(int num)
{
	int result_days = NumberOfDayYear(_month) - num;
	
	if (result_days < 1)
	{
		_year--;
		if (DaysInFebruary() == 29)
		{
			result_days = 366 + result_days;
		}
		else
		{
			result_days = 365 + result_days;
		}
	}
	DaysToMonthsAndDays(result_days);

	return *this;
}

Date& Date::operator+(int num)
{
	int result_days = NumberOfDayYear(_month - 1) + num;
	
	if (result_days > NumberOfDaysInMonths(12))
	{
		_year++;
		if (DaysInFebruary() == 29)
		{
			result_days = result_days - 366;
		}
		else
		{
			result_days = result_days - 365;
		}
	}

	DaysToMonthsAndDays(result_days);

	return *this;
}

void Date::DaysToMonthsAndDays(int result_days)
{
	unsigned char month = 1;
	if (result_days >= 1 && result_days <= 31)
	{
		month = 1;
	}
	else if (result_days > NumberOfDaysInMonths(1) && result_days <= NumberOfDaysInMonths(2))
	{
		month = 2;
		result_days -= 31;
	}
	else if (result_days > NumberOfDaysInMonths(2) && result_days <= NumberOfDaysInMonths(3))
	{
		month = 3;
		result_days -= NumberOfDaysInMonths(2);
	}
	else if (result_days > NumberOfDaysInMonths(3) && result_days <= NumberOfDaysInMonths(4))
	{
		month = 4;
		result_days -= NumberOfDaysInMonths(3);
	}
	else if (result_days > NumberOfDaysInMonths(4) && result_days <= NumberOfDaysInMonths(5))
	{
		month = 5;
		result_days -= NumberOfDaysInMonths(4);
	}
	else if (result_days > NumberOfDaysInMonths(5) && result_days <= NumberOfDaysInMonths(6))
	{
		month = 6;
		result_days -= NumberOfDaysInMonths(5);
	}
	else if (result_days > NumberOfDaysInMonths(6) && result_days <= NumberOfDaysInMonths(7))
	{
		month = 7;
		result_days -= NumberOfDaysInMonths(6);
	}
	else if (result_days > NumberOfDaysInMonths(7) && result_days <= NumberOfDaysInMonths(8))
	{
		month = 8;
		result_days -= NumberOfDaysInMonths(7);
	}
	else if (result_days > NumberOfDaysInMonths(8) && result_days <= NumberOfDaysInMonths(9))
	{
		month = 9;
		result_days -= NumberOfDaysInMonths(8);
	}
	else if (result_days > NumberOfDaysInMonths(9) && result_days <= NumberOfDaysInMonths(10))
	{
		month = 10;
		result_days -= NumberOfDaysInMonths(9);
	}
	else if (result_days > NumberOfDaysInMonths(10) && result_days <= NumberOfDaysInMonths(11))
	{
		month = 11;
		result_days -= NumberOfDaysInMonths(10);
	}
	else if (result_days > NumberOfDaysInMonths(11) && result_days <= NumberOfDaysInMonths(12))
	{
		month = 12;
		result_days -= NumberOfDaysInMonths(11);
	}
	this->_month = month;
	this->_day = result_days;
}


int Date::NumberOfDaysInMonths(unsigned char numberOfMonth)
{
	int amountOfDays = 0;
	for (int i = 1; i <= numberOfMonth; ++i)
	{
		switch (i)
		{
		case 1:
			amountOfDays += 31;
			break;
		case 2:
			amountOfDays += (int)DaysInFebruary();
			break;
		case 3:
			amountOfDays += 31;
			break;
		case 4:
			amountOfDays += 30;
			break;
		case 5:
			amountOfDays += 31;
			break;
		case 6:
			amountOfDays += 30;
			break;
		case 7:
			amountOfDays += 31;
			break;
		case 8:
			amountOfDays += 31;
			break;
		case 9:
			amountOfDays += 30;
			break;
		case 10:
			amountOfDays += 31;
			break;
		case 11:
			amountOfDays += 30;
			break;
		case 12:
			amountOfDays += 31;
			break;
		}
	}
	return amountOfDays;
}

int Date::NumberOfDayYear(unsigned char numberOfMonth)
{
	int amountOfDays = NumberOfDaysInMonths(numberOfMonth);
	
	amountOfDays += _day;
	return amountOfDays;
}

void Date::PrintDate()
{
	std::cout << (int)_day << "." << (int)_month << "." << _year << std::endl;

}