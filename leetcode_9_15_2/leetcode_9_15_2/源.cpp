#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    int pivotIndex(vector<int>& nums)
    {
        //ÌîÁ½¸ö±í
        int n = nums.size();
        vector<int> f(n), g(n);
        for (int i = 1; i < n; i++)
            f[i] = nums[i - 1] + f[i - 1];

        for (int i = n - 2; i >= 0; i--)
            g[i] = nums[i + 1] + g[i + 1];

        for (int i = 0; i < n; i++)
            if (f[i] == g[i])
                return i;

        return -1;

    }
};