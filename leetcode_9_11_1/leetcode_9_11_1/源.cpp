#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    int totalFruit(vector<int>& f)
    {
        int hash[100001] = { 0 };//用数组优化空间
        int ret = 0;
        for (int left = 0, right = 0, kid = 0; right < f.size(); right++)
        {
            if (hash[f[right]] == 0)
                kid++;
            hash[f[right]]++;//进窗口
            while (kid > 2)//判断
            {
                hash[f[left]]--;
                if (hash[f[left]] == 0) kid--;
                left++;//出窗口

            }
            ret = max(ret, right - left + 1);//更新结果
        }
        return ret;
    }
};