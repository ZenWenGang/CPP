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
	cout << _year << "/" << _month << "/" << _day <<  endl;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "⽉" << d._day << "⽇" << endl;
		return out;
}

istream& operator>>(istream& in, Date& d)
{
	cout << "请依次输⼊年⽉⽇: > ";
	in >> d._year >> d._month >> d._day;	
	return in;
}
int Date::operator-(const Date& d)
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
		flag = -1;
	int n = 0;
	while (max != min)
	{
		++min;
		++n;
	}
	return n * flag;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
Date& Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
Date& Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}
bool Date::operator<(const Date& d)
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			return _day < d._day;
		}
	}
	return false;
}
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}
bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}
bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}
bool Date::operator==(const Date& d)
{
	return _year == d._year &&
		_month == d._month &&
		_day == d._day;
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;//直接调用重载后的+=：operator+=

	return tmp;
}
Date &Date:: operator+=(int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}
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
Date& Date:: operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month==0)
		{
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year,_month);
	}
	return *this;
}
Date Date:: operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}
