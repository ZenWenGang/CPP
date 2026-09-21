#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int x = a ^ b;
            unsigned int carry = (unsigned)(a & b) << 1;
            a = x;
            b = carry;
        }
        return a;
    }
};