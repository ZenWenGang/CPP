#define _CRT_SECURE_NO_WARNINGS 1
void moveZeroes(vector<int>& nums)
{
    for (int cur = 0, dest = -1; cur < nums.size(); cur++)
    {
        if (nums[cur])
            swap(nums[++dest], nums[cur]);
    }
}