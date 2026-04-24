#define _CRT_SECURE_NO_WARNINGS 1
#include "process.h"
#include <string.h>
#include <unistd.h>
#define NUM 101 //留一个给‘/0’
#define STYLE '='
void FlushProcess(double total, double current)
{
	char buffer[NUM];
	memset(buffer, 0, sizeof(buffer));
	const char* lable = "|/-\\";
	int len = strlen(lable);
	static int cnt = 0;
	// 不需要⾃⼰循环,填充= 
	int num = (int)(current * 100 / total); // 11.0 / 1000的比例
	int i = 0;
	for (; i < num; i++)
	{
		buffer[i] = STYLE;
	}
	double rate = current / total;//下载比率
	cnt %= len;
	printf("[%-100s][%.1f%%][%c]\r", buffer, rate * 100, lable[cnt]);//进度条，百分比，下载状态
	cnt++;
	fflush(stdout);
}