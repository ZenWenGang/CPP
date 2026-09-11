#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ret;
        int hash1[26] = { 0 };//存p
        for (auto a : p) hash1[a - 'a']++;
        int hash2[26] = { 0 };//存s
        int m = p.size();
        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];
            if (++hash2[in - 'a'] <= hash1[in - 'a']) count++;
            if (right - left + 1 > m)
            {
                char out = s[left++];
                if (hash2[out - 'a']-- <= hash1[out - 'a']) count--;//出窗口
            }
            //更新结果
            if (count == m) ret.push_back(left);
        }
        return ret;
    }
};