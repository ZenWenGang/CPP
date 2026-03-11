#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace zwg
{
	class string
	{
	public:
		//模拟实现迭代器（模拟的是指针的行为）
		typedef char* iterator;
		typedef const char* const_iterator ;//const迭代器
		iterator begin()//开头
		{
			return _str;
		}
		iterator end()//结尾
		{
			return _str+_size;
		}

		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}

		//构造函数
		string(const char* str="")//常量字符串后面都有一个\0,如果写成"\0"就会有两个\0
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];//_capacity不包含\0,因此开空间的时候多开一个
			strcpy(_str, str);
		}

		string(const string& s)//拷贝构造
		{
			_str = new char[s._capacity+1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		~string()
		{
			delete[]_str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str()const
		{
			return _str;
		}

		void clear()//清掉数据但不清空间
		{
			_str[0] = '\0';
			_size = 0;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}

		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}	

		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);
		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos, size_t len = npos);

		size_t find(char ch, size_t pos=0);
		size_t find(const char* str, size_t pos=0);
		string substr(size_t pos, size_t len=npos );
		string& operator=(const string& s);
	private:
		char* _str=nullptr;
		size_t _size=0;
		size_t _capacity=0;

		static const size_t npos;
	};
	bool operator<(const string& s1, const string& s2);
	bool operator<=(const string& s1, const string& s2);
	bool operator>(const string& s1, const string& s2);
	bool operator>=(const string& s1, const string& s2);
	bool operator==(const string& s1, const string& s2);
	bool operator!=(const string& s1, const string& s2);

	ostream& operator<<(ostream& out,const string& s);
	istream& operator>>(istream& in, string& s);
}