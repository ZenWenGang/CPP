#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int hash1[128] = { 0 };//统计字符串t中每一个字符的频次
        int kinds = 0;//统计有效字符有多少种
        for (auto ch : t)
            if (hash1[ch]++ == 0) kinds++;
        int hash2[128] = { 0 };//统计窗口内每个字符的频次

        int minlen = INT_MAX, begin = -1;
        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];
            if (++hash2[in] == hash1[in]) count++;//进窗口，维护count
            while (count == kinds)
            {
                if (right - left + 1 < minlen)//更新结果
                {
                    minlen = right - left + 1;
                    begin = left;
                }
                char out = s[left++];
                if (hash2[out]-- == hash1[out]) count--;
            }
        }
        if (begin == -1) return "";
        else return s.substr(begin, minlen);
    }
};