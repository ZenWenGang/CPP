#define _CRT_SECURE_NO_WARNINGS 1
#include"dateclass.h"
int main()
{
	Date d1(2024, 7, 12);
	Date d2(2002,12,29);
	d1.Print();
	d2.Print();
	cout << d1 - d2;
	return 0;
}