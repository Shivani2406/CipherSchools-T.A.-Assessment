// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed, the only constraint stopping you
// from robbing each of them is that adjacent houses have security systems connected and
// it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money
// you can rob tonight without alerting the police. Input:nums = [1,2,3,1] Output: 4

#include <iostream>

using namespace std;

int robbery(int *nums, int n)
{
	if (n == 0) return 0;
	if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

	int result; // max amt of money
	int j = nums[0];
	int k = max(nums[0], nums[1]);

	for (int i=2; i<n; i++)
	{
		result = max(nums[i]+j, k);
		j = k;
		k = result;
	}

	return result;
}

int main()
{
	int n;
	cout << "Enter no of houses: ";
	cin >> n;
	int nums[n];

	cout << "Enter money amounts: ";
	for (int i=0; i<n; i++){
        cin >> nums[i];
	}

	cout << "Maximum amount of money robbed : " << robbery(nums, n);
	return 0;
}

