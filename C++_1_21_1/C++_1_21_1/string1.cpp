#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>//使用string必须包含的头文件，跟C的<string.h>不同
using namespace std;
//class string
//{
//public:
//	char& operator[](size_t i)
//	{
//      assert(i < _size);
//		return _str[i];
//	}
//private:
//	char* _str;
//	size_t _size;
//	size_t _capacity;
//};
int main()
{
	string s1;//string(); 构造函数，是一个空串
	string s2("hello world");
	string s3(s2);//string (const string& str); 将s2拷贝给s3
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	//string (const string& str, size_t pos, size_t len = npos);
	string s4(s2, 6, 15);//从s2中第6个字符开始复制15个字符到s4，如果复制数量超过s2，就有多少拷多少
	cout << s4 << endl;

	string s5(s2, 6);//不传第三个参数，就直到拷贝结束
	cout << s5 << endl;

	//string (const char* s, size_t n);
	string s6("hello world", 5);//拷贝前5个字符给s6初始化
	cout << s6 << endl;

	//string(size_t n, char c);
	string s7(10, 'X'); //用10个'X'初始化s7
	cout << s7 << endl;

	//string能够直接修改数组的内容，并能检测数组是否越界
	s6[0] = 'x';//将数组下标0的字符修改为‘x’
	//s6[10];//如果数组越界能够检查出来
	cout << s6 << endl;

	return 0;
}
