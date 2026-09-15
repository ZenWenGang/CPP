#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> f(n);
        vector<int> g(n);
        vector<int> ret(n);
        //填表
        f[0] = g[n - 1] = 1;//注意这个细节
        for (int i = 1; i <= n - 1; i++)
            f[i] = f[i - 1] * nums[i - 1];


        for (int i = n - 2; i >= 0; i--)
            g[i] = g[i + 1] * nums[i + 1];

        //使用表
        for (int i = 0; i < n; i++)
            ret[i] = f[i] * g[i];

        return ret;
    }
};