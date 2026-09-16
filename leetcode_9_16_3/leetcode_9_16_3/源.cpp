#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        unordered_map<int, int> hash;
        hash[0 % k] = 1;//0这个数的余数
        int sum = 0, ret = 0;
        for (auto x : nums)
        {
            sum += x;//算出当前位置的前缀和
            int r = (sum % k + k) % k;//修正后的余数
            if (hash.count(r)) ret += hash[r];//统计结果
            hash[r]++;
        }
        return ret;
    }
};