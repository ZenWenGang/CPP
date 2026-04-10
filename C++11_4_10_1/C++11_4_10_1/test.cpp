#define _CRT_SECURE_NO_WARNINGS 1
// 由于引用折叠限定，f1实例化以后总是一个左值引用
template<class T>
void f1(T& x)
{}

// 由于引用折叠限定，f2实例化后可以是左值引用，也可以是右值引用
template<class T>
void f2(T&& x)
{}

int main()
{
	typedef int& lref;
	typedef int&& rref;
	int n = 0;

	// 引用折叠
	lref& r1 = n; // r1 的类型是 int&
	lref&& r2 = n; // r2 的类型是 int&
	rref& r3 = n; // r3 的类型是 int&
	rref&& r4 = 1; // r4 的类型是 int&&

	// 没有折叠->实例化为void f1(int& x)
	f1<int>(n);
	//f1<int>(0); // 报错

	// 折叠->实例化为void f1(int& x)
	f1<int&>(n);
	//f1<int&>(0); // 报错

	// 折叠->实例化为void f1(int& x)
	f1<int&&>(n);
	//f1<int&&>(0); // 报错

	// 折叠->实例化为void f1(const int& x)
	f1<const int&>(n);
	f1<const int&>(0);

	// 折叠->实例化为void f1(const int& x)
	f1<const int&&>(n);
	f1<const int&&>(0);

	// 没有折叠->实例化为void f2(int&& x)
	//f2<int>(n); // 报错
	f2<int>(0);

	// 折叠->实例化为void f2(int& x)
	f2<int&>(n);
	//f2<int&>(0); // 报错

	// 折叠->实例化为void f2(int&& x)
	//f2<int&&>(n); // 报错
	f2<int&&>(0);

	return 0;
}

 //万能引用 
template<class T>
void Function(T&& t)
{
	int a = 0;
	T x = a;
	//x++;

	cout << &a << endl;
	cout << &x << endl << endl;
}