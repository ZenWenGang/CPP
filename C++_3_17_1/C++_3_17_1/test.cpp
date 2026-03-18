#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
namespace zwg
{
	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int> l2(lt);
		list<int>::iterator it = l2.begin();
		while (it != l2.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list2()
	{
		list<int> lt1({ 1,2,3,4,5 });
		list<int>::iterator it = lt1.begin();
		//print_container(lt1);
	}
}
int main()
{
	zwg::test_list1();
	return 0;
}