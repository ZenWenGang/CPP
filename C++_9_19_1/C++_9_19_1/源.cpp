#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>

int main()
{

	int target = 9;
	vector<int>nums = { 8,6,3,4,7,6 };
	
	for (int left = 0; left < nums.size(); left++)
	{
		for (int right = left; right < nums.size(); right++)
		{
			if (nums[left] + nums[right] == target)
				cout << left << " " << right << endl;
		}
	}

	return 0;
}