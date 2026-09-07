#define _CRT_SECURE_NO_WARNINGS 1
int maxArea(vector<int>& height)
{
    int left = 0, right = height.size() - 1, ret = 0;
    while (left < right)
    {
        int v = min(height[left], height[right]) * (right - left);//求体积
        ret = max(ret, v);

        if (height[left] < height[right])//移动指针，谁小移动谁
            left++;
        else
            right--;
    }
    return ret;
}