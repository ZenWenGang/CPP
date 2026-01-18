#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class B;// 前置声明，否则A的友元函数声明编译器不认识B

class A
{
	friend void func(const A& aa, const B& bb);// 友元声明
private:
	int _a1 = 1;
	int _a2 = 2;
};

class B
{
	friend void func(const A& aa, const B& bb);// 友元声明
private:
	int _b1 = 3;
	int _b2 = 4;
};

void func(const A& aa, const B& bb)
{
	cout << aa._a1 << endl;
	cout << bb._b1 << endl;
}

int main()
{
	A aa;
	B bb;
	func(aa, bb);
	return 0;
}