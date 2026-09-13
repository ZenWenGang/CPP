#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[nums.size() - 1])//以最右边为参照
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};