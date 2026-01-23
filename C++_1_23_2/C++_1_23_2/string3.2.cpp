#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
void test_string5()
{
	//尾插：push_back，append，+= 接口
	string s("hello world");
	s.push_back(' ');
	s.push_back('x');
	s.append("yyyyyy");
	cout << s << endl;//hello world xyyyyyy

	s += ' ';//'+='也是尾插，一般用这个多一些
	s += "33333333333";
	cout << s << endl;//hello world xyyyyyy 33333333333

	//指定位置插入：insert接口

	s.insert(0, "hello gym");
	cout << s << endl;//hello gymhello world xyyyyyy 33333333333
	s.insert(0, "p");//插入一个字符
	cout << s << endl;//phello gymhello world xyyyyyy 33333333333

	// string& insert (size_t pos, size_t n, char c);
	char ch = 't';
	s.insert(0, 1, ch);//pos位置插入n个字符
	s.insert(s.begin(), ch);//迭代器版本头插
	cout << s << endl;//ttphello gymhello world xyyyyyy 33333333333
}

void test_string6()
{
	string s("hello world");
	//指定位置删除：erase接口
	// string& erase (size_t pos = 0, size_t len = npos);pos位置开始，删len个字符
	s.erase(6, 1);
	cout << s << endl;//hello orld

	s.erase(0, 1);
	cout << s << endl;//ello orld

	//迭代器用法：
	s.erase(s.begin());//头删
	cout << s << endl;//llo orld

	s.erase(--s.end());//尾删
	cout << s << endl;//llo orl

	s.erase(2);//从下标2开始，后面全部删除
	cout << s << endl;//ll

	//指定位置替换：replace
	//string& replace (size_t pos,  size_t len,  const string& str);
	string ss("hello world");
	//replace的本质伴随着插入删除
	ss.replace(5, 1, "##");//第5个位置的一个字符替换成两个"#"
	cout << ss << endl;//hello##world
	//sss.replace(5, 4, "##");//第5个位置的四个字符替换成一个"#"
	//cout << sss << endl;//hello##ld

	//查找：find（从左开始找）/rfind(从右开始找)
	//例题：找出字符串的空格，并替换成"##"
	string sss("hello world hello gym");
	size_t pos = sss.find(' ');
	while (pos != string::npos)
	{
		sss.replace(pos, 1, "##");
		pos = sss.find(' ', pos + 2);
	}
	cout << sss << endl;//hello##world##hello##gym
}

void test_string7()
{
	string str("Please,replace the vowe in this sentence by asterisks.");
	cout << str << endl;
	size_t found = str.find_first_of("abcd");//找到abcd任意一个将其替换成‘*’
	while (found != string::npos)
	{
		str[found] = '*';
		found = str.find_first_of("abcd", found + 1);
	}
	cout << str << endl;
}