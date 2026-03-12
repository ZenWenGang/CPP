#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"
namespace bit
{
	void test_string1()
	{
		// 返回c在string中第一次出现的位置
		string s1 = ("hello world");
		size_t pos1= s1.find('o');
		cout << pos1 << endl;
		// 返回子串s在string中第一次出现的位置
		size_t pos2 = s1.find("wo");
		cout << pos2 << endl;
		 // 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string s2=s1.insert(1,'#');
		cout << s2 << endl;
		 s2 = s1.insert(6, "&&&");
		cout << s2 << endl;
		 // 删除pos位置上的元素，并返回该元素的下一个位置
		string s3 = s1.erase(6,2);
		cout << s3 << endl;

	}
}

int main()
{
	bit::test_string1();
	return 0;
}