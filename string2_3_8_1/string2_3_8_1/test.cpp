#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"
namespace zwg
{
	void test_string1()
	{
		string s1;
		string s2("hello world");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		//下标遍历
		for (size_t i = 0; i < s2.size(); i++)
		{
			s2[i] += 2;
		}
		cout << s2.c_str() << endl;

		//迭代器遍历
		string::iterator it = s2.begin();
		while (it != s2.end())
		{
			*it += 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;
		//范围for遍历
		for (auto a : s2)
		{
			cout << a << " ";
		}
		cout << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		s1 += 't';
		s1 += '$';
		cout << s1.c_str() << endl;

		s1 += "hello zwg";
		cout << s1.c_str() << endl;
		s1.insert(5, '$');
		cout << s1.c_str() << endl;
		s1.insert(0, '$');
		cout << s1.c_str() << endl;

		s1.insert(5, "zwg");
		cout << s1.c_str() << endl;
	}
	void test_string3()
	{
		string s1("hello world");
		s1.erase(6, 50);
		cout << s1.c_str() << endl;

		string s2("hello world");
		s2.erase(6);
		cout << s1.c_str() << endl;

		string s3("hello world");
		s3.erase(6, 3);
		cout << s3.c_str() << endl;
	}
	void test_string4()
	{
		string s("test.cpp.zip");
		size_t pos = s.find('.');
		string suffix = s.substr(pos);
		cout << suffix.c_str() << endl;

		string copy(s);//拷贝构造copy
		cout << copy.c_str() << endl;

		s=suffix ;
		cout << s.c_str() << endl;
	}
	void test_string5()
	{
		string s1("hello world");
		string s2("hello world");
		cout << (s1 < s2) << endl;
		cout << (s1 == s2) << endl;
		//单参数构造函数支持隐式类型转换
		cout << ("hello world" < s2) << endl;
		cout << (s1 == "hello world")<<endl;
		//cout << ("hello world" == "hello world") << endl;//err,运算符重载必须有一个类类型参数

		cout << s1 << s2 << endl;
		cin >> s1;
		cout << s1 << endl;
	}
}
int main()
{
	zwg::test_string5();
	return 0;
}