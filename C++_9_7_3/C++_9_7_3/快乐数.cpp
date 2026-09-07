#define _CRT_SECURE_NO_WARNINGS 1
int Sum(int n)//用于算每位的平方和
{
    int sum = 0;
    while (n)
    {
        int t = n % 10;
        sum += t * t;
        n /= 10;
    }
    return sum;
}
bool isHappy(int n)
{
    int slow = n, fast = Sum(n);
    while (slow != fast)
    {   //快慢指针
        slow = Sum(slow);
        fast = Sum(Sum(fast));
    }
    return slow == 1;
}
