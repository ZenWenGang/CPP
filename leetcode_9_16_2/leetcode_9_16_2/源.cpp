#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    int findMaxLength(vector<int>& nums)
    {
        unordered_map<int, int>hash;
        hash[0] = -1;
        int sum = 0, ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 0 ? -1 : 1;//计算当前位置的前缀和
            if (hash.count(sum)) ret = max(ret, i - hash[sum]);
            else
                hash[sum] = i;
        }
        return ret;
    }
};