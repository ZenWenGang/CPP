#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
namespace bit
{
	class string
	{
	public:
		//构造函数
		string(const char* str = "")
		{
			//先确认大小
			_size = strlen(str);
			_capacity = _size;
			//开辟比总大小多一个的空间给\0
			_str = new char[_capacity + 1];
			//拷贝
			strcpy(_str, str);
		}
		//拷贝构造
		string(const string& s)
		{
			//先开空间
			_str = new char[s._capacity + 1];
			//拷贝数据
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		//深拷贝
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				//释放旧空间
				delete[] _str;
				//开辟新空间
				_str = new char[s._capacity + 1];
				//拷贝数据
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}

		const char* c_str()const
		{
			return _str;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

	private:
		char* _str=nullptr;
		size_t _size = 0;
		size_t _capacity = 0;
	};

	void test_string()
	{
		//深拷贝
		string s1 = "hello world";
		string s2 = s1;
		cout << "s1:"<<s1.c_str() << endl;
		cout << "s2:"<<s2.c_str() << endl;

		//深赋值
		string s3 = "hello bit";
		s1 = s3;
		cout << "s3:" << s3.c_str() << endl;
		cout << "s1:" << s1.c_str() << endl;


	}
}
int main()
{
	bit::test_string();
	return 0;
}