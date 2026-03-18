#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
namespace bite
{
	void test_list1()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);
		lt1.push_back(5);
		print_container(lt1);
		lt1.erase(++lt1.begin());
		print_container(lt1);
		lt1.insert(lt1.end(), 100);
		print_container(lt1);
	}
}

int main()
{
	bite::test_list1();
	return 0;
}