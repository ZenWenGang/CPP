#define _CRT_SECURE_NO_WARNINGS 1
#include"list2.h"
namespace zwg
{
	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}
int main()
{
	zwg::test_list1(); ///这里是函数调用 不是声明
	return 0;
}