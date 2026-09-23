#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    string convert(string s, int numRows)
    {
        string ret;
        if (numRows == 1) return s;

        int d = 2 * numRows - 2, n = s.size();
        for (int i = 0; i < n; i += d)
            ret += s[i];

        for (int k = 1; k < numRows - 1; k++)
        {
            for (int i = k, j = d - k; i < n || j < n; i += d, j += d)
            {
                if (i < n) ret += s[i];
                if (j < n) ret += s[j];
            }
        }

        for (int i = numRows - 1; i < n; i += d)
            ret += s[i];

        return ret;

    }
};