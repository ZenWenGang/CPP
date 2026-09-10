#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int hash[128] = { 0 };
        int n = s.size();
        int left = 0, right = 0, len = 0;
        while (right < n)
        {
            hash[s[right]]++;//进窗口
            while (hash[s[right]] > 1)//判断
                hash[s[left++]]--;//出窗口
            len = max(len, right - left + 1);
            right++;//下一个元素进入窗口
        }
        return len;
    }
};