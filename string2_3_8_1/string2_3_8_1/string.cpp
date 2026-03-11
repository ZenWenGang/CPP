#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"
namespace zwg
{
	const size_t string::npos = -1;
	void string::reserve(size_t n)
	{
		//手动扩容
		if (n > _capacity)
		{
			//开辟新空间，拷贝数据，释放旧空间，指向新空间
			char* tmp = new char[n + 1];//多开一个给\0
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}
	//尾插字符
	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';//不要漏了，否则会乱码
	}
	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	//尾插字符串
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}
		strcpy(_str + _size, str);//strcpy会自动拷贝\0
		_size+= len;
	}
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	//从pos位置插入字符
	void string::insert(size_t pos, char ch)
	{
		assert(pos <=_size);
		if (_size == _capacity)//需要扩容的情况
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		//挪动数据
		size_t end = _size+1;
		while (end > pos)
		{
			_str[end ] = _str[end-1];
			--end;
		}
		_str[pos] = ch;
		++_size;
	}
	//从pos位置插入字符串
	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (len == 0)
			return;

		if (_size + len > _capacity)
		{
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}
		//向后挪动数据
		size_t end = _size + len;
		while (end > pos+len-1)//注意位置关系
		{
			_str[end] = _str[end - len];
			--end;
		}
		//插入数据
		for (size_t i = 0; i < len; i++)
		{
			_str[pos + i] = str[i];
		}

		_size += len;
	}
	//删除从pos位置开始的len个字符
	void string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len >= _size-pos)//删除个数超过字符串的情况
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			for (size_t i = pos+len; i <=_size; i++)
			{
				_str[i - len] = _str[i];//数据前移
			}
			_size -= len;
		}
	}

	//查找字符
	size_t string::find(char ch, size_t pos)
	{
		assert(pos < _size);
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}
	//查找字符串
	size_t string::find(const char* str, size_t pos)
	{
		assert(pos < _size);
		const char* ptr = strstr(_str + pos, str);//采用strstr算法
		if (ptr == nullptr)//没找到的情况
		{
			return npos;
		}
		else
		{
			return ptr - _str;//找到的位置减去起始位置的下标
		}
	}
	//从pos位置开始取len个字符
	string string::substr(size_t pos = 0, size_t len )
	{
		assert(pos < _size);
		if (len > _size - pos)//要求返回个数超过pos开始的个数，有多少个返回多少个
		{
			len = _size - pos;
		}
		//返回一串字符
		string sub;
		sub.reserve(len);
		for (size_t i = 0; i < len; i++)
		{
			sub += _str[pos + i];
		}
		return sub;//传值返回，要写对应的拷贝构造
	}
	//深拷贝
	string& string::operator=(const string& s)
	{
		if (this != &s)//防止自己赋值给自己出现问题
		{
			delete[] _str;//释放旧空间
			_str = new char[s._capacity + 1];//开辟新空间
			strcpy(_str, s._str);//将数据拷贝到新空间
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}
	//比较大小(与库里面一样实现成全局函数)
	//实现两个就可以开始代码复用
	bool operator<(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}
	bool operator<=(const string& s1, const string& s2)
	{
		return !(s1 > s2);
	}
	bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}
	bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}
	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str())==0;
	}
	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}
	//重载流插入，流提取运算符
	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		const int N = 256;
		char buff[N];//设一个缓冲,减少空间浪费
		int i = 0;

		//cin/scanf提取不到空格和换行符，默认它们是分隔符。
		//所以用get函数来规避这一问题。
		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			buff[i++]=ch;
			if (i == N - 1)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch=in.get();
		}
		if (i > 0)//buff没存满的情况
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}
}