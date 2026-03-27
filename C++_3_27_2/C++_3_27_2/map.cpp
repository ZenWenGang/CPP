#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	//初始化列表构造
	map<string, string> dict = { {"left","左边"},{"right","右边"},{"insert","插入"} };
	
	//插入pair的多种方式
	//1.插入一个有名对象
	pair<string, string> kv1("first", "第一个");
	dict.insert(kv1);

	//2.插入一个匿名对象
	dict.insert(pair<string,string>("second","第二个"));

	//3.传函数模板：make_pair
	//make_pair:是一个函数模板，传Key和value会自动推导类型构造一个pair进行返回
	dict.insert(make_pair("sort", "排序"));
	//dict.insert(pair<string,string>("sort", "排序"))跟上面等价
	
	//4.多参数的隐式类型转换   C++11
	dict.insert({ "auto","自动的" });
	dict.insert({ "auto","自动" });//插入时只看key，value不一样不会更新

	//迭代器遍历
	auto it = dict.begin();
	while (it != dict.end())
	{
		//it->first+='x';err
		it->second += 'x';//vlaue支持修改，key不支持修改
		cout << it->first << ":" << it->second << endl;
		++it;
	}

	return 0;
}