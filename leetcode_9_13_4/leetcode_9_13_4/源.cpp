#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    int takeAttendance(vector<int>& records)
    {
        int left = 0, right = records.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (records[mid] == mid)
                left = mid + 1;
            else
                right = mid;
        }
        //出了循环还是跟下标相等，就是最右边情况
        return left == records[left] ? left + 1 : left;
    }
};