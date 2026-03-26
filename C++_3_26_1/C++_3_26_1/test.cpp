#define _CRT_SECURE_NO_WARNINGS 1
#include"BSTree.h"
void TestBSTree1()
{
	BSTree<string, string> dict;
	dict.Insert("insert", "²åÈë");
	dict.Insert("erase", "É¾³ý");
	dict.Insert("left", "×ó±ß");
	dict.Insert("string", "×Ö·û´®");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << str << ":" << ret->_value << endl;
		}
		else
		{
			cout << "µ¥´ÊÆ´Ð´´íÎó" << endl;
		}
	}
}

void TestBSTree2()
{
	string strs[] = { "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ó£ÌÒ", "Æ»¹û", "Ó£ÌÒ", "Æ»¹û", "Ó£ÌÒ", "Æ»¹û" };
	// Í³¼ÆË®¹û³öÏÖµÄ´Î
	BSTree<string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	BSTree<string, int> copy = countTree;
	copy.InOrder();
	
}

int main()
{
	TestBSTree2();
	return 0;
}