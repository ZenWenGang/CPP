#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//template <class ...Args>
//void Print(Args&&... args)
//{
//	cout << sizeof...(args) << endl;
//}
//int main()
//{
//	double x = 2.2;
//	Print();                       // 包⾥有0个参数
//	Print(1);	                   // 包⾥有1个参数
//	Print(1, string("xxxxx"));     // 包⾥有2个参数
//	Print(1.1, string("xxxxx"), x);// 包⾥有3个参数    
//
//	return 0;
//}
// 原理1：编译本质这⾥会结合引⽤折叠规则实例化出以下四个函数
//void Print();
//void Print(int&& arg1);
//void Print(int&& arg1, string&& arg2);
//void Print(double&& arg1, string&& arg2, double& arg3);
//    
//
// 原理2：更本质去看没有可变参数模板，我们实现出下面这样的多个
// 函数模板才能⽀持这⾥的功能，有了可变参数模板，我们进⼀
// 步被解放，他是类型泛化基础上叠加数量变化，让我们泛型编程更灵活。
//void Print();
//
//template <class T1>
//void Print(T1&& arg1);
//
//template <class T1, class T2>
//void Print(T1 && arg1, T2 && arg2);
//
//template <class T1, class T2, class T3>
//void Print(T1&& arg1, T2&& arg2, T3&& arg3);


//template <class ...Args>
//void Print(Args&&... args)
//{
//	// 不支持
//	for (auto&& e : args...)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

// //包扩展（解析出参数包的内容）
//void ShowList()
//{
//	// 编译器时递归的终止条件，参数包是0个时，直接匹配这个函数
//	cout << endl;
//}
//
//template <class T, class ...Args>
//void ShowList(T&& x, Args&&... args)
//{
//	// 运行时
//	/*if (sizeof...(args) == 0)
//		return;*/
//
//	cout << x << " ";
//	// args是N个参数的参数包
//	// 调用ShowList，参数包的第一个传给x，剩下N-1传给第二个参数包
//	ShowList(args...);
//}
//
//template <class ...Args>
//void Print(Args&&... args)
//{
//	ShowList(args...);
//}
//int main()
//{
//	double x = 2.2;
//	Print(); // 包里有0个参数
//	Print(1); // 包里有1个参数
//	Print(1, string("xxxxx")); // 包里有2个参数
//	Print(1.1, string("xxxxx"), x); // 包里有3个参数
//
//	return 0;
//}
#include<algorithm>
#include<vector>
struct Goods
{
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价
	// ...

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{
	}
};

//struct Compare1
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price < gr._price;
//	}
//};
//
//struct Compare2
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;
//	}
//};
//
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3}, { "菠萝", 1.5, 4 } };
//	// 类似这样的场景，我们实现仿函数对象或者函数指针支持商品中
//	// 不同项的比较，相对还是比较麻烦的，那么这里lambda就很好用了
//
//	//仿函数：
//	// 价格升序
//	//sort(v.begin(), v.end(), Compare1());
//	// 价格降序
//	//sort(v.begin(), v.end(), Compare2());
//
//	//lambda：
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price < g2._price; });
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price > g2._price; });
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate < g2._evaluate; });
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate > g2._evaluate; });
//
//	return 0;
//}
#include<functional>
using placeholders::_1;
using placeholders::_2;
using placeholders::_3;

int Sub(int a, int b)
{
	return (a - b) * 10;
}

int SubX(int a, int b, int c)
{
	return (a - b - c) * 10;
}

int main()
{
	auto sub1 = bind(Sub, _1, _2);
	cout << sub1(10, 5) << endl;

	auto sub2 = bind(Sub, _2, _1);
	cout << sub2(10, 5) << endl;

	// 调整参数个数 （常用）
	auto sub3 = bind(Sub, 100, _1);
	cout << sub3(5) << endl;

	auto sub4 = bind(Sub, _1, 100);
	cout << sub4(5) << endl;

	// 分别绑死第123个参数
	auto sub5 = bind(SubX, 100, _1, _2);
	cout << sub5(5, 1) << endl;
	auto sub6 = bind(SubX, _1, 100, _2);
	cout << sub6(5, 1) << endl;
	auto sub7 = bind(SubX, _1, _2, 100);
	cout << sub7(5, 1) << endl;
}