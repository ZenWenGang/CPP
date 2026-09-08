#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    int triangleNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());//ÏÈÅÅÐò
        int ret = 0, n = nums.size();
        for (int i = n - 1; i > 0; i--)
        {
            int left = 0, right = i - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[i])
                {
                    ret += right - left;
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return ret;
    }
};