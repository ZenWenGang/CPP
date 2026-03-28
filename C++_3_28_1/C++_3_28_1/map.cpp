#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<string, string>dict; 
	dict.insert(make_pair("sort","排序" ));

	//key不存在：插入+修改
	dict["left"];
	dict["right"] = "右边";
	
	//key存在：修改
	dict["left"] = "左边";

	//查找,确定key存在才能这么用，否则就是插入
	cout << dict["right"] << endl;

	//插入,因为red不存在
	cout << dict["red"] << endl;

	for (auto e : dict)
	{
		cout << e.first << " " << e.second << endl;
	}
	return 0;
}