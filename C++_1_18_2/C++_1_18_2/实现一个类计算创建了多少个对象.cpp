#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//计算现存的对象个数
using namespace std;
class A
{
public:
	A()
	{
		++_scount;
	}
	A(const A& t)
	{
		++_scount;
	}
	~A()
	{
		--_scount;
	}
	static int GetACount()
	{
		//a++;  err,静态成员没有this指针，不能访问
		return _scount;
	}
	void func()//非静态的可以随意访问静态的
	{
		cout << _scount << endl;
		cout << GetACount << endl;
	}
private:
	// 类⾥⾯声明
	static int a;//声明一个a
	static int _scount;
};
int A::_scount = 0;

int main()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	{
		A a3(a1);
		cout << A::GetACount() << endl;
	}
	cout << A::GetACount() << endl;//用：：突破类域访问
	cout << a1.GetACount() << endl;//也可以用 . 突破类域访问
	return 0;
}