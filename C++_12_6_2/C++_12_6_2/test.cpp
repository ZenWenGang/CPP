#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	// 这⾥只是声明，没有开空间
	int _year;
	int _month;
	int _day;
};
int main()
{
	// Date类实例化出对象d1和d2
	Date d1;
	Date d2;

	d1.Init(2025, 11, 30);
	d1.Print();
	d2.Init(2025, 12, 31);
	d2.Print();
	return 0;
}

