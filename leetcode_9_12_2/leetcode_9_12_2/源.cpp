#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.size() == 0) return { -1,-1 };//边界情况
        int left = 0, right = nums.size() - 1;
        int begin = 0;//开始值
        int end = 0;//结束值
        //先找左边开始值
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if (nums[left] != target)
            return { -1,-1 };
        else
            begin = left;
        //找右边
        right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid;
        }
        if (nums[right] != target)
            return { -1,-1 };
        else
            end = right;

        return { begin,end };
    }
};