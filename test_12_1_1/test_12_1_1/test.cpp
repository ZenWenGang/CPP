#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	int a = 0;
	// 引⽤：b和c是a的别名 
	int& b = a;
	int& c = a;
	// 也可以给别名b取别名，d相当于还是a的别名

	int& d = b;
	++d;
	//这⾥取地址我们看到是⼀样的

	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	cout << &d << endl;
	return 0;
}