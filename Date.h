#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

class Date
{
private:
	unsigned char _day;
	unsigned char _month;
	unsigned int _year;
	bool CheckDayByMonth();
	unsigned char DaysInFebruary();
	int NumberOfDayYear(unsigned char numberOfMonth);
	int NumberOfDaysInMonths(unsigned char numberOfMonth);	// количество дней в сумме от начала года до текущего мес€ца
	void DaysToMonthsAndDays(int result_days);
public:
	Date();
	Date(unsigned char day, unsigned char month, unsigned int year);
	explicit Date(unsigned char day);
	Date(unsigned char day, unsigned char month);
	Date& operator-(int num);
	Date& operator+(int num);
	void PrintDate();
};

#endif
