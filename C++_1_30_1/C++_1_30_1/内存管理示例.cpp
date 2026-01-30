#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int globalVal = 1;
static int staticGlobalVar = 1;

void Test()
{
	static int staticVar = 1;
	int localVar = 1;
	int num1[10] = { 1,2,3,4 };
	char char2[] = "abcd";
	char* pChar3 = char2;
	int* ptr1 = (int*)malloc(sizeof(int) * 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
	free(ptr1);
	free(ptr3);
}