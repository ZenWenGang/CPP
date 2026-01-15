#define _CRT_SECURE_NO_WARNINGS 1
#include"dateclass.h"

Date::Date(int year , int month , int day )
{
	_year = year;
	_month = month;
	_day = day;
}

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day <<  endl;
}

Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;//直接调用重载后的+=：operator+=
	/*while (tmp._day > GetMonthDay(tmp._year, tmp. _month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		++tmp._month;
		if (tmp._month == 13)
		{
			tmp._month = 1;
			++tmp._year;
		}
	}	*/
	return tmp;
}
Date &Date:: operator+=(int day)
{
	
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_month = 1;
			++_year;
		}
	}
	return *this;
}
