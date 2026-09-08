#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
    vector<int> twoSum(vector<int>& price, int target)
    {
        int n = price.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (price[left] + price[right] > target)
            {
                right--;
            }
            else if (price[left] + price[right] < target)
            {
                left++;
            }
            else
            {
                return { price[left],price[right] };//c++Óï·¨
            }
        }
        return { -1,-1 };  //ÕÕ¹Ë±àÒëÆ÷
    }
};