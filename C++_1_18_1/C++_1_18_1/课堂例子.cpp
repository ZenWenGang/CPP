#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date
{
	public:
	Date(int year = 1, int month = 1, int day = 1)
			:_year(year)
			,_month(month)
			//这里没有初化_day
	{}
	
	void Print() const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	
	private:
		// C++11
		// 声明，缺省值->初始化列表用的
		int _year = 1;
		int _month = 1;
		int _day=1;//没初始化就用这个缺省值
};
	
int main()
{
	// 对象定义
	Date d1(2025, 3, 14);
	d1.Print();
	return 0;
}