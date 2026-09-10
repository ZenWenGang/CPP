#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int n = nums.size();
        int len = INT_MAX;
        int sum = 0;
        for (int left = 0, right = 0; right < n; right++)
        {
            sum += nums[right];//进窗口
            while (sum >= target)
            {
                len = min(len, right - left + 1);
                sum -= nums[left++];//出窗口
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};