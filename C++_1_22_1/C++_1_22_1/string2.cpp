#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
using namespace std;
//class string
//{
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//};
void test_string()
{
	string s1;
	string s2("hello word!");
	cout << s1 << s2 << endl;
	//遍历string的三种方法：
	//1.下标+[]
	for (size_t i = 0; i < s2.size(); i++)//string中的size接口
	{
		cout << s2[i] << " " ;//h e l l o   w o r d !
	}
	cout << endl;

	//2.迭代器：用来遍历和访问容器
	string::iterator it = s2.begin();//串
	while (it != s2.end())
	{
		//it += 2;迭代器是可以修改的
		cout << *it << " ";//h e l l o   w o r d !
		++it;
	}
	cout << endl;

	list<int> lt = { 1,2,3,4,5,6,7 };//链表
	list<int>::iterator lit = lt.begin();
	while (lit != lt.end())
	{
		cout << *lit << " ";//解引用返回
		++lit;
	}
	cout << endl;
	//其他容器使用迭代器访问都是类似的，通用的
	
	//3.范围for遍历
	//字符赋值，自动迭代，自动判断结束
	//底层就是迭代器，也是跟迭代器一样支持所有容器
	for (auto ch : s2)//auto：自动类型；这里也可以自己写char，只要类型匹配即可
	//for (auto& ch : s2) //上面的只是拷贝，修改不了s2，只有加个引用才能修改s2
	{
		//ch -= 2;
		cout << ch << " ";
	}
	cout << endl;
	//以上三种遍历方式没有区别
}

//4种迭代器：
//iterator
//reverse_iterator
//const_iterator
//const_reverse_iterator
void test_string2()
{
	string s2("hello world");
	string::iterator it = s2.begin();//正向迭代器
	while (it != s2.end())
	{
		cout << *it << " "; //h e l l o   w o r l d
		++it;
	}
	cout << endl;

	string::reverse_iterator rit = s2.rbegin();//反向迭代器
	while (rit != s2.rend())
	{
		cout << *rit << " ";//d l r o w   o l l e h
		++rit;
	}
	cout << endl;

	const string s3("hello world!");//const迭代器
	string::const_iterator cit = s3.begin();
	while (cit != s3.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;

	//string::const_reverse_iterator rcit = s3.rbegin();//const反向迭代器
	auto  rcit = s3.rbegin();//auto指针的好处，节省代码量
	while (rcit != s3.rend())
	{
		cout << *rcit << " ";
		++rcit;
	}
	cout << endl;

}

void TestPushBack()
{
	//reverse 反转 逆置 
	//reverve 保留 预留
	string s;
	size_t sz = s.capacity();
	s.reserve(100);//提前开空间，避免扩容
	
	cout << "capacity changed:" << sz << '\n';
	cout << "making s grow:\n";

	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}
void test_string3()
{
	string s2("hello world");
	//下面两个作用都是返回字符串有效字符长度
	cout << s2.length() << endl;
	cout << s2.size() << endl;

	cout << s2.max_size() << endl;//最大长度
	cout << s2.capacity() << endl;//返回空间总大小
	TestPushBack();
	string s3("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
}
void test_string4()
{
	//reserve在vs平台不会缩容，在g++会缩容，具体看平台实现
	string s2("hello worldxxxxxxxxxxxxxxx");
	cout << s2.size() << endl;//26
	cout << s2.capacity() << endl << endl;//31（\0占了一位）对齐32，

	s2.reserve(20);//20<26<31       在g++平台下，这里会缩容，capacity会输出26
	cout << s2.size() << endl;//26
	cout << s2.capacity() << endl << endl;//31没缩容

	s2.reserve(28);//26<28<31 
	cout << s2.size() << endl;//26
	cout << s2.capacity() << endl << endl;//31

	s2.reserve(48);//26<31<48
	cout << s2.size() << endl;//26
	cout << s2.capacity() << endl << endl;//63  扩容
	

	//clear  ：：清数据但不清容量
	s2.clear();
	cout << s2.size() << endl;//0
	cout << s2.capacity() << endl << endl;//63


}
int main()
{
	test_string3();
	test_string4();
	return 0;
}