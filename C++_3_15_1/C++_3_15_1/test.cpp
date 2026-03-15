#define _CRT_SECURE_NO_WARNINGS 1
#include"vector.h"
using namespace std;
namespace bit
{
	void test_vector1()
	{
		//开空间，尾插，指定位置删除
		vector<int> v1;
		v1.reserve(10);
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.erase(v1.begin()+2);
		print_vector(v1);
		//不同类型的实现
		vector<string> s1 ;
		s1.push_back("xxxxx");
		print_vector(s1);
		//迭代器区间构造
		vector<int> v2(10, 1);//10个1
		vector<int> v3(v2.begin()+1, v2.end()-2);
		print_vector(v3);

		v2.resize(15, 2);
		print_vector(v2);
		v2.insert(v2.begin()+9,3);
		print_vector(v2);
		v2.resize(5);
		print_vector(v2);


	}
}

int main()
{
	bit::test_vector1();
	return 0;
}