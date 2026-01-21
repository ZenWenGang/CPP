#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
template<class T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

//int main()
//{
//	double d1 = 2.0;
//	double d2 = 5.0;
//	Swap(d1, d2);
//	int i1 = 10;
//	int i2 = 20;
//	Swap(i1, i2);
//	char a = '0';
//	char b = '9';
//	Swap(a, b);
//	return 0;
//}
template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.0;
//	Add(a1, a2);
//	cout << Add(a1, a2) << endl;
//	Add(d1, d2);
//	cout<<Add(d1, d2) << endl;
//	/*
//	该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有
//	一个T，
//	编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//	注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
//	Add(a1, d1);//err
//	*/
//// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
//   Add(a1, (int)d1);//自己强转
//   cout << Add(a1, (int)d1) << endl;
//return 0;
//}
//int main(void)
//{
//	int a = 10;
//	double b = 20.2;
//	// 显式实例化
//	Add<int>(a, b);
//	cout << Add<double>(a, b) << endl;
//	return 0;
//}

// 类模版
template<typename T>
class Stack
{
public:
	Stack(size_t capacity = 4)
	{
		_array = new T[capacity];
		_capacity = capacity;
		_size = 0;
	}
	void Push(const T& data);
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};
// 模版不建议声明和定义分离到两个文件.h 和.cpp会出现链接错误
template<class T>
void Stack<T>::Push(const T& data)
{
	// 扩容
	_array[_size] = data;
	++_size;
}

int main()
{
	Stack<int> st1;
	// int
	Stack<double> st2; // double
	return 0;
}