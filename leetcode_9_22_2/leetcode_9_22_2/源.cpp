#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int tmp = 0;
        for (auto x : nums) tmp ^= x;
        for (int i = 1; i <= nums.size() + 2; i++) tmp ^= i;

        int diff = 0;
        while (1)
        {
            if (((tmp >> diff) & 1) == 1) break;
            else diff++;
        }

        int a = 0, b = 0;
        for (auto x : nums)
            if (((x >> diff) & 1) == 1) b ^= x;
            else a ^= x;
        for (int i = 1; i <= nums.size() + 2; i++)
            if (((i >> diff) & 1) == 1) b ^= i;
            else a ^= i;

        return { a,b };
    }
};