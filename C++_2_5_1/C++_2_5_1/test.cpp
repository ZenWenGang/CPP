#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
void test01()
{
	Date s1(2024, 7, 13);
	Date s2 = s1+100;
	s2.Print();
	s1 += 100;
	s1.Print();
	s1 -= 100;
	s1.Print();
	s2 - 100;
	s2.Print();
}
void test02()
{
	Date s1(2002, 12, 29);
	Date s2 = s1++;
	s2.Print();
	s1.Print();

}
void test03()
{
	Date s1(2024, 6, 31);
	Date s2 (2024,9,1);
	cout << s1 - s2 << endl;
}
void test04()
{
	Date s1(2024, 6, 30);
	Date s2(2024, 9, 1);
	cout << s1 - s2 << endl;
}
void test05()
{
	Date s1(2024, 6, 30);
	Date s2(2024, 9, 1);
	Date s3;
	cin >> s3;
	cout << s3 << endl;
}
int main()
{
	test05();
	return 0;
}