// Q2. Given an integer array nums of length n and an integer target,
// find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.You may assume that each input
// would have exactly one solution . Input:nums =[-1,2,1,-4],target = 1 , Output: 2

#include <bits/stdc++.h>

using namespace std;

#define INFINITY 1000000000

int findClosestSum(vector<int>& arr, int target)
{

    // Sorting of array
    sort(arr.begin(), arr.end());

    // initialize closest sum to infinity
    int closest_sum = INFINITY;

    // form sets of 3 elements, find their sum and check the difference with target
    for (int i = 0; i < arr.size() - 2; i++) {
        // i -> 1st elem in subset
        // start -> 2nd elem in subset
        // end_ -> 3rd elem in subset
        int start = i + 1, end_ = arr.size() - 1;
        while (start < end_) {
            int sum = arr[i] + arr[start] + arr[end_];
              if (sum == target) return sum;

            if (abs(target - sum) < abs(target - closest_sum)) {
                closest_sum = sum;
            }

            if (sum > target) {
                end_--;
            }
            else {
                start++;
            }
        }
    }

    return closest_sum;
}

int main()
{
    int n, i, elem;

    // take user input for array elements and target
    cout << "Enter size of an array: ";
    cin >> n;
    vector<int> arr;
    cout << "Enter array elements: ";
    for (i=0; i<n; i++){
        cin >> elem;
        arr.push_back(elem);
    }

    int target;
    cout << "Enter target: ";
    cin >> target;
    cout << findClosestSum(arr, target);

    return 0;
}
