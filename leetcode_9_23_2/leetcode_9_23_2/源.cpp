#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        int ret = 0, n = timeSeries.size();
        for (int i = 1; i < n; i++)
        {
            int x = timeSeries[i] - timeSeries[i - 1];
            if (x >= duration)
                ret += duration;
            else
                ret += x;
        }
        return ret += duration;//最后一个数字加上中毒时间
    }
};