#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        if (nums.size() == 1 && nums[0] == target)
            return 0;
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;//防止数据太大，栈溢出
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};