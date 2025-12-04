#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	int a = 10;

	
	//int& ra;// 编译报错：“ra” :必须初始化引⽤
	int& b = a;
	int c = 20;
	
	b = c;// 这⾥并⾮让b引⽤c，因为C++引⽤不能改变指向。这⾥是⼀个赋值
	
    cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	return 0;
}