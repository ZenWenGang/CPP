#pragma once
#include<iostream>
using namespace std;
#include<assert.h>
class Date
{
public:
	void Print();
	Date(int year = 2000, int month = 1, int day = 1);
	
	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator-=(int day);
	Date operator-(int day);
	int GetMonthDay(int year, int month)
	{
		assert(year > 0 && month < 13);
		int MonthDay[13]={ -1, 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year
			% 400 == 0))
		{
			return 29;
		}
		else
		{
			return MonthDay[month];
		}
	}
private:
	int  _year;
	int  _month;
	int  _day;
};
