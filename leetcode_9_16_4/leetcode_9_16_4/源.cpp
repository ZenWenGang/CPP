#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int>hash;
        hash[0] = 1;
        int sum = 0, ret = 0;
        for (auto x : nums)
        {
            sum += x;//计算当前位置的前缀和
            if (hash.count(sum - k)) ret += hash[sum - k];//统计个数
            hash[sum]++;
        }
        return ret;
    }
};