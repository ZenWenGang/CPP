#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public://和三数之和大差不差
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ret;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n;)
        {
            for (int j = i + 1; j < n;)
            {
                int left = j + 1, right = n - 1;
                long long aim = (long long)target - nums[i] - nums[j];//唯一区别
                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    if (sum < aim)
                        left++;
                    else if (sum > aim)
                        right--;
                    else
                    {
                        ret.push_back({ nums[i],nums[j],nums[left++],nums[right--] });
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                }
                j++;
                while (j < n && nums[j] == nums[j - 1])
                    j++;
            }
            i++;
            while (i < n && nums[i] == nums[i - 1])
                i++;
        }
        return ret;
    }
};