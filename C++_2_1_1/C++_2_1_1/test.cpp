#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<map>
#include<list>
using namespace std;

//class string
//{
//private:
//	char _buff[16];
//	char*  _str;
//
//	size_t _size;
//	size_t _capacity;
//};

void test_string1()
{
	string s1;
	string s2("hello world");

	cout << s1 << s2 << endl;

	s2[0] = 'x';
	cout << s1 << s2 << endl;

	// 1、下标 + []
	for (size_t i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;

	// 2、迭代器
	//string::iterator it = s2.begin();
	auto it = s2.begin();
	while (it != s2.end())
	{
		*it += 2;

		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << s2 << endl;

	map<string, string> dict;
	//map<string, string>::iterator mit = dict.begin();
	auto mit = dict.begin();

	/*list<int> lt = { 1,2,3,4,5,6,7 };
	list<int>::iterator lit = lt.begin();
	while (lit != lt.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;*/

	// 3、字符赋值，自动迭代，自动判断结束
	// 底层就是迭代器
	//for (auto ch : s2)
	for (auto& ch : s2)
	{
		ch -= 2;
		cout << ch << " ";
	}
	cout << endl;

	cout << s2 << endl;
}

void test_string2()
{
	string s2("hello world");
	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		*it += 2;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	const string s3("hello world");
	//string::const_iterator cit = s3.begin();
	auto cit = s3.begin();
	while (cit != s3.end())
	{
		//*cit += 2;
		cout << *cit << " ";
		++cit;
	}
	cout << endl;

	//string::const_reverse_iterator rcit = s3.rbegin();
	auto rcit = s3.rbegin();
	while (rcit != s3.rend())
	{
		// *rcit += 2;
		cout << *rcit << " ";
		++rcit;
	}
	cout << endl;
}

void TestPushBack()
{
	// reverse 反转  逆置
	// reserve 保留、预留
	string s;
	// 提前开空间，避免扩容，提高效率
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << '\n';

	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_string3()
{
	string s2("hello world");
	cout << s2.length() << endl;
	cout << s2.size() << endl;

	cout << s2.max_size() << endl;

	cout << s2.capacity() << endl;
	TestPushBack();

	string s3("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	
}

void test_string4()
{
	string s2("hello worldxxxxxxxxxxxxx");
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.reserve(20);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.reserve(28);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.reserve(40);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.clear();
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	cout << typeid(string::iterator).name() << endl;
	cout << typeid(string::reverse_iterator).name() << endl;
}

void test_string5()
{
	string s("hello world");
	s.push_back(' ');
	s.push_back('x');
	s.append("yyyyyy");

	cout << s << endl;

	s += ' ';
	s += "33333333333";
	cout << s << endl;

	s.insert(0, "hello gym ");
	cout << s << endl;

	s.insert(10, "zzzz");
	cout << s << endl;

	s.insert(0, "p");
	cout << s << endl;

	char ch = 't';
	s.insert(0, 1, ch);
	s.insert(s.begin(), ch);

	cout << s << endl;
}

void test_string6()
{
	string s("hello world");
	s.erase(6, 1);
	cout << s << endl;

	// 头删
	s.erase(0, 1);
	cout << s << endl;

	s.erase(s.begin());
	cout << s << endl;

	// 尾删
	s.erase(--s.end());
	cout << s << endl;

	s.erase(s.size() - 1, 1);
	cout << s << endl;

	string ss("hello world");
	ss.erase(6);
	cout << ss << endl;

	string sss("hello                 world hello gym");

	string tmp;
	tmp.reserve(sss.size());
	for (auto ch : sss)
	{
		if (ch == ' ')
			tmp += "%%";
		else
			tmp += ch;
	}
	cout << tmp << endl;
	sss.swap(tmp);
	cout << sss << endl;

	string file;
	cin >> file;
	FILE* fout = fopen(file.c_str(), "r");
	char ch = fgetc(fout);
	while (ch != EOF)
	{
		cout << ch;
		ch = fgetc(fout);
	}
	fclose(fout);
}

void SplitFilename(const std::string& str)
{
	std::cout << "Splitting: " << str << '\n';
	std::size_t found = str.find_last_of("/\\");

	std::cout << " path: " << str.substr(0, found) << '\n';
	std::cout << " file: " << str.substr(found + 1) << '\n';
}
void test_string7()
{
	string s("test.cpp.zip");
	size_t pos = s.rfind('.');
	string suffix = s.substr(pos);
	cout << suffix << endl;

	std::string str("Please, replace the vowels in this sentence by asterisks.");
	std::cout << str << '\n';

	std::size_t found = str.find_first_not_of("abcdef");
	while (found != std::string::npos)
	{
		str[found] = '*';
		found = str.find_first_not_of("abcdef", found + 1);
	}

	std::cout << str << '\n';

	std::string str1("/usr/bin/man");
	

	SplitFilename(str1);
}

void test_string8()
{
	string s1("hello");

	string s2 = s1 + "world";
	cout << s2 << endl;

	string s3 = "world" + s1;
	cout << s3 << endl;
}
////////////////////////////////////////////////////////////////////////////////////
// 模拟实现
#include"string.h"

namespace str
{
	void test_string1()
	{
		string s1;
		string s2("hello world");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s2.size(); i++)
		{
			s2[i] += 2;
		}

		cout << s2.c_str() << endl;

		for (auto e : s2)
		{
			cout << e << " ";
		}
		cout << endl;

		string::iterator it = s2.begin();
		while (it != s2.end())
		{
			//*it += 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		s1 += 'x';
		s1 += '#';
		cout << s1.c_str() << endl;

		s1 += "hello bit";
		cout << s1.c_str() << endl;

		s1.insert(5, '$');
		cout << s1.c_str() << endl;

		s1.insert(0, '$');
		cout << s1.c_str() << endl;

		string s2("hello world");
		cout << s2.c_str() << endl;

		s2.insert(5, "$$$");
		cout << s2.c_str() << endl;

		s2.insert(0, "$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
		cout << s2.c_str() << endl;
	}

	void test_string3()
	{
		string s1("hello world");
		s1.erase(6, 100);
		cout << s1.c_str() << endl;

		string s2("hello world");
		s2.erase(6);
		cout << s2.c_str() << endl;

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

		string copy(s);
		cout << copy.c_str() << endl;

		s = suffix;
		cout << suffix.c_str() << endl;
		cout << s.c_str() << endl;

		s = s;
		cout << s.c_str() << endl;
	}

	void test_string5()
	{
		string s1("hello world");
		string s2("hello world");

		cout << (s1 < s2) << endl;
		cout << (s1 == s2) << endl;
		cout << ("hello world" < s2) << endl;
		cout << (s1 == "hello world") << endl;
		//cout << ("hello world" == "hello world") << endl;

		cout << s1 << s2 << endl;

		string s0;
		cin >> s0;
		cout << s0 << endl;
	}
}

int main()
{
	str::test_string5();
	return 0;
}