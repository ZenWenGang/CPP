#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1(nums1.begin(), nums1.end());
        set<int> n2(nums2.begin(), nums2.end());
        vector<int> ret;
        set<int>::iterator t1 = n1.begin();
        set<int>::iterator t2 = n2.begin();
        while (t1 != n1.end() && t2 != n2.end())
        {
            if (*t1 < *t2)
            {
                ++t1;
            }
            else if (*t1 > *t2)
            {
                ++t2;
            }
            else
            {
                ret.push_back(*t1);
                ++t1;
                ++t2;
            }
        }
        return ret;

    }
};