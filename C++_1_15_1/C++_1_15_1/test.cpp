#define _CRT_SECURE_NO_WARNINGS 1
#include"dateclass.h"
int main()
{
	Date d1(2024, 7, 12);
	Date d2 = d1 + 100;
	d1.Print();
	d2.Print();
	return 0;
}