#define _CRT_SECURE_NO_WARNINGS 1
#include"BinarySearch.h"

int main()
{
	key::BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 1, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.Inorder();
	t.Erase(8);
	t.Inorder();
	return 0;
}