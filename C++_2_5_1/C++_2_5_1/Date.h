#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
 public:
	bool CheckDate();

	Date(int year = 2000, int month = 1, int day = 1);

	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int MonthArr[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return 29;
		return MonthArr[month];
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date& operator+=(int day);
	Date operator+(int day) const;

	Date& operator-=(int day);
	Date operator-(int day) const;
	
	Date& operator++();
	Date operator++(int day);
	Date& operator--();
	Date operator--(int day);

	int operator-(const Date& day)const;
 private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& cin, const Date& d);
