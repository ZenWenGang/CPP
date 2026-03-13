#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
void test_vector1()
{
	vector<int> v1;//空表
	vector<int> v2(10,1);//10个1
	vector<int> v3(++v2.begin(), --v2.end());//迭代器区间初始化

	//vector支持迭代器遍历
	for (size_t i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
}
//vector没有length

//vector:reserve
// 测试vector的默认扩容机制
//在vs2022下是1.5倍扩容
void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_vector2()
{
	TestVectorExpand();

}
void test_vector3()
{
	vector<int> v(10, 1);
	v.reserve(20);
	cout << v.size() << endl;//10
	cout << v.capacity() << endl;//20

	v.resize(15,2);//补齐15个数据,缺5个用2填充
	cout << v.size() << endl;//15
	cout << v.capacity() << endl;//20

	v.resize(25,3);
	cout << v.size() << endl;//25
	cout << v.capacity() << endl;//30

	v.resize(5);//size缩到只剩5个1，capacity还是30
	cout << v.size() << endl;//5
	cout << v.capacity() << endl;//30
}
void test_vector4()
{
	vector<int> v(10, 1);
	v.push_back(2);//尾插一个2
	//迭代器遍历：
	v.insert(v.begin(), 0);//头插一个0
	for (auto e : v)
	{
		cout << e << " ";//0 1 1 1 1 1 1 1 1 1 1 2
	}
	cout << endl;

	v.insert(v.begin() + 3, 10);//第3个位置插入一个10 c 
	for (auto e : v)
	{
		cout << e << " ";//0 1 1 10 1 1 1 1 1 1 1 1 2
	}
	cout << endl;
}

void test_vector5()
{
	vector<string> v1;//vector里存string
	string s1("xxxxx");
	v1.push_back(s1);//以前的写法

	v1.push_back("yyyyy");//隐式类型转换

	
	for (const auto& e : v1)//这里v1的string要走拷贝构造代价比较大，所以加&，如果不改变就加多一个const
	{                       //以前是int型，拷贝代价不大就没加&		
		cout << e << " ";
	}
	cout << endl;

	vector<int> v2(5, 1);
	vector<vector<int>> vv(10,v2);//vector里存vector就是二维数组
	vv[1][2] = 5;//这样可以修改或访问数据

}
int main()
{
	test_vector5();
	return 0;
}