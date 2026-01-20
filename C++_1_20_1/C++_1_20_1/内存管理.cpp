#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
class A
{
public:
	A(int a1 = 0, int a2 = 0)
		:_a1(a1)
		, _a2(a2)
	{
		cout << "A(int a1 = 0, int a2 = 0)" << endl;
	}

	A(const A& aa)
		:_a1(aa._a1)
	{
		cout << "A(const A& aa)" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

	void Print()
	{
		cout << "A::Print->" << _a1 << endl;
	}

private:
	int _a1 = 1;
	int _a2 = 1;
};
//int main()
//{
//	A* p1 = new A(1);//半缺省
//	A* p2 = new A(2,2);
//
//	A aa1(1, 1);
//	A aa2(2, 2);
//	A aa3(3, 3);
//	A* p3 = new A[3]{aa1, aa2, aa3};//有名对象，new一个数组，严格来说是调用了拷贝构造
//	A* p4 = new A[3]{ A(1,1), A(2,2), A(3,3)};//用匿名对象创建一个数组
//
//	A* p5 = new A[3]{ {1,1}, {2,2}, {3,3} };//多参数的隐式类型转换
//
//	return 0;
//}
int main()
{
	try
	{
		// throw try/catch 
		void* p1 = new char[1024 * 1024 * 1024];
		cout << p1 << endl;

		void* p2 = new char[1024 * 1024 * 1024];
		cout << p2 << endl;

		void* p3 = new char[1024 * 1024 * 1024];
		cout << p3 << endl;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}